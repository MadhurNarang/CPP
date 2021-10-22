#include<iostream.h>
int sum(int c,int d);
void main()
{
 int a,b,s;
 cout<<"ENTER THE NUMBERS";
 cin>>a>>b;
 s=sum(a,b);
 cout<<"sum is"<<s;
}
int sum(int c,int d)
{
 int t=c+d;
 return(t);
}

