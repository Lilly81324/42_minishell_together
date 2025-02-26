CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -lreadline

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC_FILES = $(addprefix $(SRC_DIR), \
	main.c \
	ft_get_path.c \
	ft_space_bef.c \
	ft_loop.c \
	ft_handle_input.c \
	ft_null.c \
	ft_nullb.c \
	ft_nullc.c \
	ft_prepare_argv.c \
	ft_special_cmd.c \
	ft_regular_cmd.c \
	ft_check_special.c \
	ft_skip_spaces.c \
	ft_c_in_s.c \
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
	ft_token_skip_chunk.c \
	ft_print_tokens.c \
	ft_dup_std.c \
	ft_reset_std.c \
	ft_stdin_to_infile.c \
	ft_stdout_to_pipe.c \
	ft_stdin_to_pipe.c \
	ft_builtin_env.c \
	ft_make_prompt.c \
	ft_builtin_pwd.c \
	ft_split_quot_ex.c \
	ft_builtin_cd.c \
	ft_find_c.c \
	ft_env_functions.c \
	ft_builtin_export.c \
	ft_builtin_unset.c \
	ft_stdout_to_outfile_append.c \
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
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) $(OBJ_MAIN) $(LIBFT_LIB) -o $(NAME)

# Compile the libft
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

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
run:
	valgrind --leak-check=full ./$(NAME)

# Redo programm
re: fclean all

PHONY: all clean fclean show run re