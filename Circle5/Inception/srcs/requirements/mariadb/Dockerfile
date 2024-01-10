FROM debian:bullseye
RUN apt-get update && \
    apt-get upgrade && \
    apt-get -y install mariadb-server vim dumb-init

# RUN apt-get install dumb-init

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY tools/ .

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
#CMD ["/bin/bash"]
CMD ["sh", "docker-entrypoint.sh"]
