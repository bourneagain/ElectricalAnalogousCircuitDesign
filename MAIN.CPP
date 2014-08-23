####################
#  AUTHOR : SHYAM RAJENDRAN : 
##################
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<graphics.h>
#include<about.cpp>
#include<screen.cpp>
#include<gui.cpp>
#include<ctype.h>

#pragma warn -par          /*to supress warnings*/
#pragma warn -aus

#define X1 161             /*defines the loop co ordinates on screem*/
#define X2 595
#define Y1 169
#define Y2 322
void intro();              /*list of function prototypes*/
void drawbasev();
void drawbr();
void drawcapv(int ,int, int, int);
void drawspringh();
void drawspringv();
void initialise();
void showmouse();
void hidemouse();
void ordinates();
void into();
void ordinates2();
void ordinates3();
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
void RealiseVolt();
void RealiseCurrent();
void RealiseVoltLoopDivision(int);
void RealiseCurrentLoopDivision(int);
void drawresh(int, int, int, int);
void drawforceh();
void drawtor();
void drawresv(int,int,int,int);
void drawe(int);
void drawi(int,int);
void help();

struct maco{              //to store mass co ordinates
int x1;
int y1;
int x2;
int y2;
}om[12];
struct shco{              //horizantal spring co ordinates
int x1;
int y1;
int x2;
int y2;
}osh[12];
struct svco{              //vertical spring co ordinates
int x1;
int y1;
int x2;
int y2;
}osv[12];
struct dvco{              //vertical dashpot co ordinates
int x1;
int y1;
int x2;
int y2;
}odv[12];
struct dhco{              //horizantal dashpot co ordinates
int x1;
int y1;
int x2;
int y2;
}odh[12];
struct fh{                //force co ordinates
int x1;
int y1;
}ofh[12];
struct bvco{              //vertical base cordinates
int x1;
int y1;
}obv;
struct br{
int x1;
int y1;
}obr[12];
struct ta{
int x1;
int y1;
}ota[12];

union REGS regs;          /*to pass information to int86 function*/
char *str;                /*to display element name on screen*/
int  ta=1;                /*torque anticlockwise*/
int x1,y1,k;              /*to store mouse coordinates*/
int flag=0;
extern int first=0;

int xx,yy,xx1,yy1,b,incount=0;
int screen=0,bv=0,BR=0,RV=0,Rh=0,IV=0,CV=0;

int fh=0,m=0,sv=0,sh=0,dv=0,dh=0;
int br;                   /*indicates no. of bases*/
int p[5];                 /*indicates nodes in circuit*/

void RealiseVolt()        /*this function obtains Force-Voltage Analogous circuit*/
{
   incount++;
   BR=RV=Rh=IV=CV=0;
   if(m==0)
    {
     outtextxy(250,200,"Place mass first and then try again!!");
     getch();
     translation();
    }
   hidemouse();
   outtextxy(250,440,"Force-Voltage Electrical Analogous Circuit");
   setfillstyle(1,BLACK);
   bar(120,42,630,420);
   rectangle(X1,Y1,X2,Y2);
   if(m==1)
   {
    drawindh(X1+10,Y1,X1,Y1);
    drawresh(X1+90,Y1,X1+130,Y1);
   }

  if(m!=1)
  RealiseVoltLoopDivision(m);
  showmouse();
  getch();
  if(incount==2)m=sh=dh=0;
  translation();
}


void RealiseVoltLoopDivision(int m)  /*synthesis of loops in circuit*/
{
 int dispr=0,dispv=0,displ=0,inpar=0;
  for(int j=1;m!=1&&j<=m;j++)
  {
  if(j==m) goto f;
  line((X2-X1)/m*j+X1,Y1,(X2-X1)/m*j+X1,Y2);
  f:
  j--;
  drawindh((X2-X1)/m*j+X1+8,Y1,(X2-X1)/m*j+X1+8,Y2);

  j++;
  }
 for(int l=1;l<=ta;l++)
   {
    for(int i=1;i<=m;i++)
	{
	if((i!=m) && ota[l].x1>=om[i].x1&&ota[l].x1<=om[i].x2)
	{
	drawi(i,displ);
	displ+=20;
	}

	if((i==m) && ota[l].x1>=om[i].x1&&ota[l].x1<=om[i].x2)
	{
	drawi(i,dispr+20);
	dispr+=20;
	}
	}
   }

 for(int i=1;i<=sh;i++)
  for(k=1;k<=m;k++)
 {
 if(osh[i].x1<=om[k].x2&&osh[i].x2<=om[k+1].x2)
   {
    drawcapv((X2-X1)/m*k+X1,Y1+(Y2-Y1)/2-50,(X2-X1)/m*k+X1,Y1+(Y2-Y1)/2-30);
    break;
   }
 }
 for(i=1;i<=sh;i++)
 for(k=1;k<=m;k++)
  if(bv==1&&osh[i].x1<=om[k].x2&&osh[i].x2>=obv.x1)
  {
   drawcapv(X1+(X2-X1)/m*(k),Y1+(Y2-Y1)/2-50,X1+(X2-X1)/m*k,Y1+(Y2-Y1)/2-30);
   break;
  }


 for(i=1;i<=fh;i++)
  for(k=1;k<=m;k++)
 {if(ofh[i].x1>=om[k].x1&&ofh[i].x1<=om[k].x2)
   drawe(k);
 }

 for(i=1;i<=dh;i++)
  for(k=1;k<=m;k++)
 {
 if(odh[i].x1<=om[k].x2&&odh[i].x2<=om[k+1].x2)
   {
    drawresv((X2-X1)/m*k+X1,Y1+40,(X2-X1)/m*k+X1,Y2+60);
    break;
   }
  if(odh[i].x1<=om[k].x2&&odh[i].x2>=obv.x1)
   drawresv((X2-X1)/m*k+X1,Y1+40,(X2-X1)/m*k+X1,Y2+60);
 }
 for(l=1;l<=br;l++)
 for(i=1;i<=m;i++)
 if(obr[l].x1>=om[i].x1&&obr[l].x1<=om[i].x2)
 {
 drawresh(X1+(X2-X1)/m*i-50,Y1,X1+(X2-X1)/m*i-30,Y1);
 break;
 }
}


