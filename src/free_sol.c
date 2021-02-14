/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:24:09 by mellie            #+#    #+#             */
/*   Updated: 2020/12/09 14:08:09 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_sol(t_sol *sol)
{
	int		i;

	if (sol)
	{
		if (sol->links)
			free(sol->links);
		if (sol->par)
			free(sol->par);
		if (sol->moves)
		{
			i = 0;
			while (i < sol->free_count_p)
				free(sol->moves[i++]);
			free(sol->moves);
		}
		free_sol_paths(sol);
		free(sol);
	}
}

void		free_sol_rooms(char **rooms, int n)
{
	int i;

	if (rooms)
	{
		i = 0;
		while (i < n)
		{
			free(rooms[i]);
			i++;
		}
		free(rooms);
	}
}

void		free_sol_paths(t_sol *sol)
{
	t_pt	*tmp;

	if (sol->paths)
	{
		sol->paths = sol->first_path;
		while (sol->paths->next)
		{
			tmp = sol->paths->next;
			if (sol->paths->path)
				free(sol->paths->path);
			free(sol->paths);
			sol->paths = tmp;
		}
		if (sol->paths->path)
			free(sol->paths->path);
		free(sol->paths);
	}
	if (sol->first_path)
		sol->first_path = NULL;
}
