CC		=	gcc -arch x86_64
FLAGS	=	-Wall -Werror -Wextra

NASM	=	nasm -f macho64 

SRCS	=	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s	\
			ft_read.s	\
			ft_strdup.s	\
			ft_strdup.s

OBJS	=	$(SRCS:.s=.o)

RM		=	rm -f

NAME	=	libasm.a

.s.o:
		$(NASM) $< -o ${<:.s=.o}

$(NAME):	$(OBJS)
		ar rcs $@ $^


all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) a.out debug_file

re:			fclean all

debug:		all
			$(CC) $(FLAGS) main.c -L. -lasm

.PHONY:		all clean fclean re