#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLK "\e[0;30m"//color codess
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define reset "\e[0m"

char gameArea[15][30];//our area array

int dice();//Gets a random dice value from 1 to 6
int startGame();//determines who starts the game
void createMap(char area[15][30]);//creates the field before the game starts
void printMap(char area[15][30]);//prints the field to the screen in the terminal
int check_game_over(char area[15][30]);//checks if the game is over
void playGame(char area[15][30],int start);//Function where 1st and 2nd players play the game by rolling the dice

int main(){

    int who_start;//determines who starts
    srand(time(NULL));
    who_start = startGame();
    createMap(gameArea);//creates the field before the game starts
    playGame(gameArea,who_start);//the field that play game...

    return 0;
}

int dice(){//Gets a random dice value from 1 to 6
    int random = rand()%6+1;
    return random;
}
int startGame(){
    int count=0,dice1,dice2;
    do{
        if(count==0) printf("To start to game,players should dice and decide who is going to start first acording to it...\n");
        else printf("Same dice value... Please try again.\n");//If the same value comes up, the dice are rolled again.

        printf(YEL"PLAYER 1...press ENTER to dice"reset);//YEL and reset to paint the screen YEL-yellow
        getchar();//to enter
        dice1=dice();
        printf(YEL"DICE:%d\n"reset,dice1);

        printf(BLU"PLAYER 2...press ENTER to dice"reset);//BLU and reset to paint the screen BLU-blue
        getchar();
        dice2=dice();
        printf(BLU"DICE:%d\n"reset,dice2);
        count++;
    }while(dice1 == dice2);

    if(dice1>dice2) return 1;//return bigger dice value
    else return 2;
}
void createMap(char area[15][30]){//creates the lines that will form the area
    int i,j;
    for(i=0;i<15;i++){
        for(j=0;j<30;j++){
            if((j==0 || j==29) && i!=0 && i!=14) area[i][j]=':';
            else if(i==0 || i==14) area[i][j]='.';
            else if((i==2 ||i==12) && 2<=j && j<=27) area[i][j]='.';
            else if((i==4 || i==10) && 4<=j && j<=25) area[i][j]='.';
            else if((j==2 || j==27) && 3<=i && i<=11) area[i][j]=':';
            else if((j==4 || j==25) && 5<=i && i<=9) area[i][j]=':';
            else area[i][j]=' ';
        }
    }
    //creates other elements in the field
    area[1][14]='X';area[7][28]='X';area[1][14]='X';area[13][14]='X';
    area[3][10]='X';area[3][18]='X';area[5][26]='X';area[10][26]='X';area[11][1]='X';area[11][18]='X';
    area[2][1]='_';area[4][3]='_';
    area[1][1]='1';area[3][3]='2';
}

