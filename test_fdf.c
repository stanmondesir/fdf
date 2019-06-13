/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:22:46 by smondesi          #+#    #+#             */
/*   Updated: 2019/05/21 12:26:29 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "minilibx_macos/mlx.h"
#include "get_next_line_V1/get_next_line.h"
#include "libft.h"

typedef struct Coords
{
	int x;
	int y;
	int z;
}Coord;

int shut_the_f_up (int Key, void *param)
{
	if (Key == 53)
	{
		exit(1);
	}
	return (0);
}

void	ligne(void *mlx_ptr, void *win_ptr, Coord in, Coord fi)
{
	int dx;
	int dy;
	int xinc;
	int yinc;
	int i;
	int x;
	int y;
	int cumul;

	dx = fi.x - in.x;
	dy = fi.y - in.y;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	x = in.x;
	y = in.y;

	if (dx > dy)
		return ;	
	cumul = dy / 2;
	i = 1;
	while (i <= dy)
	{
		i++;
		y += yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			x += xinc;
		}
		mlx_pixel_put ( mlx_ptr, win_ptr, x, y,  16777215);
	}

}


int main()
{
	char	*line;
	char	**pop;
	int		fd;
	Coord	coord;
	Coord	screen;
	Coord	last;
	void	*mlx_ptr;
	void	*win_ptr;
	int p;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2500, 1600, "yop");

	coord.x = 0;
	p = 0;
	fd = open("42.fdf", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		coord.y++;
		pop = ft_strsplit(line, ' ');
		while (pop[coord.x])
		{	
			coord.z = ft_atoi(pop[coord.x]);
			coord.x++;
			last = screen;
			screen.x = (coord.x - coord.y) * 32 + 500;
			screen.y = (coord.x + coord.y) * 32 - coord.z * 10 + 500;
			if(p == 2)
				ligne (mlx_ptr, win_ptr, screen, last);
		//				mlx_pixel_put (mlx_ptr, win_ptr, screen.x, screen.y,);
		//	mlx_pixel_put (mlx_ptr, win_ptr, coord.x * 50, (coord.y * 50  - coord.z * 5), 16777215 - coord.z * 50 );
		}
		p = 2;
		coord.x = 0;
	}
	mlx_key_hook(win_ptr, shut_the_f_up, 0);
	mlx_loop (mlx_ptr);
}
