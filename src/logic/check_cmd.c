#include "../../minishell.h"

void    cheak_cmd(t_info *inf)
{
    if (ftt_strcmp(inf->link->str, "env") == 0)
        print_me_env(inf);
    else if (ftt_strcmp(inf->link->str, "pwd") == 0)
        ftt_pwd(inf);
    else if (ftt_strcmp(inf->link->str, "echo") == 0)
        ftt_echo(inf);
    else if (!ftt_strcmp(inf->link->str, "exit"))
        ftt_exit(porting_link_str(inf));
    else if (ftt_strcmp(inf->link->str, "export") == 0)
        ft_export(inf);
    else if (ftt_strcmp(inf->link->str, "unset") == 0)
        ft_unset(inf);
//    sle
//        ftt_pwd(inf);


}