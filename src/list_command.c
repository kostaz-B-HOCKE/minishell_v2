#include "../minishell.h"

void    link_to_str(char *str, t_info *inf)
{
    if (!inf->link) {
        inf->link = list_new_mini(str);
    }
    else {
        link_add_list(&(inf->link), list_new_mini(str));
    }
//    printf("count_list:%d\n", link_size(inf->link));
//    print_me_link(inf);
}

int	ft_envsize(t_env *lst)
{
    int	amount;

    amount = 0;
    while (lst)
    {
        lst = lst->next;
        amount++;
    }
    return (amount);
}

