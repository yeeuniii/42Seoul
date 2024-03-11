FROM debian:bullseye
RUN apt-get update && \
    apt-get upgrade && \
    apt-get -y install nginx openssl

COPY conf/default.conf /etc/nginx/conf.d
COPY tools/ /scripts

RUN chmod +x /scripts/docker-entrypoint.sh

EXPOSE 443

# ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["/scripts/docker-entrypoint.sh"]
