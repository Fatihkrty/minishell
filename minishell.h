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
	EMPTY, // 1
	STRING, // 2
	HERE_DOC, // 3
	RED_INPUT, // 4
	RED_APPEND, // 5
	RED_OUTPUT // 6
};

typedef	struct s_token
{
	char	*str;
	enum	e_ttype type;
	struct	s_token	*prev;
	struct	s_token	*next;
}	t_token;

typedef	struct s_ms
{
	t_token	token;
}	t_ms;


size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	**ft_split(char const *str, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_replace(char *str, char from, char from2, char to);
char	*ft_substr(char const *str, unsigned int start, size_t len);
#endif