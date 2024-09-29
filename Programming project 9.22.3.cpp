// Programming Project 9.22.3
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
    vector<string> friends;

public:
    // Initializes a person with a given name and no friends
    Person(const string& name) : name(name) {}

    // Adds a friend by name
    void befriend(Person p) 
    {
        if (find(friends.begin(), friends.end(), p.name) == friends.end()) 
        {
            friends.push_back(p.name);
        }
    }

    // Removes a friend by name
    void unfriend(Person p) 
    {
        friends.erase(remove(friends.begin(), friends.end(), p.name), friends.end());
    }

    // Returns the list of friends
    string get_friend_names() const 
    {
        ostringstream oss;
        oss << "Friends: "; 

        for (const auto& friend_name : friends) 
        {
            oss << friend_name << " ";
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
};

int main() 
{
    Person sergio("Sergio");
    Person ethan("Ethan");
    Person bob("Bob");

    sergio.befriend(ethan);
    sergio.befriend(bob);

    cout << sergio.get_friend_names() << endl;  // Output: Friends: Ethan Bob
    cout << "Friend count: " << sergio.get_friend_count() << endl;  // Output: Friend count: 2

    sergio.unfriend(ethan);
    cout << sergio.get_friend_names() << endl;  // Output: Friends: Bob
    cout << "Friend count: " << sergio.get_friend_count() << endl;  // Output: Friend count: 1

    return 0;
}
