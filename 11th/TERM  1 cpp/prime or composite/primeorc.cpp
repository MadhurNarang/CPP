#include<iostream.h>
void main()
{
 int a,b,c=0;
 cout<<"ENTER A NUMBER TO CHECK WHETHER IT IS PRIME OR NOT"<<endl;
 cin>>a;
 for(b=2;b<a;b++)
 {
  if(a%b==0)
	{c++;}
 }
  if(c==0)
  cout<<"\nPRIME";
 else
  cout<<"\nCOMPOSITE\n";
}
 
