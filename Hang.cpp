#include <iostream>
#include <graphics.h>
#include <process.h>
#include <iomanip.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <dos.h>
#define pi 3.141592653589
#define spaces "                                                        "
char cph[20], ca[27], ch='y';
int nph[20], na[27], k=180, h=-50, r=0, dr=0;
int hangctr=1, nk=180, nh=-50, tr=1, score=0;
int n_objects;

void table();
void ifexit();
void control();
void credits();
void mainmenu();

struct words
{
	char word[20];      //for word
	char hint[100];     //for its corresponding hint
	int done;           //a flag to check if the word has already been used once
}
W[12];

/////////////////////////////////////////////////////////////////////
//dictionary

void dict()
{
	n_objects=13;
	strcpy(W[0].word,"SWIFT");
	strcpy(W[0].hint,"Hint: Apple\'s current official programming language\n");
	strcpy(W[1].word,"RUST");
	strcpy(W[1].hint,"Hint: Mozilla\'s official programming language\n");
	strcpy(W[2].word,"PYTHON");
	strcpy(W[2].hint,"Hint: A fourth generation HLL by Guido van Rossum\n");
	strcpy(W[3].word,"JAVA");
	strcpy(W[3].hint,"Hint: Oracle\'s multiplatform language\n");
	strcpy(W[4].word,"JAVASCRIPT");
	strcpy(W[4].hint,"Hint: Originally called Livescript\n");
	strcpy(W[5].word,"PROLOG");
	strcpy(W[5].hint,"Hint: The first 5-Gen programming language\n");
	strcpy(W[6].word,"MATLAB");
	strcpy(W[6].hint,"Hint: A fourth generation programming language by MathWorks\n");
	strcpy(W[7].word,"RUBY");
	strcpy(W[7].hint,"Hint: A dynamic, reflective language by Yukihiro Matsumoto\n");
	strcpy(W[8].word,"MYSQL");
	strcpy(W[8].hint,"Hint: A relational database management system by Oracle\n");
	strcpy(W[9].word,"BASIC");
	strcpy(W[9].hint,"Hint: One of the earliest general-purpose HLL released in 1964\n");
	strcpy(W[10].word,"PASCAL");
	strcpy(W[10].hint, "Hint: A structured language published by Niklaus Wirth in 1970\n");
	strcpy(W[11].word,"FORTRAN");
	strcpy(W[11].hint, "Hint: The earliest language for scientific computing \nby IBM in 1957\n");
	strcpy(W[12].word,"COBOL");
	strcpy(W[12].hint,"Hint: An acronym for \'Common Business Oriented Language\'\n");
}

/////////////////////////////////////////////////////////////////////
//to initialize arrays.                                            //

void init()
{
	hangctr=1;               //hang counter initialised to one
	k=180, h=-50;            //h and k are to shift the position of the character
	nk=180, nh=-50, score=0; //initializes score to zero;
	for(int ln=0; ln<20; ++ln)
		nph[ln]=0;           //initialises the phrase flags to zero
	for(int lm=1; lm<27; ++lm)
		na[lm]=0;            //initialises the table flags to zero
	for(int la=65, lh=1; la<=90, lh<=26; ++la, ++lh)
		ca[lh]=char(la);     //initialises the table to the 26 letters
							 //of the alphabet
}

