//SWAPPING WITHOUT USING THIRD VARIABLE
#include<iostream.h>                          //HEADER FILES INCLUDED
void swap(int c,int d)                       //FUNTION NOT RETURNING ANY VALUES
{
	c=c+d;
	d=c-d;                                  //FUNCTION DEFINITION
	c=c-d;
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
	swap(a,b);                                    //FUNCTION CALL(CALL BY VALUE)
}
