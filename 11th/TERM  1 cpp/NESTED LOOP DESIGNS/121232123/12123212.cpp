#include<iostream.h>
void main()
{
 int a,b,c=8,d;
 for(a=1;a<=9;a++)
  {
	for(d=1;d<=c;d++)
	{
	 cout<<" ";      //for spaces
   }
  d=1;
  c--;
	for(b=a;b>1;b--)
	 {
	  cout<<b;                  //to print in descending order
	 }
	b=1;
	for(b=1;b<=a;b++)
	 {
	  cout<<b;         //to print in ascending order
	 }
  b=1;
  cout<<endl;
	}
}
