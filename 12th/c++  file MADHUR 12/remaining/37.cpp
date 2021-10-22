//PROGRAM TO COUNT LINES STARTING WITH 'A'
#include<fstream.h>
#include<stdio.h>
void main()
{
  ofstream a("TEXT.txt",ios::out);
  char ch[100],c[50];
  int i=0;
  cout<<"ENTER THE TEXT TO WRITE IN DATA FILE:\n";
  gets(ch);
  a<<ch;
  a.close();
  ifstream v("TEXT.txt",ios::in);
  while(!v.eof())
  {
	v.getline(c,80,'.');
	if((c[0]=='A'))
		  i++;
  }
  cout<<"\nTHERE ARE "<<i<<" LINES STARTING WITH 'A'";
  v.close();
}
