NAME	=	libft.a
CC		=	gcc
CCFLAGS	=	-Wall -Werror -Wextra

_OBJS	=	ft_abs.o \
			ft_atoi.o \
			ft_atoi_base.o \
			ft_atol.o \
			ft_atoll.o \
			ft_atoui.o \
			ft_btree_del.o \
			ft_btree_delone.o \
			ft_btree_fromlist.o \
			ft_btree_fromlistf.o \
			ft_btree_insert.o \
			ft_btree_insertf.o \
			ft_btree_left.o \
			ft_btree_new.o \
			ft_btree_right.o \
			ft_btree_search.o \
			ft_btree_searchf.o \
			ft_btree_size.o \
			ft_btree_tolist.o \
			ft_bzero.o \
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
			ft_itoa_base.o \
			ft_llonglen.o \
			ft_lltoa.o \
			ft_longlen.o \
			ft_lstadd.o \
			ft_lstat.o \
			ft_lstcopy.o \
			ft_lstcopyone.o \
			ft_lstdel.o \
			ft_lstdelone.o \
			ft_lstend.o \
			ft_lstfind.o \
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
			ft_memmalloc.o \
			ft_memmove.o \
			ft_memset.o \
			ft_pow.o \
			ft_putchar.o \
			ft_putchar_fd.o \
			ft_putendl.o \
			ft_putendl_fd.o \
			ft_putnbr.o \
			ft_putnbr_base.o \
			ft_putnbr_base_fd.o \
			ft_putnbr_fd.o \
			ft_putptr.o \
			ft_putptr_fd.o \
			ft_putstr.o \
			ft_putstr_fd.o \
			ft_putullong_base.o \
			ft_putullong_base_fd.o \
			ft_putunbr.o \
			ft_putunbr_fd.o \
			ft_realloc_fail.o \
			ft_revnstr.o \
			ft_revstr.o \
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
			ft_strjoincs.o \
			ft_strlcat.o \
			ft_strlen.o \
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
			ft_tobase.o \
			ft_tolower.o \
			ft_toupper.o \
			ft_uintlen.o \
			ft_uitoa.o

SRCS	=	.
OBJS	=	$(patsubst %,$(SRCS)/%,$(_OBJS))

.PHONY:	all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

$(SRCS)%.o: %.c \
	&(CC) $(CCFLAGS) -c $@ $^

re: fclean all

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
