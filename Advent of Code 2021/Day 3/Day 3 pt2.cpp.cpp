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
    string line;
  
    vector<int> inputs;

    int linecount = 0;
    int  bits[12] = {0};
    char char_array[13];

    
    vector<string> v1;
    vector<string> v2;
    


    ifstream myfile ("input3.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            //cout << line << endl;
            linecount++;
//            cout << line.length() << endl;
       
            v1.push_back(line);
            v2.push_back(line);
            strcpy(char_array,line.c_str());

            for(int i = 0; i < line.length(); i++) {
                if(char_array[i] == '1') {
                    bits[i]++;
                }
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 
  
    string gamma = "";
    string epsilon = "";
  
    for(auto e : bits) {
        if(1000 - e < 500) {
            gamma += "0";
            epsilon += "1";
        }
        else {
            gamma += "1";
            epsilon += "0";
        }
    }
    
//    cout << gamma << " " << epsilon <<endl; //1564, 2531 = 3958484
    
    for(int i = 0; i < 12; i++) {
        int mostcommon = 0;
        for(int j = 0; j < v1.size(); j++) {
            if(v1[j][i] == '1') { mostcommon++; }
        }
        
        if( mostcommon*2 > v1.size()) {
            mostcommon = 1;
        }
        else if( mostcommon*2 == v1.size()) {
            mostcommon = 1;
        }
        else {
            mostcommon = 0;
        }
        
        for(int j = 0; j < v1.size(); j++) {
            if(v1[j][i] != mostcommon+'0') { v1.erase(v1.begin() + j); j--; } // erasing a vector messes this up, so j-- to fix it
        }
        
        if(v1.size() == 1){
            break;
        }
    }
  
    cout << "hello" << endl;
    for(auto e : v1) {
        cout << e << endl;
    }

    
    for(int i = 0; i < 12; i++) {
        int mostcommon = 0;
        for(int j = 0; j < v2.size(); j++) {
            if(v2[j][i] == '1') { mostcommon++; }
        }
        
        if( mostcommon*2 > v2.size()) {
            mostcommon = 0;
        }
        else if( mostcommon*2 == v2.size()) {
            mostcommon = 0;
        }
        else {
            mostcommon = 1;
        }
        
        for(int j = 0; j < v2.size(); j++) {
            if(v2[j][i] != mostcommon+'0') { v2.erase(v2.begin() + j); j--; } // erasing a vector messes this up, so j-- to fix it
        }
        
        if(v2.size() == 1){
            break;
        }
    }
  
    for(auto e : v2) {
        cout << e << endl;
    }
    
}
