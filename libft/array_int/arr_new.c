/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:52:58 by Nik               #+#    #+#             */
/*   Updated: 2022/11/14 17:11:36 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

int		*arr_new(char *arr)
{
	int		*new;
	int		len;
	char	**tmp;
	int		i;
	int		j;
	
	tmp = ft_split(arr, ' ');
	len = ft_arraylen(tmp);
	new = (int *)malloc(sizeof(int) * (len + 1));
	i = 1;
	j = 0;
	new[0] = len;
	while (tmp[j])
	{
		if (check_arr_input(tmp[j]))
		{
			j++;
			new[0]--;
			continue ;
		}
		new[i++] = ft_atoi(tmp[j++]);
	}
	ft_arrayfree(tmp);
	return (new);
}
