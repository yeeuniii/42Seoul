#!/bin/sh
mkdir /etc/nginx/ssl
openssl req -x509 \
    -nodes \
	-days 365 \
	-newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=KO/ST=Seoul/L=Gaepo-dong/O=42Seoul/CN=${DOMAIN_NAME}"
exec nginx -g "daemon off;"