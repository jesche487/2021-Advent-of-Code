/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> counts (9);
    

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
                counts[a]++;
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 

    for(int i = 0; i < counts.size(); i++) {
        cout << counts[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 256; i++) {
        long long temp = counts[0];
        for(int j = 0; j < counts.size(); j++) {
            counts[j]=counts[j+1];
        }
        counts[counts.size()-1] = temp;
        
        counts[6]+=counts[8];
    }

    long long sum = 0;
    for(int i = 0; i < counts.size(); i++) {
        sum += counts[i];
    }
    cout << endl;

    cout << sum;

    return 0;
}
