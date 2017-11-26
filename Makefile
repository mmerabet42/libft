NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

_OBJS	=	ft_abs.o \
			ft_atod.o \
			ft_atoi.o \
			ft_atoi_base.o \
			ft_atol.o \
			ft_atoll.o \
			ft_atoui.o \
			ft_atoull.o \
			ft_btree_balance.o \
			ft_btree_copy.o \
			ft_btree_create.o \
			ft_btree_del.o \
			ft_btree_delone.o \
			ft_btree_erase.o \
			ft_btree_erasef.o \
			ft_btree_fromlist.o \
			ft_btree_fromlistf.o \
			ft_btree_insert.o \
			ft_btree_insertf.o \
			ft_btree_left.o \
			ft_btree_leftrotate.o \
			ft_btree_new.o \
			ft_btree_right.o \
			ft_btree_rightrotate.o \
			ft_btree_search.o \
			ft_btree_searchf.o \
			ft_btree_size.o \
			ft_btree_swap.o \
			ft_btree_tolist.o \
			ft_bzero.o \
			ft_dtoa.o \
			ft_intlen.o \
			ft_isalnum.o \
			ft_isalpha.o \
			ft_isascii.o \
			ft_iscntrl.o \
			ft_isdigit.o \
			ft_islower.o \
			ft_isprint.o \
			ft_ispunct.o \
			ft_isspace.o \
			ft_isupper.o \
			ft_itoa.o \
			ft_itoa_cbase.o \
			ft_llonglen.o \
			ft_lltoa.o \
			ft_longlen.o \
			ft_lstadd.o \
			ft_lstatpos.o \
			ft_lstcopy.o \
			ft_lstcopyone.o \
			ft_lstcreate.o \
			ft_lstdel.o \
			ft_lstdelone.o \
			ft_lstend.o \
			ft_lstfind.o \
			ft_lstfindbysize.o \
			ft_lstiter.o \
			ft_lstmap.o \
			ft_lstnew.o \
			ft_lstpush.o \
			ft_lstpushfront.o \
			ft_lstsize.o \
			ft_ltoa.o \
			ft_memccpy.o \
			ft_memchr.o \
			ft_memcmp.o \
			ft_memcpy.o \
			ft_memdel.o \
			ft_memdup.o \
			ft_memalloc.o \
			ft_memmove.o \
			ft_memset.o \
			ft_pow.o \
			ft_putchar.o \
			ft_putnchar.o \
			ft_putchar_fd.o \
			ft_putnchar_fd.o \
			ft_putdouble.o \
			ft_putdouble_fd.o \
			ft_putendl.o \
			ft_putnendl.o \
			ft_putendl_fd.o \
			ft_putnendl_fd.o \
			ft_putnbr.o \
			ft_putnbr_base.o \
			ft_putnbr_base_fd.o \
			ft_putnbr_fd.o \
			ft_putptr.o \
			ft_putptr_fd.o \
			ft_putstr.o \
			ft_putnstr.o \
			ft_putstr_fd.o \
			ft_putnstr_fd.o \
			ft_putullong_base.o \
			ft_putullong_base_fd.o \
			ft_putunbr.o \
			ft_putunbr_fd.o \
			ft_revnstr.o \
			ft_revstr.o \
			ft_strafter.o \
			ft_strafterstr.o \
			ft_strbefore.o \
			ft_strbeforestr.o \
			ft_strcat.o \
			ft_strcatc.o \
			ft_strchr.o \
			ft_strchr_pos.o \
			ft_strclr.o \
			ft_strcmp.o \
			ft_strcount.o \
			ft_strcountstr.o \
			ft_strcpy.o \
			ft_strdel.o \
			ft_strdup.o \
			ft_strequ.o \
			ft_striter.o \
			ft_striteri.o \
			ft_strjoin.o \
			ft_strjoin_clr.o \
			ft_strjoinc.o \
			ft_strjoinc_clr.o \
			ft_strjoincs.o \
			ft_strjoincs_clr.o \
			ft_strlcat.o \
			ft_strlen.o \
			ft_sqrt.o \
			ft_strmap.o \
			ft_strmapi.o \
			ft_strmdup.o \
			ft_strncat.o \
			ft_strnchr.o \
			ft_strncmp.o \
			ft_strncpy.o \
			ft_strndup.o \
			ft_strnequ.o \
			ft_strnew.o \
			ft_strnrchr.o \
			ft_strnrstr.o \
			ft_strnstr.o \
			ft_strrchr.o \
			ft_strrep.o \
			ft_strrep_clr.o \
			ft_strrepstr.o \
			ft_strrepstr_clr.o \
			ft_strrstr.o \
			ft_strsplit.o \
			ft_strsplitstr.o \
			ft_strstr.o \
			ft_strstr_pos.o \
			ft_strsub.o \
			ft_strtrim.o \
			ft_swap.o \
			ft_swapptr.o \
			ft_tobase.o \
			ft_tolower.o \
			ft_toupper.o \
			ft_uintlen.o \
			ft_uitoa.o \
			ft_ullonglen.o \
			ft_ulltoa.o

SRCS_DIR=	.
ICLD_DIR=	includes
OBJS	=	$(patsubst %,$(SRCS_DIR)/%,$(_OBJS))
SRCS	=	$(OBJS:.o=.c)

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
	@$(CC) $(CFLAGS) -I $(ICLD_DIR) -c $(SRCS)
clean:
	@/bin/rm -f $(OBJS)
	@echo "clean: $(_SUCCESS)done$(_END)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "fclean: $(_SUCCESS)done$(_END)"

re: fclean all
