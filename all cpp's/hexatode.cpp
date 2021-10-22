#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
 long l,i,e=1,s=0,b,check=1;
 char  arr[20];
 cout<<"ENTER THE HEXADECIMAL CODE TO CONVERT IT TO DECIMAL"<<endl;
 gets(arr);
 l=strlen(arr);
 for(i=0;i<l;i++)
 {
  if(arr[i]=='0'||arr[i]=='1'||arr[i]=='2'||arr[i]=='3'||arr[i]=='4'||arr[i]=='5'||arr[i]=='6'||arr[i]=='7'||arr[i]=='8'||arr[i]=='9'||arr[i]=='A'||arr[i]=='B'||arr[i]=='C'||arr[i]=='D'||arr[i]=='E'||arr[i]=='F')
	continue;                             //to check for hexadecimal code
  else
	check=2;break;
 }
 for(i=l-1;i>=0;i--)
 {
	b=(int)arr[i];          //reverse array and multiply by power of 16 to converted ascii values
	if(isdigit(arr[i]))
	 b-=48;  //ASCII VALUE OF 1 IS 49
	else
	 b-=55;  //ASCII VALUE OF A IS 65
	s+=b*e;
	 e*=16;
 }
  if(check==1)
  {
  cout<<"ENTERED THE HEXADECIMAL CODE'S DECIMAL IS "<<endl;
  cout<<s;
  }
 else
  cout<<"ENTERED CODE ISNT HEXADECIMAL";
}

