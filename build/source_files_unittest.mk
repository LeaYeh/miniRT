# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source_files_unittest.mk                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 16:15:33 by ldulling          #+#    #+#              #
#    Updated: 2024/05/28 12:26:06 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include				$(BUILD_DIR)/source_files_miniRT.mk

# Filter out main.c from SRC
SRC             :=  $(filter-out $(SRC_DIR)/main.c, $(SRC))

SRC				+=	$(wildcard $(SRC_DIR_TEST)/*.c $(SRC_DIR_TEST)/**/*.c)

# Main:
# DIR		:=	./
# SRC		+=	$(addprefix $(DIR), \
#             main.c \
# )
