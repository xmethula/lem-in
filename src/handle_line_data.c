#include "../includes/lem_in.h"

int			read_map(const int fd, char **data, char c)
{
	char		buff;
	char		*temp;
	size_t		result;
	size_t		size;

	if (!data || fd < 0)
		return (-1);
	*data = NULL;
	size = 0;
	while ((result = read(fd, &buff, 1)) > 0)
	{
		if (buff == c)
			return (1);
		++size;
		temp = *data;
		*data = ft_strnew(size);
		if (temp)
			ft_strcpy(*data, temp);
		(*data)[size - 1] = buff;
		if (temp)
			free(temp);
	}
	return (0);
}

static int get_line_data(t_list **input, char *data)
{
	size_t line_size;
	t_list *line_new;
	int line_length;

	line_length = ft_strlen(data);
	if ((line_size = line_length) == 0)
	{
		return (0);
	}
	if ((line_new = ft_lstnew(data, line_size + 1)) == 0)
	{
		free(data);
		return (0);
	}
	ft_lstappend(input, line_new);
	free(data);
	return (1);
}

int handle_line_data(t_list **input)
{
	char *data;
	int result;

	data = NULL;
	*input = NULL;
	while ((result = read_map(0, &data, '\n')) > 0)
	{	
		if(!data)
			break;
		if (get_line_data(input, data) == 0)
			return (0);
	}
	if (data != NULL && get_line_data(input, data) == 0)
		return (0);
	return (1);
}
