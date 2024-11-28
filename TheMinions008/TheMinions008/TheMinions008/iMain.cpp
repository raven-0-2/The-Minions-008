#include <iostream>
#include<string>

using namespace std;

#include "iGraphics.h"


//farabe
#define screenWidth =1000;
#define screenHeight = 600;

bool mainPage = true, startB = false, scoreB = false, helpB = false, aboutB = false, exitB = false, easyPage = false, hardPage = false, mediumPage = false, easyB = false, mediumB = false, hardB = false;
bool startPage = false, scorePage = false, helpPage = false, aboutPage = false, exitPage = false;

int i = 0, hy = 85, score = 0;

bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;




char bg[1][100] = { "photo\\bg.bmp" };
char button[5][100] = { "photo\\buttonB1.bmp", "photo\\buttonB2.bmp", "photo\\buttonB3.bmp", "photo\\buttonB4.bmp", "photo\\buttonB5.bmp" };
char buttonHover[5][100] = { "photo\\buttonP1.bmp", "photo\\buttonP2.bmp", "photo\\buttonP3.bmp", "photo\\buttonP4.bmp", "photo\\buttonP5.bmp" };
char backButton[100] = { "photo\\backb.bmp" };
char name[26] = "YOUR NAME";
int nameindex = 0;


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

//bool vanish = true;
int vanish = 1;
//bool vanish1 = true;
int vanish1 = 1;
//bool vanish2 = true;
int vanish2 = 1;
//bool vanish3 = true;
int vanish3 = 1;
//bool vanish4 = true;
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
double targetPosX = /*870*/765, targetPosY = 130/*200*/, targetPosX1 = 656/*870*/, targetPosY1 = /*450*/79,targetPosX2 =834 /*770*/,targetPosY2 = 204/*280*/,targetPosX3 = /*890*/817,targetPosY3=315/*300*/,targetPosX4 = 810/*770*/,targetPosY4 = 430;

//double targetPosX = 700, targetPosY = 300, targetPosX1 = 700, targetPosY1 = 500;

const int targetRadius = 20;
//int targetImage;
int miniimage;
int background;
//double dx;

//double dx = 10;
//double dy = 10;
//void checkCollision(birdPosX, birdPosY, targetPosX, targetPosY, targetRadius);


//bool checkCollision(double x1, double y1, double x2, double y2, double radius);

void drawTimer();
bool checkCollision(double gunX, double gunY, double targetX, double targetY, double targetRadius) {
	double distance = abs(sqrt(pow(gunX - targetX, 2) + pow(gunY - targetY, 2)));
	
	return distance < targetRadius;
}


/*
bool checkCollision(double x1, double y1, double x2, double y2, double radius) {
	double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return distance < radius;
}
*/


//redowan
void mainPageFunction()
{
	iShowBMP(0, 0, bg[0]);
	//iShowBMP(300, 300, "syr1.bmp");



	/*iShowBMP2(60, hy, button[0], 0);
	iShowBMP2(60, hy + 100, button[1], 0);
	iShowBMP2(60, hy + 100, button[2], 0);
	iShowBMP2(60, hy + 100, button[3], 0);
	//iShowBMP2(60, hy + 100, button[1], 0);
	*/

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

//rupom
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
		iShowBMP2(645, 245, "photo\\hardB1.bmp", 0);
	}
	else
	{
		iShowBMP2(650, 250, "photo\\hardB.bmp", 0);
		
	}




}

//game first level

void easyPageFunction()
{



	iShowBMP(0, 0, "photo\\gameBackground1.bmp");
	//iLoadImage("photo\\b-1.png");

	//iShowBMP2(100, 75, "photo\\mini.bmp" ,255);
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
		PlaySound("F:\\TheMinions008\\TheMinions008\\photo\\dM.wav", NULL, SND_ASYNC);
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
		//iShowImage(c1x, c1y,50,50, coinImage);
		iShowBMP2(c1x, c1y, "photo\\finalcc.bmp",0);

		c1y = c1y - 10;
		
		//c1y = c1y + 10;
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
	//coinImage = iLoadImage("photo\\coin.png");
	//iFilledRectangle(300, 570, 200, 20);
	//iShowImage(gunPosX, gunPosY, 30, 30, gun);
	



}


//game second level
void mediumPageFunction()
{

}

//game third level
void hardPageFunction()
{

}



void scorePageFunction()
{
	iShowBMP(0, 0, "photo\\helpPage.bmp");
	iShowBMP2(7, 500, backButton, 0);
	iText(500, 100, name, GLUT_BITMAP_TIMES_ROMAN_24);
}

