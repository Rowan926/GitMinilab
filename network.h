#ifndef NETWORK_H
#define NETWORK_H

#include "User.cpp"
#include <cstddef>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Network
{
public:
    Network();

    void add_user(User);

    int add_connection(string s1, string s2);

    int remove_connection(string s1, string s2);

    int get_id(string name);

    int read_friends(char* fname);

    int write_friends(char *fname);

    size_t num_users();

    vector<User> users();
private:

    vector<User> users_;
};

#endif // NETWORK_H
