#include "Jeans.h"
#include <cstdlib>

Jeans::Jeans() : color(Jeans_colors(rand() % 4)), size(Jeans_sizes(rand() % 4)) {} // random generation for the vals

Jeans::Jeans(Jeans_colors c, Jeans_sizes s) : color(c), size(s) {}


bool Jeans::operator==(const Jeans &sb) {  // operator for getting color and size
bool c1 = false;
bool c2 = false;

if (get_color() == sb.get_color()) {
    c1 = true;
}

if (get_size() == sb.get_size()) {
    c2 = true;
}

    return c1 && c2;
}

Jeans_colors Jeans::get_color() const {

    return color;
}

Jeans_sizes Jeans::get_size() const {

    return size;
}

ostream& operator << (ostream& os, const Jeans& sb) { // operator
    switch(sb.get_color()) {
        case Jeans_colors::white:
            os<<"(white, ";
            break;
        case Jeans_colors::black:
            os<<"(black, ";
            break;
        case Jeans_colors::blue: 
            os<<"(blue, ";
            break;
        case  Jeans_colors::grey:
            os<<"(grey, ";
            break;
    }
    switch(sb.get_size()) {
        case  Jeans_sizes::small: 
            os<<"small)";
            break;
        case  Jeans_sizes::medium: 
            os<<"medium)";
            break;
        case  Jeans_sizes::large: 
            os<<"large)";
            break;
        case Jeans_sizes::xlarge:
            os<<"xlarge)";
            break;
    }
    return os;
}