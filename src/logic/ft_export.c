#include "../../minishell.h"

t_env	*export_list_env(t_env **env_ls, char *str)
{
    t_env	*new;
    t_env   *start;
    int		i;
    int     flag;

    i = -1;
    flag = 0;
    while (str[++i])
        if (str[i] == '=')
            flag = 1;
    if (flag == 1) {
        start = *env_ls;
        i = 0;
        new = start;
        while (new->next) {
            i++;
            new = new->next;
        }
        new->next = lst_new_env(str);
        return (start);
    }
    return (NULL);
}

//вовзращает стрку с выделенйо памятью
char    *search_env_util(char *input)
{
    char *str;
    int i;

    i = -1;
    while (input[++i] && input[i] != '=')
        ;
    str = malloc(sizeof(char )* i + 1);
    if (!str)
        return (NULL);
    i = -1;
    while (input[++i] && input[i] != '=')
    {
        str[i] = input[i];
    }
    str[i] = '\0';
    return (str);
}

void    ex_env_addendum(t_env *env_ls, char *replec)
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
    str1 = ft_substr(replec, i + 1, ft_strlen(replec) - i);
//    free(env_ls->str);
    input = ft_strjoin_free(str, str1);
    env_ls->str = input;
//    free(input);
}

void    search_env(t_env *env_ls, char *str)
{
    char *see_str;
    char *see_link_str;
    t_env   *tmp;
    int     flag;

    tmp = env_ls;
    flag = 0;
    see_str = search_env_util(str);//нужно free;
    while (tmp->next)
    {
        see_link_str = search_env_util(tmp->str);
        if (!ft_strcmp(see_str, see_link_str))
        {
            flag = 1;
            ex_env_addendum(tmp, str);
        }
        free(see_link_str);
        tmp = tmp->next;
    }
    see_link_str = search_env_util(tmp->str);
    if (!ft_strcmp(see_str, see_link_str)) {
        flag = 1;
        ex_env_addendum(tmp, str);
    }
    if (flag != 1)
        export_list_env(&env_ls, str);
    free(see_link_str);
    free(see_str);
}

void    ft_export(t_info *inf)
{
    t_link  *tmp;

    if (inf->link->next) {
        tmp = inf->link->next;
        while (tmp->next) {
            if (ft_isalpha(tmp->str[0]))
                search_env(inf->env_lst, tmp->str);
            else
                printf("export: `str': not a valid identifier\n");
            tmp = tmp->next;
        }
        if (ft_isalpha(tmp->str[0]))
            search_env(inf->env_lst, tmp->str);
        else
            printf("export: `str': not a valid identifier\n");
    }
}