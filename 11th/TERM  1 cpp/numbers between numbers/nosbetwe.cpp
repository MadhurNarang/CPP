#include<iostream.h>
void main()
{
 int a,b,c;
 cout<<"Enter the number"<<endl;
 cin>>a>>b;
 if(a<b)
  for(c=a+1;c<b;c++)
	{
	 cout<<c<<" ";
	}
 else
	if(a>b)
	  for(c=a-1;c>b;c--)
	 {
	  cout<<c<<" ";
	 }
	else
	cout<<"NO NUMBERS";

}

