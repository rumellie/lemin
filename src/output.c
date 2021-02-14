/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:26 by mellie            #+#    #+#             */
/*   Updated: 2020/12/09 15:01:40 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_res		*new_res(char *s)
{
	t_res	*new_res;

	new_res = (t_res *)malloc(sizeof(t_res));
	err_allocate(new_res);
	new_res->line = ft_strdup(s);
	new_res->next = NULL;
	return (new_res);
}

void		add_res(t_lemin *lem)
{
	t_res	*tmp;

	tmp = lem->res;
	if (!lem->res)
		lem->res = new_res(lem->line);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_res(lem->line);
	}
	ft_strdel(&(lem->line));
}

void		print_res(t_lemin *lem)
{
	t_res	*tmp;

	tmp = lem->res;
	while (tmp)
	{
		ft_putstr(tmp->line);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putstr("\n");
}
