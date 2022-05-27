#include "../../minishell.h"

void	ftt_pwd(t_info *inf)
{
    t_env	*tmp;
    int		fd;
    char    *test;
    char    *str;

    fd = init_fd_out(inf);
    test = malloc(sizeof(char) * 1000);
    if (!test)
        return ;
    test = getcwd(test, 1000);
    ft_putendl_fd(test, fd);
    free(test);

//    tmp = inf->env_lst;
//    flag = 1;
//    while (tmp != NULL)
//    {
//        if (ft_strncmp(tmp->str, "PWD=", 4) == 0)
//        {
//            ft_putendl_fd(tmp->str + 4, fd);
//            flag = 0;
//            break ;
//        }
//        tmp = tmp->next;
//    }
//    if (flag)
//    {
//        print_error("command not found", "pwd: ");
//        gl_exit = 127;
//    }
//    else
        gl_exit = 0;
}