// Paul Beomcheol Kim
// 12/23/2019
// Karatsuba multiplication for real positive integers 
// In this project, I build two positive integer multiplication algorithms by each recursive calls
// --------------------------------------------
#include <iostream>
#include <cmath>
#include <string>


using namespace std;


int mult(int x, int y) {
    //this is an old school type of multiplication.
    // computating cost O(n^2)
    string s_x = to_string(x);//in order to get the length of integer type, casted to string

    int len = s_x.length();//string type variable has a method to extract the length(return integer)

    if (len == 1 || len == 0) {
        return x * y;
    }
    else {
        int a, b, c, d;
        int len_d2 = len / 2;
        a = x / pow(10, len / 2);
        b = x % int(pow(10, len_d2));
        c = y / pow(10, len / 2);
        d = y % int(pow(10, len_d2));
        int ac = mult(a, c);
        int ad = mult(a, d);
        int bc = mult(b, c);
        int bd = mult(b, d);
        // here , 4 recursive calls

        return pow(10, len) * ac + pow(10, len / 2) * (ad + bc) + bd;
    }
}
int karatsuba(int x, int y) {
    string s_x = to_string(x);
    int len = s_x.length();
    if (len == 1 || len == 0) {

        return x * y;
    }
    else {
        int a, b, c, d;
        a = x / pow(10, len / 2);
        b = x % int(pow(10, len / 2));
        c = y / pow(10, len / 2);
        d = y % int(pow(10, len / 2));
        int ac = karatsuba(a, c);
        int bd = karatsuba(b, d);
        int step_3 = karatsuba(a + b, c + d);
        //Karatsuba has 3 recursive calls
        return ac * pow(10, len) + (step_3 - ac - bd) * pow(10, len / 2) + bd;
    }

}
int main()
{
    //check both functions generate a same result.
    int x = 2789;
    int y = 1348;
    cout <<"Karatsuba multiplication : " <<karatsuba(x, y) << endl;
    cout << "old school multiplication : " << mult(x, y) << endl;
    
}

