#include<iostream.h>
void main()
{
 long a,b,c=0,d,e=0,f;
 cout<<"ENTER THE NUMBER TO CONVERT IT TO BINARY"<<endl;
 cin>>a;
 f=a;
 while(a!=0)
  {
	b=a%2;
						//to get number from its remainders when divided by 2
	c=(c*10)+b;
	a=a/2;
  }
 while(c!=0)
  {
	d=c%10;
	e=(e*10)+d;   //to reverse the number
	c=c/10;
  }
 cout<<"\n\nTHE BINARY EQUIVALENT OF "<<f<<" IS "<<e;
 while(f%2==0)
  {
	cout<<"0";    //to add truncated 0's 
	f=f/2;
  }
}


