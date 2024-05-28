# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 03:22:46 by ldulling          #+#    #+#              #
#    Updated: 2024/05/28 14:34:29 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ***************************** CONFIGURATION ******************************** #

#	Executable

NAME 			:=	miniRT
TEST_NAME		:=	unittest


#	Directories

SRC_DIR			:=	source
INC_DIR			:=	include
BUILD_DIR		:=	build
OBJ_DIR			:=	$(BUILD_DIR)/_obj
DEP_DIR			:=	$(BUILD_DIR)/_dep
LIB_DIR			:=	libraries


#	Dependencies

LIBRARIES		:=	$(LIB_DIR)/libft
LIBRARIES_EXT	:=	m criterion
LIB_INCLUDES 	:=	$(LIB_DIR)/libft/inc
BUILDFILES		:=	Makefile \
					$(BUILD_DIR)/source_files_miniRT.mk \
					$(BUILD_DIR)/source_files_unittest.mk


#	Flags

CC 				:=	cc
CC_VERSION		:=	$(shell $(CC) --version | head -1)
CFLAGS 			:=	-Wall -Wextra -Werror -ggdb3
INCFLAGS 		:=	$(addprefix -I,$(INC_DIR) $(LIB_INCLUDES))
LIBFLAGS		:=	$(addprefix -L,$(LIBRARIES)) \
					$(addprefix -l,$(patsubst lib%,%,$(notdir \
					$(LIBRARIES) $(LIBRARIES_EXT))))
MAKEFLAGS		:=	-j -s


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

# ifeq ($(MAKECMDGOALS),test)
# include				$(BUILD_DIR)/source_files_unittest.mk
# else
include				$(BUILD_DIR)/source_files_miniRT.mk
# endif

OBJ 			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)
DEP				:=	$(SRC:%.c=$(DEP_DIR)/%.d)


#	Subdirectories

OBJ_SUBDIRS		:=	$(sort $(dir $(OBJ)))
DEP_SUBDIRS		:=	$(sort $(dir $(DEP)))


# ***************************** BUILD PROCESS ******************************** #

.PHONY			:	all run test val valfd build lib waitforlib clean \
					fclean ffclean re


#	Compilation

all				:
					($(MAKE) --question build && echo $(MSG_NO_CHNG)) \
						|| (echo -n $(MSG_INFO)$(MSG_START) \
							&& ($(MAKE) build && echo $(MSG_SUCCESS)) \
							|| (echo $(MSG_FAILURE) && exit 42))

run				:	all
					"./$(NAME)"

test			:	all
					"./$(TEST_NAME)"

val				:	all
					$(VALGRIND) $(VALGRINDFLAGS) "./$(NAME)"

valfd			:	all
ifneq ($(TERMINAL),)
					$(TERMINAL) $(TERMINALFLAGS) \
					"bash --posix -c 'trap \"\" SIGINT ; \
					$(VALGRIND) $(VALGRINDFLAGS) $(VALGRINDFDFLAGS) ./$(NAME) ; \
					exec bash --posix'"
else
					$(VALGRIND) $(VALGRINDFLAGS) $(VALGRINDFDFLAGS) "./$(NAME)"
endif


#	Library dependency management

ifeq ($(firstword $(sort $(MAKE_VERSION) 4.4)),4.4)
build			:	lib .WAIT $(NAME)
else
build			:	waitforlib
					$(MAKE) $(NAME)
endif


#	Library compilation

export				CC CFLAGS MAKECMDGOALS MAKEFLAGS

lib				:
					$(MAKE) -C $(LIBRARIES)

waitforlib		:	lib


#	Executable linking

$(NAME)			:	$(LIBRARIES) $(OBJ)
					$(CC) $(CFLAGS) $(INCFLAGS) $(OBJ) $(LIBFLAGS) -o $(NAME)


#	Source file compiling

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c $(BUILDFILES) | $(OBJ_SUBDIRS)
					$(CC) $(CFLAGS) $(MACROS) $(INCFLAGS) -c $< -o $@ \
						&& echo -n $(MSG_PROGRESS)


#	Pre-processing and dependency file creation

$(DEP_DIR)/%.d	:	$(SRC_DIR)/%.c $(BUILDFILES) | $(DEP_SUBDIRS)
					$(CC) $(CFLAGS) $(MACROS) $(INCFLAGS) \
						-M -MP -MF $@ -MT "$(OBJ_DIR)/$*.o $@" $<


#	Mirror directory structure of source files for build artifacts

$(OBJ_SUBDIRS) \
$(DEP_SUBDIRS)	:
					mkdir -p $@


#	Cleaning

clean			:
					$(MAKE) clean -C $(LIBRARIES)
					rm -f $(OBJ) $(DEP)
ifneq (,$(wildcard $(OBJ_DIR)))
					-find $(OBJ_DIR) -type d -empty -delete
endif
ifneq (,$(wildcard $(DEP_DIR)))
					-find $(DEP_DIR) -type d -empty -delete
endif

fclean			:	clean
					$(MAKE) fclean -C $(LIBRARIES)
					rm -f $(NAME)

ffclean			:	fclean
					rm -rf $(OBJ_DIR) $(DEP_DIR)

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
