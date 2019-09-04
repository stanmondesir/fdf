#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define SPACING 50
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
	void 	*ptr;
	char 	*data;
	int 	width;
	int 	height;
}Image;

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	Image	*img;

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
void print_array(int *array, int size);
//DEBUG FUNCTION !!

Image	*create_img(int width, int height, void *mlx_ptr);
void 	img_put_pixel(Image *img, int x, int y, int color);
t_map	*read_map(char *fp);
void 	draw_line(t_fdf fdf, Pixel start, Pixel end);
void 	put_grid(t_fdf fdf, t_map *map);
int 	get_height(t_map *map);
Color get_color(int int_color);
#endif
