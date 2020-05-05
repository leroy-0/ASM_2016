##
## Makefile for makefile in /home/kleinh/Documents/minilibc
## 
## Made by Arthur Klein
## Login   <arthur.klein@epitech.eu>
## 
## Started on  Mon Mar  6 10:04:45 2017 Arthur Klein
## Last update Thu Mar 23 16:30:02 2017 leroy_0
##

NAME=   libasm.so

SRCS=   src/strlen.s \
	src/strcmp.s \
	src/strncmp.s \
	src/strcasecmp.s \
	src/strchr.s \
	src/memset.s \
	src/memmove.s \
	src/memcpy.s \
	src/strstr.s \
	src/rindex.s \
	src/strpbrk.s \
	src/strcspn.s \

OBJS=   $(SRCS:.s=.o)

ASM=    nasm

ASMF=   -f elf64

CFLAGS= -fpic -fno-builtin

AS = $(ASM) $(ASMF)

all:    $(NAME)

$(NAME): $(OBJS)
	ld -shared -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:     fclean all
