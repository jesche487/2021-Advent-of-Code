#include <bits/stdc++.h>
using namespace std;


int main()
{
    // string line;

    // ifstream myfile ("input20.txt");
    // if (myfile.is_open())
    // {
    //     int count = 0;

    //     while ( getline(myfile,line) )
    //     {
    //         cout << line << endl;
    //     }
    //     myfile.close();
    // }
    
    // else cout << "Unable to open file"; 

    int p1pos = 3;
    int p2pos = 4;

    int p1score = 0;
    int p2score = 0;

    int diceroll = 1;

    int rollcount = 0;
    int alternate = true;
   while(p1score < 21 && p2score < 21) {
        if(alternate) {
            for(int i = 0; i < 3; i++) {
                p1pos += diceroll;
                diceroll++;
                if(diceroll == 101) diceroll -= 100;
            }

            while(p1pos > 10) {
                p1pos -= 10;
            }
            p1score += p1pos;

            cout << "p1score: " << p1score << "\t";
            alternate = false;
        }
        else {
            for(int i = 0; i < 3; i++) {
                p2pos += diceroll;
                diceroll++;
                if(diceroll == 101) diceroll -= 100;
            }

            while(p2pos > 10) {
                p2pos -= 10;
            }
            p2score += p2pos;

            cout << "p2score: " << p2score << endl;
            alternate = true;
        }
        rollcount++;
    }

    cout << rollcount << " " << diceroll << " " << p1score << " " << p2score << endl;

    return 0;
}
