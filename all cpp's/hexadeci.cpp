#include<iostream.h>
void main()
{
 long a,b,f,l=0;
 char  arr[20];
 cout<<"ENTER THE NUMBER TO CONVERT IT TO HEXADECIMAL"<<endl;
 cin>>a;
 f=a;
 while(a!=0)
  {
	b=a%16;
	 if(b==1)
	  arr[l]='1';
	 if(b==2)
	  arr[l]='2';
	 if(b==3)
	  arr[l]='3';
	 if(b==4)
	  arr[l]='4';
	 if(b==4)
	  arr[l]='4';
	 if(b==5)
	  arr[l]='5';
	 if(b==6)
	  arr[l]='6';
	 if(b==7)
	  arr[l]='7';
	 if(b==8)
	  arr[l]='8';
	 if(b==9)
	  arr[l]='9';
	if(b==10)
	 arr[l]='A';
	if(b==11)
	 arr[l]='B';
	if(b==12)
	 arr[l]='C';   //to get number from its remainders when divided by 16
	if(b==13)
	 arr[l]='D';
	if(b==14)
	 arr[l]='E';
	if(b==15)
	 arr[l]='F';
	l++;
	a=a/16;
  }
 cout<<"\n\nTHE HEXADECIMAL EQUIVALENT OF "<<f<<" IS ";
 for(int i=l;i>=0;i--)
 cout<<arr[i];         //to print reversed array
 while(f%16==0)
  {
	cout<<"0";    //to add truncated 0's
	f=f/16;
  }
}