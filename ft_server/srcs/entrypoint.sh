#!/bin/bash

service mysql start
service $(find /etc/init.d -name "php*" -printf "%f") start
service nginx start
