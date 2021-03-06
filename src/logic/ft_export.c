#include "../../minishell.h"

t_env	*export_list_env(t_env *env_ls, char *str)
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
//    printf("flag%d\n", flag);
    if (flag == 1)
    {
//        printf("flag =1\n");
        start = env_ls;
        i = 0;
        new = start;
        while (new->next) {
            i++;
//            printf("%s\n", new->str);
            new = new->next;
        }
//        printf("12312%s\n", new->str);
//        new = new->next;
//        printf("str:%s\n", str);
        new->next = lst_new_env(str, (1 + ft_envsize(env_ls)));
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
//    if (!ft_strchr(input, '='))
//        return (NULL);
    while (input[++i] && input[i] != '=')
        ;
    str = malloc(sizeof(char )* i + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (input[i] && input[i] != '=')
    {
        str[i] = input[i];
        i++;
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
//    t_env   *tmp;

    i = -1;
    input = env_ls->str;
    while (input[++i] && input[i] != '=')
        ;
    str = ft_substr(input, 0, i + 1);
    str1 = ft_substr(replec, i + 1, ft_strlen(replec) - i);
    input = ft_strjoin_free(str, str1);
    free(env_ls->str);
    env_ls->str = input;
}

void    search_env(t_info *inf, char *str)
{
    char *str1;
    char *str2;
    t_env   *tmp;
    int     flag;

    tmp = inf->env_lst;
    flag = 0;
    str1 = search_env_util(str);
//    printf("стока1:%s\n", str1);
    while (tmp->next)
    {
        str2 = search_env_util(tmp->str);
//        printf("str2:%s\n", str2);
        if (str2 && str1 && !ft_strcmp(str1, str2))
        {
            flag = 1;
            ex_env_addendum(tmp, str);
        }
        free(str2);
        tmp = tmp->next;
    }
    str2 = search_env_util(tmp->str);
    if (str2 && str1 && !ft_strcmp(str1, str2)) {
        flag = 1;
        ex_env_addendum(tmp, str);
    }
    if (flag != 1) {
        export_list_env(inf->env_lst, str);
    }
    free_two_str(str2, str1);
}

void    ft_export(t_info *inf)
{
    t_link  *tmp;

    if (inf->pipe_lst->link->next) {
        tmp = inf->pipe_lst->link->next;
        while (tmp->next) {
            if (ft_isalpha(tmp->str[0]))
                search_env(inf, tmp->str);
            else
              print_error("", "export: `%s': not a valid identifier");
            tmp = tmp->next;
        }
        if (ft_isalpha(tmp->str[0])) {
            search_env(inf, tmp->str);
        }
        else
            print_error("", "export: `%s': not a valid identifier");
    }
//    print_me_env(inf);
}