/////////////////////////////////////////////////////////////////////
//Character parts.                                                 //
//origin shifted to (k,h)

	//the following functions are for the character parts
	//only coordinates of required lines have been coded here
	void noose()
	{
		//variables nh and nk are to shift the origin
		line(200-nk, 295-nh, 200-nk, 20-nh);
		line(205-nk, 295-nh, 205-nk, 25-nh);
		line(180-nk, 295-nh, 265-nk, 295-nh);
		line(265-nk, 295-nh, 265-nk, 300-nh);
		line(265-nk, 300-nh, 180-nk, 300-nh);
		line(180-nk, 300-nh, 180-nk, 295-nh);
		line(330-nk, 20-nh, 200-nk, 20-nh);
		line(330-nk, 20-nh, 330-nk, 25-nh);
		line(330-nk, 25-nh, 205-nk, 25-nh);
		line(320-nk, 25-nh, 320-nk, 70-nh);
	}

	void water()
	{
		int px = 1, col, y=450;
		for(int phi=1; phi<=250; ++phi)
		{
			//a logic similar to the wave has been used here
			px+=2;
			if(phi%2==0) col=3; 	//for cyan
			else col=15;        	//for white
			//to put pixels in an ordered way
			putpixel(px, y+(40*sin(0.02*pi+phi)), col);
		}
	}

	//k and h have been used to shift the origin

	void head()
	{
		ellipse(320-k,95-h,360,0,20,25);
		line(298-k,85-h,341-k,85-h);
		circle(310-k,90-h,2);
		circle(330-k,90-h,2);
		arc(320-k,100-h,200,-20,10);
	}

	void neck()
	{
		line(313-k,120-h,313-k,125-h);
		line(328-k,120-h,328-k,125-h);
	}

	void torso()
	{
		arc(320-k,225-h,72,107,100);
		line(290-k,129-h,290-k,200-h);
		line(350-k,129-h,350-k,200-h);
		line(290-k,193-h,350-k,193-h);
		line(290-k,200-h,350-k,200-h);
	}

	void left_leg()
	{
		line(290-k,200-h,285-k,280-h);
		line(320-k,225-h,305-k,280-h);
	}

	void right_leg()
	{
		line(322-k,225-h,335-k,280-h);
		line(350-k,200-h,355-k,280-h);
	}

	void right_hand()
	{
		line(290-k,129-h,255-k,165-h);
		line(255-k,165-h,290-k,200-h);
		line(290-k,149-h,275-k,165-h);
		line(275-k,165-h,290-k,182-h);
	}

	void left_hand()
	{
		line(350-k,129-h,385-k,165-h);
		line(385-k,165-h,350-k,200-h);
		line(350-k,149-h,365-k,165-h);
		line(365-k,165-h,350-k,182-h);
	}

	void left_shoe()
	{
		line(285-k,280-h,275-k,287-h);
		line(275-k,287-h,305-k,287-h);
		line(305-k,280-h,305-k,287-h);
	}

	void right_shoe()
	{
		line(335-k,280-h,335-k,287-h);
		line(335-k,287-h,365-k,287-h);
		line(355-k,280-h,365-k,287-h);
	}

	void name()
	{
		settextstyle(2,HORIZ_DIR,4);
		outtextxy(293-k,150-h,"  R I P  ");
	}

	void dunk()
	{
		for(int o=0; o<40; ++o)
		{
			// ++o gives an effect of acceleration of the man downwards
			//this loop is for drowning the man.
			delay(10);
			cleardevice();
			h-=(o);
			noose();
			head();
			neck();
			torso();
			left_hand();
			right_hand();
			left_leg();
			right_leg();
			left_shoe();
			right_shoe();
			name();
			water();
		}
		cleardevice();
		settextstyle(9, HORIZ_DIR, 3);
		outtextxy(getmaxx()/2-100, getmaxy()/2-30, "DROWNED !!");
		delay(1000);
		cout<<"\nYour final score: "<<score;
		getch();
		cleardevice();
		cout<<"\nTry again?? (Y/N): ";
		cin>>ch;
		cleardevice();
		if(ch=='y'||ch=='Y')
		{
			for(int ls=0; ls<n_objects; ++ls)
				W[ls].done=0;
			tr=1;     //tr is the initializing variable,
					  //the control function restarts only if tr=1
			init();
			mainmenu();
		}
		else
		{
			cout<<"Thankyou for playing hangman !";
			delay(1000);
			ifexit();
		}
	}

//                                                                 //
/////////////////////////////////////////////////////////////////////

void man(int l1)
{
	switch(l1)
	{
		//the fall through situtation has been used
		case 11:{
					dunk();
					cout<<"\nYour final score..."<<score;
					credits();
				}
		case 10: water();
		case 9: {
					left_leg();
					left_shoe();
				}
		case 8: {
					right_leg();
					right_shoe();
				}
		case 7: right_hand();
		case 6: left_hand();
		case 5: torso();
		case 4: neck();
		case 3: head();
		case 2: noose();
		default: break;
	}
}

void instructions()
{
	cleardevice();
	settextstyle(6, HORIZ_DIR, 4);
	outtextxy(10, 20, "INSTRUCTIONS");
	settextstyle(6, HORIZ_DIR, 1);
	//gives instructions
	outtextxy(12, 60, "DON'T LET THE MAN DROWN!!");
	outtextxy(12, 90, "SCORE POINTS BY GUESSING NAMES OF PROGRAMMING LANGUAGES");
	outtextxy(12, 120, "EACH WORD GUESSED CORRECTLY EARNS YOU ONE POINT");
	outtextxy(12, 150, "A WRONG GUESS IS A STEP CLOSER TO DROWNING");
	outtextxy(12, 180, "PRESS \'1\' FOR HINT ANY TIME DURING THE GAME");
	outtextxy(12, 210, "PRESS \'0\' TO EXIT ANY TIME DURING THE GAME");
	outtextxy(12, 270, "PRESS ANY KEY TO CONTINUE...");
	getch();
	mainmenu();
}