void RealiseCurrent()     /*to obtains Force-Current Equivalent*/
 {
 incount++;
 BR=RV=Rh=IV=CV=0;
 if(m==0)
 {
 outtextxy(250,200,"Place mass first and then try again!!");
 getch();
 translation();
 }

 hidemouse();
 outtextxy(250,440,"Force-Current Electrical Analogous Circuit");
 setfillstyle(1,BLACK);
 bar(120,42,630,420);

 if(m!=1)
 RealiseCurrentLoopDivision(m);
 showmouse();
 getch();
 if(incount==2)
 m=sh=dh=br=0;
 translation();
}



void RealiseCurrentLoopDivision(int m)  /*to synthesis current loops in circuit*/
{
 int dispr=0,dispv=0,displ=0,inpar=0;
 for(int i=2;i<=m;i++)
 {
  p[m-i]=(X2-X1)/m*(i-1)+X1-(200/m);
  circle(p[m-i],Y1,2);
  line(p[m-i],Y1,p[m-i],Y1+(Y2-Y1)/2);
  line(p[m-i],Y2,p[m-i],Y1+(Y2-Y1)/2);
  drawcapv(p[m-i],Y1+(Y2-Y1)/2-10,p[m-i],Y1+(Y2-Y1)/2+10);
 }
  for(i=2;i<=m;i++)
  line(X2-200/m,Y1,p[m-i],Y1);

  circle(X2-200/m,Y1,2);
  line(X2-200/m,Y1,X2-200/m,Y1+(Y2-Y1)/2);
  line(X2-200/m,Y2,X2-200/m,Y1+(Y2-Y1)/2);
  drawcapv(X2-200/m,Y1+(Y2-Y1)/2-10,X2-200/m,Y1+(Y2-Y1)/2+10);

 for(int l=1;l<=fh;l++)
   {
    for(i=1;i<=m;i++)
	{
	if((i!=m) && ofh[l].x1>=om[i].x1&&ofh[l].x1<=om[i].x2)
	{
	drawi(i,displ);   //to place voltage source
	displ+=20;
	}

	if((i==m) && ofh[l].x1>=om[i].x1&&ofh[l].x1<=om[i].x2)
	{
	drawi(i,dispr+20);
	dispr+=20;
	}
	}
   }

 if(obv.x1!=0)
 {
  for(int j=1;j<=sh;j++)
  {
   for(i=1;i<=m;i++)
   if(i==m && (osh[j].x1<=om[i].x2)&& (osh[j].x2>=obv.x1))
   {
     line(X2-200/m+dispr+20,Y1,X2-200/m+dispr+20,Y1+(Y2-Y1)/2-8);
     line(X2-200/m+dispr+20,Y2,X2-200/m+dispr+20,Y1+(Y2-Y1)/2-2);
     drawindv(X2-200/m+dispr+20,Y1+(Y2-Y1)/2-10,X2-200/m+dispr+20,Y1+(Y2-Y1)/2+10);
     dispr+=20;
     break;
   }
  }
 }

 if(obv.x1!=0)
    for(int k=1;k<=dh;k++)
   {
    for(i=1;i<=m;i++)
    if(i==m && (odh[k].x1<=om[i].x2) && (odh[k].x2>=obv.x1) )
    {
    line(X2-200/m+dispr+20,Y1,X2-200/m+dispr+20,Y1+(Y2-Y1)/2-10);
    line(X2-200/m+dispr+20,Y2,X2-200/m+dispr+20,Y1+(Y2-Y1)/2+10);
    drawresv(X2-200/m+dispr+20,Y1+(Y2-Y1)/2-10,X2-200/m+dispr+20,Y1+(Y2-Y1)/2+10);
    dispr+=20;
    break;
    }
   }

   for(l=1;l<=ta;l++)
   {
    for(i=1;i<=m;i++)
	{
	if((i!=m) && ota[l].x1>=om[i].x1&&ota[l].x1<=om[i].x2)
	{
	drawi(i,displ);
	displ+=20;
	}

	if((i==m) && ota[l].x1>=om[i].x1&&ota[l].x1<=om[i].x2)
	{
	drawi(i,dispr+20);
	dispr+=20;
	}
	}
   }

  for(l=1;l<=br;l++)
   {   for(i=1;i<=m;i++)
	if(obr[l].x1>=om[i].x1&&obr[l].x1<=om[i].x2)
	{
	if(i!=m)
	{
	line(p[m-i-1]-displ-20,Y1,p[m-i-1]-displ-20,Y2);
	drawresv(p[m-i-1]-displ-20,Y1+(Y2-Y1)/2-20,p[m-i-1]-displ-20,Y1+(Y2-Y1)/2+10);
	displ+=20;
	}
	else
	{
	line(X2-200/m+dispr+20,Y1,X2-200/m+dispr+20,Y2);
	drawresv(X2-200/m+dispr+20,Y1+(Y2-Y1)/2-20,X2-200/m+dispr+20,Y1+(Y2-Y1)/2+10);
	 dispr+=20;
	}
	}
   }

   for(int j=1;j<=dh;j++)
   {
   for(i=1;i<=m;i++)
   {
    if(i==1 && (m==3) && (odh[j].x1<=om[i].x2) && (odh[j].x2>=om[i+1].x1) )
    {
    drawresh( (p[0]-p[i])/2+p[i]-25, Y1-dispv-20, (p[0]-p[i])/2+p[i]-5, Y1-dispv-20);
    setfillstyle(1,BLACK);
    line((p[0]-p[i])/2+p[i]-25, Y1,(p[0]-p[i])/2+p[i]-25,Y1-dispv-20);
    line((p[0]-p[i])/2+p[i]+5, Y1,(p[0]-p[i])/2+p[i]+5,Y1-dispv-20);
    bar((p[0]-p[i])/2+p[i]-25, Y1,(p[0]-p[i])/2+p[i]+3, Y1+6);
    dispv+=20;
    inpar=1;
     break;
    }
    if(i==1 && (m==2)&&(odh[j].x1<=om[i].x2) && (odh[j].x2>=om[i+1].x1) )
    {
    drawresh( (p[0]-X1+200/m)/2+p[0]-25, Y1-dispv-20, (p[0]-X1+200/m)/2+p[0], Y1-dispv-20);
    setfillstyle(1,BLACK);
    bar((X2-200/m-p[0])/2+p[0]-25, Y1,(X2-200/m-p[0])/2+p[0],Y1+3);
    line((X2-200/m-p[0])/2+p[0]-25, Y1,(X2-200/m-p[0])/2+p[0]-25,Y1-dispv-20);
    line((X2-200/m-p[0])/2+p[0]+5, Y1,(X2-200/m-p[0])/2+p[0]+5,Y1-dispv-20);

    dispv+=20;
    inpar=1;
    break;
    }

    if(i==2 && i!=m && (odh[j].x1<=om[i].x2) && (odh[j].x2>=om[i+1].x1) )
    {
    drawresh( (X2-200/m-p[0])/2+p[0]-15, Y1-dispv-20, (X2-200/m-p[0])/2+p[0]+5, Y1-dispv-20);
    setfillstyle(1,BLACK);
    line((X2-200/m-p[0])/2+p[0]-15, Y1,(X2-200/m-p[0])/2+p[0]-15,Y1-dispv-20);
    line((X2-200/m-p[0])/2+p[0]+15, Y1,(X2-200/m-p[0])/2+p[0]+15,Y1-dispv-20);
    bar((X2-200/m-p[0])/2+p[0]-15, Y1,(X2-200/m-p[0])/2+p[0]+15,Y1+3);
    dispv+=20;
    inpar=1;
    }

    if( (i==3) && (i!=m) &&(osh[j].x1<=om[i].x2) && (osh[j].x2>=om[i+1].x1) )
    {
    drawresh( (p[0]-X1)/2+p[0]-10, Y1-dispv-20, (p[0]-X1)/2+p[0]+10, Y1-dispv-20);
    setfillstyle(1,BLACK);
    line((X2-200/m-p[0])/2+p[0]-15, Y1,(X2-200/m-p[0])/2+p[0]-15,Y1-dispv-20);
    line((X2-200/m-p[0])/2+p[0]+15, Y1,(X2-200/m-p[0])/2+p[0]+15,Y1-dispv-20);
    bar((X2-200/m-p[0])/2+p[0]-15, Y1,(X2-200/m-p[0])/2+p[0]+15,Y1+3);
    dispv+=20;
    inpar=1;
    }
   }
  }

 for(j=1;j<=sh;j++)
   {
   for(i=1;i<=m;i++)
   {
    if(i==1&& (osh[j].x1<=om[i].x2) && (osh[j].x2>=om[i+1].x1) )
    {
    drawindh( (p[m-(i+1)]-(X1-200/m))/2+p[m-(i+1)]-20, Y1-dispv-20, (p[m-(i+1)]-(X1-200/m))/2+p[m-(i+1)]+5, Y1-dispv-20);
    setfillstyle(1,BLACK);
    bar((p[m-(i+1)]-(X1-200/m))/2+p[m-(i+1)]-25, Y1-3, (p[m-(i+1)]-(X1-200/m))/2+p[m-(i+1)]+3, Y1+3);
    line((p[m-(i+1)]-(X1-200/m))/2+p[m-(i+1)]-25, Y1, (p[m-(i+1)]-(X1-200/m))/2+p[m-(i+1)]-25, Y1-dispv-20);
    line((p[m-(i+1)]-(X1-200/m))/2+p[m-(i+1)]+5, Y1, (p[m-(i+1)]-(X1-200/m))/2+p[m-(i+1)]+5, Y1-dispv-20);
    dispv+=20;
    inpar=1;
    break;
    }

    if(i==2 && (i+1==m)&& (osh[j].x1<=om[i].x2) && (osh[j].x2>=om[i+1].x1) )
    {
    drawindh( (X2-200/m-p[0])/2+p[0]-10, Y1-dispv-20, (X2-200/m-p[0])/2+p[0]+10, Y1-dispv-20);
    setfillstyle(1,BLACK);
    bar((X2-200/m-p[0])/2+p[0]-15, Y1, (X2-200/m-p[0])/2+p[0]+15, Y1+5);
    line((X2-200/m-p[0])/2+p[0]-15, Y1, (X2-200/m-p[0])/2+p[0]-15, Y1-dispv-20);
    line((X2-200/m-p[0])/2+p[0]+15, Y1, (X2-200/m-p[0])/2+p[0]+15, Y1-dispv-20);
    dispv+=20;
    inpar=1;
    break;
    }

    if( (i==3) && (i+1==m) &&(osh[j].x1<=om[i].x2) && (osh[j].x2>=om[i+1].x1) )
    {
    drawindh( (X2-200/m-p[0])/2+p[0]-10, Y1-dispv-20, (X2-200/m-p[0])/2+p[0]+10, Y1-dispv-20);
    setfillstyle(1,BLACK);
    bar((X2-200/m-p[0])/2+p[0]-15, Y1, (X2-200/m-p[0])/2+p[0]+15, Y1+5);
    line((X2-200/m-p[0])/2+p[0]-15, Y1, (X2-200/m-p[0])/2+p[0]-15, Y1-dispv-20);
    line((X2-200/m-p[0])/2+p[0]+15, Y1, (X2-200/m-p[0])/2+p[0]+15, Y1-dispv-20);
    dispv+=20;
    inpar=1;
    break;
    }
  }
  }

  line(p[m-2]-displ,Y2,X2-200/m+dispr,Y2);
  line(p[m-2],Y1,p[m-2]-displ,Y1);
  line(X2-200/m,Y1,X2-200/m+dispr,Y1);
 }


