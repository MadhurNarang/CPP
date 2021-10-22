#include<iostream.h>
#include<ctype.h>
void main()
{
 char c;
 cout<<"ENTER ANY CHARACTER";
 cin>>c;
 if(isalpha(c))
  {
	if(isupper(c))
	 cout<<"ENTERED CHARACTER IS AN UPPERCASE ALPHABET";
	if(islower(c))
	 cout<<"ENTERED CHARACTER IS A LOWERCASE ALPHABET";
  }
 else
  if(isdigit(c))
	cout<<"ENTERED CHARACTER IS A NUMBER";
  else
   cout<<"ENTERED NUMBER IS NEITHER ALPHABET NOR A NUMBER";
}


