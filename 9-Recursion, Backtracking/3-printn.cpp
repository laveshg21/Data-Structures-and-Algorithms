/*
Coding Problem: Print numbers
Given is the code to print numbers from 1 to n in increasing order recursively. But it contains few bugs that you need to rectify such that all the test cases pass.
Input Format :
Integer n

Output Format :
Numbers from 1 to n (separated by space)

Constraints :
1 <= n <= 10000

Sample Input 1 :                 Sample Output 1 :
6                                1 2 3 4 5 6

Sample Input 2 :                 Sample Output 2 :
4                                1 2 3 4

*/


#include<iostream>
using namespace std; 

void printn(int n){ 
    if(n==0){
        return ;
    }

    printn(n-1); // going up the recursion stack
    cout << n << " "; // printing from the top of the stack
    
}

int main()
{
    int x;
    cin >> x;
    printn(x); 
    return 0;
}
