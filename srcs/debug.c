#include "../incl/fdf.h"

void print_array(int *array, int size)
{
	int i;

	i = 0;
	ft_putchar('[');
	while (i < size)
	{
		ft_putnbr(array[i]);
		if (i < size - 1)
			ft_putstr(", ");
		i++;
	}
	ft_putendl("]");
}

void print_map(t_map *map)
{
	t_map *cpy;

	cpy = map;
	while (cpy != NULL)
	{
		print_array(cpy->row.content, cpy->row.len);
		cpy = cpy->next;
	}
}
