#include "Stress_ball.h"
using namespace std;

/* Sameer Hussain - CSCE 221 – PA 1*/

        Stress_ball::Stress_ball() : color(Stress_ball_colors(rand() % 4)), size(Stress_ball_sizes(rand() % 3)) {} // random generation for the vals
                
        Stress_ball::Stress_ball(Stress_ball_colors col, Stress_ball_sizes siz) : color(col), size(siz) {}


        bool Stress_ball::operator==(const Stress_ball &c) {  // operator for getting color and size
        bool c1 = false;
        bool c2 = false;

        if (get_color() == c.get_color()) {
            c1 = true;
        }

        if (get_size() == c.get_size()) {
            c2 = true;
        }

            return c1 && c2;
        }
    
        Stress_ball_colors Stress_ball::get_color() const {

            return color;
        }

        Stress_ball_sizes Stress_ball::get_size() const {

            return size;
        }
/*
        void Stress_ball::print_stress_ball(){
            switch (get_size()) {
                case Stress_ball_sizes::small:
                    cout << "Small ";
                    break;
                case Stress_ball_sizes::medium:
                    cout << "Medium ";
                    break;
                case Stress_ball_sizes::large:
                cout << "Large ";
                    break;
            }
*/

ostream& operator << (ostream& os, const Stress_ball& sb) { // operator
    switch(sb.get_color()) {
        case Stress_ball_colors::red:
            os<<"(red, ";
            break;
        case Stress_ball_colors::blue:
            os<<"(blue, ";
            break;
        case Stress_ball_colors::yellow: 
            os<<"(yellow, ";
            break;
        case  Stress_ball_colors::green:
            os<<"green, ";
            break;
    }
    switch(sb.get_size()) {
        case  Stress_ball_sizes::small: 
            os<<"small)";
            break;
        case  Stress_ball_sizes::medium: 
            os<<"medium)";
            break;
        case  Stress_ball_sizes::large: 
            os<<"large)";
            break;
    }
    return os;
}
