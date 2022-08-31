#ifndef MINISHEL_H
# define MINISHEL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>

# define true 1
# define false 0


enum e_ttype
{
	PIPE, // 0
	STRING, // 1
	HERE_DOC, // 2
	RED_INPUT, // 3
	RED_APPEND, // 4
	RED_OUTPUT   // 5
};

typedef	struct s_token
{
	char	*str; // Default NULL
	enum	e_ttype type;
	struct	s_token	*prev; // Default NULL
	struct	s_token	*next; // Default NULL
}	t_token;

typedef	struct s_minishell
{
	char	**env;
	t_token	*token;
}	t_minishell;

extern t_minishell ms;

// TOKENIZE
t_token	*tokenize(char *str);
t_token	*init_token(char *str, enum e_ttype type);
void	token_addback(t_token **token, t_token *new_token);
void	parse_token_string(t_token **token, char *str, int *pos);


// UTILS
int		is_whitespace(char c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *str, unsigned int start, size_t len);
#endif