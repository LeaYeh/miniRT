# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 03:22:46 by ldulling          #+#    #+#              #
#    Updated: 2024/06/25 23:15:38 by ldulling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ***************************** CONFIGURATION ******************************** #

#	Executable

NAME 			:=	miniRT
NAME_TEST		:=	unittest


#	Directories

SRC_DIR			:=	source
SRC_DIR_TEST	:=	tests
INC_DIR			:=	include
BUILD_DIR		:=	build
OBJ_DIR			:=	$(BUILD_DIR)/_obj
DEP_DIR			:=	$(BUILD_DIR)/_dep
LIB_DIR			:=	libraries
ASSET_DIR		:=	assets


#	Dependencies

LIBS			:=	$(LIB_DIR)/libft
LIBS_EXT		:=	m mlx Xext X11
LIBS_EXT_TEST	:=	criterion
LIB_INCLUDES 	:=	$(LIB_DIR)/libft/inc
BUILDFILES		:=	Makefile \
					$(BUILD_DIR)/source_files_miniRT.mk \
					$(BUILD_DIR)/source_files_unittest.mk


#	Flags

CC 				:=	cc
CC_VERSION		:=	$(shell $(CC) --version | head -1)
CFLAGS_STD		:=	-Wall -Wextra -Werror -ggdb3
CFLAGS_SAN		:=	-fsanitize=address,undefined,bounds,float-divide-by-zero
CFLAGS_OPT		:=	-O3
CFLAGS 			?=	$(CFLAGS_STD)
INCFLAGS 		:=	$(addprefix -I,$(INC_DIR) $(LIB_INCLUDES))
LIBFLAGS		:=	$(addprefix -L,$(LIBS)) \
					$(addprefix -l,$(patsubst lib%,%,$(notdir $(LIBS) $(LIBS_EXT))))
LIBFLAGS_TEST	:=	$(addprefix -l,$(LIBS_EXT_TEST))
MAKEFLAGS		:=	-j -s

ARGS				?=	$(ASSET_DIR)/$(shell ls -1 $(ASSET_DIR) | head -n 1)


#	Valgrind

VALGRIND		:=	$(shell which valgrind)

VALGRINDFLAGS	=	--errors-for-leak-kinds=all \
					--leak-check=full \
					--read-var-info=yes \
					--show-error-list=yes \
					--show-leak-kinds=all \
					--trace-children=yes \
					--track-origins=yes

VALGRINDFDFLAGS	:=	--track-fds=all


#	Terminal

TERMINAL		:=	$(shell which gnome-terminal 2> /dev/null)

ifeq ($(filter val,$(MAKECMDGOALS)),val)
TERMINALTITLE	:=	valgrind $(NAME)
else ifeq ($(filter valfd,$(MAKECMDGOALS)),valfd)
TERMINALTITLE	:=	valgrind-fd $(NAME)
else
TERMINALTITLE	:=	$(NAME)
endif

TERMINALFLAGS	:=	--title="$(TERMINALTITLE)" -- /bin/sh -c


#	Files

ifeq ($(MAKECMDGOALS),test)
include				$(BUILD_DIR)/source_files_unittest.mk
else
include				$(BUILD_DIR)/source_files_miniRT.mk
endif

OBJ 			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)
DEP				:=	$(SRC:%.c=$(DEP_DIR)/%.d)


#	Subdirectories

OBJ_SUBDIRS		:=	$(sort $(dir $(OBJ)))
DEP_SUBDIRS		:=	$(sort $(dir $(DEP)))


# ***************************** BUILD PROCESS ******************************** #

.PHONY			:	all fast run test san val valfd build build_test lib waitforlib \
					clean fclean re


#	Compilation

all				:
					($(MAKE) --question build && echo $(MSG_NO_CHNG)) \
						|| (echo -n $(MSG_INFO)$(MSG_START) \
							&& ($(MAKE) build && echo $(MSG_SUCCESS)) \
							|| (echo $(MSG_FAILURE) && exit 42))

fast			:	CFLAGS := $(CFLAGS_STD) $(CFLAGS_OPT)
fast			:	re
					$(MAKE) clean

run				:	all
					"./$(NAME)" $(ARGS)

test			:
					($(MAKE) --question build_test && echo $(MSG_NO_CHNG)) \
						|| (echo -n $(MSG_INFO)$(MSG_START_TEST) \
							&& ($(MAKE) build_test && echo $(MSG_SUCCESS)) \
							|| (echo $(MSG_FAILURE) && exit 42))
					"./$(NAME_TEST)"

san				:	CFLAGS := $(CFLAGS_STD) $(CFLAGS_SAN)
san				:	re
					$(MAKE) clean
					"./$(NAME)" $(ARGS)

val				:	all
					$(VALGRIND) $(VALGRINDFLAGS) "./$(NAME)" $(ARGS)

valfd			:	all
ifneq ($(TERMINAL),)
					$(TERMINAL) $(TERMINALFLAGS) \
					"bash -c 'trap \"\" SIGINT ; \
					$(VALGRIND) $(VALGRINDFLAGS) $(VALGRINDFDFLAGS) ./$(NAME) $(ARGS) ; \
					exec bash'"
