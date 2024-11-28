#include <iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include <cstdlib>

using namespace std;

#include "iGraphics.h"
#include "bitmap_loader.h"


//all variables start
#define screenWidth =1000;
#define screenHeight = 600;

bool mainPage = true, startB = false, scoreB = false, helpB = false, aboutB = false, exitB = false, easyPage = false, hardPage = false, mediumPage = false, easyB = false, mediumB = false, hardB = false;
bool startPage = false, scorePage = false, helpPage = false, aboutPage = false, exitPage = false;
bool gameOver = false, afterGameOver = false, easyLeverScore, mHelp = false, eHelp = false, hHelp = false;

int i = 0, hy = 85, score = 0;

bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;




char bg[1][100] = { "photo\\bg.bmp" };
char button[5][100] = { "photo\\buttonB1.bmp", "photo\\buttonB2.bmp", "photo\\buttonB3.bmp", "photo\\buttonB4.bmp", "photo\\buttonB5.bmp" };
char buttonHover[5][100] = { "photo\\buttonP1.bmp", "photo\\buttonP2.bmp", "photo\\buttonP3.bmp", "photo\\buttonP4.bmp", "photo\\buttonP5.bmp" };
char backButton[100] = { "photo\\backb.bmp" };
char name[26] = "Name";
int nameindex = 0;
char tempName[50] = "NoName";


const double gravity = 0.2;
const double timeStep = 0.1;
double circleX = 200;
double circleY = 300;

// Bird properties
double birdPosX = 100, birdPosY = 280, dx = 0, gunPosX=160, gunPosY=160;
double birdVelX = 0, birdVelY = 0;
bool birdInFlight = false;
int birdImage;
int gun;
int targetImage;
int targetImage1;
int targetImage2;
int targetImage3;
//int targetImage1;

int vanish = 1;
int vanish1 = 1;
int vanish2 = 1;
int vanish3 = 1;
int vanish4 = 1;
bool vanishgun = false;
bool mini = true;
bool bird = false;
bool flag = false;
int n = 1;
int m = 1;
bool musicOn = false;
bool dM = false;


int c1x = 400;
int c1y = 1000;
int c1xspeed = 0;
int coinScore = 0;
int coinImage;
bool coinshow = false;

int second = 0;
int sc = 0;


// Target properties
double targetPosX = 765, targetPosY = 130, targetPosX1 = 656, targetPosY1 = 79,targetPosX2 =834 ,targetPosY2 = 204,targetPosX3 = 817,targetPosY3=315,targetPosX4 = 810,targetPosY4 = 430;



const int targetRadius = 20;
int miniimage;
int background;


char sec[10000];
int minute = 0;
int hour = 0;
char hr[10000];
int totalSecond = 0;
char point[10000];

//.........................................................:::MD. MAHDI AZFAR TALUKDER <START> :::.........................................


#define enemyNumber 7
#define enemyPic 8
#define gruRunPic 7

char s[100] = { "     " };
int bc;

//gru's initial co-ordinate
int gruPosX = 10;
int gruPosY = 8;
int gruRunningIndx = 0;

//minions initial co-ordinate
int miniPosX = gruPosX - 10;
int miniPosY = gruPosY - 8;
int minionFollowingIndx = 0;

//co-ordinate of bullet
int bulletX = gruPosX + 135;
int bulletY = gruPosY + 65;

//for moving bullet co-ordinate
long long int bx;
long long int by;
bool gruBullet;

//gru life and score var
int gruLife = 50;
int gruScore = 0;

