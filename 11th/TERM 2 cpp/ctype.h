#include<iostream.h>
#include<ctype.h>
void main()
{
 char c,d;
 cout<<"ENTER ANY ALPHABET AND CONVERT TO OPP";
 cin>>c;
 if(isalpha(c))
 {
  if(isupper(c))
	{
	 cout<<"ENTERED ALPHABET IS UPPER CASE";
	 d=tolower(c);
	 cout<<"\nITS LOWER CASE IS "<<d;
	}
  else
	if(islower(c))
	{
	 cout<<"ENTERED ALPHABET IS LOWER CASE";
	 d=toupper(c);
	 cout<<"\nITS UPPER CASE IS "<<d;
	}
 }
 else
  cout<<"ENTERED CHARACTER ISNT AN ALPHABET";
}
