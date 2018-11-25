NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address

SRCD		=	srcs/
INCLUDES_D	=	includes/
_INCLUDES	=	libft.h ft_btree.h ft_list.h ft_mem.h ft_regex.h ft_types.h ft_event.h \
				ft_math.h ft_printf.h ft_str.h ft_str.h get_next_line.h ft_io.h ft_matrix.h \
				ft_printf_ext.h ft_time.h handlers.h

_PRINTF_FS	=	ft_printf.c ft_vprintf.c \
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

_MATRIX_FS	=	ft_mat_new.c ft_mat_dump.c ft_mat_add.c ft_mat_get.c ft_mat_mult.c \
				ft_mat_sub.c ft_mat_div.c ft_mat_calc.c ft_mat_zero.c ft_mat_rotate.c ft_mat_transform.c

_BTREE_FS	=	ft_btree_balance.c ft_btree_copy.c ft_btree_erase.c ft_btree_dump.c ft_btree_root.c \
				ft_btree_fromlist.c ft_btree_insert.c ft_btree_left.c ft_btree_move.c ft_btree_new.c \
				ft_btree_right.c ft_btree_search.c ft_btree_size.c ft_btree_swap.c ft_btree_tolist.c \
				ft_btree_pos.c ft_btree_splay.c ft_btree_balancem.c ft_btree_count.c ft_btree_insert_p.c \
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
				ft_strrepeat.c ft_strmap.c ft_strnew.c ft_strnrchr.c ft_strnrstr.c \
				ft_strrep.c ft_strrepstr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
				ft_strpbrk.c ft_strbetween.c ft_strnpbrk.c ft_strtks.c ft_getmchi.c  ft_strforeach.c \
				ft_wcharlen.c ft_getwchar.c ft_wstrlen.c ft_getwstr.c ft_strmatch_opt.c ft_strbetweenps.c \
				ft_strchrln.c ft_strmatch_old.c ft_strdupl.c ft_strpbrkstr.c ft_strnpbrkstr.c \
				ft_strbetweenps_ext.c ft_strmatch.c ft_strntks.c ft_strpbrkstrp.c ft_strpbrkstrp_len.c \
				ft_strcatl.c ft_strjoinl.c ft_strpbrkstrpv_len.c ft_strnjoin.c ft_strinsert.c

_TIME_FS	=	ft_timefnew.c

_REGEX_FS	=	ft_regex.c regex_exec.c get_matches.c regex_bracket.c regex_wildcard.c \
				regex_start.c regex_utils.c regex_function.c regex_function1.c \
				regex_function2.c regex_function3.c regex_group.c regex_load.c read_arguments.c \
				print_matches.c

_LIBFTS		=	$(_MATH_FS) $(_TYPES_FS) $(_MATRIX_FS) $(_BTREE_FS) $(_LIST_FS) $(_MEM_FS) \
				$(_IO_FS) $(_EVENT_FS) $(_STR_FS) $(_TIME_FS) $(_REGEX_FS)

INCLUDES	=	$(addprefix $(INCLUDES_D),$(_INCLUDES))

PRINTF_FS	=	$(addprefix $(SRCD)ft_printf/,$(_PRINTF_FS))
PRINTF_O	=	$(_PRINTF_FS:.c=.o)
MATH_FS		=	$(addprefix $(SRCD)ft_math/,$(_MATH_FS))
MATH_O		=	$(_MATH_FS:.c=.o)
TYPES_FS	=	$(addprefix $(SRCD)ft_types/,$(_TYPES_FS))
TYPES_O		=	$(_TYPES_FS:.c=.o)
MATRIX_FS	=	$(addprefix $(SRCD)ft_matrix/,$(_MATRIX_FS))
MATRIX_O	=	$(_MATRIX_FS:.c=.o)
BTREE_FS	=	$(addprefix $(SRCD)ft_btree/,$(_BTREE_FS))
BTREE_O		=	$(_BTREE_FS:.c=.o)
LIST_FS		=	$(addprefix $(SRCD)ft_list/,$(_LIST_FS))
LIST_O		=	$(_LIST_FS:.c=.o)
MEM_FS		=	$(addprefix $(SRCD)ft_mem/,$(_MEM_FS))
MEM_O		=	$(_MEM_FS:.c=.o)
IO_FS		=	$(addprefix $(SRCD)ft_io/,$(_IO_FS))
IO_O		=	$(_IO_FS:.c=.o)
EVENT_FS	=	$(addprefix $(SRCD)ft_event/,$(_EVENT_FS))
EVENT_O		=	$(_EVENT_FS:.c=.o)
STR_FS		=	$(addprefix $(SRCD)ft_str/,$(_STR_FS))
STR_O		=	$(_STR_FS:.c=.o)
TIME_FS		=	$(addprefix $(SRCD)ft_time/,$(_TIME_FS))
TIME_O		=	$(_TIME_FS:.c=.o)
REGEX_FS	=	$(addprefix $(SRCD)ft_regex/,$(_REGEX_FS))
REGEX_O		=	$(_REGEX_FS:.c=.o)

SRCS		=	$(PRINTF_FS) $(MATH_FS) $(TYPES_FS) $(MATRIX_FS) $(BTREE_FS) $(LIST_FS) $(MEM_FS) \
				$(IO_FS) $(EVENT_FS) $(STR_FS) $(TIME_FS) $(REGEX_FS)
OBJS		=	$(PRINTF_O) $(MATH_O) $(TYPES_O) $(MATRIX_O) $(BTREE_O) $(LIST_O) $(MEM_O) \
				$(IO_O) $(EVENT_O) $(STR_O) $(TIME_O) $(REGEX_O)
OBJD		=	.objs/
OBJB		=	$(addprefix $(OBJD),$(OBJS))

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

$(OBJD)%.o: $(SRCD)ft_printf/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_math/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_types/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_matrix/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_btree/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_list/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_mem/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_io/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_event/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_str/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_time/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

$(OBJD)%.o: $(SRCD)ft_regex/%.c $(INCLUDES) Makefile
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $<"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_D)

clean:
	@rm -f $(OBJB)
	@echo "$(CRED)Cleaning$(CEND): $(NAME)"

fclean:
	@make clean
	@rm -f $(NAME)
	@echo "$(CRED)Full cleaning$(CEND): $(NAME)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
