FROM debian:13.2

RUN apt-get update && \
    apt-get install -y build-essential && \
    rm -rf /var/lib/apt/lists/*

COPY longerword.deb /tmp/longerword.deb

RUN dpkg -i /tmp/longerword.deb || apt-get install -f -y

WORKDIR /usr/local/bin

CMD ["longerword"]
