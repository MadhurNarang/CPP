   //PAIRWISE DESTRUCTION
   #include<iostream.h>
   #include<conio.h>
   #include<string.h>
   #include<stdio.h>
   typedef char word[10];
   int des(int n,char str[])
   {
     int i,l,j,g,p,res=n,m=0,k=0;
     char ch[10];
     word words[10];
      for(j=0;str[j]!='\0';j++)
      {
	if(str[j]==' ')
	 {
	   for(l=k,p=0;l<j;l++)
	   {
	     ch[p++]=str[l];
	   }
	   ch[p]='\0';
	   strcpy(words[m++],ch);
	   k=j+1;
	 }
      }
      for(j=0;j<n;j++)
      {
	for(k=0;k<m;k++)
	{
	 if(strcmp(words[k],words[k+1])==0)
	  {
	   for(g=k;g<m;g++)
	   {
	     strcpy(words[g],words[g+2]);
	   }
	   res-=2;
	  }
	}
      }
    return(res);
   }
   void main()
   {
     clrscr();
     int n,i,t,res[10];
     char str[100];
     cout<<"\nENTER THE NUMBER OF TEST CASES  \n ";
     cin>>t;
     for(i=0;i<t;i++)
     {
      cout<<"\nENTER THE NUMBER OF WORDS IN SEQUENCE "<<i+1<<endl;
      cin>>n;
      cout<<"\nENTER THE STRING \n ";
      gets(str);
      res[i]=des(n,str);
     }
     for(i=0;i<t;i++)
     {
      cout<<"\nNUMBER OF WORDS LEFT IN SEQUENCE "<<i+1<<" IS "<<res[i]<<endl;
     }
    getch();
   }