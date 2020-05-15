#include<iostream>
using namespace std;

int fact(int n)
{
    if(n == 1)
    {
        return(1);
    }
    else
        return(n*fact(n-1));
}


int main()
{
    int n,result;
    cout<<"Enter the number : ";
    cin>>n;
if(n==0)
cout<<"The factorial is : 1"<<endl;
 result= fact(n);
    cout<<"The factorial is : "<<result<<endl;
}
