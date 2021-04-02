#include "iGraphics.h"
#include "bitmap_loader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define screenwidth 1300
#define screenheight 1500
ofstream writeFile;
ifstream readFile;
bool musicOn = true;
struct Buttons
{
	int x;
	int y;
}bCoordinate[5];

char buttons[30][30] = { "p.bmp", "h.bmp", "i2.bmp", "c.bmp", "q.bmp" };
int bg,story,b,c,d,e;
int gamestate = -1;
int game = 0;
int loop = 0, numofHS, temp;
double flag = 0;
int image, img[22][100];

int bkindex = 0;

char bun[8][100];
char bunIndex = 0;
char coinChange[4][20] = { "Coin_000.bmp", "Coin_001.bmp", "Coin_002.bmp", "Coin_003.bmp" };
char s1[3][20] = { "Coin_s.bmp", "carrot_1.bmp", "blust.bmp" };
char coinIndex = 0, carrotIndex = 0;
char carrotChange[4][20] = { "car_1.bmp", "car_2.bmp", "car_3.bmp", "car_4.bmp" };
char points[10][300] = { "0.bmp", "1.bmp", "2.bmp", "3.bmp", "4.bmp", "5.bmp", "6.bmp", "7.bmp", "8.bmp", "9.bmp" };
char spoints[10][300] = { "s0.bmp", "s1.bmp", "s2.bmp", "s3.bmp", "s4.bmp", "s5.bmp", "s6.bmp", "s7.bmp", "s8.bmp", "s9.bmp" };

bool f_coin1 = true, f_coin2 = true, f_coin3 = true;
bool f_carrot1 = true, f_carrot2 = true, f_carrot3 = true;
bool f_bomb1 = true, f_bomb2 = true, f_bomb3 = true, f_sbomb = true, f_s1bomb = true;

bool f_c1 = true, f_c2 = true, f_c3 = true;
bool f_car1 = true, f_car2 = true, f_car3 = true;
bool f_b1 = true, f_b2 = true, f_b3 = true, f_sb = true, f_s1b = true,play=false,rest=true;
bool f_heart = true, f_h = true,point = false;
bool gameover1 = false, sScore = false, control = true;
int life, mLife;
int gameoverr, scoreboard;
int s = 0, score1 = 0, sumScore = 0, score = 0, lifeCounter = 3, digit1, digit2, digit3,hs1=0,hs2=0,hs3=0;
int by = 10, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10;
string scoreStr, scoreStr1, scoreStr2;
char* score_char1, *score_char2, *score_char;

struct rabbit{
	int x, y;
	rabbit(int get, int get1){
		x = get;
		y = get1;
	}

};
struct coin{
	int x, y;
	coin(int get, int get1){
		x = get;
		y = get1;
	}

};

struct carrot{
	int x, y;
	carrot(int get, int get1){
		x = get;
		y = get1;
	}

};
struct bomb
{
	int   x;
	int y;

	bomb(int get, int get1)
	{
		x = get;
		y = get1;
	}
};
struct heart{
	int x, y;
	heart(int get, int get1){
		x = get;
		y = get1;
	}

};





struct coin coin1(400, screenheight);
struct coin coin2(800, screenheight);
struct coin coin3(600, screenheight);

struct rabbit bunny(927, 100);
struct heart dil(0, screenheight);
struct carrot carrot1(500, screenheight);
struct carrot carrot2(700, screenheight);
struct carrot carrot3(900, screenheight);

struct bomb bomb1(0, screenheight);
struct bomb bomb2(0, screenheight);
struct bomb bomb3(0, screenheight);
struct bomb sbomb(0, screenheight);
struct bomb s1bomb(0, screenheight);


void collision();

void coinChange1();
void coinChange2();
void coinChange3();


void carrotChange1();
void carrotChange2();
void carrotChange3();

void callCarrot();
void callCoin();

void showLife();
void showScore();
void difficulty();
void aid();
void gameover();
void scoreBoard();
void scoreBoard1();
void showBlust();
void customScore(int num);
void customScore1(int num);
void customScore2(int num);
void restart();
void customScore3(int num);
void customScore4(int num);
void customScore5(int num);
void highScore();



void iDraw()
{
	iClear();
	if (gamestate == -1){
		iShowImage(0, 0, screenwidth, screenheight, bg);
		for (int i = 0; i < 5; i++){
			iShowBMP2(bCoordinate[i].x, bCoordinate[i].y, buttons[i], 255);
		}
	}
	
	else if (gamestate == 1){
		
		scoreBoard1();
	
	}
	else if (gamestate == 2){
		iShowImage(0, 0, screenwidth, screenheight, c);
	
	

	}
	else if (gamestate == 3){
		iShowImage(0, 0, screenwidth, screenheight, d);
	}
	else if (gamestate == 0){
		iClear();
		if (rest){
			iResumeTimer(x1);
			iResumeTimer(x2);
			iResumeTimer(x3);
			iResumeTimer(x4);
			iResumeTimer(x5);
			iResumeTimer(x6);
			iResumeTimer(x7);
			iResumeTimer(x8);
			iResumeTimer(x9);
			iResumeTimer(x10);
		}
		


		iShowImage(0, 0, screenwidth, screenheight, story);

		if (gamestate == 0 && play == true){
		
			iShowImage(0, 0, 1308, 1500, img[bkindex][100]);

			collision();

			iShowImage(bunny.x, bunny.y, 150, 150, bun[bunIndex][100]);


			if (f_bomb1)iShowBMP2(bomb1.x, bomb1.y, "bomb.bmp", 255);
			if (f_bomb2)iShowBMP2(bomb2.x, bomb2.y, "bomb.bmp", 255);
			if (f_bomb3)iShowBMP2(bomb3.x, bomb3.y, "bomb.bmp", 255);
			if (f_sbomb)iShowBMP2(sbomb.x, sbomb.y, "bomb.bmp", 255);
			if (f_sbomb)iShowBMP2(s1bomb.x, s1bomb.y, "bomb.bmp", 255);

			callCarrot();
			callCoin();
			showScore();

			if (control){
				if (flag == 0){
					if (bunny.x + 100 < 1245)
					{

						bunny.x += 5;

					}
				}
				else if (flag == 1)
				{
					if (bunny.x + 100 > 110)
					{
						bunny.x -= 5;

					}
				}
			}
			showLife();

			if (f_heart)
			{
				iShowImage(dil.x, dil.y, 80, 80, mLife);
			}
			gameover();
			if (sScore == true && gameover1 == true)

			{
				scoreBoard();
				

			}
			
		}

	}
	
		
	
	
	
	
	

}

