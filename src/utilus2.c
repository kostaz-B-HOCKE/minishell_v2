#include "../minishell.h"

void	spl_free(char **str)
{
    int	i;

    i = 0;
    while (str[i])
        free(str[i]);
    free(str);
}

void    free_finish_me(t_info *inf)
{
    if (inf->link)
        free_link(&inf->link);
    if (inf->env_lst)
        free_env_ls(&inf->env_lst);
    free(inf);
}
