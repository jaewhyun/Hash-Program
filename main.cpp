// John Maslanka October 2009 HashProg1a.cpp
// A program which does hashing of user data to a fixed-length array.
// Edits 10/24/2014 JM -- (1) Remove two break; statements from the code. (2) Define
// a "full" boolean variable to discontinue processing when the array is full.
// (3) Define a "found" boolean variable to indicate that a location in the array is
// found for a new entry. The "found" variable terminates further search for a new location
// for an input value when a location has been successfully found.

// Jae Final Edit 

#include <iostream>
#include <string>
using namespace std;
// #define MAX 23

// define name, firsthash, occupied
string *name;
int *firstHash;
bool *occupied;

int main ()
{
    bool full = false; // boolean set to false, changed to true when hash table full
    
    char inputLine[80] = "";
    
    int hashValue, modHash, i;
    
    //string name [MAX];  // This line and following two establish the information which
    
    //int firstHash [MAX];  // is preserved for each entry of the hash array
    
    //bool occupied [MAX] = {MAX * false};
    
    // ask user for the number of elements in the array
    cout << "How many number of elements would you like in your array? Enter a number bigger than 0 and less than or equal to 23: ";

    // get userinput
    int userinputmax;
    cin >> userinputmax;
    
    // if the input is good
    if(!cin.eof() && cin.good())
    {
        // while userinput is not bigger than 0 and smaller than 23
        while(userinputmax > 23 || userinputmax < 0)
        {
            cout << "The number has to be smaller than 23 and bigger than 0. Try again: ";
            cin >> userinputmax;
        }
    }
    else
    {
        cout << "Try again! Bye." << endl;
    }
    
    // dynamically allocated array of name
    string *name;
    name = new string[userinputmax];
    // dynamically allocated array of firstHash
    int *firstHash;
    firstHash = new int[userinputmax];
    // dynamically allocated array of occupied
    bool *occupied;
    occupied = new bool[userinputmax]();
    
    cout << "Please enter each string of characters followed by <Enter>." << endl
    << "Terminate by entering EOF on keyboard (control-z in Windows)." << endl;
    
    // clear c.in
    cin.ignore();
    
    while (!cin.eof() && full == false)// test for EOF
    {
        //  also test for hash table not full
        cin.getline(inputLine, 80);
        
        if (!cin.eof())
        {
            hashValue = 0;  // calculate initial hash value
            for (i = 0; i < strlen (inputLine); i++)
            {
                hashValue += (int) inputLine[i];
                
            }
            
            // switched out MAX for userinput
            modHash = hashValue % userinputmax;	// test initial hash value for available //  array entry
            
            if (occupied[modHash] == false)
            {
                name[modHash] = inputLine;
                firstHash[modHash] = modHash;
                occupied [modHash] = true;
                cout << "Your input line " << inputLine << " hashes to "
                << modHash << endl;
            }
            else   // initial test failed, look for alternate location in array
            {
                cout << "Hash collision! " << "We need to find an open table entry." << endl;
                bool found = false;  // declare binary state variable "found":
                // false means an available  array position
                // not found, true means it is found.
                // switched out MAX for userinput
                for (i = 0; i < userinputmax && found == false && full == false; i++)
                {
                    // test found == false, need to stop execution of loop when
                    //  an available array position is found
                    if (occupied[i] == false)// test if selected hash
                    { 	//table element is occupied
                        name[i] = inputLine;
                        firstHash[i] = modHash;
                        occupied [i] = true;
                        cout << "Your input line" << inputLine
                        << " hashes to " << i << endl;
                        found = true; // Set array position found
                        // remove unnecessary } right curly bracket
                        // remove break; statement
                    }
                    // switched out MAX for userinput
                    else if (i >= userinputmax-1)
                    {
                            cout << "Sorry! Table is full!" 
                            <<" We cannot place your entry." 
                            << endl << endl;
                            full = true;  // set state flag hash
                            //array full
                    }
                }
            }
        }
    }
    // switched out MAX for userinput
    for (i = 0; i < userinputmax; i++)  // finally, list members of hash table
    {
        if (occupied[i] == true)
        {
            cout << " Position in table is " << i << " Hashed to "
            << firstHash[i] << ".\tString is " << name[i] << endl;
        }
    }
    return 0;
}
