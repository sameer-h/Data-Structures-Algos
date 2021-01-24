#include <iostream>
using namespace std;

/* Sameer Hussain - CSCE 221 – PA 1*/

enum class Stress_ball_colors {  // enum for stress ball colors
    red,
    blue,
    yellow,
    green
};


enum class Stress_ball_sizes {  // enum for stress ball sizes
    small,
    medium,
    large
};

class Stress_ball {
    
    private:

        Stress_ball_colors color;

        Stress_ball_sizes size;

    public:
        Stress_ball() : color(Stress_ball_colors(rand() % 4)), size(Stress_ball_sizes(rand() % 3)) {} // random generation for the vals
        
        Stress_ball(Stress_ball_colors col, Stress_ball_sizes siz) : color(col), size(siz) {}

        Stress_ball_colors get_color() const {

            return color;
        }

        Stress_ball_sizes get_size() const {

            return size;
        }

        bool operator==(Stress_ball &c) {  // operator for getting color and size
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
};

inline
std::ostream &operator<<( std::ostream &os, const Stress_ball &sb )  
{
  switch (sb.get_color()) {
  case Stress_ball_colors::red:  // using switch statements to run through the different cases of color/size and outputting
      os << "(red,";
      break;
  case Stress_ball_colors::blue:
      os << "(blue,";
      break;
  case Stress_ball_colors::yellow:
      os << "(yellow,";
      break;
  case Stress_ball_colors::green:
      os << "(green,";
  }

    switch(sb.get_size()) {
        case Stress_ball_sizes::small:
            os << "small)";
            break;
        case Stress_ball_sizes::medium:
            os << "medium)";
            break;
        case Stress_ball_sizes::large:
            os << "large)";
            break;
    }

  return os; // returning os which has both color and size
}

int main()
{
    // setting a stress ball
    Stress_ball s1(Stress_ball_colors::red, Stress_ball_sizes::small);
    

    //printing stress ball
    cout << s1;

    return 0;
}
