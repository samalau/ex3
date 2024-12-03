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

// void getMax() ;

int getSum(const int *array, int size) ;
// void flattenCubeSlice (const int *cube, int specificDay, int brandSize, int typeSize, int *flattened) ;

void updateCube(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int *brandIndex, int sales[NUM_OF_TYPES]) ;

int brandsPopulated(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) ;

void initDays(int days[NUM_OF_BRANDS], int initAsValue) ;
void initSales(int sales[NUM_OF_TYPES], int initAsValue) ; 
void initCube(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int initAsValue) ;

void printMenu() ;

void _1_enterSingle(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) ;
void _2_enterEvery(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) ;
void _3_dayStat(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) ;
void _4_EntireData(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES]) ;

// void _5_simpleInsight() ;
// void _6_avgDelta() ;


// void getMax() {}


int getSum(const int *array, int size) {
	int sum = 0 ;
	for (int i = 0 ; i < size ; i++) {
		if (array[i] != -1) {
			sum += array[i];
		}
	}
	return sum ;
}





void updateCube(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int *brandIndex, int sales[NUM_OF_TYPES]) {
	if (*brandIndex < 0 || *brandIndex > NUM_OF_BRANDS - 1) {
		printf("This brand is not valid\n") ;
	} else {
		if (days[*brandIndex] < DAYS_IN_YEAR - 1) {
			for (int typeIndex = 0 ; typeIndex < NUM_OF_TYPES ; typeIndex++) {
				cube[days[*brandIndex]][*brandIndex][typeIndex] = sales[typeIndex] ;
			}
			days[*brandIndex]++ ;
		}
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


void initSales(int sales[NUM_OF_TYPES], int initAsValue) {
	for (int i = 0 ; i < NUM_OF_TYPES ; i++) {
		sales[i] = -1 ;
	}
}


void initDays(int days[NUM_OF_BRANDS], int initAsValue) {
	for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
		days[i] = -1 ;
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
	int days[NUM_OF_BRANDS] ;
	initDays(days, -1) ;
	int sales[NUM_OF_TYPES] ;
	initSales(sales, -1) ;
	int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES] ;
	initCube(cube, -1) ;
	int choice = 0 ;
	int c ;
	while(choice != done) {
		printMenu() ;
		if (scanf(" %d", &choice) != 1 || ((c = getchar()) != '\n' && c != EOF)) {
			choice = 0 ;
			while ((c = getchar()) != '\n' && c != EOF) ;
		}
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
				_3_dayStat(cube, days) ;
				break ;
			case print:
				_4_EntireData(cube) ;
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
		while ((c = getchar()) != '\n' && c != EOF) ;
	}
	printf("Goodbye!\n") ;
	return 0 ;
}


void _1_enterSingle(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) {
	
	int brandIndex ;
	printf("Enter the sales data for a single brand on a single day:\n") ;
	int c ;
	if (scanf(" %d %d %d %d %d", &brandIndex, &sales[0], &sales[1], &sales[2], &sales[3]) == 5) {
		if ((c = getchar()) == '\n' && brandIndex >= 0 && brandIndex < NUM_OF_BRANDS && days[brandIndex] < DAYS_IN_YEAR - 1) {
			for (int i = 0 ; i < NUM_OF_TYPES ; i++) {
				if (sales[i] >= 0) {
					if (i == NUM_OF_TYPES - 1) {
						updateCube(cube, days, &brandIndex, sales) ;
					}
				} else {
					break ;
				}
			}
		}
	} else {
		while ((c = getchar()) == '\n' && c != EOF) ;
	}
}


int brandsPopulated(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) {
	int complete = 0 ;
	int beganState = 0 ;
	for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
		int needsData = 0 ;
		for (int i = 0 ; i < days[j] ; i++) {
			if (cube[i][j][0] == -1) {
				needsData = 1 ;
				if (!beganState) {
					beganState = 1 ;
					printf("No data for brands") ;
				}
				printf(" %s", brands[j]) ;
			}
		}
	}
	if (beganState) {
		printf("\nPlease complete the data\n") ;
	} else {
		complete = 1 ;
	}
	return complete ;
}


void _2_enterEvery(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) {
	int valid = 0 ;
	for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
		if (days[i] < DAYS_IN_YEAR - 1) {
			valid = 1 ;
			break ;
		}
	}
	if (!valid) {
		return ;
	} else {
		while (!brandsPopulated(cube, days)) {
			int brandIndex = -1 ;
			int tryAnother = 0 ;
			if (scanf(" %d", &brandIndex) != 1 || brandIndex < 0 || brandIndex >= NUM_OF_BRANDS) {
				int c ;
				while ((c = getchar()) != '\n' && c != EOF);
				continue ;
			}
			for (int typeIndex = 0 ; typeIndex < NUM_OF_TYPES ; typeIndex++) {
				if (scanf(" %d", &sales[typeIndex]) != 1 || sales[typeIndex] < 0) {
					tryAnother = 1 ;
					break ;
				}
			}
			if (tryAnother) {
				int c ;
				while ((c = getchar()) != '\n' && c != EOF);
				continue ;
			}
			updateCube(cube, days, &brandIndex, sales) ;
		}
	}
}


