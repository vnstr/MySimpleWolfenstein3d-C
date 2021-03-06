/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:14:28 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:22 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game_engine.h"

void	turn_player(t_game *game)
{
	t_double_vector	*dir;
	t_double_vector	*plane;
	double			old_dir_x;
	double			old_plane_x;

	dir = &game->player.dir;
	plane = &game->ray.plane;
	old_dir_x = dir->x;
	old_plane_x = plane->x;
	if (game->keys.q == 1 && game->keys.e == 1)
		return ;
	if (game->keys.q == 1)
	{
		dir->x = dir->x * cos(-ROT_SPEED) - dir->y * sin(-ROT_SPEED);
		dir->y = old_dir_x * sin(-ROT_SPEED) + dir->y * cos(-ROT_SPEED);
		plane->x = plane->x * cos(-ROT_SPEED) - plane->y * sin(-ROT_SPEED);
		plane->y = old_plane_x * sin(-ROT_SPEED) + plane->y * cos(-ROT_SPEED);
	}
	if (game->keys.e == 1)
	{
		dir->x = dir->x * cos(ROT_SPEED) - dir->y * sin(ROT_SPEED);
		dir->y = old_dir_x * sin(ROT_SPEED) + dir->y * cos(ROT_SPEED);
		plane->x = plane->x * cos(ROT_SPEED) - plane->y * sin(ROT_SPEED);
		plane->y = old_plane_x * sin(ROT_SPEED) + plane->y * cos(ROT_SPEED);
	}
}
