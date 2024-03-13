FROM debian:bullseye
RUN apt-get update && \
	apt-get upgrade && \
	apt-get -y install \
	php php-common php-mysql \
	php-gd php-xml php-mbstring \
	php-curl php-intl php-json \
	curl vim sudo

COPY tools/ /scripts/
WORKDIR /scripts
RUN chmod +x run_wpcli.sh && \
	sh run_wpcli.sh

EXPOSE 9000