void helpPageFunction()
{
	iShowBMP(0, 0, "photo\\helpPage.bmp");
	iShowBMP2(7, 500, backButton, 0);
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
void easypage()
{

	/*
	iSetTimer(5, iUpdate); // Update game state every 5 ms

	iShowBMP2(0, 0, "photo\\helpPage.bmp", 0);
	iShowImage(birdPosX - 10, birdPosY - 10, 20, 20, birdImage);
	if (vanish) {
	iShowImage(targetPosX - targetRadius, targetPosY - targetRadius, targetRadius * 4, targetRadius * 4, targetImage);
	}
	if (vanish1) {
	iShowImage(targetPosX1 - targetRadius, targetPosY1 - targetRadius, targetRadius * 4, targetRadius * 4, targetImage);
	}
	iSetColor(255, 0, 0);
	iCircle(circleX, circleY, 10, 100);
	iCircle(circleX, circleY, 5, 100);
	iFilledRectangle(300, 570, 200, 20);
	iShowImage(gunPosX - 80, gunPosY - 70, 80, 80, gun);
	*/


	/*void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !birdInFlight) {
	if (mx > birdPosX) {
	birdVelX = (mx - birdPosX) * 0.1;
	birdVelY = (my - birdPosY) * 0.1;
	birdInFlight = true;
	}
	else if (mx == birdPosX && (my < birdPosY || my > birdPosY)) {
	birdInFlight = false;
	}
	}
	}
	*/


}

char sec[10000];
int minute = 0;
int hour = 0;
char hr[10000];
int totalSecond = 0;
char point[10000];

void changeTimer()
{
	if (easyPage)
	{
		totalSecond = (second++) + (60 * minute) + (60 * 60 * hour);
		//score = score  + second;
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







void iDraw()
{
	iClear();

	//farabe
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
		/*
		if (checkCollision( gunPosX, gunPosY, targetPosX, targetPosY,targetRadius))
		{
			vanish = false;
			vanish1 = false;
			vanish2 = false;
			vanish3 = false;
			vanish4 = false;
		}
		
		*/
		

		easyPageFunction();
	}
	

	if (mediumPage)
	{
		mediumPageFunction();
	}

	if (hardPage)
	{
		hardPageFunction();
	}






}






void iMouseMove(int mx, int my)
{
	circleX = mx;
	circleY = my;
}



void iPassiveMouseMove(int mx, int my)
{
	//redowan
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
		//farabe
		//main page button
		cout << "x= " << mx << " y=" << my;
		if (mx >= 60 && mx <= 310 && my >= 475 && my <= 557 && mainPage)
		{
			startPage = true;
			mainPage = false;
		}

		if (mx >= 60 && mx <= 310 && my >= 375 && my <= 457 && mainPage)
		{
			scorePage = true;
			mainPage = false;
		}

		if (mx >= 60 && mx <= 310 && my >= 275 && my <= 357 && mainPage)
		{
			helpPage = true;
			mainPage = false;
		}

		if (mx >= 60 && mx <= 310 && my >= 175 && my <= 257 && mainPage)
		{
			aboutPage = true;
			mainPage = false;
		}

		if (mx >= 60 && mx <= 310 && my >= 75 && my <= 157 && mainPage)
		{
			exitPage = true;
			mainPage = false;
		}


		//rupom
		//back button
		if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && startPage){
			mainPage = true;
			startPage = false;
		}

		if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && aboutPage){
			mainPage = true;
			aboutPage = false;
		}
		if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && scorePage){
			mainPage = true;
			scorePage = false;
		}
		if (mx >= 20 && mx <= 80 && my >= 515 && my <= 575 && helpPage){
			mainPage = true;
			helpPage = false;
		}

		//start page (game level)
		if (mx >= 105 && mx <= 330 && my >= 255 && my <= 325 && startPage)
		{
			easyPage = true;
			startPage = false;
		}

		if (mx >= 382 && mx <= 610 && my >= 255 && my <= 325 && startPage)
		{
			mediumPage = true;
			startPage = false;
		}

		if (mx >= 660 && mx <= 890 && my >= 255 && my <= 325 && startPage)
		{
			hardPage = true;
			startPage = false;
		}
		
		if (!birdInFlight)
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

/*

if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && ! birdInFlight)
{


if (mx > gunPosX) {
birdVelX = (mx - gunPosX) * 0.1;
birdVelY = (my - gunPosY) * 0.1;
birdInFlight = true;
}
else if (mx == gunPosX && (my < gunPosY || my > gunPosY)) {
birdInFlight = false;
}


}
}
*/



