/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/04/08 19:35:39 by sikunne          ###   ########.fr       */
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
// For Signals
# include <signal.h>
// For checking if file is directory
# include <dirent.h>
// For ioctl to make SIGINT signal
# include <sys/ioctl.h>

# include "../libft/libft.h"

// Error messages
//		General
# define ARGC_START "lelshell: Too many arguments for lelshell\n"
# define ERR_SHLVL_MAX \
"lelshell: warning: shell level (%s) too high, resetting to 1\n"
# define NO_SUCH_FILE "lelshell: %s: No such file or directory\n"
# define QUOTE_UNCLOSED "lelshell: Error, unquoted quote unclosed\n"
# define FORK_ERROR "lelshell: Error creating fork\n"
// 		Syntax
# define SYNTAX_REDIR "lelshell: syntax error near unexpected token `%s'\n"
// 		Redirection
# define REDIR_INVAL_PIPE "Invalid read end fd for pipe given\n"
# define REDIR_PIPE_TO_INP "Error redirecting stdin to read end of pipe\n"
# define REDIR_OUT_TO_PIPE "Error redirecting stdout to write end of pipe\n"
# define REDIR_INF_TO_INP "Error redirecting stdin to infile\n"
# define REDIR_INVAL_OUTF "Error opening outfile\n"
# define REDIR_OUT_TO_OUTF "Error redirecting stdout to outfile\n"
//		Commands
# define INVALID_COMMAND "lelshell: %s: command not found\n"
# define CMD_IS_DIR "lelshell: %s: Is a directory\n"
# define PWD_NONEXISTENT_ERROR "lelshell: pwd: No pwd exists\n"
# define ARG_MUCH_ERROR "lelshell: %s: too many arguments\n"
# define CD_INVALID_PATH "lelshell: cd: %s: No such file or directory\n"
# define CD_HOMELESS_ERROR "lelshell: cd: HOME not set\n"
# define EXIT_NUMERIC_ERROR "lelshell: exit: %s: numeric argument required\n"
# define FILE_EXECUTE_NO_PERMISSION	"lelshell: %s: Permission denied\n"
# define EXPORT_INVALID	"lelshell: export: %s: not a valid identifier\n"

// Error return values
# define ERNUM_START_ARGC	1
# define ERNUM_SYNTAX		2
# define ERNUM_CMD_IS_DIR	126
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
# define ERNUM_CTRLC		130

// For shlvl increasing at start
# define MAX_SHLVL 999

// Used in ft_tokenization to know what to skip over
# define SPACES " \n\t\v\f\r"
// For SEMICOLON handling add semicolon to SPECIALS, more in ft_isdelimiter
# define SPECIALS "><|"
// Used to define how many times argument substitution is called on same string
# define MAX_SUBSTITUTIONS 20

// Used for showing the prompt before readline like this:
// <PROMPT><PWD><POST_PROMPT>
# define PROMPT "[lelshell]>"
# define POST_PROMPT "$ "

typedef struct s_shell
{
	char		**tok;
	char		***env;
	char		**subenv;
	int			exit_code;
	int			*hd_fd;
}	t_shell;

extern volatile sig_atomic_t	g_sig;

// Utility-------------------------------------------------
void	ft_null(char **ptr);
void	ft_nullb(char ***ptr);
void	ft_nullc(char ***ptr);
void	ft_null_int(int **ptr);
void	ft_skip_spaces(int *i, char *str);
int		ft_cooler_open(char *filename, int flags, mode_t mode);
int		ft_is_delimiter(char *str);
int		ft_is_redirector(char *str);
int		ft_is_del_or_red(char *str);
int		ft_is_chunk_delim(char *str);
int		ft_find_c(char c, char *string);
void	ft_write_string(char *string);
char	*ft_strip(char *extra, char *core);
int		ft_b_strcmp(char *s1, char *s2);
void	ft_b_close(int *fd);
void	ft_skip_redirector(char **tok, int *pos);
// Redirection
void	ft_std_dup(int *std);
void	ft_std_reset(int *std);
void	ft_std_close(int *std);
int		ft_stdout_to_outfile(char *filename);
int		ft_stdout_to_pipe(void);
int		ft_stdin_to_infile( char *filename);
int		ft_stdin_to_pipe(int r_end);
int		ft_stdout_to_outfile_append(char *filename);
int		ft_stdin_to_heredoc(t_shell *shl, int pos);
// Debugging
void	ft_print_tokens(char **tokens);
// Enviroment Functions
char	**ft_copy_env(char **envp);
void	ft_remove_env(char ***envp, char *key);
char	*ft_get_env(char **envp, char *key);
void	ft_change_env(char ***envp, char *pair);
void	ft_env_increase(char ***envp, char *target, int value);
void	ft_env_decrease(char ***envp, char *target, int value);
char	**ft_env_subshell(char ***src);
// Error Functions
int		ft_too_many_args(char *str, int exit);
void	ft_perror(char *input, char *arg1, char *arg2);
// String Manipulation
char	*ft_str_insert(char *src, char *goal, int pos);
int		ft_str_cut(char **src, int pos, int cutlen);

