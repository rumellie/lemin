/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:31 by mellie            #+#    #+#             */
/*   Updated: 2020/12/09 17:58:43 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		check_ants(t_lemin *lem)
{
	while ((lem->rlen = get_next_line(lem->fd, &(lem->line))) && !(lem->n_ants))
	{
		if (!(skip_line(lem)))
		{
			lem->n_ants = ft_atol(lem->line);
			if (lem->n_ants <= 0 || lem->n_ants > INT_MAX)
				terminate(ERR_1_NUM_ANTS);
			add_res(lem);
		}
		else
			add_res(lem);
	}
	if (lem->rlen == 0 && !(lem->n_ants))
		terminate(ERR_1_NUM_ANTS);
}

void		add_room(t_lemin *lem, t_room *room)
{
	if (!lem->n_rooms)
	{
		room->rind = 0;
		room->next = room;
		room->prev = room;
		lem->rooms = room;
	}
	else
	{
		room->rind = lem->rooms->prev->rind + 1;
		room->next = lem->rooms;
		room->prev = lem->rooms->prev;
		lem->rooms->prev->next = room;
		lem->rooms->prev = room;
	}
	lem->n_rooms++;
	if (lem->n_rooms > 46000)
		terminate(ERR_3_MAP_INVALID);
	start_end2(lem, room);
	add_res(lem);
}

void		add_link(t_lemin *lem, char **links)
{
	int		room1;
	int		room2;

	if (lem->start_id <= -1 || lem->end_id <= -1)
		terminate(ERR_7_START_END_NEXIST);
	room1 = get_indx(lem, links[0]);
	room2 = get_indx(lem, links[1]);
	lem->links[room1 * lem->n_rooms + room2] = 1;
	lem->links[room2 * lem->n_rooms + room1] = 1;
	free_words(&links);
	add_res(lem);
}

void		parse(t_lemin *lem)
{
	check_ants(lem);
	while (lem->rlen > 0)
	{
		if (!(skip_line(lem)))
		{
			if (!(is_link(lem->line, '-')))
				add_room(lem, valid_room(lem));
			else
			{
				init_links(lem);
				add_link(lem, valid_link(lem));
			}
		}
		else
			add_res(lem);
		lem->rlen = get_next_line(lem->fd, &lem->line);
	}
	if (lem->rlen == 0 && (!(lem->n_ants) || !(lem->rooms) || !(lem->links)))
		terminate(ERR_3_MAP_INVALID);
}
