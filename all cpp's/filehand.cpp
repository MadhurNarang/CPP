#include<fstream.h>
void countchar()
{
	char ch;
	int count=0;
	ifstream fin("IN1.TXT",ios::in);
	if(!fin)
	 cout<<"ERROR!!!FILE DOESNT EXIST";
	else
	 {
		while(!fin.eof())
		 {
			fin.get(ch);         //READS CHARACTER BY CHARACTER
			count++;
		 }
		cout<<"THERE ARE "<<count<<" NUMBER OF CHARACTERS IN THE FILE";
	 }
	fin.close();
}
void main()
{
  countchar();
}

