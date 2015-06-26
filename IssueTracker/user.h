#ifndef USER_H
#define USER_H
#include<string>
using namespace std;
class User
{
    string name;
    int s;
public:
    User(string name,int s):name(name),s(s){}
    ~User();
    string get_name()const{return name;}
    string get_status_str()const{
        if(s==1)return "programmer";
                           else
                           return "tester";
                           }
};

#endif // USER_H
