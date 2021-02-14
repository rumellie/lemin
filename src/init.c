/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:16 by mellie            #+#    #+#             */
/*   Updated: 2020/12/08 18:01:56 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin		*init_lem(void)
{
	t_lemin	*lem;

	lem = (t_lemin *)malloc(sizeof(t_lemin));
	err_allocate(lem);
	lem->n_ants = 0;
	lem->fd = 0;
	lem->rlen = 0;
	lem->line = NULL;
	lem->res = NULL;
	lem->start_id = -2;
	lem->end_id = -2;
	lem->n_rooms = 0;
	lem->links = NULL;
	return (lem);
}

void		init_links(t_lemin *lem)
{
	if (!lem->links)
	{
		if (!lem->start || !lem->end)
			terminate(ERR_7_START_END_NEXIST);
		lem->links = (int*)malloc(sizeof(int) * lem->n_rooms * lem->n_rooms);
		err_allocate(lem->links);
		init_arr(lem->links, lem->n_rooms * lem->n_rooms, 0);
	}
}
