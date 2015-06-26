#include "tablemodel.h"
#include<iostream>
TableModel::TableModel(Tracker& controller,User user, QObject *parent):user(user),controller(controller),QAbstractTableModel(parent){
    vi=controller.get_issues();
    /*
    connect(&game,SIGNAL(guessed()),this,SLOT(update()));
    connect(&game,SIGNAL(not_guessed()),this,SLOT(update()));*/
    connect(&controller,SIGNAL(modified()),this,SLOT(update()));

}
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("text");
            case 1:
                return QString("state");
            }
        }
    }
    return QVariant();
}
QVariant TableModel::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole) {
        if(index.column()==0)
           return QString(vi[index.row()].get_text().c_str());
        if(index.column()==1)
            return QString(vi[index.row()].get_status_str().c_str());
    }
    return QVariant();
}
void TableModel::setVectorData(std::vector<Issue> v2){
    vi.clear();


    beginResetModel();
    endResetModel();
}

void TableModel::update(){
   // vi.clear();
    vi=controller.get_issues();

    //vi=controller.get_messages_user(user.get_id());
    beginResetModel();
    endResetModel();
}
TableModel::~TableModel()
{
    ;
}

