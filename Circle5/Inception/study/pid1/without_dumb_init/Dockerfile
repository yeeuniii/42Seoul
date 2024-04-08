FROM alpine:3.7

RUN mkdir /app
WORKDIR /app
COPY . .
RUN chmod +x /app/sleep.sh

ENTRYPOINT ["/app/sleep.sh"]
