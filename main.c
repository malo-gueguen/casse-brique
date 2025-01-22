#include <SDL2/SDL.h>
#include <unistd.h>
#include "function.h"
#include <time.h>
#include "sdl_helper/sdlhelper.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define FPS 60
char animationA[300];
int programLaunched = 1;
Balles tBalles[50];
Point bPoint[9][6];
int animLVL[4000];
int tabvies[10];
int nballe=1;
int cballe=1;
int x = 300;
int y = 600;
int by =100;
int bx =80;
int i = 0;
int c = 0;
int r = 0;
int endw = 0;
int vies = 4;
int vieBoss = 30;
int j = 0;
int tot = 0;
int manche = 1;
int v = 0;
int t = 100;
int rando = 0;
int qa = 0;
int da = 0;
int pvy =0;
int menu=0;
int phase=1;
int compteurA=1;
int animy=0;
int animx=0;
int ballevide=0;
int frameM=0;
int mousex=0;
int mousey=0;
int stop=-1;
void bruit_briques(){

    	if (manche==2){
      	audioLoadAndPlay("sdl_helper/sound/dirt.wav", 3);
    	}
    	if (manche==3){
      	audioLoadAndPlay("sdl_helper/sound/netherrack.wav", 3);
    	}
    	if (manche==4){
      	audioLoadAndPlay("sdl_helper/sound/stone.wav", 3);
    	}
    	if (manche==5){
      	audioLoadAndPlay("sdl_helper/sound/stone.wav", 3);
    	}
    	if (manche==6){
      	audioLoadAndPlay("sdl_helper/sound/dirt.wav", 3);
    	}


}
void draw_loose(){
  sprite(0,0,"sprites/loose.bmp");
if ((mousex>180 && mousex<540) && (mousey>370 && mousey<400)){
  menu=1;
  vies=4;
  manche=1;


}
if ((mousex>180 && mousex<540) && (mousey>410 && mousey<450)){
  menu=0;
	vies=4;

}
  actualize();
  usleep(1000000 / FPS);
}
void draw_menu(){
sprite(0,0,"sprites/menu.bmp");

 if ((mousex>280 && mousex<440) && (mousey>290 && mousey<430)){
  menu=1;
  manche=1;
}
if ((mousex>180 && mousex<330) && (mousey>450 && mousey<570)){
  menu=1;
}
if ((mousex>380 && mousex<530) && (mousey>450 && mousey<570)){
  manche=5;
  menu=5;
}
if ((mousex>310 && mousex<390) && (mousey>600 && mousey<670)){
  programLaunched = 0;
}
  actualize();
  usleep(1000000 / FPS);
}
void next_lvl(){
  drawRect(150,350,400,4);
  drawRect(150,370,404,4);
  drawRect(550,350,4,20);
  drawRect(150,350,4,20);
  drawRect(250,350,4,20);
  drawRect(350,350,4,20);
  drawRect(450,350,4,20);
   for(i=0;i<frameM;i++){

 	if (animLVL[i]==1){
  	drawCircle(i+159,361,10);

 	}
animLVL[frameM]=1;
   }
if (menu==20 && frameM==85){
	menu=2;
	frameM=0;
}
 if (menu==30 && frameM<100){
	frameM=100;

}
if (menu==30 && frameM==185){
	menu=3;
	frameM=0;

}
if (menu==40 && frameM<200){
	frameM=200;
}
if (menu==40 && frameM==285){
	menu=4;
	frameM=0;

}
if (menu==50 && frameM<300){
	frameM=300;
}
if (menu==50 && frameM>=385){
	menu=0;
}
usleep(1000000 / FPS);
actualize();
clear();
frameM++;
printf("%d",frameM);

}
void tuto(){

   if ((mousex>310 && mousex<390) && (mousey>400 && mousey<470)){

phase++;
bPoint[3][2].brique=-1;
}
if (bPoint[3][2].brique==0){
  stop=1;
  sprite(310,400,"sprites/ok.bmp");
  sprite(230,250,"sprites/panneau.bmp");
  if (phase==1){
	textDrawText("Touche les briques pour les  ", 240, 280, comfortaaFont_16);
	textDrawText("casser et passer au niveau", 240, 300, comfortaaFont_16);
	textDrawText("suivant !", 320, 320, comfortaaFont_16);
  }
  if (phase==3){
	textDrawText("recupere ce bonus pour avoir", 230, 280, comfortaaFont_16);
	textDrawText("une balle supplementaire ", 230, 300, comfortaaFont_16);

}
if (phase==5){
	textDrawText("recupere ce bonus pour", 250, 280, comfortaaFont_16);
	textDrawText("avoir une reduction de ", 250, 300, comfortaaFont_16);
	textDrawText("la taille de la raquette ", 250, 320, comfortaaFont_16);

}
if (phase==7){
	textDrawText("recupere ce bonus pour", 250, 280, comfortaaFont_16);
	textDrawText("avoir une augmentation de ", 250, 300, comfortaaFont_16);
	textDrawText("la taille de la raquette ", 250, 320, comfortaaFont_16);

}
if (phase==9){
	textDrawText("recupere ce bonus pour", 250, 280, comfortaaFont_16);
	textDrawText("avoir un point de vie ", 250, 300, comfortaaFont_16);
	textDrawText("supplementaire ", 250, 320, comfortaaFont_16);

}
if (phase==11){
	textDrawText("recupere ce bonus pour", 250, 280, comfortaaFont_16);
	textDrawText("avoir une augmentation de la", 250, 300, comfortaaFont_16);
	textDrawText("vitesse de la balle ", 250, 320, comfortaaFont_16);

}
if (phase==13){
	textDrawText("recupere ce bonus pour", 250, 280, comfortaaFont_16);
	textDrawText("avoir une reduction de la", 250, 300, comfortaaFont_16);
	textDrawText("vitesse de la balle ", 250, 320, comfortaaFont_16);

}
}
else{
  stop=-1;
}


if (phase==2){

  bPoint[3][2].brique=1;
  bPoint[3][2].b=1;
  phase++;
}
if (phase==4){
  if(bPoint[3][2].b==0){
  bPoint[3][2].brique=1;
  bPoint[3][2].b=2;
  phase++;
  }
}
if (phase==6){
  if(bPoint[3][2].b==0){
  bPoint[3][2].brique=1;
  bPoint[3][2].b=3;
  phase++;
  }
}
if (phase==8){
  if(bPoint[3][2].b==0){
  bPoint[3][2].brique=1;
  bPoint[3][2].b=4;
  phase++;
  }
}
if (phase==10){
  if(bPoint[3][2].b==0){
  bPoint[3][2].brique=1;
  bPoint[3][2].b=5;
  phase++;
  }
}
if (phase==12){
  if(bPoint[3][2].b==0){
  bPoint[3][2].brique=1;
  bPoint[3][2].b=6;
  phase++;
  }
}
if (phase==14){
  if(bPoint[3][2].b==0){
  endw=1;
  }
}

}
void cadre(){
    	if (manche==2){
      	sprite(0,0,"sprites/fond1.bmp");
    	}
    	if (manche==3){
      	sprite(0,0,"sprites/fond2.bmp");
    	}
    	if (manche==4){
      	sprite(0,0,"sprites/fond3.bmp");
    	}
    	if (manche==5){
      	sprite(0,0,"sprites/fond3.bmp");
    	}
    	if (manche==6){
      	sprite(0,0,"sprites/fond1.bmp");
    	}

  drawRect(0, 0, 700, 20);
  drawRect(0, 0, 20, 700);
  drawRect(0, 680, 700, 20);
  drawRect(680, 0, 20, 700);
  for(cballe=0;cballe<20;cballe++){
	if (tBalles[cballe].x>670){
  	tBalles[cballe].c=1;
  	}
	if (tBalles[cballe].x<30){
  	tBalles[cballe].c=0;
	}
	if (tBalles[cballe].y<30){
  	tBalles[cballe].r=0;
	}
  }
}
void vie(){
  changeColor(25,18,112);
  drawRect(50,640,90,4);
  drawRect(50,660,94,4);
  drawRect(50,640,4,20);
  drawRect(140,640,4,20);
  if(vies<=3){
	drawRect(50,640,30*vies,20);
  }
  if(vies>3){

  	drawRect(50,640,90,20);
  	tabvies[vies]=1;
	for (i=0;i<20;i++){
  	drawCircle(140+20*(tabvies[i]),650,10);
	}
  }
}
void bonus(){
  for (i=0;i<=5;i++){
	for (j=0;j<=5;j++){
  	if (bPoint[i][j].b<0){
    	if(bPoint[i][j].y<680){
      	if (bPoint[i][j].b==-1){
        	changeColor(25,18,112);
        	sprite(bPoint[i][j].x+40,bPoint[i][j].y+10,"sprites/balleb.bmp");
      	}
      	if (bPoint[i][j].b==-2){
        	changeColor(100,18,220);
        	sprite(bPoint[i][j].x+40,bPoint[i][j].y+10,"sprites/rapetissement.bmp");
      	}
      	if (bPoint[i][j].b==-3){
        	changeColor(12,100,220);
        	sprite(bPoint[i][j].x+40,bPoint[i][j].y+10,"sprites/agrandissement.bmp");
      	}
      	if (bPoint[i][j].b==-4){
        	sprite(bPoint[i][j].x+40,bPoint[i][j].y+10,"sprites/vie.bmp");
      	}
      	if (bPoint[i][j].b==-5){
        	sprite(bPoint[i][j].x+40,bPoint[i][j].y+10,"sprites/speed.bmp");
      	}
      	if (bPoint[i][j].b==-6){
        	sprite(bPoint[i][j].x+40,bPoint[i][j].y+10,"sprites/slow.bmp");
      	}

    	}
    	else{
      	bPoint[i][j].b=0;

    	}
      	if ((x<bPoint[i][j].x+50)&&(bPoint[i][j].x+50<x+t)&&(y-10<bPoint[i][j].y)&&(bPoint[i][j].y<y+5)){
        	audioLoadAndPlay("sdl_helper/sound/drop.wav", 2);
        	if (bPoint[i][j].b==-1){
        	bPoint[i][j].b=0;
         	nballe++;
         	tBalles[ballevide].actif =-1;
        	}
        	else if (bPoint[i][j].b==-2){
          	bPoint[i][j].b=0;
          	if (t>20){
            	t=t-20;
          	}
        	}
        	else if (bPoint[i][j].b==-3){
          	bPoint[i][j].b=0;
         	t=t+20;
        	}
        	else if (bPoint[i][j].b==-4){
          	bPoint[i][j].b=0;

          	vies++;
        	}
        	else if (bPoint[i][j].b==-5){
          	bPoint[i][j].b=0;
          	v=v+3;
        	}
        	else if (bPoint[i][j].b==-6){
          	bPoint[i][j].b=0;
          	v=v-3;
        	}
      	}
      	if(stop==-1){
          	bPoint[i][j].y=bPoint[i][j].y+3;

      	}
    	}
	}
  }
}
void manche_1(){
  for (i=0;i<3;i++){
	for (j=0;j<5;j++){
   	bPoint[i][j].brique=1;
  	if (rand()%2==1){
    	rando=rand()%6+1;
    	bPoint[i][j].b=rando;
  	}
	}
  }
}
void manche_2(){
  for (i=0;i<5;i++){
	for (j=0;j<2;j++){
  	bPoint[i][j].brique=1;
  	if (rand()%2==1){
  	rando=rand()%6+1;
  	bPoint[i][j].b=rando;
  	}

  	}
	for (j=0;j<2;j++){
  	bPoint[i][j+3].brique=1;
  	if (rand()%2==1){
    	rando=rand()%6+1;
  	bPoint[i][j+3].b=rando;
	}
  }
}
}
void manche_3(){
  for (i=0;i<3;i++){
	for (j=0;j<5;j++){
  	bPoint[i][j].brique=1;
  	if (rand()%2==1){
    	rando=rand()%6+1;
  	bPoint[i][j].b=rando;
  	}
	}
  }
  for (j=0;j<5;j++){
	bPoint[4][j].brique=2;
	if (rand()%2==1){
    	rando=rand()%6+1;
	bPoint[4][j].b=rando;
	}
	}
}
void manche_boss(){
bPoint[3][3].brique=130;
}
void manche_tuto(){
bPoint[3][2].brique=1;
}
void boss(){
  changeColor(25,18,112);
  drawRect(60,60,600,4);
  drawRect(60,80,604,4);
  drawRect(60,60,4,20);
  drawRect(660,60,4,20);
  drawRect(60,60,20*(vieBoss),20);

  for(cballe=0;cballe<20;cballe++){
 if (vieBoss>0){


    	sprite(275,125,"sprites/boss.bmp");
    	if ((245<tBalles[cballe].y)&&(tBalles[cballe].y<255)&&(275<tBalles[cballe].x)&&(tBalles[cballe].x<425)){
      	tBalles[cballe].r=0;
      	bPoint[3][3].brique--;
      	if((bPoint[0][0].brique==0 || bPoint[0][0].brique==1 )&&( bPoint[0][4].brique==0 || bPoint[0][4].brique==1)){
        	vieBoss--;
      	}
    	}
    	else if ((120<tBalles[cballe].y)&&(tBalles[cballe].y<130)&&(275<tBalles[cballe].x)&&(tBalles[cballe].x<425)){
      	tBalles[cballe].r=1;
      	bPoint[3][3].brique--;
      	if((bPoint[0][0].brique==0 || bPoint[0][0].brique==1 )&&( bPoint[0][4].brique==0 || bPoint[0][4].brique==1)){
        	vieBoss--;
      	}
    	}
     	else if ((125<tBalles[cballe].y)&&(tBalles[cballe].y<250)&&(420<tBalles[cballe].x)&&(tBalles[cballe].x<430)){
      	tBalles[cballe].c=0;
      	bPoint[3][3].brique--;
      	if((bPoint[0][0].brique==0 || bPoint[0][0].brique==1 )&&( bPoint[0][4].brique==0 || bPoint[0][4].brique==1)){
        	vieBoss--;
      	}
    	}
    	else if ((125<tBalles[cballe].y)&&(tBalles[cballe].y<250)&&(270<tBalles[cballe].x)&&(tBalles[cballe].x<280)){
      	tBalles[cballe].c=1;
      	bPoint[3][3].brique--;
      	if((bPoint[0][0].brique==0 || bPoint[0][0].brique==1 )&&( bPoint[0][4].brique==0 || bPoint[0][4].brique==1)){
        	vieBoss--;
      	}
    	}
  	}
  	else{
    	endw=1;
  	}
  	if(bPoint[3][3].brique==127){
    	for (j=0;j<5;j++){
      	bPoint[8][j].brique=1;
      	if (rand()%2==1){
      	rando=rand()%6+1;
      	bPoint[8][j].b=rando;
      	}
    	}
      	bPoint[3][3].brique--;
  	}
  	if(bPoint[3][3].brique==120){

      	for (j=0;j<6;j++){

      	bPoint[8][j].brique=1;
      	bPoint[0][j].brique=1;
      	if (rand()%2==1){
        	rando=rand()%6+1;
        	bPoint[8][j].b=rando;
      	}
      	if (rand()%2==1){
        	rando=rand()%6+1;
        	bPoint[0][j].b=rando;
      	}
      	}
      	for (i=0;i<8;i++){
      	rando=rand()%2+1;
      	bPoint[i][0].brique=1;
      	bPoint[i][4].brique=1;
      	if (rand()%2==1){
        	rando=rand()%6+1;
        	bPoint[i][0].b=rando;
      	}
      	if (rand()%2==1){
        	rando=rand()%6+1;
        	bPoint[i][4].b=rando;
      	}
      	}

      	bPoint[3][3].brique--;

  	}
   	if(bPoint[3][3].brique==112){

      	bPoint[0][0].brique=10;
      	bPoint[0][4].brique=10;
      	bPoint[3][3].brique--;
  	}
  	if(bPoint[3][3].brique==107){


  	}
  }
}
void briques(){

  by =75;
  for (i=0;i<9;i++){
	bx =90;
	for (j=0;j<5;j++){
  	if (bPoint[i][j].brique==1){
    	if (manche==2){
      	sprite(bx,by,"sprites/brique1.bmp");
    	}
    	if (manche==3){
      	sprite(bx,by,"sprites/brique2.bmp");
    	}
    	if (manche==4){
      	sprite(bx,by,"sprites/brique3.bmp");
    	}
    	if (manche==5){
      	sprite(bx,by,"sprites/brique4.bmp");
    	}
    	if (manche==6){
      	sprite(bx,by,"sprites/brique1.bmp");
    	}
  	}
  	bx=bx+105;
	}
	by=by+25;
  }
  for(cballe=0;cballe<20;cballe++){
	by =75;
	for (i=0;i<9;i++){
  	bx =90;
  	for (j=0;j<5;j++){
    	if (bPoint[i][j].brique==1){
      	if ((by+15<tBalles[cballe].y)&&(tBalles[cballe].y<by+25)&&(bx-5<tBalles[cballe].x+10)&&(tBalles[cballe].x+10<bx+105)){
        	tBalles[cballe].r++;//rebond vertical
        	bPoint[i][j].brique=0;
        	tot--;
        	animx=bx;
        	animy=by;
        	compteurA = 1;
        	bruit_briques();

        	if ((bPoint[i][j].b>=1)){
          	bPoint[i][j].b=-bPoint[i][j].b;
          	bPoint[i][j].y=by;
          	bPoint[i][j].x=bx;
        	}
      	}
      	else if ((by-5<tBalles[cballe].y+10)&&(tBalles[cballe].y+10<by+5)&&(bx-5<tBalles[cballe].x+10)&&(tBalles[cballe].x+10<bx+105)){
        	tBalles[cballe].r++;
        	bPoint[i][j].brique=0;
        	tot--;
        	animx=bx;
        	animy=by;
        	compteurA = 1;
        	bruit_briques();

        	if ((bPoint[i][j].b>=1)){
          	bPoint[i][j].b=-bPoint[i][j].b;
          	bPoint[i][j].y=by;
          	bPoint[i][j].x=bx;
        	}
      	}
      	else if ((by-5<tBalles[cballe].y+10)&&(tBalles[cballe].y+10<by+25)&&(bx+95<tBalles[cballe].x)&&(tBalles[cballe].x<bx+105)){
        	tBalles[cballe].c=tBalles[cballe].c+1;//rebond horizontal
        	bPoint[i][j].brique=0;
        	tot--;
        	animx=bx;
        	animy=by;
        	compteurA = 1;
        	bruit_briques();

        	if ((bPoint[i][j].b>=1)){
          	bPoint[i][j].b=-bPoint[i][j].b;
          	bPoint[i][j].y=by;
          	bPoint[i][j].x=bx;
        	}
      	}
      	else if ((by-5<tBalles[cballe].y+10)&&(tBalles[cballe].y+10<by+25)&&(bx-5<tBalles[cballe].x+10)&&(tBalles[cballe].x+10<bx+5)){
        	tBalles[cballe].c++;
        	bPoint[i][j].brique=0;
        	tot--;
        	animx=bx;
        	animy=by;
        	compteurA = 1;
        	bruit_briques();

        	if ((bPoint[i][j].b>=1)){
          	bPoint[i][j].b=-bPoint[i][j].b;
          	bPoint[i][j].y=by;
          	bPoint[i][j].x=bx;
        	}
      	}
    	}
    	if (bPoint[i][j].brique>1 && bPoint[i][j].brique<10){
      	sprite(bx,by,"sprites/brique2.2.bmp");
      	if ((by+15<tBalles[cballe].y)&&(tBalles[cballe].y<by+25)&&(bx<tBalles[cballe].x+10)&&(tBalles[cballe].x+10<bx+100)){
        	tBalles[cballe].r++;
        	bPoint[i][j].brique--;
      	}
      	else if ((by-5<tBalles[cballe].y+20)&&(tBalles[cballe].y+20<by+5)&&(bx<tBalles[cballe].x+10)&&(tBalles[cballe].x+10<bx+100)){
        	tBalles[cballe].r++;
        	bPoint[i][j].brique--;
      	}
      	else if ((by<tBalles[cballe].y+10)&&(tBalles[cballe].y+10<by+20)&&(bx+95<tBalles[cballe].x)&&(tBalles[cballe].x<bx+105)){
        	tBalles[cballe].c++;
        	bPoint[i][j].brique--;
      	}
      	else if ((by<tBalles[cballe].y+10)&&(tBalles[cballe].y+10<by+20)&&(bx-5<tBalles[cballe].x+20)&&(tBalles[cballe].x+20<bx+5)){
        	tBalles[cballe].c++;
        	bPoint[i][j].brique--;
      	}
    	}
    	if (bPoint[i][j].brique==10){
      	changeColor(15,95,7);
      	drawRect(bx, by, 100, 20);
      	if ((by+15<tBalles[cballe].y)&&(tBalles[cballe].y<by+25)&&(bx<tBalles[cballe].x+10)&&(tBalles[cballe].x+10<bx+100)){
        	tBalles[cballe].r++;
        	bPoint[i][j].brique=0;
      	}
      	else if ((by-5<tBalles[cballe].y+20)&&(tBalles[cballe].y+20<by+5)&&(bx<tBalles[cballe].x+10)&&(tBalles[cballe].x+10<bx+100)){
        	tBalles[cballe].r++;
        	bPoint[i][j].brique=0;
      	}
      	else if ((by<tBalles[cballe].y+10)&&(tBalles[cballe].y+10<by+20)&&(bx+95<tBalles[cballe].x)&&(tBalles[cballe].x<bx+105)){
        	tBalles[cballe].c++;
        	bPoint[i][j].brique=0;
      	}
      	else if ((by<tBalles[cballe].y+10)&&(tBalles[cballe].y+10<by+20)&&(bx-5<tBalles[cballe].x+20)&&(tBalles[cballe].x+20<bx+5)){
        	tBalles[cballe].c++;
        	bPoint[i][j].brique=0;
      	}
    	}
    	bx=bx+105;
  	}
  	by=by+25;
	}
	if (tot==0){
  	endw =1;
	}
  }
}
void animbriques(){
  sprintf(animationA, "sprites/animation1/cb%d.bmp", compteurA);
  sprite(animx, animy, animationA);
  compteurA++;
  if (compteurA > 9) {
	compteurA = 1;
	animx=100000;
	animy=100000;

  }
}
void raquette(){
  drawRect(x,y,t,10);
  for(cballe=0;cballe<20;cballe++){
  if((y-10<tBalles[cballe].y)&&(tBalles[cballe].y<y+5)){
	if((x<tBalles[cballe].x+10)&&(tBalles[cballe].x+10<x+(t/3))){
	tBalles[cballe].r=1;

  	if (tBalles[cballe].c%2==0){
    	pvy=1;}
  	else{
    	pvy=3;}
	}
	if(((x+(t/3))<tBalles[cballe].x+10)&&(tBalles[cballe].x+10<x+(t*2/3))){
	tBalles[cballe].r=1;
  	pvy=2;
	}
	if((x+(t*2/3)<tBalles[cballe].x+10)&&(tBalles[cballe].x+10<x+t)){
	tBalles[cballe].r=1;
  	if (tBalles[cballe].c%2==0){
    	pvy=3;}
  	else{
    	pvy=1;}
	}
  }
  }
}
void balle(){
  for(cballe=0;cballe<20;cballe++){
  if(tBalles[cballe].actif==0){
	ballevide=cballe;
  }
  if(tBalles[cballe].actif==1){
  if(stop==-1){
	if(manche<6){
  if (tBalles[cballe].c%2==0){

	tBalles[cballe].x=tBalles[cballe].x+3+v+pvy;
  }
  if (tBalles[cballe].c%2==1){
	tBalles[cballe].x=tBalles[cballe].x-3-v-pvy;
  }
  }
  if ( tBalles[cballe].r%2==0 ){
	tBalles[cballe].y=tBalles[cballe].y+6+v;
  }
  if ((tBalles[cballe].r%2==1)){
	tBalles[cballe].y=tBalles[cballe].y-6-v;
  }}
  sprite(tBalles[cballe].x-10,tBalles[cballe].y-10,"sprites/balle.bmp");
  }
  if(tBalles[cballe].actif ==-1){
	tBalles[cballe].y=y-10;
	tBalles[cballe].x=x+t/2;
 	sprite(tBalles[cballe].x-10,tBalles[cballe].y-10,"sprites/balle.bmp");
  }
  if (tBalles[cballe].y>660){
  	tBalles[cballe].actif =0;
   	tBalles[cballe].x = -1000;
   	tBalles[cballe].y = -1000;
  	tBalles[cballe].c = 0;
  	tBalles[cballe].r = 0;
  	nballe--;
  }
  if(nballe==0){
	if (vies>3){
  	tabvies[vies]=0;
	}
	vies--;
	nballe++;
	tBalles[1].actif =-1;
  }
  }
}
void init_game(){
  srand(time(NULL));
  v=0;
  t =100;
  endw = 0;
  nballe=1;
  for (i=0;i<9;i++){
	for (j=0;j<6;j++){
	bPoint[i][j].b=0;

	}
  }
  for (i=0;i<9;i++){
	for (j=0;j<6;j++){
	bPoint[i][j].brique=0;

	}
  }
  for (i=0;i<=20;i++){
	tBalles[i].x = -1000;
	tBalles[i].y = -1000;
	tBalles[i].actif =0;
	tBalles[1].actif =-1;
  }
  if (manche==1){
	tot=15;
	manche_1();
  }
  if (manche==2){
	tot=20;
	manche_2();
  }
  if (manche==3){
	tot=20;
	manche_3();
  }
  if (manche==4){
	tot=150;
	manche_boss();
  }
  if (manche==5){
	tot=8;
	manche_tuto();
  }
}
void mouvement() {
  if (qa) {
	if (x>20){
	x=x-15;
	}
  }
  if (da) {
	if (x+t<670){
	x=x+15;
	}
  }
}
void drawGame(){

  srand(time(NULL));
  clear();
  cadre();
  balle();
  vie();
  raquette();
  if (manche==5){
	boss();
  }
   if (manche==6){
	tuto();
   }
  briques();
  mouvement();
  bonus();
  animbriques();
  printf("%d\n",menu);
  actualize();
  usleep(1000000 / FPS);
  clear();
  mousex=0;
  mousey=0;
}
void KeyPressed(SDL_Keycode touche){
	/** @brief event.key.keysym.sym renvoi la touche appuyé
 	*
 	*/
	switch (touche) {
    	// Voir doc SDL_Keycode pour plus de touches https://wiki.libsdl.org/SDL_Keycode
    	// ici exemple ou appuyer sur les touches Q | D modifie x (position du carré dans drawGame())
    	case SDLK_q:
        	if (menu<5){
      	if(stop==-1){
       	qa = 1;}}
        	break;
    	case SDLK_d:
        	if (menu<5){
      	if(stop==-1){
       	da = 1;
      	}
      	}
        	break;
        	case SDLK_z:
          	for(i=1;i<20;i++)
          	if (tBalles[i].actif ==-1){
              	tBalles[i].actif =1;
          	}
        	break;
    	case SDLK_SPACE:
       	stop=-stop;
        	break;
        	case SDLK_n:
          	if (menu<4){
          	menu++;
              	for (i=0;i<8;i++){
                	for (j=0;j<5;j++){
                  	bPoint[i][j].brique=0;}}

          	}
                	break;
    	default:
        	break;

	}
}
void KeyDepressed(SDL_Keycode touche){
  switch (touche) {

    	case SDLK_q:

       	qa = 0;


        	break;
    	case SDLK_d:

       	da = 0;


        	break;

	}
}
void gameLoop() {
programLaunched = 1;
	while (programLaunched == 1) {
    	// Boucle pour garder le programme ouvert
    	// lorsque programLaunched est different de 1
    	// on sort de la boucle, donc de la fonction
    	SDL_Event event;
    	while (SDL_PollEvent(&event)) {
        	// boucle pour la gestion d'évenement
        	switch (event.type) {
            	/** event.type renvoi le type d'evenement qui se passe
             	* (si on appuie sur une touche, clique de souris...)
             	* en fonction du type d'évènement on à alors
             	* différentes information accessibles
             	* voir doc pour plus d'event https://wiki.libsdl.org/SDL_EventType
             	*/
            	case SDL_QUIT:
                	// quand on clique sur fermer la fénêtre en haut à droite
                	programLaunched = 0;
                	break;
            	case SDL_MOUSEBUTTONUP:
                	/* clique de la souris
                 	* event.motion.y | event.motion.x pour les positions de la souris
                 	*/
                	mousex=0;
                	mousey=0;
                	mousex=event.motion.x;
                	mousey=event.motion.y;
                	printf("position de la souris x : %d , y : %d\n", mousex, mousey);
                	break;
            	case SDL_KEYDOWN:
                	KeyPressed(event.key.keysym.sym);
                	break;
            	case SDL_JOYBUTTONDOWN:

                	break;
            	case SDL_KEYUP:
                	KeyDepressed(event.key.keysym.sym);
                	break;
            	default:
                	break;

        	}
    	}
//      	coder ici pour que le code s'execute après chaque évenement
//      	* exemple dessiner un carré avec position int x, int y qu'on peut
//      	* deplacer lorsqu'on appuie sur une touche
//
    	switch (menu){
      	case 0:
         	draw_menu();

        	break;

      	case 1:
         	if (manche==1){
        	init_game();}
         	manche=2;

        	drawGame();
         	if (endw==1){
           	menu=20;
         	}
         	if(vies==0){
           	menu=9;}
         	break;

      	case 2:
        	if (manche==2){
        	init_game();}
         	manche=3;

        	drawGame();
         	if (endw==1){
           	menu=30;
         	}
         	if(vies==0){
           	menu=9;}
         	break;
      	case 3:
        	if (manche==3){
        	init_game();}
         	manche=4;

        	drawGame();
         	if (endw==1){
           	menu=40;
         	}
         	if(vies==0){
           	menu=9;}
         	break;

      	case 4:
        	if (manche==4){
        	init_game();}
         	manche=5;

        	drawGame();
         	if (endw==1){
           	menu=50;
         	}
         	if(vies==0){
           	menu=9;}
         	break;
      	case 5:
        	if (manche==5){
        	init_game();}
          	manche=6;

        	drawGame();
         	if (endw==1){
           	menu=0;
         	}

           	break;
          	case 9:
         	draw_loose();

        	break;
      	case 20:
          	next_lvl();
      	break;

      	case 30:
          	next_lvl();
      	break;

      	case 40:
          	next_lvl();
      	break;

      	case 50:
          	next_lvl();
      	break;
  	}

	}
}

int main(){
	/** @description 3 fonctions dans le main qui permettent de créer l'application et la maintenir ouverte :
 	*  init(...) : initialiser la SDL/ fenêtre
 	*  gameLoop() : boucle de jeu dans laquelle l'application reste ouverte
 	*  freeAndTerminate() : quitte le programme proprement
 	*/


  init(WINDOW_WIDTH, WINDOW_HEIGHT);
  audioLoadAndPlay("sdl_helper/sound/fond.wav", 1);
  gameLoop();

  printf("Fin du programme\n");
  freeAndTerminate();
}



