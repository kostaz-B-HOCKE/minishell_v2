#include "../minishell.h"

t_link *list_new_mini(char *str)
{
    t_link  *new;
    new = malloc(sizeof(t_link));
    if (!new)
        return (NULL);
    new->str = str;
    new->next = NULL;
//    free(str);
    return (new);
}

void    link_add_list(t_link **old, t_link *new)
{
    t_link *tmp;

    tmp = *old;
    if (tmp && new)
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void    free_link(t_link **link)
{
    t_link  *tmp;

    if (*link) {
        while (*link) {
            tmp = *link;
            *link = (*link)->next;
            if (tmp->str)
                free(tmp->str);
            free(tmp);
        }
    }
}

void    free_env_ls(t_env **link)
{
    t_env *tmp;

    if (*link) {
        while (*link) {
            tmp = *link;
            *link = (*link)->next;
            if (tmp->str)
                free(tmp->str);
            free(tmp);
        }
    }
}

int link_size(t_link *link)
{
    int count;

    count = 0;
    while (link)
    {
        count++;
        link = link->next;
    }
    return (count);
}
