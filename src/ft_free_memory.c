#include "../includes/lem_in.h"

void        ft_free(void *el, size_t el_size)
{
    if (!el)
		return ;
	free(el);
	(void)el_size;
}

void        ft_free_room(void *content, size_t content_size)
{
    t_room	*room;

	if (!content)
		return ;
	room = (t_room*)content;
	if (room->name)
		ft_free(room->name, content_size);
	free(content);
}

void        ft_clear(t_list **list, void (*clr)(void *))
{
    if (*list == NULL)
        return ;
    (*clr)((*list)->content);
    ft_memdel((void**)list);
    return ;
}

void        ft_free_list(t_list **list, void (*clr)(void *, size_t))
{
    t_list  *ptr;

    if(*list == NULL)
        return ;
    while (*list != NULL)
    {
        ptr = (*list)->next;
        ft_lstdelone(list, clr);
        *list = ptr;
    }
    return ;
}

void        ft_free_farm(t_farm *data)
{
    ft_free_list(&(data->rooms), ft_free_room);
    ft_free_list(&(data->ants), ft_free);
    ft_free_list(&(data->links), ft_free);
    ft_free_list(&(data->turns), ft_free);
    return ;
}

void    ft_clear_data(char **data)
{
	size_t	i;

	i = 0;
	while (data[i] != NULL)
    {
		free(data[i]);
        i++;
    }
	free(data);
    data = NULL;
}

void	ft_remove_list(t_list **alst, void *content, int (*cmp)())
{
	t_list *last;
	t_list *curr;
	t_list *prev;

	last = NULL;
	prev = NULL;
	curr = *alst;
	while (curr)
	{
		if ((cmp && (*cmp)(curr->content, content) == 0) ||
			(curr->content == content))
		{
			if (*alst != curr)
				last->next = curr->next;
			else
				*alst = curr->next;
			prev = curr;
			curr = curr->next;
			free(prev);
			break ;
		}
		last = curr;
		curr = curr->next;
	}
}

void	ft_struct_del(void *node, size_t node_size)
{
	if (!node)
		return ;
	free(node);
	(void)node_size;
}

void	ft_lstappend(t_list **lst, t_list *new)
{
	t_list	*list;

	if (lst == 0)
		return ;
	if (*lst)
	{
		list = *lst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*lst = new;
}
