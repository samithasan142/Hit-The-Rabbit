#include<iostream>
#include "iGraphics.h"
#include<gl\GLU.h>
#include<time.h>
#include<ctime>
#include<windows.h>



char var1[100];
char t1[100],t2[100];
char playerName[30];

int indexNumber=0;
int aust=0;
int kk;


int h=0,life=5;
int v,count=0;
int mposx, mposy;

int r=255,g=255,b=255;
int x=30;
int menu=0;
int pause=0;
int l,m,rr;
int save=0;

int mm,MEN;

 
//char pN[5][20];
char pS[5][20];

struct FilePurpose{
	char name[30];
	int score;
};

FilePurpose pN[5];


int len;

//Reading from text file for Highscore 
void file(){
	
	int i=0;
	FILE *fptr = fopen("h1.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
    }
    
    while (fscanf(fptr,"%s %d",&pN[i].name,&pN[i].score) != EOF)
    {
		printf ("%s %d\n", pN[i].name,pN[i].score);
		i++;
    }
	strcpy(pN[i].name,playerName);
	pN[i].score=aust;
	printf ("%s %d\n", pN[i].name,pN[i].score);
    fclose(fptr);
	FilePurpose temp;
	
	//Sorting the scores
	for(int i=0;i<=4;i++){
		for(int j=i+1;j<=5;j++){
			if(pN[i].score<pN[j].score){
				temp=pN[i];
				pN[i]=pN[j];
				pN[j]=temp;
			}
		}
	}

	//Writing from text file for Highscore 
	FILE *fp=fopen("h1.txt","w");
	for(int i=0;i<5;i++){
		fprintf(fp,"%s %d\n", pN[i].name, pN[i].score);
	}
	len=0;
	pN[3].name[0]='\0';
	fclose(fp);

}


void fileWrite(){
	int i=0;
	FILE *fptr = fopen("h1.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
    }
    
    while (fscanf(fptr,"%s %s",&pN[i].name,&pS[i]) != EOF)
    {
		printf ("%s %d\n", pN[i].name,pS[i]);
		i++;
    }
	//printf ("%s %d\n", pN[i].name,pS[i]);
    fclose(fptr);
}


//Loading for opening page  
void Load()
{
	if(x<=210)
	{
		x=x+30;	
	}
}


//For Rabbit showing
void show0()
{
	iShowBMP2(170,540,"Pictures\\RabbitNew3.bmp",0);//0
}

void show1()
{
	iShowBMP2(170+250,540,"Pictures\\RabbitNew3.bmp",0);//1
}

void show2()
{
	iShowBMP2(170+500,540,"Pictures\\RabbitNew3.bmp",0);//2
}

void show3()
{
	iShowBMP2(170+750,540,"Pictures\\RabbitNew3.bmp",0);//3
}

void show4()
{
	iShowBMP2(170,410,"Pictures\\RabbitNew3.bmp",0);//4
}

void show5()
{
	iShowBMP2(170+250,410,"Pictures\\RabbitNew3.bmp",0);//5
}
void show6()
{
	iShowBMP2(170+500,410,"Pictures\\RabbitNew3.bmp",0);//6
}
void show7()
{
	iShowBMP2(170+750,410,"Pictures\\RabbitNew3.bmp",0);//7
}
void show8()
{
	iShowBMP2(170,280,"Pictures\\RabbitNew3.bmp",0);//8
}
void show9()
{
	iShowBMP2(170+250,280,"Pictures\\RabbitNew3.bmp",0);//9
}
void show10()
{
	iShowBMP2(170+500,280,"Pictures\\RabbitNew3.bmp",0);//10
}
void show11()
{
	iShowBMP2(170+750,280,"Pictures\\RabbitNew3.bmp",0);//11
}
void show12()
{
	iShowBMP2(170,150,"Pictures\\RabbitNew3.bmp",0);//12
}
void show13()
{
	iShowBMP2(170+250,150,"Pictures\\RabbitNew3.bmp",0);//13
}
void show14()
{
	iShowBMP2(170+500,150,"Pictures\\RabbitNew3.bmp",0);//14
}
void show15()
{
	iShowBMP2(170+750,150,"Pictures\\RabbitNew3.bmp",0);//15
}


//For Frog showing
void frog0()
{
	iShowBMP2(170,540,"Pictures\\frog.bmp",0);//0
}

void frog1()
{
	iShowBMP2(170+250,540,"Pictures\\frog.bmp",0);//1
}

