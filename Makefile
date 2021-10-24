NAME = my_calculator
SRCS = main.c calculating.c parser.c utils.c
OBJS = ${SRCS:.c=.o}

${NAME} : ${OBJS}
		gcc -o ${NAME} ${OBJS}

all : ${NAME}

clean : 
	@rm -rf ${OBJS}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re