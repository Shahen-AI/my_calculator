NAME = my_calculator
SRCS = ${shell find "." -name "*.c"}
OBJS = ${SRCS:.c=.o}
MYSQL_FLAG = -lmysqlclient

${NAME} : ${OBJS}
		gcc ${MYSQL_FLAG} -o ${NAME} ${OBJS}

all : ${NAME}

clean : 
	@rm -rf ${OBJS}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re