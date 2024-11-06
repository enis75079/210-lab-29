/*

lab29: Project Proposal, Pseudocode, & Mockup
COMSC-210
Naveen Islam

*/

// headers for file handling, data structures, strings, and more

// function prototypes
// function to simulate inventory management over the 52 week period
    // paramenters: map of the clothing items, intervals for the months

// define main function
    // initialize a map that stores the different clothing items which are associated with an array of lists (in stock, discount, or out of stock)

    // read data from a file containing information on the items and input them to the map
        // for each line, the item will specify the clothing type (shirt, pants, or shoe) and the details of the item
        // inserts the item into the appropriate list in the array for its item

    // closes the file
    // begin a simulation for managing iventory
        // 52 time intervals (per week)
            //  iterate through each clothing item in the map
                
                // for each item, simulate weekly margin

                // simulate customers purchasing items
                    // determine how many items are sold for each item randomly
                    // move items that are sold from their list (in stock) to out of stock
                    // assign discounts based on customer purchasing habits...
                    // update the revenue based on how many items are sold that week
                
                // restock simulation
                    // check stock levels. If the item has reached below a certain threshold, then add a 