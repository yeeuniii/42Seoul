#!/bin/sh
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

useradd -m wordpressmanager
mkdir /wordpress
chown -R wordpressmanager:wordpressmanager /wordpress
sudo -u wordpressmanager -i -- wp core download --locale=ko_KR --path=/wordpress
