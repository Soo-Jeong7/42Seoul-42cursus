docker rm ft_server
#docker rmi $(docker images | grep none | awk '{print $3}')
docker build .
docker ps -a
docker run -it -d -p 80:80 --name ft_server $(docker images | grep none | head -n 1 | awk '{print $3}')
