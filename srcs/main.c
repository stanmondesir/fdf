/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <smondesi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:28:47 by smondesi          #+#    #+#             */
/*   Updated: 2019/10/07 16:31:31 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	del_fdf(t_fdf *fdf)
{
	t_row	*row;
	int		i;

	row = fdf->map->row;
	i = -1;
	while (row->next)
	{
		ft_memdel((void *)&row->content);
		row = row->next;
	}
	ft_memdel((void *)&row);
	ft_memdel((void *)&fdf->map);
	ft_memdel((void *)&fdf->bg);
	free(fdf->mlx);
	free(fdf->win);
	ft_memdel((void *)&fdf);
}

int		give_up(void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (fdf->vprwv == 1)
		system("pkill afplay");
	del_fdf(fdf);
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf *fdf;

	if (argc != 2)
	{
		ft_putendl("USAGE : ./fdf [fdf file]");
		return (0);
	}
	fdf = init_fdf(argv[1]);
	printf("PRINT FDF : map_height : %d\n", fdf->map->height);
	printf("Rendering fdf\n");
	put_grid(fdf);
	printf("%s\n", "FDF Rendered");
	mlx_hook(fdf->win, 17, 0, give_up, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 2, 0, key_hold, fdf);
	mlx_key_hook(fdf->win, key_press, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
