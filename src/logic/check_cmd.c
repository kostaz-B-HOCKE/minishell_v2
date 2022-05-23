#include "../../minishell.h"

//функция из пайпа определяет относительный путь
char	*chek_cmd_file(char **env, char	*cmd)
{
    int		i;
    char	*str;
    char	**str_split;
    char	**chek_split;
    char	*str_chek;

    i = 0;
    while (ft_strnstr(env[i], "PATH", 4) == 0)
        i++;
    str_split = ft_split(env[i] + 5, ':');
    chek_split = ft_split(cmd, ' ');
    i = 0;
    while (str_split[i])
    {
        str = ft_strjoin(str_split[i], "/");
        str_chek = ft_strjoin(str, chek_split[0]);
        free(str);
        if (access(str_chek, F_OK) == 0)
            return (str_chek);
        i++;
        free(str_chek);
    }
    spl_free(str_split);
    spl_free(chek_split);
    return (0);
}

void    cheak_cmd(t_info *inf)
{
//    printf("1:%s\n", inf->link->str);
    if (ftt_strcmp(inf->link->str, "env") == 0)
        print_me_env(inf);
    else if (ftt_strcmp(inf->link->str, "pwd") == 0)
        ftt_pwd(inf);
    else if (ftt_strcmp(inf->link->str, "echo") == 0)
        ftt_echo(inf);
    else if (!ftt_strcmp(inf->link->str, "exit"))
        ftt_exit(inf, porting_link_str(inf));
//    else if (!ftt_strcmp(inf->link->str, "cd"))
//        ft_cd(inf);
    else if (ftt_strcmp(inf->link->str, "export") == 0) {
        ft_export(inf);
    }
    else if (ftt_strcmp(inf->link->str, "unset") == 0)
        ft_unset(inf);
//    else if (ftt_strcmp(inf->link->str, "555") == 0)
//        printf("555 666\n");
//        exit(0);
    else
    {
        printf("остальные команды\n");
//        printf("chek_cmd_file:%s\n", chek_cmd_file(porting_link_str(inf), inf->link->str));
//        execve(command, )
//        printf()
    }
}