void frog2()
{
	iShowBMP2(170+500,540,"Pictures\\frog.bmp",0);//2
}

void frog3()
{
	iShowBMP2(170+750,540,"Pictures\\frog.bmp",0);//3
}

void frog4()
{
	iShowBMP2(170,410,"Pictures\\frog.bmp",0);//4
}

void frog5()
{
	iShowBMP2(170+250,410,"Pictures\\frog.bmp",0);//5
}
void frog6()
{
	iShowBMP2(170+500,410,"Pictures\\frog.bmp",0);//6
}
void frog7()
{
	iShowBMP2(170+750,410,"Pictures\\frog.bmp",0);//7
}
void frog8()
{
	iShowBMP2(170,280,"Pictures\\frog.bmp",0);//8
}
void frog9()
{
	iShowBMP2(170+250,280,"Pictures\\frog.bmp",0);//9
}
void frog10()
{
	iShowBMP2(170+500,280,"Pictures\\frog.bmp",0);//10
}
void frog11()
{
	iShowBMP2(170+750,280,"Pictures\\frog.bmp",0);//11
}
void frog12()
{
	iShowBMP2(170,150,"Pictures\\frog.bmp",0);//12
}
void frog13()
{
	iShowBMP2(170+250,150,"Pictures\\frog.bmp",0);//13
}
void frog14()
{
	iShowBMP2(170+500,150,"Pictures\\frog.bmp",0);//14
}
void frog15()
{
	iShowBMP2(170+750,150,"Pictures\\frog.bmp",0);//15
}

//For Mouse showing
void mouse0()
{
	iShowBMP2(170,540,"Pictures\\NewRat.bmp",0);//0
}

void mouse1()
{
	iShowBMP2(170+250,540,"Pictures\\NewRat.bmp",0);//1
}

void mouse2()
{
	iShowBMP2(170+500,540,"Pictures\\NewRat.bmp",0);//2
}

void mouse3()
{
	iShowBMP2(170+750,540,"Pictures\\NewRat.bmp",0);//3
}

void mouse4()
{
	iShowBMP2(170,410,"Pictures\\NewRat.bmp",0);//4
}

void mouse5()
{
	iShowBMP2(170+250,410,"Pictures\\NewRat.bmp",0);//5
}
void mouse6()
{
	iShowBMP2(170+500,410,"Pictures\\NewRat.bmp",0);//6
}
void mouse7()
{
	iShowBMP2(170+750,410,"Pictures\\NewRat.bmp",0);//7
}
void mouse8()
{
	iShowBMP2(170,280,"Pictures\\NewRat.bmp",0);//8
}
void mouse9()
{
	iShowBMP2(170+250,280,"Pictures\\NewRat.bmp",0);//9
}
void mouse10()
{
	iShowBMP2(170+500,280,"Pictures\\NewRat.bmp",0);//10
}
void mouse11()
{
	iShowBMP2(170+750,280,"Pictures\\NewRat.bmp",0);//11
}
void mouse12()
{
	iShowBMP2(170,150,"Pictures\\NewRat.bmp",0);//12
}
void mouse13()
{
	iShowBMP2(170+250,150,"Pictures\\NewRat.bmp",0);//13
}
void mouse14()
{
	iShowBMP2(170+500,150,"Pictures\\NewRat.bmp",0);//14
}
void mouse15()
{
	iShowBMP2(170+750,150,"Pictures\\NewRat.bmp",0);//15
}



//For Heart showing
void lifeplus0() 
{
	iShowBMP2(275,435,"Pictures\\LifePlus.bmp",0);
}

void lifeplus1()
{
	iShowBMP2(775,435,"Pictures\\LifePlus.bmp",0);
}

void lifeplus2()
{
	iShowBMP2(525,305,"Pictures\\LifePlus.bmp",0);
}

void lifeplus3()
{
	iShowBMP2(275,175,"Pictures\\LifePlus.bmp",0);
}
void lifeplus4()
{
	iShowBMP2(775,175,"Pictures\\LifePlus.bmp",0);
}    



//Random function which is calling Rabbits, Frogs & Mouses
 void func1()
{
	if(pause==0)
	{
		l=rand()%16;
	}

	if(pause==0)
	{
		m=rand()%16;
	}

	if(pause==0)
	{
		rr=rand()%16;
	}

	kk=-1;
}


//Random function which is calling Hearts
void func4()  
  {
     if(pause==0)
	{
		count++;
		v=rand()%5;
	}
  } 

