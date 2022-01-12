#include<bits/stdc++.h>
using namespace std; 



vector<vector<vector<int>>> rotationmatrices { {{1,0,0},{0,1,0},{0,0,1}},
                                       {{1,0,0},{0,0,-1},{0,1,0}},
                                       {{1,0,0},{0,-1,0},{0,0,-1}},
                                       {{1,0,0},{0,0,1},{0,-1,0}},
                                       {{0,-1,0},{1,0,0},{0,0,1}},
                                       {{0,0,1},{1,0,0},{0,1,0}},
                                       {{0,1,0},{1,0,0},{0,0,-1}},
                                       {{0,0,-1},{1,0,0},{0,-1,0}},
                                       {{-1,0,0},{0,-1,0},{0,0,1}},
                                       {{-1,0,0},{0,0,-1},{0,-1,0}},
                                       {{-1,0,0},{0,1,0},{0,0,-1}},
                                       {{-1,0,0},{0,0,1},{0,1,0}},
                                       {{0,1,0},{-1,0,0},{0,0,1}},
                                       {{0,0,1},{-1,0,0},{0,-1,0}},
                                       {{0,-1,0},{-1,0,0},{0,0,-1}},
                                       {{0,0,-1},{-1,0,0},{0,1,0}},
                                       {{0,0,-1},{0,1,0},{1,0,0}},
                                       {{0,1,0},{0,0,1},{1,0,0}},
                                       {{0,0,1},{0,-1,0},{1,0,0}},
                                       {{0,-1,0},{0,0,-1},{1,0,0}},
                                       {{0,0,-1},{0,-1,0},{-1,0,0}},
                                       {{0,-1,0},{0,0,1},{-1,0,0}},
                                       {{0,0,1},{0,1,0},{-1,0,0}},
                                       {{0,1,0},{0,0,-1},{-1,0,0}} };



struct Coord {
    Coord(int xcoord, int ycoord, int zcoord) {
        x = xcoord;
        y = ycoord;
        z = zcoord;
    }

    bool operator== (Coord const &c) const {
        return x == c.x && y == c.y && z == c.z;
    }

    int x;
    int y; 
    int z;
};

struct Beacon {
    Beacon(int x, int y, int z) : pos(x,y,z) {
        //default
        ID = 0;
    }

    bool operator== (Beacon const &b) const {
        return pos == b.pos;
    }

    bool operator< (Beacon const &b) const {
        return pos.x < b.pos.x;
    }

    Coord pos;
    int ID;
};

template<>
struct std::hash<Beacon>
{
    std::size_t operator()(Beacon const& b) const noexcept
    {
        std::size_t h1 = std::hash<int>{}(b.pos.x);
        std::size_t h2 = std::hash<int>{}(b.pos.y); 
        std::size_t h3 = std::hash<int>{}(b.pos.z);
        return h1 ^ h2 ^ h3; 
    }
};

ostream& operator<<(ostream& out, Beacon& b) {
    out << "(" << b.pos.x << "," << b.pos.y << "," << b.pos.z << ")";

    return out;
}

struct Scanner {
    Scanner(int size) { beaconno = size; }

    void add_beacon(Beacon b) { beacons.push_back(b);} 

    void print() {
        for(int i = 0; i < beacons.size(); i++) {
            cout << "(" << beacons[i].pos.x << "," 
                        << beacons[i].pos.y << ","
                        << beacons[i].pos.z << ")" << " "; 
        }
    }

    void idgen() { 
        int arbnum = 160; 

        for(int i = 0; i < beacons.size(); i++) {
            if(beacons[i].pos.x > - 1000 + arbnum && beacons[i].pos.x < 1000 - arbnum && 
               beacons[i].pos.y > - 1000 + arbnum && beacons[i].pos.y < 1000 - arbnum &&
               beacons[i].pos.z > - 1000 + arbnum && beacons[i].pos.z < 1000 - arbnum) {
                    //arbitrary 200, change if needed
                    int code = 0; 

                    int beaconsinrange = 0;

                    for(int j = 0; j < beacons.size(); j++) {
                        if(beacons[j].pos.x > beacons[i].pos.x -arbnum && beacons[j].pos.x < beacons[i].pos.x +arbnum &&
                        beacons[j].pos.y > beacons[i].pos.y -arbnum && beacons[j].pos.y < beacons[i].pos.y +arbnum &&
                        beacons[j].pos.z > beacons[i].pos.z -arbnum && beacons[j].pos.z < beacons[i].pos.z +arbnum) {
                            code += pow(beacons[j].pos.x - beacons[i].pos.x,2) + 
                                    pow(beacons[j].pos.y - beacons[i].pos.y,2) + 
                                    pow(beacons[j].pos.z - beacons[i].pos.z,2); 
                            beaconsinrange++;
                        }
                    }

                    if(beaconsinrange == 2) {
                        continue;
                    }

                    //arbitrary BEEG prime numbor
                    //code %= 611953;
                    beacons[i].ID = code;
            }
        }
    }

