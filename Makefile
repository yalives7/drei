NAME = minitalk
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f 
SERVER = server_bonus 
SERVER_SRC= server_bonus.c 
CLİENT = client_bonus
CLİENT_SRC = client_bonus.c
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