 #include<iostream.h>
 void main()
 {
  int a,count,f=1;
  cout<<"enter the number";
  cin>>a;
  for(count=a;count>=1;count--)
  {
	f*=count;
  }
  cout<<"factorial is "<<f;

 }