void ifexit()
{
	cleardevice();
	int ch3='y', ch4;
	settextstyle(6, HORIZ_DIR, 4);
	for(int pj=0; ch3!='\r'; ++pj)
	{
		//for loop runs till user presses enter '\r'
		ch4=ch3;
		/*the variable ch4 has been used because every time the loop
		  runs, the value of ch3 changes and the last value of ch3
		  will be '\r', but we need the second-last value of ch3*/
		cleardevice();
		outtextxy(120, 40, "DO YOU REALLY WANT TO EXIT ?");
		settextstyle(6, HORIZ_DIR, 1);
		outtextxy(255, 80, "PRESS Y OR N");
		settextstyle(6, HORIZ_DIR, 4);
		//if statements are for highlighting choices
		if(ch3=='Y')
			setcolor(RED);
		outtextxy(130, 120, "YES");
		setcolor(WHITE);
		if(ch3!='Y')
			setcolor(RED);
		outtextxy(450, 120, "NO");
		setcolor(WHITE);
		ch3=getch();
		ch3=toupper(ch3);
	}
	ch4=toupper(ch4);
	if(ch4=='Y')
		exit(0);
	else if(ch4=='N')
		mainmenu();
}

void mainmenu()
{
	char ch=49, ch2;
	settextstyle(6, HORIZ_DIR, 4);
	for(int j=0; ch!='\r'; ++j)
	{
		//for loop runs till the user presses enter '\r'
		ch2=ch;
		cleardevice();
		outtextxy(220, 40, "MAIN MENU");
		settextstyle(6, HORIZ_DIR, 1);
		outtextxy(100, 80, "USE THE NUMBER KEYS TO HIGHLIGHT YOUR CHOICE");
		settextstyle(6, HORIZ_DIR, 4);
		//if statements are for highlighting choices.
		if(ch<=49)
			setcolor(RED);
		outtextxy(180, 120, "1. START GAME");
		setcolor(WHITE);
		if(ch==50)
			setcolor(RED);
		outtextxy(175, 190, "2. INSTRUCTIONS");
		setcolor(WHITE);
		if(ch==51)
			setcolor(RED);
		outtextxy(210, 260, "3. CREDITS");
		setcolor(WHITE);
		if(ch>=52)
			setcolor(RED);
		outtextxy(235, 330, "4. EXIT");
		setcolor(WHITE);
		ch=getch();
	}
	if(ch2<=49)
	{
		init();
		tr=1;	//the variable that indicates the start of the game.
		cleardevice();
	}
	else if(ch2==50)
		instructions();
	else if(ch2==51)
		credits();
	else if(ch2>=52)
		ifexit();
	else
		mainmenu();
	cleardevice();
}

void enter()
{
	int t1=0, d1;
	float phi1;
	int x1=getmaxx()/2;
	settextstyle(8, HORIZ_DIR, 3);
	outtextxy(260, 200, "HANGMAN");
	delay(200);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	while(!kbhit())
	{
		t1++;
		d1=0;
		pieslice(x1+1, 480, 0, 210, 220);
		/* a black pieslice is drawn on the existing wave so that
		   it gets covered and the next wave appears on it */
		for(phi1=1; d1<640; phi1+=0.5)
		{
			d1+=10;                          //d1 sets x-coordinate
			putpixel(d1, 400+((40*sin(0.02*pi*t1+phi1))), WHITE);
			//this puts pixels every ten pixels at a phase difference of phi1

			/*the sine function puts a pixel within a vertical range between
			  the amplitude */
		}
		delay(3);
	}
	getch();
	setcolor(WHITE);
	mainmenu();
}

void end()
{
	for(int b=0;b<strlen(cph);b++)
	{
		cout<<cph[b]<<" ";
	}
	cout<<"\nYOU WIN !!!";
	score++;
	cout<<"\nYour current score: "<<score;
	cout<<"\nPress any key for next word...";
	getch();
		control();
}

void credits()
{
	cleardevice();
		settextstyle(6, HORIZ_DIR, 2);
		outtextxy(20, 40, "PROGRAM DESIGN:");
		settextstyle(6, HORIZ_DIR, 1);
		outtextxy(20, 70, "MIHIR KULKARNI and TUSHALI CHETTY");
		settextstyle(6, HORIZ_DIR, 2);
		outtextxy(20, 110, "GRAPHICS DESIGN:");
		settextstyle(6, HORIZ_DIR, 1);
		outtextxy(20, 140, "AMAN DEEP SINGH");
		settextstyle(6, HORIZ_DIR, 2);
		outtextxy(20, 180, "DETAILING:");
		settextstyle(6, HORIZ_DIR, 1);
		outtextxy(20, 210, "TUSHALI CHETTY");
		settextstyle(6, HORIZ_DIR, 2);
		outtextxy(20, 250, "TESTING AND ERROR HANDLING:");
		settextstyle(6, HORIZ_DIR, 1);
		outtextxy(20, 280, "MIHIR KULKARNI");
		getch();
	mainmenu();
}

