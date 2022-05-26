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
    ../app/*.h \
    tst_stdout.h

SOURCES +=     main.cpp \
    ../app/append_line.c \
    ../app/cb.c \
    ../app/create_text.c \
    ../app/functions.c \
    ../app/input_string.c \
    ../app/load.c \
    ../app/move.c \
    ../app/process_forward.c \ 
    ../app/remove_all.c \
    ../app/save.c \
    ../app/show.c \
    ../app/showlastnonspace.c



INCLUDEPATH += ../app

DISTFILES += \
    input/TestSTDOut_output.txt
