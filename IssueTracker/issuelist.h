#ifndef ISSUELIST_H
#define ISSUELIST_H

#include <QtWidgets>
#include"tracker.h"
#include"tablemodel.h"
#include<future>
#include<iostream>
#include"graph.h"
#include"errorwindow.h"
class IssueList : public QWidget
{
    Q_OBJECT
    Tracker& controller;
    User user;
    QPushButton *add,*resolved;
    QLineEdit *text;
    QVBoxLayout *layout;
    QHBoxLayout *ioLayout;
    QTableView *view;
    TableModel *model;
    Graph *graph;
    QItemSelectionModel *selectionModel;
    ErrorWindow *error;
public:
    explicit IssueList(Tracker& controller,User user,QWidget *parent = 0);
    ~IssueList();

signals:
    void modified();
public slots:
    void selected(const QItemSelection& newSelection,const QItemSelection& oldSelection){
        QModelIndexList selection = view->selectionModel()->selectedIndexes();
        QModelIndex index = selection.at(0);
        QModelIndex idx =model->index(index.row(), 1);
        if(idx.data().toString().toStdString()=="open")
            resolved->setEnabled(true);
        else
            resolved->setEnabled(false);
        if(user.get_status_str()=="tester")
            resolved->setEnabled(false);
        if(newSelection.indexes().size()>0)
            view->selectRow(view->currentIndex().row());
    }

    void solve_issue(){
        QModelIndexList selection = view->selectionModel()->selectedIndexes();
        QModelIndex index = selection.at(0);
        QModelIndex idx =model->index(index.row(), 0);
        std::future<void> f=std::async(&Tracker::solve,&controller,model->data(idx).toString().toStdString(),user.get_name());
        f.get();

    }

    void add_issue(){
        try{
            std::future<void> f=std::async(&Tracker::add_issue,&controller,user.get_name(),text->text().toStdString(),0);
            f.get();
            //controller.add_message(user.get_id(),text->text().toStdString());
        }

        catch(MyException &e){
            if(error==0)
                error=new ErrorWindow(e.what());
            error->show();
        }
    }

};

#endif // ISSUELIST_H
