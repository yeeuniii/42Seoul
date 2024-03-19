FROM debian:bullseye
RUN apt-get update && \
	apt-get upgrade && \
	apt-get -y install \
	php php-common php-mysql \
	php-gd php-xml php-mbstring \
	php-curl php-intl php-json \
	php7.4-fpm dumb-init \
	curl vim sudo

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY tools/ /scripts/
WORKDIR /scripts
RUN chmod +x install_wpcli.sh docker-entrypoint.sh && sh install_wpcli.sh

EXPOSE 9000

ENTRYPOINT ["/usr/bin/dumb-init", "--"]
CMD ["sh", "/scripts/docker-entrypoint.sh"]