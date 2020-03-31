CREATE DATABASE IF NOT EXISTS ft_server_db;
CREATE USER "ft_server_db_user"@"localhost" IDENTIFIED BY "ft_server_db_user_pw";
GRANT ALL PRIVILEGES ON ft_server_db.* TO "ft_server_db_user"@"localhost";
