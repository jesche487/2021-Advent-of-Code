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
    //initialize big diagram
    vector<vector<int>> diagram;
    
    for(int i = 0; i < 1000; i++) {
        vector<int> row;
        for(int j = 0; j < 1000; j++) {
            row.push_back(0);
        }
        diagram.push_back(row);
    }

    string line;

    ifstream myfile ("input5.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            //cout << line << endl;
            istringstream iss(line);
            int a, b, c, d;
            while(iss >> a >> b >> c >> d) {
                cout << a << " " << b << " " << c << " " << d << endl;
                //if diag
                if(a-c != 0 && b-d != 0) {
                    if(a < c && b < d) {
                        for(int i = 0; i < c-a+1; i++) {
                            diagram[a+i][b+i]++;
                        }
                    }
                    else if(a < c && b > d) {
                        for(int i = 0; i < c-a+1; i++) {
                            diagram[a+i][b-i]++;
                        }
                    }
                    else if(a > c && b < d) {
                        for(int i = 0; i < a-c+1; i++) {
                            diagram[a-i][b+i]++;
                        }
                    }
                    else if(a > c && b > d) {
                        for(int i = 0; i < a-c+1; i++) {
                            diagram[a-i][b-i]++;
                        }
                    }
                }
                //vert
                else if(a-c == 0) {
                    if(b < d) {
                        for(int i = b; i < d+1; i++) {
                            diagram[a][i]++;
                        }
                    }
                    else {
                        for(int i = d; i < b+1; i++) {
                            diagram[a][i]++;
                        }
                    }
                }
                //if horiz
                else {
                    if(a < c) {
                        for(int i = a; i < c+1; i++) {
                            diagram[i][b]++;
                        }
                    }
                    else {
                        for(int i = c; i < a+1; i++) {
                            diagram[i][b]++;
                        }
                    }
                }
                
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 

    int count = 0;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            if(diagram[i][j]>=2) count++;
        }
    }
    cout << count << endl;
    

    return 0;
}
