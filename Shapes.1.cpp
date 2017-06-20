//Programmer: Shih-hung Pi
//Programmer's ID: 1509770

//C++ library
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//C library
#include <cmath>

float stringToFloat(string);
vector<string> parseString(string);
void square(ofstream&, float);
void rectangle(ofstream&, float, float);
void circle(ofstream&, float);
void triangle(ofstream&, float);
void cube(ofstream&, float);
void box(ofstream&, float, float, float);
void cylinder(ofstream&, float, float);
void prism(ofstream&, float, float);

int main()
{
  string input;
  ifstream infile("Shapes.input.txt");
  ofstream outfile("TXT.txt");
  if(infile.is_open())
  {
    while(getline(infile, input))
	  {
	    vector<string> tokens = parseString(input);
      if (tokens.size() > 0)
      {
        if (tokens[0] == "SQUARE")
		    {
          if (tokens.size() >= 2) 
          {
            square(outfile, stringToFloat(tokens[1]));
	        }
	        else
          {
            square(outfile, 0);
          }
        }
        else if (tokens[0] == "CIRCLE")
        {
          if (tokens.size() >= 2) 
          {
            circle(outfile, stringToFloat(tokens[1]));
          }
          else
          {
            circle(outfile, 0);
          }
        }
        else if (tokens[0] == "CUBE")
        {
          if (tokens.size() >= 2) 
          {
            cube(outfile, stringToFloat(tokens[1]));
          }
          else
          {
            cube(outfile, 0);
          }
        }
        else if (tokens[0] == "TRIANGLE")
        {
          if (tokens.size() >= 2) 
          {
            triangle(outfile, stringToFloat(tokens[1]));
          }
          else
          {
            triangle(outfile, 0);
          }
        }
        else if (tokens[0] == "RECTANGLE")
        {
          if (tokens.size() == 2) 
          {
            rectangle(outfile, stringToFloat(tokens[1]), 0);
          }
          else if (tokens.size() >= 3)
          {
            rectangle(outfile, stringToFloat(tokens[1]), stringToFloat(tokens[2]));
          }
          else
          {
            rectangle(outfile, 0, 0);
          }
        }
        else if (tokens[0] == "CYLINDER")
        {
          if (tokens.size() == 2) 
          {
            cylinder(outfile, stringToFloat(tokens[1]), 0);
          }
          else if (tokens.size() >= 3)
          {
            cylinder(outfile, stringToFloat(tokens[1]), stringToFloat(tokens[2]));
          }
          else
          {
            cylinder(outfile, 0, 0);
          }
        }
        else if (tokens[0] == "PRISM")
        {
          if (tokens.size() == 2) 
          {
            prism(outfile, stringToFloat(tokens[1]), 0);
          }
          else if (tokens.size() >= 3)
          {
            prism(outfile, stringToFloat(tokens[1]), stringToFloat(tokens[2]));
          }
          else
          {
            prism(outfile, 0, 0);
          }
        }
        else if (tokens[0] == "BOX")
        {
          if (tokens.size() == 2) 
          {
            box(outfile, stringToFloat(tokens[1]), 0, 0);
          }
          else if (tokens.size() == 3)
          {
            box(outfile, stringToFloat(tokens[1]), stringToFloat(tokens[2]), 0);
          }
          else if (tokens.size() >= 4)
          {
            box(outfile, stringToFloat(tokens[1]), stringToFloat(tokens[2]), stringToFloat(tokens[3]));
          }
          else
          {
            box(outfile, 0, 0, 0);
          }
        }
        else if (tokens[0] != "EOF")
        {
          cout << tokens[0] << " invalid object" << endl;
          outfile << tokens[0] << " invalid object" << endl;
        }	
      }
    }
    outfile.close();
  }
}

float stringToFloat(string s)
{
  float f;
  stringstream ss(s);
  ss >> f;
    
  return f;
}

vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

void square(ofstream& output, float x)
{
  cout << "SQUARE";
  cout << " side=" << x;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << " area=" << x*x;
  cout << " perimeter=" << x*4 << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
    
  output << "SQUARE";
  output << " side=" << x;
  output.setf(ios::fixed);
  output.precision(2);
  output << " area=" << x*x;
  output << " perimeter=" << x*4 << endl;
  output.unsetf(ios::fixed);
  output.precision(6);
}

