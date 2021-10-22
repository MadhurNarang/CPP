//COPY DOWN WORDS STARTING WITH "A or a" TO ANOTHER FILE
#include<fstream.h>
void copydown()
{
	char ch[10];int i=0;
	fstream fout;
	ifstream fin("IN.TXT",ios::in);
	fout.open("OUT.TXT",ios::out);
	if(!fin)
	 cout<<"ERROR!!!FILE DOESNT EXIST";
	else
	 {
		while(!fin.eof())
		 {
			fin>>ch;
			if(ch[0]=='a'||ch[0]=='A')
			 {
				  fout<<ch<<" ";               //FOR CHAR,WORD,LINE
				  i++;
			 }

		 }
	 }
	fin.close();
	fout.close();
	fout.open("OUT.TXT",ios::in);
	if(i==0)
	 {
	  cout<<"NO WORDS STARTING WITH A OR a";
	 }
	else
	 {
		cout<<"WORDS STARTING WITH A OR a ARE   :\n";
		while(!fout.eof())
		 {
			fout>>ch;
			cout<<ch<<endl;
		 }
	 }
}
void main()
{
  copydown();
}
