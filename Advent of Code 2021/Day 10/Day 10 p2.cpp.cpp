/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<char> thingies;

vector<string> incompletes;

void validParentheses (string input)
{
    stack <char> s;
    int length = input.length();
    char top;

    for(int i = 0; i< length; i++){
        if(input[i] == '(' || input[i] == '{' || input[i] == '[' || input[i] == '<') {
            s.push(input[i]);
        }
        else
        {
            if(s.empty()){
                cout<<input<<" contains invalid parentheses."<<endl;
                return;
            }
            else{
                top = s.top();
                if(input[i] == ')' && top == '(' || 
                    input[i] == '}' && top == '{' ||
                    input[i] == ']' && top == '[' || 
                    input[i] == '>' && top == '<') {
                    s.pop();
                }
                else {
                //diff parentheses
                    cout << "(" << int(input[i]) << ")" <<" contains invalid parentheses."<<endl;
                    thingies.push_back(input[i]);
                    return;
                }
            }
        }    
    }
    
    if (s.empty()) {
        cout<<input<<" complete"<<endl;
    }
    else {
        string temp = "";
        while(!s.empty()) {
            if(s.top() == '(') {
                temp += ')';
                s.pop();
            }
            else if(s.top() == '[') {
                temp += ']';
                s.pop();
            }
            else if(s.top() == '{') {
                temp += '}';
                s.pop();
            }
            else if(s.top() == '<') {
                temp += '>';
                s.pop();
            }
        }
        cout << temp << endl;
        incompletes.push_back(temp);
        //cout<<input<<" incomplete"<<endl;
    }
}

int main()
{

    string line;

    ifstream myfile ("input10.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            //remove the carriage return because it fucks it up
            line.erase(line.size()-1);
            validParentheses(line);

        }
        myfile.close();
    }

    else cout << "Unable to open file"; 

    //why not printing?
    for(int i = 0; i < thingies.size(); i++) {
        cout << i << " " << thingies[i] << " end" << endl;
    }
    cout << endl;
    
    int score = 0;
    for(int i = 0; i < thingies.size(); i++) {
        if(thingies[i]==')') score += 3;
        else if(thingies[i]==']') score += 57;
        else if(thingies[i]=='}') score += 1197;
        else if(thingies[i]=='>') score += 25137;
    }
    cout << score;
    
    
    vector<long long> scores;
    
    //cout << incompletes.size() << "SIZERS" << endl;
    
    for(int i = 0; i < incompletes.size(); i++) {
        long long temp = 0;
        
        //cout << incompletes[i].length() << endl;
        
        int power = incompletes[i].length()-1;
        
        for(int j = 0; j < incompletes[i].length(); j++) {
            
           // cout << j << endl;
            
            if(incompletes[i][j]==')') temp += 1*pow(5,power);
            else if(incompletes[i][j]==']') temp += 2*pow(5,power);
            else if(incompletes[i][j]=='}') temp += 3*pow(5,power);
            else if(incompletes[i][j]=='>') temp += 4*pow(5,power);
            power--;
        }
        scores.push_back(temp);
    }
    
    sort(scores.begin(),scores.end());
    
    cout << endl;
    for(int i = 0; i < scores.size(); i++) {
        cout << i << " " << scores[i] << endl;
    }
    
    cout << endl << scores[24];
    
    return 0;
}
