/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

int main()
{
  string line;
  
  vector<int> inputs;

    int linecount = 0;
    int  bits[12] = {0};
  char char_array[13];

    


  ifstream myfile ("input3.txt");
  if (myfile.is_open())
  {
    while ( getline(myfile,line) )
    {
      //cout << line << endl;
      linecount++;
      cout << line.length() << endl;
        strcpy(char_array,line.c_str());
        for(int i = 0; i < line.length(); i++) {
            if(char_array[i] == '1') {
                bits[i]++;
            }
        }
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
  
  string gamma = "";
  string epsilon = "";
  
  for(auto e : bits) {
        if(1000 - e < 500) {
            gamma += "0";
            epsilon += "1";
        }
        else {
            gamma += "1";
            epsilon += "0";
        }
    }
    
    cout << gamma << " " << epsilon; //1564, 2531 = 3958484
    
    
}
