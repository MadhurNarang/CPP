#include<iostream.h>
void main()
{
  char c;
  cout<<"ENTER THE CHARACTER";
  cin>>c;

		if((c<='9')&&(c>='0'))
		  cout<<c<<" is a number";

			 else
				if((c<='z')&&(c>='a'))
				cout<<c<<" is a non capital alphabet";

			else
			 if((c<='Z')&&(c>='A'))
			 cout<<c<<" is a capital alphabet";

		else
		cout<<c<<" is a special character";
}

