// Programmer -  Ethan Bailey
// Tester - Ethan Bailey, Jada Isable, Sergio Silerio
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class CashRegister {

    private:
    vector<int> cents; // stores the prices of each item in cents (integers)

    public:
        void clear() {
            cents.clear(); // clear the cents vector
        }

        void add_item(double price) {
            int price_in_cents = static_cast<int>(price * 100 + 0.5); //convert to cents and add .5 to round the remainder
            cents.push_back(price_in_cents); // adds price in cents to the vector
        }

        int get_total() const { // gets the total of the prices in cents
            int total_cents = 0; // starts the total at 0
            for (int cent : cents) {
                total_cents += cent; // adds each price in cents to the total
            }
            return total_cents; 
        }

        int get_count() const { // get count of the items
            return cents.size(); // returns number of items
        }

        void display_all() const { // display all the item prices
            cout << "Prices in cents of all the items currently in the sale: " << endl; 
            for (int cent : cents) {
                cout << cent << "¢"<< endl; 

            }
        }
    };

    int main() {
        CashRegister register1;

        register1.clear(); // clear the register
        register1.add_item(12.99);
        register1.add_item(23.49);
        register1.add_item(45.29);
        register1.add_item(11.98);
        register1.add_item(34.49);
        register1.add_item(55.99);
        register1.add_item(14.60);    

        register1.display_all();

        cout << "Number of items: " << register1.get_count() << endl;
        
        cout << "Total cents: " << register1.get_total() << endl; 



    return 0;
 }
