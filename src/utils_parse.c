/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:49 by mellie            #+#    #+#             */
/*   Updated: 2020/12/09 15:27:43 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			is_link(char *s, char c)
{
	int		count_min;
	char	*tmp;

	count_min = 0;
	tmp = s;
	while (*tmp && *tmp != '\t' && *tmp != ' ')
	{
		if (*tmp == c)
			count_min++;
		tmp++;
	}
	if (count_min > 1)
		terminate(ERR_4_INV_LNK);
	return (count_min);
}

int			skip_line(t_lemin *lem)
{
	int		skip;

	skip = 0;
	if (*(lem->line) == '\0' || *(lem->line) == '\n')
		terminate(ERR_2_EMPTY_LINE);
	if (lem->line[0] == '#' && lem->line[1] == '#')
	{
		start_end(lem);
		skip = 1;
	}
	else if (lem->line[0] == '#')
		skip = 1;
	else
		skip = 0;
	return (skip);
}

int			get_indx(t_lemin *lem, char *s)
{
	int		ind;
	t_room	*tmp;

	ind = 0;
	tmp = lem->rooms;
	while (ind < lem->n_rooms)
	{
		if (!(ft_strcmp(tmp->name, s)))
			return (ind);
		ind++;
		tmp = tmp->next;
	}
	return (-1);
}
