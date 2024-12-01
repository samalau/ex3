/******************
Name: Samantha Newmark
ID: 346587629
Assignment: ex3
*******************/

#include <stdio.h>

#define NUM_OF_BRANDS 5
#define BRANDS_NAMES 15
#define NUM_OF_TYPES 4
#define TYPES_NAMES 10
#define DAYS_IN_YEAR 365
#define addOne  1
#define addAll  2  
#define stats  3
#define print  4
#define insights  5
#define deltas  6
#define done  7

char brands[NUM_OF_BRANDS][BRANDS_NAMES] = {"Toyoga", "HyunNight", "Mazduh", "FolksVegan", "Key-Yuh"} ;
char types[NUM_OF_TYPES][TYPES_NAMES] = {"SUV", "Sedan", "Coupe", "GT"} ;


void pathOneOne(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) {
	int brandIndex, sales[NUM_OF_TYPES] ;
	printf("") ;
	scanf(" %d", &brandIndex) ;
	for (int typeIndex = 0 ; typeIndex < NUM_OF_TYPES ; typeIndex++) {
		scanf(" %d", &sales[typeIndex]) ;
	}
	updateCube(cube, days, &brandIndex, sales) ;
	dayCounter(days[brandIndex], NULL, NULL) ;
}


void pathTwo() {
	
}

void pathOneOne() {
	
}

void pathOneOne() {
	
}

void pathOneOne() {
	
}

void pathOneOne() {
	
}


void dayCounter(int days[NUM_OF_BRANDS], int* brands, int* brandIndex) {
	if (brandIndex == NULL) {
		for (int i = 0  ; i < NUM_OF_BRANDS  ; i++) {
			days[i]++ ;  
		}
	} else {
		days[brands[*brandIndex]]++ ;
	}
}


void updateCube(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int* brandIndex, int sales[NUM_OF_TYPES]) {
	if (brandIndex == NULL || *brandIndex < 0 || *brandIndex > NUM_OF_BRANDS - 1) {
		printf("This brand is not valid\n") ;
	} else {
		int currentDay = days[*brandIndex] ;
		if (currentDay < DAYS_IN_YEAR) {
			for (int typeIndex = 0 ; typeIndex < NUM_OF_TYPES ; typeIndex++) {
				cube[currentDay][*brandIndex][typeIndex] = sales[typeIndex] ;
			}
		}
		// else {}
	}	
}


void initCube(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int initAsValue) {
	for (int i = 0 ; i < DAYS_IN_YEAR ; i++) {
		for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
			for (int k = 0 ; k < NUM_OF_TYPES ; k++) {
				cube[i][j][k] = initAsValue ;
			}
		}
	}
}


void printMenu(){
	printf("Welcome to the Cars Data Cube! What would you like to do?\n"
		   "1.Enter Daily Data For A Brand\n"
		   "2.Populate A Day Of Sales For All Brands\n"
		   "3.Provide Daily Stats\n"
		   "4.Print All Data\n"
		   "5.Provide Overall (simple) Insights\n"
		   "6.Provide Average Delta Metrics\n"
		   "7.exit\n") ;
}


int main() {
	int brandIndex, typeIndex ;
	int sales[NUM_OF_TYPES]  ;
	int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES] ;
	int days[NUM_OF_BRANDS] = {0} ;
	initCube(cube, -1) ;
	int choice = 0 ;
	while(choice != done){
		switch(choice){
			case done:
				printf("Goodbye!\n") ;
				break ;
			case addOne:
				//...
				break ;
			case addAll:
				//...
				break ;
			case stats:
				//...
				break ;
			case print:
				//...
				break ;
			case insights:
				//...
				break ;
			case deltas:
				//...
				break ;
			default:
				printf("Invalid input\n") ;
		}
		printMenu() ;
		scanf("%d", &choice) ;
	}
	printf("Goodbye!\n") ;
	return 0 ;
}
