#ifndef TRACKERREPOSITORY_H
#define TRACKERREPOSITORY_H
#include<issue.h>
#include<user.h>
#include<vector>
#include<fstream>
#include<algorithm>
#include<iostream>
#include<future>
class TrackerRepository
{
    string user_file,issue_file;
    vector<User> vu;
    vector<Issue> vi;
public:
    TrackerRepository(string user_file,string issue_file):user_file(user_file),issue_file(issue_file){
        std::future<void> f=std::async(&TrackerRepository::load_users,this);
        f.get();
        std::future<void> f2=std::async(&TrackerRepository::load_issues,this);
        f2.get();
       // load_users();
        //load_issues();
    }
    ~TrackerRepository();

    void load_users(){
        ifstream f(user_file.c_str());
        int status;
        string name;
        while(f>>name>>status)
            vu.push_back(User(name,status));
    }
    void add_issue(string name,string text,int status){
        Issue i(text,"none",name,status);
        vi.push_back(i);
        ofstream g(issue_file.c_str(),ostream::app);
        g<<text<<" "<<"none"<<" "<<name<<" "<<status<<endl;
    }
    void save_issues(){
        ofstream g(issue_file.c_str());
        for(auto i:vi){
            g<<i.get_text()<<" "<<i.get_rezolvitor()<<" "<<i.get_registrat()<<" "<<i.get_status()<<endl;
        }
    }
    void load_issues(){
        ifstream f(issue_file.c_str());
        string name,name_solved;
        string text;
        int status;
        while(f>>text>>name_solved>>name>>status)
            vi.push_back(Issue(text,name_solved,name,status));
    }
    void solve(string text,string name){
        vector<Issue> v2;
        for_each(vi.begin(),vi.end(),[&](Issue i)
        {
            if(i.get_text()==text){
                i.set_status(1);
                i.set_rezolvitor(name);

            }
            v2.push_back(i);
         }
                 );
        vi=v2;
        std::future<void> f=std::async(&TrackerRepository::save_issues,this);
        f.get();
        //save_issues();

    }


    vector<User> get_users(){return vu;}
    vector<Issue> get_issues(){return vi;}
};

#endif // TRACKERREPOSITORY_H
