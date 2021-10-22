#include<iostream.h>
void main()
{
 int a=1,n;
 float s=0;
 cout<<"ENTER THE NUMBER OF TERMS";
 cin>>n;
 for(;a<=n;a++)
  {
	cout<<"1/"<<a<<" + ";
	s+=(float)1/a;
  }
  cout<<"\b\b = "<<s;
}
