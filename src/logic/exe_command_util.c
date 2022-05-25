#include "../../minishell.h"

char	*search_in_arr(char **arr, char *command)
{
    char	*full_path;
    char	*path;
    int		i;

    i = 0;
    while (arr[i])
    {
        path = ft_strjoin(arr[i], "/");
        full_path = ft_strjoin(path, command);
        free(path);
        if (access(full_path, X_OK) == 0)
        {
            free(command);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    full_path = ft_strdup(command);
    free(command);
    return (full_path);
}

int	get_variable_env(t_info *inf, char **adr, char *key_word, int n)
{
    t_env	*temp;

    temp = inf->env_lst;
    while (temp != NULL)
    {
        if (ft_strncmp(temp->str, key_word, n) == 0)
        {
            *adr = temp->str + n;
            return (0);
        }
        temp = temp->next;
    }
    return (1);
}

char	*find_command_in_env(char *command, t_info *inf)
{
    char	*env;
    char	*full_path;
    char	**arr;

    if (get_variable_env(inf, &env, "PATH=", 5))
        return (NULL);
    arr = ft_split(env, ':');
    if (!arr)
        return (NULL);
    full_path = search_in_arr(arr, command);
    free_arr(arr);
    return (full_path);
}

char	**init_res(char **res, char **arg, t_info *inf)
{
    int		i;
    int		size;

    i = 0;
    size = 0;
    while (arg[i])
    {
        if (ft_strlen(arg[i]) != 0)
            res[size++] = ft_strdup(arg[i]);
        i++;
    }
    res[size] = NULL;
    if (!ft_strchr(res[0], '/'))
        res[0] = find_command_in_env(res[0], inf);
    return (res);
}

char	**re_build_command(char **arg, t_info *inf)
{
    int		i;
    int		size;
    char	**res;

    i = 0;
    size = 0;
    while (arg[i])
    {
        if (ft_strlen(arg[i]) != 0)
            size++;
        i++;
    }
    res = malloc(sizeof(char *) * size + 1);
    if (!res)
        return (NULL);
    res = init_res(res, arg, inf);
    return (res);
}