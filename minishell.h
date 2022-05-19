#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
#include "libft/libft.h"
# define SHELL_NAME "minishell% "
# define ERROR_NAME "minishell"
# define ONE_TOKEN "Error! Unclosed quote"
# define TWO_TOKEN "Error! Unclosed dquote"
# define SYNTAX_TOKEN "syntax error"
# define IN_TOKEN "syntax error near unexpected token `<'"
# define OUT_TOKEN "syntax error near unexpected token `>'"
# define PIPE_TOKEN "syntax error near unexpected token `|'"
# define NEW_TOKEN "syntax error near unexpected token `newline'"
# define BUFFER_SIZE 1024
# define D "/"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"

int	gl_exit;

typedef struct  s_link
{
    char    *str;
    struct  s_link *next;
}           t_link;

typedef struct  s_pipels
{
    char        *str;
    struct s_pipels *next;
}   t_pipels;







typedef struct	s_env
{
    char			*str;
    int				number_list;
    struct s_env	*next;
}				t_env;

typedef struct	s_info
{
    int     is_dollar;
//	char	*shlvl;
//    t_pipels *pipels;

    t_link  *link;
	t_env	*env_lst;
}		t_info;

//от readline
extern void rl_replace_line(const char *, int);

//проверки
void    print_me_env(t_info *inf);
void    print_me_link(t_info *inf);
void    print_list_pipels(t_info *inf);

//init.c
t_info	*init_info(char **env);


//parsing.c
void    parsing_s(t_info *inf, char *str);
char    **porting_env(t_info *info);
char	*parse_spaces(char *input, int *index, t_info *inf);
char    *chek_symbol_str(t_info *inf, char *str, int *i);

//list_command_util.c
void    link_to_str(char *str, t_info *inf);
t_link  *list_new_mini(char *str);
void    link_add_list(t_link **old, t_link *new);
void    free_link(t_link **link);
int     link_size(t_link *link);

//ft_qap.c
char	*ft_gap(char *str, int *i, char c);
char	*ft_gap2(char *str, int *i, char c, t_info *inf);

//utilus.c
char	*ft_strjoin_free(char *s1, char *s2);

//ft_dollar.c
char	*ft_dollar_pv(char *str, int *i, char **env);


#endif
