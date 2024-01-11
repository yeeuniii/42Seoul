FROM alpine:3.7

RUN mkdir /app
RUN apk update && apk add dumb-init
WORKDIR /app
COPY . .
RUN chmod +x /app/sleep.sh

ENTRYPOINT ["/usr/bin/dumb-init","--","/app/sleep.sh"]
