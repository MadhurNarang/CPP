//PROGRAM TO COPY NUMBER OF LINES
#include<fstream.h>
void countline()
{
	char ch[100];
	int count=0;
	ifstream fin("IN2.TXT",ios::in);
	if(!fin)
	 cout<<"ERROR!!!FILE DOESNT EXIST";
	else
	 {
		while(!fin.eof())
		 {
			fin.getline(ch,80,'.');
			count++;
		 }
		cout<<"THERE ARE "<<count<<" NUMBER OF LINES IN THE FILE";
	 }
	fin.close();
}
void main()
{
  countline();
}