//Timer calling for ending game
void timer() 
   {
	   if(pause==0)
	   {
		   mm=mm-1;
	   }
	    
   } 

void sound()
	{
		if(pause==0)
		{
			if(menu==2){
				PlaySound("PimPoy.wav", NULL, SND_ASYNC);
			}
		}
	}





/*
	function iDraw() is called again and again by the system.
*/


void iDraw()
{
	//place your drawing codes here
	iClear();

	
		

		r=rand()%180;
        b=rand()%145;
		g=rand()%205;

	    //Game opening page
		if(menu==0)
		{
			iShowBMP(0,0,"Pictures\\new.bmp");

			iSetColor(24, 211, 222);
			iFilledRectangle(510,120,x,30);
			iRectangle(510,120,240,30);
			iSetColor(r,b,220);
			iText(585,80,"LOADING",GLUT_BITMAP_TIMES_ROMAN_24);

			if(x==240)
			{	
				menu=1;
			}

	 }	

	
	//Menu Page  
	if(menu==1)
	{

	iShowBMP(0,0,"Pictures\\MenuPage.bmp");

	iSetColor(255,126,0);
	iFilledRectangle(216,510,158,42);

    iSetColor(237,242,187);
	iFilledRectangle(220,514,150,34);
	iSetColor(0,0,0);
	iText(225,519,"NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);


    iSetColor(255,126,0);
	iFilledRectangle(236,451,118,42);
    
	iSetColor(237,242,187);
	iFilledRectangle(240,455,110,34);
	iSetColor(0,0,0);		
	iText(245,460,"RESUME",GLUT_BITMAP_TIMES_ROMAN_24);

	
	iSetColor(255,126,0);
	iFilledRectangle(193,392,198,42);
	
	iSetColor(237,242,187);
	iFilledRectangle(197,396,190,34);
	iSetColor(0,0,0);
	iText(202,401,"INSTRUCTIONS",GLUT_BITMAP_TIMES_ROMAN_24);


	iSetColor(255,126,0);
	iFilledRectangle(206,333,168,42);
	
	iSetColor(237,242,187);
	iFilledRectangle(210,337,160,34);
	iSetColor(0,0,0);
	iText(215,342,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(255,126,0);
	iFilledRectangle(236,274,110,42);
	
	iSetColor(237,242,187);
	iFilledRectangle(240,278,102,34);
	iSetColor(0,0,0);
	iText(245,283,"CREDIT",GLUT_BITMAP_TIMES_ROMAN_24);  


	iSetColor(255,126,0);
	iFilledRectangle(251,215,76,42);

	iSetColor(237,242,187);
	iFilledRectangle(255,219,68,34);
	iSetColor(0,0,0);
	iText(260,224,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);  
	  
	
	}


	
	
	else if(menu==2)
	{


	   

		iShowBMP(0,0,"Pictures\\ss2.bmp");


		iSetColor(153,76,0);
		iFilledEllipse(200,550,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200,550,80,10,100);
		//iShowBMP(170,540,"Pictures\\RabbitCarrot2.bmp");//0

		iSetColor(153,76,0);
		iFilledEllipse(200+250,550,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+250,550,80,10,100);
		//iShowBMP(170+250,540,"Pictures\\RabbitCarrot2.bmp");//1


		iSetColor(153,76,0);
		iFilledEllipse(200+500,550,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+500,550,80,10,100);
		//iShowBMP(170+500,540,"Pictures\\RabbitCarrot2.bmp");//2

		iSetColor(153,76,0);
		iFilledEllipse(200+750,550,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+750,550,80,10,100);
		//iShowBMP(170+750,540,"Pictures\\RabbitCarrot2.bmp");//3


		iSetColor(153,76,0);
		iFilledEllipse(200,420,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200,420,80,10,100);
		//iShowBMP(170,410,"Pictures\\RabbitCarrot2.bmp");//4
		
		iSetColor(153,76,0);
		iFilledEllipse(200+250,420,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+250,420,80,10,100);
		//iShowBMP(170+250,410,"Pictures\\RabbitCarrot2.bmp");//5

		iSetColor(153,76,0);
		iFilledEllipse(200+500,420,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+500,420,80,10,100);
		//iShowBMP(170+500,410,"Pictures\\RabbitCarrot2.bmp");//6

		iSetColor(153,76,0);
		iFilledEllipse(200+750,420,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+750,420,80,10,100);
		//iShowBMP(170+750,410,"Pictures\\RabbitCarrot2.bmp");//7



		iSetColor(153,76,0);
		iFilledEllipse(200,290,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200,290,80,10,100);
		//iShowBMP(170,280,"Pictures\\RabbitCarrot2.bmp");//8
		
		iSetColor(153,76,0);
		iFilledEllipse(200+250,290,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+250,290,80,10,100);
		//iShowBMP(170+250,280,"Pictures\\RabbitCarrot2.bmp");//9

		iSetColor(153,76,0);
		iFilledEllipse(200+500,290,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+500,290,80,10,100);
		//iShowBMP(170+500,280,"Pictures\\RabbitCarrot2.bmp");//10

		iSetColor(153,76,0);
		iFilledEllipse(200+750,290,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+750,290,80,10,100);
		//iShowBMP(170+750,280,"Pictures\\RabbitCarrot2.bmp");//11


		iSetColor(153,76,0);
		iFilledEllipse(200,160,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200,160,80,10,100);
		//iShowBMP(170,150,"Pictures\\RabbitCarrot2.bmp");//12
		
		iSetColor(153,76,0);
		iFilledEllipse(200+250,160,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+250,160,80,10,100);
		//iShowBMP(170+250,150,"Pictures\\RabbitCarrot2.bmp");//13

		iSetColor(153,76,0);
		iFilledEllipse(200+500,160,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+500,160,80,10,100);
		//iShowBMP(170+500,150,"Pictures\\RabbitCarrot2.bmp");//14

		iSetColor(153,76,0);
		iFilledEllipse(200+750,160,100,20,100);
		iSetColor(0,0,0);
		iFilledEllipse(200+750,160,80,10,100);
		//iShowBMP(170+750,150,"Pictures\\RabbitCarrot2.bmp");//15

	
    //For Rabbits Ups & Downs when Frogs and Mouses will never come in same place 
	if(l!=m && l!=rr)
	{ 
		if(l==0)
		{
		show0();
		}
	

		if(l==1)
		{
		  show1();
		}
	

		if(l==2)
		{
		  show2();
		}

		if(l==3)
		{
		  show3();
		}

		if(l==4)
		{
		  show4();
		}

		if(l==5)
		{
		  show5();
		}

		if(l==6)
		{
		  show6();
		}

		if(l==7)
		{
		  show7();
		}
		if(l==8)
		{
		  show8();
		}
		if(l==9)
		{
		  show9();
		}
		if(l==10)
		{
		  show10();
		}
		if(l==11)
		{
		  show11();
		}
		if(l==12)
		{
		  show12();
		}
		if(l==13)
		{
		  show13();
		}
		if(l==14)
		{
		  show14();
		}
		if(l==15)
		{
		  show15();
		}

	}

	
//For Frogs Ups & Downs when Rabbits and Mouses will never come in same place
  if(m!=l && m!=rr)
  {
	  
	if(m==0)
	{
	  frog0();
	}

    if(m==1)
	{
	  frog1();
	}
	

	if(m==2)
	{
	  frog2();
	}

	if(m==3)
	{
	  frog3();
	}

	if(m==4)
	{
	  frog4();
	}

	if(m==5)
	{
	  frog5();
	}

	if(m==6)
	{
	  frog6();
	}

	if(m==7)
	{
	  frog7();
	}
	if(m==8)
	{
	  frog8();
	}
	if(m==9)
	{
	  frog9();
	}
	if(m==10)
	{
	  frog10();
	}
	if(m==11)
	{
	  frog11();
	}
	if(m==12)
	{
	  frog12();
	}
	if(m==13)
	{
	  frog13();
	}
	if(m==14)
	{
	 frog14();
	}
	if(m==15)
	{
	  frog15();
	}

  }

  //For Mouses Ups & Downs when Rabbits and Frogs will never come in same place
  if(rr!=l && rr!=m)
  {
	  
	if(rr==0)
	{
	  mouse0();
	}

    if(rr==1)
	{
	  mouse1();
	}
	

	if(rr==2)
	{
	  mouse2();
	}

	if(rr==3)
	{
	  mouse3();
	}

	if(rr==4)
	{
	  mouse4();
	}

	if(rr==5)
	{
	  mouse5();
	}

	if(rr==6)
	{
	  mouse6();
	}

	if(rr==7)
	{
	  mouse7();
	}
	if(rr==8)
	{
	  mouse8();
	}
	if(rr==9)
	{
	  mouse9();
	}
	if(rr==10)
	{
	  mouse10();
	}
	if(rr==11)
	{
	  mouse11();
	}
	if(rr==12)
	{
	  mouse12();
	}
	if(rr==13)
	{
	  mouse13();
	}
	if(rr==14)
	{
	  mouse14();
	}
	if(rr==15)
	{
	  mouse15();
	}

  }


  //For Hearts ups & downs
  if(count%10==0)   
			 {

			 if(v==0)
			  {
				  lifeplus0();
			  }
		     if(v==1)
			  {
				  lifeplus1();
			  }
			 if(v==2)
			  {
				  lifeplus2();
			  }
			 if(v==3)
			  {
				  lifeplus3();
			  }
			 if(v==4)
			  {
				  lifeplus4();
			  }
			 } 
	


	iSetColor(174, 210, 241);
    iFilledRectangle(450,65,160,34);
	iSetColor(125, 7, 31);
	iText(455,70,"SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(125, 7, 31);
	itoa(h,var1,10);
	iText(550,70,var1,GLUT_BITMAP_TIMES_ROMAN_24);



	iSetColor(174, 210, 241);
    iFilledRectangle(845,65,215,34);
	iSetColor(125, 7, 31);
	iText(850,70,"LIFE : ",GLUT_BITMAP_TIMES_ROMAN_24);
	
					//For showing how many life players have
					if(life==5)
					{

						iShowBMP2(920,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(945,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(970,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(995,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(1020,65,"Pictures\\Heart.bmp",0);
					}

					if(life==4)
					{
	
						iShowBMP2(920,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(945,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(970,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(995,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(1020,65,"Pictures\\Heart.bmp",0);
					}

					if(life==3)
					{
						iShowBMP2(920,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(945,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(970,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(995,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(1020,65,"Pictures\\Heart.bmp",0);
					}

					if(life==2)
					{
						iShowBMP2(920,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(945,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(970,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(995,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(1020,65,"Pictures\\Heart.bmp",0);
					}

					if(life==1)
					{
						iShowBMP2(920,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(945,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(970,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(995,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(1020,65,"Pictures\\Heart.bmp",0);
					}

        iSetColor(174, 210, 241);
        iFilledRectangle(845,620,215,34);
	    iSetColor(125, 7, 31);
	    iText(850,628,"TIMER :",GLUT_BITMAP_TIMES_ROMAN_24);




		iSetColor(174, 210, 241);
		iFilledRectangle(105,65,75,34);
		iSetColor(125, 7, 31);
		iText(110,70,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);


		//Writing text file for save the game
		if(save==1){
		FILE *fp1 = fopen("saveload.txt","w");
		fprintf(fp1,"%d %d %d %d %d\n",h,life,v,count,mm);
		fclose(fp1);

		save=0;

		}


	  //Showing timer in the game page
      iSetColor(225, 7, 0);
	  itoa(mm/60,t1,10);
	  iText(950,628,t1,GLUT_BITMAP_TIMES_ROMAN_24);

	  iText(962,628,":",GLUT_BITMAP_TIMES_ROMAN_24);

	  iSetColor(225, 7, 0);
	  itoa(mm%60,t2,10);
	  iText(970,628,t2,GLUT_BITMAP_TIMES_ROMAN_24);

	  //*********
	  iSetColor(255,255,0);
	  iFilledRectangle(408,629,260,32);
	  iSetColor(0,0,0);
	  iText(412,638,"Press s for save the game",GLUT_BITMAP_TIMES_ROMAN_24);

	  //If the limit of time is finished, then the game over page will come
	  if(mm==0)
			{
				menu=10;
			}

	  
	  //For showing blood when hit the rabbits
	  if(kk==0)
	  {
		  iShowBMP2(170,540,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==1)
	  {
		  iShowBMP2(170+250,540,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==2)
	  {
		  iShowBMP2(170+500,540,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==3)
	  {
		  iShowBMP2(170+750,540,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==4)
	  {
		  iShowBMP2(170,410,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==5)
	  {
		  iShowBMP2(170+250,410,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==6)
	  {
		  iShowBMP2(170+500,410,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==7)
	  {
		  iShowBMP2(170+750,410,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==8)
	  {
		  iShowBMP2(170,280,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==9)
	  {
		  iShowBMP2(170+250,280,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==10)
	  {
		  iShowBMP2(170+500,280,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==11)
	  {
		  iShowBMP2(170+750,280,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==12)
	  {
		  iShowBMP2(170,150,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==13)
	  {
		  iShowBMP2(170+250,150,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==14)
	  {
		  iShowBMP2(170+500,150,"Pictures\\blood7.bmp",0);
	  }

	  if(kk==15)
	  {
		  iShowBMP2(170+750,150,"Pictures\\blood7.bmp",0);
	  }

}
	
	//Resume Page
	else if(menu==3)
	{
		
		iSetColor(r,b,190);
		iFilledRectangle(100,80,75,34);
		iSetColor(125, 7, 31);
		iText(105,85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);

	}


	//Instructions Page
	else if(menu==4)
	{

		iShowBMP(0,0,"Pictures\\instra3.bmp");
		
		iSetColor(r,b,190);
		iFilledRectangle(100,80,75,34);
		iSetColor(125, 7, 31);
		iText(105,85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);

	}

	//Highscore Page
	else if(menu==5)
	{	
		
		iShowBMP(0,0,"Pictures\\bgimage2.bmp");
		

		iSetColor(255,255,0);
		int x=430,y=450;
		for(int i=0;i<5;i++){
		
			iText(x, y, pN[i].name ,GLUT_BITMAP_TIMES_ROMAN_24);
			iText(x+280, y,pS[i] ,GLUT_BITMAP_TIMES_ROMAN_24);
			y-=50;
		}

		iSetColor(r,b,170);
		iFilledRectangle(100,80,75,34);
		iSetColor(125, 7, 31);
		iText(105,85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	}


	//Credit Page
	else if(menu==6)
	{

		iShowBMP(0,0,"Pictures\\credit2.bmp");

		iSetColor(r,b,190);
		iFilledRectangle(100,80,75,34);
		iSetColor(125, 7, 31);
		iText(105,85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);


		
	}

	//Game Over Page
	else if(menu==10)
	{

		
		iShowBMP(0,0,"Pictures\\GameOver.bmp");
		iSetColor(24, 211, 222);
	    iFilledRectangle(350,115+100,500,35);
		iSetColor(0, 0, 0);
		iText(360,125+100,"Enter Player Name: ",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 0, 0);
		iText(585,125+100,playerName,GLUT_BITMAP_TIMES_ROMAN_24);
		
		h=0;
		life=5;
		r=255,g=255,b=255;
		x=30;


		if(MEN==1)
		{
			MEN=-1;
			menu=1;
			
		}
		
	}

}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	 if(menu==1)
		{
	  if(mx>=220 && mx<=370 && my>=514 && my<=548)
	  {
	      PlaySound("click.wav",NULL,SND_SYNC);
		  menu=2;
		  mm=120;


		  h=0;
	      life=5;



	  }
		  
	  else if(mx>=240 && mx<=355 && my>=455 && my<=489)
	  {
	   PlaySound("click.wav",NULL,SND_SYNC);
	   menu=3;

	  }
		      
	  else if(mx>=197 && mx<=387 && my>=396 && my<=430)
	  {
	   PlaySound("click.wav",NULL,SND_SYNC);
	    menu=4;
	  }
		 
	  else if(mx>=210 && mx<=370 && my>=337 && my<=371)
	  {
		    PlaySound("click.wav",NULL,SND_SYNC);
			menu=5;
	  }
		
	  else if(mx>=240 && mx<=342 && my>=278 && my<=312)
	  {
		  PlaySound("click.wav",NULL,SND_SYNC);
		  menu=6;
	  }


	 else if(mx>=255 && mx<=323 && my>=219 && my<=253)
	  {
		  PlaySound("click.wav",NULL,SND_SYNC);
		  menu=7;
	  }
		  
	  }


	  if(menu==2)
	  {
		  if(pause==0)
		  {

		  if(mx>=105 && mx<=180 && my>=65 && my<=99)
		  {
		     PlaySound("click.wav",NULL,SND_SYNC);
		     menu=1;
		  }	 


		   if((v==0 && mx>=275 && mx<=375 && my>=435 && my<=515 ) || (v==1 && mx>=775 && mx<=875 && my>=435 && my<=515 ) || (v==2 && mx>=525 && mx<=625 && my>=305 && my<=385 ) || (v==3 && mx>=275 && mx<=375 && my>=175 && my<=255 ) ||  (v==4 && mx>=775 && mx<=875 && my>=175 && my<=255 ) )
				{
					
					if(life<5)
					{
						PlaySound("click.wav",NULL,SND_SYNC);
						life=life+1;
					}
					
					v=-1;
				}

		  

				if(l==0 && mx>=170 && mx<=233 && my>=540 && my<=609 )
				{
					h++;
					aust++;
					kk=0;
					l=-1;	
				}

				if(l==1 && mx>=420 && mx<=483 && my>=540 && my<=609) 
				{
					h++;
					aust++;
					kk=1;
					l=-1;	
				}

				if (l==2 && mx>=670 && mx<=733 && my>=540 && my<=609)  
				{
					h++;
					aust++;
					kk=2;
					l=-1;	
				}

				if(l==3 && mx>=920 && mx<=983 && my>=540 && my<=609)  
				{
					h++;
					aust++;
					kk=3;
					l=-1;	
				}

				if(l==4 && mx>=170 && mx<=233 && my>=410 && my<=479) 
				{
					h++;
					aust++;
					kk=4;
					l=-1;	
				}

				if(l==5 && mx>=420 && mx<=483 && my>=410 && my<=479) 
				{
					h++;
					aust++;
					kk=5;
					l=-1;	
				}

				if(l==6 && mx>=670 && mx<=733 && my>=410 && my<=479) 
				{
					h++;
					aust++;
					kk=6;
					l=-1;	
				}

				if(l==7 && mx>=920 && mx<=983 && my>=410 && my<=479) 
				{
					h++;
					aust++;
					kk=7;
					l=-1;	
				}

				if(l==8 && mx>=170 && mx<=233 && my>=280 && my<=349) 
				{
					h++;
					aust++;
					kk=8;
					l=-1;	
				}

				if(l==9 && mx>=420 && mx<=483 && my>=280 && my<=349) 
				{
					h++;
					aust++;
					kk=9;
					l=-1;	
				}

				if(l==10 && mx>=670 && mx<=733 && my>=280 && my<=349) 
				{
					h++;
					aust++;
					kk=10;
					l=-1;	
				}

				if(l==11 && mx>=920 && mx<=983 && my>=280 && my<=349) 
				{
					h++;
					aust++;
					kk=11;
					l=-1;	
				}

				if(l==12 && mx>=170 && mx<=233 && my>=150 && my<=219) 
				{
					h++;
					aust++;
					kk=12;
					l=-1;	
				}

				if(l==13 && mx>=420 && mx<=483 && my>=150 && my<=219) 
				{
					h++;
					aust++;
					kk=13;
					l=-1;	
				}

				if(l==14 && mx>=670 && mx<=733 && my>=150 && my<=219) 
				{
					h++;
					aust++;
					kk=14;
					l=-1;	
				}

				if(l==15 && mx>=920 && mx<=983 && my>=150 && my<=219) 
				{
					h++;
					aust++;
					kk=15;
					l=-1;	
				}



			

				
			    if((m==0 && mx>=170 && mx<=233 && my>=540 && my<=609 ) || (m==1 && mx>=420 && mx<=483 && my>=540 && my<=609)  ||  (m==2 && mx>=670 && mx<=733 && my>=540 && my<=609) ||  (m==3 && mx>=920 && mx<=983 && my>=540 && my<=609) ||  (m==4 && mx>=170 && mx<=233 && my>=410 && my<=479) ||  (m==5 && mx>=420 && mx<=483 && my>=410 && my<=479) ||  (m==6 && mx>=670 && mx<=733 && my>=410 && my<=479) ||  (m==7 && mx>=920 && mx<=983 && my>=410 && my<=479)  ||  (m==8 && mx>=170 && mx<=233 && my>=280 && my<=349) ||  (m==9 && mx>=420 && mx<=483 && my>=280 && my<=349) ||  (m==10 && mx>=670 && mx<=733 && my>=280 && my<=349) ||  (m==11 && mx>=920 && mx<=983 && my>=280 && my<=349) ||  (m==12 && mx>=170 && mx<=233 && my>=150 && my<=219) ||  (m==13 && mx>=420 && mx<=483 && my>=150 && my<=219) ||  (m==14 && mx>=670 && mx<=733 && my>=150 && my<=219) ||  (m==15 && mx>=920 && mx<=983 && my>=150 && my<=219) || (rr==0 && mx>=170 && mx<=233 && my>=540 && my<=609 ) || (rr==1 && mx>=420 && mx<=483 && my>=540 && my<=609)  ||  (rr==2 && mx>=670 && mx<=733 && my>=540 && my<=609) ||  (rr==3 && mx>=920 && mx<=983 && my>=540 && my<=609) ||  (rr==4 && mx>=170 && mx<=233 && my>=410 && my<=479) ||  (rr==5 && mx>=420 && mx<=483 && my>=410 && my<=479) ||  (rr==6 && mx>=670 && mx<=733 && my>=410 && my<=479) ||  (rr==7 && mx>=920 && mx<=983 && my>=410 && my<=479)  ||  (rr==8 && mx>=170 && mx<=233 && my>=280 && my<=349) ||  (rr==9 && mx>=420 && mx<=483 && my>=280 && my<=349) ||  (rr==10 && mx>=670 && mx<=733 && my>=280 && my<=349) ||  (rr==11 && mx>=920 && mx<=983 && my>=280 && my<=349) ||  (rr==12 && mx>=170 && mx<=233 && my>=150 && my<=219) ||  (rr==13 && mx>=420 && mx<=483 && my>=150 && my<=219) ||  (rr==14 && mx>=670 && mx<=733 && my>=150 && my<=219) ||  (rr==15 && mx>=920 && mx<=983 && my>=150 && my<=219))
		        {
					life=life-1;
					m=-1;
					rr=-1;
					if(life==5)
					{

						iShowBMP2(920,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(945,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(970,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(995,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(1020,65,"Pictures\\Heart.bmp",0);
					}

					if(life==4)
					{
	
						iShowBMP2(920,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(945,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(970,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(995,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(1020,65,"Pictures\\Heart.bmp",0);
					}

					if(life==3)
					{
						iShowBMP2(920,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(945,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(970,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(995,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(1020,65,"Pictures\\Heart.bmp",0);
					}

					if(life==2)
					{
						iShowBMP2(920,65,"Pictures\\Heart.bmp",0);
						iShowBMP2(945,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(970,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(995,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(1020,65,"Pictures\\Heart.bmp",0);
					}

					if(life==1)
					{
						iShowBMP2(920,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(945,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(970,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(995,65,"Pictures\\Heart.bmp",0);
						//iShowBMP2(1020,65,"Pictures\\Heart.bmp",0);
					}


					// if life is finished, then it will go to the game over page
					if(life==0 )
					{
						menu=10;
					}

					
			
				
		        }
			}
		   
		   
	  }

	 /* if(menu==3)
	   {
		  
		  if(mx>=100 && mx<=175 && my>=80 && my<=114)
		   {
		     PlaySound("click.wav",NULL,SND_SYNC);
		     menu=1;
		   } 

	   		 
	    }*/


	  if(menu==3){

	    save=2;
		//reading from text file for resume the game
	   	if(save==2){
		FILE *fp2 = fopen("saveload.txt","r");
		fscanf(fp2,"%d %d %d %d %d \n",&h,&life,&v,&count,&mm);
		fclose(fp2);
		}
	    menu=2;

	}

	  if(menu==4)
	  {
		 if(mx>=100 && mx<=175 && my>=80 && my<=114)
		 {	  
		   PlaySound("click.wav",NULL,SND_SYNC);
		   menu=1;
		 }
	  }

	  if(menu==5)
	  {
		   if(mx>=100 && mx<=175 && my>=80 && my<=114)
		   {
			  PlaySound("click.wav",NULL,SND_SYNC);
			  menu=1;
		   }
	  }

	  if(menu==6)
	  {
		   if(mx>=100 && mx<=175 && my>=80 && my<=114)
		   {
			  PlaySound("click.wav",NULL,SND_SYNC);
			  menu=1;
		   }
	  }

	   if(menu==7)
	  {
			 exit(0);
	  }

	}


	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	

}




void iPassiveMouseMove(int mx,int my)
{
		
	

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	//for pause and resume the game
	if(key=='p' || key=='P')
	{
		if (pause==0)
		{
			pause=1;
		}
		else if (pause==1)
		{
			pause=0;
		}
	}


	//for save the game
	if(menu==2){
		if(key=='s'){
			save=1;
		}
	}


	if(menu==10)
	{
	 
		//for input player names in gameover page

       if(key!='\b')
		{
		
			playerName[indexNumber]=key;
			indexNumber++;
			playerName[indexNumber+1]='\0';
		
		}
		else
		{
			if(indexNumber<=0)
			{
				indexNumber=0;
			}
			else
			{
				indexNumber--;
			}
			playerName[indexNumber]='\0';
		}
		if(key=='\r'){
			
			//fileWrite();
			file();
			
			fileWrite();
			MEN=1;
		}
		

	}
	


}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
//
int main()


{

	
	file();
	fileWrite();
	iSetTimer(1000,Load);
	iSetTimer(1500,func1);
	
	iSetTimer(1500,func4);
	iSetTimer(1000,timer);
	iSetTimer(15000,sound);
	


	iInitialize(1200,680, "Hit The Rabbit");
	return 0;
}