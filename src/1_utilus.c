#include "../minishell.h"

int	ftt_strcmp(const char *s1, const char *s2)
{
    int	i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}

void	free_arr(char **arr)
{
    int	i;

    if (arr)
    {
        i = 0;
        while (arr[i])
            free(arr[i++]);
        free(arr);
    }
}

void    printf_dstr(char **super_str)
{
    int i;

    i = 0;
    printf("\n");
    while (super_str[i]) {
        printf("i:%d\n", i);
        printf("str:%s\n ", super_str[i++]);
    }
}