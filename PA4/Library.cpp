#include "Library.h"
#include <fstream>
#include <iostream>
#include "TemplatedDLList.h"

/* Sameer Hussain - CSCE 221 - PA 2*/

int letter_convert(char letter) {
    if ('a' <= letter && 'z' >= letter) {  // lower case letter for 'c'

        return letter - 'a'; // map number to letter

    } else if ('A' <= letter && 'Z' >= letter) { // uppercase

        return letter - 'A'; // same as lowercase map

    } else {

        throw runtime_error("Incorrect input, please type again.");
    }
}

/*  Iterate through book_db's linked lists and return a vector containing all of 
the records whose title matches the function's argument. Return an empty vector if none match. */

std::vector<Record> Library::search (std::string title) { // returns vector of records

    vector<Record> vectRecord;

    char letter = title[0];

    int pos = letter_convert(letter);

    DLListNode<Record> *nde = book_db[pos].first_node(); // node for first node that holds letter

    while(nde != book_db[pos].after_last_node()) {

    if (nde->obj.get_title() == title)
        {
            vectRecord.push_back(nde->obj);
        }

        nde = nde->next;

        }

        return vectRecord;
}

/* Display the string of options to the user (using cout) */

int Library::prompt_menu(std::vector<std::string> vect) {

    int count = 1;

    for (auto x : vect) {

        cout << count << ". " << x << endl;

        count++;
    }

    int userInput;
    
    cin >> userInput;

    return userInput-1; // the index of vect (the function's argument) corresponding to the user's input.
}

Record Library::prompt_record() {

    std::string userInput;

    Record r;

    // Given format

    cout << "Please enter a Title" << endl; 
    cin >> userInput;
    r.set_title(userInput);

    cout << "Please enter an Author" << endl;
    cin >> userInput;
    r.set_author(userInput);

    cout << "Please enter an ISBN number" << endl;
    cin >> userInput;
    r.set_ISBN(userInput);

    cout << "Please enter a Year" << endl;
    cin >> userInput;
    r.set_year(userInput);

    cout << "Please enter an Edition" << endl;
    cin >> userInput;
    r.set_edition(userInput);
    
    return r;
}

/* Print the prompt to the user, then take in the user's input from cin. */

std::string Library::prompt_string(std::string prompt) {

    std::string userInput;

    cout << prompt << endl;

    cin >> userInput;

    return userInput;
}

std::string Library::prompt_title() {

    std::string userInput;

    cout << "Enter a title" << endl;

    cin >> userInput;

    return userInput;
}

char Library::prompt_yes_no() {

    char YN = 'x';
    cout << "Please enter Y/N" << endl;
    cin >> YN;
    return YN;
}

void Library::print_database() {

    for (auto x : book_db) cout << x << endl; // cout the contents of library
}

bool Library::add_record (Record book) {

    char letter = book.get_title()[0];

    int pos = letter_convert(letter);

    bool exists = false;

    if (!exists)  // if (true)
    {
        book_db[pos].insert_last(book);
        return true;
    }
    return false;
}

/*  Search through book_db and remove the record if it is in the database. */

void Library::remove_record(Record book) {

    char letter = book.get_title()[0];
    
    int pos = letter_convert(letter);

    DLListNode<Record> *nde = book_db[pos].first_node();

    while(nde != book_db[pos].after_last_node()) {

        if (book == nde->obj) {
            
            DLListNode<Record> *node_after = nde->next;

            nde->prev->next = node_after;

            node_after->prev = nde->prev;

            delete nde;

            break;
        }

        nde = nde->next;
    }
}


int Library::export_database(std::string filename) {

    return 0;
}

/* Read the contents of a properly formatted file of records (such as Book.txt) into your program, create a record for each book
 in the file, then add each book to the correct linked list in book_db.*/

int Library::import_database(std::string filename) {

    Record r;

    int count = 0;

    ifstream ifs(filename);

    if (!ifs.is_open()) {

        cout << filename << "Cannot find this";

        return 1;
    }

    while (ifs >> r) {

        add_record(r);

        count++;
    }

    return count;
}

