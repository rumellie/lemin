/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:35 by mellie            #+#    #+#             */
/*   Updated: 2020/12/08 18:12:01 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		init_arr(int *ar, int n, int c)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ar[i] = c;
		i++;
	}
}

void		cp_arr(int *source, int *dest, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
}

int			ft_min(int *ar, int *check, int n)
{
	int		min;
	int		min_i;
	int		i;

	i = 0;
	min_i = n;
	min = n;
	while (i < n)
	{
		if ((ar[i] < min) && (!check[i]))
		{
			min_i = i;
			min = ar[i];
		}
		i++;
	}
	return (min_i);
}

void		swap_arrays(int *ar1, int *ar2, int n)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < n)
	{
		tmp = ar1[i];
		ar1[i] = ar2[i];
		ar2[i] = tmp;
		i++;
	}
}

char		**fill_rooms(t_sol *s)
{
	char	**ar;
	int		i;

	i = 0;
	ar = (char **)malloc(sizeof(char *) * s->n);
	while (i < s->n)
	{
		ar[i] = (char *)malloc(sizeof(char) * ft_strlen(s->rooms->name) + 1);
		ft_strcpy(ar[i], s->rooms->name);
		s->rooms = s->rooms->next;
		i++;
	}
	return (ar);
}
