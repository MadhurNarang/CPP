#include<iostream.h>
void main()
{
 int a,b;
 char c='G';
 for(a=4;a>=1;a--)
 {
  for(b=1;b<=a;b++)
  {
	cout<<c++;
  }
  c=c-(2*a-1);
  cout<<endl;
 }
}
