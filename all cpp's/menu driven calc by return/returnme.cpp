#include<iostream.h>
#include<stdlib.h>
int sum(int c,int d);
int diff(int c,int d);             //these are func declarations
int prod(int c,int d);
float quo(int c,int d);
void main()
{
 int a,b,c,d,e,f;
 float g;
 char ch;
 do{
	 cout<<"\nENTER THE NUMBERS\n";
	 cin>>a>>b;
	 cout<<"press 1 to add \npress 2 to subtract \npress 3 to multiply \npress 4 to divide \npress 5 to exit\n";
	 cin>>c;
	 if(c==1)
	  { d=sum(a,b);
		 cout<<d;
	  }
	  else
		if(c==2)
		 {e=diff(a,b);  //this is func call
		  cout<<e;
		 }
		else
		 if(c==3)
		  {f=prod(a,b);
		  cout<<f;}
		 else
		  if(c==4)
			{g =quo(a,b);
			 cout<<g;}
		  else
			if(c==5)
			 exit(0);
			else
			 cout<<"PLEASE CHECK YOUR CHOICE";
	 cout<<"\nDO YOU WANT TO CONTINUE Y/N\t";
	 cin>>ch;
	}while(ch=='Y');
}
int sum(int c,int d)     //function definition's header
{
 int s=c+d;                                             //function definition
 return(s);              //function body
}
int diff(int c,int d)
{
 int di=c-d;
 return(di);
}
int prod(int c,int d)
{
 int p=c*d;
 return(p);
}
float quo(int c,int d)
{
 float q=(float)c/d;
 return(q);
}
