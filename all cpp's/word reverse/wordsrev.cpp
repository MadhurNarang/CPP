#include<iostream.h>
#include<string.h>
#include<stdio.h>
void main()
{
 int len,i,j,k=0,l,q=1;
 char str1[100],str2[100],count[20];
 count[0]=-1;
 cout<<"ENTER THE STRING  :  ";
 gets(str1);
 len=strlen(str1);
 for(i=0;i<len+1;i++)
	 {
		 if((str1[i]==' ')||(str1[i]=='\0'))
		 {
			j=i-1;
			count[q++]=i;
			for(l=0;l<(count[q-1]-count[q-2]-1);l++,j--)
			  {
				 str2[k++]=str1[j];
			  }
				 str2[k++]=' ';
	   }
	 }
  cout<<"NOW STRING IS:       ";
  for(i=0;i<k;i++)
  {
   cout<<str2[i];
  }
}