#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <string.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
static int p = 0;
class a
{
	char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
	void install();
	void allotment();
	void empty();
	void show();
	void avail();
	void position(int i);
}
bus[10];
void vline(char ch)
{
	for (int i=80;i>0;i--)
	cout<<ch;
}
void a::install()
{

	cout<<"Enter bus no: ";
	cin>>bus[p].busn;
	cout<<"\nEnter Driver's name: ";
	cin>>bus[p].driver;
	cout<<"\nArrival time: ";
	cin>>bus[p].arrival;
	cout<<"\nDeparture: ";
	cin>>bus[p].depart;
	cout<<"\nFrom: \t\t\t";
	cin>>bus[p].from;
	cout<<"\nTo: \t\t\t";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void a::allotment()
{
	int seat;
	char number[5];
	top:
	cout<<"Bus no: ";
	cin>>number;
	int n;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn, number)==0)
		break;
	}
	while(n<=p)
	{
		cout<<"\nSeat Number: ";
		cin>>seat;
		if(seat>32)
		{
			cout<<"\nThere are only 32 seats available in this bus.";
		}
		else
		{
		if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
			{
				cout<<"Enter passanger's name: ";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
		else
			cout<<"The seat no. is already reserved.\n";
			}
			}
		if(n>p)
		{
			cout<<"Enter correct bus no.\n";
			if(p>0)
			goto top;
			else
			{
				printf("first install the bus then try to reserve :");
				goto dot;
			}
			dot:
		}
	}

void a::empty()
{
	for(int i=0; i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j], "Empty");
		}
	}
}
void a::show()
{
	int n;
	char number[5];
	cout<<"Enter bus no: ";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn, number)==0)
		break;
	}
while(n<=p)
{
	vline('*');
	cout<<"Bus no: \t"<<bus[n].busn
	<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
	<<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
	<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
	bus[n].to<<"\n";
	vline('*');
	bus[0].position(n);
	int a=1;
	for (int i=0; i<8; i++)
	{
		for(int j=0;j<4;j++)
		{
			a++;
			if(strcmp(bus[n].seat[i][j],"Empty")!=0)
			cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
		}
	}
	break;
	}
	if(n>p)
		cout<<"Enter correct bus no: ";
}
void a::position(int l)
{
	int s=0;p=0;
	for (int i =0; i<8;i++)
	{
		cout<<"\n";
		for (int j = 0;j<4; j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j], "Empty")==0)
				{
					cout.width(5);
					cout.fill(' ');
					cout<<s<<".";
					cout.width(10);
					cout.fill(' ');
					cout<<bus[l].seat[i][j];
					p++;
				}
				else
				{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
				}
			}
		}
	cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
	}
void a::avail()
{

	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver
		<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
		<<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
		<<bus[n].to<<"\n";
		vline('*');
		vline('_');
	}
}
void main()
{
clrscr();
int w,i;
int gd=DETECT, gm;
initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
for(i=0;i<248;i++)
	{
		setbkcolor(RED);
		cleardevice();
		outtextxy(150,100,"WELCOME TO BUS RESERVATION SYSTEM !!!");
		settextstyle(6,HORIZ_DIR,2);
		rectangle(130,90,530,140);   //for heading
		rectangle(128,88,532,142);
		outtextxy(310,280,"KEEP CALM...!!!!");
		outtextxy(310,310,"THE BUS IS APPROACHING...!!!!");
		//for the pillar
		line(600,480,600,430);
		line(601,480,601,430);
		line(630,480,630,430);
		line(631,480,631,430);
		line(598,430,632,430);
		line(625,430,625,200);
		line(605,430,605,200);
		circle(615,195,10);
		//for the person
		circle(550,400,10);	  //face of the person
		line(550,410,550,460);    //body
		line(530,480,550,460);    //left leg
		line(570,480,550,460);    //right leg
		line(550,415,560,440);    //right hand
		line(550,415,540,440);	  //left hand
		//for the bus
		rectangle(50+i,350,250+i,450);   //for passenger
		rectangle(250+i,370,290+i,440);  //for driver
		rectangle(260+i,380,280+i,420);  //driver window
		//for the driver
		circle(270+i,398,8);		 //driver's head
		line(270+i,405,260+i,420);       //body of driver
		line(270+i,405,280+i,420);	 //driver's body
		putpixel(273+i,396,WHITE);	 //driver's eye
		circle(65+i,465,15);      //rear bigger tyre
		circle(65+i,465,8);	  //rear smaller tyre
		circle(245+i,465,15);	  //front bigger tyre
		circle(245+i,465,8);      //front smaller tyre
		rectangle(70+i,370,90+i,400); //first window
		rectangle(120+i,370,140+i,400);  //second window
		rectangle(170+i,370,190+i,400);	 //third window
		rectangle(220+i,370,240+i,400);	 //fourth window
		delay(20);
	}
cleardevice();
for(i=0;i<=7;i++)
{
	cleardevice();
	setbkcolor(i);
	outtextxy(100+i,250,"GET READY TO BOOK YOUR ONLINE TICKET");
	outtextxy(50+i,150,"NO NEED TO STAND IN A QUEUE TO BOOK A TICKET");
	delay(400);
}
cleardevice();
setbkcolor(BROWN);
while(1)
{
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t1.Install\n\t\t\t"
	<<"2.Reservation\n\t\t\t"
	<<"3.Show\n\t\t\t"
	<<"4.Buses Available. \n\t\t\t"
	<<"5.Exit";
	cout<<"\n\t\t\tEnter your choice:-> ";
	cin>>w;
	switch(w)
	{
		case 1:	bus[p].install();
			break;
		case 2:	bus[p].allotment();
			break;
		case 3:	bus[p].show();
			break;
		case 4:	bus[p].avail();
			break;
		case 5:	exit(0);
	}
}
}