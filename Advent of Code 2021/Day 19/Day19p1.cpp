#include<bits/stdc++.h>
using namespace std;

struct Coord {
    Coord(int xcoord, int ycoord, int zcoord) {
        x = xcoord;
        y = ycoord;
        z = zcoord;
    }

    int x;
    int y;
    int z;
};

struct Beacon {
    Beacon(int x, int y, int z) {
        pos = new Coord(x,y,z);
        //default
        orientation = new Coord(1,1,1);
    }

    Coord* pos;
    Coord* orientation;
};

struct Scanner {
    Scanner(int size) { beaconno = size; }

    void add_beacon(Beacon b) { beacons.push_back(b);}

    void print() {
        for(int i = 0; i < beacons.size(); i++) {
            cout << "(" << beacons[i].pos->x << "," 
                        << beacons[i].pos->y << ","
                        << beacons[i].pos->z << ")" << " ";
        }
    }

    int beaconno;
    vector<Beacon> beacons;
};


int main()
{
    string line;

    vector<Scanner> scanners;
    vector<Beacon> temp;

    ifstream myfile ("input19.txt");
    if (myfile.is_open())
    {
        int a;
        int b;
        int c;
        char ch;

        bool newscanner = false;

        while ( getline(myfile,line) )
        {
            if(line == "") newscanner = true;
            else {
                if(line[0] == '-' && line[1] == '-' && line[2] == '-') continue;
                istringstream iss(line);
                iss >> a >> ch >> b >> ch >> c;
                //cout << a << " " << b << " " << c << endl;

                Beacon beac(a, b, c);
                temp.push_back(beac);
            }

            if(newscanner) {
                //cout << "cirnge" << endl;
                Scanner scann(temp.size());
                for(int i = 0; i < temp.size(); i++) {
                    scann.add_beacon(temp[i]);
                }
                
                //scann.print();
                scanners.push_back(scann);

                temp.clear();
                newscanner = false;
            }
        }


        myfile.close();
    }
    else cout << "Unable to open file"; 

    cout << "made it here" << endl;
    for(int i = 0; i < scanners.size(); i++) {
        scanners[i].print();
        cout << endl;
    }

    //absolute pos is scanner 0


    return 0;
}
