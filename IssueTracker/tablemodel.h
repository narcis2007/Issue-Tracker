#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QtWidgets>
#include"tracker.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
    Tracker& controller;
    User user;
    std::vector<Issue> vi;
private slots:
    void update();
public:
    TableModel(Tracker& controller,User user,QObject* parent=0);
    int rowCount(const QModelIndex&) const
    {
        return vi.size();
    }
    int columnCount(const QModelIndex&) const
    {
        return 2;
    }
    void setVectorData(std::vector<Issue> v2);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    ~TableModel();
};

#endif // TABLEMODEL_H
