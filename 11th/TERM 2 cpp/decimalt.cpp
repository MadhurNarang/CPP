#include<iostream.h>
void main()
{
 long a,b,c=0,d,e=0,f;
 cout<<"ENTER THE NUMBER TO CONVERT IT TO OCTAL"<<endl;
 cin>>a;
 f=a;
 while(a!=0)
  {
	b=a%8;
						//to get number from its remainders when divided by 8
	c=(c*10)+b;
	a=a/8;
  }
 while(c!=0)
  {
	d=c%10;
	e=(e*10)+d;   //to reverse the number
	c=c/10;
  }
 cout<<"\n\nTHE OCTAL EQUIVALENT OF "<<f<<" IS "<<e;
 while(f%8==0)
  {
	cout<<"0";    //to add truncated 0's 
	f=f/2;
  }
}