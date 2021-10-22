       //type casting//
#include<iostream.h>
void main()
{
  float a,b,s,d,p,q;
  int r;
  cout<<"ENTER THE FIRST NUMBER"<<endl;
  cin>>a;
  cout<<"ENTER SECOND NUMBER"<<endl;
  cin>>b;
  s=a+b;
  d=a-b;
  p=a*b;
  q=a/b;
  r=(int)a%b;
cout<<"sum of "<<a<<" and "<<b<<" is "<<s<<endl;
cout<<"Diff of "<<a<<" and "<<b<<" is "<<d<<endl;
cout<<"Product of "<<a<<" and "<<b<<" is "<<p<<endl;
cout<<"Quoitient of "<<a<<" and "<<b<<" is "<<q<<endl;
cout<<"Remainder of "<<a<<" and "<<b<<" is "<<r<<endl;
}