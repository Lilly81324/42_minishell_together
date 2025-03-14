/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/03/14 17:07:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// For write
# include <unistd.h>
// For printf
# include <stdio.h>
// For malloc
# include <stdlib.h>
// For opening files
# include <fcntl.h>
// For S_IRUSR, S_IWUSR modes for open
# include <sys/stat.h>
// For readline
# include <readline/readline.h>
// For history
# include <readline/history.h>
// For waitpid
# include <sys/wait.h>
# include "../libft/libft.h"

// Error messages
// 		Redirection
# define REDIR_INVAL_PIPE "Invalid read end fd for pipe given\n"
# define REDIR_PIPE_TO_INP "Error redirecting stdin to read end of pipe\n"
# define REDIR_OUT_TO_PIPE "Error redirecting stdout to write end of pipe\n"
# define REDIR_INVAL_INFILE "Error opening infile\n"
# define REDIR_INF_TO_INP "Error redirecting stdin to infile\n"
# define REDIR_INVAL_OUTF "Error opening outfile\n"
# define REDIR_OUT_TO_OUTF "Error redirecting stdout to outfile\n"
//		Commands
# define INVALID_COMMAND "lelshell: %s: No such file or directory\n"
# define FORK_ERROR "lelshell: Error creating fork\n"
# define PWD_NONEXISTENT_ERROR "lelshell: pwd: No pwd exists\n"
# define ARG_MUCH_ERROR "lelshell: %s: too many arguments\n"
# define CD_INVALID_PATH "lelshell: cd: %s: No such file or directory\n"
# define CD_HOMELESS_ERROR "lelshell: cd: HOME not set\n"
# define EXIT_NUMERIC_ERROR "lelshell: exit: %s: numeric argument required\n"
# define FILE_EXECUTE_NO_PERMISSION	"lelshell: %s: Permission denied\n"
# define EXPORT_INVALID	"lelshell: export: %s: not a valid identifier\n"

// Error return values
# define ERNUM_CMD_NOTEXIST	127
# define ERNUM_CMD_PERM		126
# define ERNUM_CD_HOMELESS	1
# define ERNUM_CD_HOMEWRONG	1
# define ERNUM_CD_ARGC		1
# define ERNUM_CD_PATHWRONG	1
# define ERNUM_EXIT_NUMERIC	2
# define ERNUM_EXIT_ARGC	1
# define ERNUM_PWD_NOTEXIST	1
# define ERNUM_EXPORT_INVAL	1
# define ERNUM_HISTORY_ARGC	1
# define ERNUM_ENV_ARGC		1

// Used in ft_tokenization to know what to skip over
# define SPACES " \n\t\v\f\r"
# define SPECIALS "><;|"
// Used to define how many times argument substitution is called on same string
# define MAX_SUBSTITUTIONS 10

// Used for showing the prompt before readline like this:
// <PROMPT><PWD><POST_PROMPT>
# define PROMPT "[lelshell]>"
# define POST_PROMPT "$ "

typedef struct s_shell
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
int		ft_too_many_args(char *str, int exit);
void	ft_perror(char *input, char *arg1, char *arg2);
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
void	ft_builtin_export_blank(char **envp);
int		ft_builtin_unset(t_shell *shl, int *pos);
int		ft_builtin_echo(t_shell *shl, int *pos);
int		ft_builtin_history(t_shell *shl, int *pos);
// Basic command or rest
int		ft_check_abs_cmds(char **token, int pos);
int		ft_absolute_cmd(t_shell *shl, int *pos);
int		ft_check_access(char *path, char *cmd);
int		ft_run_cmd(t_shell *shl, char *path, char **argv);
char	*ft_str_add(char *s1, char *s2);
char	*ft_get_path(char *cmd, char ***envp);
int		ft_regular_cmd(t_shell *shl, int *pos);
char	**ft_prepare_argv(char **arg, int *pos);
void	ft_update_last_arg(t_shell *shl, char *arg);

#endif