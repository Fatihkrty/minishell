#ifndef MINISHEL_H
#define MINISHEL_H
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/ioctl.h>

// Bool defines
#define true 1
#define false 0

// Program defines
#define DOLLAR_OP '$'
#define DOUBLE_QUOTE '"'
#define SINGLE_QUOTE '\''
#define CHILD_PROCESS 0
#define MAIN_PROCESS 1

// File Mode defines
#define REPLACE 1
#define APPEND 0

//Bultins Type
enum e_builtin_types
{
	CD = 1,
	ENV,
	PWD,
	ECHO,
	EXIT,
	UNSET,
	EXPORT
};

// Type defines
enum e_ttype
{
	PIPE = 1,
	STRING,
	HERE_DOC,
	RED_INPUT,
	RED_APPEND,
	RED_OUTPUT
};

typedef struct s_token
{
	char			*str;
	enum	e_ttype	type;
	struct	s_token	*prev;
	struct	s_token	*next;
} t_token;

typedef struct s_process
{
	pid_t				pid;
	int					fd[2];
	char				**execute;
	char				**redirects;
	struct s_process	*prev;
	struct s_process	*next;
}	t_process;

typedef struct s_minishell
{
	int			parent_pid;
	int			heredoc_fd[2];
	int			process_count;
	int			status;
	char		**env;
	char		**paths;
	t_token		*token;
	t_process	*process;
} t_minishell;

extern t_minishell ms;

// TOKENIZE
void		tokenize(char *str);
void		parse_token_string(char **str);
t_token		*init_token(char *str, enum e_ttype type);
void		token_addback(t_token **token, t_token *new_token);

// LEXICAL ANALYSIS
void		lexer();
t_process	*init_process();
char		*clean_quote(char *str);
char		**push_array(char **arg_arr, char *str);
void		process_addback(t_process **process, t_process *new_process);

// FREE
void	free_app();
void	free_token();
void	free_array(char **arr);

// CMD
void 	start_cmd();
void    run_cmd(t_process *process);

//BUILTINS
int		is_builtin(char *command);
void    run_builtin(char **execute);
void	builtin_env();
void	builtin_cd(char **input);
void	builtin_exit(char **input);
void	builtin_pwd(char **input);
void	builtin_echo(char **input);
void	builtin_unset(char **input);
void	builtin_export(char **input);

// REDIRECT_FUNCS
void	input(char *file);
void	heredoc(char *endline);
void	output(t_process *process, char *file, int mode);
void	run_redirects(t_process *process);

//HEREDOC
void	get_all_inputs(t_process *process);
void	set_all_outputs(t_process *process);

//CLOSE
void    close_all_fd();
void	close_heredoc_fd();

//ERROR
void    token_err();
void    command_err();
void    directory_err();
void	no_file_err();

// UTILS
int		is_parent();
void    set_paths();
int		env_len();
char	*get_env(char *str);
void	set_env(char **env);
char    *get_path(char *cmd);
int		is_whitespace(char c);
int		is_operator(char *str);
int		is_heredoc(t_process *process);

// LIBFT UTILS
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *str, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *str1, const char *str2);
int 	ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_substr(char const *str, unsigned int start, size_t len);

// TESTER
void token_test();
void lexer_test();


#endif