void click(int z)   /*calls appopriate functions as per mouse click*/
    {
	 while(k)       /*left mouse button status checked*/ 
	  {
		readmouse();/*mouse co ordinates are read */
		if(!k)
		  {
		   switch(z)
		   {
		   case 1:
		   translation();
		   break;
		   case 2:
		   rotation();
		   break;
		   case 3:
		   confirmation();
		   break;
		   case 4:
		   closegraph();
		   exit(0);
		   break;
		   case 11:
		   drawmass();
		   break;
		   case 12:
		   confirmation();
		   break;
		   case 13:
		   drawspringh();
		   break;
		   case 14:
		   drawspringv();
		   break;
		   case 15:
		   drawpoth();
		   break;
		   case 16:
		   drawpotv();
		   break;
		   case 17:
		   RealiseVolt();
		   break;
		   case 18:
		   drawforceh();
		   break;
		   case 19:
		   drawbasev();
		   break;
		   case 20:
		   drawbr();
		   break;
		   case 21:
		   RealiseCurrent();
		   break;
		   case 22:
		   drawtor();
		   break;
		   case 23:
		   main();
		   break;
		   case 25:
		   help();
		   setfillstyle(1,BLACK);
		   bar(0,0,639,459);
		   menu();
		   break;
		    }
		  }
	     }
	}