else
					$(VALGRIND) $(VALGRINDFLAGS) $(VALGRINDFDFLAGS) "./$(NAME)" $(ARGS)
endif


#	Library dependency management

ifeq ($(firstword $(sort $(MAKE_VERSION) 4.4)),4.4)
build			:	lib .WAIT $(NAME)
else
build			:	waitforlib
					$(MAKE) $(NAME)
endif

ifeq ($(firstword $(sort $(MAKE_VERSION) 4.4)),4.4)
build_test		:	lib .WAIT $(NAME_TEST)
else
build_test		:	waitforlib
					$(MAKE) $(NAME_TEST)
endif


#	Library compilation

export				CC CFLAGS MAKECMDGOALS MAKEFLAGS

lib				:
					$(MAKE) -C $(LIBS)

waitforlib		:	lib


#	Executable linking

$(NAME)			:	$(LIBS) $(OBJ)
					$(CC) $(CFLAGS) $(INCFLAGS) $(OBJ) $(LIBFLAGS) -o $@

$(NAME_TEST)	:	$(LIBS) $(OBJ)
					$(CC) $(CFLAGS) $(INCFLAGS) $(OBJ) $(LIBFLAGS) $(LIBFLAGS_TEST) -o $@


#	Source file compiling

$(OBJ_DIR)/%.o	:	%.c $(BUILDFILES) | $(OBJ_SUBDIRS)
					$(CC) $(CFLAGS) $(MACROS) $(INCFLAGS) -c $< -o $@ \
						&& echo -n $(MSG_PROGRESS)


#	Pre-processing and dependency file creation

$(DEP_DIR)/%.d	:	%.c $(BUILDFILES) | $(DEP_SUBDIRS)
					$(CC) $(CFLAGS) $(MACROS) $(INCFLAGS) \
						-M -MP -MF $@ -MT "$(OBJ_DIR)/$*.o $@" $<


#	Mirror directory structure of source files for build artifacts

$(OBJ_SUBDIRS) \
$(DEP_SUBDIRS)	:
					mkdir -p $@


#	Cleaning

clean			:
					$(MAKE) clean -C $(LIBS)
					rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean			:	clean
					$(MAKE) fclean -C $(LIBS)
					rm -f $(NAME) $(NAME_TEST)

re				:
					$(MAKE) fclean
					$(MAKE) all


#	Include dependency files

ifeq (,$(filter clean fclean re,$(MAKECMDGOALS)))
    ifneq (,$(wildcard $(OBJ_DIR)))
        -include	$(DEP)
    endif
endif


# **************************** COLORS ******************************* #

STY_RES			:=	"\e[0m"
STY_BOL			:=	"\e[1m"
STY_ITA			:=	"\e[3m"
STY_UND			:=	"\e[4m"
STY_RED			:=	"\e[31m"
STY_GRE			:=	"\e[32m"
STY_YEL			:=	"\e[33m"
STY_BLU			:=	"\e[34m"
STY_MAG			:=	"\e[35m"
STY_CYA			:=	"\e[36m"
STY_WHI			:=	"\e[37m"
STY_GRA			:=	"\e[90m"
STY_WHI_BRI		:=	"\e[97m"
STY_BLA_BG		:=	"\e[41m"
STY_RED_BG		:=	"\e[41m"
STY_GRE_BG		:=	"\e[42m"
STY_YEL_BG		:=	"\e[43m"
STY_BLU_BG		:=	"\e[44m"
STY_MAG_BG		:=	"\e[45m"
STY_CYA_BG		:=	"\e[46m"
STY_WHI_BG		:=	"\e[47m"
STY_GRA_BG		:=	"\e[100m"
STY_WHI_BRI_BG	:=	"\e[107m"


# **************************** CUSTOM MESSAGES ******************************* #

################################################################################
MSG_INFO		:=	$(STY_ITA)$(STY_WHI)" Make version: $(MAKE_VERSION)\n\
					Compiler version: $(CC_VERSION)\n"$(STY_RES)
################################################################################
MSG_START		:=	$(STY_ITA)"Building $(NAME) ... "$(STY_RES)
################################################################################
MSG_START_TEST	:=	$(STY_ITA)"Building $(NAME_TEST) ... "$(STY_RES)
################################################################################
MSG_PROGRESS	:=	"💡"
################################################################################
MSG_SUCCESS		:=	$(STY_BOL)$(STY_ITA)$(STY_YEL)"\nDONE!"$(STY_RES)
################################################################################
MSG_NO_CHNG		:=	$(STY_ITA)$(STY_WHI)"Everything up-to-date!"$(STY_RES)
################################################################################
MSG_FAILURE		:=	$(STY_BOL)$(STY_ITA)$(STY_RED)"BUILD FAILED!"$(STY_RES)
################################################################################


# *************************** MAKEFILE DEBUGGING ***************************** #

#	Execute "make print-[variable name]" to list the variable's values

print-%			:
					echo $* = $($*)


# ********************************* NOTES ************************************ #
