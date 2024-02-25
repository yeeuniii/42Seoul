#!/bin/sh

service mariadb start

chmod +x /scripts/init-user.sql

# 환경 변수 값을 포함한 새 SQL 파일 생성
envsubst < /scripts/init-user.sql > /tmp/init-user-filled.sql

cat /tmp/init-user-filled.sql | mysql -uroot -p"$MARIADB_PASSWORD"
# mysql -uroot -p"$MARIADB_PASSWORD" < /tmp/init-db-filled.sql

sleep 1
mysqladmin -uroot -p"$MARIADB_PASSWORD" shutdown
mysqld