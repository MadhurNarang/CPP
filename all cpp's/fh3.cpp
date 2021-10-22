//COPY WORDS WITHOUT VOWEL
#include<fstream.h>
#include<string.h>
void copydown()
{
  char ch[10];
  int i=0,l,k=0,c=0;
  fstream fout;
  ifstream fin("IN1.TXT",ios::in);
  fout.open("OUT1.TXT",ios::out);
  if(!fin)
	 cout<<"ERROR!!!FILE DOESNT EXIST";
  else
	 {
		while(!fin.eof())
		 {
			fin>>ch;
			l=strlen(ch);
			c=0;
			for(k=0;k<l;k++)
			 {
				if((ch[k]=='a')||(ch[k]=='e')||(ch[k]=='i')||(ch[k]=='o')||(ch[k]=='u')||(ch[k]=='A')||(ch[k]=='E')||(ch[k]=='I')||(ch[k]=='O')||(ch[k]=='U'))
				 {
				  c=10;
				 }
			 }
			if(c==0)
			 {
				fout<<ch<<" ";
				i++;
			 }
		 }
	 }
	fin.close();
	fout.close();
	fout.open("OUT1.TXT",ios::in);
	if(i==0)
	 {
		cout<<"NO WORDS WITHOUT VOWEL";
	 }
	else
	 {
		cout<<"WORDS WITHOUT VOWEL ARE   :\n";
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