//when gru is standing, bmp
char gruStand[100] = "\\photo\\running\\bmp\\st.bmp";
//when gru is standing with gun, bmp
char gruStandGun[100] = "photo\\running\\bmp\\r0.bmp";
//when gru is running, BMPs
char gruRunning[gruRunPic][100] = { 
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\running\\bmp\\r0.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\running\\bmp\\r1.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\running\\bmp\\r2.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\running\\bmp\\r3.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\running\\bmp\\r4.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\running\\bmp\\r5.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\running\\bmp\\r6.bmp" };

//when minion is following, BPMs
char minionFollowing[5][100] = { 
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\minion\\bmp\\mn1.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\minion\\bmp\\mn2.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\minion\\bmp\\mn3.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\minion\\bmp\\mn4.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\minion\\bmp\\mn5.bmp" };

//when enemy is attacking, BMPs
char enemyAttakingSprite[enemyPic][100] = { "D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\infected minion\\1.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\infected minion\\2.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\infected minion\\3.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\infected minion\\4.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\infected minion\\5.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\infected minion\\6.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\infected minion\\7.bmp",
"D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\infected minion\\8.bmp" };

//for enemy structure
struct enemy{
	int enemyPosX;
	int enemyPosY;
	int enemyLife;
	//for showing their life update
	std::string enemyLifeText;
	int enemyAttackingIndx;
	//for infected minions bullet movement
	int mx;
	int my;
	//after cured position
	int randX;
	int randY;


};
struct enemy infectedMinion[enemyNumber];

//assiging data to enemy structure
void setEnemies() {
	for (int i = 0; i<enemyNumber; i++){
		infectedMinion[i].enemyAttackingIndx = rand() % enemyPic;
		infectedMinion[i].enemyPosX = 1050 - rand() % 400;
		infectedMinion[i].enemyPosY = rand() % 200 + 0;
		infectedMinion[i].my = infectedMinion[i].enemyPosY + 25;
		infectedMinion[i].mx = 20;
		infectedMinion[i].enemyLife = (rand() % 5) + 1;
		infectedMinion[i].randX = rand() % 80;
		infectedMinion[i].randY = rand() % 80;
	}
}

//change for enemy
void changeForEnemy(){

	for (int i = 0; i < enemyNumber; i++){
		//moving of infected minion toward left to riht
		if (infectedMinion[i].enemyPosX > 0){
			infectedMinion[i].enemyPosX -= 3;
		}
		else if (infectedMinion[i].enemyPosX <= 0){
			setEnemies();
		}
		//movement of infected minions bullet
		if (infectedMinion[i].enemyPosX - infectedMinion[i].mx > 0){
			infectedMinion[i].mx += 25;
		}
		else if (infectedMinion[i].enemyPosX - infectedMinion[i].mx <= 0){
			infectedMinion[i].mx = 20;
		}
		//image rendering of infected minion
		infectedMinion[i].enemyAttackingIndx++;
		if (infectedMinion[i].enemyAttackingIndx >= enemyPic){
			infectedMinion[i].enemyAttackingIndx = 0;
		}
	}
}

void changeForGru(){
	gruRunningIndx++;
	if (gruRunningIndx >= gruRunPic){
		gruRunningIndx = 0;
	}
	minionFollowingIndx++;
	if (minionFollowingIndx >= 5){
		minionFollowingIndx = 0;
	}
}

void bulletMove(){
	bx += 35;
}
//cheacks wether minions are cured or not
void curedCheack(){
	for (int j = 0; j < enemyNumber; j++){
		if (infectedMinion[j].enemyLife){
			if ((by >= infectedMinion[j].enemyPosY + 20 && by <= infectedMinion[j].enemyPosY + 60) && (bx >= infectedMinion[j].enemyPosX && infectedMinion[j].enemyPosX > gruPosX) && infectedMinion[j].enemyLife > 0){
				infectedMinion[j].enemyLife--;
				gruBullet = false;
				by = 0;
			}
		}

	}
}

void gruAttacked(){
	for (int i = 0; i < enemyNumber; i++){
		if (gruLife){
			if ((infectedMinion[i].my >= gruPosY + 48 && infectedMinion[i].my <= gruPosY + 97) && (infectedMinion[i].mx <= gruPosX + 80 && infectedMinion[i].mx >= gruPosX + 40) && gruLife > 0){
				gruLife--;
				infectedMinion[i].mx = infectedMinion[i].mx - 20;

			}
		}

	}
}



//farabe end


//end of variables

void gameOverFunction();

struct allScore{
	char SName[10000];
	int SScore;
}highScore[8],temp,newScore;

void drawTimer();
bool checkCollision(double gunX, double gunY, double targetX, double targetY, double targetRadius) {
	double distance = abs(sqrt(pow(gunX - targetX, 2) + pow(gunY - targetY, 2)));
	
	return distance < targetRadius;
}




void mainPageFunction()
{
	iShowBMP(0, 0, bg[0]);
	

	for (i = 4; i >= 0; i--)
	{
		iShowBMP2(60, hy, button[i], 0);
		hy += 100;
		if (i == 0)
		{
			hy = 75;
		}
	}
	if (startB)
	{
		iShowBMP2(60, 475, buttonHover[0], 0);
	}

	if (scoreB)
	{
		iShowBMP2(60, 375, buttonHover[1], 0);
	}
	if (helpB)
	{
		iShowBMP2(60, 275, buttonHover[2], 0);
	}
	if (aboutB)
	{
		iShowBMP2(60, 175, buttonHover[3], 0);
	}
	if (exitB)
	{
		iShowBMP2(60, 75, buttonHover[4], 0);
	}


}


void startPageFunction()
{


	iShowBMP(0, 0, "photo\\startG.bmp");
	iShowBMP2(7, 500, backButton, 0);




	if (easyB)
	{
		iShowBMP2(95, 245, "photo\\easyB1.bmp", 0);
	}
	else
	{
		iShowBMP2(100, 250, "photo\\easyB.bmp", 0);
	}
	if (mediumB)
	{
		iShowBMP2(370, 245, "photo\\mediumB1.bmp", 0);
	}
	else
	{
		iShowBMP2(375, 250, "photo\\mediumB.bmp", 0);
	}
	if (hardB)
	{
		iShowBMP2(645, 245, "D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\hardB1x.bmp", 0);
	}
	else
	{
		iShowBMP2(650, 250, "photo\\hardB.bmp", 0);
		
	}




}

//game first level

void easyPageFunction()
{
	


	iShowBMP(0, 0, "D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\gameBackground1x.bmp");
	iShowBMP2(40, 340, backButton, 0);
	
	if (bird)
	{

		iShowImage(birdPosX - 20, birdPosY - 200, 100, 100, birdImage);
	}
	if (mini)
	{
		iShowImage(birdPosX - 20, birdPosY - 200, 100, 100, miniimage);
	}
	if (vanish == 1 ) 
	{
		iShowImage(targetPosX - targetRadius, targetPosY - targetRadius , targetRadius * 4, targetRadius * 4, targetImage);

	}
	if (dM)
	{
		PlaySound("D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\dM.wav", NULL, SND_ASYNC);
		dM = false;
	}
	
	if (vanish == -1 )
	{
		iShowImage(targetPosX+50 - targetRadius, targetPosY+20 - targetRadius, targetRadius * 4, targetRadius * 4, targetImage3);

	}

	if (vanish1 == 1)
	{
		iShowImage(targetPosX1 - targetRadius, targetPosY1 - targetRadius, targetRadius * 4, targetRadius * 4, targetImage1);
		
	};
	if (vanish1 == -1 )
	{
		iShowImage(targetPosX1+50 - targetRadius, targetPosY1+20 - targetRadius, targetRadius * 4, targetRadius * 4, targetImage3);
	}
	if (vanish2 == 1)
	{
		iShowImage(targetPosX2 - targetRadius, targetPosY2 - targetRadius, targetRadius * 4, targetRadius * 4, /*targetImage2*/targetImage1);
	}
	if (vanish2 == -1)
	{
		iShowImage(targetPosX2 - targetRadius, targetPosY2 + 20 - targetRadius, targetRadius * 4, targetRadius * 4, /*targetImage2*/targetImage3);
	}
	if (vanish3 == 1 )
	{
		iShowImage(targetPosX3 - targetRadius, targetPosY3 - targetRadius, targetRadius * 4, targetRadius * 4, /*targetImage3*/targetImage1);
	}
	if (vanish3 == -1 )
	{
		iShowImage(targetPosX3 - targetRadius, targetPosY3 - 20 - targetRadius, targetRadius * 4, targetRadius * 4, /*targetImage3*/targetImage3);
	}
	if (vanish4 == 1 )
	{
		iShowImage(targetPosX4 - targetRadius, targetPosY4 - targetRadius, targetRadius * 4, targetRadius * 4, /*targetImage3*/targetImage1);
	}
	if (vanish4 == -1 )
	{
		iShowImage(targetPosX4 - targetRadius, targetPosY4 - 20 - targetRadius, targetRadius * 4, targetRadius * 4, /*targetImage3*/targetImage3);
	}
	if (vanishgun)
	{
		iShowImage(gunPosX, gunPosY, 30, 30, gun);
		
	}
	if (coinshow)
	{
		
		iShowBMP2(c1x, c1y, "photo\\finalcc.bmp",0);

		c1y = c1y - 10;
		
		
		if (c1y <= 0){
			c1y = 1000;
			c1x = 400;
			coinshow = false;
		}
	}
	 drawTimer();
	iSetColor(255, 255, 0);
	iCircle(circleX, circleY, 10, 100);
	iCircle(circleX, circleY, 5, 100);
	



}


//game second level.........................................::MD. MAHDI AZFAR TALUKDER...............................................
void mediumPageFunction()
{
	
	//iShowImage(0, 0, 1000, 600, bc);
	iShowBMP(0, 0, "D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\bc\\bc0.bmp");
	iShowBMP2(7, 500, backButton, 0);

	//game score
	std::string gruScoreText = "Score: " + std::to_string(gruScore);
	iSetColor(255, 255, 0);
	iText(500, 580, const_cast<char*>(gruScoreText.c_str()));
	//gru life
	std::string gruLifeText = "Life:" + std::to_string(gruLife * 2 ) + "%";
	iSetColor(255, 255, 0);
	iText(gruPosX, gruPosY + 115, const_cast<char*>(gruLifeText.c_str()));
	iRectangle(gruPosX, gruPosY + 100, 55, 7);
	double temp1 = (55 / 50);
	iFilledRectangle(gruPosX, gruPosY + 100, gruLife * temp1, 7);
	//gru
	if (gruLife > 0){
		iShowBMP2(gruPosX, gruPosY, gruRunning[gruRunningIndx], 255);
	}
	else if (backButton && mediumPage)
	{
		mediumPage = false;
		gameOver = true;
		easyLeverScore = false;
	}
	else{
		mediumPage = false;
		gameOver = true;
		easyLeverScore = false;

	}
	//following minion
	iShowBMP2(miniPosX, miniPosY, minionFollowing[minionFollowingIndx], 255);
	for (int i = 0; i < enemyNumber; i++){

		if (infectedMinion[i].enemyLife > 0){
			//enemy walking
			iShowBMP2(infectedMinion[i].enemyPosX - 20, infectedMinion[i].enemyPosY, enemyAttakingSprite[infectedMinion[i].enemyAttackingIndx], 255);
			//enemy bullet moving
			
				iFilledCircle(infectedMinion[i].enemyPosX - infectedMinion[i].mx, infectedMinion[i].my, 5, 100);
			
			//enemy life
			infectedMinion[i].enemyLifeText = std::to_string(infectedMinion[i].enemyLife) + "X";
			iSetColor(255, 255, 0);
			iText(infectedMinion[i].enemyPosX + 30, infectedMinion[i].enemyPosY + 15, const_cast<char*>(infectedMinion[i].enemyLifeText.c_str()));
		}

		else{
			//cured enemy
			iShowBMP2(miniPosX - infectedMinion[i].randX, miniPosY - infectedMinion[i].randY, minionFollowing[minionFollowingIndx], 255);
			if (infectedMinion[i].enemyLife == 0){
				gruScore +=10;
				infectedMinion[i].enemyLife = -1;
			}
		}
		
	}
	iShowBMP2(650, 550, "D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\life\\healthb.bmp", 0);
	//gru's bullet
	iSetColor(255, 255, 0);
	//gur's fixed bullet
	iFilledCircle(bulletX + gruPosX, bulletY + gruPosY, 6, 100);
	
	//gru's moving bullet
	if (gruBullet){
		iFilledCircle(bx, by, 6, 100);
	}

	//infected minions bullet
	iSetColor(255, 0, 0);
	for (int i = 0; i < enemyNumber; i++){

	}

}

//game third level
void hardPageFunction()
{

	//will be developed

}



void scorePageFunction()
{

	gameOverFunction();
	iShowBMP(0, 0, "photo\\helpPage.bmp");
	iShowBMP2(7, 500, backButton, 0);
	
	char fName[5][30], fScore[5][5];
	string st;
	char nameWithPoint[5][15], onlyPoint[5][6];
	int i = 0, j = 0;

	//iText(500, 100, name, GLUT_BITMAP_TIMES_ROMAN_24);
	FILE *f;
	f = fopen("Score.txt", "r");
	
	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s %d", highScore[i].SName, &highScore[i].SScore);
	}
	for (int i = 0; i < 5; i++)
	{
		sprintf(fName[i], "%s", highScore[i].SName);
		sprintf(fScore[i], "%d", highScore[i].SScore);
		
	}
	fclose(f);

	

		iSetColor(0, 0, 0);
		iText(325, 500, fName[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(325, 400, fName[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(325, 300, fName[2], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(325, 200, fName[3], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(325, 100, fName[4], GLUT_BITMAP_TIMES_ROMAN_24);

		iText(500, 500, "- ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(500, 400, "- ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(500, 300, "- ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(500, 200, "- ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(500, 100, "- ", GLUT_BITMAP_TIMES_ROMAN_24);

		iText(575, 500, fScore[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(575, 400, fScore[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(575, 300, fScore[2], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(575, 200, fScore[3], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(575, 100, fScore[4], GLUT_BITMAP_TIMES_ROMAN_24);

}

void helpPageFunction()
{
	iShowBMP(0, 0, "D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\nohelp.bmp");
	//iShowBMP2(7, 500, backButton, 0);

	//iShowBMP(0, 0, "photo\\startG.bmp");
	iShowBMP2(7, 500, backButton, 0);




	if (easyB)
	{
		iShowBMP2(95, 245, "photo\\easyB1.bmp", 0);
	}
	else
	{
		iShowBMP2(100, 250, "photo\\easyB.bmp", 0);
	}
	if (mediumB)
	{
		iShowBMP2(370, 245, "photo\\mediumB1.bmp", 0);
	}
	else
	{
		iShowBMP2(375, 250, "photo\\mediumB.bmp", 0);
	}
	if (hardB)
	{
		iShowBMP2(645, 245, "D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\hardB1.bmp", 0);
	}
	else
	{
		iShowBMP2(650, 250, "photo\\hardB.bmp", 0);

	}
}

void aboutPageFunction(){

	iShowBMP(0, 0, "photo\\aboutPage.bmp");
	iShowBMP2(7, 500, backButton, 0);
}

void exitPageFunction()
{
	if (exitPage)
	{
		exit(0);
	}

}




void changeTimer()
{
	if (easyPage)
	{
		totalSecond = (second++) + (60 * minute) + (60 * 60 * hour);
	}
}

void drawTimer()
{
	if (easyPage)
	{
		iSetColor(255, 204, 203);
		iFilledRectangle(50, 522, 120, 30);

		iSetColor(255, 0, 0);
		sprintf_s(sec, "%d", second);
		iText(130, 530,sec, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(55, 530, "Timer :", GLUT_BITMAP_TIMES_ROMAN_24);


		iSetColor(255, 204, 203);
		iFilledRectangle(53, 440, 170, 50);
		iSetColor(255, 0, 0);
		iText(57,460, "Score", GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf_s(point, "%d", score);
		iText(185, 460,point, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(120, 460, "point :", GLUT_BITMAP_TIMES_ROMAN_24);

	}


}

void gameOverFunction()
{

	iSetColor(0, 0, 0);
	iShowBMP(0, 0, "photo\\gameover.bmp");
	iText(450, 320, name, GLUT_BITMAP_HELVETICA_18);

	

}
int tempScore=00;
void afterGameOverFunction()
{
	
	FILE *f;
	f = fopen("Score.txt", "r");

	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s %d", highScore[i].SName, &highScore[i].SScore);
	}

	
	char xp[50];
	int temp;

	if (easyLeverScore)
	{
		tempScore = score*10 +(100- second);
	}
	else
	{
		tempScore = gruScore;
	}
	
	
	if (highScore[4].SScore < tempScore)
	{
		highScore[4].SScore = tempScore;
		strcpy(highScore[4].SName, tempName);
	}
	

	for (int i = 0; i < 5; i++)
	{	
		for (int j = i; j < 5; j++)
		{
			if (highScore[i].SScore <highScore[j].SScore)
			{
				temp = highScore[i].SScore;
				highScore[i].SScore = highScore[j].SScore;
				highScore[j].SScore = temp;

				strcpy(xp, highScore[i].SName);
				strcpy(highScore[i].SName , highScore[j].SName);
				strcpy(highScore[j].SName,xp);

			}
		}
	}


	FILE* f2 = fopen("Score.txt", "w");
	for (int i = 0; i < 5; i++)
	{
		fprintf(f2, "%s %d \n", highScore[i].SName, highScore[i].SScore);

	}
	fclose(f2);

	afterGameOver = false;

}


void mHelpfunction()
{
	iShowBMP(0, 0, "D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\mh.bmp");
	iShowBMP2(30, 250, backButton, 0);
}
void eHelpFunction()
{
	iShowBMP(0, 0, "D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\eHelp.bmp");
	iShowBMP2(7, 500, backButton, 0);
}

void hHelpFunction()
{
	iShowBMP(0, 0, "D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\hHard.bmp");
	iShowBMP2(7, 500, backButton, 0);
}








void iDraw()
{
	iClear();

	if (mediumPage)
	{
		mediumPageFunction();
	}
	
	if (mainPage)
	{
		mainPageFunction();
	}


	if (startPage)
	{
		startPageFunction();

	}

	if (scorePage){
		scorePageFunction();
	}

	if (helpPage)
	{
		helpPageFunction();
	}

	if (aboutPage){
		aboutPageFunction();
	}

	if (exitPage)
	{
		exitPageFunction();
	}



	if (easyPage)
	{
		
		

		easyPageFunction();
	}
	

	

	if (hardPage)
	{
		hardPageFunction();
	}

	if (gameOver)
	{
		gameOverFunction();
	}

	if (afterGameOver)
	{
		afterGameOverFunction();
	}

	if (mHelp)
	{
		mHelpfunction();
	}
	if (eHelp)
	{
		eHelpFunction();
	}
	if (hHelp)
	{
		hHelpFunction();
	}






}






void iMouseMove(int mx, int my)
{
	circleX = mx;
	circleY = my;
}



void iPassiveMouseMove(int mx, int my)
{

	if (mx >= 60 && mx <= 310 && my >= 475 && my <= 557)
	{
		startB = true;
	}
	else
	{
		startB = false;
	}

	if (mx >= 60 && mx <= 310 && my >= 375 && my <= 457)
	{
		scoreB = true;
	}
	else
	{
		scoreB = false;
	}

	if (mx >= 60 && mx <= 310 && my >= 275 && my <= 357)
	{
		helpB = true;
	}
	else
	{
		helpB = false;
	}

	if (mx >= 60 && mx <= 310 && my >= 175 && my <= 257)
	{
		aboutB = true;
	}
	else
	{
		aboutB = false;
	}

	if (mx >= 60 && mx <= 310 && my >= 75 && my <= 157)
	{
		exitB = true;
	}
	else
	{
		exitB = false;
	}

	//start page button

	if (mx >= 105 && mx <= 330 && my >= 255 && my <= 325)
	{
		easyB = true;
	}
	else
	{
		easyB = false;
	}

	if (mx >= 382 && mx <= 610 && my >= 255 && my <= 325)
	{
		mediumB = true;
	}
	else
	{
		mediumB = false;
	}

	if (mx >= 660 && mx <= 890 && my >= 255 && my <= 325)
	{
		hardB = true;
	}
	else
	{
		hardB = false;
	}
	// easy page



	circleX = mx;
	circleY = my;






}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//main page button
		
		if (mx >= 60 && mx <= 310 && my >= 475 && my <= 557 && mainPage)
		{
			startPage = true;
			mainPage = false;
		}

		else if (mx >= 60 && mx <= 310 && my >= 375 && my <= 457 && mainPage)
		{
			scorePage = true;
			mainPage = false;
		}

		else if (mx >= 60 && mx <= 310 && my >= 275 && my <= 357 && mainPage)
		{
			helpPage = true;
			mainPage = false;
			
		}

		else if (mx >= 60 && mx <= 310 && my >= 175 && my <= 257 && mainPage)
		{
			aboutPage = true;
			mainPage = false;
		}

		else if (mx >= 60 && mx <= 310 && my >= 75 && my <= 157 && mainPage)
		{
			exitPage = true;
			mainPage = false;
		}


		
		//back button
		else if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && startPage){
			mainPage = true;
			startPage = false;
		}

		else if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && aboutPage){
			mainPage = true;
			aboutPage = false;
		}
		else if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && scorePage){
			mainPage = true;
			scorePage = false;
		}
		else if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && helpPage){
			mainPage = true;
			helpPage = false;
		}
		else if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && mediumPage){
			gameOver = true;
			easyLeverScore = false;
			mediumPage = false;
		}
		else if (mx >= 45 && mx <= 125 && my >= 350 && my <= 420 && easyPage){
			gameOver = true;
			easyLeverScore = true;
			easyPage = false;
		}

		else if (mx >= 30 && mx <= 110 && my >= 250 && my <= 320 && mHelp){
			helpPage = true;
			mHelp = false;
		}
		else if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && eHelp){
			helpPage = true;
			eHelp = false;
		}
		else if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && hHelp){
			helpPage = true;
			hHelp = false;
		}

		//start page (game level)
		else if (mx >= 105 && mx <= 330 && my >= 255 && my <= 325 && startPage)
		{

			easyPage = true;
			startPage = false;
		}

		else if (mx >= 382 && mx <= 610 && my >= 255 && my <= 325 && startPage)
		{
			mediumPage = true;
			startPage = false;
		}

		else if (mx >= 660 && mx <= 890 && my >= 255 && my <= 325 && startPage)
		{
			hardPage = false;
			
		}

		//help page

		else if (mx >= 105 && mx <= 330 && my >= 255 && my <= 325 && helpPage)
		{
			eHelp = true;
			helpPage = false;
			
		}

		else if (mx >= 382 && mx <= 610 && my >= 255 && my <= 325 && helpPage)
		{
			mHelp = true;
			helpPage = false;
		}

		else if (mx >= 660 && mx <= 890 && my >= 255 && my <= 325 && helpPage)
		{
			hHelp = true;
			helpPage = false;

		}

		//level 1
		
		else if (!birdInFlight)
		{
			if (mx > 242) {
				birdVelX = (mx - gunPosX) * 0.1;
				birdVelY = (my - gunPosY) * 0.1;
				birdInFlight = true;
				musicOn = true;
			}
			 if (mx == gunPosX && (my < gunPosY || my > gunPosY)) {
				birdInFlight = false;
			}
			 if (mx >= 242)
			 {
				 mini = false;
				 bird = true;
				 
				 vanishgun = true;
			 }
			
		}
		
	}

}



void iKeyboard(unsigned char key)
{
	

	if (gameOver)
	{	
		if (key == 13)
			{
			char noNameTemp[7] = "NoName";

			if (nameindex>0)
			{
				for (i = 0; i < nameindex; i++)
					{
						tempName[i] = name[i];
					}
					tempName[i]='\0';
			}
			
			else
			{
				for (i = 0; i <6 ; i++)
				{
					tempName[i] = noNameTemp[i];
				}
				tempName[i] = '\0';
			}
				

				
				gameOver = false;
				afterGameOver = true;
				hardPage = false;
				mainPage = true;
				
				
				
				
			}

		else if (key != '\b')
			{
			
				if (nameindex < 25)
				{
					name[nameindex] = key;
					name[nameindex + 1] = 
				nameindex++;
				}


			}

			else
			{

				name[nameindex] = '\0';
				nameindex--;
			if (nameindex < 0)
				{
					nameindex = 0;
				}


			}
	}
	//medium page control
	if (mediumPage){
		if (key == 'w')
		{
			changeForGru();
			if (gruPosY < 190){
				gruPosY += 8;
				miniPosY += 8;
			}
		}
		else if (key == 's')
		{
			changeForGru();
			if (gruPosY > 0){
				gruPosY -= 8;
				miniPosY -= 8;
			}
		}
		else if (key == 'a')
		{
			changeForGru();
			if (gruPosX > 10){
				gruPosX -= 10;
				miniPosX -= 10;
			}
		}
		else if (key == 'd')
		{
			changeForGru();
			if (gruPosX < 760){
				gruPosX += 10;
				miniPosX += 10;
			}
		}
		else if (key == 'f')
		{
			bx = bulletX + gruPosX;
			by = bulletY + gruPosY;
			gruBullet = true;
			iSetColor(255, 255, 0);
			for (int i = 0; i < enemyNumber; i++){
				if (infectedMinion[i].enemyLife == 0){

				}
			}
			
			iSetTimer(100, bulletMove);
		}
	}

	


}


void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{

	}
	if (key == GLUT_KEY_LEFT)
	{

	}

	if (key == GLUT_KEY_HOME)
	{

	}

}





void iUpdate() {
	if (birdInFlight) {

		if (musicOn && easyPage)
		{
			PlaySound("photo\\gM.wav", NULL, SND_ASYNC);
			musicOn = false;

		}
		gunPosX += birdVelX * timeStep;
		gunPosY += birdVelY * timeStep;
		birdVelY -= gravity * timeStep;

		vanish = -vanish;
		vanish1 = -vanish1;
		vanish2 = -vanish2;
		vanish3 = -vanish3;
		vanish4 = -vanish4;





		if ((gunPosX >= 242 && gunPosX <= 851) && gunPosY >= 550) {
			birdVelY = -abs(birdVelY);
			flag = true;

		}

		if (gunPosY <= 0 || gunPosX >= 1000 || gunPosY >= 600 || gunPosX <= 0) {
			mini = true;
			bird = false;
			birdInFlight = false;
			vanishgun = false;
			gunPosX = 160;
			gunPosY = 160;
		}
		

		
		
		if (checkCollision(gunPosX, gunPosY, targetPosX, targetPosY, targetRadius) && flag) {
		birdInFlight = false;
		mini = true;
		bird = false;

		vanish = 0;
		vanishgun = false;
		gunPosX = 160;
		gunPosY = 160;
		targetPosX = 0;
		targetPosY = 0;
		flag = false;
		dM = true;
		coinshow = true;
		score = score + 5;


		}
		if (checkCollision(gunPosX, gunPosY, targetPosX1, targetPosY1, targetRadius) && flag) {
		birdInFlight = false;
		mini = true;
		bird = false;
		vanish1 = 0;
		vanishgun = false;
		gunPosX = 160;
		gunPosY = 160;
		targetPosX1 = 0;
		targetPosY1 = 0;
		flag = false;
		dM = true;
		coinshow = true;
		score = score + 5;

		}
		if (checkCollision(gunPosX, gunPosY, targetPosX2, targetPosY2, targetRadius) && flag) {
		birdInFlight = false;
		mini = true;
		bird = false;
		vanish2 = 0;
		vanishgun = false;
		gunPosX = 160;
		gunPosY = 160;
		targetPosX2 = 0;
		targetPosY2 = 0;
		flag = false;
		dM = true;
		coinshow = true;
		score = score + 5;


		}
		if (checkCollision(gunPosX, gunPosY, targetPosX3, targetPosY3, targetRadius) && flag) {
		birdInFlight = false;
		mini = true;
		bird = false;
		vanish3 = 0;
		vanishgun = false;
		gunPosX = 160;
		gunPosY = 160;
		targetPosX3 = 0;
		targetPosY3 = 0;
		flag = false;
		dM = true;
		coinshow = true;
		score = score + 5;


		}
		if (checkCollision(gunPosX, gunPosY, targetPosX4, targetPosY4, targetRadius) && flag) {
		birdInFlight = false;
		mini = true;
		bird = false;
		vanish4 = 0;
		vanishgun = false;
		gunPosX = 160;
		gunPosY = 160;
		targetPosX4 = 0;
		targetPosY4 = 0;
		flag = false;
		dM = true;
		coinshow = true;
		score = score + 5;;








		}
		if (vanish == false && vanish1 == false && vanish2 == false && vanish3 == false && vanish4 == false ){
		easyPage = false;
		gameOver = true;
		easyLeverScore = true;
		}
		
	}
}







int main()
{
	

	
	iSetTimer(10, iUpdate); 
	iSetTimer(1000, changeTimer);
	iInitialize(1000, 600, "Project Title");
	birdImage = iLoadImage("photo\\minion.png");
	targetImage = iLoadImage("photo\\finalenemy.png");
	targetImage1 = iLoadImage("photo\\blue1.png");
	targetImage2 = iLoadImage("photo\\blue2.png");
	targetImage3 = iLoadImage("photo\\blue3.png");

	gun = iLoadImage("photo\\fire_copy.png");
	miniimage = iLoadImage("photo\\new_mini.png");
	coinImage = iLoadImage("photo\\coin.png");
	
		//set enemies
		setEnemies();
		//changes enemies attributes
		iSetTimer(200, changeForEnemy);
		//reduce the life of enemies
		iSetTimer(100, curedCheack);
		//reduce the life of gru
		iSetTimer(350, gruAttacked);
		//iInitialize(screenWidth, screenHeight, "Project Title");
		bc = iLoadImage("D:\\game\\TheMinions008\\TheMinions008\\TheMinions008\\TheMinions008\\photo\\bc\\bc.png");
	
	




	iStart();


	return 0;
}
