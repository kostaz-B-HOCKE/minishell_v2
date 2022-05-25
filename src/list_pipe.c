#include "../minishell.h"

t_pipe *pipe_list_new(t_info *inf)
{
    t_pipe  *new;
    new = malloc(sizeof(t_pipe));
    if (!new)
        return (NULL);
    new->link = inf->link;
    new->next = NULL;
    return (new);
}

void    link_add_pipe(t_pipe **old, t_pipe *new)
{
    t_pipe *tmp;

    tmp = *old;
    if (tmp && new)
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void    free_pipe_ls(t_pipe **pipe_ls)
{
    t_pipe  *tmp;

    if (*pipe_ls) {
        while (*pipe_ls) {
            tmp = *pipe_ls;
            if ((*pipe_ls)->link)
                free_link(&(*pipe_ls)->link);
            *pipe_ls = (*pipe_ls)->next;
            free(tmp);
        }
    }
}

void    pipe_fill_in(t_info *inf)
{
    if (!inf->pipe_lst) {
        inf->pipe_lst = pipe_list_new(inf);
        inf->link = NULL;
    }
    else {
        link_add_pipe(&(inf->pipe_lst), pipe_list_new(inf));
        inf->link = NULL;
    }
}