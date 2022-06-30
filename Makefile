NAME = fractol
HEADER  = fractol.h
FLAGS = -Werror -Wall -Wextra
SRCS = test.c mandelbrot.c budhhabrot.c utils.c
RM = rm -rf
M_OBJS := $(SRCS:.c=.o)

$(NAME): $(M_OBJS) $(HEADER)
	gcc $(M_OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
%.o : %.c
	gcc $(FLAGS) -Imlx -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(M_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean clean all
.PHONY: all fclean clean re
