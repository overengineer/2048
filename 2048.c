#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "mylib.h"
#define SIZE 4
enum{
	RIGHT, LEFT, UP, DOWN
};
int a[SIZE][SIZE]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
void slide( int );
int main( void )
{
	int i=0,j=0;
	char c;
	int s=1;
	srand( time ( NULL ));

	while(1){
		
	if(s){
		clearScreen();
		while(a[i][j]!=0){
		i=rand()%SIZE;
		j=rand()%SIZE;
	}
	a[i][j]=2;

		for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
		textColor( (int)log2(a[i][j])%7+9 );
		printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}
		s=1;
		c=getch();
				switch(c){
			case 'd':
		slide(RIGHT);
		break;
			case 'a':
		slide(LEFT);
		break;
			case 'w':
		slide(UP);
		break;
			case 's':
		slide(DOWN);
		break;
		default:
		s=0;
		break;
	}
	

	}
}




void slide( int d )
{
	int i,j,k;
	if(d==RIGHT){
	for(k=0; k<SIZE; k++){
	
	for(i=0; i<SIZE; i++){
		for(j=1; j<SIZE; j++){
			if(a[i][j]==a[i][j-1]){
	
			a[i][j]=a[i][j] + a[i][j-1];
			a[i][j-1]=0;
	}
		else if(a[i][j]==0 || a[i][j-1]==0){
			a[i][j]=a[i][j] + a[i][j-1];
				a[i][j-1]=0;
		
	}

		}
	}
}
}
else if(d==LEFT){
	for(k=0; k<SIZE; k++){
	
	for(i=0; i<SIZE; i++){
		for(j=SIZE-1; j>0; j--){
			if(a[i][j]==a[i][j-1]){
	
			a[i][j-1]=a[i][j] + a[i][j-1];
				a[i][j]=0;
		
	}
		else if(a[i][j]==0 || a[i][j-1]==0){
			a[i][j-1]=a[i][j] + a[i][j-1];
				a[i][j]=0;
			
		
	}

		}
	}
}
}

else if(d==UP){
	for(k=0; k<SIZE; k++){
	
	for(j=0; j<SIZE; j++){
		for(i=SIZE-1; i>0; i--){
			if(a[i][j]==a[i-1][j]){
			a[i-1][j]=a[i][j] + a[i-1][j];
			a[i][j]=0;
	
	}
			else if(a[i][j]==0 || a[i-1][j]==0){
			a[i-1][j]=a[i][j] + a[i-1][j];
			a[i][j]=0;	
	}	
			
		}
	}
}
}
else if(d==DOWN){

		for(k=0; k<SIZE; k++){
	for(j=0; j<SIZE; j++){
		for(i=1; i<SIZE; i++){
			if(a[i][j]==a[i-1][j]){
			a[i][j]=a[i][j] + a[i-1][j];
			a[i-1][j]=0;
	
	}
			else if(a[i][j]==0 || a[i-1][j]==0){
			a[i][j]=a[i][j] + a[i-1][j];
			a[i-1][j]=0;	
	}	
			
		}
	}
}
}
}





