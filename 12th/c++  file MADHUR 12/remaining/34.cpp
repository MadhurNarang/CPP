//PROGRAM TO COUNT ALPHABETS,DIGITS,SAPCES,WORDS AND LINES
#include<fstream.h>
#include<stdio.h>
void main()
{
  fstream a("TEXT.txt",ios::out);
  char ch[50],c[50];
  int i=0,w=0,al=0,d=0,l=0;
  cout<<"ENTER THE TEXT TO WRITE IN DATA FILE\n";
  gets(ch);
  a<<ch;
  a.close();
  fstream v("TEXT.txt",ios::in);
  while(!v.eof())
  {
	 v>>c;
	 w++;
	 for(i=0;c[i]!='\0';i++)
		if((c[i]>='a')&&(c[i]<='z'))
		  al++;
		else
		  if((c[i]>='A')&&(c[i]<='Z'))
			 al++;
		  else
			  if((c[i]>='0')&&(c[i]<='9'))
				  d++;
  }
  v.seekp(0,ios::beg);
  while(!v.eof())
  {
	 v.getline(c,80,'.');
	 l++;
  }
  cout<<"\nTHERE ARE \n"<<al<<"  ALPHABETS\n";
  cout<<d<<" DIGITS\n";
  cout<<w-1<<" SPACES\n";
  cout<<w<<" WORDS\n";
  cout<<l<<" LINES\n";
  v.close();
}
