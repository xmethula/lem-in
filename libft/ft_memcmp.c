#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	i = 0;
	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	while (i < n && sc1[i] == sc2[i])
		i++;
	if (i == n)
		return (0);
	return (sc1[i] - sc2[i]);
}
