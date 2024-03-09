#!/bin/sh

service mariadb start
chmod +x /scripts/init-user.sql
envsubst < /scripts/init-user.sql > /tmp/init-user-filled.sql
cat /tmp/init-user-filled.sql | mysql -uroot -p"$MARIADB_PASSWORD"
sleep 1
mysqladmin -uroot -p"$MARIADB_PASSWORD" shutdown
mysqld