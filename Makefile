NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address

INCLUDES	=	includes/libft.h includes/ft_btree.h includes/ft_list.h includes/ft_mem.h \
				includes/ft_regex.h includes/ft_types.h includes/ft_event.h includes/ft_math.h \
				includes/ft_printf.h includes/ft_str.h includes/ft_str.h includes/get_next_line.h \
				includes/ft_io.h includes/ft_matrix.h includes/ft_printf_ext.h includes/ft_time.h \
				includes/handlers.h

_PRINTFS	=	ft_printf.c ft_vprintf.c \
				ft_printf_parser.c ft_printf_format.c ft_init_formats.c \
				handler_s.c handler_d.c handler_u.c handler_p.c handler_x.c \
				handler_o.c handler_c.c handler_f.c handler_b.c handler_y.c \
				handler_color.c perform_width.c proper_cast.c

_MATH_FS	=	ft_abs.c ft_pow.c ft_fmax.c ft_sqrt.c ft_max.c ft_hexcolor.c \
				ft_vec_new.c ft_vec_dump.c ft_vec_add.c ft_vec_mult.c ft_vec_get.c \
				ft_vec_sub.c ft_vec_div.c ft_vec_calc.c ft_vec_zero.c ft_vec_normalize.c

_TYPES_FS	=	ft_atod.c ft_atoi.c ft_atol.c ft_atoll.c ft_atoui.c ft_atoul.c ft_atoull.c \
				ft_dtoa.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_iscntrl.c ft_isdigit.c \
				ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c ft_itoa.c \
				ft_ltoa.c ft_lltoa.c ft_uitoa.c ft_ultoa.c ft_ulltoa.c ft_tobase.c ft_tolower.c \
				ft_toupper.c

_MATRIX_FS	=	ft_mat_mult.c ft_mat_new.c ft_mat_dump.c ft_mat_add.c ft_mat_get.c ft_mat_mult.c \
				ft_mat_sub.c ft_mat_div.c ft_mat_calc.c ft_mat_zero.c ft_mat_rotate.c ft_mat_transform.c \

_BTREE_FS	=	ft_btree_balance.c ft_btree_copy.c ft_btree_erase.c ft_btree_dump.c ft_btree_root.c \
				ft_btree_fromlist.c ft_btree_insert.c ft_btree_left.c ft_btree_move.c ft_btree_new.c \
				ft_btree_new.c ft_btree_right.c ft_btree_search.c ft_btree_size.c ft_btree_swap.c \
				ft_btree_tolist.c ft_btree_pos.c ft_btree_splay.c ft_btree_balancem.c ft_btree_count.c \
				ft_btree_erase_all.c ft_btree_iter.c ft_btree_getcreate.c ft_btree_getnew.c \
				ft_btree_iterv.c ft_btree_tolistv.c ft_btree_iter_d.c ft_btree_iterv_d.c \
				ft_btree_insert_p.c

_LIST_FS	=	ft_lstatpos.c ft_lstcopy.c ft_lstend.c ft_lstfind.c ft_lstiter.c ft_lstmap.c \
				ft_lstnew.c ft_lstpush.c ft_lstadd.c ft_lstsize.c ft_lstcount.c ft_lsterase.c \
				ft_lsterase_all.c ft_lstswap.c ft_lstsort.c ft_strsplit_lst.c ft_lstdel.c

_MEM_FS		=	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdup.c  ft_memalloc.c ft_memset.c \
				ft_memjoin.c ft_memstr.c ft_swap.c ft_swapptr.c

_IO_FS		=	ft_putchar.c ft_putdouble.c ft_putendl.c  ft_putnbr.c ft_getch.c ft_putptr.c \
				ft_putstr.c ft_putullong_base.c ft_putunbr.c get_next_line.c

