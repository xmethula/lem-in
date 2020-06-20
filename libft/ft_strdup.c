#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*dst;
	const char	*src;
	int			i;

	src = (const char *)s;
	i = 0;
	dst = ft_memalloc(ft_strlen(src) + 1);
	if (!dst)
	{
		return (NULL);
	}
	else
	{
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
