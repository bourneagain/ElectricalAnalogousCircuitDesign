#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>

extern int screen;
void showmouse();
void readmouse();
void hidemouse();
void ordinates2();
void ordinates3();
void ordinates4();

void translation()
{
hidemouse();
if(screen==0)
cleardevice();
setbkcolor(0);
setfillstyle(1,8);
bar(0,39,118,457);
setfillstyle(1,1);
bar(0,0,600,38);
setfillstyle(1,3);
settextstyle(3, HORIZ_DIR, 2);
setfillstyle(1,4);
bar(601,0,635,38);
rectangle(601,0,636,40);
settextstyle(3, HORIZ_DIR, 1);
outtextxy(170,4," Mechanical Translation System");
rectangle(0,40,635,456);
rectangle(0,40,118,457);
rectangle(4,70,113,116);
outtextxy(32,45,"Mass");
outtextxy(45,85,"M");
rectangle(4,145,113,195);
circle(13,169,5);
circle(20,169,5);
circle(27,169,5);
circle(82,157,5);
circle(82,175,5);
circle(82,166,5);
outtextxy(24,116,"spring 'K'");
line(58,145,58,195);
outtextxy(11,201,"Dash Pot 'B'");
outtextxy(4,287,"Force");
outtextxy(64,287,"B-Dir");
rectangle(4,227,113,277);
line(58,227,58,277);
line(9,252,30,252);
line(30,248,30,258);
line(20,243,40,243);
line(40,243,40,265);
line(20,265,40,265);
line(40,252,50,252);
line(83,236,83,248);
line(79,248,88,248);
line(92,242,92,258);
line(92,258,75,258);
line(75,258,75,242);
line(83,258,83,266);
rectangle(4,315,55,365);
rectangle(60,315,113,365);
line(30,315,30,365);
line(4,340,55,340);
line(60,340,113,340);
line(85,315,85,365);
line(15,322,15,335);
line(10,326,15,322);
line(15,322,20,326);
line(15+57,322,15+57,335);
line(10+57,326,15+57,322);
line(15+57,322,20+57,326);
line(35,328,48,328);
line(9,354,22,354);
line(41,345,41,358);
line(41+57,345,41+57,358);
line(15+57,322,15+57,335);
line(35+57,328,48+57,328);
line(9+57,354,22+57,354);
line(41+57,345,41+57,358);
line(44+57,334,48+57,329);
line(48+57,329,44+57,321);
line(41+57,359,46+57,354);
line(41+57,359,36+57,354);
line(41+57,359,36+57,354);
line(41,345,41,358);
line(44,334,48,329);
line(48,329,44,321);
line(41,359,46,354);
line(41,359,36,354);
line(41,359,36,354);
line(10,355,13,348);
line(10,355,13,360);
line(10+57,355,13+57,348);
line(10+57,355,13+57,360);
rectangle(60,315+60,113,365+60);
line(85,315+60,85,365+60);
line(15,322,15,335);
line(10,326,15,322);
line(15,322,20,326);
line(35,328,48,328);
line(9,354,22,354);
line(41,345,41,358);
line(44,334,48,329);
line(48,329,44,321);
line(41,359,46,354);
line(41,359,36,354);
line(41,359,36,354);
line(10,355,13,348);
line(10,355,13,360);
outtextxy(6,381,"Base");
line(68,397-17,68,397+17);
	  for(int i=(397-17);i<=(397+17);i+=10)
	  line(68,i,68+10,i+10);
line(103,397-17,103,397+17);
	for(i=(397-17);i<=(397+17);i+=10)
	  line(103,i,103-10,i+10);
line(117,71,633,71);
line(193,72,193,41);
settextstyle(2, HORIZ_DIR,0);
outtextxy(125,50,"F-V Anology");
outtextxy(205,50,"F-I Anology");
outtextxy(2,460,"HELP! ");
setfillstyle(1,7);
bar(1,1,117,38);
rectangle(0,0,118,39);
outtextxy(10,15,"Tools Palette");
setfillstyle(1,GREEN);
bar(562,0,598,38);
rectangle(562,0,600,40);
outtextxy(569,15,"HOME");
outtextxy(614,15,"X");
showmouse();
while(1)ordinates3();
}




