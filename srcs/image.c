#include "../incl/fdf.h"

Image	create_img(int width, int height, void *mlx_ptr)
{
	int     bpp;
	int     size_line;
	int     endian;
	Image	img;

	img.ptr = mlx_new_image(mlx_ptr, width, height);
	img.data =  mlx_get_data_addr(img.ptr, &bpp, &size_line, &endian);

	return (img);
}
