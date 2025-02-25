CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

BASE_LIBFT_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONUS_LIBFT_FILES = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c 
PRINTF_FILES = ft_char_in_str.c ft_handle_diff.c ft_handle_specials.c ft_handle_strings.c ft_percent_strlen.c ft_print_char.c ft_printf.c ft_print_int.c ft_print_ptr.c ft_print_str.c ft_print_unsint.c ft_print_x.c ft_print_xcap.c ft_ptr_to_hex.c
GET_NEXT_FILES = get_next_line.c get_next_line_utils.c
BASE_SRC = $(BASE_LIBFT_FILES)
BONUS_SRC = $(BONUS_LIBFT_FILES) $(BASE_SRC)
BASE_OBJ = $(BASE_SRC:%.c=%.o)
BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

all: $(NAME)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile all objects into final file
$(NAME): $(BASE_OBJ)
	ar rcs $(NAME) $(BASE_OBJ)

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	rm -rf $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
