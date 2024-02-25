DOCKER-COMPOSE = srcs/docker-compose.yml

all:
	make up
up:
	docker-compose -f $(DOCKER-COMPOSE) up --build -d 

down:
	docker-compose -f $(DOCKER-COMPOSE) down -v
