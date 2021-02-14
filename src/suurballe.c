/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:45 by mellie            #+#    #+#             */
/*   Updated: 2020/12/09 16:05:15 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		fill_moves(t_sol *s)
{
	int		j;
	int		v;

	j = 0;
	v = s->s;
	s->count_p = 0;
	while (j < s->n)
	{
		if (s->links[j * s->n + v] == 1)
		{
			init_next_path(s);
			s->moves[s->num_p] = (int *)malloc(sizeof(int) * s->n);
			init_arr(s->moves[s->num_p], s->n, s->e);
			depth(s, s->num_p);
			s->num_p++;
			s->count_p++;
			s->links[j * s->n + v] = 0;
		}
		j++;
	}
	sort_paths(s);
}

int			check_se(t_lemin *lem)
{
	int		i;

	if ((lem->links[lem->start_id * lem->n_rooms + lem->end_id] != 1) &&
		(lem->links[lem->end_id * lem->n_rooms + lem->start_id] != 1))
		return (1);
	i = 0;
	while (i < lem->n_ants)
	{
		ft_printf("L%d-%s ", i + 1, lem->end->name);
		i++;
	}
	ft_printf("\n");
	return (0);
}

void		init_sol(t_sol *sol, t_lemin *lem)
{
	sol->n_ant = lem->n_ants;
	sol->n = lem->n_rooms;
	sol->s = lem->start_id;
	sol->e = lem->end_id;
	sol->rooms = lem->rooms;
	sol->links = (int *)malloc(sizeof(int) * sol->n * sol->n);
	sol->par = (int *)malloc(sizeof(int) * sol->n);
	init_arr(sol->par, sol->n, -1);
	sol->paths = (t_pt *)malloc(sizeof(t_pt));
	sol->paths->path = NULL;
	sol->paths->len = 0;
	sol->paths->next = NULL;
	sol->first_path = sol->paths;
	sol->count_paths = 0;
	sol->moves = (int **)malloc(sizeof(int *) * sol->n);
	sol->count_p = 1;
	sol->num_p = 0;
	sol->traveler = sol->n_ant;
	sol->queue = sol->n_ant;
}

void		suurballe(t_lemin *lem)
{
	t_sol	*sol;

	if (!check_se(lem))
		return ;
	sol = (t_sol *)malloc(sizeof(t_sol));
	init_sol(sol, lem);
	cp_arr(lem->links, sol->links, sol->n * sol->n);
	while ((dijkstra(sol) < sol->n) && (sol->count_p < sol->n_ant))
		remove_fp(sol);
	if (sol->count_paths)
	{
		adjust_paths(sol);
		move_ants(sol);
	}
	else
		terminate(ERROR_SOL);
	free_sol(sol);
}