void rectangle(ofstream& output, float x, float y)
{
  cout << "RECTANGLE";
  cout << " length=" << x;
  cout << " width=" << y;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << " area=" << x*y;
  cout << " perimeter=" << 2*(x+y) << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
    
  output << "RECTANGLE";
  output << " length=" << x;
  output << " width=" << y;
  output.setf(ios::fixed);
  output.precision(2);
  output << " area=" << x*y;
  output << " perimeter=" << 2*(x+y) << endl;
  output.unsetf(ios::fixed);
  output.precision(6);
}

void circle(ofstream& output, float x)
{
  double pi = 3.1415926535897;
    
  cout << "CIRCLE";
  cout << " radius=" << x;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << " area=" << pi*pow(x,2);
  cout << " perimeter=" << 2*pi*x << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
   
  output << "CIRCLE";
  output << " radius=" << x;
  output.setf(ios::fixed);
  output.precision(2);
  output << " area=" << pi*pow(x,2);
  output << " perimeter=" << 2*pi*x << endl;
  output.unsetf(ios::fixed);
  output.precision(6);
}

void triangle(ofstream& output, float x)
{
  cout << "TRIANGLE";
  cout << " side=" << x;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << " area=" << x*sqrt(3)*x/4;
  cout << " perimeter=" << 3*x << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
    
  output << "TRIANGLE";
  output << " side=" << x;
  output.setf(ios::fixed);
  output.precision(2);
  output << " area=" << x*sqrt(3)*x/4;
  output << " perimeter=" << 3*x << endl;
  output.unsetf(ios::fixed);
  output.precision(6);
}

void cube(ofstream& output, float x)
{
  cout << "CUBE";
  cout << " side=" << x;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << " surface area=" << x*x*6;
  cout << " volume=" << pow(x,3) << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
    
  output << "CUBE";
  output << " side=" << x;
  output.setf(ios::fixed);
  output.precision(2);
  output << " surface area=" << x*x*6;
  output << " volume=" << pow(x,3) << endl;
  output.unsetf(ios::fixed);
  output.precision(6);
}

void box(ofstream& output, float l, float w, float h)
{
  cout << "BOX";
  cout << " length=" << l;
  cout << " width=" << w;
  cout << " height=" << h;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << " surface area=" << 2*(l*w)+2*(w*h)+2*(l*h);
  cout << " volume=" << l*w*h << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
    
  output << "BOX";
  output << " length=" << l;
  output << " width=" << w;
  output << " height=" << h;
  output.setf(ios::fixed);
  output.precision(2);
  output << " surface area=" << 2*(l*w)+2*(w*h)+2*(l*h);
  output << " volume=" << l*w*h << endl;
  output.unsetf(ios::fixed);
  output.precision(6);
}

void cylinder(ofstream& output, float r, float h)
{
  double pi = 3.1415926535897;
  cout << "CYLINDER";
  cout << " radius=" << r;
  cout << " height=" << h;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << " surface area=" << 2*pi*r*h+2*pi*pow(r,2);
  cout << " volume=" << pi*pow(r,2)*h << endl;
  cout.unsetf(ios::fixed);
  cout.precision(6);
    
  output << "CYLINDER";
  output << " radius=" << r;
  output << " height=" << h;
  output.setf(ios::fixed);
  output.precision(2);
  output << " surface area=" << 2*pi*r*h+2*pi*pow(r,2);
  output << " volume=" << pi*pow(r,2)*h << endl;
  output.unsetf(ios::fixed);
  output.precision(6);
}

void prism(ofstream& output, float x, float y)
{
  cout << "PRISM";
  cout << " side=" << x;
  cout << " height=" << y;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout << " surface area=" << x*sqrt(3)*x/2+3*x*y;
  cout << " volume=" << x*sqrt(3)*x/4*y;
  cout.unsetf(ios::fixed);
  cout.precision(6);
    
  output << "PRISM";
  output << " side=" << x;
  output << " height=" << y;
  output.setf(ios::fixed);
  output.precision(2);
  output << " surface area=" << x*sqrt(3)*x/2+3*x*y;
  output << " volume=" << x*sqrt(3)*x/4*y;
  output.unsetf(ios::fixed);
  output.precision(6);
}