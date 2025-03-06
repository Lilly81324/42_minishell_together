/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/06 16:55:55 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define SHELL_NAME "yevshell"

// Error messages
# define INVALID_COMMAND 	SHELL_NAME ": Not a valid command\n"
# define FORK_ERROR 		SHELL_NAME": Error creating fork\n"
# define PWD_NONEXISTENT_ERROR SHELL_NAME ": pwd: No pwd exists\n"
# define ARG_MUCH_ERROR 	SHELL_NAME ": %s: too many arguments\n"
# define CD_INVALID_PATH 	SHELL_NAME ": cd: %s: No such file or directory\n"
# define CD_HOMELESS_ERROR 	SHELL_NAME ": cd: HOME not set\n"

// Used in ft_tokenization to know what to skip over
# define SPACES " \n\t\v\f\r"
# define SPECIALS "><;|"

// Used for showing the prompt before readline like this:
// <PROMPT><PWD><POST_PROMPT>
// example:
// PROMPT="lilshell:"	POST_PROMPT=">"
// lilshell:/home/sikunne>
# define PROMPT "[yevshell]>"
# define POST_PROMPT "$ "

// Utility-------------------------------------------------
char	*ft_get_path(char *cmd);
char	*ft_space_bef(char *str);
void	ft_null(char **ptr);
void	ft_nullb(char ***ptr);
void	ft_nullc(char ***ptr);
void	ft_skip_spaces(int *i, char *str);
int		ft_cooler_open(char *filename);
int		ft_is_delimiter(char *str);
int		ft_is_redirector(char *str);
int		ft_is_del_or_red(char *str);
char	**ft_split_quot_ex(char const *s, char c);
int		ft_find_c(char c, char *string);
void	ft_write_string(char *string);
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
// Error Functions
int		ft_too_many_args(char *str);

// Programm------------------------------------------------
int		ft_loop(char ***envp);
// Input getting
char	*ft_make_prompt(char ***envp);
int		ft_handle_input(char *inp, char ***envp);
// Tokenize input
int		ft_token_count(char *s);
void	ft_token_extractor(char *s, char ***result);
char	**ft_tokenization(char *s);
// Executing the input
int		ft_handle_input_loop(char **tokens, int *std, char ***envp);
int		ft_pipe_setup(char **tokens, int pos);
int		ft_handle_chunks(char *arg[], int *ri, char ***envp);
// Redirecting
int		ft_token_redirect(char *arg[], int i);
int		ft_redirection(char **argv, int pos);
// Commands
int		ft_token_cmds(char *arg[], int i, char ***envp);
// Builtin command
int		ft_check_special(char *inp);
int		ft_special_cmd(char **tokens, int *pos, char ***envp);
int		ft_builtin_env(int *pos, char ***envp);
int		ft_builtin_pwd(char **tokens, int *pos);
int		ft_builtin_cd(char **tokens, int *pos, char ***envp);
int		ft_builtin_export(char **tokens, int *pos, char ***envp);
int		ft_builtin_unset(char **tokens, int *pos, char ***envp);
int		ft_builtin_echo(char **tokens, int *pos);
int		ft_builtin_history(int *pos);
// Basic command or rest
int		ft_check_abs_cmds(char **token, int pos);
int		ft_absolute_cmd(char **token, int *pos, char ***envp);
char	*ft_str_add(char *s1, char *s2);
int		ft_regular_cmd(char **arg, int *pos, char ***envp);
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