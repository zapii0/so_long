#include "libft.h"
#include "so_long.h"
#include <mlx.h>

void    map_render(t_stack *map)
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    if (!mlx)
    {
        map->flag = false;
        return ;
    }
    
}