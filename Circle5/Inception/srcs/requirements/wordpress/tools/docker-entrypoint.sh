#!/bin/sh
cd ${WORDPRESS_PATH}
useradd -m wordpressmanager
chown -R wordpressmanager:wordpressmanager ${WORDPRESS_PATH}

if [ ! -f ${WORDPRESS_PATH}/index.php ]; then
	sudo -u wordpressmanager -i -- wp core download \
								--path=${WORDPRESS_PATH} \
								--locale=en_US
	sudo -u wordpressmanager -i -- wp config create \
								--path=${WORDPRESS_PATH} \
								--dbname=${MARIADB_DATABASE} \
								--dbuser=${MARIADB_USER} \
								--dbpass=${MARIADB_USER_PASSWORD} \
								--dbhost=mariadb
	sudo -u wordpressmanager -i -- wp core install \
								--path=${WORDPRESS_PATH} \
								--url=${WORDPRESS_URI} \
								--title=${WORDPRESS_TITLE} \
								--admin_user=${WORDPRESS_ADMIN_USER} \
								--admin_password=${WORDPRESS_ADMIN_PASSWORD} \
								--admin_email=${WORDPRESS_ADMIN_EMAIL} --skip-email
	sudo -u wordpressmanager -i -- wp user create \
								${WORDPRESS_USER_LOGIN} ${WORDPRESS_USER_EMAIL} \
								--path=${WORDPRESS_PATH} \
								--user_pass=${WORDPRESS_USER_PASSWORD} \
								--role=author
fi

mkdir -p /run/php/
chown -R www-data:www-data ${WORDPRESS_PATH}

exec php-fpm7.4 -F