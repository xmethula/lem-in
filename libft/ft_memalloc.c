#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = (void *)malloc(size);
	if (mem == NULL)
	{
		return (NULL);
	}
	ft_bzero(mem, size);
	return (mem);
}