void click2(int z)
    {
	 while(k)
	  {
		readmouse();
		if(!k)
		  {
		   switch(z)
		   {
		   case 1:
		   showmouse();
		   cleardevice();
		   closegraph();
		   exit(0);
		   break;
		   case 2:
		   showmouse();
		   m=dh=sh=fh=0;
		   main();
		   break;
		    }
		  }

	  }
     }

void ordinates4()
    {
     showmouse();
	while(1)
	 {
	  delay(30);
	    {
	   setfillstyle(1,RED);
	   bar(28,460,630,472);
	    }
	   gotoxy(73,30);
	   readmouse();
	   if(((x1>4&&x1<113)&&y1>70)&&y1<116)
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Draws Mass Between Two Click Points Of mouse");
	     click(11);
	     break;
	     }

	     if(((x1>600&&x1<639)&&y1>0)&&y1<40)
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Click Here To Terminate Program");
	     click(12);
	      }

	     if((x1>4&&x1<58)&&(y1>145&&y1<195))
	      {
	      settextstyle(2, HORIZ_DIR,0);
	      outtextxy(30,460,"Draws Spring Between Two Click Points Of Mouse");
	      click(13);
	      }
	     if(((x1>57&&x1<112)&&y1>146)&&y1<195)
	     {
	      click(14);
	      break;
	     }
	     if(((x1>4&&x1<57)&&y1>227)&&y1<277)
	     {
	      settextstyle(2, HORIZ_DIR,0);
	      outtextxy(30,460,"Draws DashPot Between Two Click Points Of Mouse");
	       click(15);
	       break;
	      }
	     if((x1>58&&x1<112)&&(y1>227&&y1<277))
	     {
	       click(16);
	       break;
	     }
	     if((x1>117&&x1<193)&&(y1>41&&y1<72))
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Click Here To Get Force-Voltage Equivalent Circuit");
	     click(17);
	     break;
	     }
	     if((x1>4&&x1<31)&&(y1>327&&y1<364))
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Point And Click Mouse to place torque T");
	     click(22);
	     break;
	     }
	     if((x1>59&&x1<83)&&(y1>375&&y1<423))
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Click to place a vertical base");
	     click(19);
	     break;
	     }
	     if((x1>85&&x1<111)&&(y1>315&&y1<338))
	     {
	     click(20);
	     break;
	     }
	     if((x1>193&&x1<250)&&(y1>41&&y1<72))
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Click Here To Get Force-Current Equivalent Circuit");
	     click(21);
	     break;
	     }

	     if((x1>562&&x1<600)&&(y1>0&&y1<40))
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Click Here To Go to Home Page");
	     click(23);
	     break;
	     }
	  }

    }


