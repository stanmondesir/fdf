#include "../incl/fdf.h"

// void draw_line(t_fdf fdf, int x1, int y1, int x2, int y2, int color)
// {
// 	int x,y,end,p,dx,dy;
//
// 	dx=abs(x1-x2);
// 	dy=abs(y1-y2);
// 	p = 2*dy-dx;
// 	if(x1>x2)
// 	{
// 		x=x2;
// 		y=y2;
// 		end=x1;
// 	}
// 	else
// 	{
// 		x=x1;
// 		y=y1;
// 		end=x2;
// 	}
// 	mlx_pixel_put(fdf.mlx, fdf.win, x, y, color);
// 	while(x<=end)
// 	{
// 		if(p<0)
// 		{
// 			x++;
// 			p=p+2*dy;
// 		}
// 		else
// 		{
// 			x++;
// 			y++;
// 			p=p+2*(dy-dx);
// 		}
// 		mlx_pixel_put(fdf.mlx, fdf.win, x, y, color);
// 	}
// }

/* ALGO DE STAN
void draw_line(t_fdf fdf, int x1, int y1, int x2, int y2, int color)
{
    int dx;
    int dy;
    int xinc;
    int yinc;
    int i;
    int x;
    int y;
    int cumul;

    dx = x2 - x1;
    dy = y2 - y1;
    xinc = (dx > 0) ? 1 : -1;
    yinc = (dy > 0) ? 1 : -1;
    dx = abs(dx);
    dy = abs(dy);
    x = x1;
    y = y1;

    if (dx > dy)
        return ;
    cumul = dy / 2;
    i = 1;
    while (i <= dy)
    {
        i++;
        y += yinc;
        cumul += dx;
        if (cumul >= dy)
        {
            cumul -= dy;
            x += xinc;
        }
        mlx_pixel_put ( fdf.mlx, fdf.win, x, y,  color);
    }

}
*/

void draw_line(t_fdf fdf, int x1, int y1, int x2, int y2, int color)
{
	int x,y,dx,dy,dx1,dy1,px,py,xe,ye;
	dx=x2-x1;
	dy=y2-y1;
	dx1=abs(dx);
	dy1=abs(dy);
	px=2*dy1-dx1;
	py=2*dx1-dy1;
	if(dy1<=dx1)
	{
		if(dx>=0)
		{
			x=x1;
			y=y1;
			xe=x2;
		}
		else
		{
			x=x2;
			y=y2;
			xe=x1;
		}
		mlx_pixel_put(fdf.mlx, fdf.win, x, y, color);
		while(x<xe)
		{
			x++;
			if(px<0)
				px=px+2*dy1;
			else
			{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
					y=y+1;
				else
					y=y-1;
				px=px+2*(dy1-dx1);
			}
			mlx_pixel_put(fdf.mlx, fdf.win, x, y, color);
		}
	}
	else
	{
		if(dy>=0)
		{
			x=x1;
			y=y1;
			ye=y2;
		}
		else
		{
			x=x2;
			y=y2;
			ye=y1;
		}
		mlx_pixel_put(fdf.mlx, fdf.win, x, y, color);
		while(y<ye)
		{
			y++;
			if(py<=0)
				py=py+2*dx1;
			else
			{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
					x=x+1;
				else
					x=x-1;
				py=py+2*(dx1-dy1);
			}
			mlx_pixel_put(fdf.mlx, fdf.win, x, y, color);
		}
	}
}