_EVENT_FS	=	ft_event_new.c ft_event_add.c ft_event_trigger.c ft_event_clean.c ft_pevent_new.c \
				ft_pevent_add.c ft_pevent_remove.c ft_pevent_trigger.c ft_pevent_clean.c

_STR_FS		=	ft_strchrl.c ft_strdupli.c ft_revstr.c ft_strafter.c ft_strbefore.c ft_strcat.c \
				ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcount.c  ft_strcpy.c ft_strdup.c \
				ft_strequ.c ft_striter.c ft_strjoin.c ft_strjoinc.c ft_strjoincs.c ft_strlen.c \
				ft_strrepeat.c ft_strmap.c ft_strnew.c ft_strmatch.c ft_strnrchr.c ft_strnrstr.c \
				ft_strrep.c ft_strrepstr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
				ft_strpbrk.c ft_strbetween.c ft_strnpbrk.c ft_strtks.c ft_getmchi.c  ft_strforeach.c \
				ft_wcharlen.c ft_getwchar.c ft_wstrlen.c ft_getwstr.c ft_strmatch_opt.c ft_strbetweenps.c \
				ft_strchrln.c ft_strmatch_old.c ft_strdupl.c ft_strpbrkstr.c ft_strnpbrkstr.c \
				ft_strbetweenps_ext.c ft_strmatch.c ft_strntks.c ft_strpbrkstrp.c ft_strpbrkstrp_len.c \
				ft_strcatl.c ft_strjoinl.c ft_strpbrkstrpv_len.c ft_strnjoin.c ft_strinsert.c \

_TIME_FS	=	ft_timefnew.c

_REGEX_FS	=	ft_regex.c regex_exec.c get_matches.c regex_bracket.c regex_wildcard.c \
				regex_start.c regex_utils.c regex_function.c regex_function1.c \
				regex_function2.c regex_function3.c regex_group.c regex_load.c read_arguments.c

_LIBFTS		=	$(_MATH_FS) $(_TYPES_FS) $(_MATRIX_FS) $(_BTREE_FS) $(_LIST_FS) $(_MEM_FS) \
				$(_IO_FS) $(_EVENT_FS) $(_STR_FS) $(_TIME_FS) $(_REGEX_FS)

SRCD		=	srcs/
ICLD		=	includes/
ICLDS		=	$(addprefix $(ICLD),$(_ICLDS))
LIBFTS		=	$(addprefix $(SRCD),$(_LIBFTS))
_LIBFTO		=	$(_LIBFTS:.c=.o)
LIBFTO		=	$(LIBFTS:.c=.o)

PRINTFD		=	$(SRCD)ft_printf/
PRINTFS		=	$(addprefix $(PRINTFD),$(_PRINTFS))
_PRINTFO	=	$(_PRINTFS:.c=.o)
PRINTFO		=	$(PRINTFS:.c=.o)

SRCS		=	$(LIBFTS) $(PRINTFS)
_OBJS		=	$(_LIBFTO) $(_PRINTFO)
OBJD		=	.objs/
OBJS		=	$(LIBFTO) $(PRINTFO)
OBJB		=	$(addprefix $(OBJD),$(_OBJS))

# COLORS
CRED=\033[91m
CGREEN=\033[38;2;0;255;145m
CEND=\033[0m

all: $(NAME)

$(NAME): $(OBJB)
	@printf "\r\033[K$(CGREEN)Creating library$(CEND): $(NAME)\n"
	@ar rc $(NAME) $(OBJB)
	@ranlib $(NAME)
	@echo  "$(NAME): $(CGREEN)done$(CEND)"

$(OBJD)%.o: $(SRCD)%.c $(ICLDS) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(ICLD)

$(OBJD)%.o: $(PRINTFD)%.c $(ICLDS) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(ICLD)

clean:
	@rm -f $(OBJB)
	@echo "$(CRED)Cleaning$(CEND): $(NAME)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CRED)Full cleaning$(CEND): $(NAME)"

re: fclean all

.PHONY: all clean fclean re
