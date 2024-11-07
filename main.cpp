/*

lab29: Project Proposal, Pseudocode, & Mockup
COMSC-210
Naveen Islam

*/

// headers for file handling, data structures, strings, and more
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>
using namespace std;

// structure for storing the clothing item
struct Item {
    string name;
    string clothingType;
};

// function prototypes
// function to simulate inventory management over the 52 week period
// paramenters: map of the clothing items, intervals for the months
void simInventory(map<string, list<Item>>&, int);

// define main
int main() {
    // initialize a map that stores the different clothing items which are associated with an array of lists (in stock, discount, or out of stock)
    map<string, list<Item>> inventory;

    inventory["in_stock"].push_back({"Shirt"});
    inventory["discount"].push_back({"Pants"});
    inventory["out_stock"].push_back({"Shoes"});


    // read data from a file containing information on the items and input them to the map
        // for each line, the file will specify the clothing type (shirt, pants, or shoe) and the details of the item
        // inserts the item into their appropriate list in the array for its item

    // close the file
    // begin a simulation for managing inventory
    simInventory(inventory, 52);
        // 52 time intervals (per week)
            //  iterate through each clothing item in the map
                
                // for each item, simulate weekly margin

                // simulate customers purchasing items
                    // determine how many items are sold for each item randomly
                    // move items that are sold from their list (in stock) to out of stock
                    // assign discounts based on customer purchasing habits...
                    // update the revenue based on how many items are sold that week
                
                // restock simulation
                    // check stock levels. If the item has reached below a certain threshold, then add a specified amount to the stock
                    // (if necessary) move items from out of stock to in stock after restock
                
                // discount simulation
                    // select items either randomly or based off most sold item from in stock list to discount list
                    // adjust the price assigned to the item to a discount item price

            // display the summary for the week
    // return 0
    return 0;
// end of main
}

// simInventory function. function to simulate the inventory
void simInventory(map<string, list<Item>>& inventory, int week) {
    // loops for the parameter weeks (in this case, 52)
    int i = 0;
    while (i != week) {
        // for each item in inventory, check inventory, or mark discounts and out of stock items
        // then update all items
        for (auto& type : inventory) {
            // perform some task that gives the type of item
            cout << "" << type.first << endl;

            for (auto& item : type.second) {
                // perform some task that will display information useful to managing
                cout << item.name << endl;
            }
        }
        i++;
    }

}