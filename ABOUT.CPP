####################
#  AUTHOR : SHYAM RAJENDRAN : 
##################
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
extern first;
void help()               /*provides help to user*/
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");
window(10,5,40,11);
textcolor(RED);
textbackground(WHITE);
moveto(300,20);
settextstyle(2,0,4);
setbkcolor(9);
outtextxy(150,50,"\n\rELECTRICAL ANALOGOUS EQUIVALENT CIRCUIT SIMULATION FOR MECHNICAL SYSTEMS ");
outtextxy(150,60,"                        IN C LANGUAGE");
outtextxy(20,90,"ABSTRACT");
outtextxy(20,95,"--------");
outtextxy(20,110,"The projects objective is to obtain equivalent electrical analogous circuits for the user designed");
outtextxy(20,120,"mechanical systems");
outtextxy(20,130,"Usually the design of mechanical systems (say a suspension system) calls for the design using the ");
outtextxy(20,140,"traditional mechanical design elements like dashpots , springs to represent frictional force and other ");
outtextxy(20,150,"forces involved. In modern days of computer aided design and simutions , the need for accurate ");
outtextxy(20,160,"representation thus brings in the use of electrical analogous circuits for further study of the");
outtextxy(20,170,"mechanical systems. The electrical systems once designed are far easier to work with than its ");
outtextxy(20,180,"mechanical counterparts.");
outtextxy(20,190,"This projects aims to bridge the gap between conversions of mechanical system design to electrical ");
outtextxy(20,200,"analogous system using c language as its base by providing interactive design environment.");
outtextxy(20,220,"The user is given the choice as to choose force current or force voltage electrical analogous ");
outtextxy(20,230,"according to his needs. Once designed, the Force-Current(F-I) and Force-Voltage(F-V) electrical ");
outtextxy(20,240,"equivalent circuit can be obtained by clicking on the appropriate buttons on the design screen.");
outtextxy(20,250+5,"ALGORITHM");
outtextxy(20,255+5,"---------");
outtextxy(20,260+5+5,"1.	The user is given a choice as to choose translation mechanical system or rotational system.");
outtextxy(20,280+5+5,"2.	Once chosen the user can design any mechanical system from the tools available in the tools ");
outtextxy(20,290+5+5,"palette of the design window.");
outtextxy(20,310+5+5,"3.	Appropriate names given to the designed elements.");
outtextxy(20,340+5+5,"4.	The user can now choose to obtain either F-I(Force Current) or F-V(Force-Voltage) equivalent ");
outtextxy(20,350+5+5,"electrical system for the designed mechanical model.");
outtextxy(20,370+5+5,"5.	The functions realisevoltage() and realisecurrent() are written to be called as per user needs ");
outtextxy(20,380+5+5,"via mouse interaction for obtaining the corresponding equivalent circuits.");
outtextxy(20,400+5+5,"6.	The program then logically computes the electrical equivalent circuit for the designed model and ");
outtextxy(20,410+5+5,"displays in the same design window.");
outtextxy(20,430+5+5,"7.	Easy navigation is provided by using graphics and mouse interface.");
outtextxy(0,455,"........................................press any key to Return..............................................................................................");
getch();
}

void into()               /*welcomes user with brief introduction*/
				  /*about software*/
{
    clrscr();
    if(first!=1)
     {
     textcolor(4);
   cprintf("\n\n\n\n               Electrical Analogous Circuit Design\r\n\n\n");
   textcolor(3);
   cprintf("\n\n        This simulator helps to design the mechanical system,  both \n\n\r   \"TRANSLATION SYSTEM\" and \"ROTATIONAL SYSTEM\" and to find the \n\n\r    electrical anaolgous circuits \"FORCE-VOLTAGE\" as well as \"FORCE-CURRENT\" \n\n\r   Equivalent Analogou Circuit for the designed mechanical system\r\n");
   cprintf("\n\n\n              Press Any Key To Run Software........");
   first=1;
   getch();
     }
}
