FROM debian:bullseye
RUN apt-get update && \
    apt-get upgrade && \
    apt-get -y install mariadb-server dumb-init gettext

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY tools/ /scripts/

RUN chmod +x /scripts/docker-entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["/scripts/docker-entrypoint.sh"]
