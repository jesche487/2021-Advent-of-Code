#include <bits/stdc++.h>
using namespace std;



int main()
{
    //p1pos, p2pos, p1score, p2score
    vector<vector<vector<vector<long long>>>> gamestate(10, vector<vector<vector<long long>>>(10, vector<vector<long long>>(22, vector<long long>(22))));

    //uisng zero index
    gamestate[3][7][0][0] = 1;

    long long gamesnotdone = 1;

    while(gamesnotdone != 0) {

        for(int a = 0; a < 10; a++) {
            for(int b = 0; b < 10; b++) {
                for(int c = 0; c < 21; c++) {
                    for(int d = 0; d < 21; d++) {
                        vector<int> rolls = {1, 3, 6, 7, 6, 3, 1};  

                        //p1
                        for(int i = 0; i < rolls.size(); i++) { 
                            //p2
                            for(int j = 0; j < rolls.size(); j++) {
                                int p1pos = a;
                                int p2pos = b;

                                p1pos += i +3;
                                while(p1pos > 9) {
                                    p1pos -= 10;
                                }

                                p2pos += j +3;
                                while(p2pos > 9) {
                                    p2pos -= 10;
                                }

                                int p1score = c + p1pos + 1;
                                int p2score = d + p2pos + 1;

                                if(p1score >= 21) {
                                    gamestate[p1pos][p2pos][21][d] += rolls[i] * gamestate[a][b][c][d]; 
                                    break;
                                } 

                                if(p2score >= 21) gamestate[p1pos][p2pos][c][21] += rolls[i] * rolls[j] * gamestate[a][b][c][d]; 
                                else {
                                    gamestate[p1pos][p2pos][p1score][p2score] += rolls[i] * rolls[j] * gamestate[a][b][c][d];
                                    gamesnotdone += rolls[i] * rolls[j] * gamestate[a][b][c][d];
                                }
                            }
                        }

                        gamesnotdone -= gamestate[a][b][c][d];
                        gamestate[a][b][c][d] = 0;

                    }
                }
            }
        }

    }

    long long p1wins = 0;
    long long p2wins = 0;


    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 21; k++) {
                p1wins += gamestate[i][j][21][k];
                p2wins += gamestate[i][j][k][21];
            }
        }
    }

    cout << p1wins << " " << p2wins << endl;

    return 0;
}
