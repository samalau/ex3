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

void _1_enterSingle(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) ;
void _2_enterEvery(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) ;
void _3_dayStat(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES]) ;

// void _4_EntireData() ;
// void _5_simpleInsight() ;
// void _6_avgDelta() ;

int getSum(const int *array, int size) {
	int sum = 0 ;
	for (int i = 0 ; i < size ; i++) {
		for (int j = 0 ; j < size ; j++) {
			for (int k = 0 ; k < size ; k++) {
				sum += array[i] ;
			}
		}
	}
	return sum ;
}

// void getMax() {

// }

void dayCounter(int days[NUM_OF_BRANDS], int* brandIndex) {
	if (brandIndex == NULL) {
		for (int i = 0  ; i < NUM_OF_BRANDS  ; i++) {
			days[i]++ ;  
		}
	} else {
		days[*brandIndex]++ ;
	}
}


void updateCube(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int* brandIndex, int sales[NUM_OF_TYPES]) {
	if (*brandIndex < 0 || *brandIndex > NUM_OF_BRANDS - 1) {
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
	int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES] ;
	int days[NUM_OF_BRANDS] = {0} ;
	int sales[NUM_OF_TYPES] ;
	initCube(cube, -1) ;
	int choice = 0 ;
	while(choice != done) {
		printMenu() ;
		// assumes input positive integer choice
		scanf(" %d", &choice) ;
		switch(choice){
			case done:
				printf("Goodbye!\n") ;
				break ;
			case addOne:
				_1_enterSingle(cube, days, sales) ;
				break ;
			case addAll:
				_2_enterEvery(cube, days, sales) ;
				break ;
			case stats:
				_3_dayStat(cube) ;
				break ;
			case print:
				// _4_EntireData() ;
				break ;
			case insights:
				// _5_simpleInsight() ;
				break ;
			case deltas:
				// _6_avgDelta() ;
				break ;
			default:
				printf("Invalid input\n") ;
		}
		char c ;
		while ((c = getchar()) != '\n' && c != EOF) ;
	}
	printf("Goodbye!\n") ;
	return 0 ;
}


void _1_enterSingle(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) {
	int brandIndex ;
	printf("Enter the sales data for a single brand on a single day:\n") ;
	scanf(" %d", &brandIndex) ;
	for (int typeIndex = 0 ; typeIndex < NUM_OF_TYPES ; typeIndex++) {
		scanf(" %d", &sales[typeIndex]) ;
	}
	updateCube(cube, days, &brandIndex, sales) ;
	dayCounter(days, &brandIndex) ;
}


int brandsPopulated(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) {
	int complete = 1 ;
	for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
		if (days[i] < DAYS_IN_YEAR - 1 && cube[days[i]][i][0] == -1) {
			if (complete) {
				printf("No data for brands") ;
			}
			printf(" %s", brands[i]) ;
			complete = 0 ;
		}
	}
	printf("\nPlease complete the data\n") ;
	return complete ;
}


void _2_enterEvery(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) {
	int brandIndex ;
	while (!brandsPopulated(cube, days)) {
		if (scanf(" %d", &brandIndex) == 1) {
			for (int typeIndex = 0 ; typeIndex < NUM_OF_TYPES ; typeIndex++) {
				scanf(" %d", &sales[typeIndex]) ;
			}
			updateCube(cube, days, &brandIndex, sales) ;
		}
	}
	dayCounter(days, NULL) ;
}


void _3_dayStat(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES]) {
	int c, yom ;
	int display = 0 ;
	printf("What day would you like to analyze?\n");
	while (!display) {
		if (scanf(" %d", &yom) == 1 && yom >= 0 && yom < DAYS_IN_YEAR) {
			int sum = 0 ;
			for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
				if (i != -1) {
					for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
						if (i != -1) {
							sum += cube[yom][i][j] ;
						}
					}
				}
			}
			printf("sum is %d\n", sum) ;
			//getSum(cube[yom], )
		} else {
			while ((c = getchar()) != '\n' && c != EOF) ;
			printf("Please enter a valid day\n"
					"Which day would you like to analyze?\n") ;
			continue ;
		}
	}

}


// void _4_EntireData() {}

// void _5_simpleInsight() {}

// void _6_avgDelta() {}
