#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // if either A or B is < 50, return min(46, C)
    // else return C

    // return 46 iff A||B < 50 and C >= 46
    // aka return 46 iff a < 50 and C >= 46
    
    // aka return 46 iff d == 1
    // else return C

    int A = 50, B = 50, C = 50;
    int a = min(A, B);
    int b = a/50; b = min(b, 1);// 0 (a < 50), 1 (a >= 50)
    int c = C/46; c = min(c, 1);// 0 (C < 46), 1 (C >= 46)
    // flip b values
    b -= 1; b *= -1;// 0 (a >= 50), 1 (a < 50)
    int d = b*c;// 1 (return 46), 0 (return C)
    d -= 1; d *= -1;// 0 (46), 1 (C)
    int e = C*d;// 0 (46), C (C)
    d -= 1; d *= -1;// 1 (46), 0 (C)
    e += d*46;

    printf("%d, %d, %d, %d, %d\n", a, b, c, d, e);

    return 0;
}