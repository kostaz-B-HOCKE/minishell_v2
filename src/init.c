#include "../minishell.h"

//char    *circu_env(char *input)
//{
//    char    *str;
//    int i;
//
//    i = -1;
//    while (input[++i] && input[i] != '=')
//        ;
//    str = malloc(sizeof (char ) * i + 2);
//    if (!str)
//        return (NULL);
//    i = -1;
//    while (input[++i] && input[i] != '=')
//    {
//        str[i] = input[i];
//    }
//    str[i++] = '=';
//    str[i] = 0;
//    return (str);
//}


t_env	*lst_new_env(char *str, int i)
{
	t_env	*me_env;

	me_env = malloc(sizeof(t_env));
	if (!me_env)
		return (NULL);
	me_env->str = ft_strdup(str);
    me_env->number_list = i;
    me_env->next = NULL;
    return (me_env);
}

void    minishell_patch(t_info *inf)
{
    t_env   *tmp;
    char    *str;
    char    *str1;
    char    *str3;

    tmp = inf->env_lst;
    while (tmp != NULL)
    {
        if (ft_strncmp(tmp->str, "PWD=", 4) == 0)
        {
            str = ft_substr(tmp->str, 4, ft_strlen(tmp->str) - 4);
            break ;
        }
        tmp = tmp->next;
    }
    if (str) {
        str1 = ft_strjoin(str, "/./minishell");
        free(str);
        str3 = ft_strjoin("_=", str1);
        free(str1);
        search_env(inf, str3);
        free(str3);
    }
}

t_env	*start_list_env(t_info *inf, char **env)
{
	t_env	*start;
	t_env	*new;
	int		i;

	i = 0;
    if (env) {
        start = lst_new_env(env[0], 0);
        new = start;
        while (env[++i]) {
            new->next = lst_new_env(env[i], i);
            new = new->next;
        }
        return (start);
    }
    return (NULL);
}

int	env_move(t_info *inf, char **env)
{
	if (!inf->env_lst)
		inf->env_lst = start_list_env(inf, env);
    return (0);
}

t_info	*init_info(char **env)
{
	t_info	*inf;

    if (env) {
        inf = malloc(sizeof(t_info));
        if (!inf) {
            return (NULL);
        }
        inf->env_lst = NULL;
        inf->is_dollar = 0;
        inf->link = NULL;
        inf->pipe_lst = NULL;
        inf->fd_in = -1;
        inf->fd_out = -1;
        env_move(inf, env);
        minishell_patch(inf);
        return (inf);
    }
    return (NULL);
}

//для проверок________________________________________________________________________________________________________
void    print_me_env(t_info *inf)
{
    t_env *tmp;

//    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	tmp = inf->env_lst;
	if (tmp != NULL)
	{
		while (tmp->next)
		{
            ft_putendl_fd(tmp->str, 1);
//			printf("%s\n",  tmp->str);
//            printf("%s\n",  tmp->start);
//            printf("count_list:%d\n", tmp->number_list);
			tmp = tmp->next;
		}
        ft_putendl_fd(tmp->str, 1);
	}
}

void    print_link_p(t_link *link)
{
    t_link *tmp;

    tmp = link;
    if (tmp != NULL)
    {
        while (tmp->next)
        {
            printf("  link:%s\n",  tmp->str);
            tmp = tmp->next;
        }
        printf("  link:%s\n", tmp->str);
    }
    else
        printf("no list link\n");
}

void    print_me_pipels(t_info *inf)
{
    t_pipe *tmp;
    int i;

    i = 0;
    tmp = inf->pipe_lst;
    if (tmp != NULL)
    {
        while (tmp->next)
        {
            printf("%d", i);
            print_link_p(tmp->link);
            printf("\n");
            tmp = tmp->next;
            i++;
        }
        printf("%d", i);
        print_link_p(tmp->link);
    }
    else
        printf("no list pipe\n");
}

void    print_me_link(t_info *inf)
{
    t_link *tmp;

    tmp = inf->link;
    if (tmp != NULL)
    {
        while (tmp->next)
        {
            printf("link:%s\n",  tmp->str);
            tmp = tmp->next;
        }
        printf("link:%s\n", tmp->str);
    }
    else
        printf("no list link\n");
}

//void    print_list_pipels(t_info *inf)
//{
//    t_pipels *tmp;
//    int i;
//    int j = 0;
//
//    tmp = inf->pipels;
//    if (tmp != NULL)
//    {
//        while (tmp->next)
//        {
////            printf("NO NULL\n");
//            i = -1;
//            printf("|%d|", j++);
//            while (tmp->arg[++i])
//                printf("i%d:%s ", i, tmp->arg[i]);
//            printf("\n");
//            tmp = tmp->next;
//        }
//        i = -1;
//        printf("|%d|", j++);
//        while (tmp->arg[++i])
//            printf("i%d:%s ", i, tmp->arg[i]);
//        printf("\n");
//    }
//    else
//        printf("no list pipels\n");
//}
