CFLAGS			= -Wall -Werror -Wextra
LEM_IN			= lem_in

SRC_DIR				= src/a_dijkstra.c \
				      src/analyze_map_data.c \
				      src/find_info.c \
				      src/ft_connections_to_the_rooms.c \
				      src/ft_free_memory.c \
				      src/ft_print_out.c \
				      src/handle_ant_data.c \
				      src/handle_line_data.c \
				      src/ignore_comments_and_commands.c \
				      src/resolve_info.c \
					  src/utilities.c \

LEM_IN_DIR		= src/lem-in.c
LEM_HEADER_DIR	= includes/lem_in.h

all: $(LEM_IN)

$(LEM_IN):
	make re -C libft/
	gcc $(FLAGS) $(SRC_DIR) $(LEM_IN_DIR) libft/libft.a -o $(LEM_IN)

clean:
	make clean -C libft/

fclean:
	make fclean -C libft/
	rm -f $(LEM_IN)

re: fclean all
