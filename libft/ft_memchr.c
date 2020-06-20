#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*sc;

	i = 0;
	sc = (const char *)s;
	while (i < n)
	{
		if (sc[i] == (char)c)
		{
			return ((void *)sc + i);
		}
		i++;
	}
	return (NULL);
}
