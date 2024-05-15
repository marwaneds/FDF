/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:52:32 by mel-faqu          #+#    #+#             */
/*   Updated: 2022/11/14 17:06:44 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_dots_from_line(char *line, t_dot **matrix_dot, int y)
{
	char	**dots;
	int		x;
	
	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x])
	{
		matrix_dot[y][x].z = ft_atoi(dots[x]);
		matrix_dot[y][x].x = x;
		matrix_dot[y][x].y = y;
		matrix_dot[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix_dot[y][--x].is_last = 1;
	return (x);
}

t_dot	**memory_allocated(char *file_name)
{
	t_dot	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	if	((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_error("the file does not exist");
	get_next_line(fd, &line);
	x = ft_wordcount(line, ' ');
	free(line);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		free(line);
	}
	free(line);
	new = (t_dot **)malloc(sizeof(t_dot *) * (++y + 1));
	while (y > 0)
		new[--y] = (t_dot *)malloc(sizeof(t_dot) * (x + 1));
	close(fd);
	return (new);
}

t_dot	**read_map(char *file_name)
{
	t_dot	**matrix_dot;
	int		y;
	int		fd;
	char	*line;
	
	matrix_dot = memory_allocated(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd, &line) > 0)
		get_dots_from_line(line, matrix_dot, y++);
	free(line);
	matrix_dot[y] = NULL;
	close(fd);
	return (matrix_dot);
}