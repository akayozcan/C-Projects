#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 15
#define COL 15
#define YEL "\e[0;33m"//color codes...
#define BLU "\e[0;34m"
#define CYN "\e[0;36m"
#define reset "\e[0m"//reset color...

void random_word(char word[5]);// This function chooses random world from  wordlist
void fill_puzzle_randomly(char puzzle[ROW][COL]);//This fills the empty spaces in the puzzle area with random letters
void print_puzzle(char puzzle[ROW][COL]);//print puzzle game on the screen
void add_word_puzzle(char puzzle[ROW][COL],int direct[ROW][COL]);//Add words randomly to the table horizontlly,vertically or diagonaly
int check_word(char puzzle[ROW][COL],int direct[ROW][COL],int row,int col,char str[10]);//Checks if the word entered by the user is the same as the word in the puzzle

int main(){

    char puzzle[ROW][COL]={"\0"};//{"\0"} fill all of the spaces with null...
    int direct[ROW][COL]={0};//{0} fill all of the spaces with 0...
    int i,j,input_row,input_col,lenght,point=0,count_mistake=0;
    char input_str[10];
    srand(time(NULL));

    printf(CYN"\n=== Welcome the PUZZLE GAME ===\n\n"reset);

    for(i=0;i<7;i++){
        add_word_puzzle(puzzle,direct);//add 7 word in the puzzle
    }
    fill_puzzle_randomly(puzzle);
    print_puzzle(puzzle);

    do{
        printf(YEL"Enter word and coordinates(row,col):"reset);
        scanf("%s",input_str);
        if(input_str[0] == ':' && input_str[1]=='q') break;//if user enter :q chctr ,game will over.
        else scanf("%d %d",&input_row,&input_col);

        if(check_word(puzzle,direct,input_row,input_col,input_str)==1 && direct[input_row][input_col] !=0){
            point+=2;
            printf(BLU"Founded!You got 2 points.Your total points %d.\n"reset,point);
        }
        else{
            count_mistake++;
            printf(BLU"Wrong choice! You have only %d lefts.\n"reset,3-count_mistake);
        }
        print_puzzle(puzzle);

    }while(point !=14 && count_mistake !=3);//ends the game when the score is 14 or the number of errors is 3.

    if(point==14) printf("\nCongratulations you won the Puzzle Game! :) \n");
    else if(count_mistake==3) printf("\nYour wrong right is over play again :( \n");
    else printf("\nExiting the Puzzle Game!\n");

    return 0;
}

void random_word(char word[5]){// This function chooses random world from  wordlist
    FILE*file;
    int rand_word;
    rand_word=rand()%50+1;
    
    file=fopen("wordlist.txt","r");
    if(file==NULL) printf("File cannot open!\n");
    
    for(int j=0;j<rand_word;j++){
        fscanf(file,"%s",word);
    }
    fclose(file);
}

void fill_puzzle_randomly(char puzzle[ROW][COL]){//This fills the empty spaces in the puzzle area with random letters
    int i,j;
    char randchr;

    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            randchr='z'-rand()%26;
            if(puzzle[i][j] == '\0') puzzle[i][j]=randchr;
        }
    }
}

void print_puzzle(char puzzle[ROW][COL]){//print puzzle game on the screen
    int i,j;
    printf("\n");
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(puzzle[i][j]=='X') printf(YEL"%c "reset,puzzle[i][j]);//print X chr as yellow 
            else printf("%c ",puzzle[i][j]);
        }
        printf("\n");
    }
}

