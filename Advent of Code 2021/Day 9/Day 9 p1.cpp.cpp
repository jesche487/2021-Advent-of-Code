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

    vector<vector<int>> smokemap;
    
    vector<int> tempfill;
    for(int i = 0; i < 102; i++) {
        tempfill.push_back(1000);
    }
    smokemap.push_back(tempfill);
    

    ifstream myfile ("input9.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            istringstream iss(line);
            vector<int> temp;
            char a;
            temp.push_back(1000);
            while(iss >> a) {
                cout << a << " ";
                int tempint = a-48;
                temp.push_back(tempint);
            }
            cout << endl;
            temp.push_back(1000);
            smokemap.push_back(temp);

        }
        myfile.close();
    }

    else cout << "Unable to open file"; 
    smokemap.push_back(tempfill);

    for(int i = 0; i < smokemap.size(); i++) {
        for(int j = 0; j < smokemap[i].size(); j++){
            cout << smokemap[i][j] << " ";
        }
        cout << endl;
    }
    
    int lowpointsum = 0;
    for(int i = 1; i < 101; i++) {
        for(int j = 1; j < 101; j++) {
            if(smokemap[i+1][j] > smokemap[i][j] && smokemap[i][j+1] > smokemap[i][j] 
            && smokemap[i-1][j] > smokemap[i][j] && smokemap[i][j-1] > smokemap[i][j]) {
                lowpointsum += smokemap[i][j] +1;
            }
            
        }        
    }

    cout << endl << lowpointsum;
    return 0;
}
