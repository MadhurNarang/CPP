//PROGRAM TO IMPLEMENT BINARY FILE
//WRITE,EDIT,SEARCH,SORT,DELETE,ADD RECORDS IN SORTED MANNER
#include<stdio.h>
#include<fstream.h>                                     //HEADER FILES INCLUDED
int bon=0;
class student                                                   //CLASS TAGNAME
 {
	int roll;
	char name[25];                                                //DATA MEMBERS
	char dob[10];
	float per;
 public:                                              //PUBLIC ACCESS SPECIFIER
	void in()
	{
	  cout<<"\nENTER THE ROLL NUMBER\t";       //INLINE FUNCTION TO INPUT VALUES
	  cin>>roll;
	  cout<<"\nENTER THE NAME\t\t";
	  gets(name);
	  cout<<"\nENTER DOB\t\t";
	  gets(dob);
	  cout<<"\nENTER PERCENTAGE\t";
	  cin>>per;
	}
	void out()                                //INLINE FUNCTION TO OUTPUT VALUES
	{
	  cout<<"\nROLL NUMBER\t"<<roll;
	  cout<<"\nNAME\t\t"<<name;
	  cout<<"\nDOB\t\t"<<dob;
	  cout<<"\nPERCENTAGE\t"<<per;
	}
	int getroll()
	{                                           //FUNCTION TO RETURN ROLL NUMBER
	  return roll;
	}
	void destroy()                      //FUNCTION TO DELETE ALL RECORDS IN FILE
	{
	  remove("Det.dat");
	  cout<<"\n\t\tALL RECORDS DELETED\n";
	}
	void sort();
	void writefile();                             //ALL MEMBER FUNCTION DECLARED
	void readfile();
	void search();
	void del();
	void edit();
	void insor();
 }a;                                            //DECLARING GLOBAL CLASS OBJECT


void student::insor()             //FUNCTION TO INSERT RECORDS IN SORTED MANNER
 {
	student s;
	int p=0;
	char t;
	cout<<"\n\t\tBONUS\n";
	do{
		 cout<<"\nENTER THE NEW RECORD\n";
		 s.in();
		 fstream abc("Det.dat",ios::in|ios::binary);      //USING 'abc' AND 'bca'
		 fstream bca("Tmp.dat",ios::in|ios::binary);    //AS FILE STREAM OPERATOR
		 while(abc.read((char*)&a,sizeof(a)))
		 {
			if(s.getroll()<=a.getroll())
			{
			  if(p==0)
			  {
				 bca.write((char*)&s,sizeof(s));
				 p=1;                                       //CODE TO INSERT RECORD
				 bca.write((char*)&a,sizeof(a));                 //IN SORTED MANNER
			  }
			}
			else
			  bca.write((char*)&a,sizeof(a));
		 }
		 if(p==0)
			 bca.write((char*)&s,sizeof(s));
		 cout<<"\nRECORD INSERTED.DO YOU WANT TO ADD MORE?(Y/N)\t";
		 cin>>t;
		 abc.close();
		 bca.close();
		 remove("Det.dat");
		 rename("Tmp.dat","Det.dat");
	  }while(t=='y'||t=='Y');
 }


 void student::edit()                   //FUNCTION TO EDIT RECORDS IN DATA FILE
 {
	int rn,rec;
	char t,found;
	do
	 {
		fstream abc("Det.dat",ios::in|ios::out|ios::binary);        //USING 'abc'
		cout<<"\n\t\tEDIT\n";                           //AS FILE STREAM OPERATOR
		if(!abc)
			cout<<"\nFILE DOESNOT EXIST";
		else
		{
		  cout<<"\nENTER THE ROLL NUMBER OF RECORD TO EDIT\n";
		  cin>>rn;
		  while(abc.read((char*)&a,sizeof(a)))
			 if(a.getroll()==rn)
			 {
				rec=abc.tellg();
				cout<<"\nTHE CURRENT RECORD IS\n";
				a.out();                                      //CODE TO EDIT RECORD
				cout<<"\nENTER VALUES TO UPDATE\n";                  //IN DATA FILE
				a.in();
				abc.seekg(rec-sizeof(a),ios::beg);
				found='y';
				abc.write((char*)&a,sizeof(a));
			 }
		}
		if(found=='y')
			cout<<"\nTHE RECORD HAS BEEN UPDATED,DO YOU WISH TO EDIT MORE(Y/N)\t";
		else
			cout<<"\nROLL NUMBER NOT FOUND.DO YOU WISH TO EDIT MORE(Y/N)\t";
		cin>>t;
		abc.close();
	 }while(t=='y'||t=='Y');
 }


