FROM debian:buster

# set apt repo
COPY ./srcs/kor-sources.list /etc/apt/sources.list

RUN apt-get update &&\
	apt-get install nginx -y &&\
	apt-get install php-fpm php-mysql -y &&\
	apt-get install default-mysql-server -y

COPY ./srcs/phpMyAdmin.tar.gz /root

RUN tar -xvf /root/phpMyAdmin.tar.gz &&\
	mkdir /var/www/html/phpmyadmin &&\
	mv phpMyAdmin*/* /var/www/html/phpmyadmin/ &&\
	rm -rf phpMyAdmin* /root/phpMyAdmin

COPY ./srcs/nginx-conf /etc/nginx/sites-available/default

# ENTRYPOINT ["", ""]
