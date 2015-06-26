#ifndef TRACKER_H
#define TRACKER_H

#include <QObject>
#include<trackerrepository.h>
class Tracker : public QObject
{
    Q_OBJECT
    TrackerRepository& repo;
public:
    explicit Tracker(TrackerRepository& repo,QObject *parent = 0):repo(repo){}
    ~Tracker();
    vector<User> get_users(){return repo.get_users();}
    void add_issue(string name,string text,int status){
        int ok=0;
        auto v=repo.get_issues();
        for_each(v.begin(),v.end(),[&](Issue i)
        {
            if(i.get_text()==text)
                    ok=1;
         }
                 );
        if(text==""||ok==1)
            throw MyException();
        repo.add_issue(name,text,status);
        emit modified();
    }
    void solve(string text,string name){
        repo.solve(text,name);
        emit modified();
    }

    vector<Issue> get_issues(){return repo.get_issues();}


signals:
    void modified();

public slots:
};

#endif // TRACKER_H
