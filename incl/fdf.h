#ifndef FDF_H
# define FDF_H
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126
# define BASE_COLOR 6618980
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct Pixels {
    int x;
    int y;
    int z;
	int color;
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
	struct s_row	*next;
}t_row;

typedef struct s_map {
	t_row 			*row;
	int				height;
	int 			max_height;
	int 			min_height;
}t_map;

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	int		win_width;
	int 	win_height;
	char 	*win_name;
	int		mode;
	int		palette;
	Image	*img;
	t_map 	*map;
	int 	map_height;
	int		spacing;
	int		amplify;
	int		x;
	int		y;
	int		x_offset;
	int		y_offset;
	int		cos;
    int		sin;
	int		lol_y;
	int		lol_x;
	Image	*bg;
	int 	vprwv;
}t_fdf;

//DEBUG FUNCTION !!
//REMOVE AT END OF PROJECT !!!!!!!
void print_map(t_row *map);
void print_array(int *array, int size);
//DEBUG FUNCTION !!

t_fdf	*init_fdf(char *map_path);
Image	*create_img(int width, int height, void *mlx_ptr);
void 	img_put_pixel(Image *img, int x, int y, int color);
t_map	*read_map(char *fp);
int		get_offset(t_fdf *fdf, t_map *map);
Pixel	get_pixel(t_fdf *fdf, t_row *row,int x, int y);
void 	draw_line(t_fdf *fdf, Pixel start, Pixel end);
void 	put_grid(t_fdf *fdf);
float	get_rad(int deg);
int 	get_int_color(int red, int green, int blue);
int 	get_color(Pixel current, Pixel start, Pixel end, Pixel delta);
void 	vprwv(t_fdf *fdf);
void 	set_color(t_fdf *fdf, int *color, int z);
int 	key_press(int key, void *param);
int 	key_hold(int key, void *param);
int 	mouse_press(int button, int x, int y, void *param);
int give_up(void *param);

#endif
