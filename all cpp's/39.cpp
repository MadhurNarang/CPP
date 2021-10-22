//PROGRAM FOR IMPLEMENTATION OF BINARY DATA FILE
//WRITE,READ,SEARCh,SORT,DELETE,ADD(EVEN IN SORTED MANNER)
//AND EDIT RECORDS
#include<stdio.h>
#include<fstream.h>
#include<stdio.h>
int bon=0;
class student
{
int roll;
char name[25];
char dob[10];
float per;
public:
void in()
{
cout<<"ENTER ROLL NUMBER\t";
cin>>roll;
cout<<"ENTER NAME\t\t";
gets(name);
cout<<"ENTER DATE OF BIRTH \t\t";
gets(dob);
cout<<"ENTER PERCENTAGE \t";
cin>>per;
}
void out()
{
cout<<"\nROLL NUMBER \t"<<roll;
cout<<"\nNAME\t\t"<<name;
cout<<"\nDATE OF BIRTH\t\t"<<dob;
cout<<"\nPERCENTAGE\t"<<per;
}
void sort();
int getroll()
{
return roll;
}
void writefile();
void readfile();
void search();
void del();
void destroy()
{
remove("Det.dat");
cout<<"\nALL RECORDS DELETED";
}
void edit();
void insor();
}a;
void student::insor()
{
student s;
int p=0,n;
char t;
cout<<"\n\tBONUS\n\t-----\n";
do{
cout<<"\nENTER THE NEW RECORD \n";
s.in();
fstream abc("Det.dat",ios::in|ios::binary);
fstream bca("Tmp.dat",ios::out|ios::binary);
while(abc.read((char*)&a,sizeof(a)))
{
 if(s.getroll()<=a.getroll())
{
bca.write((char*)&s,sizeof(s));
p=1;
}
else
bca.write((char*)&a,sizeof(a));
}
if(p==0)
bca.write((char*)&s,sizeof(s));
else
if(!abc.eof())
while(abc.read((char*)&a,sizeof(a)))
{
bca.write((char*)&a,sizeof(a));
}
cout<<"\nRECORD INSERTED ,DO YOU WANT TO ADD MORE(Y/N)\t";
cin>>t;
abc.close();
bca.close();
remove("Det.dat");
rename("Tmp.dat","Det.dat");
}while(t=='y'||t=='Y');
}
void student::edit()
{
int rn;
long rec;
char t,found;
do
{
 fstream abc("Det.dat",ios::in|ios::out|ios::binary);
cout<<"\tEDIT\n\t----\n";
if(!abc)
cout<<"\nFILE DOENNOT EXIST";
else
{
cout<<"\nENTER ROLL NUMBER OF RECORD TO EDIT \t\t";
cin>>rn;
while(abc.read((char*)&a,sizeof(a)))
if(a.getroll()==rn)
{
rec=abc.tellg();
cout<<"\nTHE CURRENT RECORD IS:\n";
a.out();
cout<<"\n\nENTER VALUES TO UPDATE:\n\n ";
a.in();
abc.seekg(rec-sizeof(a),ios::beg);
found='y';
abc.write((char*)&a,sizeof(a));
}
}
if(found=='y')
cout<<"\nTHE RECORD HAS BEEN UPDATED,DO YOU WANT TO EDIT MORE?(Y/N)\t";
else
cout<<"\nROLL NUMBER NOT FOUND,DO YOU WANT TO RETRY(Y/N)\t";
cin>>t;
abc.close();
}while(t=='Y'||t=='y');
}
void student::del()
{
int rn;
char t;
do
{
cout<<"\tDELETE\n\t------\n";
fstream abc("Det.dat",ios::in||ios::binary);
fstream bca("Tmp.dat",ios::out||ios::binary);
cout<<"\nENTER ROLL NUMBER TO DELETE \t";
cin>>rn;
if(!abc)
cout<<"\nFILE NOT FOUND";
else
while(abc.read((char*)&a,sizeof(a)))
{
if(a.getroll()!=rn)
bca.write((char*)&a,sizeof(a));
}
abc.close();
bca.close();
remove("Det.dat");
rename("Tmp.dat","Det.dat");
cout<<"\nTHE RECORD HAS BEEN DELETED,DO YOU WANT TO DELETE MORE?(Y/N)\t";
cin>>t;
}while(t=='Y'||t=='y');
}
void student::sort()
{
int n=0,i,j;
student s[20],tmp;
fstream bca("Det.dat",ios::in|ios::binary);
cout<<"\tSORT\n\t----\n";
if(!bca)
cout<<"\nFILE DOESNOT EXIST";
else
while(bca.read((char*)&s[n],sizeof(student)))
n++;
bca.close();
for(i=0;i<n;i++)
  for(j-0;j<n-1-1;j++)
if(s[j].getroll()>s[j+1].getroll())
{
tmp=s[j];
s[j]=s[j+1];
s[j+1]=tmp;
}
for(i=0;i<n;i++)
{
s[i].out();
cout<<endl;
}
fstream abc("Det.dat",ios::out||ios::binary);
i=0;
while(i<n)
{
abc.write((char *)&s[i],sizeof(student));
++i;
abc.close();
bon=1;
}
}
void student::writefile()
{
fstream abc("Det.dat",ios::out||ios::app||ios::binary);
char t;
do
{
cout<<"\n\tENTRY\n\t-----\n";
a.in();
abc.write((char *)&a,sizeof(a));
cout<<"\nDO YOU WANT TO ADD MORE RECORDS?(Y/N)\t";
cin>>t;
}while((t=='y')||(t=='Y'));
abc.close();
}
void student::readfile()
{
fstream bca("Det.dat",ios::in||ios::binary);
cout<<"\n\tREAD\n\t----\n";
if(!bca)
cout<<"\nFILE DOESNOT EXIST";
else
while(bca.read((char*)&a,sizeof(a)))
{
a.out();
cout<<endl;
}
}
void student::search()
{ 
int rn,p=0;
cout<<"\n\tSEARCH\n\t------\n\n";
cout<<"ENTER ROLL NUMBER TO SEARCH \t";
cin>>rn;
fstream bca("Det.dat",ios::in||ios::binary);
if(!bca)
cout<<"\nFILE DOESNOT EXIST ";
else
while(bca.read((char *)&a,sizeof(a)))
if(a.getroll()==rn)
{
a.out();
cout<<endl;
p=1;
}
if(p==0)
cout<<"\nROLL NUMBER NOT FOUND\ n";
}
void main()
{
char t,c;
do
{
cout<<"\tMENU\n\t----\nPRESS 1 TO WRITE IN DATA FILE \n";
cout<<"PRESS 2 TO SEARCH AND DISPLAY A CERTAIN RECORD \n";
cout<<"PRESS 3 TO READ DATA FILE \n";
cout<<"PRESS 4 TO SORT THE RECORDS \n";
cout<<"PRESS 5 TO DELETE A RECORD \n";
cout<<"PRESS 6 TO DELETE ALL RECORDS \n";
cout<<"PRESS 7 TO EDIT A RECORD \n";
if(bon!=0)
cout<<"PRESS 8 TO ADD RECORD IN A SORTED MANNER";
cout<<"YOUR CHOICE\ t";
cin>>c;
cout<"\n\n";
if(bon!=0)
switch(c)
{
case '1':a.writefile();
break;
case '2':a.search();
break;
case '3':a.readfile();
break;
case '4':a.sort();
break;
case '5':a.del();
break;
case '6':a.destroy();
break;
case '7':a.edit();
break;
case '8':a.insor();
break;
default:cout<<"\n ENTER VALID ENTRY";
break;
}
else
switch(c)
{
case '1':a.writefile();
break;
case '2':a.search();
break;
case '3':a.readfile();
break;
case '4':a.sort();
break;
case '5':a.del();
break;
case '6':a.destroy();
break;
case '7':a.edit();
break;
case '8':a.insor();
break;
default:cout<<"\n ENTER VALID ENTRY";
break;
}

cout<<"\n\nCONTINUE TO MENU(Y/N)\t";
cin>>t;
}while((t=='y')||(t='Y'));
}
