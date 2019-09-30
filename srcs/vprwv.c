#include "../incl/fdf.h"

Image	*ft_background(t_fdf *fdf, char* fp)
{
	Image *img;
	int bpp;
	int size_line;
	int endian;

	img = (Image *)malloc(sizeof(Image));
	img->ptr = mlx_xpm_file_to_image(fdf->mlx, fp, &img->width, &img->height);
	img->data = mlx_get_data_addr(img->ptr, &bpp, &size_line, &endian);
	printf("Width height : %d %d\n", img->width, img->height);
	return (img);
}

void 	vprwv(t_fdf *fdf)
{
	if (fdf->vprwv == 0)
	{
		system("afplay ./assets/hello.mp3&");
		fdf->bg = ft_background(fdf, "./assets/fdf_bg.xpm");
		fdf->vprwv = 1;
	}
	else
	{
		system("pkill afplay");
		fdf->vprwv = 0;
	}
}