void printMap(char area[15][30]){//prints the field to the screen in the terminal
    int i,j;
    for(i=0;i<15;i++){
        for(j=0;j<30;j++){
            if(area[i][j] == 'X') printf(RED"%c"reset,area[i][j]);
            else if(area[i][j] == '_') printf(GRN"%c"reset,area[i][j]);
            else if(area[i][j] == '1') printf(YEL"%c"reset,area[i][j]);
            else if(area[i][j] == '2') printf(BLU"%c"reset,area[i][j]);
            else printf("%c",area[i][j]);
        }
        printf("\n");
    }
}
int check_game_over(char area[15][30]){//eğer oyuncu başlangıçtaki konumuna yada çizgiye ulaşırsa oyunu bitirir
    int r=0;
    if(area[1][1]=='1'){
        printf("1.Player WON the GAME!!\n");
        r=1;
    }
    if(area[3][3]=='2'){
        printf("2.Player WON the GAME!!\n");
        r=1;
    }
    return r;
}
void playGame(char area[15][30],int start){

    int dice1,dice2,i,tur=0,kalan,count=1,count1=1,count2=1,count3=1;
    int c=3,c1=3,c2=3,c3=1,k1,tur2=0;

    printMap(area);
    if(start==1) printf("*** PLAYER 1 will start the game... ***\n");
    else printf("*** PLAYER 2 will start the game... ***\n");
   
    do{
        if(start==1){//dice are rolled according to the first starting order
            printf(YEL"\nPLAYER 1...press ENTER to dice"reset);
            getchar();
            dice1=dice();
            printf(YEL"DICE:%d\n"reset,dice1);

            printf(BLU"PLAYER 2...press ENTER to dice"reset);
            getchar();
            dice2=dice();
            printf(BLU"DICE:%d\n"reset,dice2);
        }
        else{
            printf(BLU"PLAYER 2...press ENTER to dice"reset);
            getchar();
            dice2=dice();
            printf(BLU"DICE:%d\n"reset,dice2);

            printf(YEL"\nPLAYER 1...press ENTER to dice"reset);
            getchar();
            dice1=dice();
            printf(YEL"DICE:%d\n"reset,dice1);
        }
        if(tur==0){//moves 1 from left to right
            count+=dice1;
            if(count>28){
                kalan=count-28;
                area[1+kalan][28]='1';
                area[1][28+kalan-dice1]=' ';
                count1+=kalan;
            }
            if(area[1][count] == ' '){
                area[1][count]='1';
                area[1][count-dice1]=' ';
            }
            if(area[1][count] == 'X'){
                if(area[1][count-2]!='1'){
                    area[1][count-2]='1';
                    area[1][count-dice1]=' ';
                }
                count-=2;
            }
        }

        if(tur==1){//moves 1 from up to down
            count1+=dice1;
            if(count1>13){
                kalan=count1-13;
                area[13][28-kalan]='1';
                area[13+kalan-dice1][28]=' ';
                count2+=kalan;
            }
            if(area[count1][28] == ' '){
                area[count1][28]='1';
                area[count1-dice1][28]=' ';
            }
            if(area[count1][28] == 'X'){
                if(area[count1-2][28]!='1'){
                    area[count1-2][28]='1';
                    area[count1-dice1][28]=' ';
                } 
                  count1-=2;
            }
        }

        if(tur==2){//moves 1 from right  to left
            count2+=dice1;
            if(count2>28){
                kalan=count2-28;
                area[13-kalan][1]='1';
                area[13][1-kalan+dice1]=' ';
                count3+=kalan;
            }
            if(area[13][29-count2] == ' '){
                area[13][29-count2]='1';
                area[13][29+(dice1-count2)]=' ';
            }
            if(area[13][29-count2] == 'X'){
                if(area[13][29-count2+2]!='1'){
                    area[13][29-count2+2]='1';
                    area[13][29+(dice1-count2)]=' ';
                }
                count2-=2;
            }
        }
        
        if(tur==3){//moves 1 from down to up
            count3+=dice1;
            if(count3>=12){
                area[1][1]='1';
                area[14-(count3-dice1)][1]=' ';
            }
            if(area[14-count3][1] == ' '){
                area[14-count3][1]='1';
                area[14-(count3-dice1)][1]=' ';
            }
            if(area[14-count3][1] == 'X'){
                if(area[14-count3+2][1]!='1'){
                    area[14-count3+2][1]='1';
                    area[14-(count3-dice1)][1]=' ';
                }
                count3-=2;
            }
        }

        if(count>28){//increase tur by 1
            tur++;
            count=0;
        }
        if(count1>13){
             tur++;
             count1=0;
        }
         if(count2>28){
            tur++;
            count2=0;
        }
        //-----------------------------------------------------------------------------
        if(tur2==0){//moves 2 from left to right
            c+=dice2;
            if(c>26){
                k1=c-26;
                if(area[3+k1][26]=='X'){
                    area[3+k1-2][26]='2';
                    area[3][26+k1-dice2]=' '; 
                    k1-=2;
                }
                else{
                    area[3+k1][26]='2';
                    area[3][26+k1-dice2]=' ';
                }
                c1+=k1;
            }
            if(area[3][c] == ' '){
                area[3][c]='2';
                area[3][c-dice2]=' ';
            }
            if(area[3][c] == 'X'){
                if(area[3][c-2]!='2'){
                    area[3][c-2]='2';
                    area[3][c-dice2]=' ';
                }
                c-=2;
            }
        }
        if(tur2==1){//moves 2 from up to down
            c1+=dice2;
            if(c1>=10){
                k1=c1-11;
                area[11][26-k1]='2';
                area[11+k1-dice2][26]=' ';
                c2+=k1;
            }
            if(area[c1][26] == ' '){
                area[c1][26]='2';
                area[c1-dice2][26]=' ';
            }
            if(area[c1][26] == 'X'){
                if(area[c1-2][26]!='2'){
                    area[c1-2][26]='2';
                    area[c1-dice2][26]=' ';
                } 
                c1-=2;
            }
        }
        if(tur2==2){//moves 2 from right to left
            c2+=dice2;
            if(c2>26){
                k1=c2-26;
                area[11-k1][3]='2';
                area[11][3+dice2-k1]=' ';
                c3+=k1;
            }
            if(area[11][29-c2] == ' '){
                area[11][29-c2]='2';
                area[11][29+(dice2-c2)]=' ';
            }
            if(area[11][29-c2] == 'X'){
                if(area[11][29-c2+2]!='2'){
                    area[11][29-c2+2]='2';
                    area[11][29+(dice2-c2)]=' ';
                }
                c2-=2;
            }
        }
        if(tur2==3){//moves 2 from down to up
            c3+=dice2;
            if(c3>=10){
                area[3][3]='2';
                area[12-(c3-dice2)][3]=' ';
            }
            if(area[12-c3][3] == ' '){
                area[12-c3][3]='2';
                area[12-(c3-dice2)][3]=' ';
            }
            if(area[12-c3][3] == 'X'){
                if(area[12-c3+2][3]!='2'){
                    area[12-c3+2][3]='2';
                    area[12-(c3-dice2)][3]=' ';
                }
                c3-=2;
            }
        }
        if(c>26){
            tur2++;
            c=0;
        }
        if(c1>9){
             tur2++;
             c1=0;
        }
         if(c2>26){
            tur2++;
            c2=0;
        } 
        printMap(area);//after every movements print area on screen
     
    }while(check_game_over(area) ==0);//exit the loop when the order to finish the game comes
}
