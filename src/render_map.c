#include "libft.h"
#include "so_long.h"

void    map_render(t_stack *m)
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    if (!mlx)
    {
        m->flag = false;
        return ;
    }
    win = mlx_new_window(mlx, m->width, m->high, "so_long");
    
}