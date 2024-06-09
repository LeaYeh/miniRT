# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source_files_miniRT.mk                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 16:15:33 by ldulling          #+#    #+#              #
#    Updated: 2024/06/09 17:35:22 by ldulling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Initialize SRC
# SRC		:= $(SRC)

#TODO Temporary solution to get all source files
SRC				:=	$(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/**/*.c)

# Main:
# DIR		:=	./
# SRC		+=	$(addprefix $(DIR), \
#             main.c \
# )
