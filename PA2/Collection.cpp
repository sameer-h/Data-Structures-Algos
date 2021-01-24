#include "Collection.h"
#include "Stress_ball.h"
using namespace std;

/*Sameer Hussain - CSCE 221 - PA 1 Part 2*/
// Second part of Programming Assignment

Collection::Collection() {
    array = nullptr;

    this->size = 0;

    this->capacity = 0;
}

Collection::Collection(int sze) {

    array = new Stress_ball[sze];

    this->size = 0;

    this->capacity = sze;
}

Collection::Collection(const Collection& c) {

    size = c.size; // size

    capacity = c.capacity;


    array = new Stress_ball[size];

    for (int i =0; i<size; ++i) {

        array[i] = c.array[i];
    }
}

Collection& Collection::operator=(const Collection& c) {
    if (this != &c) {

        delete [] array;

        capacity = c.capacity;

        size = c.size;

        array = new Stress_ball[capacity];

        for (int i =0; i< size; ++i) {

            array[i] = c.array[i];
        }
    }
    
    return *this;
}

Collection::~Collection() { // destructor

    delete [] array;

    size = 0;

    capacity = 0; // size and capacity = 0
    // same as make empty
}


Collection::Collection(Collection&& c) {
    size = c.size;

    capacity = c.capacity;

    array = c.array;

    c.array = nullptr; // nullptr so free the ptr

    c.size = 0;

    // c.capacity = 0;

}

Collection& Collection::operator=(Collection&& c) {
    
    if (this != &c) {

        size = c.size;
        capacity = c.capacity;

        array = c.array;


    
        c.array = nullptr;
        c.size = 0;
        // c.capacity = 0;
    }

    return *this;
}

void Collection::insert_item(const Stress_ball& sb) {
    if (size==capacity) {
        if (capacity == 0) {
            capacity=1;
        }
    
        capacity = capacity * 2;
    
    Stress_ball* arr_sb_next = new Stress_ball[capacity];
    
    for (int i = 0; i < size; ++i) {

        arr_sb_next[i] = array[i];
    }

    delete [] array;

    array = arr_sb_next;

    }

    else if (array == nullptr) {

        array = new Stress_ball[capacity];
    }
    array[size] = sb;

    size++;
}


bool Collection::contains (const Stress_ball& sb) const {
    for (int i = 0; i < size; ++i) {
        if (array[i] == sb)
            return true;
    }
    return false;
}

Stress_ball Collection::remove_any_item() {

    if (size == 0) {
        throw runtime_error("Collection empty");
    }
    Stress_ball itemRemove;

    int dex; // index for running through array with i

    itemRemove = array[rand() % size+1];

    for (int i = 0; i<size; ++i) {
        if (array[i] == itemRemove) 
            dex = i;
    }
    
    for (int i = dex; i < size-1; ++i) 
        array[i] = array[i+1];

    size--;
    return itemRemove;
}

void Collection::remove_this_item (const Stress_ball& sb) {

    bool gotItem = false;
    if (size == 0) 
        throw runtime_error("Collection Empty");

    for (int i = 0; i<size; ++i) {

        if (array[i] == sb) {

            gotItem = true;
            
            for (int j = i; j < size-1; j++) 
                array[j] = array[j+1];
            break;
        }
    }

    if (gotItem) 
        size--;
}

void Collection::make_empty() {
    delete [] array;

    array = nullptr;



    size = 0;
    capacity = 0;
}

bool Collection::is_empty() const {
    if (size==0) 
        return true;
    return false;

}

void Collection::print_items() const {
    for (int i = 0; i < size; ++i) {
        
        cout << array[i] << endl; // printing items
    }
}

int Collection::total_items () const {return size;}

int Collection::total_items (Stress_ball_sizes s) const {
    int num = 0;

    for (int i = 0; i < size; ++i) {

        if (array[i].get_size()==s)
            num++;
    }
    return num;
}

int Collection::total_items (Stress_ball_colors c) const {
    int num = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i].get_color()==c) 
            num++; 
    }
    return num;
}

Stress_ball& Collection::operator[](int i) {
    return array[i];
}

const Stress_ball& Collection::operator[](int i) const{
    return array[i];
}

