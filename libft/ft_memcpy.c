#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	i = 0;
	if (n == 0 || ptr1 == ptr2)
		return (dst);
	while (i < n)
	{
		*(ptr1 + i) = *(ptr2 + i);
		i++;
	}
	return (dst);
}
