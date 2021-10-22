#include<iostream.h>
#include<stdlib.h>
void main()
{
 int i,b,no;
 cout<<"enter any number";
 cin>>no;
 for(i=2;i<=no/2;i++)
  {
	if(no%i==0)
	 goto lb;
  }
  cout<<"PRIME";exit(0);
  lb:cout<<"Composite";
}
