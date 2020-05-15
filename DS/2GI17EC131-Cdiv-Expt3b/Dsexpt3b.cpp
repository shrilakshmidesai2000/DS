#include<iostream>
using namespace std;


int fibo(int n)
{
    if(n<=1)
    {
        return(1);
    }
    else{
        return((fibo(n-1)+fibo(n-2)));
    }
}
int main()
{
    int n,x;
    cout<<"Enter the sequence end range : ";
    cin>>n;
    x = fibo((n-1));
    cout<<"Fibonacci digit is : "<<x;
}