    vector<int> idprint() {
        vector<int> IDS;

        for(int i = 0; i < beacons.size(); i++) {
            IDS.push_back(beacons[i].ID);
        }
        
        return IDS;
    }

    int beaconno;
    int code;
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

    // cout << "made it here" << endl;

    // for(int i = 0; i < scanners.size(); i++) {
        // cout << i << " ";
        // scanners[i].print();
        // cout << endl;
    // }

    //generates ID for each beacon in each scanner
    for(int i = 0; i < scanners.size(); i++) {
            scanners[i].idgen();
            vector<int> temp = scanners[i].idprint();
            sort(temp.begin(), temp.end());
    //         for(int j = 0; j < temp.size(); j++) {
    //             cout << temp[j] << " ";
    //         }
    //         cout << endl;
    }

    // cout << "ID generated" << endl;

    

    // for(Beacon b : scanners[0].beacons) {
        // if(b.ID != 0) cout << b.ID << endl;
    // }
    // cout << endl << endl;
    // for(Beacon b : scanners[1].beacons) {
        // if(b.ID != 0) cout << b.ID << endl;
    // }

    //compare each scanner pair with zero
    vector<Beacon> matchesA;
    vector<Beacon> matchesB;
    
    unordered_set<Beacon> uniqueons; 

    for(int i = 0; i < scanners[0].beacons.size(); i++) {
        uniqueons.insert(scanners[0].beacons[i]);
    }


//change uniqueouns to hold beacons and change the foor loop to compare w uniquons
//pick one with most mathces
//array of visited?
    vector<int> visited(scanners.size()); 
    int numvisited = 1;
    visited[0] = 1;

    int j = 0; 

    int counter = 0;

    vector<Beacon> scannerlocs;
    for(int i = 0; i < scanners.size(); i++) {
        scannerlocs.push_back(Beacon(0,0,0));
    }

