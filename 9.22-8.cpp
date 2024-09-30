// Programmer -  Ethan Bailey
// Tester - Ethan Bailey, Jada Isable, Sergio Silerio
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class CashRegister {

    private:

        vector<int> cents; // stores the prices of each item in cents (integers)
        vector<int> taxable_cent; // for the taxable items
        double tax_rate; 

    public:

        CashRegister(double tax_rate) : tax_rate(tax_rate){}

        void clear() {
            cents.clear(); // clear the cents vector
            taxable_cent.clear();
        }

        void add_item(double price) {
            int price_in_cents = static_cast<int>(price * 100 + 0.5); //convert to cents and add .5 to round the remainder
            cents.push_back(price_in_cents); // adds price in cents to the vector
        }
        void add_taxable_item(double price) {
            int price_in_cents = static_cast<int>(price * 100 + 0.5);
            taxable_cent.push_back(price_in_cents);
        }

        int get_total() const { // gets the total of the prices in cents
            int total_cents = 0; // starts the total at 0
            for (int cent : cents) {
                total_cents += cent; // adds each price in cents to the total
            }
            for (int cent : taxable_cent) {
                total_cents += cent; // adds each price in cents to the total
            } 
            return total_cents; 
        }

        double get_total_tax() const{
            int total_taxable_cents = 0; // starts total taxable at 0
            for(int cent : taxable_cent ){
                total_taxable_cents += cent; // adds the tax to the price total
            }
            return static_cast<int>(total_taxable_cents * tax_rate + 0.5);
        }

        int get_count() const { // get count of the items
            return cents.size() + taxable_cent.size(); // returns number of items
        }

        void display_all() const { // display all the item prices
            cout << "Prices in cents of all the items currently in the sale: " << endl; 
            for (int cent : cents) {
                cout << cent << "¢"<< endl; 
            }
            for (int price_in_cents : taxable_cent){
                cout << "Taxable Item: " << price_in_cents <<  "¢"  << endl; 
            }
        }
    };

    int main() {
        int total_tax;
        double tax_rate = 0.07;
        CashRegister register1(tax_rate); //adds the tax rate to the rgister

        register1.clear(); // clear the register
        register1.add_taxable_item(12.99);
        register1.add_taxable_item(23.49);
        register1.add_item(45.29);
        register1.add_item(11.98);
        register1.add_item(34.49);
        register1.add_item(55.99);
        register1.add_item(14.60);    
        
        total_tax = register1.get_total_tax();

        cout << "Total: " << register1.get_total() + total_tax << "¢" << endl;
        cout << "Total tax: " << register1.get_total_tax()  << "¢" << endl;
        cout << "Number of items: " << register1.get_count() << endl;


        register1.display_all();

    return 0;
 }
