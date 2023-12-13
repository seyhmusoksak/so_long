#include "so_long.h"
#include <stdio.h>
#include <string.h>

void    createmap(char **map, int g)
{
    void *mlx;
    void *win;
    void *img;
    void *player;
    char *relative_path = "./textures/wall.xpm";
    char *player_path = "./textures/player.xpm";
    int img_width;
    int img_height;
    int i = 0;
    int len = strlen(map[0]);

    printf("%d\n", len);

    mlx = mlx_init();
    win = mlx_new_window(mlx, (40 * (len - 1)), (40 * g), "Üçlü XPM Ekranı");
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    player = mlx_xpm_file_to_image(mlx, player_path, &img_width, &img_height);

    if (img == NULL) {
        fprintf(stderr, "XPM dosyası yüklenemedi\n");
         }

    // İlk görüntüyü pencereye çizme (konum: 100, 100)
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    int y = 0;
    int u = 0;
    while (map[u])
    {
        i = 0;
        printf("%s", map[u]);
        while (map[u][i] && i < len)
        {
            if (map[u][i] == '1')
                mlx_put_image_to_window(mlx, win, img, 0 + (i * img_width), y);
            else if (map[u][i] == 'P')
                mlx_put_image_to_window(mlx, win, player, 0 + (i * img_width), y);
            else if (map[u][i] == '\n')
            {
                y += 40;
                break;
            }
         i++;
        }
        u++;
    }
    // Pencereyi görüntüleme
    mlx_loop(mlx);

}

int main(void) {

    char *maps[5];
    int fd = open("./maps/map.ber", O_RDONLY,777);
    int e = 0;
    while (1)
    {
        maps[e] = get_next_line(fd);
        if (!maps[e])
            break;
        e++;
    }
    printf("%d", e);

    createmap(maps, e);
}

