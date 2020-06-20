#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (src[i])
			dst[i] = src[i];
		else
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
		i++;
	}
	return (dst);
}
