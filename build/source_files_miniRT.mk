# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source_files_miniRT.mk                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 16:15:33 by ldulling          #+#    #+#              #
#    Updated: 2024/05/29 19:04:19 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Initialize SRC
# SRC		:= $(SRC)

#TODO Temporary solution to get all source files
SRC				:=	$(patsubst source/%,%,$(wildcard source/*.c source/**/*.c))
# SRC				+=	$(addprefix ../,$(wildcard debug/*.c debug/**/*.c))

# Main:
# DIR		:=	./
# SRC		+=	$(addprefix $(DIR), \
#             main.c \
# )
