//CHECK WHETHER NUMBER IS PALINDROME OR NOT
#include<iostream.h>                           //HEADER FILES INCLUDED
void palindrome(int a)                     //FUNCTION NOT RETURNING ANY VALUE
{
  int b=0,c,d;
  c=a;
  while(c!=0)
  {
	d=c%10;                           //FUNCTION DEFINITION
	b=(b*10)+d;
	c/=10;
  }
  if(b==a)
	 cout<<"\n\nENTERED NUMBER IS PALINDROME";
  else
	 cout<<"\n\nENTERED NUMBER IS NOT A PALINDROME";
}
void main()
{
  int a;
  cout<<"ENTER THE NUMBER TO CHECK FOR PALINDROME     ";
  cin>>a;
  palindrome(a);                             //FUNCTION CALL(CALL BY REFERENCE)
}
