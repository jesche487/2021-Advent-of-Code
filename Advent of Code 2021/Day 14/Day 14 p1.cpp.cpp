/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}


int main()
{

    string line;
    
    //HBCHSNFFVOBNOFHFOBNO
    string initialpoly = "HBCHSNFFVOBNOFHFOBNO";

    vector<char> polymer;
    for(int i = 0; i < initialpoly.length(); i++) {
        polymer.push_back(initialpoly[i]);
    }
    
    vector<string> pairs;
    vector<char> inserts;

    ifstream myfile ("input14.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            string a;
            string b;
            char c;
            istringstream iss(line);
            while(iss >> a >> b >> c) {
                //cout << a << " || " << c << endl;//<< b << c << endl;
                pairs.push_back(a);
                inserts.push_back(c);
            }

        }
        myfile.close();
    }
    
    else cout << "Unable to open file"; 
    
    //vector<char> temppolymer;

    //vector<char> temppolymer = polymer;
    // first - index in polymer, second - which letter to insert in from inserts vec
    vector<pair<int,int>> insertinstructions;
    
    for(int a = 0; a < 40; a++) {
        
        //checks for all instructions that can be done
        for(int i = 0; i < pairs.size(); i++) {
            for(int j = 0; j < polymer.size()-1; j++) {
                if(pairs[i][0] == polymer[j] && pairs[i][1] == polymer[j+1]) {
                    //cout << pairs[i] << endl;
                    insertinstructions.push_back(make_pair(j,i));
                }
            }
        }
    
        //inserting based off saved instructions
        for(int i = 0; i < insertinstructions.size(); i++) {
            polymer.insert(polymer.begin()+insertinstructions[i].first + 1, inserts[insertinstructions[i].second]);
            for(int j = 0; j < insertinstructions.size(); j++) {
                if(insertinstructions[j].first > insertinstructions[i].first) {
                    insertinstructions[j].first++;
                }
            }
        }
        
        //reset
        insertinstructions.clear();
    }
    
     /*
    cout << endl;
    for(int i = 0; i < insertinstructions.size(); i++) {
        cout << insertinstructions[i].first;
    }
    
    cout << endl;
    for(int i = 0; i < polymer.size(); i++) {
        cout << polymer[i];
    }
    */
    
    
    //first - letter number in alphabet, second - number of times it appears
    vector<pair<char,int>> lettercount;
    char letter = 'A';
    
    for(int i = 0; i < 26; i++) {
        lettercount.push_back(make_pair(letter+i,0));
    }
    
    for(int i = 0; i < polymer.size(); i++) {
        for(int j = 0; j < lettercount.size(); j++) {
            if(lettercount[j].first == polymer[i]) {
                lettercount[j].second++;
            }
        }
    }
    
    sort(lettercount.begin(), lettercount.end(), sortbysec);
    
    int smallest = 0;
    for(int i = 0; i < lettercount.size(); i++) {
        if(lettercount[i].second != 0) {
            smallest = lettercount[i].second;
            break;
        }
    }
    
    cout << lettercount[25].second - smallest;
    
    
    return 0;
}
