TEMPLATE=app
TARGET=gta02-gps

CONFIG+=qtopia
DEFINES+=QTOPIA
CFLAGS+=-fpack-struct -Wall

# I18n info
STRING_LANGUAGE=en_US
LANGUAGES=en_US

# Package info
pkg [
    name=gta02-gps
    desc="GTA02 GPS helper program"
    license=GPLv2
    version=1.0
    maintainer="Radek Polak <psonek2@seznam.cz>"
]

SOURCES=qtopia_main.cpp

# Install rules
target [
    hint=sxe
    domain=untrusted
]