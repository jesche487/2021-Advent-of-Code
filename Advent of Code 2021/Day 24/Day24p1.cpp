#include <bits/stdc++.h>
using namespace std;

int w;
int x;
int y;
int z;

int func(int a, int b, int c) {
    // inp w

    if((z%26 + b) != w) {
        z = z/a * 26 + w + c;
    }
    else {
        z = z/a;
    }

    /*
    x *= 0; // mul x 0
    x += z; // add x z
    x %= 26; //mod x 26
    z /= 1; //div z 1

    x += diff1; //add x 11

    if(x == w) x = 1;
    else x = 0; //eql x w
    if(x == 0) x = 1;
    else x = 0; //eql x 0
    y *= 0; //mul y 0
    y += 25; //add y 25
    y *= x; //mul y x
    y += 1; //add y 1
    z *= y; //mul z y
    y *= 0; //mul y 0
    y += w; //add y w

    y += diff2; //add y 16

    y *= x; //mul y x
    z += y; //add z y
    */

    return z;
   
}


int main() {

/*
int x = 0;
int y = 0;
int z = 0;


for(int w = 1; w != 9; w++) {
x = 0;
y = 0;
z = 0;

// inp w
x *= 0; // mul x 0
x += z; // add x z
x %= 26; //mod x 26
z /= 1; //div z 1
x += 11; //add x 11
if(x == w) x = 1;
else x = 0; //eql x w
if(x == 0) x = 1;
else x = 0; //eql x 0
y *= 0; //mul y 0
y += 25; //add y 25
y *= x; //mul y x
y += 1; //add y 1
z *= y; //mul z y
y *= 0; //mul y 0
y += w; //add y w
y += 16; //add y 16
y *= x; //mul y x
z += y; //add z y

cout << "z: " << z << endl;
}



//inp w
x *= 0; //mul x 0
x += z; //add x z
x %= 26; //mod x 26
z /= 1; //div z 1
x += 12; //add x 12   DIFFERENT
if(x == w) x = 1;
else x = 0; //eql x w
if(x == 0) x = 1;
else x = 0; //eql x 0
y *= 0; //mul y 0
y += 5; //add y 25
y *= x; //mul y x
y += 1; //add y 1
z *= y; //mul z y
y *= 0; //mul y 0
y += w; //add y w
y += 11; //add y 11
y *= x; //mul y x
z += y; //add z y

inp w
mul x 0
add x z
mod x 26
div z 1
add x 13
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 12
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 26
add x -5
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 12
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 26
add x -3
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 12
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 1
add x 14
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 2
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 1
add x 15
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 11
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 26
add x -16
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 4
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 1
add x 14
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 12
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 1
add x 15
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 9
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 26
add x -7
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 10
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 26
add x -11
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 11
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 26
add x -6
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 6
mul y x
add z y

inp w
mul x 0
add x z
mod x 26
div z 26
add x -11
eql x w
eql x 0
mul y 0
add y 25
mul y x
add y 1
mul z y
mul y 0
add y w
add y 15
mul y x
add z y
*/

for(int w = 1; w < 9; w++) {

    cout << func(-11, 15) << endl;

}

}