void iKeyboard(unsigned char key)
{
	if (key == 13)
	{

	}

	else if (key != '\b')
	{
		if (nameindex < 25)
		{
			name[nameindex] = key;
			name[nameindex + 1] = '\0';
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

/*void iUpdate() {
if (birdInFlight) {
birdPosX += birdVelX * timeStep;
birdPosY += birdVelY * timeStep;
birdVelY -= gravity * timeStep;

if ((birdPosX >= 300 && birdPosX <= 500) && birdPosY >= 570) {
birdVelY = -abs(birdVelY);
}

if (birdPosY <= 0  birdPosX >= 800  birdPosY >= 600 || birdPosX <= 0) {
birdInFlight = false;
birdPosX = 100;
birdPosY = 300;
}

if (checkCollision(birdPosX, birdPosY, targetPosX, targetPosY, targetRadius)) {
birdInFlight = false;
vanish = false;
birdPosX = 100;
birdPosY = 300;
}
if (checkCollision(birdPosX, birdPosY, targetPosX1, targetPosY1, targetRadius)) {
birdInFlight = false;
vanish1 = false;
birdPosX = 100;
birdPosY = 300;
}
}
}*/

/*
bool checkCollision(double x1, double y1, double x2, double y2, double radius) {
	double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return distance < radius;
}
*/

void iUpdate() {
	if (birdInFlight) {

		if (musicOn && easyPage)
		{
			PlaySound("F:\\TheMinions008\\TheMinions008\\photo\\gM.wav", NULL, SND_ASYNC);
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
		/*
		if (gunPosX >= 740 && gunPosY >= 177 && gunPosY <= 524)
		{
		//birdInFlight = false;
		birdVelX = -abs(birdVelX);
		birdVelY = -abs(birdVelY);
		//gunPosX = 160;
		//gunPosY = 160;
		}
		*/
		/*
		if (gunPosY <= 30 )
		{
		birdVelY = abs(birdVelY);

		}
		*/

		/*
		if (gunPosX >= 970)
		{
		birdVelX = - abs(birdVelX);
		birdVelY = abs(birdVelY);
		}

		*/

		/*
		if ((gunPosX >= 821 && gunPosX <= 865) && (gunPosY >= 435 && gunPosY <= 493))
		{
		birdInFlight = false;
		vanish1 = false;
		}
		if ((gunPosX >= 817 && gunPosX <= 869 )&& (gunPosY >= 184 && gunPosY <= 242))
		{
		birdInFlight = false;
		vanish = false;
		gunPosX = 160;
		gunPosY = 160;
		}
		*/
		
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
		//coinScore = coinScore + 5;
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
		//coinScore = coinScore + 5;
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
		//coinScore = coinScore + 5;
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
		//coinScore = coinScore + 5;
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
		//coinScore = coinScore + 5;
		score = score + 5;;








		}
		if (vanish == false && vanish1 == false && vanish2 == false && vanish3 == false && vanish4 == false){
		easyPage = false;
		mainPage = true;
		}
		
	}
}

/*
	void changebird()
	{
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
			//coinScore = coinScore + 5;
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
			//coinScore = coinScore + 5;
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
			//coinScore = coinScore + 5;
			score = score + 5;;








		}
		if (vanish == false && vanish1 == false && vanish2 == false && vanish3 == false && vanish4 == false){
			easyPage = false;
			mainPage = true;
		}
	}
	
*/



	
/*
void iUpdate()
{
	if (birdInFlight) {
		gunPosX += dx;
		gunPosY += dy;
		if (gunPosX >= 990 || gunPosX <= 0)
		{
			dx *= (-1);
		}
		if (gunPosY >= 590 || gunPosY <= 0)
		{
			dy *= (-1);
		}

	}
}
*/


int main()
{
	

	//birdPosX = 100;
	//birdPosY = 300;
	//gunPosX = 160;
	//gunPosY = 175;
	iSetTimer(10, iUpdate); 
	iSetTimer(1000, changeTimer);
	//iSetTimer(10, changebird);// Update game state every 5 ms
	//iSetTimer(5, iUpdate); // Update game state every 5 ms
	iInitialize(1000, 600, "Project Title");
	birdImage = iLoadImage("F:\\TheMinions008\\TheMinions008\\photo\\minion.png");
	//background = iLoadImage("photo\\background.png");
	//birdImage = iLoadImage("photo\\minion.png");
	targetImage = iLoadImage("photo\\finalenemy.png");
	targetImage1 = iLoadImage("photo\\blue1.png");
	targetImage2 = iLoadImage("photo\\blue2.png");
	targetImage3 = iLoadImage("photo\\blue3.png");

	gun = iLoadImage("F:\\TheMinions008\\TheMinions008\\photo\\fire_copy.png");
	miniimage = iLoadImage("F:\\TheMinions008\\TheMinions008\\photo\\new_mini copy.png");
	coinImage = iLoadImage("photo\\coin.png");




	iStart();


	return 0;
}
