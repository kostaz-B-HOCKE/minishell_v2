#include "../minishell.h"
//open(file_name, O_CREAT + O_WRONLY + O_TRUNC, 0777)



char *ft_redirect1(char *str, int *i, t_info *inf)
{
    char    *file_name;
    char    *new_str;
    int     fd_out;
    int     tt;
    int     j;

    if (*i == -1)
        *i = 0;
    tt = *i + 1;
    while (str[tt] && str[tt] == ' ')
        tt++;
//    tt++;
    j = tt;
    while (str[j] && str[j] != ' ')
        j++;
    file_name = ft_substr(str, tt, j - tt);
    while (str[j] && str[j] == ' ')
        j++;
    new_str = ft_substr(str, j, ft_strlen(str) - *i + 1);
    printf("name:%s|\n", file_name);
    printf("j%c\n", str[j - 1]);
    printf("tt%c\n", str[tt]);
    printf("c%c\n", str[*i]);
    printf("new_str:%s\n", new_str);
    fd_out = open(file_name, O_CREAT + O_WRONLY + O_TRUNC, 0777);
//    printf("c%c\n", str[*i]);
//    dup2(fd_out, 1);
    *i = -1;
    free(str);
    return (new_str);

//    return (str);
}