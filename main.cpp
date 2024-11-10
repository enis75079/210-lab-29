/*

lab29: 
COMSC-210
Naveen Islam

*/

// headers for file handling, data structures, strings, and more
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

// struct for item name and type
struct Item {
    string name;
    string type;
};

// function prototypes
// function to simulate inventory management over the 52 week period
// paramenters: map of the clothing items, intervals for the months
void simInventory(map<string, vector<Item> >&);
void inventorySize(map<string, vector<Item> >);
void specificStatus(string, map<string, vector<Item> >);

// define main
int main() {
    // initialize a map that stores the different clothing items which are associated with an array of lists (in stock, discount, or out of stock)
    map<string, vector<Item> > inventory;
    string name;
    string type;
    string status;
    

    // read data from a file containing information on the items and input them to the map
    ifstream items("items.txt");
    // for each line, the file will specify the clothing type (shirt, pants, or shoe) and the details of the item
    while (items >> name >> type >> status) {
        inventory[status].push_back(Item{name, type});
    }    

    // displays the items from the file and outputs them in a formatted fashion
    for (const auto& x : inventory) {
        cout << x.first << " ";
        for (const auto& y : x.second) {
            cout << y.name << " " << y.type << endl;
        }
    }
    
    for (int week = 1; week <= 52; week++) {
        bool nextWeek = false;
        int userChoice = 0;

        while (nextWeek != true) {
            // displays the management interface
            cout << "\nManagement Mode: " << "(week: " << week << ")" << endl;
            cout << "[1] Total Inventory" << endl;
            cout << "[2] Specific Inventory Stock" << endl;
            cout << "[3] Next Week" << endl;
            cout << "[4] Quit Early" << endl;
            cout << "Choice: ";
            cin >> userChoice;
            cout << endl;
            if (userChoice == 1) {
                // displays the total inventory
                cout << "Total Inventory: ";
                inventorySize(inventory);
            } else if (userChoice == 2) {
                // asks user for the specific type of clothing's stock
                int stockChoice = 0;
                cout << "[1] In Stock" << endl;
                cout << "[2] Discount" << endl;
                cout << "[3] Out of Stock" << endl;
                cout << "Choice: ";
                cin >> stockChoice;
                if (stockChoice == 1) {
                    cout << "In Stock Inventory: ";
                    specificStatus("in_stock", inventory);
                } else if (stockChoice == 2) {
                    cout << "Discount Inventory: ";
                    specificStatus("discount", inventory);
                } else if (stockChoice == 3) {
                    cout << "Out of Stock Inventory: ";
                    specificStatus("out_stock", inventory);
                }
            } else if (userChoice == 3) {
                // continue to next week
                simInventory(inventory);
                cout << "Starting week:" << (week + 1) << " " << endl;
                nextWeek = true;
            } else if (userChoice == 4) {
                // terminates the program early
                cout << "Ended on week: " << (week + 1) << endl;
                return 0;
            } else {
                // if user inputs a value that doesnt correspond with the management prompt
                cout << "Invalid input. Program has been terminated." << endl;
                return 0;
            }
        }
    }

    // close the file
    // begin a simulation for managing inventory
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
// inventorySize function. if the manager wants to access their total stock
void inventorySize(map<string, vector<Item> > inventory) {
    cout << inventory.size() << endl;
}

// specifcStatus function. similar to inventorySize where it finds the inventory count for a specific status
void specificStatus(string status, map<string, vector<Item> > inventory) {
    string chosenStatus = status;
    int total = 0;
    auto it = inventory.find(chosenStatus);
    cout << endl;
    if (it != inventory.end()) {
        for (const auto x : it->second) {
            total++;
        }
    }
    cout << total;
    cout << endl;
}
// simInventory function. function to simulate the inventory
void simInventory(map<string, vector<Item> >& inventory) {
    srand(time(0));

    int sold = rand() % (inventory["in_stock"].size() + 1);
    int restock = rand() % (inventory["out_stock"].size() + 1);
    cout << "Sold: " << sold << " item(s)" << endl;

    // simulates purchases. erases an item from the "in_stock" status, and puts that item into the "out_stock" status
    for (int i = 0; i < sold && !(inventory["in_stock"].empty()); i++) {
        int soldIndex = rand() % (inventory["in_stock"].size());

        Item soldItem = inventory["in_stock"][soldIndex];
        inventory["in_stock"].erase(inventory["in_stock"].begin() + soldIndex);
        inventory["out_stock"].push_back(soldItem);
        cout << "=> " <<soldItem.name << " (" << soldItem.type << ")" << endl;
    }
    cout << "Restocked " << restock << " item(s)" << endl;

    // simulates restocking. erases an item from the "out_stock" status, and puts that item into the "in_stock" status
    for (int i = 0; i < restock && !(inventory["out_stock"].empty()); i++ ) {
        int restockIndex = rand() % (inventory["out_stock"].size());

        Item restockItem = inventory["out_stock"][restockIndex];
        inventory["out_stock"].erase(inventory["out_stock"].begin() + restockIndex);
        inventory["in_stock"].push_back(restockItem);
        cout << "=>: " << restockItem.name << " (" << restockItem.type << ") " << endl;
    }
    cout << endl;
}