/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct point {
    int x, y, path;
    point(int a, int b, int c) {
        x = a;
        y = b;
        path = c;
    }

    bool operator> (const point& p) const {
        return path > p.path;
    }
};

int main()
{

    string line;
    
    vector<vector<int>> cave;
    
    int count = 0;

    ifstream myfile ("input15.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            vector<int> temp;
            //cout << line << endl;
            if(line.back()=='\r') line = line.substr(0,line.length()-1);
            for(int i = 0; i < line.length(); i++) {
                char a = line[i];
                int num = a-48;
                temp.push_back(num);
            }
            cave.push_back(temp);
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 
    
    
    cout << endl;
    for(int i = 0; i < cave.size(); i++) {
        for(int j = 0; j < cave[i].size(); j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }
    
    int height = 5*cave.size();
    int width = 5*cave[0].size();
    
    vector<vector<int>> bigcave(height,vector<int> (width));
    
    for(int i = 0; i < cave.size(); i++) {
        for(int j = 0; j < cave[i].size(); j++) {
            for(int a = 0; a < 5; a++) {
                for(int b = 0; b < 5; b++) {
                    bigcave[i+a*cave.size()][j+b*cave[0].size()] = (a + b + cave[i][j] - 1) % 9 + 1;                
                }
            }
        }
    }
    
    cave = bigcave;
    
    vector<int> finalrisk;
  
    vector<vector<int>> visited;
    vector<int> temp(width);
    for(int i = 0; i < height; i++) {
        visited.push_back(temp);
    }

    priority_queue <point,vector<point>,greater<point>> q;
    
    q.push(point(0,0,0));

    
    while(!q.empty()) {
        //cout << "running" << endl;
        point current = q.top();
        q.pop();
        
        
        int x = current.x;
        int y = current.y;
        
        if(visited[x][y] == 1) {
            continue;
        }
        visited[x][y] = 1;
        
        int path = current.path;
        if(x == height-1 && y == width-1) {
            finalrisk.push_back(path);
            break;
        }
        else {
            for(int i = 0; i < 4; i++) {
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                if(newX >=0 && newX < height && newY >=0 && newY < width) {
                    q.push(point(newX,newY,path+cave[newX][newY]));
                }
            }
        }
    }
    
    
    for(int i = 0; i < finalrisk.size(); i++) {
        cout << finalrisk[i] << " ";   
    }
    
    
    return 0;
}
