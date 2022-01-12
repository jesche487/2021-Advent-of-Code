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
    //numbers to call
    int arr[100] = {23,91,18,32,73,14,20,4,10,55,40,29,13,25,48,65,2,80,22,16,93,85,66,21,9,36,47,72,88,58,5,42,53,69,52,8,54,63,76,12,6,99,35,95,82,49,41,17,62,34,51,77,94,7,28,71,92,74,46,79,26,19,97,86,87,37,57,64,1,30,11,96,70,44,83,0,56,90,59,78,61,98,89,43,3,84,67,38,68,27,81,39,15,50,60,24,45,75,33,31};

    string line;
    //holds each bingo board, each element is a board
    // a board is a vector of vectors, index 0 = row 0, index 1 = row 1 etc.
    vector<vector<vector<int>>> boards;

    int boardno = 0;
    int row = 0;
    int rowind = 0;
  
    cout << "ready" << endl;
    
        vector<vector<int>> board (5,vector<int>(5));
        
        while ( getline(cin,line) )
        {
            if(line == "-1") break;
            //cout << line << endl;
            istringstream iss(line);
            int a, b, c, d, e;
            while(iss >> a >> b >> c >> d >> e) {
                board[row][0] = a;
                board[row][1] = b;
                board[row][2] = c;
                board[row][3] = d;
                board[row][4] = e;
            }
            row++;
            if (row == 5) {
                row = 0;
                getline(cin,line); //empty line
                boards.push_back(board);
            }
        }

    cout << "test" << endl;
    
    //input works
    for(int a = 0; a < boards.size(); a++) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cout << boards[a][i][j] << " ";
            } 
            cout << endl;
        }
        cout << endl;
    }

    //brute force each board one by one
    vector<pair<int,int>> endscores;
    int count = 0;
    bool win = false;
    for(int a = 0; a < boards.size(); a++) {
        while(count < 100) {  
            
            if(win) break;
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(arr[count] == boards[a][i][j]) {
                        boards[a][i][j] = 100;
                    }
                }
            }
            
            //check horiz
            if(win) break;
            for(int i = 0; i < 5; i++) {
                if(boards[a][i][0] == boards[a][i][1] && boards[a][i][0] == boards[a][i][2] && boards[a][i][0] == boards[a][i][3] && boards[a][i][0] == boards[a][i][4]) {
                    endscores.push_back(make_pair(count+1,arr[count]));
                    win = true;
                    break;
                }
            }
            
            
            //check vert
            if(win) break;
            for(int i = 0; i < 5; i++) {
                if(boards[a][0][i] == boards[a][1][i] && boards[a][0][i] == boards[a][2][i] && boards[a][0][i] == boards[a][3][i] && boards[a][0][i] == boards[a][4][i]) {
                    endscores.push_back(make_pair(count+1,arr[count]));
                    win = true;
                    break;
                }
            }
            count++;
        }
        count = 0;
        win = false;
    }

    for(int i = 0; i <endscores.size(); i++) {
        cout << endscores[i].first << " " << endscores[i].second << endl;
    }
    
    int smallest = 0;
    for(int i = 1; i < endscores.size(); i++) {
      if(endscores[i].first < endscores[smallest].first) smallest = i;
    }
    
    cout << smallest << " " << endscores[smallest].first << " " << endscores[smallest].second << endl;

    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        cout << boards[smallest][i][j] << " ";
      }
      cout << endl;
    }

    return 0;
}
