/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:50:23 by mel-faqu          #+#    #+#             */
/*   Updated: 2022/11/30 15:00:06 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.5;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 2.1;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr =\
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
}

int		main(int argc, char **argv)
{
	t_dot	**matrix;

	if (argc != 2)
		ft_error("Utilisation: ./fdf map.fdf");
	matrix = read_map(argv[1]);
	set_default(&PRM);
	draw(matrix);
	mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	mlx_loop(PRM.mlx_ptr);
}