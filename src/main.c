#include "../minishell.h"

void	handler(int sig)
{
    (void)sig;
    rl_on_new_line();
    rl_redisplay();
    write(1, "  \n", 3);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
    gl_exit = 1;
}

void	sig_handler(void)
{
    struct sigaction	sa;
    sigset_t			set;

    signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    sa.sa_handler = handler;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sa.sa_mask = set;
    sigaction(SIGINT, &sa, NULL);
}

void    start_shell(t_info *inf)
{
    char *str;

    while (1)
    {
        sig_handler(); //contrl +D дает сегу
        str = readline("mimishell: ");
        if (!ft_strcmp(str, "./minishell"))
            shell_level(inf);
        if (!str)
            break ;
//        if (str[0] == '1') //для теста
//            break;
        if (ft_strlen(str) != 0)
            add_history(str);
        parsing_s(inf, str);
        free_link(&inf->link);
    }
}

//????????
void	execute(char *argv, char **env)
{
    char	**cmd;
    int 	i;
    char	*path;

    i = -1;
    cmd = ft_split(argv, ' ');
//    path = find_path(cmd[0], inf);
    path = "/bin/cat";
    if (!path)
    {
        while (cmd[++i])
            free(cmd[i]);
        free(cmd);
        exit(EXIT_FAILURE);
    }
    if (execve(path, cmd, env) == -1)
        exit(EXIT_FAILURE);
}

void	child_process(char **env)
{
    pid_t	pid;
    int		fd[2];

    if (pipe(fd) == -1)
        exit(EXIT_FAILURE);
    pid = fork();
    if (pid == -1)
        exit(EXIT_FAILURE);
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execute("cat", env);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
}

int main(int ac, char **argv, char **env)
{
    t_info	*inf;

    gl_exit = 0;
    inf = init_info(env);
    shell_level(inf);
//    print_me_env(inf);
//    child_process(env);
//	printf("__/__/__/__/__/__/__/__/__/__/__/\n");
//    pipee_test();
//    start_shell(inf);
    free_finish_me(inf);
    free(inf);
    exit(0);
}
