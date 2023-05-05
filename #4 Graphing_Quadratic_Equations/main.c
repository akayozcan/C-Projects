#include <stdio.h>

void write_file(FILE*fptr,int a,int b,int c); //prints the coefficients we get from the user to the file
void draw_the_graph(FILE *fptr);	//first reads the coefficients from the file and then plots the graph based on these values
void print_the_graph(FILE *fptr,FILE* fgraph);//function that prints coordinate system to file
void white();//color functions...
void blue();
void yellow();
void reset ();//color reset function...

int main(){

    FILE*file;
    FILE*file_graph;
    int selection=1,a,b,c;
	
    while(selection!=4){
        printf("\n1 -> Enter the coefficients.\n");		//menu
        printf("2 -> Draw the graph.\n");
        printf("3 -> Print the graph into a.txt file.\n");
        printf("4 -> Exit.\n");
        printf("\nChoice:");
        scanf("%d",&selection);
        switch(selection){
            case 1:
                printf("Please enter the coefficient for the following equation: x=a(y*y) + b*y +c\n");
                printf("a:");
                scanf("%d",&a);
                printf("b:");
                scanf("%d",&b);
                printf("c:");
                scanf("%d",&c);
                write_file(file,a,b,c);
                printf("coefficients.txt file has been created.\n");
                break;
            
            case 2:
                draw_the_graph(file);
                break;

            case 3:
                print_the_graph(file,file_graph);
                break;
        }
    }


    return 0;
}

void write_file(FILE*fptr,int a,int b,int c){//prints the coefficients we get from the user to the file
    fptr = fopen("coefficients.txt","w");
    if(fptr == NULL){
        printf("File cannot open!");
    }
    fprintf(fptr,"%d\n%d\n%d",a,b,c);
    fclose(fptr);
}

void draw_the_graph(FILE *fptr){//first reads the coefficients from the file and then plots the graph based on these values
    int a,b,c;
    int i,j,equetion;
    fptr=fopen("coefficients.txt","r");//open file
    if(fptr == NULL) printf("File cannot open!\n");
    fscanf(fptr,"%d\n%d\n%d",&a,&b,&c);//read file
    fclose(fptr);	//close file

	printf("Coefficients has been read from the coefficient.txt file.\n");
	printf("Printing the graph of x=%d*(y*y) + %d*y +%d\n\n",a,b,c);

	for(i=15;i>=-15;i--){	//loops for drawing elements of the coordinate system
		equetion=(a*i*i) +(b*i)+(c);
		for(j=-55;j<=55;j++){
			if(j==equetion){
				blue();
				printf("#"); //# stands for dots
				reset();
			}
			else if(i==0 && j!=0){
				white();
				if(j==-55 && i!=equetion) printf("<");
				else if(j==55) printf(">");
				else printf("-");
			}
			else if(j==0 && j!=equetion){
				if(i==15) printf("^");
				else printf("|");
				reset();
			}
			else if(i==-1){
				yellow();
				if(j%10==-1){
					if(j==-1){
						printf("0");
					}
				}
				else if(j%10 == 0){
					printf("\b%d",j);
				}
				else{
					printf(" ");
				}
				reset();
			}
			else if(i%5==0 &&j==-1){
				yellow();
				if(i==5) printf("%d",i);
				else if(i==-5) printf("\b%d",i);
				else if(i>5) printf("\b%d",i);
				else printf("\b\b%d",i);
				reset();
			}
			else{
				printf(" ");
			}
		}	
		printf("\n");
	}
}

void print_the_graph(FILE *fptr,FILE *fgraph){//function that prints coordinate system to file
    int a,b,c;
    int i,j,equetion;
    fptr=fopen("coefficients.txt","r");//open first file to read coefficients...
    if(fptr == NULL) printf("File cannot open!\n");
    fscanf(fptr,"%d\n%d\n%d",&a,&b,&c);
    fclose(fptr);
    fgraph=fopen("graph.txt","w");//open second file to write graph...
    if(fptr == NULL) printf("File cannot open!\n");
    
	printf("Coefficients has been read from the coefficient.txt file.\n");
	printf("The graph of x=%d*(y*y) + %d*y +%d has been written to graph.txt file.\n\n",a,b,c);

	for(i=15;i>=-15;i--){
		equetion=(a*i*i) +(b*i)+(c);
		for(j=-55;j<=55;j++){
			if(j==equetion){
				fprintf(fgraph,"#");
			}
			else if(i==0 && j!=0){
				if(j==-55 && i!=equetion) fprintf(fgraph,"<");
				else if(j==55) fprintf(fgraph,">");
				else fprintf(fgraph,"-");
			}
			else if(j==0 && j!=equetion){
				if(i==15) fprintf(fgraph,"^");
				else fprintf(fgraph,"|");
			}
			else{
				fprintf(fgraph," ");
			}
		}	
        fprintf(fgraph,"\n");
	}
    fclose(fgraph);
}
void white(){printf("\033[0;37m");} //color functions...
void blue(){printf("\e[0;34m");}
void yellow(){printf("\e[0;33m");}
void reset (){ printf("\033[0m");}// color reset function