void callCoin(){
	if (f_coin1)iShowBMP2(coin1.x, coin1.y, coinChange[coinIndex], 255);
	if (f_coin2)iShowBMP2(coin2.x, coin2.y, coinChange[coinIndex], 255);
	if (f_coin3)iShowBMP2(coin3.x, coin3.y, coinChange[coinIndex], 255);



}

void callCarrot(){

	if (f_carrot1)iShowBMP2(carrot1.x, carrot1.y, carrotChange[carrotIndex], 255);
	if (f_carrot2)iShowBMP2(carrot2.x, carrot2.y, carrotChange[carrotIndex], 255);
	if (f_carrot3)iShowBMP2(carrot3.x, carrot3.y, carrotChange[carrotIndex], 255);

}

void showBlust(){


	iShowBMP2(bunny.x, bunny.y, s1[2], 255);
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= bCoordinate[0].x && mx <= bCoordinate[0].x + 200 && my >= bCoordinate[0].y + 180 && my <= bCoordinate[0].y + 220)
		{
			gamestate = 0;
			point = true;
			restart();
		
		}
		else if (mx >= bCoordinate[1].x && mx <= bCoordinate[1].x + 200 && my >= bCoordinate[1].y + 205 && my <= bCoordinate[1].y + 235){
			gamestate = 1;
			highScore();
			
		}
		else if (mx >= bCoordinate[2].x && mx <= bCoordinate[2].x + 200 && my >= bCoordinate[2].y + 230 && my <= bCoordinate[2].y + 250)
			gamestate = 2;
		else if (mx >= bCoordinate[3].x && mx <= bCoordinate[3].x + 200 && my >= bCoordinate[3].y + 245 && my <= bCoordinate[3].y + 265)
			gamestate = 3;
		else if (mx >= bCoordinate[4].x && mx <= bCoordinate[4].x + 200 && my >= bCoordinate[4].y + 270 && my <= bCoordinate[4].y + 295)
			gamestate = 4;
		if (gamestate == 4)
		{
			exit(0);
		}
		if (musicOn)
		{
			musicOn = false;
			PlaySound("menu.wav", NULL, SND_ASYNC);
			if (gamestate == 0 && musicOn==false)
				PlaySound("bg.wav", NULL, SND_LOOP | SND_ASYNC);

		}
	
		
		
		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		gamestate = -1;		
		sScore = false;		
		if (gamestate == -1){
			
			iShowImage(0, 0, screenwidth, screenheight, bg);			
		}
		musicOn = true;
		if (musicOn)
		{
			PlaySound("startbg.wav", NULL, SND_LOOP | SND_ASYNC);
		}
		
		iPauseTimer(x1);
		iPauseTimer(x2);
		iPauseTimer(x3);
		iPauseTimer(x4);
		iPauseTimer(x5);
		iPauseTimer(x6);
		iPauseTimer(x7);
		iPauseTimer(x8);
		iPauseTimer(x9);
		iPauseTimer(x10);

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == ' ')
	{

		if (flag == 0)
			flag = 1;
		else if (flag == 1)
			flag = 0;
	}
	if (key == 'p'){
		iPauseTimer(x1);
		iPauseTimer(x2);
		iPauseTimer(x3);
		iPauseTimer(x4);
		iPauseTimer(x5);
		iPauseTimer(x6);
		iPauseTimer(x7);
		iPauseTimer(x8);
		iPauseTimer(x9);
		iPauseTimer(x10);
		control = false;
		rest = false;
	}
	if (key == 'r'){
		
		rest = true;
		control = true;
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

	
	if (key == GLUT_KEY_INSERT)
	{

	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (game == 0)
		{
			game == 1;
		}
		if (game == 1)
		{
			game == 2;
		}
		if (game == 2)
		{
			game = 3;
		}
		if (game == 3)
		{
			gamestate = 0;
		}

		if (gameover1==true)
		sScore = true;

		if (gamestate == 0)
		{
			play = true;
			
		}


	}

	if (key == GLUT_KEY_HOME)
	{

	}
	
}

