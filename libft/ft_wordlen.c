#include "libft.h"

int	ft_wordlen(char const *s, int c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}
