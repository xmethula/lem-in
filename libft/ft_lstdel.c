#include "libft.h"

void	ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(&current, del);
		current = next;
	}
	*lst = NULL;
}
