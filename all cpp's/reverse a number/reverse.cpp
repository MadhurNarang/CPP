#include<iostream.h>
 void main()
{
  int a,b,c=0;
  char ch;
  do{
  cout<<"ENTER ANY NUMBER TO REVERSE"<<endl;
  cin>>a;
  while(a!=0)
  {
	 b=a%10;
	 c=(c*10)+b;
	 a=a/10;
  }
  cout<<"REVERSED NUMBER IS:"<<c;
  cout<<"\npress c to continue the program";
  cin>>ch;
  }while(ch=='c');

}
