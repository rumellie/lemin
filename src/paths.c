/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:40 by mellie            #+#    #+#             */
/*   Updated: 2020/12/09 14:08:21 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		init_next_path(t_sol *s)
{
	s->paths->next = (t_pt *)malloc(sizeof(t_pt));
	s->paths = s->paths->next;
	s->paths->path = NULL;
	s->paths->len = 0;
	s->paths->next = NULL;
}

void		count_path(t_sol *s, int *dist, int *v)
{
	int		k;
	int		i;

	init_next_path(s);
	s->paths->path = (int *)malloc(sizeof(int) * (dist[s->e] + 1));
	init_arr(s->paths->path, dist[s->e] + 1, s->e);
	*v = s->e;
	k = dist[s->e] - 1;
	while ((*v != s->s) && (k >= 0))
	{
		i = 0;
		while (i < s->n)
		{
			if (s->links[*v * s->n + i] != 0)
				if (dist[s->paths->path[k + 1]] == dist[i] + 1)
				{
					s->paths->path[k] = i;
					s->par[s->paths->path[k + 1]] = i;
				}
			i++;
		}
		*v = s->paths->path[k];
		k--;
	}
}

void		rest_path(t_sol *s, int *dist)
{
	int		v;
	int		*tmp;
	t_pt	*savpt;

	tmp = (int *)malloc(sizeof(int) * s->n);
	cp_arr(s->par, tmp, s->n);
	savpt = s->paths;
	count_path(s, dist, &v);
	if (v == s->s)
	{
		s->paths->len = dist[s->e];
		s->count_paths++;
	}
	else
	{
		cp_arr(tmp, s->par, s->n);
		free(s->paths->path);
		s->paths->path = NULL;
		free(s->paths);
		s->paths = NULL;
		s->paths = savpt;
		dist[s->e] = s->n;
	}
	free(tmp);
}

void		sort_paths(t_sol *s)
{
	int		i;
	int		j;

	i = 0;
	while (i < s->count_p - 1)
	{
		j = i + 1;
		while (j < s->count_p)
		{
			if (s->moves[i][0] > s->moves[j][0])
				swap_arrays(s->moves[i], s->moves[j], s->n);
			j++;
		}
		i++;
	}
}

void		adjust_paths(t_sol *s)
{
	t_pt	*p;
	int		i;

	init_arr(s->links, s->n * s->n, 0);
	p = s->first_path;
	while (p)
	{
		i = 0;
		while (i < p->len)
		{
			if (((s->links[p->path[i] + p->path[i + 1] * s->n]) == 0) &&
				((s->links[p->path[i + 1] + p->path[i] * s->n]) == 0))
				s->links[p->path[i] + p->path[i + 1] * s->n] = 1;
			else
			{
				s->links[p->path[i] + p->path[i + 1] * s->n] = -1;
				s->links[p->path[i + 1] + p->path[i] * s->n] = -1;
			}
			i++;
		}
		p = p->next;
	}
	fill_moves(s);
}
