#include "multiwindow.h"

MultiWindow::MultiWindow(Tracker &controller,QWidget *parent) :controller(controller), QWidget(parent)
{
    for(auto i:controller.get_users()){
        vml.push_back(new IssueList(controller,i));
        vml[vml.size()-1]->show();
    }
}

MultiWindow::~MultiWindow()
{
    for(auto i:vml)
        delete i;
}

