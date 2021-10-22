#include<iostream.h>
void main()
{
  float a,b,c,d,e,p;
  char g;
  cin>>a>>b>>c>>d>>e;
  p=(a+b+c+d+e)/5;

  if(p>=90)
	  g='A';

			else
				if(p<90&&p>=80)
					g='B';


						 else
							 if(p<80&&p>=65)
											g='C';


											  else
												if(p<65&&p>=60)
														  g='D';


														  else
															if(p<60&&p>=40)
																	g='E';


																	else
																		if(p<40)
																				  g='E';
 cout<<g;
}





