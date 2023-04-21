#include "network.h"

Network::Network() {
    users_ = vector<User>();
}

void Network::add_user(User j){
    users_.push_back(j);
}

int Network::add_connection(string s1, string s2){
    int a = -1;
    int b = -1;
    int i = 0;
    for (auto j: users_) {
        if (j.name() == s1)
            a = i;
        if (j.name() == s2)
            b = i;
        i++;
    }
    if (a == -1 || b == -1)
        return -1;
    users_[a].add_friend(b);
    users_[b].add_friend(a);
    return 0;
}

int Network::remove_connection(string s1, string s2){
    int a = -1;
    int b = -1;
    int i = 0;
    for (auto j: users_) {
        if (j.name() == s1)
            a = i;
        if (j.name() == s2)
            b = i;
        i++;
    }
    if (a == -1 || b == -1)
        return -1;
    users_[a].delete_friend(b);
    users_[b].delete_friend(a);
    return 0;
}

int Network::get_id(string name){
    int i = 0;
    for (auto j: users_) {
        if (j.name() == name) {
            return i;
        }
        i++;
    }
    return -1;
}

int Network::read_friends(char* fname){
    string s;
    int x;
    ifstream i;
    i.open(fname);
    if(i.fail()){
        cout << "Input file opening failed." << endl;
        return -1;
    }
    i >> x; // number of friends
    cout << x << " users added.\n" << endl;
    size_t id;
    string name;
    int year;
    int zip;
    vector<size_t> friends;
    while (i >> id) {
        getline(i >> ws, name);
        i >> year;
        i >> zip;
        friends.clear();
        string temp;
        getline(i >> ws, temp);
        istringstream iss(temp);
        int number;
        while (iss >> number) {
            friends.push_back(number);
        }
        name.erase(0, name.find_first_not_of(" \t\r\n"));
        name.erase(name.find_last_not_of(" \t\r\n") + 1);
//        cout << "Id: " << id << endl;
//        cout << "Name: " << name << endl;
//        cout << "Year: " << year << endl;
//        cout << "Zip code: " << zip << endl;
//        cout << "Friends:";
//        for (int n : friends) {
//            cout << " " << n;
//        }
//        cout << endl;
        User u = User(id,name,year,zip,friends);
        users_.push_back(u);
//        cout << "ID: " << u.id() << " Name: " << u.name() << " Year: " << u.year() << " Zip: " << u.zip() << endl;
    }
    i.close();
    return 0;
}

int Network::write_friends(char *fname){
    ofstream o;
    o.open("output.txt");
    if(o.fail()){
        cout << "output file opening failed" << endl;
        return -1;
    }
    o << num_users() << endl;
    for (auto i: users_) {
        o << i.id() << endl;
        o << "\t" << i.name() << endl;
        o << "\t" << i.year() << endl;
        o << "\t" << i.zip() << endl;
        o << "\t";
        for (auto j: i.friends())
            o << j << " ";
        o << endl;
    }
    return 0;
}

size_t Network::num_users(){
    return users_.size();
}

vector<User> Network::users() {
    return users_;
}

// Hello this is a different message
