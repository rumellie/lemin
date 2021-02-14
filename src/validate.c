/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:54 by mellie            #+#    #+#             */
/*   Updated: 2020/12/09 16:28:18 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*check_dupl(t_lemin *lem, char **s)
{
	int		i;
	t_room	*cur;
	t_room	*room;

	room = (t_room *)malloc(sizeof(t_room));
	err_allocate(room);
	room->name = ft_strdup(s[0]);
	room->x = ft_atol(s[1]);
	room->y = ft_atol(s[2]);
	if (lem->n_rooms > 0)
	{
		cur = lem->rooms;
		i = 0;
		while ((cur != lem->rooms) || ((i == 0) && (cur == lem->rooms)))
		{
			if (!(ft_strcmp(cur->name, s[0])))
				terminate(ERR_6_DUP_ROOM);
			if ((cur->x == room->x) && (cur->y == room->y))
				terminate(ERR_6_DUP_ROOM);
			cur = cur->next;
			i++;
		}
	}
	free_words(&s);
	return (room);
}

void		start_end(t_lemin *lem)
{
	if (!(ft_strcmp(lem->line, "##start")))
	{
		if (lem->start_id != -2 || (lem->start_id == -2 && lem->end_id == -1))
			terminate(ERR_5_DUP_STEN);
		else if (lem->n_ants == 0 || lem->links)
			terminate(ERR_9_ROOM_NOT_EXPECTED);
		else
			lem->start_id = -1;
	}
	else if (!(ft_strcmp(lem->line, "##end")))
	{
		if (lem->end_id != -2 || (lem->end_id == -2 && lem->start_id == -1))
			terminate(ERR_5_DUP_STEN);
		else if (lem->n_ants == 0 || lem->links)
			terminate(ERR_9_ROOM_NOT_EXPECTED);
		else
			lem->end_id = -1;
	}
}

void		start_end2(t_lemin *lem, t_room *room)
{
	if (lem->start_id == -1)
	{
		lem->start_id = room->rind;
		lem->start = room;
	}
	if (lem->end_id == -1)
	{
		lem->end_id = room->rind;
		lem->end = room;
	}
}

t_room		*valid_room(t_lemin *lem)
{
	char	**words;
	int		i;

	if (lem->n_ants == 0 || lem->links)
		terminate(ERR_9_ROOM_NOT_EXPECTED);
	words = ft_strsplit(lem->line, ' ');
	i = 0;
	while (words[i])
		i++;
	if (i != 3 || (words[0][0] == 'L'))
		terminate(ERROR);
	i = 1;
	while (words[i])
	{
		if (ft_atol(words[i]) > INT_MAX || ft_atol(words[i]) < INT_MIN)
			terminate(ERROR);
		i++;
	}
	return (check_dupl(lem, words));
}

char		**valid_link(t_lemin *lem)
{
	char	**links;
	int		i;
	int		j;
	int		count;
	t_room	*cur;

	links = ft_strsplit(lem->line, '-');
	i = 0;
	while (links[i])
	{
		j = 0;
		count = 0;
		cur = lem->rooms;
		while (j++ < lem->n_rooms)
		{
			if (!(ft_strcmp(links[i], cur->name)))
				count++;
			cur = cur->next;
		}
		if (!count)
			terminate(ERR_8_ROOM_NEXIST);
		i++;
	}
	return (links);
}
