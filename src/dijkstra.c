/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:23:32 by mellie            #+#    #+#             */
/*   Updated: 2020/12/09 14:07:50 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		next_v(int s, int v, int n, int *links)
{
	int i;

	i = v;
	while (i < n)
	{
		if (links[s + i * n] == 1)
			return (i);
		i++;
	}
	return (-1);
}

void	depth(t_sol *s, int i)
{
	int v;
	int	j;

	v = s->s;
	j = 0;
	s->moves[i][j] = v;
	while (v != s->e)
	{
		v = next_v(v, 0, s->n, s->links);
		j++;
		s->moves[i][j] = v;
	}
	s->moves[i][0] = j;
}

void	dij_count(t_sol *s, int *used, int *dist)
{
	int i;
	int v;

	v = s->s;
	while ((v != s->e) && (v < s->n))
	{
		if (s->par[v] != -1)
		{
			used[v] = 1;
			if (dist[s->par[v]] > dist[v] + s->links[v + s->par[v] * s->n])
				dist[s->par[v]] = dist[v] + s->links[v + s->par[v] * s->n];
			v = s->par[v];
		}
		i = 0;
		while (i < s->n)
		{
			if ((s->links[v + i * s->n] != 0) && used[i] == 0)
				if (dist[i] > dist[v] + s->links[v + i * s->n])
					dist[i] = dist[v] + s->links[v + i * s->n];
			i++;
		}
		used[v] = 1;
		v = ft_min(dist, used, s->n);
	}
}

int		dijkstra(t_sol *s)
{
	int	*used;
	int	*dist;
	int	tmp;

	used = (int *)malloc(sizeof(int) * s->n);
	dist = (int *)malloc(sizeof(int) * s->n);
	err_allocate(dist);
	init_arr(used, s->n, 0);
	init_arr(dist, s->n, s->n);
	dist[s->s] = 0;
	dij_count(s, used, dist);
	if (dist[s->e] < s->n)
		rest_path(s, dist);
	tmp = dist[s->e];
	free(used);
	free(dist);
	return (tmp);
}

void	remove_fp(t_sol *s)
{
	int	i;

	i = 0;
	while (i < s->paths->len)
	{
		s->links[s->paths->path[i + 1] * s->n + s->paths->path[i]] = 0;
		i++;
	}
}
