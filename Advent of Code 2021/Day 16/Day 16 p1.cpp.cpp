/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string HexToBin(string hexdec)
{
    long int i = 0;
    string result;
    
    while (hexdec[i]) {
 
        switch (hexdec[i]) {
        case '0':
            result += "0000";
            break;
        case '1':
            result += "0001";
            break;
        case '2':
            result += "0010";
            break;
        case '3':
            result += "0011";
            break;
        case '4':
            result += "0100";
            break;
        case '5':
            result += "0101";
            break;
        case '6':
            result += "0110";
            break;
        case '7':
            result += "0111";
            break;
        case '8':
            result += "1000";
            break;
        case '9':
            result += "1001";
            break;
        case 'A':
        case 'a':
            result += "1010";
            break;
        case 'B':
        case 'b':
            result += "1011";
            break;
        case 'C':
        case 'c':
            result += "1100";
            break;
        case 'D':
        case 'd':
            result += "1101";
            break;
        case 'E':
        case 'e':
            result += "1110";
            break;
        case 'F':
        case 'f':
            result += "1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit "
                 << hexdec[i];
        }
        i++;
    }
    return result;
}

struct Packet {
    Packet() {
        ID = 0;
        version = 0;
        literal = 0;
        size = 0;
    }
    
    Packet(string a, string b, string c, int packetsize) {
        ID = stoi(a,nullptr,2);
        version = stoi(b,nullptr,2);
        literal = stoll(c,nullptr,2);
        size = packetsize;
        
    }

    Packet(string a, string b,  vector<Packet> subpacks, int packetsize) {
        ID = stoi(a,nullptr,2);
        version = stoi(b,nullptr,2);
        literal = 0;
        size = packetsize;

        subpackets = subpacks;        
    }


    int ID;
    int version;
    long long literal;
    int size;
    
    vector<Packet> subpackets;
};

Packet recurse(string b) {
    //no need for base case because one packet
    
    //if(b.length() == 0) {
    //    return; //fuck am i returning
    //}
    Packet p;
    
    int packetlength = 0;
    //literal value, checks packet type ID equal to 4
    if(b.substr(3,3) == "100") {
        string version = b.substr(0,3);
        
        packetlength += 6;
        //check five bit groups, if zero it is the last group
        
        string num = "";
        
        while(b.substr(packetlength, 1) != "0") {
            num += b.substr(packetlength + 1, 4); //binary, converto later
            packetlength += 5;
        }
        
        //adds the last group beginning w 0, is now a whole binary number
        num += b.substr(packetlength + 1, 4);
        packetlength += 5;
        
        //literal packet
        p = Packet(b.substr(3,3), version, num, packetlength);
    }
    //operator
    else {
        string version = b.substr(0,3);

        packetlength += 6;
        
        //next 15 bits are a number that represents the total length in bits of the sub-packets contained by this packet.
        if(b.substr(6,1) == "0") {
            int length = stoi(b.substr(7,15),nullptr,2);
            
            //call recursion on length no of characters e.g. b.substr(23,length)
            int subpacketlen = 0;
            
            vector<Packet> subpacks;
            //cout << length << endl;
            while(subpacketlen < length) {
                Packet subpack = recurse(b.substr(22+subpacketlen));
                subpacketlen += subpack.size;
                subpacks.push_back(subpack);
            }
            
            packetlength += 1 + 15 + subpacketlen;
            
            p = Packet(b.substr(3,3), version, subpacks, packetlength);
        }
        else {
            int packetnum = stoi(b.substr(7,11),nullptr,2);
            packetlength += 1 + 11;
            
            int subpacketlen = 0;
            vector<Packet> subpacks;
            for(int i = 0; i < packetnum; i++) {
                //call recursion to find packetnum of packets
                Packet subpack = recurse(b.substr(18+subpacketlen));
                subpacketlen += subpack.size;
                subpacks.push_back(subpack);
            }
            
            packetlength += subpacketlen;
    
            p = Packet(b.substr(3,3), version, subpacks, packetlength);
        }
    }
    
    //recurse(b.substr(packetlength));
    return p;
    
}

int totalversions(Packet p) {
    //cout << p.size<< endl;
    if(p.subpackets.size() == 0) return p.version;
    
    int sum = 0;
    //cout << p.subpackets.size() << endl;
    
    for(auto e : p.subpackets) {
        sum += totalversions(e);
    }
    
    return sum + p.version;
}

int main()
{

    string line;
    string binline;

    ifstream myfile ("input16.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            //cout << HexToBin(line);
            binline = HexToBin(line);
            
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 
    
    cout << totalversions(recurse(binline)) << endl;
    
    cout << "made it to here" << endl;
    
    return 0;
}
