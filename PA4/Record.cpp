#include "Record.h"

/* Sameer Hussain - CSCE 221 - PA 2*/

string Record::get_title() const {
    return title;
}

string Record::get_ISBN () const {
    return ISBN;
}

string Record::get_year () const {
    return year;
}

string Record::get_edition () const {
    return edition;
}

string Record::get_author () const {
    return author;

}

void Record::set_title (string t) {
    title = t;
}

void Record::set_ISBN (string isbn) {
    ISBN = isbn;
}

void Record::set_year (string yr) {
    year = yr;
}

void Record::set_edition (string ed) {
    edition = ed;
}

void Record::set_author (string aut) {
    author = aut;
}



std::istream& operator>>(std::istream& is, Record& rec) {

    string emp;

    string t, a, i, y, e;

    getline(is, emp); // empty char line

    getline(is, t);
    getline(is, a);
    getline(is, i);
    getline(is, y);
    getline(is, e);

    rec.set_title(t);

    rec.set_author(a);

    rec.set_ISBN(i);

    rec.set_year(y);

    rec.set_edition(e);

    return is;
}
std::ostream& operator<<(std::ostream& os, Record& rec) 
{
    os << rec.get_title() << endl;

    os << rec.get_author() << endl;

    os << rec.get_ISBN() << endl;

    os << rec.get_year() << endl;
    
    os << rec.get_edition() << endl;

    return os;
}

// Comparison operators
bool operator==(const Record& r1, const Record& r2) {

if(r1.get_title() == r2.get_title() && r1.get_ISBN() == r2.get_ISBN() && r1.get_author() == r2.get_author()) { // comparing the data

    return true;
}
return false;
}
