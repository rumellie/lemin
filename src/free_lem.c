/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:02 by mellie            #+#    #+#             */
/*   Updated: 2020/12/08 17:58:00 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_words(char ***s)
{
	char	**tmp;

	if (s && *s)
	{
		tmp = *s;
		while (*tmp)
			free(*(tmp++));
		free(*s);
		*s = NULL;
	}
}

void		free_rooms(t_lemin *lem)
{
	t_room	*tmp;
	t_room	*head;

	if (lem->rooms)
	{
		head = lem->rooms;
		while (lem->rooms->next != head)
		{
			tmp = lem->rooms;
			if (lem->rooms->name)
				ft_strdel(&lem->rooms->name);
			lem->rooms = lem->rooms->next;
			free(tmp);
		}
		if (lem->rooms->name)
			ft_strdel(&lem->rooms->name);
		free(lem->rooms);
	}
}

void		free_res(t_res *res)
{
	t_res	*tmp;

	if (res)
	{
		while (res->next)
		{
			tmp = res;
			free(res->line);
			res->line = NULL;
			res = res->next;
			free(tmp);
		}
		free(res->line);
		res->line = NULL;
		free(res);
	}
}

void		free_lemin(t_lemin *lem)
{
	if (lem)
	{
		free_rooms(lem);
		free_res(lem->res);
		if (lem->line)
			ft_strdel(&lem->line);
		if (lem->links)
			free(lem->links);
		free(lem);
		lem = NULL;
	}
}
