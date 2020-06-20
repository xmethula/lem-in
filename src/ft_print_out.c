#include "../includes/lem_in.h"

void        ft_print(t_list *list)
{
    char    *str;

    str = (char*)list->content;
    ft_putstr(str);
    if(str[0] != '\n')
        ft_putchar('\n');
    return ;
}

void        ft_print_point(t_list *list)
{
    t_turn  *point;
    char    *str;
    char    *id;

    point = (t_turn*)list->content;
    id = ft_itoa(point->ant->id);
    str = ft_ant_link(id, point->room->name);
    ft_putstr(str);
    free(id);
    free(str);
    (point->last_move)? ft_putchar('\n') : ft_putchar(' ');
    return ;
}

char        *ft_ant_link(char *id, char *name)
{
    char    *str;
    char    *s;
    char    *house;

    house = ft_strjoin("-", name);
    str = ft_strjoin(id, house);
    s = ft_strjoin("L", str);
    free(str);
    free(house);
    return (s);
}

void        ft_error()
{
    ft_putendl("ERROR");
    return ;
}

void        ft_print_out(t_list *value, t_list *points)
{
    ft_print_list(value, ft_print);
    ft_putchar('\n');
    ft_print_list(points, ft_print_point);
    return ;
}

void        ft_print_list(t_list *list, void (*fn)(t_list *))
{
    if (list == NULL)
        return ;
    (*fn)(list);
    while (list->next != NULL)
    {
        list = list->next;
        (*fn)(list);
    }
    return ;
}