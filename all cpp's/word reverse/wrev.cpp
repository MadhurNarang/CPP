//REVERSE EACH WORD IN ENTERED STRING
#include<iostream.h>
#include<string.h>
#include<stdio.h>
void main()
{
 int len,i,j,k=0,l,q=1,m=0;
 char str1[100],str2[100];
 cout<<"ENTER THE STRING  :  ";
 gets(str1);
 len=strlen(str1);
 for(i=0;i<len+1;i++)
	 {
		 if((str1[i]==' ')||(str1[i]=='\0'))
		 {
			for(j=i-1;j>=m;j--)
			  {
				 str2[k++]=str1[j];
			  }
			str2[k++]=' ';
			m=i+1;
		 }
	}
  cout<<"NOW STRING IS     :  ";
  for(i=0;i<k;i++)
  {
	cout<<str2[i];
  }
}