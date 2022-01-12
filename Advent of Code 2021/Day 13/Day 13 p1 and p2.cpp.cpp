/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dots;
int xmaximum = 1400;
int ymaximum = 1400;


void foldx(int x) {
    //hardcoded fold over x = 655
    //x direction
    for(int i = x+1; i < xmaximum; i++) {
        //y direction
        for(int j = 0; j < ymaximum; j++) {
            if(x-(i-x)>=0) {
                dots[x-(i-x)][j] += dots[i][j];
            }        
        }
    }
    
    xmaximum = x;
}

void foldy(int y) {
    //hardcoded fold over y = 447
    //x direction
    for(int i = 0; i < xmaximum; i++) {
        //y direction
        for(int j = y+1; j < ymaximum; j++) {
            if(y-(j-y)>=0) {
                dots[i][y-(j-y)] += dots[i][j];
            }        
        }
    }
    ymaximum = y;
}


int main()
{

    string line;
    
    
    vector<int> temp(1400);
    for(int i = 0; i < 1400; i++){
        dots.push_back(temp);
    }
    
    ifstream myfile ("input13.txt");
    if (myfile.is_open())
    {
        int count = 1;
        while ( getline(myfile,line) )
        {
            istringstream iss(line);
            int a;
            int b;
            char c;
            while(iss >> a >> c >> b) {
                //cout << a << endl;
                dots[a][b] = 1;
            }
            cout << "dot no. " << count << endl;
            count++;

        }
        myfile.close();
    }
    
    else cout << "Unable to open file"; 

    
    foldx(655);

    foldy(447);
   
    /*
    int dotties = 0;
    for(int i = 0; i < xmaximum; i++) {
        for(int j = 0; j < ymaximum; j++) {
            dotties+=dots[i][j];
        }
    }
    cout << dotties;
 */
    foldx(327);
    foldy(223);
    foldx(163);
    foldy(111);
    foldx(81);
    foldy(55);
    foldx(40);
    foldy(27);
    foldy(13);
    foldy(6);
   
    
    
    //cout << dotties;
    
    
    
    //check if input is workin
    //int tempie = 1;
    for(int i = 0; i < ymaximum; i++) {
        for(int j = 0; j < xmaximum; j++) {
            if(dots[j][i]>0) cout << "X";
            else cout << " ";
        }
        cout << endl;
    }
    
    

    return 0;
}
