/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:16:52 by mellie            #+#    #+#             */
/*   Updated: 2020/12/09 14:08:59 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include "error.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_room	t_room;
typedef struct s_res	t_res;

typedef struct			s_lemin
{
	int					fd;
	int					rlen;
	long int			n_ants;
	int					n_rooms;
	int					start_id;
	int					end_id;
	t_room				*rooms;
	t_room				*start;
	t_room				*end;
	t_res				*res;
	char				*line;
	int					*links;
}						t_lemin;

struct					s_res
{
	char				*line;
	t_res				*next;
};

struct					s_room
{
	char				*name;
	int					rind;
	int					x;
	int					y;
	int					used;
	t_room				*prev;
	t_room				*next;
};

typedef struct			s_pt
{
	int					len;
	int					*path;
	struct s_pt			*next;
}						t_pt;

typedef struct			s_ants
{
	int					path;
	int					room;
	int					move;
	struct s_ants		*next;
}						t_ants;

typedef struct			s_sol
{
	long int			n_ant;
	long int			queue;
	long int			traveler;
	int					n;
	int					s;
	int					e;
	t_room				*rooms;
	int					*links;
	int					*par;
	t_pt				*paths;
	t_pt				*first_path;
	int					count_paths;
	int					**moves;
	int					count_p;
	int					free_count_p;
	int					num_p;
}						t_sol;

t_lemin					*init_lem(void);
void					parse(t_lemin *lem);
void					check_ants(t_lemin *lem);
int						skip_line(t_lemin *lem);
int						is_link(char *s, char c);
t_room					*check_dupl(t_lemin *lem, char **s);
void					start_end(t_lemin *lem);
void					start_end2(t_lemin *lem, t_room *room);
void					free_words(char ***s);
t_room					*valid_room(t_lemin *lem);
void					add_room(t_lemin *lem, t_room *room);
char					**valid_link(t_lemin *lem);
void					add_link(t_lemin *lem, char **links);
int						get_indx(t_lemin *lem, char *s);
void					print(t_lemin *lem);
t_res					*new_res(char *s);
void					add_res(t_lemin *lem);
void					print_res(t_lemin *lem);
int						main(int argc, char **av);
void					free_lemin(t_lemin *lem);
void					free_res(t_res *res);
void					free_rooms(t_lemin *lem);
void					init_links(t_lemin *lem);
void					init_arr(int *ar, int n, int c);
void					cp_arr(int *source, int *dest, int n);
int						ft_min(int *ar, int *check, int n);
int						next_v(int s, int v, int n, int *links);
void					init_next_path(t_sol *s);
void					rest_path(t_sol *s, int *dist);
void					depth(t_sol *s, int i);
int						dijkstra(t_sol *s);
void					remove_fp(t_sol *s);
void					swap_arrays(int *ar1, int *ar2, int n);
void					sort_paths(t_sol *s);
void					adjust_paths(t_sol *s);
char					**fill_rooms(t_sol *s);
void					move_ants(t_sol *s);
int						check_se(t_lemin *lem);
void					suurballe(t_lemin *lem);
void					free_sol(t_sol *sol);
void					free_sol_rooms(char **rooms, int n);
void					free_sol_paths(t_sol *sol);
void					init_ant(t_ants *ant, t_sol *s);
void					move_ant(t_ants *ant, t_sol *s, int i, char **rooms);
void					make_move(t_ants *ant, t_sol *s, int i, char **rooms);
void					move_ants(t_sol *s);
int						enough(int n, int **move);
void					init_next_path(t_sol *s);
void					count_path(t_sol *s, int *dist, int *v);
void					rest_path(t_sol *s, int *dist);
void					sort_paths(t_sol *s);
void					adjust_paths(t_sol *s);
void					init_arr(int *ar, int n, int c);
void					cp_arr(int *source, int *dest, int n);
int						ft_min(int *ar, int *check, int n);
void					swap_arrays(int *ar1, int *ar2, int n);
char					**fill_rooms(t_sol *s);
int						next_v(int s, int v, int n, int *links);
void					depth(t_sol *s, int i);
void					dij_count (t_sol *s, int *used, int *dist);
int						dijkstra(t_sol *s);
void					remove_fp(t_sol *s);
void					fill_moves(t_sol *s);
int						check_se(t_lemin *lem);
void					init_sol(t_sol *sol, t_lemin *lem);
void					suurballe(t_lemin *lem);
#endif
