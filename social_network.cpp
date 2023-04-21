#include "Network.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    Network net;

    // Read in file
    cout << "\nWelcome to the social network!\nPlease input a file name." << endl;
    string s;
    cin >> s;
    net.read_friends(const_cast<char*>(s.c_str()));


    cout << "Please type the number corresponding to your request. \n1: Add a user \n2: Add a friend connection \n3: Remove a friend connection \n4: Print users \n5: Print friends of a user\n6: Write data to file\n7: Exit program" << endl;
    int x;
    cin >> x;
    while (x != 0)  {
        if (x == 1) {
            x = 0;
            cout << "Please provide your first and last name followed by your birth year and zip code all on the same line." << endl;
            string name, b;
            cin >> name;
            cin >> b;
            name += " " + b;
            cin >> x;
            int c;
            cin >> c;
            vector<size_t> d;
            User temp = User(net.num_users(),name,x,c,d);
       //   cout << temp.id() << " " << temp.name() << " " << temp.year() << " " << temp.zip() << endl;
            net.add_user(temp);
            cout << temp.name() << " has been added to the network." << endl;
            cout << "Choose a command or press 8 to see commands." << endl;
            cin >> x;
        } else if (x == 2) {
            x = 0;
            cout << "Please provide the full names of the two users to make friends." << endl;
            string name, b, name2, a;
            cin >> name;
            cin >> b;
            name += " " + b;
            cin >> name2;
            cin >> a;
            name2 += " " + a;
            if (net.add_connection(name, name2) == -1) {
                cout << "Error. User does not exist." << endl;
            } else
            cout << "Connection added. Note: if users were already friends, nothing occured." << endl;
            cout << "Choose a command or press 8 to see commands." << endl;
            cin >> x;
        } else if (x == 3) {
            x = 0;
            cout << "Please provide the full names of the two users to remove the friendship." << endl;
            string name, b, name2, a;
            cin >> name;
            cin >> b;
            name += " " + b;
            cin >> name2;
            cin >> a;
            name2 += " " + a;
            if (net.remove_connection(name, name2) == -1) {
                cout << "Error. User does not exist." <<endl;
            } else
            cout << "Connection removed. Note: if users were already not friends, nothing occured." << endl;
            cout << "Choose a command or press 8 to see commands." << endl;
            cin >> x;
        } else if (x == 4) {
            x = 0;
            cout << "ID  Name\t\tYear  Zip\n===============================================\n" << endl;
            for (auto i : net.users()) {
                cout << i.id();
                if (i.id() < 10)
                    cout << "   ";
                else
                    cout << "  ";
                cout << i.name() << "   \t" << setw(4) << setfill('0') << i.year() << "  " << setw(5) << setfill('0') << i.zip() << endl; // setw and setfill allows printing of leading zeros.
            }
            cout << "Choose a command or press 8 to see commands." << endl;
            cin >> x;
        } else if (x == 5) {
            x = 0;
            cout << "Please provide the name of the user of which you want to see the friends of." << endl;
            string name, b;
            cin >> name;
            cin >> b;
            name += " " + b;
            net.get_id(name);
            cout << "ID  Name\t\tYear  Zip\n===============================================\n" << endl;
            for (auto i: net.users()[net.get_id(name)].friends()) {
                cout << net.users()[i].id();
                if (net.users()[i].id() < 10)
                    cout << "   ";
                else
                    cout << "  ";
                cout << net.users()[i].name() << "   \t" << setw(4) << setfill('0') << net.users()[i].year() << "  " << setw(5) << setfill('0') << net.users()[i].zip() << endl; // setw and setfill allows printing of leading zeros.
            }
            cout << "Choose a command or press 8 to see commands." << endl;
            cin >> x;
        } else if (x == 6) {
            x = 0;
            cout << "Please input a file name to write to." << endl; // print number of users
            string s;
            cin >> s;
            if (net.write_friends(const_cast<char*>(s.c_str())) != -1)
                cout << "Printed user data to " << s << "." << endl;
            cout << "Choose a command or press 8 to see commands." << endl;
            cin >> x;
        } else if (x == 8) {
            x = 0;
            cout << "Please type the number corresponding to your request. \n1: Add a user \n2: Add a friend connection \n3: Remove a friend connection \n4: Print users \n5: Print friends of a user\n6: Write data to file\n7: Exit program" << endl;
            cin >> x;
        }
        else {
            x = 0;
            cout << "Exiting Program." << endl;
            exit(0);
        }
    }
    return 0;
}
