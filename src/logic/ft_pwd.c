#include "../../minishell.h"

void	ftt_pwd(t_info *inf)
{
    int		fd;
    int		flag;
    t_env	*tmp;

//    fd = init_logic_fd(inf);
    tmp = inf->env_lst;
    flag = 1;
    while (tmp != NULL)
    {
        if (ft_strncmp(tmp->str, "PWD=", 4) == 0)
        {
            ft_putendl_fd(tmp->str + 4, fd);
            flag = 0;
            break ;
        }
        tmp = tmp->next;
    }
    if (flag)
    {
        print_error("command not found", "pwd: ");
        gl_exit = 127;
    }
    else
        gl_exit = 0;
//    close_fds(inf->pipels->fd_in, inf->pipels->fd_out, inf->pipels->fr_re_out);
}