#include <bits/stdc++.h>
using namespace std;

struct Fishnode {
    //both are ints
    Fishnode(int l, int r) {
        left = l;
        right = r;
    }

    //left is fishnode
    Fishnode(Fishnode* l, int r) {
        children[0] = l;
        right = r;
        left = -1;
    }
    
    //right is fishnode
    Fishnode(int l, Fishnode* r) {
        children[1] = r;
        right = -1;
        left = l;
    }
     
    //both are fishnodes
    Fishnode(Fishnode* l, Fishnode* r) {
        children[0] = l;
        children[1] = r;
        right = -1;
        left = -1;
    }
        
    void print() {
        cout << "[";
        if(left != -1) cout << left;
        else children[0]->print();

        cout << ",";

        if(right != -1) cout << right;
        else children[1]->print();

        cout << "]";
    }

    void fix() {
        bool somethinghappened = true;

        while(somethinghappened) {
            if(explode()) {
                print();
                cout << " explosion" << endl;
                continue;
            }

            if(split()) {
                print();
                cout << " split" << endl;
                continue;
            }
            somethinghappened = false;

            cout << "fixing " << endl;
        };
    }

    void flattingthetree(vector<pair<int*,int>> &flattree, int depth) {
        if(left != -1) flattree.push_back(make_pair(&left,depth));
        else children[0]->flattingthetree(flattree,depth+1);

        if(right != -1) flattree.push_back(make_pair(&right,depth));
        else children[1]->flattingthetree(flattree,depth+1);
    }

    bool removepair(int depth) {
        if(left == -1) {
            if(depth == 3 && children[0]->emptypair()) {
                left = 0;
                return true;
            }
            if(children[0]->removepair(depth+1)) return true;
        } 

        if(right == -1) {
            if(depth == 3 && children[1]->emptypair()) {
                right = 0;
                return true;
            }
            if(children[1]->removepair(depth+1)) return true;
        }
         
        return false;
    }

    bool emptypair() {
        return left != -1 && right != -1;
    }

    bool explode() {
        bool exploded = false;

        vector<pair<int*,int>> flattree;
        
        flattingthetree(flattree,0);

        for(int i = 0; i < flattree.size(); i++) {
            //cout << *flattree[i].first << " " << flattree[i].second << ", ";
            //cout << *e.first << " ";
            if(flattree[i].second == 4) {
                exploded = true;
                if(i-1 >= 0) *flattree[i-1].first += *flattree[i].first;
                if(i+2 < flattree.size()) *flattree[i+2].first += *flattree[i+1].first;
                break;
            }
        }

        if(exploded) removepair(0);

        return exploded;
    }

    bool split() {
        if(left == -1) { 
            if(children[0]->split()) return true;
        }
        if(left > 9) {
            children[0] = new Fishnode (left/2, left - left/2);
            left = -1;
            return true;
        }

        if(right == -1) {
            if(children[1]->split()) return true;
        }
        if(right > 9) {
            children[1] = new Fishnode (right/2, right - right/2);
            right = -1;
            return true;
        }

        return false;
    }

    int calc() {
        int result = 0;

        if(left != -1) result += 3*left;
        else result += 3*children[0]->calc();

        if(right != -1) result += 2*right;
        else result += 2*children[1]->calc();

        return result;
    }

    vector<Fishnode*> children = vector<Fishnode*>(2);
    
    int left;
    int right;
};

Fishnode* maketree(string input) {
    // cout << input;

    //finds both elements in the string
    int midindex = 0;

    int leftparen = 0;
    int rightparen = 0;
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '[') leftparen++;
        else if(input[i] == ']') rightparen++;

        if(input[i] == ',') {
            if(leftparen == rightparen + 1) {
                midindex = i;
                break;
            }
        }
    }
   
    //recursively calls itself on both elements
    string left = input.substr(1,midindex-1);
    string right = input.substr(midindex+1,input.length()-midindex-1-1);

    // cout <<"left: " << left << " right: " << right << endl;

    if(left.length() == 1 && right.length() == 1) {
        return new Fishnode (stoi(left),stoi(right));
    }
    else if (left.length() != 1 && right.length() == 1) {
        return new Fishnode (maketree(left),stoi(right));
    }
    else if (left.length() == 1 && right.length() != 1) {
        return new Fishnode (stoi(left),maketree(right));
    }
    else if (left.length() != 1 && right.length() != 1) {
        return new Fishnode (maketree(left),maketree(right));
    }

    //ok compiler here you go
    return new Fishnode (maketree(left) , maketree(right));
}

int main()
{
    string line;

    Fishnode* f = nullptr;

    bool first = true;

    vector<string> numbers;

    ifstream myfile ("input18.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            numbers.push_back(line);
            /*
            if(first) {
                f = maketree(line);
                first = false;
            }
            else {
                f = new Fishnode(f, maketree(line));   
                f->fix();         
            } 
            */
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 

    /*
    cout << "got to here" << endl;
    f->print();
    cout << endl << "got to here" << endl;
    cout << f->calc();
    */

    int largest = 0;

    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < numbers.size(); j++) {
            if(j == i) continue;

            f = new Fishnode(maketree(numbers[i]),maketree(numbers[j]));
            f->fix();

            if(f->calc() > largest) largest = f->calc();
        }
    }

    cout << largest;

    return 0;
}
