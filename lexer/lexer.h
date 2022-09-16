#ifndef LEXER_VARIABLES
# define LEXER_VARIABLES

typedef struct s_lexer
{
	int		is_command;
	char	*data;
	char	**args;
	struct	s_token		*token;
	struct	s_commander	*commander;
	struct	s_commander	*last_commander;
}	t_lexer;

#endif