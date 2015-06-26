#ifndef MULTIWINDOW_H
#define MULTIWINDOW_H

#include <QWidget>
#include"tracker.h"
#include"issuelist.h"
class MultiWindow : public QWidget
{
    Q_OBJECT
    Tracker& controller;
    vector<IssueList*> vml;
public:
    explicit MultiWindow(Tracker& controller,QWidget *parent = 0);
    ~MultiWindow();

signals:

public slots:
};

#endif // MULTIWINDOW_H
