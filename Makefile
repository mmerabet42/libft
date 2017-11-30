NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

_SRCS	=	ft_abs.c \
			ft_atod.c \
			ft_atoi.c \
			ft_atoi_base.c \
			ft_atol.c \
			ft_atoll.c \
			ft_atoui.c \
			ft_atoull.c \
			ft_btree_balance.c \
			ft_btree_copy.c \
			ft_btree_create.c \
			ft_btree_del.c \
			ft_btree_delone.c \
			ft_btree_erase.c \
			ft_btree_erasef.c \
			ft_btree_fromlist.c \
			ft_btree_fromlistf.c \
			ft_btree_insert.c \
			ft_btree_insertf.c \
			ft_btree_left.c \
			ft_btree_leftrotate.c \
			ft_btree_new.c \
			ft_btree_right.c \
			ft_btree_rightrotate.c \
			ft_btree_search.c \
			ft_btree_searchf.c \
			ft_btree_size.c \
			ft_btree_swap.c \
			ft_btree_tolist.c \
			ft_bzero.c \
			ft_dtoa.c \
			ft_intlen.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_iscntrl.c \
			ft_isdigit.c \
			ft_islower.c \
			ft_isprint.c \
			ft_ispunct.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_itoa.c \
			ft_itoa_cbase.c \
			ft_llonglen.c \
			ft_lltoa.c \
			ft_longlen.c \
			ft_lstadd.c \
			ft_lstatpos.c \
			ft_lstcopy.c \
			ft_lstcopyone.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstend.c \
			ft_lstfind.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstpush.c \
			ft_lstpushfront.c \
			ft_lstsize.c \
			ft_ltoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memdup.c \
			ft_memalloc.c \
			ft_memmove.c \
			ft_memset.c \
			ft_pow.c \
			ft_putchar.c \
			ft_putnchar.c \
			ft_putchar_fd.c \
			ft_putnchar_fd.c \
			ft_putdouble.c \
			ft_putdouble_fd.c \
			ft_putendl.c \
			ft_putnendl.c \
			ft_putendl_fd.c \
			ft_putnendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_base.c \
			ft_putnbr_base_fd.c \
			ft_putnbr_fd.c \
			ft_putptr.c \
			ft_putptr_fd.c \
			ft_putstr.c \
			ft_putnstr.c \
			ft_putstr_fd.c \
			ft_putnstr_fd.c \
			ft_putullong_base.c \
			ft_putullong_base_fd.c \
			ft_putunbr.c \
			ft_putunbr_fd.c \
			ft_revnstr.c \
			ft_revstr.c \
			ft_strafter.c \
			ft_strafterstr.c \
			ft_strbefore.c \
			ft_strbeforestr.c \
			ft_strcat.c \
			ft_strcatc.c \
			ft_strchr.c \
			ft_strchr_pos.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcount.c \
			ft_strcountstr.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strjoin_clr.c \
			ft_strjoinc.c \
			ft_strjoinc_clr.c \
			ft_strjoincs.c \
			ft_strjoincs_clr.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_sqrt.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strmdup.c \
			ft_strncat.c \
			ft_strnchr.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnrchr.c \
			ft_strnrstr.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrep.c \
			ft_strrep_clr.c \
			ft_strrepstr.c \
			ft_strrepstr_clr.c \
			ft_strrstr.c \
			ft_strsplit.c \
			ft_strsplitstr.c \
			ft_strstr.c \
			ft_strstr_pos.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_swap.c \
			ft_swapptr.c \
			ft_tobase.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_uintlen.c \
			ft_uitoa.c \
			ft_ullonglen.c \
			ft_ulltoa.c

SRCS_DIR=	.
SRCS	=	$(patsubst %,$(SRCS_DIR)/%,$(_SRCS))
OBJS	=	$(SRCS:.c=.o)

# COLORS
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m
_SUCCESS=$(_GREEN)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): compile
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) : $(_SUCCESS)done$(_END)"

compile:
	@echo "$(_RED)Compiling$(_END) : $(NAME) $(_SUCCESS)...$(_END)"
	@$(CC) $(CFLAGS) -c $(SRCS)

clean:
	@/bin/rm -f $(OBJS)
	@echo "clean: $(_SUCCESS)done$(_END)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "fclean: $(_SUCCESS)done$(_END)"

re: fclean all
