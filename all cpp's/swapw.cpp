//SWAPPING WITH  THIRD VARIABLE
#include<iostream.h>                         //HEADER FILES INCLUDED
void swap(int c,int d)                       //FUNTION NOT RETURNING ANY VALUES
{
	int e;
	e=c;;                                    //FUNCTION DEFINITION
	c=d;
	d=e;;
	cout<<"\nSWAPPED VALUES ARE   :\n\n";
	cout<<"FIRST NUMBER IS "<<c<<" & SECOND NUMBER IS "<<d;
}
void main()
{
	int a,b;
	cout<<"ENTER THE NUMBERS TO BE SWAPPED\n";
	cout<<"ENTER THE FIRST NUMBER    ";
	cin>>a;
	cout<<"\nENTER THE SECOND NUMBER    ";
	cin>>b;
	swap(a,b);                                //FUNTION CALL(CALL BY VALUE)
}
