#include "../incl/fdf.h"

static void print_array(int *array, int size)
{
	int i;

	i = 0;
	ft_putchar('[');
	while (i < size)
	{
		ft_putnbr(array[i]);
		if (i < size - 1)
			ft_putchar(',');
		i++;
	}
	ft_putendl("]");
}

void print_map(t_map *map)
{
	while (map->next != NULL)
	{
		print_array(map->row.content, map->row.len);
		map = map->next;
	}
}
