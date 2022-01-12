#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

int main()
{
    string code = "###....#.#.#.#.##...#####....##.#..##...##...##..##.######..##.##......#...#.####..#.....##...##.######..##....#...###.##.####.##.####....###..#...##....##...##.###...####.#.##..#..#....#####.#..#...#.#..##..#..##.#.##.#.##...#######.####.#.#..#......##.#...##.#..##....#.###.##.#..####.#......#..#..##.....#.####..#####..###.######..#......####.###.##....##.#.#####..##.#####....#.###..###.#..#..##.##..#.##..###....##.###..#.##.#..########....###.####..##..###..#.#..######..#.##.####.##...#####....#........#.";

    string line;
    
    vector<string> tempfill;
    for(int i = 0; i < 340; i++) {
        tempfill.push_back(".");
    }

    vector<vector<string>> image;

    for(int i = 0; i < 120; i++) {
        image.push_back(tempfill);
    }

    ifstream myfile ("input20.txt");
    if (myfile.is_open())
    {
        int count = 0;

        while ( getline(myfile,line) )
        {
            vector<string> temp;
            
            for(int i = 0; i < 120; i++) {
                temp.push_back(".");
            }

            int length = line.length();
            if(line.length() == 101) {
                length--;
            }
            for(int i = 0; i < length; i++) {
                string str = "";
                str += line[i];
                temp.push_back(str);
            }

            for(int i = 0; i < 120; i++) {
                temp.push_back(".");
            }
        
            //cout << temp.size() << endl;

            //cout << line << endl;
            image.push_back(temp);
            count++;
            
        }
        myfile.close();
    }
    
    else cout << "Unable to open file"; 

    for(int i = 0; i < 120; i++) {
        image.push_back(tempfill);
    }



    int lit = 0;

    for(int i = 0; i < image.size(); i++) {
        for(int j = 0; j < image[i].size(); j++) {
            cout << image[i][j];
            if(image[i][j] == "#") lit++;
        }
        cout << endl;
    }

    cout << endl << endl << lit << endl << endl;

    lit = 0;

    for(int step = 0; step < 50; step++) {

        vector<vector<string>> newimage;

        for(int i = 0; i < image.size()-2; i++) {
            vector<string> temp;

            for(int j = 0; j < image[i].size()-2; j++) {
                string bin;

                if(image[i][j] == ".") bin+="0";
                else bin+= "1";
                if(image[i][j+1] == ".") bin+="0";
                else bin+= "1";
                if(image[i][j+2] == ".") bin+="0";
                else bin+= "1";
                if(image[i+1][j] == ".") bin+="0";
                else bin+= "1";
                if(image[i+1][j+1] == ".") bin+="0";
                else bin+= "1";
                if(image[i+1][j+2] == ".") bin+="0";
                else bin+= "1";
                if(image[i+2][j] == ".") bin+="0";
                else bin+= "1";
                if(image[i+2][j+1] == ".") bin+="0";
                else bin+= "1";
                if(image[i+2][j+2] == ".") bin+="0";
                else bin+= "1";

                int binnumber = binaryToDecimal(stoi(bin));

                //cout << bin << " " << binnumber << endl;

                string str = "";
                str+=code[binnumber];
                temp.push_back(str); 
            }

            newimage.push_back(temp);
        }

        image = newimage;
        newimage.clear();


    }

        for(int i = 0; i < image.size(); i++) {
            for(int j = 0; j < image[i].size(); j++) {
                cout << image[i][j];
                if(image[i][j] == "#") lit++;
            }
            cout << endl;
        }
    
        cout << endl << endl << lit;


    return 0;
}
