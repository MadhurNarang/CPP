//REVERSE EACH WORD IN DATA TEXT FILE
#include<fstream.h>
#include<string.h>
void change()
{
	int j,i,len;
	char ch[10],c[10];
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
			len=strlen(ch);
			for(i=0,j=len-1;i<len;i++,j--)
			{
			  c[i]=ch[j];
			}
			//strrev(ch);
			fout<<c;
		 }
	 }
	fin.close();
	fout.close();
	fout.open("OUT.TXT",ios::in);
		cout<<"REVERSED WORDS ARE :\n";
		while(!fout.eof())
		 {
			fout>>ch;
			cout<<ch<<" ";
		 }
}
void main()
{
  change();
}