/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> smokemap;

//fuk recursion
int findzeroes(int i, int j) {
    if(smokemap[i][j] == 9) {
        return 0;
    }
    // so it doesnt recurse back and forth
    smokemap[i][j]=9;
    return 1+findzeroes(i+1,j) + findzeroes(i,j+1) + findzeroes(i-1,j) + findzeroes(i,j-1); 
}

int main()
{

    string line;

    vector<int> tempfill;
    for(int i = 0; i < 102; i++) {
        tempfill.push_back(9);
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
            temp.push_back(9);
            while(iss >> a) {
                //cout << a << " ";
                int tempint = a-48;
                temp.push_back(tempint);
            }
            //cout << endl;
            temp.push_back(9);
            smokemap.push_back(temp);

        }
        myfile.close();
    }

    else cout << "Unable to open file"; 
    smokemap.push_back(tempfill);

    int lowpointsum = 0;
    vector<int> basinsizes;
    for(int i = 1; i < 101; i++) {
        for(int j = 1; j < 101; j++) {
            basinsizes.push_back(findzeroes(i,j));
        }        
    }

    
    sort(basinsizes.begin(), basinsizes.end());
    for(int i = 0; i < basinsizes.size(); i++) {
        if(basinsizes[i]!=0) {
            cout << basinsizes[i] << " ";
        }
    }
    
    
    return 0;
}
