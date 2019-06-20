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

/*
void img_put_pixel(Image *img, Pixel pixel)
{

	int 	start_pos;

	start_pos = (4 * x) + (4 * img->width * y);
	img->data[start_pos] = color.r;
	img->data[start_pos + 1] = color.g;
	img->data[start_pos + 2] = color.b;
}
*/
