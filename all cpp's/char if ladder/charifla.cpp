#include<iostream.h>
void main()
{
  int a,b,s,d,p,r;
  float q;
  char c;
  cout<<"ENTER FIRST NUMBER"<<endl;
  cin>>a;
  cout<<"ENTER SECOND NUMBER"<<endl;
  cin>>b;
  cout<<"Press:\n\"+\" to add \n\"-\" to subtract \n\"X\" to multiply \n\"/\" to divide"<<endl;
  cout<<"Enter your choice"<<endl;
  cin>>c;
  if(c=='+')
		  {
			s=a+b;
			cout<<"sum of "<<a<<" and "<<b<<" is "<<s<<endl;
		  }
  else
		if(c=='-')
			 {
				d=a-b;
				cout<<"Diff of "<<a<<" and "<<b<<" is "<<d<<endl;
			 }
		else
			 if(c=='X')
				 {
				  p=a*b;
				  cout<<"Product of "<<a<<" and "<<b<<" is "<<p<<endl;
				  }
			 else
				  if(c=='/')
						 {
						  q=(float)a/b;
						  cout<<"Quoitient of "<<a<<" and "<<b<<" is "<<q<<endl;
						 }
				  else
					  cout<<"PLEASE RECHECK YOUR CHOICE";

}