/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sideways_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:03:32 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:20 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

int	a_strafe_next_y_is_not_wall(t_game *game)
{
	t_double_vector		*plane;
	t_player			*player;
	char				**maze;

	plane = &game->ray.plane;
	player = &game->player;
	maze = game->map.map;
	return (maze[(int)(player->pos.y + plane->y * MOVE_SPEED)]
			[(int)player->pos.x] == '0' ||
			is_player(maze[(int)(player->pos.y + plane->y * MOVE_SPEED)]
				[(int)player->pos.x]));
}

int	a_strafe_next_x_is_not_wall(t_game *game)
{
	t_double_vector		*plane;
	t_player			*player;
	char				**maze;

	plane = &game->ray.plane;
	player = &game->player;
	maze = game->map.map;
	return (maze[(int)player->pos.y]
			[(int)(player->pos.x + plane->x * MOVE_SPEED)] == '0' ||
			is_player(maze[(int)player->pos.y]
			[(int)(player->pos.x + plane->x * MOVE_SPEED)]));
}

int	d_strafe_next_y_is_not_wall(t_game *game)
{
	t_double_vector		*plane;
	t_player			*player;
	char				**maze;

	plane = &game->ray.plane;
	player = &game->player;
	maze = game->map.map;
	return (maze[(int)(player->pos.y - plane->y * MOVE_SPEED)]
			[(int)player->pos.x] == '0' ||
			is_player(maze[(int)(player->pos.y - plane->y * MOVE_SPEED)]
				[(int)player->pos.x]));
}

int	d_strafe_next_x_is_not_wall(t_game *game)
{
	t_double_vector		*plane;
	t_player			*player;
	char				**maze;

	plane = &game->ray.plane;
	player = &game->player;
	maze = game->map.map;
	return (maze[(int)player->pos.y]
			[(int)(player->pos.x - plane->x * MOVE_SPEED)] == '0' ||
			is_player(maze[(int)player->pos.y]
			[(int)(player->pos.x - plane->x * MOVE_SPEED)]));
}
