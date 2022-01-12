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

    vector<vector<string>> board;

    ifstream myfile ("input25.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            vector<string> temp;

            for(int i = 0; i < line.length(); i++) {
                string str = "";
                str += line[i];
                temp.push_back(str);
            }
            
            board.push_back(temp);

        }
        myfile.close();
    }
    else cout << "Unable to open file"; 

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

    
    bool moved = false;

    int day = 0;

    while(true) {
        day += 1;
        moved = false;

        //right over down

        //moves right ones first
        vector<vector<string>> tempboard = board;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == ">") {
                    if(board[i][(j+1)% board[i].size()] == ".") {
                        tempboard[i][(j+1)% board[i].size()] = ">";
                        tempboard[i][j] = ".";
                        moved = true;
                    }
                }

            }
        }

        //moves left ones next
        vector<vector<string>> tempboard2 = tempboard;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(tempboard[i][j] == "v") {
                    if(tempboard[(i+1)% board.size()][j] == ".") {
                        tempboard2[(i+1)% board.size()][j] = "v";
                        tempboard2[i][j] = ".";
                        moved = true;
                    }
                }

            }
        }
        
        if(moved == false) {
            break;
        }

        board = tempboard2;
    }


    cout << endl << endl;

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

    cout << endl << day;


    return 0;
}
