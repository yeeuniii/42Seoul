CREATE DATABASE wordpress_db;
CREATE USER 'yeepark'@'%' IDENTIFED BY 'password';
GRANT ALL ON wordpress_db.* TO 'yeepark'@'%';
FLUSH PRIVILEGES;