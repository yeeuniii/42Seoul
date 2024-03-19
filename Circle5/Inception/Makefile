NAME = Inception
DOCKER-COMPOSE = ./srcs/docker-compose.yml
VOLUME_PATH = /home/yeepark/data

all: $(NAME)

$(NAME): up

up: 
	sudo mkdir -p $(VOLUME_PATH)/mariadb_volume
	sudo mkdir -p $(VOLUME_PATH)/wordpress_volume
	docker-compose -f $(DOCKER-COMPOSE) up --build -d 

down:
	docker-compose -f $(DOCKER-COMPOSE) down

clean:
	docker-compose -f $(DOCKER-COMPOSE) down -v

fclean: clean
	rm -rf $(VOLUME_PATH)/
	docker system prune -f

re:
	make fclean
	make all

.PHONY : all up down clean fclean re
