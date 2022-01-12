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

    int ones = 0;
    int fours = 0;
    int sevens = 0;
    int eights = 0;

    vector<string> words;

    ifstream myfile ("input8.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            istringstream iss(line);
            string a;
            while(iss >> a) {
                words.push_back(a);
            }

        }
        myfile.close();
    }

    else cout << "Unable to open file"; 

    for(int i = 0; i < words.size(); i++) {
        if(words[i]=="|") {
            for(int j = 1; j <= 4; j++) {
                if(words[i+j].length() == 2) ones++;
                else if(words[i+j].length() == 4) fours++;
                else if(words[i+j].length() == 3) sevens++;
                else if(words[i+j].length() == 7) eights++;
            }
        }
    }

    cout << ones << " " << fours << " " << sevens << " " << eights;
    cout << endl << ones + fours + sevens + eights;
    
    return 0;
}
