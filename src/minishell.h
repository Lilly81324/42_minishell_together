/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/12 17:25:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
// # include <limits.h>
// for S_IRUSR, S_IWUSR modes for open
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define SHELL_NAME "yevshell"

// Error messages
# define INVALID_COMMAND 			\
"yevshell: %s: No such file or directory\n"
# define FORK_ERROR 				\
"yevshell: Error creating fork\n"
# define PWD_NONEXISTENT_ERROR		\
"yevshell: pwd: No pwd exists\n"
# define ARG_MUCH_ERROR  			\
"yevshell: %s: too many arguments\n"
# define CD_INVALID_PATH 			\
"yevshell: cd: %s: No such file or directory\n"
# define CD_HOMELESS_ERROR  		\
"yevshell: cd: HOME not set\n"
# define EXIT_NUMERIC_ERROR 		\
"yevshell: exit: %s: numeric argument required\n"
# define FILE_EXECUTE_NO_PERMISSION	\
"yevshell: %s: Permission denied\n"

// Used in ft_tokenization to know what to skip over
# define SPACES " \n\t\v\f\r"
# define SPECIALS "><;|"
// Used to define how many times argument substitution is called on same string
# define MAX_SUBSTITUTIONS 10

// Used for showing the prompt before readline like this:
// <PROMPT><PWD><POST_PROMPT>
# define PROMPT "[yevshell]>"
# define POST_PROMPT "$ "

typedef struct	s_shell
{
	char	**tok;
	char	***env;
	int		exit_code;
}	t_shell;

// Utility-------------------------------------------------
void	ft_null(char **ptr);
void	ft_nullb(char ***ptr);
void	ft_nullc(char ***ptr);
void	ft_skip_spaces(int *i, char *str);
int		ft_cooler_open(char *filename, int flags, mode_t mode);
int		ft_is_delimiter(char *str);
int		ft_is_redirector(char *str);
int		ft_is_del_or_red(char *str);
char	**ft_split_quot_ex(char const *s, char c);
int		ft_find_c(char c, char *string);
void	ft_write_string(char *string);
char	*ft_strip(char *extra, char *core);
// Redirection
int		ft_stdout_to_outfile(char *filename);
int		ft_stdout_to_pipe(void);
int		ft_stdin_to_infile(char *filename);
int		ft_stdin_to_pipe(int r_end);
void	ft_std_dup(int *std);
void	ft_std_reset(int *std);
void	ft_std_close(int *std);
int		ft_stdout_to_outfile_append(char *filename);
// Debugging
void	ft_print_tokens(char **tokens);
// Enviroment Functions
char	**ft_copy_env(char **envp);
void	ft_remove_env(char ***envp, char *key);
char	*ft_get_env(char **envp, char *key);
void	ft_change_env(char ***envp, char *pair);
void	ft_env_increase(char ***envp, char *target, int value);
// Error Functions
int		ft_too_many_args(char *str);
// String Manipulation
char	*ft_str_insert(char *src, char *goal, int pos);
int		ft_str_cut(char **src, int pos, int cutlen);

// Programm------------------------------------------------
int		ft_loop(char ***envp);
// Input getting
char	*ft_make_prompt(char ***envp);
int		ft_handle_input(char **inp, t_shell *shl);
// Tokenize input
void	ft_string_substitution(t_shell *shl, char **str);
int		ft_token_count(char *s);
void	ft_token_extractor(char *s, char ***result);
char	**ft_tokenization(char *s);
// Executing the input
int		ft_handle_input_loop(t_shell *shl, int *std);
int		ft_pipe_setup(char **tokens, int pos);
int		ft_handle_chunks(t_shell *shl, int *i);
// Redirecting
int		ft_token_redirect(char **tok, int i);
int		ft_redirection(char **argv, int pos);
// Commands
int		ft_token_cmds(t_shell *shl, int i);
// Builtin command
int		ft_check_special(char *inp);
int		ft_special_cmd(t_shell *shl, int *pos);
int		ft_builtin_exit(t_shell *shl, int *pos);
int		ft_builtin_env(t_shell *shl, int *pos);
int		ft_builtin_pwd(t_shell *shl, int *pos);
int		ft_builtin_cd(t_shell *shl, int *pos);
int		ft_builtin_export(t_shell *shl, int *pos);
int		ft_builtin_unset(t_shell *shl, int *pos);
int		ft_builtin_echo(t_shell *shl, int *pos);
int		ft_builtin_history(t_shell *shl, int *pos);
// Basic command or rest
int		ft_check_abs_cmds(char **token, int pos);
int		ft_absolute_cmd(t_shell *shl, int *pos);
int		ft_run_cmd(char *path, char **argv, char **envp, int *status);
char	*ft_str_add(char *s1, char *s2);
char	*ft_get_path(char *cmd, char ***envp);
int		ft_regular_cmd(t_shell *shl, int *pos);
char	**ft_prepare_argv(char **arg, int *pos);

// Builtins such as cd, unset or export run in parent process
// otherwise every other command runs as child

// Every chunk like redirection has different amount of blocks it needs,
// The current position needst to be increased accordingly

// I used continue instead of return, are we allowed to use that?

// env -> remove a rule, add a rule

// what if every chunk is run as child process, 
// and then the execve call is run as a child of that?

// tokens given
// check if next delimiter 

#endif