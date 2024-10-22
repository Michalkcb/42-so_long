#include "../includes/so_long.h"

int load_textures(t_game *game)
{
    int width, height;

    game->textures.wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &width, &height);
    game->textures.player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &width, &height);
    game->textures.collectible = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &width, &height);
    if (!game->textures.wall || !game->textures.player || !game->textures.collectible)
        return (0);
    return (1);
}
