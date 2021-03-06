/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:50:35 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/21 19:55:40 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_H
# define GAME_ENGINE_H
# include "new_map.h"

/*
** For s_ray_data.
*/

typedef struct			s_double_vector
{
	double				x;
	double				y;
}						t_double_vector;

typedef struct			s_int_vector
{
	int					x;
	int					y;
}						t_int_vector;

typedef struct			s_side_dist
{
	double				x;
	double				y;
	double				delta_x;
	double				delta_y;
}						t_side_dist;

/*
** For s_game_data.
** Ray-data.
*/

typedef struct			s_ray
{
	t_double_vector		plane;
	double				camera_x;
	t_double_vector		dir;
	t_int_vector		map;
	t_side_dist			side_d;
	double				perp_wall_dist;
	t_int_vector		step;
	int					hit;
	int					side;
	int					line_h;
	int					draw_start;
	int					draw_end;
}						t_ray;

/*
** For s_game_data.
** MLX-data.
*/

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
}						t_mlx;

/*
** For s_game_data.
** IMG-data.
*/

typedef struct			s_img
{
	void				*img;
	void				*addr;
	int					bits_per_pixel;
	int					line_lenght;
	int					endian;
}						t_img;

/*
** For s_game_data.
** Texture-data.
*/

typedef struct			s_texture
{
	char				*relative_path;
	t_img				img;
	int					width;
	int					height;
}						t_texture;

/*
** For s_game_data.
** Textures-data:
**    n - north texture.
**    s - south texture.
**    w - west texture.
**    e - east texture.
*/

typedef struct			s_textures
{
	t_texture			no;
	t_texture			so;
	t_texture			we;
	t_texture			ea;
}						t_textures;

/*
** For s_sprites.
** Sprites-rendering-drawing-data.
*/

typedef struct			s_spr_render
{
	int					*sprite_order;
	double				*sprite_distance;
	double				sprite_x;
	double				sprite_y;
	double				inv_det;
	double				transform_x;
	double				transform_y;
	int					sprite_screen_x;
	int					sprite_height;
	int					sprite_width;
	int					draw_start_y;
	int					draw_end_y;
	int					draw_start_x;
	int					draw_end_x;
	int					stripe;
	int					tex_x;
	int					tex_y;
	int					img_y;
	int					y;
	int					d;
	uint32_t			color;
}						t_spr_render;

/*
** For s_game_data.
** Sprites-data.
*/

typedef struct			s_sprites
{
	t_double_vector		**sprites;
	size_t				num_sprites;
	t_spr_render		render;
	t_texture			texture;
}						t_double_vectors;

/*
** Keycodes.
*/

# define ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_LEFT 123
# define KEY_RIGHT 124

/*
** For s_game_data.
** Key-flags.
** 1 - key is pressed.
** 0 - key is unpressed.
*/

typedef struct			s_key_f
{
	char				w;
	char				s;
	char				a;
	char				d;
	char				q;
	char				e;
}						t_keys_f;

/*
** For s_player.
** Player position.
*/

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

/*
** For s_game_data.
** Information about player.
*/

typedef struct			s_player
{
	t_double_vector		pos;
	t_double_vector		dir;
	char				start_view;
}						t_player;

/*
** Game-data.
*/

typedef struct			s_game
{
	t_mlx				mlx;
	t_img				img;
	t_textures			texture;
	t_double_vectors	sprites;
	t_player			player;
	t_keys_f			keys;
	t_map				map;
	t_ray				ray;
}						t_game;

/*
** ============================================================================
**                             Public functions.
** ============================================================================
*/

/*
** Init game workspace.
*/

int						init_game_space(t_game *game_data);

int						init_player(t_player *player,
		t_double_vector *plane, char **maze);

void					init_wall_textures(t_game *game_data);
void					check_dot_xpm(char *s);
void					init_img_north_texture(void *mlx, t_textures *texture);
void					init_img_south_texture(void *mlx, t_textures *texture);
void					init_img_west_texture(void *mlx, t_textures *texture);
void					init_img_east_texture(void *mlx, t_textures *texture);
void					init_double_vectors(t_game *game_data);
void					init_arr_sprites(t_game *game_data);
int						free_sprites(t_double_vector ***sprites);
int						is_player(char c);

/*
** Game control.
*/

int						start_game(t_game *game_data);
int						finish_game(t_game *game_data);

/*
** Render
*/

int						raycasting_render(t_game *game_data);

/*
** Drawing img.
*/

void					my_mlx_pixel_put(t_img *data, int x, int y, int color);
void					draw_sky(t_game *game_data);
void					draw_land(t_game *game_data);
void					draw_textures(t_game *game_data, size_t i);

/*
** Keyboard hanlder.
*/

int						handle_pressed_key(int keycode, t_game *game_data);
int						handle_unpressed_key(int keycode, t_game *game_data);

/*
** ----------------------------------------------------------------------------
**                               Player moving.
** ----------------------------------------------------------------------------
*/

void					player_move(t_game *game_data);

int						move_forward_backward(t_game *game_data);
int						next_y_is_not_wall(char **maze, t_player *player);
int						next_x_is_not_wall(char **maze, t_player *player);
int						previous_y_is_not_wall(char **maze, t_player *player);
int						previous_x_is_not_wall(char **maze, t_player *player);

int						move_sideways(t_game *game_data);
int						a_strafe_next_y_is_not_wall(t_game *game_data);
int						a_strafe_next_x_is_not_wall(t_game *game_data);
int						d_strafe_next_y_is_not_wall(t_game *game_data);
int						d_strafe_next_x_is_not_wall(t_game *game_data);

void					turn_player(t_game *game_data);

/*
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
*/

/*
** ----------------------------------------------------------------------------
**                             Raycasting-render.
** ----------------------------------------------------------------------------
*/

int						init_ray(t_game *game_data, size_t i);
void					calculate_draw_start_end(t_game *game_data);

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**                              Sprites rendering.~
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

void					render_sprites(t_game *game_data, double *z_buff);
void					init_order(t_game *game);
void					sort_double_vectors(int *order,
		double *distance, size_t len);
void					init_double_vector(t_game *game, size_t i);
void					calculate_drawstart_end(t_game *game);

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
*/

/*
** ----------------------------------------------------------------------------
**                                 Screenshot.
** ----------------------------------------------------------------------------
*/

void					do_screenshot(t_game *game);
void					*init_bitmap54(t_game *game);

/*
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
*/

/*
** ============================================================================
** ============================================================================
** ============================================================================
*/

#endif
