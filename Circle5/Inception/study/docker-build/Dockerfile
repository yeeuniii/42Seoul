FROM ubuntu:20.04
RUN apt update && apt install -y python3 
# RUN : build가 되는 시점에 실행되는 명령어 -> image에 반영
WORKDIR /var/www/html
# RUN echo "Hello, <strong>Docker</strong>" > index.html
# COPY ["index.html", "."]
CMD ["python3", "-u", "-m", "http.server"]
# CMD : container가 실행되는 시점에 실행되는 명령어 -> container에 반영