#include "fractol.h"
#include "stdio.h"


void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	/* 		index = line_len * y + x * (bpp / 8) 
		*	This is the formula that gives the 
		*
		*/
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8) );
	*(int *)pixel = color;
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		i++;
	}
}

int	render(t_data *data)
{
	/* if windo has been destroyed, we don't want to put the pixel */
	if (!data->win_ptr)
		return (1);
	//render_background(&data->img, WHITE_PIXEL);
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	//printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	write(1, &keysym, 1);
	//printf("Keyrelease: %d\n", keysym);
	return (0);
}

int main(void)
{
	t_data data;
	int img_width;
	int	img_height;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	/* Setting up hooks!*/
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH , WINDOW_HEIGHT);
	data.img.mlx_img =  mlx_xpm_file_to_image(data.mlx_ptr, "./mountain.xpm",  &img_width, &img_height);

	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	printf("Line length: %d\n", data.img.line_len);
	//mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress,  KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.mlx_ptr);

	/* We execute this only we have no window left.*/
	mlx_destroy_image(data.mlx_ptr,  data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
