//PROGRAM TO INPUT STRING AND WRITE THOSE CONTENTS IN A DATA FILE
#include<fstream.h>
#include<stdio.h>
void main()
{
  char ch[20];
  cout<<"ENTER THE STRING\n";
  gets(ch);
  fstream fout,fin;
  fout.open("IN1.TXT",ios::out);
  if(!fout)
	cout<<"FILE DOESNOT EXIST";
  else
	 {
		fout<<ch;
	 }
  fout.close();        //we must close before using same file in another mode even with diff variable
  fin.open("IN1.TXT",ios::in);
  cout<<"THE STRING STORED IN TEXT FILE IS  \n";
  while(!fin.eof())
		 {
			fin>>ch;
			cout<<ch<<" ";
		 }
       fin.close();   //not necessary since program is terminated
}
