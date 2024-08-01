# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 13:04:15 by dukim             #+#    #+#              #
#    Updated: 2024/03/07 14:07:16 by dukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	push_swap
LIBFT		=	libft
LIBFT_LIB	=	libft.a
ST_SRCS		=	src/stack/ft_stack_push.c src/stack/ft_stack_reverse.c\
				src/stack/ft_stack_rotate.c src/stack/ft_stack_swap.c
SRCS		= 	src/mandatory/main.c src/mandatory/optimize1.c src/mandatory/optimize2.c\
				src/mandatory/push_swap.c src/mandatory/parse_arg.c src/mandatory/free_handler.c\
				src/mandatory/utils1.c src/mandatory/utils2.c src/mandatory/utils3.c
ST_OBJS		:=	$(ST_SRCS:%.c=%.o)
OBJS 		:=	$(SRCS:%.c=%.o)

.PHONY:		all bonus clean fclean re

all		:	$(NAME)

$(NAME)	:	$(LIBFT_LIB) $(ST_OBJS) $(OBJS)
		$(CC) $(CFLAGS) $(ST_OBJS) $(OBJS) $(LIBFT)/$(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB)	:
	@make bonus -C $(LIBFT)/

$(ST_OBJS)	:	$(ST_SRCS)
	$(CC) $(CFLAGS) -c $(ST_SRCS)
	@mv *.o src/stack/

$(OBJS)	:	$(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	@mv *.o src/mandatory/

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJS) $(ST_OBJS)

fclean:		clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re:			fclean all