/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

vector <string> globalcaves;

int main()
{

    string line;
    
    ifstream myfile ("input12.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            istringstream iss(line);
            string a;
            while(iss >> a) {
                //cout << a << endl;
                if (find(globalcaves.begin(), globalcaves.end(), a) == globalcaves.end()) {
                    globalcaves.push_back(a);
                }
            }
        
            
        }
        myfile.close();
    }
    
    else cout << "Unable to open file"; 

    for(int i = 0; i < globalcaves.size(); i++) {
        cout << i << " " << globalcaves[i] << endl;
    }
   
    Graph g(13,globalcaves);
    //xz-end
    g.add_edge(0,1);
    g.add_edge(1,0);
    //CJ-pt
    g.add_edge(2,3);
    g.add_edge(3,2);
    //pt-QW
    g.add_edge(3,4);
    g.add_edge(4,3);
    //hn-SP
    g.add_edge(5,6);
    g.add_edge(6,5);
    //pw-CJ
    g.add_edge(7,2);
    g.add_edge(2,7);
    //SP-end
    g.add_edge(6,1);
    g.add_edge(1,6);
    //hn-pt
    g.add_edge(5,3);
    g.add_edge(3,5);
    //GK-nj
    g.add_edge(8,9);
    g.add_edge(9,8);
    //fe-nj
    g.add_edge(10,9);
    g.add_edge(9,10);
    //CJ-nj
    g.add_edge(2,9);
    g.add_edge(9,2);
    //hn-ZZ
    g.add_edge(5,11);
    g.add_edge(11,5);
    //hn-start
    g.add_edge(5,12);
    g.add_edge(12,5);
    //hn-fe
    g.add_edge(5,10);
    g.add_edge(10,5);
    //ZZ-fe
    g.add_edge(11,10);
    g.add_edge(10,11);
    //SP-nj
    g.add_edge(6,9);
    g.add_edge(9,6);
    //SP-xz
    g.add_edge(6,0);
    g.add_edge(0,6);
    //ZZ-pt
    g.add_edge(11,3);
    g.add_edge(3,11);
    //nj-ZZ
    g.add_edge(9,11);
    g.add_edge(11,9);
    //start-ZZ
    g.add_edge(12,11);
    g.add_edge(11,12);
    //hn-GK
    g.add_edge(5,8);
    g.add_edge(8,5);
    //CJ-end
    g.add_edge(2,1);
    g.add_edge(1,2);
    //start-fe
    g.add_edge(12,10);
    g.add_edge(10,12);
    //CJ-xz
    g.add_edge(2,0);
    g.add_edge(0,2);
    
    g.print();
    
    //cave search from start == 12
    g.set_special("xz");
    g.cave_search(12);

    
    g.set_special("pt");
    g.cave_search(12);

    g.set_special("hn");
    g.cave_search(12);

    g.set_special("pw");
    g.cave_search(12);

    g.set_special("nj");
    g.cave_search(12);

    g.set_special("fe");
    g.cave_search(12);
    

    cout << "end of program";
    g.print();
    
    return 0;
}
