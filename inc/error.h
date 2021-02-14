/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mellie <mellie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:16:12 by mellie            #+#    #+#             */
/*   Updated: 2020/12/09 17:58:28 by mellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define LEMIN_USAGE				"USAGE: ./lem-in < MAP_FILE"
# define ERR_1_NUM_ANTS				"ERROR: Wrong number of ants. Must be > 0."
# define ERR_2_EMPTY_LINE			"ERROR: Empty line."
# define ERR_3_MAP_INVALID			"ERROR: Invalid map."
# define ERR_4_INV_LNK				"ERROR: Invalid link."
# define ERR_5_DUP_STEN				"ERROR: Duplicate of ##start / ##end."
# define ERR_6_DUP_ROOM				"ERROR: Duplicate of the room."
# define ERR_7_START_END_NEXIST		"ERROR: START / END room doesn't exist."
# define ERR_8_ROOM_NEXIST			"ERROR: Room doesn't exist."
# define ERR_9_ROOM_NOT_EXPECTED	"ERROR: Room isn't expected here."
# define ERROR						"ERROR: Error reading."
# define ERROR_SOL					"ERROR: Solution is not found."
#endif
