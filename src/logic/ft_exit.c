#include "../../minishell.h"

int	len_argvs(char **ar)
{
    int	str;

    str = 0;
    while (ar[str])
        str++;
    return (str);
}

int	is_numbers_to_string(char *str)
{
    int	i;

    i = -1;
    if (str[0] == '-')
        i++;
    while (str[++i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    }
    return (1);
}

static void	ft_exit_util(char **code)
{
    if (is_numbers_to_string(code[1]))
    {
        ft_putstr_fd("exit\n", 1);
        exit(ft_atoi(code[1]));
    }
    else
    {
        ft_putstr_fd("exit\n", 1);
        ft_putstr_fd("minishell: exit: ", 1);
        ft_putstr_fd(code[1], 1);
        ft_putstr_fd(": numeric argument required\n", 1);
        exit(255);
    }
}

void	ftt_exit(t_info *inf, char **code)
{
    if (!code || !*code) {
        exit(0);
    }
//    if (inf->is_pipe)
//        return ;
    if (len_argvs(code) == 1)
    {
        ft_putstr_fd("exit\n", 1);
        exit(EXIT_SUCCESS);
    }
    else if (len_argvs(code) == 2)
        ft_exit_util(code);
    else
    {
        ft_putstr_fd("exit\n", 1);
        ft_putstr_fd("minishell: exit: too many arguments\n", 1);
        gl_exit = 1;
        return ;
    }
    free_arr(code);
}