#include "libft.h"

static int	ft_start_chunk_space(char const *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
	}
	return (i);
}

static int	ft_end_chunk_space(char const *s)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
	{
		i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		startlen;
	int		endlen;
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	startlen = (int)ft_start_chunk_space(s);
	endlen = (int)ft_end_chunk_space(s);
	if ((!endlen && !startlen) || !ft_strlen(s))
		return ((char *)s);
	i = 0;
	if (endlen < 1)
		str = ft_strnew(1);
	else
		str = ft_strnew(endlen - startlen + 1);
	if (!str)
		return (NULL);
	while (startlen < endlen + 1)
	{
		str[i] = s[startlen];
		startlen++;
		i++;
	}
	return (str);
}
