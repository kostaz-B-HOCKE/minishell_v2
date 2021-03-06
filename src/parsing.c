#include "../minishell.h"

char	*delete_spese(char *str)
{
    int		i;
    int		len;
    char	*res;

    if (!str)
        return (str);
    i = -1;
    while (str[++i] == ' ')
        ;
    res = ft_substr(str, i, ft_strlen(str) - i);
    free(str);
    len = ft_strlen(res);
    while (len >= 0 && ft_strchr(" ", res[len]))
        len--;
    len++;
    res[len] = 0;
    str = ft_strdup(res);
    free(res);
    return (str);
}

//возвращает 2мер массив выдеена память
char    **porting_env(t_info *info)
{
    t_env   *tmp;
    char **super_str;
    int i;

    i = 0;
    tmp = info->env_lst;
    while (tmp->next)
    {
        i++;
        tmp = tmp->next;
    }
    super_str = (char **)malloc(sizeof(char *) * (i + 2));
    if (!super_str)
        return (NULL);
    i = 0;
    tmp = info->env_lst;
    while (tmp->next)
    {
        super_str[i++] = ft_strdup(tmp->str);
        tmp = tmp->next;
    }
    super_str[i++] = ft_strdup(tmp->str);
    super_str[i] = NULL;
    return (super_str);
}

char	*parse_spaces(char *input, int *index, t_info *inf)
{
    char	*start;
    char	*end;
    int		i;

    i = *index;
    start = ft_strdup(input);
    start[i++] = 0;
    link_to_str(start, inf);
    while (input[i] == ' ')
        (i)++;
    end = ft_substr(input, i, ft_strlen(input));
    free(input);
    *index = -1;
    return (end);
}

char    *ft_chek_redirect(char *str, int *i, t_info *inf)
{
//    if (str[*i] == '>' && str[*i + 1] == '>')
    if (str[*i] == '>')
        str = ft_redirect1(str, i, inf);
//    else if (str[*i] == '<' && str[*i + 1] == '<')
//    else if (str[*i] == '<')
    return (str);
}

char    *chek_symbol_str(t_info *inf, char *str, int *i)
{
    while (str[++(*i)]) {
//        printf("do:%s\n", str);
        if (str[*i] && (str[*i] == '\''))
            str = ft_gap(str, i, '\'');
        else if (str[*i] && str[*i] == '\"')
            str = ft_gap2(str, i, '\"', inf);
        else if (str[*i] && (str[*i] == '$' && (ft_isalnum(str[*i + 1]) || str[*i + 1] == '?')))
            str = ft_dollar_pv(str, i, porting_env(inf));
        else if (str[*i] && (str[*i] == '|'))
            str = ft_pipex_cutting(str, i, inf);
		else if (str[*i] && (str[*i] == '>' || str[*i] == '<'))
			str = ft_chek_redirect(str, i, inf);
        else if (str[*i] && str[*i] == ' ') {
            str = parse_spaces(str, i, inf);
        }
        if (!str)
            return (NULL);
    }
    if (ft_strlen(str) != 0) {
        link_to_str(str, inf);
    }
    pipe_fill_in(inf);

    print_me_pipels(inf);
    return (str);
}

void    parsing_s(t_info *inf, char *str)
{
    int			i;

    i = -1;
    if (str[0] == 0)
    {
        free(str);
        return ;
    }
    str = delete_spese(str);
    str = chek_symbol_str(inf, str,	&i);
    //требуется функция pipe
    cheak_cmd(inf);
}
