#include<iostream.h>
#include<stdlib.h>
void sum(int c,int d);
void diff(int c,int d);
void prod(int c,int d);
void quo(float c,float d);
void main()
{
 int a,b,c;
 char ch;
 do{
	 cout<<"\nENTER THE NUMBERS\n";
	 cin>>a>>b;
	 cout<<"press 1 to add \npress 2 to subtract \npress 3 to multiply \npress 4 to divide \npress 5 to exit\n";
	 cin>>c;
	 if(c==1)
	  sum(a,b);
	  else
		if(c==2)
		 diff(a,b);
		else
		 if(c==3)
		  prod(a,b);
		 else
		  if(c==4)
			quo(a,b);
		  else
			if(c==5)
			 exit(0);
			else
			 cout<<"PLEASE CHECK YOUR CHOICE";
	 cout<<"\nDO YOU WANT TO CONTINUE Y/N\t";
	 cin>>ch;
   }while(ch=='Y');
}
void sum(int c,int d)
{
 int s=c+d;
 cout<<s;
}
void diff(int c,int d)
{
 int di=c-d;
 cout<<di;
}
void prod(int c,int d)
{
 int p=c*d;
 cout<<p;
}
void quo(float c,float d)
{
 float q=c/d;
 cout<<q;
}










