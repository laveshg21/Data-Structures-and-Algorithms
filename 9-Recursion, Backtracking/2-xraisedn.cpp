/*
Coding Problem: x to the power n
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.
Input format :
Two integers x and n (separated by space)

Output Format :
x^n (i.e. x raise to the power n)

Constraints :
1 <= x <= 30
0 <= n <= 30

Sample Input 1 :            Sample Output 1 :
3 4                         81                        

Sample Input 2 :            Sample Output 2 :
2 5                         32
*/

#include <bits/stdc++.h>
using namespace std;

int xraisen(int x, int n){
    if(n==0){
        return 1; // base case: if n =0 i.e. X^0 then return 1 as X^0 = 1
    }
    int out = x * xraisen(x,n-1);
    return out; 
}

int main() {
    int input_x = 0, input_n = 0;
    cin >> input_x >> input_n;
    int output = xraisen(input_x, input_n);
    cout << output;
    return 0;
}