void ordinates3()
    {
    showmouse();
	while(1)
	 {
	 delay(30);
	    {
	     setfillstyle(1,RED);
	     bar(28,460,630,472);
	    }
	    gotoxy(73,30);
	    readmouse();
	    if(((x1>4&&x1<113)&&y1>70)&&y1<116)
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Draws Mass Between Two Click Points Of mouse");
	     click(11);
	     break;
	     }

	     if(((x1>600&&x1<639)&&y1>0)&&y1<40)
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Click Here To Terminate Program");
	     click(12);
	     }

	     if((x1>4&&x1<58)&&(y1>145&&y1<195))
	      {
	      settextstyle(2, HORIZ_DIR,0);
	      outtextxy(30,460,"Draws Spring Between Two Click Points Of Mouse");
	      click(13);
	      }
	     if(((x1>57&&x1<112)&&y1>146)&&y1<195)
	     {
	       click(14);
	       break;
	     }
	     if(((x1>4&&x1<57)&&y1>227)&&y1<277)
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Draws DashPot Between Two Click Points Of Mouse");
	     click(15);
	     break;
	     }
	     if((x1>58&&x1<112)&&(y1>227&&y1<277))
	     {
	       click(16);
	       break;
	     }
	     if((x1>117&&x1<193)&&(y1>41&&y1<72))
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Click Here To Get Force-Voltage Equivalent Circuit");
	     click(17);
	     break;
	     }
	     if((x1>30&&x1<54)&&(y1>316&&y1<340))
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Point And Click Mouse to place Force F");
	     click(18);
	     break;
	     }
	     if((x1>59&&x1<83)&&(y1>375&&y1<423))
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Click to place a vertical base");
	     click(19);
	     break;
	     }
	     if((x1>85&&x1<111)&&(y1>315&&y1<338))
	     {
	     click(20);
	     break;
	     }
	     if((x1>193&&x1<250)&&(y1>41&&y1<72))
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Click Here To Get Force-Current Equivalent Circuit");
	     click(21);
	     break;
	     }

	     if((x1>562&&x1<600)&&(y1>0&&y1<40))
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     outtextxy(30,460,"Click Here To Go to Home Page");
	     click(23);
	     break;
	     }
	    }
      }

void ordinates2()
    {
    showmouse();
	while(1)
	 {
	   readmouse();
	    if(((x1>200&&x1<294)&&y1>246)&&y1<278)
	     {
	      click2(1);
	      break;
	     }
	     if(((x1>325&&x1<495)&&y1>256)&&y1<278)
	     {
	       click2(2);
	       break;
	     }
	 }
    }

