/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <smondesi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:23:22 by smondesi          #+#    #+#             */
/*   Updated: 2019/10/07 16:27:39 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

t_fdf	*init_fdf(char *map_path)
{
	t_fdf *fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		exit(1);
	fdf->map = read_map(map_path);
	fdf->mlx = mlx_init();
	fdf->win_width = 1920;
	fdf->win_height = 1080;
	fdf->spacing = (fdf->win_height) / (fdf->map->height + 5);
	fdf->amplify = 0;
	fdf->cos = 30;
	fdf->sin = 30;
	fdf->mode = 0;
	fdf->palette = 0;
	fdf->vprwv = 0;
	fdf->x = 0;
	fdf->y = 0;
	fdf->x_offset += abs(get_offset(fdf, fdf->map));
	fdf->y_offset = 0;
	fdf->win_name = map_path;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width,
			fdf->win_height, fdf->win_name);
	fdf->lol_x = 250;
	fdf->lol_y = 250;
	return (fdf);
}
