/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
  string line;
  
  vector<int> inputs;
  
  string direction;
  int value = 0;
  
  int horizPos = 0;
  int depth = 0;
  int aim = 0;
  
  ifstream myfile ("input2.txt");
  if (myfile.is_open())
  {
    while ( myfile >> direction >> value )
    {
    //  cout << line << endl;
      if(direction == "forward") {
          horizPos += value;
          depth += aim*value;
      }
      else if(direction == "up") {
          aim -= value;
      }
      else if(direction == "down") {
          aim += value;
      }
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

    cout << horizPos << " " << depth << endl;
    cout << horizPos * depth << endl;

}
