/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  string line;
  
  vector<int> inputs;
  
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //cout << line << '\n';
      inputs.push_back(stoi(line));
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

    int count = 0;

    for(int i = 1; i < inputs.size(); i++) {
        if(inputs[i] > inputs[i-1]) {
            count++;
        }
    }    
    
    cout << count << endl;
}
