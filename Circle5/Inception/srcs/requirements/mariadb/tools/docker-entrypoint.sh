#!/bin/sh
mysqld_safe &
until mysqladmin ping -hlocalhost -uroot > /dev/null 2>&1; do
    echo "Waiting for mysql to run"
    sleep 1
done
envsubst < /scripts/init-user.sql > /scripts/init-user-filled.sql
mysql -uroot -p${MARIADB_ROOT_PASSWORD} < /scripts/init-user-filled.sql
mysqladmin -uroot -p${MARIADB_ROOT_PASSWORD} shutdown
exec mysqld_safe --user=mysql