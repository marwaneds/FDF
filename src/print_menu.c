/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:47:22 by mel-faqu          #+#    #+#             */
/*   Updated: 2022/11/20 12:39:41 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_dot param)
{
	char *menu;

	menu = "up, down, left, right for move picture";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 1570, 5, 0xffffff, menu);
	menu = "5, spase for 3d/2d mode; +, - for zoom";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 1570, 20, 0xffffff, menu);
	menu = "8, 2 for z-scale; 4, 6 for rotation";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 1570, 35, 0xffffff, menu);
	menu = "f for full screen mode";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 1570, 50, 0xffffff, menu);
}