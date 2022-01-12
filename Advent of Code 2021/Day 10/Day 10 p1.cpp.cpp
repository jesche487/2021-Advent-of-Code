/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<char> thingies;

void validParentheses (string input)
{
 stack <char> s;
 int length = input.length();
 char top;

 for(int i = 0; i< length; i++){
   if(input[i] == '(' || input[i] == '{' || input[i] == '[' || input[i] == '<'){
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
      else{
        //diff parentheses
        cout << input[i] <<" contains invalid parentheses."<<endl;
        thingies.push_back(input[i]);
        return;
      }
     }
   }
 }
 
 if (s.empty()){
   cout<<input<<" complete"<<endl;
 }
 else{
   cout<<input<<" incomplete"<<endl;
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
            validParentheses(line);
            //cout << checkExpress(line) << " ";
            
            //cout << line << endl;
            
            //istringstream iss(line);
            //while(iss >> a) {
            //}

        }
        myfile.close();
    }

    else cout << "Unable to open file"; 

    //why not printing?
    for(int i = 0; i < thingies.size(); i++) {
        cout << i << " " << thingies[i] << endl;
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
    return 0;
}
