include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD/input/\\\"

HEADERS +=     test_functions.h \
    test_save.h \
    test_stand.h \
    test_ind_func.h \
    ../app/src/common.h \
    ../app/src/text/*.h \
    tst_stdout.h

SOURCES +=     main.cpp \
    ../app/src/cb.c \
    ../app/src/functions.c \
    ../app/src/input_string.c \
    ../app/src/load.c \
    ../app/src/move.c \
    ../app/src/save.c \
    ../app/src/showlastnonspace.c \
    ../app/src/show.c \
    ../app/src/text/*.c




INCLUDEPATH += ../app

DISTFILES += \
    input/TestSTDOut_output.txt
