NAME		= minishell

SRB_DIR		= src/

SRB		= $(addprefix $(SRB_DIR), main.c init.c parsing.c ft_qap.c ft_dollar.c list_command.c utilus2.c \
								list_command_util.c utilus.c	pipex_test.c	logic/check_cmd.c	1_utilus.c		\
								shlv.c logic/ftt_echo.c	logic/ft_exit.c	logic/ft_unset.c	\
								logic/ft_pwd.c	logic/ft_export.c\
								)


#SRB		= $(addprefix $(SRB_DIR), main.c execve_unil.c pipex.c init.c \
#					adoption_cmd.c par.c shell_level.c utilus.c ft_dollar.c ft_qap.c \
#					utilus_free.c check_util.c redirect_1.c reading_get_line.c \
#					list_command_util.c	list_command.c  parsin.c  pipe_list_utilus.c      \
#					exe_command.c error_util.c execute_ft_pipe.c ft_pwd.c				\
#					ftt_echo.c ftt_cd.c)



#SRB		= $(addprefix $(SRB_DIR), main.c)

OBJ			= $(SRB:.c=.o)

LIB			= libft/libft.a

#CFLAGS		= -Wall -Wextra -Werror
CFLAGS		=
RED			=	"\033[1;31m"
BLUE		=	"\033[1;34m"
YELLOW		=	"\033[1;33m"
WHITE		=	"\033[1;37m"
GREEN		=	"\033[1;32m"
PURPLE		=	"\033[1;35m"
GRAY		=	"\033[1;30m"
END			=	"\033[0m"
#@echo ${YELLOW} "\n< .o files -> removed >\n" ${END}

.PHONY:		all clean fclean re

all:		$(LIB) $(NAME)

$(NAME):	$(OBJ)
			@gcc $(CFLAGS) -L /Users/$(USER)/.brew/opt/readline/lib/ -lreadline -L libft -lft -o ${NAME} ${OBJ}

$(LIB):
			@make -C libft

clean:
			@$(RM) $(OBJ)
			@make $@ -C libft

fclean:		clean
			@$(RM) $(NAME)
			@make $@ -C libft

re:			fclean all
