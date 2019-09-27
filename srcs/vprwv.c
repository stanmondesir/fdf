#include "../incl/fdf.h"

static void	data_bg(t_fdf *fdf, char *image_data)
{
	int y;
	int x;
	int i;

	y = 0;
	while (y < fdf->win_height)
	{
		x = 0;
		while (x < fdf->win_width)
		{
			i = (x * 4 + 4 * fdf->win_width * y);
			image_data[i] = 101;
			image_data[i + 1] = 30;
			image_data[i + 2] = 73;
			x++;
		}
		y++;
	}
}

static void	*ft_background(t_fdf *fdf)
{
	void *img;
	int bpp;
	int size_line;
	int endian;
	int width;
	int height;
	char *image_data;

	img = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	image_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	data_bg(fdf, image_data);
	img = mlx_xpm_file_to_image(fdf->mlx, "fdf_bg.xpm", &width, &height);
	return (img);
}

void 	vprwv(t_fdf *fdf)
{
	system("afplay hello.mp3&");
	fdf->bg = ft_background(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win , fdf->bg, 0, 0);
}
