#include<iostream.h>
void main()
{
  int a,b,n,f=1,s=0;
  cout<<"ENTER THE NUMBER OF TERMS"<<endl;
  cin>>n;
  for(a=1;a<=n;a++)
  {
	 cout<<a<<"\! + ";
		 for(b=1;b<=a;b++)
		 {
			f*=b;
		 }
	 s+=f;
	 f=1;
  }
		cout<<"\b\b = "<<s;

}