// void flattenCubeSlice (const int *cube, int specificDay, int brandSize, int typeSize, int *flattened) {
// 	int ind = 0 ;
// 	for (int i = 0 ; i < brandSize ; i++) {
// 		for (int j = 0 ; j < typeSize ; j++) {
// 			flattened[ind++] = cube[(specificDay * brandSize * typeSize) + (i * typeSize) + j] ;
// 		}
// 	}
// }


void _3_dayStat(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) {

	int display = 0 ;

	printf("What day would you like to analyze?\n") ;

	while (!display) {

		int yom = -1;

		if (scanf(" %d", &yom) != 1 || yom < 0 || yom >= DAYS_IN_YEAR) {
			// int c;
			// while ((c = getchar()) != '\n' && c != EOF) ;
			printf("Please enter a valid day\n"
					"Which day would you like to analyze?\n") ;
			continue ;
		}

		int valid = 0 ;
		for (int k = 0 ; k < NUM_OF_BRANDS ; k++) {
			if (days[k] > -1 && yom <= days[k]) {
				valid = 1 ;
				break ;
			}
		}
		
		if (!valid) {
			// int c;
			// while ((c = getchar()) != '\n' && c != EOF) ;
			printf("Please enter a valid day\n"
					"Which day would you like to analyze?\n") ;
			continue ;
		}

		int brandSize = 0 ;
		int typeSize = 0 ;
		// int brandSize = sizeof(cube[yom]) / sizeof(cube[yom][0]) ;
		// int typeSize = sizeof(cube[yom][0]) / sizeof(cube[yom][0][0]) ;
		
		for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
			int validData = 0 ;
			for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
				if (cube[yom][i][j] != -1) {
					validData = 1 ;
					break ;
				}
			}
			// QUE: what if equally best?
			if (validData) {
				brandSize++ ;
			}
		}
		for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
			int validData = 0 ;
			for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
				if (cube[yom][i][j] != -1) {
					validData = 1 ;
					break ;
				}
			}
			// QUE: what if equally best?
			if (validData) {
				typeSize++ ;
			}
		}


		int flattened[brandSize * typeSize] ;
		int ind = 0 ;
		for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
			for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
				if (cube[yom][i][j] != 1) {
					flattened[ind++] = cube[yom][i][j] ;
				}
			}
		}

		// flattenCubeSlice((const int *)cube, yom, brandSize, typeSize, flattened) ;
		// int flatSliceSize = sizeof(flattened) / sizeof(flattened[0]) ;
		int salesTotal = getSum(flattened, ind) ;

		// int i = 0, j = 0 ;
		int bestBrand = 0 ;
		int bestBrand_sales = 0 ;
		int previousTotal_brand = 0 ;
		
		for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
			for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
				if (cube[yom][i][j] != -1) {
					bestBrand_sales += cube[yom][i][j] ;
				}
			}
			// QUE: what if equally best?
			if (bestBrand_sales > previousTotal_brand) {
				previousTotal_brand = bestBrand_sales ;
				bestBrand = i ;
			}
		}

		// TODO: combine above and below

		int bestType = 0 ;
		int bestType__sales = 0 ;
		int previousTotal_type = 0 ;
		for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
			for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
				if (cube[yom][i][j] != -1) {
					bestType__sales += cube[yom][i][j] ;
				}
			}
			// QUE: what if equally best?
			if (bestType__sales > previousTotal_type) {
				previousTotal_type = bestType__sales ;
				bestType = j ;
			}
		}
		display = 1 ;
		printf("In day number %d:\n"
				"The sales total was %d\n"
				"The best sold brand with %d sales was %s\n"
				"The best sold type with %d sales was %s\n",
				yom,
				salesTotal,
				bestBrand_sales, brands[bestBrand],
				bestType__sales, types[bestType]) ;
	}
}


void _4_EntireData(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES]) {
	printf("*****************************************\n") ;
	for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
		printf("\nSales for %s:", brands[j]) ;
		for (int i = 0 ; i < DAYS_IN_YEAR ; i++) {
			printf("\nDay %d-", i) ;
			for (int k = 0 ; k < NUM_OF_TYPES ; k++) {
				if (cube[i][j][k] > -1) {
					printf(" %s: %d", types[k], cube[i][j][k]) ;
				}
			}
		}
	}
	printf("\n\n*****************************************\n") ;
}


// void _5_simpleInsight() {}
// void _6_avgDelta() {}
