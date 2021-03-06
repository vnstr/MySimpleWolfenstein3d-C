/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:47:54 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 20:28:42 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "game_engine.h"
#include "libft.h"

void		check_dot_xpm(char *s)
{
	int64_t	i;

	i = (int64_t)ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == '.')
		{
			if (ft_strcmp(s + i, ".xpm") == 0)
				return ;
		}
		i--;
	}
	write(2, "ERROR: invalid textures\n", 24);
	exit(-1);
}

void		init_relative_path(t_textures *texture, t_map *map)
{
	texture->no.relative_path = map->no;
	texture->so.relative_path = map->so;
	texture->we.relative_path = map->we;
	texture->ea.relative_path = map->ea;
	check_dot_xpm(texture->no.relative_path);
	check_dot_xpm(texture->so.relative_path);
	check_dot_xpm(texture->we.relative_path);
	check_dot_xpm(texture->ea.relative_path);
}

void		init_wall_textures(t_game *game)
{
	t_textures	*texture;
	t_map		*map;

	texture = &game->texture;
	map = &game->map;
	init_relative_path(&game->texture, &game->map);
	init_img_north_texture(game->mlx.mlx, &game->texture);
	init_img_south_texture(game->mlx.mlx, &game->texture);
	init_img_west_texture(game->mlx.mlx, &game->texture);
	init_img_east_texture(game->mlx.mlx, &game->texture);
}
