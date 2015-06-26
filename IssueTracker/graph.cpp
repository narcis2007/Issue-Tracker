#include "graph.h"

Graph::Graph(Tracker& controller,QWidget *parent) :controller(controller), QWidget(parent)
{
    v=controller.get_issues();
    setMinimumSize(300,300);
    connect(&controller,SIGNAL(modified()),this,SLOT(update_graph()));
    update_graph();
}
void Graph::paintEvent(QPaintEvent *event){
       QPainter painter(this);
       int w=width();
       int h=height();
       int baselineY=h-100;
       int barWidth=100;
       int k=0;
       painter.drawLine(0,baselineY,w,baselineY);
       for (auto i:m) {
           int barX = k * barWidth + barWidth / 2;
           painter.drawRect(barX, baselineY - i.second*20 , barWidth/2 , i.second*20);
           painter.drawText(barX, baselineY + 20, QString(i.first.c_str()));
           painter.drawText(barX, baselineY + 40, QString::number(i.second));
           k++;
        }
}
Graph::~Graph()
{

}

