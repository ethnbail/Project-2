// Programming Project 9.22.4
// Lead programmer Sergio Silerio
// group 6, Sergio Silerio, Ethan Baily, jada isabell  

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Person 
{
private:
    string name;
    vector<Person*> friends;  // Stores pointers to friends

public:
    // Initializes a person with a given name and no friends
    Person(const string& name) : name(name) {}

    // Adds a friend by Person pointer
    void befriend(Person* p) 
    {
        // make sure the friend is not already in the friends list
        if (find(friends.begin(), friends.end(), p) == friends.end()) 
        {
            friends.push_back(p);
        }
    }

    // Removes a friend by Person pointer
    void unfriend(Person* p) 
    {
        friends.erase(remove(friends.begin(), friends.end(), p), friends.end());
    }

    // Returns the list of friend names
    string get_friend_names() const 
    {
        ostringstream oss;
        oss << "Friends: "; 

        for (const auto& friend_ptr : friends) 
        {
            oss << friend_ptr->name << " ";  // Access friend's name via pointer
        }

        string result = oss.str();
        if (!result.empty() && result != "Friends: ") 
        {
            result.pop_back(); // Remove the trailing space after the last name
        }

        return result;
    }

    // Returns the number of friends
    int get_friend_count() const
    {
        return friends.size();
    }

    // Getter for person's name
    string get_name() const {
        return name;
    }
};

int main() 
{
    Person sergio("Sergio");
    Person ethan("Ethan");
    Person bob("Bob");

    sergio.befriend(&ethan);
    sergio.befriend(&bob);

    cout << sergio.get_friend_names() << endl;  // Output: Friends: Ethan Bob
    cout << "Friend count: " << sergio.get_friend_count() << endl;  // Output: Friend count: 2

    sergio.unfriend(&ethan);
    cout << sergio.get_friend_names() << endl;  // Output: Friends: Bob
    cout << "Friend count: " << sergio.get_friend_count() << endl;  // Output: Friend count: 1

    return 0;
}
