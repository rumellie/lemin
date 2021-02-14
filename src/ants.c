/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:11:53 by mellie            #+#    #+#             */
/*   Updated: 2020/12/08 17:49:59 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		init_ant(t_ants *ant, t_sol *s)
{
	int		i;

	i = 0;
	while (i < s->n_ant)
	{
		ant[i].path = -1;
		ant[i].room = s->s;
		ant[i].move = 0;
		i++;
	}
}

void		move_ant(t_ants *ant, t_sol *s, int i, char **rooms)
{
	ant[i].move++;
	ant[i].room = s->moves[ant[i].path][ant[i].move];
	ft_printf("L%d-%s ", i + 1, rooms[ant[i].room]);
}

void		make_move(t_ants *ant, t_sol *s, int i, char **rooms)
{
	if (ant[i].path >= 0)
	{
		move_ant(ant, s, i, rooms);
		if (ant[i].room == s->e)
		{
			ant[i].path = -2;
			s->traveler--;
		}
	}
	if ((ant[i].path == -1) && (s->num_p < s->count_p))
	{
		if (s->queue > enough(s->num_p, s->moves))
		{
			s->queue--;
			ant[i].path = s->num_p;
			move_ant(ant, s, i, rooms);
			s->num_p++;
		}
		else
			s->count_p = s->num_p;
	}
}

void		move_ants(t_sol *s)
{
	t_ants	*ant;
	char	**rooms;
	int		move;
	int		i;

	rooms = fill_rooms(s);
	s->free_count_p = s->count_p;
	move = 0;
	ant = (t_ants *)malloc(sizeof(t_ants) * s->n_ant);
	init_ant(ant, s);
	while (s->traveler > 0)
	{
		move++;
		s->num_p = 0;
		i = 0;
		while (i < s->n_ant)
		{
			make_move(ant, s, i, rooms);
			i++;
		}
		ft_printf("\n");
	}
	free(ant);
	free_sol_rooms(rooms, s->n);
}

int			enough(int n, int **move)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (i < n)
	{
		k += (move[n][0] - 1) - (move[i][0] - 1);
		i++;
	}
	return (k);
}
