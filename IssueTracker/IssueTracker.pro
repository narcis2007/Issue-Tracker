#-------------------------------------------------
#
# Project created by QtCreator 2015-06-15T11:05:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IssueTracker
TEMPLATE = app


SOURCES += main.cpp\
        main.cpp \
    user.cpp \
    issue.cpp \
    trackerrepository.cpp \
    tracker.cpp \
    issuelist.cpp \
    multiwindow.cpp \
    tablemodel.cpp \
    graph.cpp \
    errorwindow.cpp

HEADERS  += main.h \
    user.h \
    issue.h \
    trackerrepository.h \
    tracker.h \
    issuelist.h \
    multiwindow.h \
    tablemodel.h \
    graph.h \
    errorwindow.h

DISTFILES += \
    ../build-IssueTracker-Desktop_Qt_5_4_1_MSVC2013_64bit-Debug/users.txt \
    ../build-IssueTracker-Desktop_Qt_5_4_1_MSVC2013_64bit-Debug/issues.txt