void ordinates()
  {
    showmouse();
    while(1)
	 {
	   moveto(200,100);
	   readmouse();
	   if(((x1>139&&x1<458)&&y1>94)&&y1<181)
	     {
	     setcolor(RED);
	     rectangle(139,94,458,181);
	     line(139,180,458,180);
	     setcolor(6);
	     line(139,179,458,179);
	     setcolor(6);
	     line(457,94,457,181);
	     line(456,94,456,181);
	     settextstyle(3, HORIZ_DIR, 3);
	     setcolor(RED);
	     outtextxy(220,145, "TRANSLATION");
	     setcolor(WHITE);
	     click(1);
	     break;
	     }
	     else
	     {
	     setcolor(WHITE);
	     rectangle(139,94,458,181);
	     setcolor(8);
	     line(139,180,458,180);
	     setcolor(8);
	     line(457,94,457,181);
	     line(456,94,456,181);
	     setcolor(WHITE);
	     settextstyle(3, HORIZ_DIR, 3);
	     outtextxy(220,145, "TRANSLATION");
	     }

	     if(((x1>139&&x1<458)&&y1>247)&&y1<339)
	     {
	     setcolor(RED);
	     outtextxy(245,280,"ROTATION");
	     rectangle(139,243,458,332);
	     setcolor(6);
	     line(139,332,458,332);
	     line(139,331,458,331);
	     setcolor(6);
	     line(457,243,457,332);
	     line(456,243,456,332);
	     setcolor(WHITE);
	     click(2);
	       break;
	      }
	     else
	     {
	      settextstyle(3, HORIZ_DIR, 3);
	      setcolor(WHITE);
	      outtextxy(245,280, "ROTATION");
	      rectangle(139,243,458,332);
	      setcolor(8);
	      setcolor(8);
	      line(457,243,457,332);
	      line(456,243,456,332);
	      setcolor(WHITE);
	     }
	     if(((x1>564&&x1<602)&&y1>0)&&y1<40)
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     setcolor(4);
	     outtextxy(500,40,"Click Here To Know About This Project");
	     setcolor(WHITE);
	     click(25);
	     break;
	     }
	     else
	     {
	     setcolor(0);
	     setfillstyle(1,7);
	     bar(500,42,639,50);
	     setcolor(WHITE);
	     }
	     if(((x1>601&&x1<630)&&y1>0)&&y1<40)
	     {
	     settextstyle(2, HORIZ_DIR,0);
	     setcolor(4);
	     outtextxy(500,40,"Click here to Terminate");
	     setcolor(WHITE);
	     click(3);
	     break;
	     }
	     else
	     {
	     setcolor(0);
	     setfillstyle(1,7);
	     bar(500,42,639,50);
	     setcolor(WHITE);
	     }
	  }
      }


void intro()
    {
    while(1)
    ordinates();
    }

void co_2()
   {
	while(k)
	  {
	     readmouse();
	     if(!k)
		{
		   xx1=x1;yy1=y1;
		}
	     flag=1;
	  }
  }

void co_1()
  {
	while(k)
	{
	   readmouse();
	   if(!k)
	     {
		 xx=x1;yy=y1;
	     }
	   flag=1;
	}
  }

  void drawtor()
    {
	flag=0;
	while(1)
	   {
	     readmouse();
		{
		 co_1();
		 if(flag)
		 break;
		}
	   }
	   ota[ta].x1=xx;
	   ota[ta].y1=yy;
	   hidemouse();
	   line(xx+6-40,yy-17,xx+4-40,yy-11);
	   line(xx+6-40,yy-17,xx+12-40,yy-19);
	   line(xx,yy,xx-40,yy);
	   ellipse(xx-40, yy,  300,70,15,20 );
	  settextstyle(2, HORIZ_DIR, 4);
	  sprintf(str,"T%d",ta++);
	  outtextxy(xx+(x1-xx)/2-50,yy+(y1-yy)/2-12,str);
	  showmouse();
}

 void drawmass()
    {   m++;
	flag=0;
	while(1)
	   {
	     readmouse();
	     {
		 co_1();
		 if(flag)
		   break;
		}
	   }
	   om[m].x1=xx;
	   om[m].y1=yy;
	flag=0;
	while(1)
	  {
	  readmouse();
		{
		  co_2();
		  if(flag)
		    break;
		}
	  }
	  om[m].x2=xx1;
	  om[m].y2=yy1;
	  hidemouse();
	  rectangle(xx,yy,xx1,yy1);
	  settextstyle(2, HORIZ_DIR, 4);
	  sprintf(str,"M %d",m);
	  outtextxy(xx+(x1-xx)/2-8,yy+(y1-yy)/2,str);
	  showmouse();
}


