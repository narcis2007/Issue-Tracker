#include "issuelist.h"

IssueList::IssueList(Tracker& controller,User user,QWidget *parent):user(user),controller(controller), QWidget(parent)
{
    setWindowTitle((user.get_name() + ":"+ user.get_status_str()).c_str());

    layout=new QVBoxLayout();

    error=0;

    ioLayout=new QHBoxLayout();

    view=new QTableView();
    model=new TableModel(controller,user);
    view->setModel(model);

    selectionModel=view->selectionModel();
    connect(selectionModel,SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)),this,SLOT(selected(const QItemSelection&,const QItemSelection&)));

    layout->addWidget(view);

    graph=new Graph(controller);
    layout->addWidget(graph);text=new QLineEdit();
    ioLayout->addWidget(text);

    add=new QPushButton("add");
    if(user.get_status_str()=="programmer")
        add->setEnabled(false);
    connect(add,SIGNAL(clicked()),this,SLOT(add_issue()));
    ioLayout->addWidget(add);
    layout->addLayout(ioLayout);

    resolved=new QPushButton("resolved");
    if(user.get_status_str()=="tester")
        resolved->setEnabled(false);
    layout->addWidget(resolved);
    connect(resolved,SIGNAL(clicked()),this,SLOT(solve_issue()));

    setLayout(layout);
}

IssueList::~IssueList()
{

}

