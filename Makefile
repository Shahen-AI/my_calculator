NAME = my_calculator
SRCS = main.c calculating.c parser.c utils.c
OBJS = ${SRCS:.c=.o}

${NAME} : ${OBJS}
		gcc -o ${NAME} ${OBJS}

all : ${NAME}

clean : rm -rf ${NAME}

re : clean all

.PHONY : all clean re