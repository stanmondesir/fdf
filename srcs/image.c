#include "../incl/fdf.h"

Image	*create_img(int width, int height, void *mlx_ptr)
{
	int     bpp;
	int     size_line;
	int     endian;
	Image	*img;

	img = malloc(sizeof(Image));
	img->ptr = mlx_new_image(mlx_ptr, width, height);
	img->data =  mlx_get_data_addr(img->ptr, &bpp, &size_line, &endian);
	img->width = width;
	img->height = height;

	return (img);
}

void img_put_pixel(Image *img, int x, int y, int color)
{

	int 	start_pos;
	Color 	rgb_color;

	rgb_color = get_color(color);
	start_pos = (4 * x) + (4 * img->width * y);
	//printf("%d : (%d, %d, %d)\n", start_pos,rgb_color.r, rgb_color.g, rgb_color.b);
	img->data[start_pos] = rgb_color.b;
	//printf("R done\n");
	img->data[start_pos + 1] = rgb_color.g;
	//printf("G done\n");
	img->data[start_pos + 2] = rgb_color.r;
	//printf("B done\n");
}
