CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -MD -O3
NAME =	lem-in

DIR_S		=	src
DIR_O		=	tmp
DIR_H		=	inc

DIR_LIB		=	libft
DIR_H_LIB	=	libft

SRC	=	lemin.c\
		parse.c\
		validate.c\
		utils_parse.c\
		free_lem.c\
		free_sol.c\
		init.c\
		output.c\
		ants.c\
		paths.c\
		path_tools.c\
		dijkstra.c\
		suurballe.c\

OBJS	=	$(addprefix $(DIR_O)/, $(SRC:.c=.o))

INCLUDES	=	-I$(DIR_H_LIB) -I$(DIR_H)

all: $(NAME)
	@make -C $(DIR_LIB)

$(NAME): $(OBJS)
	@make -C $(DIR_LIB)
	$(CC) $(OBJS) -L$(DIR_LIB) -lft -o $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	@make clean -C $(DIR_LIB)
	@rm -rf $(DIR_O)

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re