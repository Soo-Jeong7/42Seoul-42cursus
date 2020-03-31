FROM debian:buster

# set apt repo
COPY ./srcs/kor-sources.list /etc/apt/sources.list

RUN apt-get update &&\
	apt-get install nginx -y &&\
	apt-get install php-fpm php-mysql -y &&\
	apt-get install default-mysql-server -y

COPY ./srcs/db.sql /root

RUN service mysql start &&\
	mysql -u root -p < /root/db.sql

COPY ./srcs/phpMyAdmin.tar.gz /root

RUN tar -xvf /root/phpMyAdmin.tar.gz &&\
	mkdir /var/www/html/phpmyadmin &&\
	mv phpMyAdmin*/* /var/www/html/phpmyadmin/ &&\
	rm -rf phpMyAdmin* /root/phpMyAdmin

COPY ./srcs/nginx-conf /etc/nginx/sites-available/default

COPY ./srcs/wordpress.tar.gz /root

RUN tar -xvf /root/wordpress.tar.gz &&\
	mkdir /var/www/html/wordpress &&\
	mv wordpress*/* /var/www/html/wordpress/

COPY ./srcs/wp-config.php /var/www/html/wordpress/

COPY ./srcs/entrypoint.sh /root

ENTRYPOINT ["sh", "/root/entrypoint.sh"]
