#include "../../minishell.h"

char    **porting_link_str(t_info *info)
{
    t_link  *tmp;
    char **super_str;
    int i;

//    printf("oo:%s\n", info->link->next->str);
    i = 0;
    tmp = info->pipe_lst->link;
    while (tmp->next)
    {
        i++;
        tmp = tmp->next;
    }
    super_str = (char **)malloc(sizeof(char *) * (i + 2));
    if (!super_str)
        return (NULL);
    i = 0;
    tmp = info->pipe_lst->link;
    while (tmp->next)
    {
        super_str[i++] = ft_strdup(tmp->str);
        tmp = tmp->next;
    }
    super_str[i++] = ft_strdup(tmp->str);
    super_str[i] = NULL;
    return (super_str);
}

void    ftt_echo(t_info *inf)
{
    int i;
    char    **arg;
    int fd;

    fd = init_fd_out(inf);
    arg = porting_link_str(inf);
    i = 0;
    if (!arg[1])
    {
        write(1, "\n", 1);
        return ;
    }
    while (arg[++i])
    {
        ft_putstr_fd(arg[i], fd);
        ft_putstr_fd(" ", fd);
//        ft_putendl_fd(" ", fd);
    }
    while (arg[i] && ft_strncmp(arg[i], "-n", 3))
        i++;
    ft_putstr_fd("\n", fd);
    free_arr(arg);
}