void student::del()                   //FUNCTION TO DELETE RECORDS IN DATA FILE
 {
	int rn;
	char t;
	do
	 {
		cout<<"\n\t\tDELETE\n";
		fstream abc("Det.dat",ios::in|ios::binary);       //USING 'abc' AND 'bca'
		fstream bca("Tmp.dat",ios::in|ios::binary);     //AS FILE STREAM OPERATOR
		cout<<"\nENTER ROLL NUMBER TO DELETE\n";
		cin>>rn;
		if(!abc)
			cout<<"\nFILE NOT FOUND\n";
		else
			while(abc.read((char*)&a,sizeof(a)))           //CODE TO DELETE RECORD
			{                                                       //IN DATA FILE
			  if(a.getroll()!=rn)
				  bca.write((char*)&a,sizeof(a));
			}
		abc.close();
		bca.close();
		remove("Det.dat");
		rename("Tmp.dat","Det.dat");
		cout<<"\nTHE RECORD HAS BEEN DELETED.DO YOU WISH TO DELETE MORE(Y/N)\t";
		cin>>t;
	 }while(t=='y'||t=='Y');
 }


 void student::sort()                   //FUNCTION TO SORT RECORDS IN DATA FILE
 {
	int n=0,i,j;
	student s[20],tmp;
	fstream bca("Det.dat",ios::in|ios::binary);                    //USING 'bca'
	cout<<"\n\t\tSORT\n";                              //AS FILE STREAM OPERATOR
	if(!bca)
		 cout<<"\nFILE DOESNOT EXIST";
	else
		while(bca.read((char*)&s[n],sizeof(student)))
			 n++;
	bca.close();
	for(i=0;i<n;i++)
	for(j=0;j<n-1-i;j++)                                   //CODE TO EDIT RECORD
	  if(s[j].getroll()>s[j+1].getroll())                         //IN DATA FILE
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
	fstream abc("Det.dat",ios::out|ios::binary);                   //USING 'abc'
	i=0;                                               //AS FILE STREAM OPERATOR
	while(i<n)
	{
	  abc.write((char*)&s[i],sizeof(student));
	  i++;
	}
	abc.close();
	bon=1;
	cout<<"\nCONGRATULATIONS,YOU HAVE UNLOCKED BONUS FUNCTION";
	cout<<"\nCHECK OUT IN MENU";
 }



void student::writefile()              //FUNCTION TO ENTER RECORDS IN DATA FILE
 {
	fstream abc("Det.dat",ios::out|ios::app|ios::binary);
	char t;
	do
	{
	  cout<<"\n\t\tENTRY\n";
	  a.in();
	  abc.write((char*)&a,sizeof(a));      //USING 'abc' AS FILE STREAM OPERATOR
	  cout<<"\nDO YOU WISH TO ADD MORE RECORDS(Y/N)\t";
	  cin>>t;
	}while((t=='y')||(t=='Y'));
	abc.close();
 }



void student::readfile()                //FUNCTION TO READ RECORDS IN DATA FILE
 {
	fstream bca("Det.dat",ios::in|ios::binary);
	cout<<"\n\t\tREAD\n";                  //USING 'bca' AS FILE STREAM OPERATOR
	if(!bca)
		cout<<"\nFILE DOESNOT EXIST";
	else
		while(bca.read((char*)&a,sizeof(a)))
		 {
			a.out();
			cout<<endl;
		 }
	bca.close();
 }



void student::search()                //FUNCTION TO SEARCH RECORDS IN DATA FILE
 {
	int rn,p=0;
	cout<<"\n\t\tSEARCH\n";
	cout<<"\nENTER ROLL NUMBER TO SEARCH\n";
	cin>>rn;
	fstream bca("Det.dat",ios::in|ios::binary);
	if(!bca)
		cout<<"\nFILE DOESNOT EXIST";
	else
		while(bca.read((char*)&a,sizeof(a)))                //CODE TO EDIT RECORD
			 if(a.getroll()==rn)                                    //IN DATA FILE
			 {
				a.out();
				cout<<endl;
				p=1;
			 }
	if(p==0)
	  cout<<"\nROLL NUMBER NOT FOUND";
	bca.close();
 }



void main()
 {
	int c;
	char t;
	do
	{
	  cout<<"\n\t\tMENU\n\n";
	  cout<<"ENTER 1 TO WRITE DATA FILE\n";
	  cout<<"ENTER 2 TO SEARCH AND DISPLAY CERTAIN RECORD\n";             //MENU
	  cout<<"ENTER 3 TO READ DATA FILE\n";
	  cout<<"ENTER 4 TO SORT THE RECORDS\n";
	  cout<<"ENTER 5 TO DELETE A RECORD\n";
	  cout<<"ENTER 6 TO DELETE ALL RECORDS\n";
	  cout<<"ENTER 7 TO EDIT A RECORD\n";
	  if(bon!=0)
		 cout<<"ENTER 8 TO ADD RECORDS IN SORTED RECORD\n";
	  cout<<"YOUR CHOICE\n";
	  cin>>c;
	  switch(c)
	  {
		  case 1  : a.writefile();
						break;
		  case 2  : a.search();
						break;
		  case 3  : a.readfile();
						break;                         //CALLING FUNCTION ACCORDINGLY
		  case 4  : a.sort();
						break;
		  case 5  : a.del();
						break;
		  case 6  : a.destroy();
						break;
		  case 7  : a.edit();
						break;
		  case 8  : a.insor();
						break;
		  default : cout<<"\nENTER VALID ENTRY";
						break;
	  }
	  cout<<"\nDO YOU WANT TO CONTINUE TO MENU?(Y/N)\n";
	  cin>>t;                                            //MENU DRIVEN CONDITION
	}while((t=='y')||(t=='Y'));
 }
