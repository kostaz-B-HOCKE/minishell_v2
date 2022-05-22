#include "../../minishell.h"

void    unset_delet_mid(t_info *inf, int i)
{
    t_env   *tmp;
    t_env   *tmp_s;
    t_env   *tmp_next;
    t_env   *tmp_start;
    int     j;

    j = 0;
    tmp_s = inf->env_lst;
    tmp_start = tmp_s;
    while (j++ < i - 1)
        tmp_s = tmp_s->next;
    tmp = tmp_s->next;
    tmp_next = tmp_s->next->next;
    tmp->next = NULL;
    tmp_s->next = tmp_next;
    free(tmp);
    inf->env_lst = tmp_start;
}

void    unset_delet(t_info *inf, int i)
{
    t_env   *tmp;
    t_env   *tmp_start;
    t_env   *tmp_next;
    int     j;

    j = ft_envsize(inf->env_lst);
    if (i == 0) {
        tmp = inf->env_lst;
        tmp_start = inf->env_lst->next;
        tmp->next = NULL;
        free(tmp);
        inf->env_lst = tmp_start;
    }
    else if (i < j - 1)
        unset_delet_mid(inf, i);
    else
    {
        tmp = inf->env_lst;
        tmp_start = tmp;
        while (tmp_start->next->next)
            tmp_start = tmp_start->next;
        tmp_next = tmp_start->next;
        tmp_start->next = NULL;
        free(tmp_next);
        inf->env_lst = tmp;
    }
}

int unset_str_util(t_info *inf, char *see_str, int i, char *env_str)
{
    int flag;

    flag = 0;
    if (see_str && env_str && !ft_strcmp(see_str, env_str)) {
        unset_delet(inf, i);
        flag = 1;
    }
    if (env_str)
        free(env_str);
    return (flag);
}

void    unset_str(t_info *inf, char *str_link)
{
    t_env   *tmp;
    char    *see_str;
    char    *env_str;
    int     flag;
    int     i;

    tmp = inf->env_lst;
    flag = 0;
    if (ft_strchr(str_link, '='))
//        print_error("unset: ", "`%s': not a valid identifier");
        printf("unset: `%s': not a valid identifier\n", str_link);
    else
    {
        see_str = search_env_util(str_link); //нужно free;
        i = 0;
        while (flag == 0 && tmp->next) {
            env_str = search_env_util(tmp->str);
            flag = unset_str_util(inf, see_str, i, env_str);
            tmp = tmp->next;
            i++;
        }
        if (flag == 0) {
            env_str = search_env_util(tmp->str);
            flag = unset_str_util(inf, see_str, i, env_str);
        }
        free(see_str);
    }
}

void    ft_unset(t_info *inf)
{
    t_link  *tmp;

    if (inf->link->next)
    {
        tmp = inf->link->next;
        while (tmp->next) {
            unset_str(inf, tmp->str);
            tmp = tmp->next;
        }
        unset_str(inf, tmp->str);
    }
//    t_env   *env = inf->env_lst;
//    while (env->next) {
//        printf("№%d\nstr:%s\n", env->number_list, env->str);
//        env = env->next;
//    }
//    printf("№%d\nstr:%s\n", env->number_list, env->str);
}
