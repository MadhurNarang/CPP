//PROGRAM TO WRITE CONTENTS ONTO A BINARY DATA FILE
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
int i=0;
class student
{
	int roll;
	char name[20];
	float per;
  public:
	void input()
	{
	  cout<<"ENTER THE NAME OF STUDENT\n";
	  cin>>name;
	  cout<<"ENTER THE ROLL NO\n";
	  cin>>roll;
	  cout<<"ENTER THE PERCENTAGE\n";
	  cin>>per;
	}
	void display()
	{
	  cout<<"\nNAME OF STUDENT IS\n";
	  cout<<name;
	  cout<<"\nROLL NO IS\n";
	  cout<<roll;
	  cout<<"\nPERCENTAGE IS\n";
	  cout<<per;
	}
	int retroll()
	{
	  return(roll);
	}
	char* retname()   //FUNCTION TO RETURN STRING
	{
	  return(name);
	}
};
void in()
{
  char ch;
  student ob;
  ofstream fout("ABC.DAT",ios::out|ios::binary);
  do
  {
	 cout<<"\nENTER THE STUDENT DATA \n\n";
	 ob.input();
	 fout.write((char*)&ob,sizeof(ob));
	 cout<<"\nDO YOU WANT TO ENTER ANOTHER RECORD  Y/N     ";
	 cin>>ch;
  }while(ch=='Y');
  fout.close();
}
void dis()
{
  student ob;
  ifstream fin("ABC.DAT",ios::in|ios::binary);
  cout<<"\nSTUDENT DATA STORED IN FILE IS \n";
  while(fin.read((char*)&ob,sizeof(ob)))
  {
	i++;
	ob.display();
	cout<<endl;
  }
  if(i==0)
  {
	cout<<"\nFILE IS EMPTY";
  }
	fin.close();
}
void search()
{
  int r;
  int found=0;
  student ob;
  cout<<"ENTER THE ROLL NO TO BE SEARCHED     ";
  cin>>r;
  ifstream fin("ABC.DAT",ios::in|ios::binary);
  while(fin.read((char*)&ob,sizeof(ob)))
  {
	if(r==ob.retroll())
	  {
		 found++;
		 ob.display();
		 break;
	  }

  }
  if(found==0)
  {
	cout<<"\nNO RECORD FOUND";
  }

	fin.close();
}
void del()
{
  fstream fout,fin;
  int r;
  student ob;
  int x=0;
  cout<<"\n\n\nENTER THE ROLL NO OF STUDENT TO DELETE ITS RECORD    ";
  cin>>r;
  fout.open("ABC.DAT",ios::in|ios::binary);
  fin.open("DEF.DAT",ios::out|ios::binary);
  while(fout.read((char*)&ob,sizeof(ob)))
  {
	if(r!=ob.retroll())
	 {
		fin.write((char*)&ob,sizeof(ob));
	 }
  }
  fout.close();
  fin.close();
  remove("ABC.DAT");
  x=rename("DEF.DAT","ABC.DAT");
  if(x==0)
	cout<<"NO RECORD FOUND ";
  else
  {
	i--;
	cout<<"NEW DELETED RECORD IS  \n";
	fout.open("ABC.DAT",ios::in|ios::binary);
	while(fout.read((char*)&ob,sizeof(ob)))
		{
		 ob.display();
		}
	fout.close();
  }
}
void ins()
{
  fstream fout,fin;
  int r;
  student ob;
  int x=0;
  cout<<"\n\n\nENTER THE ROLL NO OF STUDENT TO EDIT ITS RECORD    ";
  cin>>r;
  fout.open("ABC.DAT",ios::in|ios::binary);
  fin.open("DEF.DAT",ios::out|ios::binary);
  while(fout.read((char*)&ob,sizeof(ob)))
  {
	if(r==ob.retroll())
	 {
		 cout<<"\nENTER THE NEW DETAILS AGAIN\n";
		 ob.input();
		 fin.write((char*)&ob,sizeof(ob));
	 }
	 else
	  {
		fin.write((char*)&ob,sizeof(ob));
	  }
  }
  fout.close();
  fin.close();
  remove("ABC.DAT");
  x=rename("DEF.DAT","ABC.DAT");
  if(x==0)
	cout<<"NO RECORD FOUND ";
}
void searchname()
{
  char r[25];
  int found=0;
  student ob;
  cout<<"ENTER THE NAME TO BE SEARCHED     ";
  cin>>r;
  ifstream fin("ABC.DAT",ios::in|ios::binary);
  while(fin.read((char*)&ob,sizeof(ob)))
  {
	if(strcmp(r,ob.retname())==0)
	  {
		 found++;
		 ob.display();
		 break;
	  }
	}
	if(found==0)
	{
	  cout<<"\nNO RECORD WITH THIS NAME\n";
	}

	fin.close();
}
void inappend()
{
  char ch;
  student ob;
  ofstream fout("ABC.DAT",ios::out|ios::app|ios::binary);
  do
  {
	 cout<<"\nENTER THE STUDENT DATA \n\n";
	 ob.input();
	 fout.write((char*)&ob,sizeof(ob));
	 cout<<"\nDO YOU WANT TO ENTER ANOTHER RECORD  Y/N     ";
	 cin>>ch;
  }while(ch=='Y');
  fout.close();
}
void searrec()
{
  int r,i=0;
  int found=1;
  student ob;
  cout<<"ENTER THE RECORD NUMBER    ";
  cin>>r;
  ifstream fin("ABC.DAT",ios::in|ios::binary);
  while(fin.read((char*)&ob,sizeof(ob)))
  {
		if(found==r)
		{
		 ob.display();
		 i=1;
		 break;
		}
		found++;
  }
  if(i==0)
  {
	cout<<"\nNO RECORD FOUND";
  }

	fin.close();
}
void insrec()
{
  fstream fout,fin;
  int r;
  long p;
  student ob;
  int x=0;
  cout<<"\n\n\nENTER THE ROLL NO OF STUDENT TO EDIT ITS RECORD    ";
  cin>>r;
  fin.open("ABC.DAT",ios::in|ios::out|ios::binary);
  while(fin.read((char*)&ob,sizeof(ob)))
  {
	if(r==ob.retroll())
	 {
		/* x=1;
		 cout<<"\nENTER THE NEW DETAILS AGAIN\n";
		 p=fin.tellg();
		 fin.seekp(p-1*sizeof(ob),ios::beg);
		 ob.input();
		 fin.write((char*)&ob,sizeof(ob));
		 break;*/

		x=1;
		cout<<"\nENTER THE NEW DETAILS AGAIN\n";
		fin.seekg(fin.tellg()-1*sizeof(ob));    //LEARN IT
		//fin.seekp((-1*sizeof(ob)),ios::cur);    //THIS HAS UNCERTAIN ERROR
		ob.input();
		fin.write((char*)&ob,sizeof(ob));
		break;
	 

	 }
  }
  fin.close();
  if(x==0)
	cout<<"NO RECORD FOUND ";
}
void main()
{
  int choice;
  start:
  cout<<"\nPRESS 1 TO ENTER THE DETAILS\nPRESS 2 TO APPEND\nPRESS 3 TO DISPLAY ALL DETAILS\nPRESS 4 TO SEARCH RECORD USING RECORD NUMBER \nPRESS 5 TO SEARCH RECORD USING ROLL NUMBER \nPRESS 6 TO SEARCH RECORD USING NAME\nPRESS 7 TO DELETE A RECORD \nPRESS 8 TO EDIT THE DETAILS USING ANOTHER FILE\nPRESS 9 TO EDIT THE DETAILS USING SAME FILE\nPRESS 10 TO EXIT \n";
  cout<<"\nENTER YOUR CHOICE   ";
  cin>>choice;
  if(choice==1)
	{
	  clrscr();
	  in();
	  cout<<"\n\nPRESS ANY KEY TO CONTINUE";
	  getch();
	  clrscr();
	  goto start;
	}
  else
	 if(choice==2)
	  {
		clrscr();
		inappend();
		cout<<"\n\nPRESS ANY KEY TO CONTINUE";
		getch();
		clrscr();
		goto start;
	  }
	 else
	  if(choice==3)
		{
		 clrscr();
		 dis();
		 cout<<"\n\nPRESS ANY KEY TO CONTINUE";
		 getch();
		 clrscr();
		 goto start;
		}
	  else
		if(choice==4)
		 {
		  clrscr();
		  searrec();
		  cout<<"\n\nPRESS ANY KEY TO CONTINUE";
		  getch();
		  clrscr();
		  goto start;
		 }
	  else
		if(choice==5)
		 {
		  clrscr();
		  search();
		  cout<<"\n\nPRESS ANY KEY TO CONTINUE";
		  getch();
		  clrscr();
		  goto start;
		 }
		else
		 if(choice==6)
		  {
			clrscr();
			searchname();
			cout<<"\n\nPRESS ANY KEY TO CONTINUE";
			getch();
			clrscr();
			goto start;
		  }
		 else
		  if(choice==7)
			{
			 clrscr();
			 del();
			 cout<<"\n\nPRESS ANY KEY TO CONTINUE";
			 getch();
			 clrscr();
			 goto start;
			}
		  else
			if(choice==8)
			 {
			  clrscr();
			  ins();
			  cout<<"\n\nPRESS ANY KEY TO CONTINUE";
			  getch();
			  clrscr();
			  goto start;
			 }
			else
			if(choice==9)
			 {
			  clrscr();
			  insrec();
			  cout<<"\n\nPRESS ANY KEY TO CONTINUE";
			  getch();
			  clrscr();
			  goto start;
			 }
			else
			 if(choice==10)
				exit(0);
			 else
			  {
				cout<<"\nWRONG CHOICE ENTERED\n";
				cout<<"\nPRESS ANY KEY TO CONTINUE\n";
				getch();
				clrscr();
				goto start;
			  }
}
