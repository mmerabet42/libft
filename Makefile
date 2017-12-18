NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

_PRINTFS	=	ft_printf.c ft_vprintf.c \
				ft_printf_parser.c ft_printf_format.c ft_init_formats.c \
				handler_s.c handler_d.c handler_u.c handler_p.c handler_x.c \
				handler_o.c handler_c.c handler_f.c handler_b.c handler_y.c \
				handler_color.c \
				perform_width.c proper_cast.c \

_LIBFTS	=	ft_abs.c ft_pow.c ft_sqrt.c \
			ft_atod.c ft_atoi.c ft_atoi_base.c ft_atol.c ft_atoll.c ft_atoui.c \
			ft_atoul.c ft_atoull.c ft_dtoa.c \
			ft_btree_balance.c ft_btree_copy.c ft_btree_create.c \
			ft_btree_del.c ft_btree_delone.c ft_btree_erase.c ft_btree_erasef.c\
			ft_btree_fromlist.c ft_btree_fromlistf.c ft_btree_insert.c \
			ft_btree_insertf.c ft_btree_left.c ft_btree_leftrotate.c \
			ft_btree_new.c ft_btree_right.c ft_btree_rightrotate.c \
			ft_btree_search.c ft_btree_searchf.c ft_btree_size.c \
			ft_btree_swap.c ft_btree_tolist.c \
			ft_intlen.c ft_longlen.c ft_llonglen.c ft_uintlen.c \
			ft_ulonglen.c ft_ullonglen.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_iscntrl.c ft_isdigit.c \
			ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c \
			ft_itoa.c ft_ltoa.c ft_lltoa.c ft_uitoa.c ft_ultoa.c ft_ulltoa.c \
			ft_itoa_cbase.c ft_uitoa_cbase.c ft_ltoa_cbase.c ft_lltoa_cbase.c \
			ft_ultoa_cbase.c ft_ulltoa_cbase.c \
			ft_lstadd.c ft_lstatpos.c ft_lstcopy.c ft_lstcopyone.c ft_lstdel.c \
			ft_lstdelone.c ft_lstend.c ft_lstfind.c ft_lstiter.c ft_lstmap.c \
			ft_lstnew.c ft_lstpush.c ft_lstpushfront.c ft_lstsize.c \
			ft_lsterase.c \
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
			ft_memdup.c ft_memalloc.c ft_memmove.c ft_memset.c ft_bzero.c \
			ft_putchar.c ft_putnchar.c ft_putchar_fd.c ft_putnchar_fd.c \
			ft_putdouble.c ft_putdouble_fd.c ft_putendl.c ft_putnendl.c \
			ft_putendl_fd.c ft_putnendl_fd.c ft_putnbr.c ft_putnbr_base.c \
			ft_putnbr_base_fd.c ft_putnbr_fd.c ft_putptr.c ft_putptr_fd.c \
			ft_putstr.c ft_putnstr.c ft_putstr_fd.c ft_putnstr_fd.c \
			ft_putullong_base.c ft_putullong_base_fd.c \
			ft_putunbr.c ft_putunbr_fd.c \
			ft_revnstr.c ft_revstr.c ft_memjoin.c \
			ft_strafter.c ft_strafterstr.c ft_strbefore.c ft_strbeforestr.c \
			ft_strcat.c ft_strcatc.c ft_strchr.c ft_strchr_pos.c ft_strclr.c \
			ft_strcmp.c ft_strcount.c ft_strcountstr.c ft_strcpy.c ft_strdel.c \
			ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
			ft_strjoin_clr.c ft_strjoinc.c ft_strjoinc_clr.c ft_strjoincs.c \
			ft_strjoincs_clr.c ft_strlcat.c ft_strlen.c \
			ft_strmap.c ft_strmapi.c ft_strmdup.c ft_strncat.c ft_strnchr.c \
			ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c \
			ft_strnrchr.c ft_strnrstr.c ft_strnstr.c ft_strrchr.c ft_strrep.c \
			ft_strrepc.c ft_strrep_clr.c ft_strrepstr.c ft_strrepstr_clr.c \
			ft_strrstr.c ft_strsplit.c ft_strsplitstr.c ft_strstr.c \
			ft_strstr_pos.c ft_strsub.c ft_strtrim.c ft_swap.c ft_strforeach.c \
			ft_swapptr.c ft_tobase.c ft_tolower.c ft_toupper.c \
			ft_wcharlen.c ft_getwchar.c ft_wstrlen.c ft_wstrnlen.c \
			ft_getwstr.c ft_getnwstr.c \
			get_next_line.c \

SRCD		=	srcs
ICLD		=	includes
LIBFTS		=	$(patsubst %,$(SRCD)/%,$(_LIBFTS))
_LIBFTO		=	$(_LIBFTS:.c=.o)
LIBFTO		=	$(LIBFTS:.c=.o)

PRINTFD		=	$(SRCD)/ft_printf
PRINTFS		=	$(patsubst %,$(PRINTFD)/%,$(_PRINTFS))
_PRINTFO	=	$(_PRINTFS:.c=.o)
PRINTFO		=	$(PRINTFS:.c=.o)

SRCS		=	$(LIBFTS) $(PRINTFS)
_OBJS		=	$(_LIBFTO) $(_PRINTFO)
OBJD		=	objs
OBJS		=	$(patsubst %,$(OBJD)/%,$(_OBJS))

# COLORS
_GREY=\x1b[30m
_RED=\x1b[38;5;220m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m
_SUCCESS=$(_RED)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@echo "$(_RED)Compiling$(_END) $(NAME) $(_RED)...$(_END)"
	@$(CC) -c $(CFLAGS) $(SRCS) -I$(ICLD)
	@mv $(_OBJS) $(OBJD)/
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo  "$(NAME) : $(_SUCCESS)done$(_END)"

clean:
	@echo "$(_RED)Cleaning$(_END) : object files"
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo "$(_RED)Cleaning$(_END) : $(NAME)"
	@/bin/rm -f $(NAME)

re: fclean all
