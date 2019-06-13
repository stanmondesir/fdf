/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:22:46 by smondesi          #+#    #+#             */
/*   Updated: 2018/11/19 17:56:49 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "minilibx_macos/mlx.h"
#include "get_next_line_V1/libft/libft.h"
#include "get_next_line_V1/get_next_line.h"

//gcc tets.c -I ./minilibx_macos  -L ./minilibx_macos -lmlx -framework OpenGL -framework Appkit
typedef struct Coords
{
	int x;
	int y;
	int z;
}Coord;

int shut_the_f_up (int Key, void *param)
{
	if (Key == 53)
		exit(1);
	return (0);
}

void	ligne(void *mlx_ptr, void *win_ptr, Coord in, Coord fi)
{
	Coord d;
	Coord inc;
	int i;
	int cumul;

	d.x = abs(fi.x - in.x);
	d.y = abs(fi.y - in.y);
	inc.x = ((fi.x - in.x) > 0) ? 1 : -1;
	inc.y = ((fi.y - in.y) > 0) ? 1 : -1;
	if (d.x > d.y)
		return ;	
	cumul = d.y / 2;
	i = 1;
	while (i <= d.y)
	{
		i++;
		in.y += inc.y;
		cumul += d.x;
		if (cumul >= d.y)
		{
			cumul -= d.y;
			in.x += inc.x;
		}
		mlx_pixel_put ( mlx_ptr, win_ptr, in.x, in.y,  16777215);
	}
	/**voire comment faire meilleur ligne**/
}

int main()
{
	char	*line;
	char	*line2;
	char	**pop;
	int		fd;
	Coord	coord;
	Coord	**screen;
	void	*mlx_ptr;
	void	*win_ptr;
	int		*p;
	int		y;
	int		x;

	y = 0;
	x = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2500, 1600, "yop");
	coord.x = 0;
	coord.y = 0;
	fd = open("julia.fdf", O_RDONLY);
	while (get_next_line(fd, &line2) > 0)
	{
		coord.y++;
		free(line2);
	}
	if(!(screen = (Coord **)malloc (sizeof(Coord*) * coord.y)))
		return (0);
	close (fd);
	coord.y = 0;
	fd = open("julia.fdf", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(screen[coord.y] = (Coord *)malloc (sizeof(Coord) * (ft_count_words(line, ' ') + 1))))
		{
			while (coord.y--)
				free(screen[coord.y]);
			free(screen);
			return(0);
		}
		printf("%d %d\n", ft_count_words(line, ' '), coord.y);
		pop = ft_strsplit(line, ' ');
		while (pop[coord.x])
		{
			screen[coord.y][coord.x].z = ft_atoi(pop[coord.x]);
			screen[coord.y][coord.x].x = (coord.x - coord.y) * 2 + 1500;
			screen[coord.y][coord.x].y = (coord.x + coord.y) * 2 - screen[coord.y][coord.x].z * 2 + 150;
			coord.x++;
		}
		coord.x = 0;
		coord.y++;
		free(line);
	}
	printf("%d\n", coord.y);
	while (y < coord.y)
	{
		while (x < 400)
		{
			ligne (mlx_ptr, win_ptr, screen[y][x], screen[y][x + 1]);
	//		mlx_pixel_put ( mlx_ptr, win_ptr, screen[y][x].x, screen[y][x].y,  16777215);
			x++;
		}
		x = 0;
		y++;
	}
	x = 0;
	y = 0;	
	while (x < 27)
	{
		while (y < (coord.y - 1))
		{
			ligne (mlx_ptr, win_ptr, screen[y][x], screen[y + 1][x]);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_key_hook(win_ptr, shut_the_f_up, 0);
	mlx_loop (mlx_ptr);
	while (coord.y--)
		free(screen[coord.y]);
	free(screen);
	return(0);
}