void drawspringh()
    {   sh++;
	flag=0;
	while(1)
	   {
	     readmouse();

		{
		 co_1();
		 if(flag)
		   break;
		}
	   }
	   osh[sh].x1=xx;
	   osh[sh].y1=yy;
	   flag=0;
	  while(1)
	  {
	  readmouse();

		{
		    co_2();
		    if(flag)
		    break;
		}
	  }
	  osh[sh].x2=xx1;
	  osh[sh].y2=yy1;
	  b=xx;
	  hidemouse();
	  line(xx,yy,xx+8,yy);
	  line(x1,yy,x1-8,yy);
	   xx+=12;
	  for(;xx<x1-12;xx+=5)
	  circle(xx,yy,4);
	  circle(x1-12,yy,4);

	  showmouse();
	  settextstyle(2, HORIZ_DIR, 4);
	  sprintf(str,"K %d",sh);
	  outtextxy(b+(x1-b)/2,yy-20,str);
 }

void drawspringv()
    {   sv++;
	flag=0;
	while(1)
	   {
	     readmouse();

		{
		 co_1();
		 if(flag)
		   break;
		}
	   }
	   osv[sv].x1=xx;
	   osv[sv].y1=yy;
	flag=0;
	while(1)
	  {
	  readmouse();

		{
		  co_2();
		  if(flag)
		    break;
		}
	  }
	  osv[sv].x2=x1;
	  osv[sv].y2=y1;
	  hidemouse();
	  line(xx,yy,xx,yy+8);
	  circle(xx,yy+12,4);
	  b=yy;
	  for(;;b+=8)
	  {circle(xx,b+10,4);
	  if(b>=(y1-24))break;}
	  line(xx,y1,xx,y1-8);
	   showmouse();
	   gotoxy(1,29);
	   settextstyle(2, HORIZ_DIR, 4);
	 sprintf(str,"K %d",sv);
	  outtextxy(xx+9,yy+(y1-yy)/2,str);
 }

void drawpoth()
{
    dh++;
	flag=0;
	while(1)
	   {
	     readmouse();

		{
		 co_1();
		 if(flag)
		   break;
		}
	   }
	   odh[dh].x1=xx;
	   odh[dh].y1=yy;

	flag=0;
	while(1)
	  {
	  readmouse();
		{
		  co_2();
		  if(flag)
		    break;
		}
	  }
	  odh[dh].x2=x1;
	  odh[dh].y2=y1;
	  hidemouse();
	  line(xx,yy,xx+(xx1-xx)/2-9,yy);
	  line(xx+(xx1-xx)/2,yy,x1,yy);
	  line(xx+(xx1-xx)/2-9,yy-6,xx+(xx1-xx)/2-9,yy+6);
	  line(xx+(xx1-xx)/2,yy-12,xx+(xx1-xx)/2,yy+12);
	  line(xx+(xx1-xx)/2,yy-12,xx+(xx1-xx)/2-12,yy-12);
	  line(xx+(xx1-xx)/2,yy+12,xx+(xx1-xx)/2-12,yy+12);
	  settextstyle(2, HORIZ_DIR, 4);
	  gotoxy(1,29);
	  sprintf(str,"B %d",dh);
	  outtextxy(xx+(x1-xx)/2-30,yy+5,str);
	  showmouse();
}


void drawpotv()
{
    dv++;
	flag=0;
	while(1)
	   {
	     readmouse();
		{
		 co_1();
		 if(flag)
		   break;
		}
	   }
	   odv[dv].x1=xx;
	   odv[dv].x2=yy;
	flag=0;
	while(1)
	  {
	  readmouse();
		{
		  co_2();
		  if(flag)
		    break;
		}
	  }
	  odv[dv].x2=xx1;
	  odv[dv].y2=yy1;
	  hidemouse();
	  line(xx,yy,xx,yy+(y1-yy)/2-12);
	  line(xx,yy+(y1-yy)/2,xx,y1);
	 line(xx-4,yy+(y1-yy)/2-12,xx+4,yy+(y1-yy)/2-12);
	 line(xx-9,yy+(y1-yy)/2,xx+9,yy+(y1-yy)/2);
	 line(xx-9,yy+(y1-yy)/2,xx-9,yy+(y1-yy)/2-12);
	 line(xx+9,yy+(y1-yy)/2,xx+9,yy+(y1-yy)/2-12);
	 settextstyle(2, HORIZ_DIR, 5);
	 gotoxy(1,29);
	 sprintf(str,"B %d",dv);
	 outtextxy(xx+(x1-xx)/2-8,yy+(y1-yy)/2,str);
	 showmouse();
}


void drawindh(int xx,int yy,int x1,int y1)
{
 setfillstyle(1,BLACK);
 bar(xx,yy-4,xx+20,yy+4);
 int b=xx+20;
	 for(;;xx+=5)
	 {
	 circle(xx,yy,4);
	 if(xx>=b)
	 break;
	 }
	 sprintf(str,"L%d",++IV);
	 outtextxy(xx-10,yy-20,str);
}

