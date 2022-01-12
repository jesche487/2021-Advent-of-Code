#include <bits/stdc++.h>
using namespace std;


struct cuboid {
    cuboid(bool onoff, int xlow, int xhigh, int ylow, int yhigh, int zlow, int zhigh) {
        mode = onoff;
        xl = xlow;
        xh = xhigh;
        yl = ylow;
        yh = yhigh;
        zl = zlow;
        zh = zhigh;
    }

    void intersect(cuboid c, vector<cuboid> &cubers) {
        //find coords for intersected cube
        int xlint = max(xl, c.xl);
        int xhint = min(xh, c.xh);
        int ylint = max(yl, c.yl);
        int yhint = min(yh, c.yh);
        int zlint = max(zl, c.zl);
        int zhint = min(zh, c.zh);




        if(xlint <= xhint && ylint <= yhint && zlint <= zhint) {
               //create new cube that is intersected CHANGE BOOL LATER
                if(mode == true && c.mode == true) { //add cube to cancel area later 
                    cubers.push_back(cuboid(false , xlint, xhint, ylint, yhint, zlint, zhint));
                }
                else if(mode == true && c.mode != true) { // also add opp sign
                    cubers.push_back(cuboid(true , xlint, xhint, ylint, yhint, zlint, zhint));
                }
                else if(mode != true && c.mode == true) { // cancel that area boi
                    cubers.push_back(cuboid(false , xlint, xhint, ylint, yhint, zlint, zhint));
                }
                else if(mode != true && c.mode != true) { // nothing happens?
                    cubers.push_back(cuboid(true , xlint, xhint, ylint, yhint, zlint, zhint));
                }
            
           }
    }

    bool mode;
    long long xl;
    long long xh;
    long long yl;
    long long yh;
    long long zl;
    long long zh;
};



int main()
{
    vector<cuboid> cubers;


    //possible by area?
    string line;
    ifstream myfile ("input22.txt");


    bool first = true;
                         
    if (myfile.is_open())                  
    {                                                             
        int count = 0;

        while ( getline(myfile,line) )
        {
            istringstream iss(line);
            string mode;
            long long xl = 0;
            long long xh = 0;
            long long yl = 0;
            long long yh = 0;
            long long zl = 0;
            long long zh = 0;

            //int offset = 150000;

            while(iss >> mode >> xl >> xh >> yl >> yh >> zl >> zh) {
                //if(xl > 50 || xl <-50 || yl > 50 || yl < -50) break; //skip the fat numbs for now
               // cout << mode << " " << xl << " " << xh << " " << yl << " " << yh << " " << zl << " " << zh << endl;


                bool tempmode;
                if(mode == "on") tempmode = true;
                else tempmode = false;

                if(first) {
                    cubers.push_back(cuboid(tempmode, xl, xh, yl, yh, zl, zh));
                    first = false;
                }

                cuboid temp(tempmode, xl, xh, yl, yh, zl, zh);

                int n = cubers.size();

                //vector<cuboid> tempcubers;
                for(int i = 0; i < n; i++) {
                    temp.intersect(cubers[i], cubers);
                }

                if(tempmode) cubers.push_back(temp);
            }
        }
        myfile.close();
    }
    
    else cout << "Unable to open file"; 


    long long sum = 0;


    for(int i = 0; i < cubers.size(); i++) {
        long long tempvol = (cubers[i].xh - cubers[i].xl + 1) * (cubers[i].yh - cubers[i].yl + 1) * (cubers[i].zh - cubers[i].zl + 1);
        cout << "tempvol: " << tempvol << "mode: " << cubers[i].mode << endl;
        
        if(cubers[i].mode) {
            sum += tempvol;
        } 
        else {
            sum -= tempvol;
        }
    }

    cout << "ons: " << sum;
    return 0;
}
