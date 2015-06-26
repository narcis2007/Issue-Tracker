#ifndef GRAPH_H
#define GRAPH_H

#include <QtWidgets>
#include<tracker.h>
#include<map>
class Graph : public QWidget
{
    Q_OBJECT
    std::vector<Issue> v;
    Tracker& controller;
    std::map<std::string,int> m;
    void paintEvent(QPaintEvent *event);
public:
    explicit Graph(Tracker& controller,QWidget *parent = 0);
    ~Graph();


signals:

public slots:
    void update_graph(){
        auto v=controller.get_issues();
        m["open"]=0;
        m["closed"]=0;
        for(auto i:v){
            m[i.get_status_str()]++;
        }
        update();
    }
};

#endif // GRAPH_H
