#include "../minishell.h"

char    *ft_pipex_cutting(char *input, int *offset, t_info *inf)
{
    int     i;
    char    *str_do;

    inf->flag_pipe = 1;
    i = 0;
//    printf("input:%s\n", input);

//    print_me_link(inf);
    pipe_fill_in(inf);
//    printf("+++++++++++++++++++++++++++++\n");
//    print_me_link(inf);
    str_do = ft_substr(input, 1, ft_strlen(input) - 1);
//    printf("c:%c\n", input[*offset]);

    *offset = 0;
    free(input);
    return (str_do);
    return (input);
}