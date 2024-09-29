// Programming Project 9.22.5
// Lead programmer Sergio Silerio
// group 6, Sergio Silerio, Ethan Baily, jada isabell 

#include <iostream>

using namespace std;

class Battery 
{
private:
    double capacity;          // original capacity of the battery
    double remainingCapacity;  

public:
    // Initializes the battery with a given capacity (in mAh)
    Battery(double capacity) : capacity(capacity), remainingCapacity(capacity) {}

    // Drains the battery by a given amount (in mAh)
    void drain(double amount) 
    {
        if (amount > remainingCapacity) 
        {
            remainingCapacity = 0;  // The battery cannot have negative capacity
        } 
        else
        {
            remainingCapacity -= amount;
        }
    }

    // Charges the battery to its original capacity
    void charge() 
    {
        remainingCapacity = capacity;
    }

    // Returns the remaining capacity of the battery (in mAh)
    double get_remaining_capacity() const 
    {
        return remainingCapacity;
    }
};

int main() 
{
    Battery myBattery(2500);  // Create a battery with a capacity of 2500 mAh

    cout << "Initial capacity: " << myBattery.get_remaining_capacity() << " mAh" << endl;

    myBattery.drain(500);  // Drain 500 mAh from the battery
    cout << "After draining 500 mAh: " << myBattery.get_remaining_capacity() << " mAh" << endl;

    myBattery.charge();    // Recharge the battery to its full capacity
    cout << "After charging: " << myBattery.get_remaining_capacity() << " mAh" << endl;

    return 0;
}
