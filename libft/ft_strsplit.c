#include "libft.h"

static int	ft_cntwrd(char const *s, char c)
{
	int		i;
	int		cntr;

	i = 0;
	cntr = 0;
	while (*s != '\0')
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			cntr++;
		}
		s++;
	}
	return (cntr);
}

static int	ft_wrdlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, int c)
{
	int		j;
	int		i;
	char	**str;

	i = 0;
	if (!s || !c)
		return (NULL);
	j = ft_cntwrd((const char *)s, c);
	str = (char **)malloc(sizeof(*str) * (ft_cntwrd((const char *)s, c)) + 1);
	if (str == NULL)
		return (NULL);
	while (j--)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i] = ft_strsub((const char *)s, 0, ft_wrdlen((const char *)s, c));
		if (str[i] == NULL)
			return (NULL);
		s = s + ft_wrdlen(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
