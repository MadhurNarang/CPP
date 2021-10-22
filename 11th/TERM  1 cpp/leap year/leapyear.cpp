#include<iostream.h>
void main()
{
 int y;
 cout<<"ENTER AN YEAR";
 cin>>y;
	if(y%100==0)
	 {
		if(y%400==0)
			cout<<y<<" is a leap year ";
		else
			 cout<<y<<" is not a leap year ";
	 }
	 else
			if(y%4==0)
			  cout<<y<<" is a leap year";

			else
				 cout<<y<<" is not a leap year ";

}

