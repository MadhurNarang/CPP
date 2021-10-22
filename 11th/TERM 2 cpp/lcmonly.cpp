#include<iostream.h>
#include<stdlib.h>
void main()
 {
  int a,b,c,d,f,g;
  cout<<"ENTER THE NUMBERS IN ASCENDING ORDER";
  cin>>a>>b;
  for(c=1;c<b;c++)
  {
	f=c*b;
	for(d=1;d<=b;d++) //  = has much important role
	{
	 g=d*a;
	 if(g==f)
	  {
		 goto l;
	  }
	}
  }cout<<"ENTER NUMBERS IN ASCENDING ORDER";exit(0);
 l:cout<<"LCM IS "<<f;
}

