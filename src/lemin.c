/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:21 by mellie            #+#    #+#             */
/*   Updated: 2020/12/08 18:02:54 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(int argc, char **av)
{
	t_lemin	*lem;

	(void)av;
	if (argc != 1)
		ft_putendl_fd(LEMIN_USAGE, 2);
	lem = init_lem();
	parse(lem);
	print_res(lem);
	suurballe(lem);
	free_lemin(lem);
}
