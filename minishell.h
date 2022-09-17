#ifndef MINISHEL_H
# define MINISHEL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>

# define true 1
# define false 0
# define SINGLE_QUOTE '\''
# define DOUBLE_QUOTE '"'
# define DOLLAR_OP '$'

enum e_ttype
{
	PIPE, // 0 |
	STRING, // 1 echo
	HERE_DOC, // 2 <
	RED_INPUT, // 3 <<
	RED_APPEND, // 4 >>
	RED_OUTPUT   // 5 >
};

typedef	struct s_token
{
	char	*str;
	enum	e_ttype type;
	struct	s_token	*prev;
	struct	s_token	*next;
}	t_token;

typedef struct s_arguments
{
	char	*arg;
	enum	e_ttype type;
	struct	s_arguments *next;
	struct	s_arguments *prev;

}	t_arguments;

typedef	struct s_commander
{
	int		type;
	char	*command;
	char	**arguments;
	struct	s_commander *prev;
	struct	s_commander *next;
}	t_commander;

typedef	struct s_minishell
{
	char		**env;
	t_token		*token;
	t_commander	*commander;
}	t_minishell;

extern t_minishell ms;

// TOKENIZE
t_token	*tokenize(char *str);
t_token	*init_token(char *str, enum e_ttype type);
void	token_addback(t_token **token, t_token *new_token);
void	parse_token_string(t_token **token, char *str, int *pos);

//LEXICAL ANALYSIS
void	lexical_analysis();
char	*clean_quote(char *str);
char	**init_arg_arr();
void	arg_arr_push(char ***arg_arr, char *str);
t_commander *init_commander(char *command, int type);
t_commander	*commander_addback(t_commander **commander, t_commander *new_commander);

// UTILS
void	set_env(char **env);
int		is_whitespace(char c);
int		is_operator(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *str, unsigned int start, size_t len);
#endif