####################
#  AUTHOR : SHYAM RAJENDRAN : 
##################
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>


extern int x1,y1,x2,y2,k;
void intro();
void drawbasev();
void drawbr();
void drawcapv(int ,int, int, int);
void drawspringh();
void drawspringv();
void initialise();
void showmouse();
void readmouse();
void hidemouse();
void ordinates();
void into();
void ordinates2();
void ordinates3();
void ordinates4();
void co_2();
void co_1();
void click(int);
void translation();
void rotation();
void drawmass();
void drawpoth();
void drawpotv();
void drawindh(int, int, int,int);
void drawindv(int, int, int,int);
void confirmation();
void menu();
void main();
void realisevolage();
void realisecurrent();
void loopdivision(int);
void loopdivision2(int);
void drawresh(int, int, int, int);
void drawforceh();
void drawtor();
void drawresv(int,int,int,int);
void drawe(int);
void drawi(int,int);
void help();
extern union REGS regs;
void showmouse()
 {
  regs.x.ax=1;
  int86(0x33,&regs,&regs);
 }
  void readmouse()
 {
  regs.x.ax=3;
  int86(0x33,&regs,&regs);
  x1=regs.x.cx;
  y1=regs.x.dx;
  k=regs.x.bx&1;
 }
 void hidemouse()
 {
  regs.x.ax=2;
  int86(0x33,&regs,&regs);
 }
 void initialise()
     {
      int gdriver = DETECT, gmode, errorcode;
      initgraph(&gdriver, &gmode, "");
      errorcode = graphresult();
      if (errorcode != grOk)
      {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
      }
     regs.x.ax=0;
     int86(0x33,&regs,&regs);
   }

