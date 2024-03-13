#!bin/sh
sudo -u wordpressmanager -i -- wp config create --path=${WORDPRESS_PATH} \
										--dbname=${MARIADB_DATABASE} \
										--dbuser=${MARIADB_USER} \
										--dbpass=${MARIADB_USER_PASSWORD} \
										--dbhost=mariadb
