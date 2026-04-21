#include<iostream>
#include<vector>
#include<string>
using namespace std;

//  User and group many to many relation
class Group;

class User {
private:
    string name;
    vector<Group*> groups;

public:
    User(const string& name): name(name){};
    string getName()  { return name; };
    void addGroup(Group* group);
};

class Group{
private:
    string name;
    vector<User*> users;

public:
    Group(const string& name): name(name){};

    void addUser(User* user);
    string getName()  { return name; };
    vector<User*> getUser() const { 
        return users;
    };
};

void User::addGroup(Group* group){
    for(auto* g: groups){
        if(g== group) return;
    }
    groups.push_back(group);
    group->addUser(this);
}

void Group::addUser(User* user){
    for(auto* u: users) if(u==user) return;
    users.push_back(user);
    user->addGroup(this);
}

int main(){
    User u1("alice");
    User u2("bob");
    User u3("sara");

    Group g1("backend");
    Group g2("AWS");

    u1.addGroup(&g1);
    u1.addGroup(&g2);

    u2.addGroup(&g1);
    g1.addUser(&u3);
    g2.addUser(&u2);

    for(auto*  c: g2.getUser()){
        cout << c->getName() << " ";
    }
    return 0;
}