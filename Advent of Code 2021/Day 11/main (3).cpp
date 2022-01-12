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
    
    vector<vector<int>> octos;
  
    ifstream myfile ("input11.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            istringstream iss(line);
            vector<int> temp;
            char a;
            while(iss >> a) {
                //cout << a << " ";
                int tempint = a-48;
                temp.push_back(tempint);
            }
            //cout << endl;
            octos.push_back(temp);

        }
        myfile.close();
    }

    else cout << "Unable to open file"; 

    //displays initial
    for(int a = 0; a < octos.size(); a++) {
        for(int i = 0; i < octos[a].size(); i++) {
            cout << setw(3) << octos[a][i] << " ";
        }
        cout << endl;
    }

    bool allflash = false;
    int flashday = 0;
    int flashcounter = 0;
    int day = 0;
    
    int sum = 0;

    bool flashed = false;


    while(!allflash) {//for(int day = 0; day < 5000; day++) {
        for(int i = 0; i < octos.size(); i++) {
            for(int j = 0; j < octos.size(); j++) {
                octos[i][j]++;
            }
        }

        flashed = false;

        while(!flashed) {
            for(int i = 0; i < octos.size(); i++) {
                for(int j = 0; j < octos.size(); j++) {
                    if(octos[i][j] > 9) {
                        octos[i][j] = 0;
                        sum++;
                        
        
                        //do the surrounding flashes
                        for(int changex = -1; changex <= 1; changex++) {
                            for(int changey = -1; changey <= 1; changey++) {
                                //check if exists
                                if(changex + i >=0 && changex + i < octos.size() && changey + j >=0 && changey + j < octos.size()) {
                                    if(octos[changex+i][changey+j] != 0) {
                                        octos[changex+i][changey+j]++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
    
            flashed = true;
    
            for(int i = 0; i < octos.size(); i++) {
                for(int j = 0; j < octos.size(); j++) {
                    if(octos[i][j] > 9) {
                        flashed = false;
                    }
                }
            }
        }
        
        for(int i = 0; i < octos.size(); i++) {
            for(int j = 0; j < octos.size(); j++) {
                if(octos[i][j] == 0) {
                    flashcounter++;
                }
            }
        }  
                    
        day++;            
    
        if(flashcounter == 100) {
            allflash = true;
            flashday = day;
        }
        else {
            cout << flashcounter << endl;
            flashcounter = 0;
        }

    }    
    
    cout << endl << endl << flashday;


    return 0;
}
