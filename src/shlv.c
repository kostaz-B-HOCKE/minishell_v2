#include "../minishell.h"

static int	check_digit(char *str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

char    *shlvl_util(int number)
{
    char    *str;
    char    *str3;
    int     i;

    str = ft_itoa(number);
    i = 0;
    while (str[i])
        i++;
    str3 = ft_strjoin("SHLVL=", str);
    if (str)
        free(str);
    return (str3);
}

static void shell_level_pars(t_info *inf, char *str)
{
    int     number;
    char    *str_add;

    if (check_digit(str))
    {
        number = ft_atoi(str);
        number++;
        if (number < 0)
            search_env(inf, "SHLVL=1");
        else if (number == 999) {
            search_env(inf, "SHLVL=");
        }
        else if (number > 999)
            search_env(inf, "SHLVL=1");
        else
        {
            str_add = shlvl_util(number);
            search_env(inf, str_add);
            free(str_add);
        }
//            (*tmp)->str = ex_shlvl_add(tmp, ft_itoa(number + 1));
//      print_error("", "shell level (1000) too high, resetting to 1");
    }
    else {
        search_env(inf, "SHLVL=1");
    }
}

void	shell_level(t_info *inf)
{
    t_env	*tmp;
    char	*str;
    int     flag;

    flag = 0;
    tmp = inf->env_lst;

    while (tmp)
    {
        if (!ft_strncmp(tmp->str, "SHLVL=", 6))
        {
            str = ft_substr(tmp->str, 6, ft_strlen(tmp->str) - 6);
            shell_level_pars(inf, str);
            free(str);
            flag = 1;
        }
        tmp = tmp->next;
    }
    if (flag == 0)
        search_env(inf, "SHLVL=1");
}
