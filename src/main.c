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
    start_shell(inf);

    free_finish_me(inf);
//    exit(0);
}