void collision(){

	if (((bunny.x + 100 >= coin1.x && bunny.x + 100 <= coin1.x + 90) && (bunny.y + 100 >= coin1.y && bunny.y <= coin1.y)) || ((bunny.x <= coin1.x + 90 && bunny.x + 100 >= coin1.x + 90) && (bunny.y + 100 > coin1.y && bunny.y <= coin1.y))){
		f_coin1 = false;
	}
	if (((bunny.x + 100 >= coin2.x && bunny.x + 100 <= coin2.x + 90) && (bunny.y + 100 >= coin2.y && bunny.y <= coin2.y)) || ((bunny.x <= coin2.x + 90 && bunny.x + 100 >= coin2.x + 90) && (bunny.y + 100 > coin2.y && bunny.y <= coin2.y))){
		f_coin2 = false;
	}
	if (((bunny.x + 100 >= coin3.x && bunny.x + 100 <= coin3.x + 90) && (bunny.y + 100 >= coin3.y && bunny.y <= coin3.y)) || ((bunny.x <= coin3.x + 90 && bunny.x + 100 >= coin3.x + 90) && (bunny.y + 100 > coin3.y && bunny.y <= coin3.y))){
		f_coin3 = false;
	}




	if (((bunny.x + 100 >= carrot1.x && bunny.x + 100 <= carrot1.x + 90) && (bunny.y + 100 >= carrot1.y && bunny.y <= carrot1.y)) || ((bunny.x <= carrot1.x + 90 && bunny.x + 100 >= carrot1.x + 90) && (bunny.y + 100 > carrot1.y && bunny.y <= carrot1.y)))
	{
		f_carrot1 = false;
	}
	if (((bunny.x + 100 >= carrot2.x && bunny.x + 100 <= carrot2.x + 90) && (bunny.y + 100 >= carrot2.y && bunny.y <= carrot2.y)) || ((bunny.x <= carrot2.x + 90 && bunny.x + 100 >= carrot2.x + 90) && (bunny.y + 100 > carrot2.y && bunny.y <= carrot2.y)))
	{
		f_carrot2 = false;
	}
	if (((bunny.x + 100 >= carrot3.x && bunny.x + 100 <= carrot3.x + 90) && (bunny.y + 100 >= carrot3.y && bunny.y <= carrot3.y)) || ((bunny.x <= carrot3.x + 90 && bunny.x + 100 >= carrot3.x + 90) && (bunny.y + 100 > carrot3.y && bunny.y <= carrot3.y)))
	{
		f_carrot3 = false;
	}


	if (((bunny.x + 100 >= bomb1.x && bunny.x + 100 <= bomb1.x + 90) && (bunny.y + 100 >= bomb1.y && bunny.y <= bomb1.y)) || ((bunny.x <= bomb1.x + 90 && bunny.x + 100 >= bomb1.x + 90) && (bunny.y + 100 > bomb1.y && bunny.y <= bomb1.y))){
		showBlust();
		f_bomb1 = false;
	}
	if (((bunny.x + 100 >= bomb2.x && bunny.x + 100 <= bomb2.x + 90) && (bunny.y + 100 >= bomb2.y && bunny.y <= bomb2.y)) || ((bunny.x <= bomb2.x + 90 && bunny.x + 100 >= bomb2.x + 90) && (bunny.y + 100 > bomb2.y && bunny.y <= bomb2.y))){
		showBlust();
		f_bomb2 = false;

	}
	if (((bunny.x + 100 >= bomb3.x && bunny.x + 100 <= bomb3.x + 90) && (bunny.y + 100 >= bomb3.y && bunny.y <= bomb3.y)) || ((bunny.x <= bomb3.x + 90 && bunny.x + 100 >= bomb3.x + 90) && (bunny.y + 100 > bomb3.y && bunny.y <= bomb3.y))){
		showBlust();
		f_bomb3 = false;

	}
	if (((bunny.x + 100 >= sbomb.x && bunny.x + 100 <= sbomb.x + 90) && (bunny.y + 100 >= sbomb.y && bunny.y <= sbomb.y)) || ((bunny.x <= sbomb.x + 90 && bunny.x + 100 >= sbomb.x + 90) && (bunny.y + 100 > sbomb.y && bunny.y <= sbomb.y))){
		showBlust();
		f_sbomb = false;

	}
	if (((bunny.x + 100 >= s1bomb.x && bunny.x + 100 <= s1bomb.x + 90) && (bunny.y + 100 >= s1bomb.y && bunny.y <= s1bomb.y)) || ((bunny.x <= s1bomb.x + 90 && bunny.x + 100 >= s1bomb.x + 90) && (bunny.y + 100 > s1bomb.y && bunny.y <= s1bomb.y))){
		showBlust();
		f_sbomb = false;

	}


	if (((bunny.x + 100 >= dil.x && bunny.x + 100 <= dil.x + 90) && (bunny.y + 100 >= dil.y && bunny.y <= dil.y)) || ((bunny.x <= dil.x + 90 && bunny.x + 100 >= dil.x + 90) && (bunny.y + 100 > dil.y && bunny.y <= dil.y))){
		f_heart = false;

	}

}


void bkchange(){
	bkindex++;
	if (bkindex > 21)
		bkindex = 0;

	bunIndex++;
	if (bunIndex >= 8)
		bunIndex = 0;

}
void change(){
	bunIndex++;
	if (bunIndex > 8)
		bunIndex = 0;

}
void coinChange1(){

	if (f_c1)
	{
		coin1.x = rand() % 800;
		f_c1 = false;

	}
	coin1.y -= 10;
	if (coin1.y <= 0){
		f_c1 = true;
		coin1.y = 1500;
		if (f_coin1 == false)
		{
			if (lifeCounter > 0)
			{
				score++;
				sumScore += 2;
			}
			difficulty();
		}
		f_coin1 = true;
	}


	coinIndex++;
	if (coinIndex >= 4)
	{
		coinIndex = 0;
	}



}
void coinChange2(){
	if (f_c2)
	{
		coin2.x = rand() % 800;
		f_c2 = false;
	}
	coin2.y -= 8;
	if (coin2.y <= 0){
		f_c2 = true;
		coin2.y = 1500;
		if (f_coin2 == false)
		{

			if (lifeCounter > 0)
			{
				score++;
				sumScore += 2;
			}

			difficulty();
		}

		f_coin2 = true;
	}





	if (f_c3)
	{
		coin3.x = rand() % 800;
		f_c3 = false;
	}
	coin3.y -= 10;
	if (coin3.y <= 0){
		f_c3 = true;
		coin3.y = 1500;

		if (f_coin3 == false)
		{
			if (lifeCounter > 0){

				score++;
				sumScore += 2;
			}
			

			difficulty();
		}

		f_coin3 = true;
	}


	coinIndex++;
	if (coinIndex >= 4)
	{
		coinIndex = 0;
	}



}




