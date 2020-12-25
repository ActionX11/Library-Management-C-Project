//*****************************************************************************
//           	        HEADER FILE USED IN PROJECT
//*****************************************************************************
#include<stdio.h>
#include<TIME.H>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
//****************************************************************************
//              	     FUNCTION DECLARATIONS
//****************************************************************************
void delani();
void border();
void sh();
void display();
void about();
void front();
void table();
void categ();
int password();
void menu();
//****************************************************************************
//               	    CLASS USED IN PROJECT
//*****************************************************************************
fstream f,f1;
class lib
{
		char bkn[50],atrn[30],pubn[50],date[9],prev[9];
		float pric;
		float g;
	public:
		void modify_book()
		{
			textcolor(1075);
			gotoxy(15,12);
			cprintf("Modify Publication : ");
			textcolor(1081);
			gets(pubn);
			textcolor(1075);
			gotoxy(15,13);
			cprintf("Modify Price : ");
			textcolor(1081);
			cin>>pric;
		}
	void modi()
	{
		int e,g=0;
		y:
		clrscr();
		e=password();
		if(g<3)
		{
			if(e==1)
			{
				border();
				char h;
				int found=0;
				gotoxy(10,5);
				textcolor(1289);
				cprintf("Enter the category in which you want to modify the details");
				categ();
				h=getch();
				char bkc[50];
				border();
				textcolor(1334);
				gotoxy(9,6);
				cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
				gotoxy(9,7);
				cprintf("³                                                                   ³");
				gotoxy(9,8);
				cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
				textcolor(881);
				gotoxy(10,5);
				cprintf("Enter the name of the book whose details are to be modified : \n\n");
				textcolor(946);
				gotoxy(10,7);
				textcolor(946);
				gets(bkc);
				if(h=='1')
					f.open("adventure.dat",ios::binary | ios::in | ios::out);
				if(h=='2')
					f.open("action.dat",ios::binary | ios::in | ios::out);
				if(h=='3')
					f.open("romance.dat",ios::binary | ios::in | ios::out);
				if(h=='4')
					f.open("biographical.dat",ios::binary | ios::in | ios::out);
				if(h=='5')
					f.open("thrill.dat",ios::binary | ios::in | ios::out);
				if(h=='6')
					f.open("mystery.dat",ios::binary | ios::in | ios::out);
				if(h=='7')
					f.open("humour.dat",ios::binary | ios::in | ios::out);
				while(f.read((char*)&s,sizeof(s)) && found==0)
				{
					if(strcmp(bkn,bkc)==0)
					{
						s.qoutput();
						gotoxy(15,8);
						cprintf("\nEnter The New Details of book : \n");
						s.modify_book();
						int pos=-1*sizeof(s);
						f.seekp(pos,ios::cur);
						f.write((char*)&s,sizeof(s));
						gotoxy(25,18);
						for(int ij=10;ij<50;ij+=5)
						{
							sound(ij);
							delay(300);
						}
						nosound();
						cprintf("\n\n!!!Record Updated!!!");
						found=1;
					}
				}
				f.close();
				if(found==0)
				{
					for(int ij=50;ij>10;ij-=5)
					{	sound(ij);
						delay(300);
					}
					nosound();
					textcolor(RED+BLINK);
					gotoxy(35,16);
					cprintf("\n\n Record Not Found ");
				}
				getch();
				menu();
			}
			else
			{
				g++;
				gotoxy(22,22);
				cprintf("Password is wrong you have used ");
				cout<<g;
				cprintf(" Chances");
				cout<<endl;
				delay(900);
				if(g<3)
					goto y;
				else
					goto x;
			}
		}
		else
		{
			x:
			textcolor(4);
			cprintf("Intruder Alert!");
			getch();
			exit(0);
		}
	}
	void input()
	{
		border();
		gotoxy(30,4);
		cprintf("Enter The Book Name : ");
		gets(bkn);
		gotoxy(30,5);
		cprintf("Author Name : ");
		gets(atrn);
		gotoxy(30,6);
		cprintf("Publication Name : ");
		gets(pubn);
		gotoxy(30,7);
		cprintf("Enter The Price : ");
		cin>>pric;
		_strdate(prev);
	}
	void output()
	{
		border();
		int g=1;
		char a;
		textcolor(4);
		gotoxy(10,4);
		cprintf("Book : ");
		textcolor(BLUE+RED);
		puts(bkn);
		textcolor(4);
		gotoxy(10,5);
		cprintf("Author : ");
		textcolor(BLUE+RED);
		puts(atrn);
		textcolor(4);
		gotoxy(10,6);
		cprintf("Publication : ");
		textcolor(BLUE+RED);
		puts(pubn);
		textcolor(4);
		gotoxy(10,7);
		cprintf("Price : ");
		textcolor(BLUE+RED);
		cout<<pric;
		gotoxy(10,8);
		textcolor(BLUE+RED);
		_strdate(prev);
		gotoxy(10,10);
		cprintf("Press N Key For Next Book and P for previous book");
		a=getch();
		if(a=='p'||a=='P')
			f.seekg((g)*134);
		else
			g++;
	}
	void isout()
	{
		border();
		int g=1;
		char a;
		textcolor(4);
		gotoxy(10,4);
		cprintf("Book : ");
		textcolor(BLUE+RED);
		puts(bkn);
		textcolor(4);
		gotoxy(10,5);
		cprintf("Author : ");
		textcolor(BLUE+RED);
		puts(atrn);
		textcolor(4);
		gotoxy(10,6);
		cprintf("Publication : ");
		textcolor(BLUE+RED);
		puts(pubn);
		textcolor(4);
		gotoxy(10,7);
		cprintf("Price : ");
		textcolor(BLUE+RED);
		cout<<pric;
		textcolor(RED);
		gotoxy(10,8);
		cprintf("Date : ");
		puts(prev);
		textcolor(BLUE+RED);
		gotoxy(10,10);
		cprintf("Press N Key For Next Book and P for previous book");
		a=getch();
		if(a=='p'||a=='P')
			f.seekg((g)*134);
		else
			g++;
	}
	void qoutput()
	{
		border();
		textcolor(4);
		gotoxy(10,4);
		cprintf("Book : ");
		textcolor(BLUE+RED);
		puts(bkn);
		textcolor(4);
		gotoxy(10,5);
		cprintf("Author : ");
		textcolor(BLUE+RED);
		puts(atrn);
		textcolor(4);
		gotoxy(10,6);
		cprintf("Publication : ");
		textcolor(BLUE+RED);
		puts(pubn);
		textcolor(4);
		gotoxy(10,7);
		cprintf("Price : ");
		textcolor(BLUE+RED);
		cout<<pric;
	}
	void repout()
	{
		border();
		textcolor(YELLOW);
		gotoxy(30,6);
		cprintf("Late Fine Details");
		textcolor(LIGHTBLUE);
		gotoxy(3,7);
		cprintf("1.If Number Of Days Is More Than 10 Then Fine Is 5 Rupees");
		gotoxy(3,8);
		cprintf("2.If Number Of Days Is More Than 20 Then Fine Is 15 Rupees");
		gotoxy(3,9);
		cprintf("3.If Number Of Days Is More Than 30 Then Fine Is 5*Number of Days Rupees");
		getch();
		menu();
	}
	void routput()
	{
		char a;
		border();
		textcolor(4);
		gotoxy(10,4);
		cprintf("Book : ");
		textcolor(BLUE+RED);
		puts(bkn);
		textcolor(4);
		gotoxy(10,5);
		cprintf("Author : ");
		textcolor(BLUE+RED);
		puts(atrn);
		textcolor(4);
		gotoxy(10,6);
		cprintf("Publication : ");
		textcolor(BLUE+RED);
		puts(pubn);
		textcolor(4);
		gotoxy(10,7);
		cprintf("Price : ");
		textcolor(BLUE+RED);
		cout<<pric;
		cprintf("Date : ");
		_strdate(date);
		puts(date);
		textcolor(BLUE+RED);
		gotoxy(10,10);
		cprintf("Press N Key For Next Book and P for previous book");
		a=getch();
		if(a=='p'||a=='P')
			f.seekg((g)*134);
		else
			g++;
	}
	void delrecord();
	void writedata();
	void readdata();
	int query();
	void issuelist()
	{
		clrscr();
		gotoxy(10,8);
		f1.open("bkis.dat",ios::binary | ios::in);
		f1.seekg(0);
		while(f1.read((char *)&s,sizeof(s)))
		{
			s.isout();
		}
		f1.close();
		getch();
		menu();
	}
void returna()
{
	border();
	char bkc[50];
	textcolor(1097);
	gotoxy(10,5);
	cprintf("Enter the book you have to return : ");
	textcolor(1075);
	gotoxy(9,11);
	cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
	gotoxy(9,12);
	cprintf("³                                                                   ³");
	gotoxy(9,13);
	cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	gotoxy(10,12);
	gets(bkc);
	fstream f,f1;
	f.open("bkre.dat",ios::binary | ios::app);
	f1.open("bkis.dat",ios::binary | ios::in);
	int chg=0;
	char ch;
	while(f1.read((char *)&s,sizeof(s)))
	{
		if((strcmp(bkc,bkn)==0))
		{
			 f.write((char *)&s,sizeof(s));
		}
		else
			chg=1;
		f.close();
		f1.close();
	}
	if(chg==1)
	{
		gotoxy(20,10);
		cprintf("Sorry ! Book not found in the records");
		gotoxy(20,15);
		cprintf("Do you want to check the books (y/n) : ");
		ch=getch();
		if(ch=='y' || ch=='Y')
			query();
		else
			menu();
	}
	f.open("bkis.dat",ios::binary | ios::in);
	f1.open("Temp.dat",ios::binary|ios::out);
	f.seekg(0);
	while(f.read((char*)&s,sizeof(s)))
	{
		if(strcmp(bkc,bkn)!=0)
		f1.write((char *)&s,sizeof(s));
	}
	f.close();
	f1.close();
	remove("bkis.dat");
	rename("temp.dat","bkis.dat");
	menu();
}
	void returnlist()
	{
		clrscr();
		gotoxy(10,8);
		f1.open("bkre.dat",ios::binary | ios::in);
		f1.seekg(0);
		while(f1.read((char *)&s,sizeof(s)))
		{
			s.routput();
		}
		f1.close();
		getch();
		menu();
	}
	void issue()
	{
		char h;
		char bkc[50];
		border();
		textcolor(GREEN);
		gotoxy(10,4);
		cprintf("Enter the category in which you have to issue the book : ");
		textcolor(YELLOW);
		categ();
		h=getch();
		border();
		gotoxy(20,6);
		cprintf("Enter the name of book to be issued : ");
		textcolor(1334);
		gotoxy(9,7);
		cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
		gotoxy(9,8);
		cprintf("³                                                                   ³");
		gotoxy(9,9);
		cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		gotoxy(10,8);
		gets(bkc);
		if(h=='1')
			f.open("adventure.dat",ios::binary | ios::in);
		if(h=='2')
			f.open("action.dat",ios::binary | ios::in);
		if(h=='3')
			f.open("romance.dat",ios::binary | ios::in);
		if(h=='4')
			f.open("biographical.dat",ios::binary | ios::in);
		if(h=='5')
			f.open("thrill.dat",ios::binary | ios::in);
		if(h=='6')
			f.open("mystery.dat",ios::binary | ios::in);
		if(h=='7')
			f.open("humour.dat",ios::binary | ios::in);
		int chg=0;
		char ch;
		f.seekg(0);
		f1.open("bkis.dat",ios::binary | ios::app);
		while(f.read((char *)&s,sizeof(s)))
		{
			if((strcmp(bkc,bkn)==0))
			{
				 _strdate(prev);
				 f1.write((char *)&s,sizeof(s));
			}
			else
				chg=1;
			f1.close();
			f.close();
			menu();
		}
		if(chg==1)
		{
			gotoxy(20,10);
			cprintf("Sorry ! Book not found in the records");
			gotoxy(20,15);
			cprintf("Do you want to check the books (y/n) : ");
			ch=getch();
			if(ch=='y' || ch=='Y')
				query();
			else
				menu();
		}
	}
}s;
//**************************************************************************\\
//              	    	 FUNCTIONS                                  \\
//**************************************************************************\\
void delani()
{
	clrscr();
	textcolor(BROWN);
	gotoxy(1,16);
	cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
	gotoxy(1,17);
	cprintf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÂÄÄÙ");
	for(int mop=18;mop<=25;mop++)
	{
		gotoxy(24,mop);
		cprintf("³³");
	}
	textcolor(GREEN);
	gotoxy(28,20);
	cprintf("¿           Ú");
	for(int dust=21;dust<=24;dust++)
	{
		gotoxy(28,dust);
		cprintf("³           ³");
	}
	gotoxy(31,23);
	cprintf("RECYCLE");
	gotoxy(28,25);
	cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÙ");
	int jk;
	randomize();
	p:
	jk=random(100);
	if(jk%16==0)
		goto p;
	for(int book=1;book<=29;book++)
	{       textcolor(jk);
		gotoxy(book,14);
		cprintf(" ÉÍÍÍÍÍÍÍÍ»");
		gotoxy(book,15);
		cprintf(" ÌÍÍÍÍÍÍÍÍ¹");
		gotoxy(book,16);
		cprintf(" ÈÍÍÍÍÍÍÍÍ¼");
		textcolor(BROWN);
		if(book<=28)
		{	gotoxy(book,16);
			cprintf("Ä");
		}
		delay(40);
	}
	gotoxy(28,16);
	cprintf("¿");
	textcolor(jk);
	for(int lib=14;lib<=20;lib++)
	{	gotoxy(30,lib-1);
		cprintf("          ");
		gotoxy(30,lib);
		cprintf("ÉÍÍÍÍÍÍÍÍ»");
		gotoxy(30,lib+1);
		cprintf("ÌÍÍÍÍÍÍÍÍ¹");
		gotoxy(30,lib+2);
		cprintf("ÈÍÍÍÍÍÍÍÍ¼");
		delay(30);
	}
}
void categ()
{
	gotoxy(30,10);
	cprintf("1. Adventure");
	gotoxy(30,12);
	cprintf("2. Action");
	gotoxy(30,14);
	cprintf("3. Romance");
	gotoxy(30,16);
	cprintf("4. Biographical");
	gotoxy(30,18);
	cprintf("5. Thriller");
	gotoxy(30,20);
	cprintf("6. Mystery");
	gotoxy(30,22);
	cprintf("7. Humour");
}
int lib::query()
{
	char h;
	char bkc[50];
	border();
	textcolor(GREEN);
	gotoxy(10,4);
	cprintf("Enter the category in which you have to search the books : ");
	textcolor(YELLOW);
	categ();
	h=getch();
	clrscr();
	border();
	textcolor(1334);
	gotoxy(5,7);
	cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
	gotoxy(5,8);
	cprintf("³                                                                        ³");
	gotoxy(5,9);
	cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	gotoxy(5,6);
	cprintf("Enter the name of book to be searched : ");
	textcolor(881);
	gotoxy(9,8);
	gets(bkc);
	fstream f;
	if(h=='1')
		f.open("adventure.dat",ios::binary | ios::in);
	if(h=='2')
		f.open("action.dat",ios::binary | ios::in);
	if(h=='3')
		f.open("romance.dat",ios::binary | ios::in);
	if(h=='4')
		f.open("biographical.dat",ios::binary | ios::in);
	if(h=='5')
		f.open("thrill.dat",ios::binary | ios::in);
	if(h=='6')
		f.open("mystery.dat",ios::binary | ios::in);
	if(h=='7')
		f.open("humour.dat",ios::binary | ios::in);
	int chg=0;
	char ch;
	f.seekg(0);
	while(f.read((char *)&s,sizeof(s)))
	{
		if((strcmp(bkc,bkn)==0))
		{
			for(int ij=10;ij<50;ij+=5)
			{
				sound(ij);
				delay(300);
			}
			nosound();
			s.qoutput();
			chg=0;
			gotoxy(20,15);
		cprintf("Do you want to search again (y/n) : ");
		ch=getch();
		if(ch=='y' || ch=='Y')
			query();
		else
			menu();
		}
		else
			chg=1;
	}
	if(chg==1)
	{
		for(int ij=50;ij>10;ij-=5)
		{
			sound(ij);
			delay(300);
		}
		nosound();
		textcolor(RED+BLINK);
		gotoxy(20,10);
		cprintf("Sorry ! Book not found in the records");
		gotoxy(20,15);
		cprintf("Do you want to search again (y/n) : ");
		ch=getch();
		if(ch=='y' || ch=='Y')
			query();
		else
			menu();
	}
	return 0;
}
void sh()
{
	textcolor(LIGHTBLUE);
	for(int m=36;m<46;m++)
	{
		gotoxy(m,12);
		cprintf("þ");
		gotoxy(m,14);
		cprintf("þ");
		gotoxy(36,13);
		cprintf("Ý");
		gotoxy(45,13);
		cprintf("Þ");
	}
	textcolor(CYAN);
	for(int i=0;i<6;i++)
	{
		gotoxy(38+i,13);
		cprintf("-");
	}
}
int password()
{
	textcolor(LIGHTRED);
	gotoxy(34,7);
	cprintf("--------------");
	gotoxy(34,8);
	cprintf("Encrypted Mode");
	gotoxy(34,9);
	cprintf("--------------");
	sh();
	char pas[7];
	pas[0]=char(73);
	pas[1]=char(110);
	pas[2]=char(100);
	pas[3]=char(105);
	pas[4]=char(97);
	pas[5]=char(110);
	pas[6]='\0';
	char pch[7];
	for(int i=0;i<6;i++)
	{
		gotoxy(38+i,13);
		pch[i]=getche();
		if(int(pch[i])==8)
		{
			if(i>0)
				i-=2;
			gotoxy(39+i,13);
			cprintf("-");
			goto a;
		}
		else
		{
			delay(60);
			gotoxy(38+i,13);
			cprintf("*");
		}
		a:
	}
	pch[6]='\0';
	if(strcmp(pas,pch)==0)
	{
		textcolor(GREEN);
		for(int i=34;i<48;i+=2)
		{
			delay(100);
			gotoxy(i,17);
			cprintf("þ");
		}
		gotoxy(34,17);
		cprintf("Access Granted");
		delay(500);
		return 1;
	}
	else
	{
		textcolor(RED);
		for(int i=36;i<48;i+=2)
		{
			delay(100);
			gotoxy(i,17);
			cprintf("þ");
		}
		gotoxy(35,17);
		cprintf("Access Denied");
		delay(500);
		return 0;
	}
}
void lib::delrecord()
{
	int e,g=0;
	y:
	clrscr();
	e=password();
	if(g<3)
	{
		if(e==1)
		{
			border();
			char h;
			char bkc[50];
			textcolor(1097);
			gotoxy(10,5);
			cprintf("Enter the category in which you have to delete the records : ");
			textcolor(1075);
			categ();
			h=getch();
			border();
			gotoxy(20,10);
			cprintf("Enter the name of book to be deleted : ");
			textcolor(1334);
			gotoxy(9,11);
			cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
			gotoxy(9,12);
			cprintf("³                                                                   ³");
			gotoxy(9,13);
			cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
			gotoxy(10,12);
			gets(bkc);
			fstream f,f1;
			if(h=='1')
				f.open("adventure.dat",ios::binary | ios::in);
			if(h=='2')
				f.open("action.dat",ios::binary | ios::in);
			if(h=='3')
				f.open("romance.dat",ios::binary | ios::in);
			if(h=='4')
				f.open("biographical.dat",ios::binary | ios::in);
			if(h=='5')
				f.open("thrill.dat",ios::binary | ios::in);
			if(h=='6')
				f.open("mystery.dat",ios::binary | ios::in);
			if(h=='7')
				f.open("humour.dat",ios::binary | ios::in);
			f1.open("Temp.dat",ios::binary|ios::out);
			f.seekg(0);
			while(f.read((char*)&s,sizeof(s)))
			{
				if(strcmp(bkc,bkn)!=0)
				f1.write((char *)&s,sizeof(s));
			}
			f.close();
			f1.close();
			if(h=='1')
			{
				remove("adventure.dat");
			rename("temp.dat","adventure.dat");
			}
			if(h=='2')
			{
				remove("action.dat");
				rename("temp.dat","action.dat");
			}
			if(h=='3')
			{
				remove("romance.dat");
				rename("temp.dat","romance.dat");
			}
			if(h=='4')
			{
				remove("biographical.dat");
				rename("temp.dat","biographical.dat");
			}
			if(h=='5')
			{
				remove("thrill.dat");
				rename("temp.dat","thrill.dat");
			}
			if(h=='6')
			{
				remove("mystery.dat");
				rename("temp.dat","mystery.dat");
			}
			if(h=='7')
			{
				remove("humour.dat");
				rename("temp.dat","humour.dat");
			}
			delani();
			menu();
		}
		else
		{
			g++;
			gotoxy(22,22);
			cprintf("Password is wrong you have used ");
			cout<<g;
			cprintf(" Chances");
			cout<<endl;
			delay(900);
			if(g<3)
				goto y;
			else
				goto x;
		}
	}
	else
	{
		x:
		textcolor(4);
		cprintf("Intruder Alert!");
		getch();
		exit(0);
	}
}
void  lib::writedata()
{
	border();
	int n,e,g=0;
	char h;
	y:
	e=password();
	if(g<3)
	{
		if(e==1)
		{
			clrscr();
			textcolor(1230);
			gotoxy(10,8);
			cprintf("Enter The Category In Which You Have To Purchase");
			textcolor(1298);
			categ();
			h=getch();
			if(h=='1')
				f.open("adventure.dat",ios::binary | ios::app);
			if(h=='2')
				f.open("action.dat",ios::binary | ios::app);
			if(h=='3')
				f.open("romance.dat",ios::binary | ios::app);
			if(h=='4')
				f.open("biographical.dat",ios::binary | ios::app);
			if(h=='5')
				f.open("thrill.dat",ios::binary | ios::app);
			if(h=='6')
				f.open("mystery.dat",ios::binary | ios::app);
			if(h=='7')
				f.open("humour.dat",ios::binary | ios::app);
			clrscr();
			gotoxy(20,2);
			cout<<"Enter The No. Of Books To Be Purchased : ";
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				s.input();
				f.write((char *)&s,sizeof(s));
			}
			f.close();
			menu();
		}
		else
		{
			g++;
			gotoxy(22,22);
			cprintf("Password is wrong you have used ");
			cout<<g;
			cprintf(" Chances");
			cout<<endl;
			delay(900);
			goto y;
		}
       }
       else
	       textcolor(4);
	       cprintf("Intruder Alert!");
	       getch();
	       exit(0);
}
void lib::readdata()
{
	char h;
	border();
	textcolor(1115);
	gotoxy(10,8);
	cprintf("Enter the category in which you have to check the books");
	textcolor(1084);
	categ();
	h=getch();
	if(h=='1')
		f.open("adventure.dat",ios::binary | ios::in);
	if(h=='2')
		f.open("action.dat",ios::binary | ios::in);
	if(h=='3')
		f.open("romance.dat",ios::binary | ios::in);
	if(h=='4')
		f.open("biographical.dat",ios::binary | ios::in);
	if(h=='5')
		f.open("thrill.dat",ios::binary | ios::in);
	if(h=='6')
		f.open("mystery.dat",ios::binary | ios::in);
	if(h=='7')
		f.open("humour.dat",ios::binary | ios::in);
	f.seekg(0);
	while(f.read((char *)&s,sizeof(s)))
	{
		s.output();
	}
	f.close();
	getch();
	menu();
}
void table()
{       for(int ij=11;ij<24;ij+=2)
	{
		if(ij<22)
		{
			gotoxy(6,ij+1);
			cprintf("º");
			gotoxy(38,ij+1);
			cprintf("º");
			gotoxy(76,ij+1);
			cprintf("º");
		}
		gotoxy(6,ij);
		cprintf("Ì");
		for(int j=5;j<74;j++)
		{
			if(j==36)
				cprintf("Î");
			else
				cprintf("Í");
		}
			cprintf("¹");
	}
	gotoxy(6,11);
	cprintf("É");
	gotoxy(76,11);
	cprintf("»");
	gotoxy(6,23);
	cprintf("È");
	gotoxy(76,23);
	cprintf("¼");
	gotoxy(38,11);
	cprintf("Ë");
	gotoxy(38,23);
	cprintf("Ê");
}
void border()
{	clrscr();
	for(int i=2;i<80;i+=2)
	{
		textcolor(RED);
		gotoxy(i,3);
		cprintf("Ü");
		gotoxy(i,25);
		cprintf("Ü");
		delay(10);
	}
	gotoxy(79,25);
	cprintf("Ü");
	gotoxy(79,3);
	cprintf("Ü");
	for(int j=3;j<=25;j++)
	{
		textcolor(RED);
		gotoxy(1,j);
		cprintf("Ü");
		gotoxy(80,j);
		cprintf("Ü");
		delay(10);
	}
	gotoxy(80,3);
	cprintf("Û");
	gotoxy(80,24);
	cprintf("Û");
	gotoxy(1,3);
	cprintf("Û");
	gotoxy(1,24);
	cprintf("Û");
}
void display()
{       clrscr();
	border();
	textcolor(GREEN);
	gotoxy(11,4);
	cprintf("ÌË¹      ÌÍËÍ¹  ÌËÍÍÍ»  ÌËÍÍÍ»    ÉÍÍÍ»   ÌËÍÍÍ»  ÌË¹   ÌË¹");
	gotoxy(11,5);
	delay(100);
	cprintf(" º         º     º   º   º   º    º   º    º   º   º     º");
	gotoxy(11,6);
	delay(100);
	cprintf(" º         º     ÌÍÍÍ¹   ÌÍÍÍ¼    ÌÍÍÍ¹    ÌÍÍÍ¼   ÈÍÍËÍÍ¼");
	gotoxy(11,7);
	delay(100);
	cprintf(" º         º     º   º   ÌÍÍÍ»    º   º    ÌÍÍÍ»      º   ");
	gotoxy(11,8);
	delay(100);
	cprintf("ÌÊÍÍÍÍ¹  ÌÍÊÍ¹  ÌÊÍÍÍ¼  ÌÊ¹ ÌÊ¹  ÌÊ¹ ÌÊ¹  ÌÊ¹ ÌÊ¹    ÌÊ¹  ");
	delay(100);
	gotoxy(4,11);
	cprintf("ÌËÍÍËÍÍË¹  ÉÍÍÍ»  ÌËÍÍÍ»   ÉÍÍÍ»  ÉÍÍÍ¹ ÉÍÍÍ¹ ÌËÍÍËÍÍË¹ ÉÍÍÍ¹ ÌËÍÍÍ»  ÌÍËÍ¹");
	gotoxy(4,12);
	delay(100);
	cprintf(" º  º  º   º   º   º   º   º   º  º     º      º  º  º  º      º   º    º");
	gotoxy(4,13);
	delay(100);
	cprintf(" º  Ê  º   ÌÍÍÍ¹   º   º   ÌÍÍÍ¹  º  Ì» ÌÍÍÍ¹  º  Ê  º  ÌÍÍÍ¹  º   º    º");
	delay(100);
	gotoxy(4,14);
	cprintf(" º     º   º   º   º   º   º   º  º   º º      º     º  º      º   º    º");
	delay(100);
	gotoxy(4,15);
	cprintf("ÌÊ¹   ÌÊ¹ ÌÊ¹ ÌÊ¹ ÌÊ¹ ÌÊ¹ ÌÊ¹ ÌÊ¹ ÈÍÍÍ¼ ÈÍÍÍ¹ ÌÊ¹   ÌÊ¹ ÈÍÍÍ¹ ÌÊ¹ ÌÊ¹  ÌÊ¹");
}
void about()
{
	border();
	textcolor(LIGHTBLUE);
	gotoxy(33,10);
	cprintf("ABOUT APPLICATION");
	gotoxy(33,11);
	cprintf("ÍÍÍÍÍ ÍÍÍÍÍÍÍÍÍÍÍ");
	textcolor(LIGHTRED);
	gotoxy(5,12);
	cprintf("This program is created by SHIVANSHU VERMA, ABHISHEK RATHOUR and ASHISH");
	gotoxy(5,13);
	cprintf("This program runs only on microsoft copyright system and Linux MINT");
	gotoxy(5,14);
	cprintf("and other higher upgrades. This is a virtual library management simulation");
	gotoxy(5,15);
	cprintf("software made under the guidance of Mr. Shaktirish Agrawal. Please share");
	gotoxy(5,16);
	cprintf("this if you like the software and rate it on windows store.");
	textcolor(LIGHTGREEN+BLINK);
	gotoxy(30,18);
	_setcursortype(_NOCURSOR);
	cprintf("Press any key to go back!");
	getch();
	menu();
}
void front()
{
	clrscr();
	display();
	textcolor(RED+BLUE);
	gotoxy(5,17);
	cprintf("Made By : ");
	for(int a=65,b=0;a>15;a-=3,b++)
	{      	textcolor(CYAN);
		gotoxy(a,17);
		cprintf("Shivanshu Verma     ");
		if(b<16)
		{
			gotoxy(b,18);
			cprintf("  Abhishek Rathore ");
		}
		gotoxy(a,19);
		cprintf("Ashish     ");
		delay(15);
		textcolor(RED);
		gotoxy(80,17);
		cprintf("Ü");
		gotoxy(1,18);
		cprintf("Ü");
	}
	for(int cj=21;cj>16;cj--)
	{
		gotoxy(53,cj);
		textcolor(BLUE+RED);
		cprintf("Guided by : ");
		textcolor(CYAN);
		gotoxy(53,cj+1);
		cprintf("Mr. Shaktirish K. Agrawal");
		gotoxy(53,cj+2);
		cprintf("                          ");
		delay(20);
	}
	textcolor(LIGHTGREEN+BLINK);
	gotoxy(30,22);
	cprintf("Press any key to continue!");
	getch();
}
void menu()
{
	border();
	_setcursortype(_NORMALCURSOR);
	textcolor(GREEN);
	gotoxy(19,4);
	cprintf("ÌËÍÍËÍÍË¹    ÌËÍÍÍ¹    ÌËÍÍÍ»    ÌË¹   ÌË¹");
	gotoxy(19,5);
	delay(100);
	cprintf(" º  º  º      º         º   º     º     º ");
	gotoxy(19,6);
	delay(100);
	cprintf(" º  Ê  º      ÌÍÍÍ¹     º   º     º     º ");
	gotoxy(19,7);
	delay(100);
	cprintf(" º     º      º         º   º     º     º ");
	gotoxy(19,8);
	delay(100);
	cprintf("ÌÊ¹   ÌÊ¹    ÌÊÍÍÍ¹    ÌÊ¹ ÌÊ¹    ÈÍÍÍÍÍ¼ ");

			table();
			textcolor(YELLOW);
			gotoxy(11,10);
			cprintf("Key Configuration: W=Up, S=Down, A=Left ,D=Right and E=Enter");
			textcolor(RED+BLUE);
			gotoxy(10,12);
			cprintf("1.List of Books");
			gotoxy(10,14);
			cprintf("2.List of issued books");
			gotoxy(10,16);
			cprintf("3.List of returned books");
			gotoxy(10,18);
			cprintf("4.Book issue");
			gotoxy(10,20);
			cprintf("5.Books return");
			gotoxy(10,22);
			cprintf("6.Books purchase");
			gotoxy(50,12);
			cprintf("7.Modify Details");
			gotoxy(50,14);
			cprintf("8.Delete Book");
			gotoxy(50,16);
			cprintf("9.Query by book");
			gotoxy(50,18);
			cprintf("10.Late Fine details");
			gotoxy(50,20);
			cprintf("11.About Application");
			gotoxy(50,22);
			cprintf("12.Exit");
			int x=8,y;
			char key;
			r:
			y=12;
			gotoxy(x,12);
			p:
			key=getch();
			if(y>22||y<12)
				goto r;
			else
			{
				if(key=='a'||key=='A')
				{
					x=8;
					gotoxy(x,y);
				}
				if(key=='d'||key=='D')
				{
					x=46;
					gotoxy(x,y);
				}
				if(key=='w'||key=='W')
				{
					y-=2;
					gotoxy(x,y);
				}
				if(key=='s'||key=='S')
				{
					y+=2;
					gotoxy(x,y);
				}
				if(y==22)
					if(x==46)
					{
						if(key=='E'||key=='e')
						exit(0);
					}
					else
					{
					if(key=='E'||key=='e')
						s.writedata();
					}
				if(y==18)
					if(x==8)
					{
						if(key=='E'||key=='e')
						s.issue();
					}
					else
					{
						if(key=='E'||key=='e')
							s.repout();
					}
				 if(y==20)
					 if(x==46)
					 {
						if(key=='E'||key=='e')
							about();
					 }
					 else
					 {
						if(key=='E'||key=='e')
						{
							s.returna();
							menu();
						}
					 }
				 if(y==12)
					 if(x==8)
					 {
						  if(key=='E'||key=='e')
							  s.readdata();
					 }
					 else
						 {
							 if(key=='E'||key=='e')
								s.modi();
						 }
				if(y==14)
					if(x==46)
					{
						if(key=='E' || key=='e')
							s.delrecord();
					}
					else
					{
						if(key=='E' || key=='e')
							s.issuelist();
					}
				if(y==16)
					if(x==46)
					{
						if(key=='E'||key=='e')
						{
							s.query();
							menu();
						}
					}
					else
					{
						if(key=='E'||key=='e')
						{
							s.returnlist();
						}
					}
				goto p;
			}
}
void main()
{
	front();
	menu();
}