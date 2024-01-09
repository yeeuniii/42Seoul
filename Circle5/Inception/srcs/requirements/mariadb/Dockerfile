FROM alpine:3.18.5
RUN apk update && \
    apk upgrade && \
    apk add openrc --no-cache mariadb 

COPY conf/mariadb-server.cnf /etc/my.cnf.d
COPY tools/create_wordpress_user.sql /home
COPY tools/docker-entrypoint.sh /home
ENTRYPOINT ["sh", "/home/docker-entrypoint.sh"]
