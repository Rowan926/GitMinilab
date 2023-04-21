#ifndef USER_H
#define USER_H


#include <cstddef>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class User {
public:
    User();

    User(size_t a, string b, int c, int d, vector<size_t> e);

    void add_friend(size_t num);

    void delete_friend(size_t num);

    size_t id();

    string name();

    int year();

    int zip();

    vector<size_t> friends();

private:
    size_t id_;
    string name_;
    int year_;
    int zip_;
    vector<size_t> friends_;
};

#endif // USER_H
