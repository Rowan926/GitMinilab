#include "User.cpp"
#include <iostream>

using namespace std;

int main()
{
    vector<size_t> i;
    User j = User(0, "John Jacobs", 2004, 98112, i);
    User p;
    j.add_friend(1);
    j.add_friend(1);
    j.delete_friend(1);
    return 0;
}
