TEMPLATE=app
TARGET=gta02-gps

CONFIG+=qtopia
DEFINES+=QTOPIA
MKSPEC.CFLAGS+=-fpack-struct
MKSPEC.CXXFLAGS+=-fpack-struct

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

SOURCES=gta02-gps.c

# Install rules
target [
    hint=sxe
    domain=untrusted
]