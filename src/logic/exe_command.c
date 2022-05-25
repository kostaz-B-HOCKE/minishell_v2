#include "../../minishell.h"

void    ft_parent(pid_t pid, t_info *inf)
{
    int status;

    waitpid(pid, &status, 0);
    gl_exit = WEXITSTATUS(status);
}

void    ft_child(t_info *inf, char **command)
{
    char    **cmd_d;

    cmd_d = re_build_command(command, inf);

    execve(cmd_d[0], cmd_d, command);
    exit(127);
}

void    exe_fork(char **command, t_info *inf)
{
    pid_t   pid;

    pid = fork();
    if (pid < 0)
    {
        perror("mimishell");
        exit(1);
    }
    else if (pid == 0)
    {

        ft_child(inf, command);

    }
    else
    {
        ft_parent(pid, inf);
    }
}

void    exe_command(t_info *inf)
{
    char    **command;

    if (inf->link->str)
        command = porting_link_str(inf);

    exe_fork(command, inf);
    free_arr(command);
}