void table()
{
	cout<<"\n\n\n\n\n\n";
	cout<<spaces;

	for(int l_i=1; l_i<=26; ++l_i)
	{
		cout<<ca[l_i]<<"   ";
		if(l_i%5==0)
			cout<<endl<<endl<<endl<<spaces;
	}
	cout<<"\n\n\n\n\n";
}

void check(char alp)
{
	int gictr=0, ldctr=0;
	for(int i=1; i<=26; ++i)
	{
		if(alp==ca[i])                            //alphabet checking
		{
			if(na[i]==1)
				cout<<"\nSorry! You've already used this letter... \1\n";
			else
			{
				na[i] = 1;
				ca[i] = ' ';
				for(int lp=0; lp<strlen(cph); ++lp)       //verifying presence in phrase
				{
					if(cph[lp] == alp)
					{
						nph[lp] = 1;
						dr=1;      //dr=1 means correct guess. hangctr not affected
						r=0;       //to increment the main for loop
					}
					else if(cph[lp] != alp)
					{
						for(int gi = 0; gi<strlen(cph); ++gi)
							if(cph[gi]!=alp)
								gictr++;
								//rechecks if alp is not in the array
						if(gictr==strlen(cph))
							dr=0;  //if alp is absent, hangctr is incremented
						r=0;       //to increment the main for loop
					}
				}
				if(dr==1)
				{
					table();
					man(hangctr);
				}
				else if(dr==0)
				{
					hangctr+=1;
					table();
					man(hangctr);
				}
				for(int ld=0; ld<strlen(cph); ++ld)
				{
					if(nph[ld]==1)         //to check if user has already won
						ldctr++;
				}
				if(ldctr==strlen(cph))
					end();                 //if won, game ends
			}
		}
	}
}

void control()
{
	randomize();
	//to initialise global arrays
		for(int in=0; in<30; ++in)
			nph[in]=0;
		for(int im=1; im<=26; ++im)
			na[im]=0;
		for(int ia=65, ih=1; ia<=90, ih<=26; ++ia, ++ih)
			ca[ih]=char(ia);

	char alp, xch;
	int gd=0, ji;
	int ran;
	ran=random(n_objects);	   //select a random word
	while(tr==1)
	{
		if(W[ran].done==1)
		{
			ran=random(n_objects);
			continue;
			//this part ensures that a word is not repeated
		}
		strcpy(cph, W[ran].word);
		W[ran].done=1;
		cleardevice();
		if(gd==0)
		{
			cout<<"\nWord: \n" ;
			for(int lt=0; lt<strlen(cph); lt++)   //displays the blanks
				cout<<"_ ";
		}
		gd++;
		table();
		man(hangctr);
		for(int l1=1; hangctr<=10;   )
		{
			start:
			cout<<"\n\nENTER A LETTER:-";
			alp=getch();                        //to enter letters
			alp=toupper(alp);
			if(alp=='1')
				cout<<W[ran].hint;  //displays hints
			else if(alp=='0')
			{
				cout<<"\nDo you really want to exit? (Y/N): ";
				cin>>xch;
				if(xch=='n'||xch=='N')
				{
					for(ji=0;ji<strlen(cph);ji++)
					{
						if(nph[ji]==1)
						cout<<cph[ji]<<" ";
						else cout<<"_ ";
					}
					goto start;
				}
				else if(xch!='n'||xch!='N')
					exit(0);
			}
			else if(alp!='1'&&alp!='0')
			{
				check(alp);     //checks presence of alphabet
				if(r==0)        //loop proceeds if check() returns r as zero
					l1++;       //l1 is the loop variable
			}
			cout<<"YOU GOT:-  "<<endl;    //displays current word with blanks
			for(ji=0;ji<strlen(cph);ji++)
			{
				if(nph[ji]==1)
				cout<<cph[ji]<<" ";
				else cout<<"_ ";
			}
		}
	}
}

void main()
{
	clrscr();
	init();                  //initializes arrays, scores, hang counter, etc
	dict();                  //initializes dictionary
	int gdriver = DETECT, gmode, i;
	int chances = 10;
	char ca[27];
	for(int v=0; v<5; ++v)
		W[v].done=0;
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	enter();                 //displays enter screen
	control();               //starts the control for the game, input/output, etc
	getch();
}
