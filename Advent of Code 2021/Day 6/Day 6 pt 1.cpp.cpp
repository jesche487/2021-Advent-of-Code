/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //initialize big diagram

    vector<int> fish;

    string line;
    
    int totalfish = 0;

    ifstream myfile ("input6.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            istringstream iss(line);
            int a;
            while(iss >> a) {
                fish.push_back(a);
            }
            
            for(int i = 0; i < 80; i++) {
                for(int j = 0; j < fish.size(); j++) {
                    if(fish[j] == 0) {
                        fish.push_back(9);
                        fish[j] = 6;
                    }
                    else {
                        fish[j]--;
                    }
                    //cout << fish[j] << " ";
                    
                }
                
                //cout << endl;
            }
            totalfish += fish.size();
            fish.clear();       
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 
  
    
    
    cout << totalfish;
    //for(int i = 0; i < fish.size(); i++) {
    //    cout << fish[i] << " ";
    //}

    return 0;
}
