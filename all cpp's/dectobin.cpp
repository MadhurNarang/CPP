//CONVERTING DECIMAL TO BINARY
#include<iostream.h>                           //HEADER FILES INCLUDED
void main()
{
  int dec,b,bin[20],i=0;
  cout<<"ENTER DECIMAL EQUIVALENT TO CONVERT IN BINARY   :  ";
  cin>>dec;
  b=dec;
  while(b!=0)
  {
	bin[i++]=b%2;                        //BINARY EQUIVALENT IS STORED IN ARRAY 
	b/=2;
  }
  cout<<"\nBINARY EQUIVALENT OF "<<dec<<" IS :  ";
  for(i-=1;i>=0;i--)
  {
	cout<<bin[i];
  }
}
