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

// Bool defines
#define true 1
#define false 0

// Program defines
#define DOLLAR_OP '$'
#define DOUBLE_QUOTE '"'
#define SINGLE_QUOTE '\''
#define CHILD_PROCESS 0

// File Mode defines
#define REPLACE 1
#define APPEND 0

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

// Freelendi
typedef struct s_token
{
	char			*str; // Freelendi
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
t_token		*init_token(char *str, enum e_ttype type);
void		token_addback(t_token **token, t_token *new_token);
void		parse_token_string(char **str);

// LEXICAL ANALYSIS
void		lexer();
t_process	*init_process();
char		*clean_quote(char *str);
char		**push_array(char **arg_arr, char *str);
void		process_addback(t_process **process, t_process *new_process);

// FREE
void	free_app();
void	free_token();

// BUILTIN_FUNC
void	env_func();
int		get_env_len();
void	unset(char *str);
void	export(char *str);

// CMD
void 	close_all_fd();
void 	start_cmd();
void    run_cmd(t_process *process);

// REDIRECT_FUNCS
void	red_input(char *file);
void	red_output(char *file, int mode);
void	run_heredoc(t_process *process);
void	run_redirects(t_process *process, int heredoc);
void	red_heredoc(char *endline);
void	close_heredoc_fd();

// PIPE ROUTER
void    pipe_route(t_process *process);

// UTILS
char	*get_env(char *str);
void	set_env(char **env);
char    *get_path(char *cmd);
int		is_whitespace(char c);
int		is_operator(char *str);
int		is_heredoc(t_process *process);

// LIBFT UTILS
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *str, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_substr(char const *str, unsigned int start, size_t len);

// TESTER
void token_test();
void lexer_test();

#endif
