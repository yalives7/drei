NAME = minitalk
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f 
SERVER = server 
SERVER_SRC= server.c 
CLİENT = client
CLİENT_SRC = client.c
UTILS_SRC= utils.c  

all :$(SERVER)$(CLİENT)

$(NAME) : all

$(SERVER):
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)

$(CLİENT):
	$(CC) $(FLAGS) $(CLİENT_SRC) $(UTILS_SRC) -o $(CLİENT)

clean : 
	$(RM) $(SERVER) $(CLİENT)

fclean : 
	$(RM) $(SERVER) $(CLİENT)

re : fclean all

.PHONY = all clean fclean re 