// Programm------------------------------------------------
// Signals
void	ft_sig_int(int sig);
void	ft_sig_quit(int sig);
int		ft_sig_term(char *input);
// Starting up
void	ft_init_setup(char ***env);
void	ft_initial_shlvl(char ***new_env);
int		ft_loop(char ***envp);
// Input getting
char	*ft_make_prompt(char ***envp);
char	*ft_my_readline(char *prompt);
int		ft_handle_input(char **inp, t_shell *shl);
// Tokenize input
void	ft_subst_string(t_shell *shl, char **str);
int		ft_subst_excode(t_shell *shl, char **str, int index);
int		ft_subst_pid(char **str, int index);
void	ft_subst_reg(char **env, char **str, int index);
char	*ft_get_pid_str(void);
int		ft_token_count(char *s);
void	ft_token_extractor(char *s, char ***result);
char	**ft_tokenization(char *s);
void	ft_strip_tokens(char **tok);
// HEREDOcs
int		ft_count_prev_hds(t_shell *shl, int pos);
int		ft_heredoc_string(t_shell *shl, char **new_buf, char **total_buf);
void	ft_heredoc_str_to_lst(t_shell *shl, char *s, int pos);
int		ft_heredoc_prepare(t_shell *shl);
int		ft_heredoc_sigs(t_shell *shl, char **n_buf, char **t_buf);
// Executing the input
int		ft_handle_input_loop(t_shell *shl, int *std);
int		ft_syntax_check(t_shell *shl);
int		ft_count_pipes(char **tok, int pos);
int		ft_singlechunk(t_shell *shl, int *pos);
int		ft_multichunk(t_shell *shl, int *std, int *pos);
int		ft_pipes(t_shell *shl, int pos, int *fd);
int		ft_subchunk(t_shell *shl, int *pos, int *std, int lpipe);
// Redirecting
int		ft_token_redirect(t_shell *shl, int i);
int		ft_redirection(t_shell *shl, int pos);
// Commands
int		ft_token_cmds(t_shell *shl, int i, char ***envp, int *ex);
// Builtin command
int		ft_builtin_check(char *inp);
int		ft_builtin_cmd(t_shell *shl, int *pos, char ***env, int *ex);
int		ft_builtin_exit(t_shell *shl, int *pos, int *ex);
int		ft_builtin_env(t_shell *shl, int *pos, char ***env);
int		ft_builtin_pwd(int *pos);
int		ft_builtin_cd(t_shell *shl, int *pos, char ***env);
int		ft_builtin_export(t_shell *shl, int *pos, char ***env);
void	ft_builtin_export_blank(char **envp);
int		ft_builtin_unset(t_shell *shl, int *pos, char ***env);
int		ft_builtin_echo(t_shell *shl, int *pos);
int		ft_builtin_history(t_shell *shl, int *pos);
// Basic command or rest
int		ft_check_abs_cmds(char **token, int pos);
int		ft_check_access(char *path, char *cmd);
int		ft_is_directory(char *path);
int		ft_absolute_cmd(t_shell *shl, int *pos, char ***env);
char	*ft_get_path(char *cmd, char ***envp);
int		ft_regular_cmd(t_shell *shl, int *pos, char ***env);
char	**ft_prepare_argv(char **arg, int *pos);
int		ft_run_cmd(char *path, char **argv, char ***env);
void	ft_update_last_arg(char *arg, char ***env);

#endif