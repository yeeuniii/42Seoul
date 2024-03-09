NAME = Inception
DOCKER-COMPOSE = srcs/docker-compose.yml

all: $(NAME)

$(NAME): up

up: 
	docker-compose -f $(DOCKER-COMPOSE) up --build -d 

down:
	docker-compose -f $(DOCKER-COMPOSE) down -v

clean:
	docker-compose down -v 

fclean: clean
	docker system prune -f

re:
	make fclean
	make all

.PHONY : all up down clean fclean re
