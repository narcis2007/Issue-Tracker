#ifndef ISSUE_H
#define ISSUE_H

#include<string>
#include<exception>
using namespace std;
class MyException : public std::exception
{
public:
    std::string what(){return "invalid text";}
private:
};

class Issue
{
    string text,rezolvitor,registrat_de;
    int status;
public:
    Issue(string text,string rezolvitor,string registrat_de,int status):text(text),rezolvitor(rezolvitor),registrat_de(registrat_de),status(status){}
    ~Issue();
    string get_text()const{return text;}
    string get_status_str()const{if(status==0)
                           return "open";
                           else
            return "closed";
                           }
    void set_rezolvitor(string n){
        rezolvitor=n;
    }

    void set_status(int s){
        status=s;}

        int get_status(){return status;}
        string get_rezolvitor(){return rezolvitor;}
        string get_registrat(){return registrat_de;}
};

#endif // ISSUE_H
