//AREA CALCULATOR USING FUNCTION OVERLOADING
#include<iostream.h>
#include<stdlib.h>                                      //HEADER FILES INCLUDED
#include<math.h>
#define pi 3.14                              //PREDEFINING VALUE USING # DEFINE
void area(float l1 ,float l2,float l3)                   //FUNCTION DECLARATION
{
 float area;                                              //FUNCTION DEFINITION
 float s=(l1+l2+l3)/2;
 area=sqrt((s)*(s-l1)*(s-l2)*(s-l3));
 cout<<"\nAREA OF TRIANGLE IS \n"<<area;
}
void area(float l1 ,float l2)                              //SAME FUNCTION NAME
{                                                    //I.E FUNCTION OVERLOADING
 float area;
 area=l1*l2;
 cout<<"\nAREA OF RECTANGLE IS \n"<<area;
}
void area(float l1)                                        //SAME FUNCTION NAME
{                                                    //I.E FUNCTION OVERLOADING
 float area;
 area=pi*l1*l1;
 cout<<"\nAREA OF CIRCLE IS \n"<<area;
}
void main()
{
 float l1,l2,l3;
 int choice;
 cout<<"PRESS 1 TO CALCULATE AREA OF TRIANGLE\n";
 cout<<"PRESS 2 TO CALCULATE AREA OF RECTANGLE\n";          //MENU INSTRUCTIONS
 cout<<"PRESS 3 TO CALCULATE AREA OF CIRCLE\n";
 cout<<"PRESS 4 TO EXIT\n";
 cin>>choice;
 switch(choice)                               //USING SWITCH FOR CHOICE ENTERED
 {
  case 1:
				cout<<"\nENTER THE THREE SIDES OF TRIANGLE\n";
				cin>>l1>>l2>>l3;
				area(l1,l2,l3);                                     //FUNCTION CALL
				break;
  case 2:
				cout<<"\nENTER THE SIDES OF RECTANGLE\n";
				cin>>l1>>l2;
				area(l1,l2);                                        //FUNCTION CALL
				break;
  case 3:
				cout<<"\nENTER THE RADIUS OF CIRCLE\n";
				cin>>l1;
				area(l1);                                           //FUNCTION CALL
				break;
  case 4:
				exit(0);

  default:
				cout<<"\nWRONG CHOICE ENTERED";
 }
}
