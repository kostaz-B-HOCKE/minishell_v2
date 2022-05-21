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

char    *ex_shlvl_add(t_env *env_ls, char *str_add)
{
    int i;
    char *str;
    char *str1;
    char    *input;

    i = -1;
    input = env_ls->str;
    while (input[++i] && input[i] != '=')
        ;
    str = ft_substr(input, 0, i + 1);
//    free(env_ls->str);
    input = ft_strjoin(str, str_add);
//    env_ls->str = input;
//    free(input);
    free(str);
    return (input);
}

char    *search_equals(char *input)
{
    char    *str;
    int i;

    i = 0;
    while (input[++i] && input[i] != '=')
        ;
    str = ft_substr(input, 0, i + 1);
    printf("str=:%s\n", str);
    return (str);
}

static void shell_level_pars(t_env  *tmp, char *str)
{
    int     number;
    int		lvl;

//    printf("str=:%s\n", str);
    if (check_digit(str))
    {
        number = ft_atoi(str);
//        printf("number:%d\n", number);
        if (number < 0)
            tmp->str = ex_shlvl_add(tmp, "1");
        else if (number == 999) {
            tmp->str = ex_shlvl_add(tmp, "");
        }
        else if (number > 999)
            tmp->str = ex_shlvl_add(tmp, "1");
        else
            tmp->str = ex_shlvl_add(tmp, ft_itoa(number + 1));
//      print_error("", "shell level (1000) too high, resetting to 1");
    }
    else {
        tmp->str = ex_shlvl_add(tmp, "1");
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
            shell_level_pars(tmp, str);
            free(str);
            flag = 1;
        }
        tmp = tmp->next;
    }
    if (flag == 0)
        search_env(inf->env_lst, "SHLVL=1");
}

