# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    source_files_miniRT.mk                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 16:15:33 by ldulling          #+#    #+#              #
#    Updated: 2024/06/30 21:51:44 by ldulling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Initialize SRC
SRC		:= $(SRC)

# Main:
DIR		:=	$(SRC_DIR)/
SRC		+=	$(addprefix $(DIR), \
            main.c \
)

# Debug:
DIR		:=	$(SRC_DIR)/debug/
SRC		+=	$(addprefix $(DIR), \
            print_camera.c \
            print_config.c \
            print_hit_record.c \
            print_vector.c \
)

# Hit:
DIR		:=	$(SRC_DIR)/hit/
SRC		+=	$(addprefix $(DIR), \
            hit.c \
            hit_management.c \
            rule_cylinder.c \
            rule_cylinder_utils.c \
            rule_plane.c \
            rule_sphere.c \
)

# Init:
DIR		:=	$(SRC_DIR)/init/
SRC		+=	$(addprefix $(DIR), \
            clean.c \
            init.c \
)

# Interact:
DIR		:=	$(SRC_DIR)/interact/
SRC		+=	$(addprefix $(DIR), \
            interact_camera.c \
            interact_light.c \
            interact_mode.c \
            interact_object.c \
            mod_key.c \
            select_object.c \
            select_utils.c \
            set_color.c \
            set_scale.c \
            set_transform.c \
)

# MLX:
DIR		:=	$(SRC_DIR)/mlx/
SRC		+=	$(addprefix $(DIR), \
            img_pixel_put.c \
            mlx_event.c \
            mlx_init.c \
)

# Object:
DIR		:=	$(SRC_DIR)/object/
SRC		+=	$(addprefix $(DIR), \
            plane_utils.c \
)

# Ray:
DIR		:=	$(SRC_DIR)/ray/
SRC		+=	$(addprefix $(DIR), \
            ray.c \
)

# Reader:
DIR		:=	$(SRC_DIR)/reader/
SRC		+=	$(addprefix $(DIR), \
            reader.c \
            reader_check.c \
            reader_environment.c \
            reader_free.c \
            reader_object.c \
            reader_utils.c \
)

# Render:
DIR		:=	$(SRC_DIR)/render/
SRC		+=	$(addprefix $(DIR), \
            ambient.c \
            diffusion.c \
            display.c \
            render.c \
            shadow.c \
            specular.c \
)

# Scene:
DIR		:=	$(SRC_DIR)/scene/
SRC		+=	$(addprefix $(DIR), \
            camera.c \
            canva.c \
)

# Transform:
DIR		:=	$(SRC_DIR)/transform/
SRC		+=	$(addprefix $(DIR), \
            rotation.c \
            transform.c \
            translate.c \
)

# Utils:
DIR		:=	$(SRC_DIR)/utils/
SRC		+=	$(addprefix $(DIR), \
            error_message.c \
            math_utils.c \
            string_array_utils.c \
)

# Vec3:
DIR		:=	$(SRC_DIR)/vec3/
SRC		+=	$(addprefix $(DIR), \
            vec3.c \
            vec3_arithmetic.c \
            vec3_linearalgebra.c \
)
