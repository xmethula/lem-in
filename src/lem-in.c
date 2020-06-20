#include "../includes/lem_in.h"

int		main(void)
{
	t_list	*input;
	t_farm	farm;

	if (analyze_map_data(&input, &farm) && 
        find_path(&farm))
		ft_print_out(input, farm.turns);
	else
		ft_error();
	ft_free_list(&input, ft_free);
	ft_free_farm(&farm);
	return (0);
}
