#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = s;
	if (!n)
	{
		return ;
	}
	while (i < n)
	{
		*(ptr + i) = 0;
		i++;
	}
}
