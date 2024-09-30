// Programmer -  Ethan Bailey
// Tester - Ethan Bailey, Jada Isable, Serio Silerio
 #include <iostream>
 #include <vector>
 #include <iomanip>

 using namespace std;

 class  CashRegister{

    private:
        vector<double> prices; // stores the prices of each item

    public:
        void clear(){
            prices.clear();
        }

        void add_item(double price){
            prices.push_back(price); // adds price to the vector
        }

        double get_total() const{ // gets the total of the prices
            double total = 0; // starts the total at 0
            for (double price : prices){
                total += price; // adds each price tot he total
            }
            return total;
        }

        int get_count() const{ // get count of the items
            return prices.size();
        }

        void display_all() const{ // display all the items prices
            cout << fixed << setprecision(2);
            cout << "Prices of all the items currently in the sale: " << endl; 
            for (double price : prices){
                cout << "$" << price << endl;
            }
        }
 };
  int main()
  {

    CashRegister register1;

    register1.clear();
    register1.add_item(22.99);
    register1.add_item(13.49);
    register1.add_item(5.29);
    register1.add_item(21.98);
    register1.add_item(14.49);
    register1.add_item(5.99);
    register1.add_item(14.60);    
      
    register1.display_all();
      

    cout << fixed << setprecision(2); // since its money it should display both decismal places
      cout << "Number of items: " << register1.get_count() << endl;

    cout << "Total: $" << register1.get_total() << endl;


return 0;


  }
