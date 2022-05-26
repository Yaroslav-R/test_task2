TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
OBJECTS_DIR += ./src \
    ./src/text

SOURCES += ./src/*.c \
    ./src/text/*.c



HEADERS += \
    ./src/*.h

QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
