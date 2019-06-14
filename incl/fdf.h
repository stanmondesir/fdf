#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define WIN_NAME "fdf"
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct Colors {
	int r;
	int g;
	int b;
	int a;
}Color;

typedef struct Pixels {
    int x;
    int y;
    int z;
	Color color;
}Pixel;

typedef struct Images{
	void *ptr;
	char *data;
}Image;

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	Image	img;

}t_fdf;

typedef struct s_row {
	int	*content;
	int	len;
}t_row;

typedef struct s_map {
	t_row 			row;
	struct s_map	*next;
}t_map;

//DEBUG FUNCTION !!
//REMOVE AT END OF PROJECT !!!!!!!
void print_map(t_map *map);
//DEBUG FUNCTION !!

Image	create_img(int width, int height, void *mlx_ptr);
t_map	*read_map(char *fp);
#endif