void drawindv(int xx,int yy,int x1,int y1)
{
 setfillstyle(1,BLACK);
 bar(xx,yy-4,xx,yy+9);
 int b=yy+20;
	  for(;;yy+=5)
	 {
	 circle(xx,yy,4);
	 if(yy>=b)
	 break;
	 }
sprintf(str,"L%d",++IV);
outtextxy(xx+4,yy-30,str);
}

void drawresv(int xx,int yy, int x1,int y1)
{
setfillstyle(1,BLACK);
bar(xx-4,yy,xx+4,yy+44);
int a,b,c,d;
a=xx;b=yy+40;c=x1,d=y1;
yy+=3;
line(xx-4,yy,xx,yy-4);
for(;yy<=b;yy+=8)
{
line(xx-4,yy,xx+4,yy+4);
line(xx+4,yy+4,xx-4,yy+8);
}
line(a-3,yy,a,yy+3);
sprintf(str,"R%d",++RV);
outtextxy(xx+10,yy,str);

}

void drawbasev()
{       bv=1;
	flag=0;
	while(1)
	   {
	     readmouse();
		{
		 co_1();
		 if(flag)
		   break;
		}
	   }
	   hidemouse();
	  obv.x1=xx;
	  obv.y1=yy;
	  line(xx,yy-36,xx,yy+36);
	  for(int i=(yy-36);i<=(yy+36);i+=10)
	  line(xx,i,xx+10,i+10);
	  showmouse();
}


void drawe(int k)
{
setfillstyle(1,BLACK);
bar(X1+(X2-X1)/m*(k-1)+55,Y1,X1+(X2-X1)/m*(k-1)+47,Y1+8);
circle(X1+(X2-X1)/m*(k-1)+51,Y1,4);
outtextxy(X1+(X2-X1)/m*(k-1)+43,Y1-15,"- V +");
}

void drawi(int k,int disp)
{
setfillstyle(1,BLACK);
if(k!=m)
{
 line(p[(m-1)-k]-disp-20,Y1,p[(m-1)-k]-disp-20,Y2);
 bar(p[(m-1)-k]-disp-20-4,Y1+(Y2-Y1)/2-4,p[(m-1)-k]-disp-20+4,Y1+(Y2-Y1)/2+4);
 circle(p[(m-1)-k]-disp-20,Y1+(Y2-Y1)/2,4);
}
else
{
line(X2-200/m+disp,Y1,X2-200/m+disp,Y2);
bar(X2-200/m+disp-4,Y1+(Y2-Y1)/2-4,X2-200/m+4+disp,Y1+(Y2-Y1)/2+4);
circle(X2-200/m+disp,Y1+(Y2-Y1)/2,4);
}
}


void drawcapv(int a,int b, int c,int d)
{
 setfillstyle(1,BLACK);
 bar(a-7,b+3,a+7,b+7);
 line(a-7,b+3,a+7,b+3);
 line(a-7,b+7,a+7,b+7);
 sprintf(str,"C%d",++CV);
 outtextxy(a+4,b-10,str);
}

void drawresh(int xx,int yy, int x1, int y1)
{
 setfillstyle(1,BLACK);
 bar(xx,yy-4,xx+30,yy+4);
 int a,b,c,d;
 a=xx;b=yy;c=x1,d=y1;
 xx+=3;
 line(xx-3,yy,xx,yy+4);
 for(;xx<=x1;xx+=8)
 {
  line(xx,yy+4,xx+4,yy-4);
  xx+=4;
  yy-=4;
  line(xx,yy,xx+4,yy+8);
  xx-=4;
  yy+=4;
 }
 line(xx+1,yy+4,a+31,b);
 sprintf(str,"R%d",++Rh);
 outtextxy(xx,yy-10,str);
}

void drawforceh()
{
	fh++;
	flag=0;
	while(1)
	   {
	     readmouse();
		{
		 co_1();
		 if(flag)
		   break;
		}
	   }
	     ofh[fh].x1=xx;
	     ofh[fh].y1=yy;
	    hidemouse();
	    line(xx,yy,xx-50,yy);
	    line(xx-5,yy-5,xx,yy);
	    line(xx-5,yy+5,xx,yy);
	    settextstyle(2, HORIZ_DIR, 4);
	    sprintf(str,"F%d",fh);
	    outtextxy(xx-40,yy+5,(str));
	    showmouse();
}

void drawbr()
{
    br++;
	flag=0;
	while(1)
	   {
	     readmouse();
		{
		 co_1();
		 if(flag)
		   break;
		}
	   }
	     obr[br].x1=xx;
	     obr[br].y1=yy;
	    hidemouse();
	    line(xx,yy,xx-10,yy);
	    line(xx-5,yy-5,xx,yy);
	    line(xx-5,yy+5,xx,yy);
	    line(xx-10,yy,xx-30,yy+10);
	    settextstyle(2, HORIZ_DIR, 4);
	    sprintf(str,"B%d",++BR);
	    outtextxy(xx-40,yy+5,(str));
	    showmouse();

}

void main()
{
      into();
      initialise();
      menu();
      intro();
}



