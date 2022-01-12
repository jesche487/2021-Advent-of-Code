#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

int main()
{

    vector<vector<vector<int>>> cube;

    vector<int> tempx(300001); //+- 150,000
    vector<vector<int>> tempplane;


    for(int y = -150000; y < 150001; y++) {
        tempplane.push_back(tempx);
    }

    for(int z = -150000; z < 150001; z++) {
        cube.push_back(tempplane);
    }

    string line;
    ifstream myfile ("input22.txt");
    if (myfile.is_open())
    {
        int count = 0;

        while ( getline(myfile,line) )
        {
            istringstream iss(line);
            string mode;
            int xl = 0;
            int xh = 0;
            int yl = 0;
            int yh = 0;
            int zl = 0;
            int zh = 0;

            int offset = 150000;

            while(iss >> mode >> xl >> xh >> yl >> yh >> zl >> zh) {
                //if(xl > 50 || xl <-50 || yl > 50 || yl < -50) break; //skip the fat numbs for now
                cout << mode << " " << xl << " " << xh << " " << yl << " " << yh << " " << zl << " " << zh << endl;

                for(int i = xl + offset; i < xh+1 + offset; i++) {
                    for(int j = yl + offset; j < yh+1 + offset; j++) {
                        for(int k = zl + offset; k < zh+1 + offset; k++) {

                            if(mode == "on") {
                                cube[i][j][k] = 1;
                            }
                            else {
                                cube[i][j][k] = 0;
                            }
;
                        }
                    }
                }

            }
        }
        myfile.close();
    }
    
    else cout << "Unable to open file"; 

    long long count = 0;

    for(int i = 0; i < cube.size(); i++) {
        for(int j = 0; j < cube[i].size(); j++) {
            for(int k = 0; k < cube[i][j].size(); k++) {
                if(cube[i][j][k] == 1) count ++;
            }
        }
    }

    cout << endl << endl << count;

    return 0;
}
