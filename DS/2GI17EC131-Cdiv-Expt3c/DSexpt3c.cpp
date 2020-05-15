#include<iostream>
#include<stack>

using namespace std;

string prefix;
string postfix;
int i;
int l;

stack<string> s;



bool isoperator(char ch)
{
    switch(ch)
    {
    case '+' :
    case '-' :
    case '*' :
    case '/' :
        return true;
    }
    return false;
}

void eval(int i)
{
    if(i<0)
    {
        postfix = s.top();s.pop();
        cout<<"Postfix expression :"<<postfix<<endl;
        return;
    }
        if(isoperator(prefix[i]))
        {
            string p1 = s.top();s.pop();
            string p2 = s.top();s.pop();

            string temp = p1+p2+prefix[i];

            s.push(temp);
        }
        else{
            s.push(string(1,prefix[i]));
        }
    i = i - 1;
    eval(i);
}

int main()
{
   cout<<"enter the prefix expression :";
   cin>>prefix;

   l = prefix.size();

   eval(l-1);

}
