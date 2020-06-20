#include "libft.h"

int	ft_wordcounter(char const *str, int c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
		{
			i++;
		}
		if (str[i] != c && str[i] != '\0')
		{
			j++;
		}
		while (str[i] != c && str[i] != '\0')
		{
			i++;
		}
	}
	return (j);
}
