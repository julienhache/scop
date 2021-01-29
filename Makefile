# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhache <jhache@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 10:02:52 by jhache            #+#    #+#              #
#    Updated: 2021/01/29 23:10:52 by jhache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := scop

# Basic definitions
SRC_PATH := source
OBJ_PATH := .bin
INC_PATH := $(SRC_PATH)# additionnal path, the other (implicit) one being the path of the currently compiled source file


# Compiler
CC := gcc
CCFLAGS := -Wall -Werror -Wextra -g3
INCFLAGS := $(addprefix -iquote , $(INC_PATH))


# Commands
RM := rm -f
RMDIR := rm -Rdf
MKDIR := mkdir -p


# Files
SRC_NAME := main.c
SRC_NAME += utils/dynamic_array/dynamic_array.c
SRC_NAME += utils/get_line/get_line.c
SRC_NAME += obj_parser/obj_parser.c
SRC_NAME += obj_parser/parsing/parsing1.c \
			obj_parser/parsing/parsing2.c \
			obj_parser/parsing/parsing3.c
SRC_NAME += obj_parser/lexing/lexing1.c

SRC :=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ :=	$(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

OBJ_DIRS := $(sort $(dir $(OBJ)))


# Rules
all: $(NAME)

$(NAME): $(OBJ_DIRS) $(OBJ)
	$(CC) -o $@ $(OBJ)

$(OBJ_DIRS):
	$(MKDIR) $(OBJ_PATH) $@

$(OBJ_PATH)/%.o: $(addprefix $(SRC_PATH)/, %.c)
	$(CC) $(CCFLAGS) -MMD -MF $(<:.c=.d) $(INCFLAGS) -c $< -o $@


#add dependencies files (*.d)
DEP_FILES = $(SRC:%.c=%.d)
-include $(DEP_FILES)


clean:
	$(RM) $(OBJ)
	$(RMDIR) $(OBJ_DIRS)
	$(RM) $(DEP_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re