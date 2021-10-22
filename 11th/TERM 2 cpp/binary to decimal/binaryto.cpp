#include<iostream.h>
void main()
{
 long a,b,c=0,d,e=1,f=1;
 cout<<"ENTER ANY BINARY NUMBER  ";
 cin>>a;
 d=a;
 while(a!=0)
 {
  if((a%10!=0)&&(a%10!=1))
  {
	f++;
  }
  a=a/10;
 }
 if(f==1)
  {
	while(d!=0)
	{
	 b=d%10;
	 c+=b*e;
	 e*=2;
	 d/=10;
	}
  cout<<"\n\nDECIMAL EQUIVALENT  "<<c;
  }
 else
 cout<<"ENTERED NUMBER IS NOT BINARY";
}

