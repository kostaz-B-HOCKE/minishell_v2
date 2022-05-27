#include "../minishell.h"

int init_fd_out(t_info *inf)
{
    int fd;

    if (inf->fd_out != -1)
    {
//        fd = inf->fd_out;
//        dup2(inf->fd_out, 1);
        fd = 1;
//        ft_putendl_fd("OM", STDOUT_FILENO);
    }
    else
        fd = 1;
    return (fd);
}

int init_fd_in(t_info *inf)
{
    int fd;

    if (inf->fd_in != -1)
        fd = inf->fd_in;
    else
        fd = 0;
    return (fd);
}