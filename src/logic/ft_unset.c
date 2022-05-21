#include "../../minishell.h"

void    unset_add(t_env *env_ls, char *str_link)
{
    int i;
    t_env   *tmp;
    char *see_str;

    printf("2,5\n");
    see_str = search_env_util(str_link);//нужно free;
    printf("!:%s\n", see_str);


//    while (tmp->next)
//    {
//
//
//    }


}

void    ft_unset(t_info *inf)
{
    t_link  *tmp;

    printf("1\n");
    if (inf->link->next)
    {
        printf("1,5\n");
        tmp = inf->link->next;
        unset_add(inf->env_lst, tmp->str);
    }
}