void carrotChange1(){



	if (f_car1)
	{
		carrot1.x = rand() % 800;
		f_car1 = false;
	}
	carrot1.y -= 15;
	if (carrot1.y < 0){
		f_car1 = true;
		carrot1.y = 1500;
		if (f_carrot1 == false)
		{
			if (lifeCounter>0){
				sumScore++;
				score1++;
			}
			difficulty();
		}

		f_carrot1 = true;

	}

	carrotIndex++;
	if (carrotIndex >= 4)
		carrotIndex = 0;

}


void carrotChange2(){


	if (f_car2)
	{
		carrot2.x = rand() % 800;
		f_car2 = false;
	}
	carrot2.y -= 10;
	if (carrot2.y < 0){
		f_car2 = true;
		carrot2.y = 1500;

		if (f_carrot2 == false)
		{
			if (lifeCounter>0){
				sumScore++;
				score1++;

			}
			
			difficulty();
		}
		f_carrot2 = true;

	}



	if (f_car3)
	{
		carrot3.x = rand() % 900;
		f_car3 = false;
	}
	carrot3.y -= 10;
	if (carrot3.y < 0){
		f_car3 = true;
		carrot3.y = 1500;
		if (f_carrot3 == false)
		{
			if (lifeCounter>0){
				sumScore++;
				score1++;
			}
			
			difficulty();
		}

		f_carrot3 = true;

	}



	carrotIndex++;
	if (carrotIndex >= 4)
		carrotIndex = 0;

}

void bomb_1(){



	if (f_b1){
		bomb1.x = rand() % 800;
		f_b1 = false;
	}
	bomb1.y -= by;
	if (bomb1.y <= 0) {
		f_b1 = true;
		bomb1.y = 1500;
		if (f_bomb1 == false)
		{

			lifeCounter--;
		}
		f_bomb1 = true;
	}

	if (sumScore > 15)
	{

		if (f_sb){
			sbomb.x = rand() % 800;
			f_sb = false;
		}
		sbomb.y -= by;
		if (sbomb.y <= 0) {
			f_sb = true;
			sbomb.y = 1500;
			if (f_sbomb == false)
			{

				lifeCounter--;
			}
			f_sbomb = true;
		}


	}


}
void bomb_2(){

	if (f_b2){
		bomb2.x = rand() % 800;
		f_b2 = false;
	}
	bomb2.y -= by;
	if (bomb2.y <= 0) {
		f_b2 = true;
		bomb2.y = 1500;
		if (f_bomb2 == false)
		{

			lifeCounter--;
		}
		f_bomb2 = true;
	}




}
void bomb_3(){

	if (f_b3){
		bomb3.x = rand() % 800;
		f_b3 = false;
	}
	bomb3.y -= by;
	if (bomb3.y <= 0) {
		f_b3 = true;
		bomb3.y = 1500;
		if (f_bomb3 == false)
		{

			lifeCounter--;
		}
		f_bomb3 = true;
	}

	if (sumScore > 30)
	{

		if (f_s1b){
			s1bomb.x = rand() % 800;
			f_s1b = false;
		}
		s1bomb.y -= by;
		if (s1bomb.y <= 0) {
			f_s1b = true;
			s1bomb.y = 1500;
			if (f_s1bomb == false)
			{

				lifeCounter--;
			}
			f_s1bomb = true;
		}
	}

}
void difficulty(){
	if (sumScore % 7 == 0)
	{
		by += 5;
	}


}

void aid(){

	if (f_h){
		dil.x = rand() % 800;
		f_h = false;
	}
	dil.y -= 10;
	if (dil.y <= 0) {
		f_h = true;
		dil.y = 1500;
		if (f_heart == false)
		{
			if (lifeCounter == 1 || lifeCounter == 2)
				lifeCounter++;

		}
		f_heart = true;
	}




}

void showScore(){

	scoreStr1 = to_string(score);
	score_char1 = (char*)scoreStr1.c_str();
	iShowBMP2(1150, 1400, s1[0], 255);
	iSetColor(255, 255, 0);
	iText(1200, 1416, score_char1, GLUT_BITMAP_TIMES_ROMAN_24);

	scoreStr2 = to_string(score1);
	score_char2 = (char*)scoreStr2.c_str();
	iShowBMP2(1230, 1400, s1[1], 255);
	iSetColor(255, 255, 0);
	iText(1280, 1416, score_char2, GLUT_BITMAP_TIMES_ROMAN_24);


	scoreStr = to_string(sumScore);
	score_char = (char*)scoreStr.c_str();
	iSetColor(255, 255, 0);
	iText(1160, 1360, " Points :", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1245, 1360, score_char, GLUT_BITMAP_TIMES_ROMAN_24);


}
void showLife(){

	if (lifeCounter >= 1)
		iShowImage(0, 1400, 60, 60, life);
	if (lifeCounter >= 2)
		iShowImage(70, 1400, 60, 60, life);
	if (lifeCounter == 3)
		iShowImage(140, 1400, 60, 60, life);
}

void gameover(){
	if (lifeCounter <= 0){
		iShowImage(0, 0, 1300, 1500, gameoverr);
		gameover1 = true;
	}
	else
		gameover1 = false;
}