    while(numvisited < scanners.size()) { //for(int j = 1; j < scanners.size(); j++) { 
        counter++; 
        if(counter > 3000) break;

        j = (j+1) % scanners.size();
        
        if(visited[j] == 1) continue;

        // cout << "j: " << j << endl;

        matchesA.clear();
        matchesB.clear();
        //compare beacon IDS, if match, use to find other information
        for(auto a : uniqueons) {
            for(int b = 0; b < scanners[j].beacons.size(); b++) {
                if(a.ID == scanners[j].beacons[b].ID && scanners[j].beacons[b].ID != 0) {
                    // cout << scanners[0].beacons[a].ID << endl;
                    matchesA.push_back(a);
                    matchesB.push_back(scanners[j].beacons[b]);
                }
            }
        }

        vector<Beacon> matchesBcopy = matchesB; 
        int rotcount = 1;
        int finalrot = 0;
        int first = 0;
        int second = 1;

        // cout << "matched A and B: " << matchesA.size() << " " << matchesB.size() << endl;


        // if(j == 8 || j == 28) {
        //     for(int x = 0; x < matchesA.size(); x++) {
        //         cout << matchesA[x] << " " << matchesB[x] << endl;
        //     }
        // }

        if(matchesA.size() <= 1) continue;

        //if(j == 1) cout << matchesA[1] << " " << matchesB[1] << endl;
        
        //matches for scanner zero and scanner j have been found
        //matchesA and matchesB have each of their scanners aligned by same ID

        //let scanner zero be one corner, scanner j be the other
        //reorient scanner j if needed
        bool found = false; 

        while(!found) { 
            // cout << matchesBcopy[0] << endl;

            Beacon tempA = Beacon(0,0,0);
            Beacon tempB = Beacon(matchesA[first].pos.x - matchesBcopy[first].pos.x,
                                  matchesA[first].pos.y - matchesBcopy[first].pos.y, 
                                  matchesA[first].pos.z - matchesBcopy[first].pos.z); 
            
            Beacon tempC = Beacon(matchesA[second].pos.x - matchesBcopy[second].pos.x, 
                                  matchesA[second].pos.y - matchesBcopy[second].pos.y,
                                  matchesA[second].pos.z - matchesBcopy[second].pos.z);

            // cout << tempB << " " << tempC << endl;

            if(tempB.pos.x == tempC.pos.x && tempB.pos.y == tempC.pos.y && tempB.pos.z == tempC.pos.z) {
                finalrot = rotcount;
                // if(found) cout << "found twice" << endl;
                found = true;

                visited[j] = 1;
                numvisited++; 

                
                //pushback all proper nodes
            }
            else {
                // cout << "rotating" << endl;

                if(rotcount == 24) {
                    break;
                    rotcount = 0; 
                    second++;
                    if(second == matchesA.size()) {
                        first++;
                        if(first == matchesA.size()-1) {
                            rotcount = 24;
                            break;
                        }
                        second = first + 1; 
                    }
                    // cout << "first: " << first << "second: " << second <<endl;
                }

                for(int i = 0; i < matchesBcopy.size(); i++) {
                    //vector<int> temp {matchesB[i].pos.x, matchesB[i].pos.y, matchesB[i].pos.z};
                    matchesBcopy[i].pos.x = matchesB[i].pos.x * rotationmatrices[rotcount][0][0] +
                                             matchesB[i].pos.y * rotationmatrices[rotcount][0][1] +
                                             matchesB[i].pos.z * rotationmatrices[rotcount][0][2]; 

                    matchesBcopy[i].pos.y = matchesB[i].pos.x * rotationmatrices[rotcount][1][0] +
                                             matchesB[i].pos.y * rotationmatrices[rotcount][1][1] +
                                             matchesB[i].pos.z * rotationmatrices[rotcount][1][2];

                    matchesBcopy[i].pos.z = matchesB[i].pos.x * rotationmatrices[rotcount][2][0] +
                                             matchesB[i].pos.y * rotationmatrices[rotcount][2][1] +
                                             matchesB[i].pos.z * rotationmatrices[rotcount][2][2];

                }
                //cout << rotcount << endl;
                rotcount++;
            }
            
        } 

        if(rotcount == 24 && !found) {
            continue;
        }

        rotcount = finalrot -1;

        int shiftx = matchesA[0].pos.x - matchesBcopy[0].pos.x;
        int shifty = matchesA[0].pos.y - matchesBcopy[0].pos.y;
        int shiftz = matchesA[0].pos.z - matchesBcopy[0].pos.z;
        
        //now that we found soemthing
        for(int i = 0; i < scanners[j].beacons.size(); i++) {
            //if(j == 4) cout << scanners[j].beacons[i] << "->";
            vector<int> temp {scanners[j].beacons[i].pos.x, scanners[j].beacons[i].pos.y, scanners[j].beacons[i].pos.z};

            scanners[j].beacons[i].pos.x = temp[0] * rotationmatrices[rotcount][0][0] +
                                           temp[1] * rotationmatrices[rotcount][0][1] +
                                           temp[2] * rotationmatrices[rotcount][0][2] + shiftx;

            scanners[j].beacons[i].pos.y = temp[0] * rotationmatrices[rotcount][1][0] +
                                           temp[1] * rotationmatrices[rotcount][1][1] +
                                           temp[2] * rotationmatrices[rotcount][1][2] + shifty;

            scanners[j].beacons[i].pos.z = temp[0] * rotationmatrices[rotcount][2][0] +
                                           temp[1] * rotationmatrices[rotcount][2][1] +
                                           temp[2] * rotationmatrices[rotcount][2][2] + shiftz;
            //if(j == 4) cout << scanners[j].beacons[i] << endl;
          
        }
        //now in same ref frame as scanner zero
        scannerlocs[j] = Beacon(shiftx, shifty, shiftz);


        for(int i = 0; i < scanners[j].beacons.size(); i++) {
            uniqueons.insert(scanners[j].beacons[i]);
        }
            
        // cout << "size: " << uniqueons.size() << endl;
    }
    cout << "size: " << uniqueons.size() << endl;

    // vector<Beacon> vecuniques;

    // for(auto e : uniqueons) {
    //     vecuniques.push_back(e);
    // }

    // sort(vecuniques.begin(),vecuniques.end());

    // for(auto e : vecuniques) {
    //     cout << e << endl;
    // }
 
    // cout << uniqueons.size();

    // cout << endl << endl;
    // for(Beacon b : scannerlocs) {
    //     cout << b << endl;
    // }

    int largestmanhat = 0;
    for(int i = 0; i < scannerlocs.size(); i++) {
        for(int j = 0; j < scannerlocs.size(); j++) {
            if(i == j) continue;

            int tempmanhat = abs(scannerlocs[i].pos.x - scannerlocs[j].pos.x) + 
               abs(scannerlocs[i].pos.y - scannerlocs[j].pos.y) + 
               abs(scannerlocs[i].pos.z - scannerlocs[j].pos.z);

            largestmanhat = max(largestmanhat, tempmanhat);

        }
    }
    cout << largestmanhat;
    /*
    //absolute pos is scanner 0
    for(int i = 0; i < scanners[0].beacons.size(); i++) {
        FINAL.push_back(scanners[0].beacons[i]);
    }
    */
    return 0;
}
