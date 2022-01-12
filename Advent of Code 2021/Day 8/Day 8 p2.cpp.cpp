/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string line;
    int sum = 0;

    ifstream myfile ("input8.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            vector<int> letter_count(7);
        
            vector<string> words;

            istringstream iss(line);
            string a;
            while(iss >> a) {
                words.push_back(a);
            }
            
            for(int i = 0; i < words.size(); i++) {
                sort(words[i].begin(),words[i].end()); 
            }
        
            // THIS IS YOUR 200 LINE SEGMENT THINGY ALGORITHM
            
            //counts number of times segments show up
            for(int i = 0; i < 10; i++) {
                for(int j = 0; j < words[i].length(); j++ ){
                    if(words[i][j] == 'a') letter_count[0]++;
                    else if(words[i][j] == 'b') letter_count[1]++;
                    else if(words[i][j] == 'c') letter_count[2]++;
                    else if(words[i][j] == 'd') letter_count[3]++;
                    else if(words[i][j] == 'e') letter_count[4]++;
                    else if(words[i][j] == 'f') letter_count[5]++;
                    else if(words[i][j] == 'g') letter_count[6]++;
                }
            }
        

            //guaranteed segments
            vector<string> finalorder {" "," "," "," "," "," "," "};
            vector<string> alphabet {"a","b","c","d","e","f","g"};
            for(int i = 0; i < letter_count.size(); i++) {
                if(letter_count[i]==6) finalorder[1]=alphabet[i];
                if(letter_count[i]==4) finalorder[4]=alphabet[i];
                if(letter_count[i]==9) finalorder[5]=alphabet[i];
            }
            
            //figures out the top and top right segment
            string twodigit;
            string threedigit;
            
            for(int i = 0; i < 10; i++) {
                if(words[i].length() == 2) twodigit = words[i];
                else if(words[i].length() == 3) threedigit = words[i];
            }
 
            for(int i = 0; i < 3; i++) {
                bool exists = false;            
                for(int j = 0; j < 2; j++) {
                    if(threedigit[i] == twodigit[j]) exists = true;
                }
                
                if(!exists){
                    finalorder[0] = threedigit[i];
                }
            }

            int skip;
            for(int i = 0; i < alphabet.size(); i++) {
                if(alphabet[i]==finalorder[0]) skip = i;
            }
            
            for(int i = 0; i < letter_count.size(); i++) {
                if(letter_count[i] == 8 && i != skip) {
                    finalorder[2]= alphabet[i];
                }
            }

            //fills the remaining two segments with the two unused letters            
            vector<string> secondalphabet {"a","b","c","d","e","f","g"};
            for(int i = 0; i < 7; i++) {
                for(int j = 0; j < secondalphabet.size(); j++) {
                    if(finalorder[i]==secondalphabet[j]) {
                        secondalphabet.erase(secondalphabet.begin()+j);
                        break;
                    }
                }
            } 
            
            
            
            finalorder[3] = secondalphabet[0];
            finalorder[6] = secondalphabet[1];
           
            vector<string> otherfinalorder = finalorder;
            otherfinalorder[3] = finalorder[6];
            otherfinalorder[6] = finalorder[3];

            //two test cases, check to see which one can create a valid zero for the seven segments
            
            string zero_one = finalorder[0] +
                              finalorder[1] +
                              finalorder[2] +
                              finalorder[4] +
                              finalorder[5] +
                              finalorder[6];
            sort(zero_one.begin(), zero_one.end());
        
            bool firstisright = false;
            
            for(int i = 0; i < words.size(); i++) {
                if(zero_one == words[i]) firstisright = true;
            }
            
            //determins the actual correct final order
            if(firstisright==false) {
                finalorder = otherfinalorder;
            }
            

            //now we generate the numbers for our determined seven segments
            vector<string> numberstrings(10);
            numberstrings[0] = finalorder[0] +
                               finalorder[1] +
                               finalorder[2] +
                               finalorder[4] +
                               finalorder[5] +
                               finalorder[6];
            numberstrings[1] = finalorder[2] +
                               finalorder[5];
            numberstrings[2] = finalorder[0] +
                               finalorder[2] +
                               finalorder[3] +
                               finalorder[4] +
                               finalorder[6];
            numberstrings[3] = finalorder[0] +
                               finalorder[2] +
                               finalorder[3] +
                               finalorder[5] +
                               finalorder[6];
            numberstrings[4] = finalorder[1] +
                               finalorder[2] +
                               finalorder[3] +
                               finalorder[5];
            numberstrings[5] = finalorder[0] +
                               finalorder[1] +
                               finalorder[3] +
                               finalorder[5] +
                               finalorder[6];
            numberstrings[6] = finalorder[0] +
                               finalorder[1] +
                               finalorder[3] +
                               finalorder[4] +
                               finalorder[5] +
                               finalorder[6];
            numberstrings[7] = finalorder[0] +
                               finalorder[2] +
                               finalorder[5];
            numberstrings[8] = finalorder[0] +
                               finalorder[1] +
                               finalorder[2] +
                               finalorder[3] +
                               finalorder[4] +
                               finalorder[5] +
                               finalorder[6];
            numberstrings[9] = finalorder[0] +
                               finalorder[1] +
                               finalorder[2] +
                               finalorder[3] +
                               finalorder[5] +
                               finalorder[6];
            
            for(int i = 0; i < numberstrings.size(); i++) {
                sort(numberstrings[i].begin(),numberstrings[i].end());
            }
        
            int finalnumber = 0;
            for(int i = 11; i < 15; i++) {
                finalnumber *= 10;
                for(int j = 0; j < numberstrings.size(); j++) {
                    if(words[i] == numberstrings[j]) finalnumber += j;
                }
            }

            sum += finalnumber;
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 

    cout << sum;
    
    return 0;
}
