#include<iostream>
using namespace std; 

int factorial(int n){ 
    if(n<0 || n ==0){
        return 1;
    }

    int induction_hypothesis = factorial(n-1);
    int induction_step = n * induction_hypothesis;
    return induction_step;
}

int main()
{
    int x;
    cin >> x;
    cout << factorial(x); 
    return 0;
}
