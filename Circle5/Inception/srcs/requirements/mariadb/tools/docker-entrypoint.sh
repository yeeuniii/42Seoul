rc default
/etc/init.d/mariadb setup
rc-service mariadb start
mysql -u root < /home/create_wordpressdb_user.sql
#mysql -u root < /home/mysql_secure_installation.sql
#rc-service mariadb stop
#/usr/bin/mysqld_safe
