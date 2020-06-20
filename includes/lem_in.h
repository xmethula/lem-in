#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# define COMMENT_ID '#'
# define ERROR_MESSAGE "ERROR"
# define START_COMMAND_ID "start"
# define END_COMMAND_ID "end"
# define START_COMMAND 1
# define END_COMMAND 2

typedef struct		s_room
{
	int				x;
	int				y;
	int				dist;
	int				available;
    char			*name;
	struct s_room	*prev;
}					t_room;
typedef struct		s_ant
{
	int				id;
	t_room			*room;
}					t_ant;
typedef struct		s_link
{
	t_room			*from;
	t_room			*to;
}					t_link;
typedef struct		s_turn
{
    int				last_move;
	t_ant			*ant;
	t_room			*room;
}					t_turn;
typedef struct		s_farm
{
	int				n_ants;
	t_list			*ants;
	t_list			*rooms;
	t_room			*start;
	t_room			*end;
	t_list			*turns;
	t_list			*links;
}					t_farm;
int analyze_map_data(t_list **input, t_farm *map);
int handle_line_data(t_list **input);
int	read_map(const int fd, char **data, char c);
int handle_ant_data(t_list **data, t_farm *map);
int check_data(t_list **data);
void ft_lstappend(t_list **lst, t_list *new);
void ft_struct_del(void *node, size_t node_size);
int check_if_comment(t_list *data);
int ignore_comments(t_list **data);
int ignore_commands(t_list **data);
int get_command(t_list *data);
int ft_isinteger(char *line);

int	resolve_rooms(t_list **data, t_farm *f);
int	resolve_room(t_list **data, t_farm *f);
int get_cmd(t_list *data);
int	is_link(t_list *data);
t_room *resolve_info(char *str);
int ft_space(int x);
int	ft_negative(const char *str, size_t n);
int find_info(t_farm *f, t_room *r);

int ft_read_connections(t_list **input, t_farm *farm);
int ft_read_connection(t_list *input, t_farm *farm);
int ft_connections_to_the_rooms(t_list *input, t_farm *farm, t_room **from, t_room **to);
t_room *ft_room_name(t_list *rooms, char *name);
void ft_clear_data(char **data);
size_t ft_board_size(char **board);
t_link *ft_resolve_connection(t_room *from, t_room *to);

int find_path(t_farm *farm);
t_list *run_a_dijkstra(t_farm *farm);
int a_dijkstra(t_farm *farm);
t_list *get_room_list(t_farm *farm);
t_room *get_closest_node(t_list *rooms);
void mod_nodes_dist(t_farm *farm, t_room *room);
int	set_path(t_farm *farm, t_list *path, int *arrived);
int	locate(t_ant *ant, t_farm *farm, t_list *path);
t_list *find_turn(t_ant *ant, t_room *room);
int find_path(t_farm *farm);

void ft_print_out(t_list *value, t_list *points);
void ft_error();
char *ft_ant_link(char *id, char *name);
void ft_print_point(t_list *list);
void ft_print(t_list *list);
void ft_print_list(t_list *list, void (*fn)(t_list *));
void ft_free_farm(t_farm *data);
void ft_free_list(t_list **list, void (*clr)(void *, size_t));
void ft_clear(t_list **list, void (*clr)(void *));
void ft_free_room(void *content, size_t content_size);
void ft_free(void *el, size_t el_size);

void ft_remove_list(t_list **alst, void *content, int (*cmp)());
t_list *ft_lstcpy(void *content, size_t content_size);
size_t get_listsize(t_list *lst);
#endif