void rotation()
{
hidemouse();
if(screen==0)
cleardevice();
setbkcolor(0);
setfillstyle(1,8);
bar(0,39,118,457);
setfillstyle(1,1);
bar(0,0,600,38);
setfillstyle(1,3);
settextstyle(3, HORIZ_DIR, 2);
setfillstyle(1,4);
bar(601,0,635,38);
rectangle(601,0,639,40);
settextstyle(3, HORIZ_DIR, 1);
outtextxy(170,4," Mechanical Rotational System");
rectangle(0,40,635,456);
rectangle(0,40,118,457);
rectangle(4,70,113,116);
outtextxy(32,45,"Inertia");
outtextxy(45,85,"J");
rectangle(4,145,113,195);
circle(13,169,5);
circle(20,169,5);
circle(27,169,5);
circle(82,157,5);
circle(82,175,5);
circle(82,166,5);
outtextxy(24,116,"spring 'K'");
line(58,145,58,195);
outtextxy(11,201,"Dash Pot 'B'");
outtextxy(4,287,"Force");
outtextxy(64,287,"B-Dir");
rectangle(4,227,113,277);
line(58,227,58,277);
line(9,252,30,252);
line(30,248,30,258);
line(20,243,40,243);
line(40,243,40,265);
line(20,265,40,265);
line(40,252,50,252);
line(83,236,83,248);
line(79,248,88,248);
line(92,242,92,258);
line(92,258,75,258);
line(75,258,75,242);
line(83,258,83,266);
rectangle(4,315,55,365);
rectangle(60,315,113,365);
line(30,315,30,365);
line(4,340,55,340);
line(60,340,113,340);
line(85,315,85,365);
line(15,322,15,335);
line(10,326,15,322);
line(15,322,20,326);
line(15+57,322,15+57,335);
line(10+57,326,15+57,322);
line(15+57,322,20+57,326);
line(35,328,48,328);
line(9,354,22,354);
line(41,345,41,358);
line(41+57,345,41+57,358);
line(15+57,322,15+57,335);
line(35+57,328,48+57,328);
line(9+57,354,22+57,354);
line(41+57,345,41+57,358);
line(44+57,334,48+57,329);
line(48+57,329,44+57,321);
line(41+57,359,46+57,354);
line(41+57,359,36+57,354);
line(41+57,359,36+57,354);
line(41,345,41,358);
line(44,334,48,329);
line(48,329,44,321);
line(41,359,46,354);
line(41,359,36,354);
line(41,359,36,354);
line(10,355,13,348);
line(10,355,13,360);
line(10+57,355,13+57,348);
line(10+57,355,13+57,360);
rectangle(60,315+60,113,365+60);
line(85,315+60,85,365+60);
line(15,322,15,335);
line(10,326,15,322);
line(15,322,20,326);
line(35,328,48,328);
line(9,354,22,354);
line(41,345,41,358);
line(44,334,48,329);
line(48,329,44,321);
line(41,359,46,354);
line(41,359,36,354);
line(41,359,36,354);
line(10,355,13,348);
line(10,355,13,360);
outtextxy(6,381,"Base");
line(68,397-17,68,397+17);
	  for(int i=(397-17);i<=(397+17);i+=10)
	  line(68,i,68+10,i+10);
line(103,397-17,103,397+17);
	for(i=(397-17);i<=(397+17);i+=10)
	  line(103,i,103-10,i+10);
line(117,71,633,71);
line(193,72,193,41);
settextstyle(2, HORIZ_DIR,0);
outtextxy(125,50,"F-V Anology");
outtextxy(205,50,"F-I Anology");
outtextxy(2,460,"HELP! ");
setfillstyle(1,GREEN);
bar(562,0,597,37);
rectangle(562,0,600,40);
setfillstyle(1,8);
bar(5,316,53,364);
ellipse(7, 341,300,70,15,20 );
ellipse(8, 341,300,70,15,20 );
ellipse(33, 341,300,70,15,20 );
ellipse(34, 341,300,70,15,20 );
line(28,315,28,365);
line(12,324,12,330);
line(12,322,20,322);
line(40,360,38,353);
line(40,360,46,360);
outtextxy(569,15,"HOME");
outtextxy(614,15,"X");
showmouse();
while(1)ordinates4();
}

void menu()
{
setbkcolor(7);
setfillstyle(1,1);
bar(0,0,600,38);
setfillstyle(1,4);
bar(0,458,639,475);
settextstyle(2, HORIZ_DIR,4);
outtextxy(5,456,"Choose Any Of The Design Models Above");
outtextxy(144,115,"Click Here To Design Translational Mechanical Model");
outtextxy(144,255,"Click Here To Design Rotational Mechanical Model");
settextstyle(3, HORIZ_DIR, 2);
setfillstyle(1,4);
bar(601,0,639,38);
rectangle(601,0,639,40);
outtextxy(615,10,"X");
settextstyle(1, HORIZ_DIR,1);
outtextxy(135,0,"Electrical Analogous Simulation");
rectangle(0,40,635,456);
settextstyle(3, HORIZ_DIR, 3);
outtextxy(220,145, "TRANSLATION");
rectangle(139,94,458,182);
outtextxy(245,280,"ROTATION");
rectangle(139,243,458,332);
setfillstyle(1,GREEN);
bar(601-37,0,639-37,40);
settextstyle(3,0,2);
outtextxy(575,10,"?");
rectangle(601-38,0,639-38,40);
showmouse();
}


void confirmation()
{cleardevice();
hidemouse();
setfillstyle(1,6);
bar(10,10,630,455);
setfillstyle(1,8);
bar3d(139,94,500,339,1,10);
settextstyle(3, HORIZ_DIR, 2);
outtextxy(150,150,"Are You Sure You Want To EXIT");
setfillstyle(1,4);
bar(139,94,500,124);
outtextxy(150,99,"Close confirmation....");
rectangle(139,94,500,124);
rectangle(200,246,294,278);
bar3d(201,247,295,279,10,1);
settextstyle(1, HORIZ_DIR, 2);
outtextxy(220,250,"YES ");
bar3d(326,247,406,279,10,1);
rectangle(325,246,405,278);
outtextxy(345,250,"NO");
while(1)
ordinates2();
}

