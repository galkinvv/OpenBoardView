# Debian10 provides g++ 8.3.0, SDL2 2.0.9 and produces binaries compatible with Ubuntu 20.04+, RHEL-like 8.+
FROM debian:10.13-slim

ARG DEBIAN_FRONTEND=noninteractive DEBCONF_NOWARNINGS=yes
RUN apt-get update && \
    apt-get -y install --no-install-recommends ca-certificates g++ make cmake rpm libsdl2-dev libgtk-3-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# mingw-w64-i686-posix >=10.3.0 is required to avoid crashing in filesystem::rename. Get it from ppa to avoid updating system libc
RUN echo 'deb [check-valid-until=no] http://snapshot.debian.org/archive/debian/20210101T000000Z unstable main' > /etc/apt/sources.list.d/pre-bullseye.list && \
    echo 'deb [trusted=yes] https://ppa.launchpadcontent.net/cybermax-dexter/mingw-w64-backport/ubuntu focal main' > /etc/apt/sources.list.d/mingw-w64-backport.list && \
    apt-get update && \
    apt-get -y install --no-install-recommends g++-mingw-w64-i686-posix && \
    rm /etc/apt/sources.list.d/*.list && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Windows build links SDL2 statically, so use latest version.
ENV MINGW_SDL2_VER=2.32.0
ADD https://www.libsdl.org/release/SDL2-devel-${MINGW_SDL2_VER}-mingw.tar.gz /usr/src
