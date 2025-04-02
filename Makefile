CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -lreadline -lhistory

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC_FILES = $(addprefix $(SRC_DIR), \
	main.c \
	ft_get_path.c \
	ft_loop.c \
	ft_handle_input.c \
	ft_null.c \
	ft_nullb.c \
	ft_nullc.c \
	ft_prepare_argv.c \
	ft_builtin_cmd.c \
	ft_regular_cmd.c \
	ft_builtin_check.c \
	ft_skip_spaces.c \
	ft_handle_chunks.c \
	ft_is_delimiter.c \
	ft_is_redirector.c \
	ft_is_del_or_red.c \
	ft_token_count.c \
	ft_token_extractor.c \
	ft_tokenization.c \
	ft_redirection.c \
	ft_stdout_to_outfile.c \
	ft_cooler_open.c \
	ft_token_redirect.c \
	ft_token_cmds.c \
	ft_print_tokens.c \
	ft_std_dup.c \
	ft_std_reset.c \
	ft_stdin_to_infile.c \
	ft_stdout_to_pipe.c \
	ft_stdin_to_pipe.c \
	ft_builtin_env.c \
	ft_make_prompt.c \
	ft_builtin_pwd.c \
	ft_builtin_cd.c \
	ft_find_c.c \
	ft_env_functions.c \
	ft_builtin_export.c \
	ft_builtin_unset.c \
	ft_stdout_to_outfile_append.c \
	ft_builtin_echo.c \
	ft_builtin_history.c \
	ft_write_string.c \
	ft_absolute_cmd.c \
	ft_check_abs_cmds.c \
	ft_std_close.c \
	ft_too_many_args.c \
	ft_builtin_exit.c \
	ft_strip.c \
	ft_env_increase.c \
	ft_subst_string.c \
	ft_str_insert.c \
	ft_str_cut.c \
	ft_run_cmd.c \
	ft_check_access.c \
	ft_perror.c \
	ft_builtin_export_blank.c \
	ft_update_last_arg.c \
	ft_initial_shlvl.c \
	ft_get_pid_str.c \
	ft_heredoc_prepare.c \
	ft_hdlst_add.c \
	ft_hdlst_new.c \
	ft_stdin_to_heredoc.c \
	ft_hdlst_clear.c \
	ft_b_strcmp.c \
	ft_is_directory.c \
	ft_strip_tokens.c \
	ft_sig_int.c \
	ft_sig_quit.c \
	ft_heredoc_string.c \
	ft_heredoc_str_to_lst.c \
	ft_sig_term.c \
	ft_subst_excode.c \
	ft_subst_pid.c \
	ft_subst_reg.c \
	ft_my_readline.c \
	ft_heredoc_sigs.c \
	ft_b_close.c \
	ft_env_decrease.c \
	ft_env_subshell.c \
)

OBJ_FILES = $(subst $(SRC_DIR),$(OBJ_DIR),$(SRC_FILES:%.c=%.o))

NAME = minishell

# RULES

# Compile programm
all: $(NAME)

# For each required .o file compile the corresponding .c file
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the programm like this
$(NAME): $(OBJ_FILES) $(LIBFT_LIB) $(OBJ_MAIN)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(INCLUDES) $(OBJ_MAIN) $(LIBFT_LIB) -o $(NAME)

# Compile the libft
$(LIBFT_LIB):
	make -C $(LIBFT_DIR) bonus

# Make directory for object files
$(OBJ_DIR):
	mkdir obj

# Remove object files
clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_FILES) $(OBJ_MAIN)

# Remove object files, libraries and programms
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

# Print the required .o and given .c files
show:
	echo $(SRC_FILES)
	echo $(OBJ_FILES)

# Basic execution
run: $(NAME)
	valgrind --leak-check=full --track-fds=all ./$(NAME)

# Norminette
norm:
	norminette | grep -v OK! | grep -v Global

# Redo programm
re: fclean all

PHONY: all clean fclean show run norm re