istream& operator>>(istream& is, Collection& c) {

    string sbCol; // stress ball colors
    string sbSiz; // stress ball sizes



    Stress_ball_colors sbColors; // enum class
    Stress_ball_sizes sbSizes; // enum class
    


    string itemStr;

    while (is>>sbCol>>sbSiz) {

// setting for all the colors and sizes

        if (sbCol  == "red")
            sbColors = Stress_ball_colors::red;
        if (sbCol == "blue")
            sbColors = Stress_ball_colors::blue;
        if (sbCol  == "yellow")
            sbColors = Stress_ball_colors::yellow;
        if (sbCol == "green")
            sbColors = Stress_ball_colors::green;
        if (sbSiz == "small") 
            sbSizes = Stress_ball_sizes::small;
        if (sbSiz == "medium") 
            sbSizes = Stress_ball_sizes::medium;
        if (sbSiz == "large") 
            sbSizes = Stress_ball_sizes::large;


        Stress_ball * genericSb = new Stress_ball(sbColors, sbSizes);
        c.insert_item(*genericSb);
    }
    return is;
}

ostream& operator<<(ostream& os, const Collection& c) {

    string colorSB_temp;
    string sizeSB_temp;

    for (int i = 0; i < c.total_items(); ++i) {
        switch(c[i].get_color()) {
            case Stress_ball_colors::red:
                colorSB_temp = "red";
                break;
            case Stress_ball_colors::blue:
                colorSB_temp = "blue";
                break;
            case Stress_ball_colors::yellow: 
                colorSB_temp = "yellow";
                break;
            case  Stress_ball_colors::green:
                colorSB_temp = "green";
                break;


        }
        switch(c[i].get_size()) {
            case  Stress_ball_sizes::small: 
                sizeSB_temp = "small";
                break;
            case  Stress_ball_sizes::medium: 
                sizeSB_temp = "medium";
                break;
            case  Stress_ball_sizes::large: 
                sizeSB_temp = "large";
                break;

        }

        os << "(" << colorSB_temp << ", " << sizeSB_temp << ")" << endl;

    }
    
    return os;
}

Collection make_union (const Collection& c1, const Collection& c2) {
    Collection * c3 = new Collection(); // make union with c1 and c2 = adding sizes
    
    for (int i = 0; i<c1.total_items(); ++i) {
        c3->insert_item(c1[i]);
    }
    for (int i = 0; i<c2.total_items(); ++i) {
        c3->insert_item(c2[i]);
    }

    return *c3;
}

void swap (Collection& c1, Collection& c2) {
    Collection tmpBall = c1;
    c1 = move(c2); // move const
    c2 = move(tmpBall);
}

void sort_by_size(Collection& c, Sort_choice sort) {
    switch(sort) {

        case Sort_choice::bubble_sort: 
            for (int i = 1 ; i < c.total_items(); ++i) {

                bool numb = false;

                for (int j = 0; j < c.total_items()-i; j++) {
                    /*
                    for (int j = 0; j < c.total_items()-i; j++) {
                        go through items
                        */

                    if (c[j].get_size() > c[j+1].get_size()) {
                        
                        Stress_ball tmpBall = c[j];
                        c[j] = c[j+1];
                        c[j+1] = tmpBall;
                        numb = true;
                    }
                }
                if (numb==false) break; // break when is false
            }
            break;

        case Sort_choice::insertion_sort: 
            for (int i = 0; i<c.total_items(); ++i) {

                Stress_ball tmpBall = c[i];
                int j = i;
                for ( ; (j>0) && (tmpBall.get_size() < c[j-1].get_size()); j--) {
                    c[j] = c[j-1];
                }
                c[j] = tmpBall;
            }
            break;
        case Sort_choice::selection_sort: 
            for (int i =0; i< c.total_items()-1; ++i) 
            {
                int indx = i;
                for (int j = i+1; j < c.total_items(); j++) 
                {
                    if (c[j].get_size() < c[indx].get_size()) {
                        indx = j;
                    }
                }
                Stress_ball tmpBall = c[i];

                c[i] = c[indx];
/*
                    if (c[j].get_size() < c[indx].get_size()) {
                        indx = j;
                    }
                }
                Stress_ball tmpBall = c[i];

                c[i] = c[indx];

                */

                c[indx] = tmpBall;
            }
            break;
    }
}
