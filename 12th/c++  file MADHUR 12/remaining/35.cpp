//PROGRAM TO COUNT WORDS STARTING WITH 'THE'
#include<fstream.h>
#include<stdio.h>
void main()
{
  ofstream a("TEXT.txt",ios::out);
  char ch[50],c[50];
  int i=0;
  cout<<"ENTER THE TEXT TO WRITE IN DATA FILE:\n";
  gets(ch);
  a<<ch;
  a.close();
  ifstream v("TEXT.txt",ios::in);
  while(!v.eof())
  {
	 v>>c;
	 if((c[0]=='T')&& (c[1]=='H')&& (c[2]=='E'))
		i++;
  }
  cout<<"\nTHERE ARE "<<i<<" WORDS STARTING WITH 'THE'";
  v.close();
}
