#include "get_next_line.h"

static	int		ft_readln(const int fd, char **str)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	while (ft_strchr(str[fd], '\n') == NULL)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == 0)
			break ;
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(str[fd], buff)))
			return (ret);
		free(str[fd]);
		str[fd] = tmp;
	}
	return (ret);
}

static	void	ft_addln(char **str, char **line)
{
	int				after;
	char			*ptr;
	int				len;
	char			*tmp;

	if (!(ptr = ft_strchr(*str, '\n')))
		ptr = ft_strchr(*str, '\0');
	len = ptr - *str;
	*line = ft_strsub(*str, 0, len);
	after = ft_strlen(*(str) + len + 1);
	if (!(*ptr))
		tmp = ft_strnew(0);
	else
		tmp = ft_strsub(*(str) + len + 1, 0, after);
	free(*str);
	*str = tmp;
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*str[FD_SIZE];
	int				ret;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	if (str[fd] == NULL && !(str[fd] = ft_strnew(0)))
		return (-1);
	ret = ft_readln(fd, str);
	if (ret < BUFF_SIZE && !ft_strlen(str[fd]))
		return (0);
	if (str[fd])
	{
		ft_addln(&str[fd], line);
		return (1);
	}
	else
		return (-1);
}
