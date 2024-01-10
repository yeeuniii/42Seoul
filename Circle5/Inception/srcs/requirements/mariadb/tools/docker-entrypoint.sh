service mariadb start
mysql -e "CREATE DATABASE wordpress_db;"
mysql -e "CREATE USER '${MARIADB_ID}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';"
mysql -e "GRANT ALL ON wordpress_db.* TO '${MARIADB_ID}'@'%';";
mysql -e "FLUSH PRIVILEGES;"
service mariadb stop
mysqld