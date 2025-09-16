CC = cc

CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
LIBFTPRINTF = printf/libftprintf.a

SRC_SERVER = server.c utils.c
SRC_CLIENT = client.c utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)


all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT): $(OBJ_CLIENT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFTPRINTF):
	make -C printf

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	make -C printf clean

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(LIBFTPRINTF)

re: fclean all

.PHONY: all clean fclean re
