//PROGRAM TO COUNT WORDS STARTING WITH 'A' OR 'a'
#include<fstream.h>
#include<stdio.h>
void main()
{
  char n[50],w[50];
  int a=0;
  cout<<"ENTER THE TEXT TO WRITE IN DATA FILE:\n";
  gets(n);
  fstream x("TEXT.txt",ios::out);
  x<<n;
  x.close();
  cout<<"\nTEXT DATA FILE WRITTEN";
  fstream b("TEXT.txt",ios::in);
  while(b)
  {
	b>>w;
	if((w[0]=='a')||(w[0]=='A'))
		a++;
  }
  b.close();
  cout<<"\nTHE TEXT HAS "<<a<<" WORDS STARTING WITH 'A' or 'a'";
}
