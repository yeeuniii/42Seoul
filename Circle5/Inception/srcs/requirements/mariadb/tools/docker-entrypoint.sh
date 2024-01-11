#export MARIADB_ID=yeepark
#export MARIADB_PASSWORD=password
service mariadb start
mysql -e "CREATE DATABASE wordpress_db;"
mysql -e "CREATE USER '${MARIADB_ID}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';"
mysql -e "GRANT ALL ON wordpress_db.* TO '${MARIADB_ID}'@'%';";
mysql -e "SET PASSWORD FOR 'root'@'localhost' = PASSWORD('${MARIADB_PASSWORD}');"
mysql -e "FLUSH PRIVILEGES;"
mysqladmin -uroot -ppassword shutdown
#service mariadb stop
mysqld
