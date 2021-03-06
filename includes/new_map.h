/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:00:19 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/27 19:00:20 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_MAP_H
# define NEW_MAP_H

# include <stdlib.h>
# include <stdint.h>

# define ERROR -1
# define TRUE 1
# define FALSE 0

typedef struct			s_arrstrs
{
	char				**arr;
	size_t				len;
}						t_arrstrs;

typedef	struct			s_map
{
	size_t				r[2];
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
	int64_t				f;
	int64_t				c;
	char				**map;
	int					(*parse_file)(char *file, struct s_map *map);
	int					(*clear)(struct s_map *map);
	int					(*scan_error)(struct s_map *map);
	void				(*print)(struct s_map *map);
}						t_map;

int						new_map(t_map *map);
int						parse_map_config(char *file, t_map *map);
void					init_zero_map(t_map *map);
int						free_map(t_map *map);

#endif
