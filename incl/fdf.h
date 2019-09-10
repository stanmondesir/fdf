#ifndef FDF_H
# define FDF_H
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
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

typedef struct s_row {
	int	*content;
	int	len;
}t_row;

typedef struct s_map {
	t_row 			row;
	struct s_map	*next;
}t_map;

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	int		win_width;
	int 	win_height;
	char 	*win_name;
	Image	*img;
	t_map 	*map;
	int		spacing;
	int		x_offset;
	int		y_offset;
}t_fdf;

//DEBUG FUNCTION !!
//REMOVE AT END OF PROJECT !!!!!!!
void print_map(t_map *map);
void print_array(int *array, int size);
//DEBUG FUNCTION !!

t_fdf	*init_fdf(char *map_path);
Image	*create_img(int width, int height, void *mlx_ptr);
void 	img_put_pixel(Image *img, int x, int y, int color);
t_map	*read_map(char *fp);
Pixel	get_pixel(t_fdf *fdf, int x, int y);
void 	draw_line(t_fdf *fdf, Pixel start, Pixel end);
void 	put_grid(t_fdf *fdf);
int 	get_height(t_map *map);
Color get_color(int int_color);
#endif