void add_word_puzzle(char puzzle[ROW][COL],int direct[ROW][COL]){//Add words randomly to the table horizontlly,vertically or diagonaly
    char word[5]={"\0"};
    int word_index[7]={0};//the word index enumerates the order in which words are vertically,up or down,diagonally
    int i,j,lenght,count=0,rand_direction,rand_row,rand_col;//For example -> 1 / <-2 / ^ 3 / 
                                                            //                         |
    rand_direction=rand()%8+1;//Randomly determines which direction the word goes...
    random_word(word);
    lenght=strlen(word);

    switch(rand_direction){
        case 1://places the word from left to right
            do{
                count=0;
                rand_row=rand()%15;
                rand_col=rand()%10+1;
                for(i=0;i<lenght;i++){
                    if(puzzle[rand_row][rand_col+i] != '\0') count++;//if there is another word in the field where the word
                }                                                //will be added,it randomly places it in a new empty place
            }while(count != 0);
            direct[rand_row][rand_col]=1;
            for(i=0;i<lenght;i++){
                puzzle[rand_row][rand_col+i]=word[i];
            }
            break;
        case 2://places the word from right to left
            do{
                count=0;
                rand_row=rand()%15;
                rand_col=rand()%11+4;
                for(i=0;i<lenght;i++){
                    if(puzzle[rand_row][rand_col-i] != '\0') count++;
                }
            }while(count != 0);
            direct[rand_row][rand_col]=2;
            for(i=0;i<lenght;i++){
                puzzle[rand_row][rand_col-i]=word[i];
            }
            break;
        case 3://places the word from up to down
            do{
                count=0;
                rand_row=rand()%10+1;
                rand_col=rand()%15;
                for(i=0;i<lenght;i++){
                    if(puzzle[rand_row+i][rand_col] != '\0') count++;
                }
            }while(count != 0);
            direct[rand_row][rand_col]=3;
            for(i=0;i<lenght;i++){
                puzzle[rand_row+i][rand_col]=word[i];
            }
            break;
        case 4://places the word from down to up
            do{
                count=0;
                rand_row=rand()%11+4;
                rand_col=rand()%15;
                for(i=0;i<lenght;i++){
                    if(puzzle[rand_row-i][rand_col] != '\0') count++;
                }
            }while(count != 0);
            direct[rand_row][rand_col]=4;
            for(i=0;i<lenght;i++){
                puzzle[rand_row-i][rand_col]=word[i];
            }
            break;
        case 5://sağ çarpraz üst
            do{
                count=0;
                rand_row=rand()%10+1;
                rand_col=rand()%11+4;
                for(i=0;i<lenght;i++){
                    if(puzzle[rand_row+i][rand_col-i] != '\0') count++;
                }
            }while(count != 0);
            direct[rand_row][rand_col]=5;
            for(i=0;i<lenght;i++){
                puzzle[rand_row+i][rand_col-i]=word[i];
            }
            break;
        case 6://sağ çapraz alt
            do{
                count=0;
                rand_row=rand()%11+4;
                rand_col=rand()%10+1;
                for(i=0;i<lenght;i++){
                    if(puzzle[rand_row-i][rand_col+i] != '\0') count++;
                }
            }while(count != 0);
            direct[rand_row][rand_col]=6;
            for(i=0;i<lenght;i++){
                puzzle[rand_row-i][rand_col+i]=word[i];
            }
            break;
        case 7://sol çapraz alt
            do{
                count=0;
                rand_row=rand()%10+1;
                rand_col=rand()%10+1;
                for(i=0;i<lenght;i++){
                    if(puzzle[rand_row+i][rand_col+i] != '\0') count++;
                }
            }while(count != 0);
            direct[rand_row][rand_col]=7;
            for(i=0;i<lenght;i++){
                puzzle[rand_row+i][rand_col+i]=word[i];
            }
            break;
        case 8://sol çapraz ust
            do{
                count=0;
                rand_row=rand()%11+4;
                rand_col=rand()%11+4;
                for(i=0;i<lenght;i++){
                    if(puzzle[rand_row-i][rand_col-i] != '\0') count++;
                }
            }while(count != 0);
            direct[rand_row][rand_col]=8;
            for(i=0;i<lenght;i++){
                puzzle[rand_row-i][rand_col-i]=word[i];
            }
            break;//Since there are 8 sides in total,I opened 8 switch case statement and placed the words according to the random value.
    }       
    printf("Word:%5s  R:%2d  C:%2d\n",word,rand_row,rand_col);
}

int check_word(char puzzle[ROW][COL],int direct[ROW][COL],int row,int col,char str[10]){//Checks if the word entered by the user is the same as the word in the puzzle
    int selection=direct[row][col];
    int i,j,lenght,count=0,r=1;
    lenght=strlen(str);
    switch(selection){//İf the word entered by the user and the word in the puzzle are the same,
        case 1:       //it accepts it as correct and replaces the word with an X.
            for(i=0;i<lenght;i++){
                if(puzzle[row][col+i]!=str[i]) count++;
            }
            if(count==0){
                for(i=0;i<lenght;i++){
                    puzzle[row][col+i]='X';
                }
            }
            else r=0;
            break;

        case 2:
            for(i=0;i<lenght;i++){
                if(puzzle[row][col-i]!=str[i]) count++;
            }
            if(count==0){
                for(i=0;i<lenght;i++){
                    puzzle[row][col-i]='X';
                }
            }
            else r=0;
            break;

        case 3:
            for(i=0;i<lenght;i++){
                if(puzzle[row+i][col]!=str[i]) count++;
            }
            if(count==0){
                for(i=0;i<lenght;i++){
                    puzzle[row+i][col]='X';
                }
            }
            else r=0;
            break;

        case 4:
            for(i=0;i<lenght;i++){
                if(puzzle[row-i][col]!=str[i]) count++;
            }
            if(count==0){
                for(i=0;i<lenght;i++){
                    puzzle[row-i][col]='X';
                }
            }
            else r=0;
            break;

        case 5:
            for(i=0;i<lenght;i++){
                if(puzzle[row+i][col-i]!=str[i]) count++;
            }
            if(count==0){
                for(i=0;i<lenght;i++){
                    puzzle[row+i][col-i]='X';
                }
            }
            else r=0;
            break;

        case 6:
            for(i=0;i<lenght;i++){
                if(puzzle[row-i][col+i]!=str[i]) count++;
            }
            if(count==0){
                for(i=0;i<lenght;i++){
                    puzzle[row-i][col+i]='X';
                }
            }
            else r=0;
            break;
        
        case 7:
            for(i=0;i<lenght;i++){
                if(puzzle[row+i][col+i]!=str[i]) count++;
            }
            if(count==0){
                for(i=0;i<lenght;i++){
                    puzzle[row+i][col+i]='X';
                }
            }
            else r=0;
            break;

        case 8:
            for(i=0;i<lenght;i++){
                if(puzzle[row-i][col-i]!=str[i]) count++;
            }
            if(count==0){
                for(i=0;i<lenght;i++){
                    puzzle[row-i][col-i]='X';
                }
            }
            else r=0;
            break;
    }
    return r;
}