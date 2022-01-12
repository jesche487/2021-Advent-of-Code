/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string line;

    vector<int> initialpos;
    
    ifstream myfile ("input7.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            istringstream iss(line);
            int a;
            while(iss >> a) {
                initialpos.push_back(a);
            }
            
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 

    sort(initialpos.begin(),initialpos.end());

    for(int i = 0; i < initialpos.size(); i++) {
        cout << initialpos[i] << " ";
    }
    cout << endl;
    
    int median = (initialpos[499] + initialpos[500])/2;
  
    int fuel = 0;
    for(int i = 0; i < initialpos.size(); i++) {
        fuel += abs(median-initialpos[i]);
    }
    cout << fuel;
    return 0;
}
