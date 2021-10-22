#include<iostream.h>
void main()
{
	int a,b,c,max;
   cout<<"ENTER THREE NUMBERS";
	cin>>a>>b>>c;
	max=a;
	if(max<b)
	max=b;
	if(max<c)
	max=c;
	cout<<max;
 }