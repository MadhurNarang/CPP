//COMPARE,CONCATENATE STRING WITHOUT USING LIBRARY FUNCTIONS
#include<iostream.h>
#include<string.h>
#include<stdio.h>
void main()
{
  int len1,len2,i,j,k=0;
  char str1[50],str2[50],str3[100];

  cout<<"ENTER THE FIRST STRING  ";
  gets(str1);
  cout<<"ENTER THE SECOND STRING  ";
  gets(str2);
  len1=strlen(str1);
  len2=strlen(str2);

  if(len1!=len2)
	k=1;
  else
	if(len1==len2)
	{
	 for(i=0;i<len1;i++)
		{
		  if(str1[i]!=str2[i])
			{
			 k=1;
			 break;
			}
		  }
		}

  if(k==1)
	cout<<"\nENTERED STRINGS ARE NOT EQUAL";
  else
	cout<<"\nENTERED STRINGS ARE EQUAL";

  for(i=0;i<len1+len2;i++)
  {
	 if(i<len1)
	  str3[i]=str1[i];
	 else
	  {
		j=i-len1;
		str3[i]=str2[j];
	  }
	 str3[len1+len2]='\0';
  }

  cout<<"\n\nCONCATENATED STRING IS ";
  puts(str3);
}
