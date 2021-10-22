//SIMPLE CALCULATOR USING FUNCTIONS
#include<iostream.h>                        //HEADER FILES INCLUDED
#include<stdlib.h>
int sum(int c,int d)
{
	int s=c+d;
	return(s);                               //FUNCTION DEFINITION
}
int diff(int c,int d)
{
	 int di=c-d;
	 return(di);
}
int prod(int c,int d)                       //FUNCTIONS RETURNING VALUES
{
	 int p=c*d;
	 return(p);
}
float quo(int c,int d)
{
	 float q=(float)c/d;
	 return(q);
}
void main()
{
	int a,b,c,d,e,f;
	float g;
	char ch;
	cout<<"\nENTER THE FIRST NUMBER\n";
	cin>>a;
	cout<<"\nENTER THE SECOND NUMBER\n";
	cin>>b;
	d=sum(a,b);                                     //FUNCTION CALL
	cout<<"\nSUM OF "<<a<<" & "<<b<<" IS "<<d;
	e=diff(a,b);
	cout<<"\nDIFFERENCE OF "<<a<<" & "<<b<<" IS "<<e;
	f=prod(a,b);
	cout<<"\nPRODUCT OF "<<a<<" & "<<b<<" IS "<<f;
	g=quo(a,b);
	cout<<"\nQUOTIENT OF "<<a<<" & "<<b<<" IS "<<g;
}

