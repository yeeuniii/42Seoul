FROM debian:bullseye
RUN apt-get update && \
    apt-get upgrade && \
    apt-get -y install mariadb-server dumb-init

# RUN apt-get install dumb-init
# RUN mkdir /run/mysqld && chown mysql:mysql /run/mysqld

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY tools .

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
#ENTRYPOINT ["/usr/bin/dumb-init", "--", "sh", "docker-entrypoint.sh"]
#CMD ["/bin/bash"]
CMD ["sh", "docker-entrypoint.sh"]
