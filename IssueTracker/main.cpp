#include<QtWidgets>
#include"trackerrepository.h"
#include"tracker.h"
#include"issuelist.h"
#include"multiwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrackerRepository repo("users.txt","issues.txt");
    Tracker controller(repo);
    //MultiWindow mw(controller);
    MultiWindow mw(controller);
    return a.exec();
}