void customScore(int num){
	int replacenum = num;
	digit1 = replacenum % 10;
	digit2 = (replacenum / 10) % 10;
	digit3 = (replacenum / 100) % 10;
	
	///////////////////////////////////////////////////
	switch (digit1) {
	case 0:
		iShowBMP2(700, 710, points[0], 255);
		break;
	case 1:
		iShowBMP2(700, 710, points[1], 255);
		break;
	case 2:
		iShowBMP2(700, 710, points[2], 255);
		break;
	case 3:
		iShowBMP2(700, 710, points[3], 255);
		break;
	case 4:
		iShowBMP2(700, 710, points[4], 255);
		break;
	case 5:
		iShowBMP2(700, 710, points[5], 255);
		break;
	case 6:
		iShowBMP2(700, 710, points[6], 255);
		break;
	case 7:
		iShowBMP2(700, 710, points[7], 255);
		break;
	case 8:
		iShowBMP2(700, 710, points[8], 255);
		break;
	case 9:
		iShowBMP2(700, 710, points[9], 255);
		break;

	default:
		cout << "Invalid  digit 1" << digit1 << endl;
	}
	/////////////////////////////////////////////////////////////////////////
	switch (digit2) {
	case 0:
		iShowBMP2(600, 710, points[0], 255);
		break;
	case 1:
		iShowBMP2(600, 710, points[1], 255);
		break;
	case 2:
		iShowBMP2(600, 710, points[2], 255);
		break;
	case 3:
		iShowBMP2(600, 710, points[3], 255);
		break;
	case 4:
		iShowBMP2(600, 710, points[4], 255);
		break;
	case 5:
		iShowBMP2(600, 710, points[5], 255);
		break;
	case 6:
		iShowBMP2(600, 710, points[6], 255);
		break;
	case 7:
		iShowBMP2(600, 710, points[7], 255);
		break;
	case 8:
		iShowBMP2(600, 710, points[8], 255);
		break;
	case 9:
		iShowBMP2(600, 710, points[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}
	//////////////////////////////////////////////
	switch (digit3) {
	case 0:
		iShowBMP2(500, 710, points[0], 255);
		break;
	case 1:
		iShowBMP2(500, 710, points[1], 255);
		break;
	case 2:
		iShowBMP2(500, 710, points[2], 255);
		break;
	case 3:
		iShowBMP2(500, 710, points[3], 255);
		break;
	case 4:
		iShowBMP2(500, 710, points[4], 255);
		break;
	case 5:
		iShowBMP2(500, 710, points[5], 255);
		break;
	case 6:
		iShowBMP2(500, 710, points[6], 255);
		break;
	case 7:
		iShowBMP2(500, 710, points[7], 255);
		break;
	case 8:
		iShowBMP2(500, 710, points[8], 255);
		break;
	case 9:
		iShowBMP2(500, 710, points[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}



}
void customScore1(int num){


	int replacenum = num;
	digit1 = replacenum % 10;
	digit2 = (replacenum / 10) % 10;
	digit3 = (replacenum / 100) % 10;
	
	///////////////////////////////////////////////////
	switch (digit1) {
	case 0:
		iShowBMP2(700, 450, points[0], 255);
		break;
	case 1:
		iShowBMP2(700, 450, points[1], 255);
		break;
	case 2:
		iShowBMP2(700, 450, points[2], 255);
		break;
	case 3:
		iShowBMP2(700, 450, points[3], 255);
		break;
	case 4:
		iShowBMP2(700, 450, points[4], 255);
		break;
	case 5:
		iShowBMP2(700, 450, points[5], 255);
		break;
	case 6:
		iShowBMP2(700, 450, points[6], 255);
		break;
	case 7:
		iShowBMP2(700, 450, points[7], 255);
		break;
	case 8:
		iShowBMP2(700, 450, points[8], 255);
		break;
	case 9:
		iShowBMP2(700, 450, points[9], 255);
		break;

	default:
		cout << "Invalid  digit 1" << digit1 << endl;
	}
	/////////////////////////////////////////////////////////////////////////
	switch (digit2) {
	case 0:
		iShowBMP2(600, 450, points[0], 255);
		break;
	case 1:
		iShowBMP2(600, 450, points[1], 255);
		break;
	case 2:
		iShowBMP2(600, 450, points[2], 255);
		break;
	case 3:
		iShowBMP2(600, 450, points[3], 255);
		break;
	case 4:
		iShowBMP2(600, 450, points[4], 255);
		break;
	case 5:
		iShowBMP2(600, 450, points[5], 255);
		break;
	case 6:
		iShowBMP2(600, 450, points[6], 255);
		break;
	case 7:
		iShowBMP2(600, 450, points[7], 255);
		break;
	case 8:
		iShowBMP2(600, 450, points[8], 255);
		break;
	case 9:
		iShowBMP2(600, 450, points[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}
	//////////////////////////////////////////////
	switch (digit3) {
	case 0:
		iShowBMP2(500, 450, points[0], 255);
		break;
	case 1:
		iShowBMP2(500, 450, points[1], 255);
		break;
	case 2:
		iShowBMP2(500, 450, points[2], 255);
		break;
	case 3:
		iShowBMP2(500, 450, points[3], 255);
		break;
	case 4:
		iShowBMP2(500, 450, points[4], 255);
		break;
	case 5:
		iShowBMP2(500, 450, points[5], 255);
		break;
	case 6:
		iShowBMP2(500, 450, points[6], 255);
		break;
	case 7:
		iShowBMP2(500, 450, points[7], 255);
		break;
	case 8:
		iShowBMP2(500, 450, points[8], 255);
		break;
	case 9:
		iShowBMP2(500, 450, points[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}



}
void customScore2(int num){


	int replacenum = num;
	digit1 = replacenum % 10;
	digit2 = (replacenum / 10) % 10;
	digit3 = (replacenum / 100) % 10;
	
	///////////////////////////////////////////////////
	switch (digit1) {
	case 0:
		iShowBMP2(970, 170, points[0], 255);
		break;
	case 1:
		iShowBMP2(970, 170, points[1], 255);
		break;
	case 2:
		iShowBMP2(970, 170, points[2], 255);
		break;
	case 3:
		iShowBMP2(970, 170, points[3], 255);
		break;
	case 4:
		iShowBMP2(970, 170, points[4], 255);
		break;
	case 5:
		iShowBMP2(970, 170, points[5], 255);
		break;
	case 6:
		iShowBMP2(970, 170, points[6], 255);
		break;
	case 7:
		iShowBMP2(970, 170, points[7], 255);
		break;
	case 8:
		iShowBMP2(970, 170, points[8], 255);
		break;
	case 9:
		iShowBMP2(970, 170, points[9], 255);
		break;

	default:
		cout << "Invalid  digit 1" << digit1 << endl;
	}
	/////////////////////////////////////////////////////////////////////////
	switch (digit2) {
	case 0:
		iShowBMP2(870, 170, points[0], 255);
		break;
	case 1:
		iShowBMP2(870, 170, points[1], 255);
		break;
	case 2:
		iShowBMP2(870, 170, points[2], 255);
		break;
	case 3:
		iShowBMP2(870, 170, points[3], 255);
		break;
	case 4:
		iShowBMP2(870, 170, points[4], 255);
		break;
	case 5:
		iShowBMP2(870, 170, points[5], 255);
		break;
	case 6:
		iShowBMP2(870, 170, points[6], 255);
		break;
	case 7:
		iShowBMP2(870, 170, points[7], 255);
		break;
	case 8:
		iShowBMP2(870, 170, points[8], 255);
		break;
	case 9:
		iShowBMP2(870, 170, points[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}
	//////////////////////////////////////////////
	switch (digit3) {
	case 0:
		iShowBMP2(770, 170, points[0], 255);
		break;
	case 1:
		iShowBMP2(770, 170, points[1], 255);
		break;
	case 2:
		iShowBMP2(770, 170, points[2], 255);
		break;
	case 3:
		iShowBMP2(770, 170, points[3], 255);
		break;
	case 4:
		iShowBMP2(770, 170, points[4], 255);
		break;
	case 5:
		iShowBMP2(770, 170, points[5], 255);
		break;
	case 6:
		iShowBMP2(770, 170, points[6], 255);
		break;
	case 7:
		iShowBMP2(770, 170, points[7], 255);
		break;
	case 8:
		iShowBMP2(770, 170, points[8], 255);
		break;
	case 9:
		iShowBMP2(770, 170, points[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}



}

void customScore3(int num){


	int replacenum = num;
	digit1 = replacenum % 10;
	digit2 = (replacenum / 10) % 10;
	digit3 = (replacenum / 100) % 10;
	
	///////////////////////////////////////////////////
	switch (digit1) {
	case 0:
		iShowBMP2(670,900, spoints[0], 255);
		break;
	case 1:
		iShowBMP2(670, 900, spoints[1], 255);
		break;
	case 2:
		iShowBMP2(670, 900, spoints[2], 255);
		break;
	case 3:
		iShowBMP2(670, 900, spoints[3], 255);
		break;
	case 4:
		iShowBMP2(670, 900, spoints[4], 255);
		break;
	case 5:
		iShowBMP2(670, 900, spoints[5], 255);
		break;
	case 6:
		iShowBMP2(670, 900, spoints[6], 255);
		break;
	case 7:
		iShowBMP2(670, 900, spoints[7], 255);
		break;
	case 8:
		iShowBMP2(670, 900, spoints[8], 255);
		break;
	case 9:
		iShowBMP2(670, 900, spoints[9], 255);
		break;

	default:
		cout << "Invalid  digit 1" << digit1 << endl;
	}
	/////////////////////////////////////////////////////////////////////////
	switch (digit2) {
	case 0:
		iShowBMP2(620, 900, spoints[0], 255);
		break;
	case 1:
		iShowBMP2(620, 900, spoints[1], 255);
		break;
	case 2:
		iShowBMP2(620, 900, spoints[2], 255);
		break;
	case 3:
		iShowBMP2(620, 900, spoints[3], 255);
		break;
	case 4:
		iShowBMP2(620, 900, spoints[4], 255);
		break;
	case 5:
		iShowBMP2(620, 900, spoints[5], 255);
		break;
	case 6:
		iShowBMP2(620, 900, spoints[6], 255);
		break;
	case 7:
		iShowBMP2(620, 900, spoints[7], 255);
		break;
	case 8:
		iShowBMP2(620, 900, spoints[8], 255);
		break;
	case 9:
		iShowBMP2(620, 900, spoints[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}
	//////////////////////////////////////////////
	switch (digit3) {
	case 0:
		iShowBMP2(570, 900, spoints[0], 255);
		break;
	case 1:
		iShowBMP2(570, 900, spoints[1], 255);
		break;
	case 2:
		iShowBMP2(570, 900, spoints[2], 255);
		break;
	case 3:
		iShowBMP2(570, 900, spoints[3], 255);
		break;
	case 4:
		iShowBMP2(570, 900, spoints[4], 255);
		break;
	case 5:
		iShowBMP2(570, 900, spoints[5], 255);
		break;
	case 6:
		iShowBMP2(570, 900, spoints[6], 255);
		break;
	case 7:
		iShowBMP2(570, 900, spoints[7], 255);
		break;
	case 8:
		iShowBMP2(570, 900, spoints[8], 255);
		break;
	case 9:
		iShowBMP2(570, 900, spoints[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}



}
void customScore4(int num){


	int replacenum = num;
	digit1 = replacenum % 10;
	digit2 = (replacenum / 10) % 10;
	digit3 = (replacenum / 100) % 10;
	
	///////////////////////////////////////////////////
	switch (digit1) {
	case 0:
		iShowBMP2(670, 600, spoints[0], 255);
		break;
	case 1:
		iShowBMP2(670, 600, spoints[1], 255);
		break;
	case 2:
		iShowBMP2(670, 600, spoints[2], 255);
		break;
	case 3:
		iShowBMP2(670, 600, spoints[3], 255);
		break;
	case 4:
		iShowBMP2(670, 600, spoints[4], 255);
		break;
	case 5:
		iShowBMP2(670, 600, spoints[5], 255);
		break;
	case 6:
		iShowBMP2(670, 600, spoints[6], 255);
		break;
	case 7:
		iShowBMP2(670, 600, spoints[7], 255);
		break;
	case 8:
		iShowBMP2(670, 600, spoints[8], 255);
		break;
	case 9:
		iShowBMP2(670, 600, spoints[9], 255);
		break;

	default:
		cout << "Invalid  digit 1" << digit1 << endl;
	}
	/////////////////////////////////////////////////////////////////////////
	switch (digit2) {
	case 0:
		iShowBMP2(620, 600, spoints[0], 255);
		break;
	case 1:
		iShowBMP2(620,600, spoints[1], 255);
		break;
	case 2:
		iShowBMP2(620, 600, spoints[2], 255);
		break;
	case 3:
		iShowBMP2(620, 600, spoints[3], 255);
		break;
	case 4:
		iShowBMP2(620, 600, spoints[4], 255);
		break;
	case 5:
		iShowBMP2(620, 600, spoints[5], 255);
		break;
	case 6:
		iShowBMP2(620, 600, spoints[6], 255);
		break;
	case 7:
		iShowBMP2(620, 600, spoints[7], 255);
		break;
	case 8:
		iShowBMP2(620, 600, spoints[8], 255);
		break;
	case 9:
		iShowBMP2(620, 600, spoints[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}
	//////////////////////////////////////////////
	switch (digit3) {
	case 0:
		iShowBMP2(570, 600, spoints[0], 255);
		break;
	case 1:
		iShowBMP2(570, 600, spoints[1], 255);
		break;
	case 2:
		iShowBMP2(570, 600, spoints[2], 255);
		break;
	case 3:
		iShowBMP2(570, 600, spoints[3], 255);
		break;
	case 4:
		iShowBMP2(570, 600, spoints[4], 255);
		break;
	case 5:
		iShowBMP2(570, 600, spoints[5], 255);
		break;
	case 6:
		iShowBMP2(570, 600, spoints[6], 255);
		break;
	case 7:
		iShowBMP2(570, 600, spoints[7], 255);
		break;
	case 8:
		iShowBMP2(570, 600, spoints[8], 255);
		break;
	case 9:
		iShowBMP2(570, 600, spoints[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}



}

void customScore5(int num){


	int replacenum = num;
	digit1 = replacenum % 10;
	digit2 = (replacenum / 10) % 10;
	digit3 = (replacenum / 100) % 10;
	
	///////////////////////////////////////////////////
	switch (digit1) {
	case 0:
		iShowBMP2(670, 300, spoints[0], 255);
		break;
	case 1:
		iShowBMP2(670, 300, spoints[1], 255);
		break;
	case 2:
		iShowBMP2(670, 300, spoints[2], 255);
		break;
	case 3:
		iShowBMP2(670, 300, spoints[3], 255);
		break;
	case 4:
		iShowBMP2(670, 300, spoints[4], 255);
		break;
	case 5:
		iShowBMP2(670, 300, spoints[5], 255);
		break;
	case 6:
		iShowBMP2(670, 300, spoints[6], 255);
		break;
	case 7:
		iShowBMP2(670, 300, spoints[7], 255);
		break;
	case 8:
		iShowBMP2(670, 300, spoints[8], 255);
		break;
	case 9:
		iShowBMP2(670, 300, spoints[9], 255);
		break;

	default:
		cout << "Invalid  digit 1" << digit1 << endl;
	}
	/////////////////////////////////////////////////////////////////////////
	switch (digit2) {
	case 0:
		iShowBMP2(620, 300, spoints[0], 255);
		break;
	case 1:
		iShowBMP2(620, 300, spoints[1], 255);
		break;
	case 2:
		iShowBMP2(620, 300, spoints[2], 255);
		break;
	case 3:
		iShowBMP2(620, 300, spoints[3], 255);
		break;
	case 4:
		iShowBMP2(620, 300, spoints[4], 255);
		break;
	case 5:
		iShowBMP2(620, 300, spoints[5], 255);
		break;
	case 6:
		iShowBMP2(620, 300, spoints[6], 255);
		break;
	case 7:
		iShowBMP2(620, 300, spoints[7], 255);
		break;
	case 8:
		iShowBMP2(620, 300, spoints[8], 255);
		break;
	case 9:
		iShowBMP2(620, 300, spoints[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}
	//////////////////////////////////////////////
	switch (digit3) {
	case 0:
		iShowBMP2(570, 300, spoints[0], 255);
		break;
	case 1:
		iShowBMP2(570, 300, spoints[1], 255);
		break;
	case 2:
		iShowBMP2(570, 300, spoints[2], 255);
		break;
	case 3:
		iShowBMP2(570, 300, spoints[3], 255);
		break;
	case 4:
		iShowBMP2(570, 300, spoints[4], 255);
		break;
	case 5:
		iShowBMP2(570, 300, spoints[5], 255);
		break;
	case 6:
		iShowBMP2(570, 300, spoints[6], 255);
		break;
	case 7:
		iShowBMP2(570, 300, spoints[7], 255);
		break;
	case 8:
		iShowBMP2(570, 300, spoints[8], 255);
		break;
	case 9:
		iShowBMP2(570, 300, spoints[9], 255);
		break;

	default:
		cout << "Invalid " << endl;
	}



}
void scoreBoard(){
	iShowImage(0, 0, 1300, 1500, scoreboard);
	customScore(score);
	customScore1(score1);
	customScore2(sumScore);
	if (point){
		writeFile.open("Finalscore.txt", ios::out | ios::app);
		writeFile << sumScore << endl;
		writeFile.close();
		point = false;
		

	}
	

}
void highScore(){

	int HS[10000];
	readFile.open("Finalscore.txt");
	while (!readFile.eof()){
		readFile >> HS[loop];
		loop++;
	}
	numofHS = loop - 1;
	readFile.close();
	for (int j = 0; j < numofHS - 1; j++){

		for (int k = j + 1; k <= numofHS; k++){
			if (HS[j] < HS[k]){
				temp = HS[j];
				HS[j] = HS[k];
				HS[k] = temp;



			}
			if (numofHS == k)
			{
				break;
			}

		}
		if (numofHS == j)
			break;
	}
	hs1 = HS[0];
	hs2 = HS[1];
	hs3 = HS[2];


}

void restart(){

	 coin coin1(400, screenheight);
	 coin coin2(800, screenheight);
	 coin coin3(600, screenheight);

	 rabbit bunny(927, 100);
	 heart dil(0, screenheight);
	 carrot carrot1(500, screenheight);
	 carrot carrot2(700, screenheight);
	 carrot carrot3(900, screenheight);

	 bomb bomb1(0, screenheight);
	 bomb bomb2(0, screenheight);
	 bomb bomb3(0, screenheight);
	 bomb sbomb(0, screenheight);
	 bomb s1bomb(0, screenheight);


	f_coin1 = true, f_coin2 = true, f_coin3 = true;
	 f_carrot1 = true, f_carrot2 = true, f_carrot3 = true;
	 f_bomb1 = true, f_bomb2 = true, f_bomb3 = true, f_sbomb = true, f_s1bomb = true;
	  f_heart = true;
	  by = 10;
	  score = 0, score1 = 0, sumScore = 0;
	  lifeCounter = 3;


	

}


void scoreBoard1(){
	
	iShowImage(0, 0, screenwidth, screenheight, b);
	
	
	customScore3(hs1);
	customScore4(hs2);
	customScore5(hs3);
}


int main()
{
	int sum = 500;
	for (int i = 4; i >= 0; i--){
		bCoordinate[i].x = 50;
		bCoordinate[i].y = sum;
		sum += 85;
	}
	if (musicOn)
		PlaySound("startbg.wav", NULL, SND_LOOP | SND_ASYNC);
	x1 = iSetTimer(100, bkchange);
	x2 = iSetTimer(100, change);


	x3 = iSetTimer(350, coinChange1);
	x4 = iSetTimer(400, coinChange2);

	x5 = iSetTimer(300, carrotChange1);
	x6 = iSetTimer(250, carrotChange2);


	x7 = iSetTimer(350, bomb_1);
	x8 = iSetTimer(300, bomb_2);
	x9 = iSetTimer(280, bomb_3);

	x10 = iSetTimer(400, aid);

	iInitialize(screenwidth, screenheight, "Hungry Rabit");
	scoreBoard1();
	bg = iLoadImage("bugs.bmp");
	story = iLoadImage("story.bmp");
	b = iLoadImage("21.bmp");
	c = iLoadImage("NEW.bmp");
	d = iLoadImage("Credits1.bmp");
	///updated see the documentations
	img[0][100] = iLoadImage("Images\\00.bmp");
	img[01][100] = iLoadImage("Images\\01.bmp");
	img[2][100] = iLoadImage("Images\\02.bmp");
	img[3][100] = iLoadImage("Images\\03.bmp");
	img[4][100] = iLoadImage("Images\\04.bmp");
	img[5][100] = iLoadImage("Images\\05.bmp");
	img[6][100] = iLoadImage("Images\\06.bmp");
	img[7][100] = iLoadImage("Images\\07.bmp");
	img[8][100] = iLoadImage("Images\\08.bmp");
	img[9][100] = iLoadImage("Images\\09.bmp");
	img[10][100] = iLoadImage("Images\\10.bmp");
	img[11][100] = iLoadImage("Images\\11.bmp");
	img[12][100] = iLoadImage("Images\\12.bmp");
	img[13][100] = iLoadImage("Images\\13.bmp");
	img[14][100] = iLoadImage("Images\\14.bmp");
	img[15][100] = iLoadImage("Images\\15.bmp");
	img[16][100] = iLoadImage("Images\\16.bmp");
	img[17][100] = iLoadImage("Images\\17.bmp");
	img[18][100] = iLoadImage("Images\\18.bmp");
	img[19][100] = iLoadImage("Images\\19.bmp");
	img[20][100] = iLoadImage("Images\\20.bmp");
	img[21][100] = iLoadImage("Images\\21.bmp");
	img[22][100] = iLoadImage("Images\\22.bmp");


	bun[0][100] = iLoadImage("rab1.png");
	bun[1][100] = iLoadImage("rab2.png");
	bun[2][100] = iLoadImage("rab3.png");
	bun[3][100] = iLoadImage("rab4.png");
	bun[4][100] = iLoadImage("rab5.png");
	bun[5][100] = iLoadImage("rab6.png");
	bun[6][100] = iLoadImage("rab7.png");
	bun[7][100] = iLoadImage("rab8.png");

	life = iLoadImage("lifeH.png");
	mLife = iLoadImage("getH.png");
	
	gameoverr = iLoadImage("gameoverr.bmp");
	scoreboard = iLoadImage("scoreboard.bmp");
	
	iStart();
	return 0;
}