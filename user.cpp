#include "User.h"

#include <cstddef>
#include <string>
#include <vector>
#include <algorithm>

User::User() {
    friends_ = vector<size_t>();
}

User::User(size_t a, string b, int c, int d, vector<size_t> e) {
    id_ = a;
    name_ = b;
    year_ = c;
    zip_ = d;
    friends_ = e;
}

void User::add_friend(size_t num) {
    if(find(friends_.begin(), friends_.end(), num) == friends_.end()){
        friends_.push_back(num);
    }
}

void User::delete_friend(size_t num) {
    if(find(friends_.begin(), friends_.end(), num) != friends_.end()){
        friends_.erase(find(friends_.begin(), friends_.end(), num));
    }
}

size_t User::id() {
    return id_;
}

string User::name() {
    return name_;
}

int User::year() {
    return year_;
}

int User::zip() {
    return zip_;
}

vector<size_t> User::friends() {
    return friends_;
}
