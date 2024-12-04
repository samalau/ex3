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

// int getMax(const int *array, int size) ;
int getSum(const int *array, int size) ;

void initDays(int days[NUM_OF_BRANDS], int initAsValue) ;
void initSales(int sales[NUM_OF_TYPES], int initAsValue) ; 
void initCube(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int initAsValue) ;

void updateCube(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int *brandIndex, int sales[NUM_OF_TYPES]) ;

void printMenu() ;

void _1_enterSingle(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) ;
void _2_enterEvery(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) ;
void _3_dayStat(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) ;
void _4_EntireData(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) ;
void _5_simpleInsight(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) ;
void _6_avgDelta(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) ;


// int getMax(const int *array, int size) {
// 	int max = 0 ;
// 	for (int i = 0 ; i < size ; i++) {
// 		if (array[i] != -1) {
// 			if (array[i] > max) {
// 				max = array[i] ;
// 			}
// 		}
// 	}
// 	return max ;
// }


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
		if (days[*brandIndex] < DAYS_IN_YEAR - 1 && cube[days[*brandIndex]][*brandIndex][0] == -1) {
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
		days[i] = 0 ;
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
			int c ;
			while ((c = getchar()) != '\n' && c != EOF) ;
			choice = 0 ;
		}
		switch(choice){
			case done:
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
				_4_EntireData(cube, days) ;
				break ;
			case insights:
				_5_simpleInsight(cube, days) ;
				break ;
			case deltas:
				_6_avgDelta(cube, days) ;
				break ;
			default:
				printf("Invalid input\n") ;
		}
	}
	printf("Goodbye!\n") ;
	return 0 ;
}


void _1_enterSingle(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) {
	int brandIndex, c ;
	printf("Enter the sales data for a single brand on a single day:\n") ;
	if (scanf(" %d %d %d %d %d", &brandIndex, &sales[0], &sales[1], &sales[2], &sales[3]) == 5) {
		int valid = 1 ;
		if (brandIndex >= 0 && brandIndex < NUM_OF_BRANDS) {
			for (int i = 0 ; i < NUM_OF_TYPES ; i++) {
				if (sales[i] < 0) {
					valid = 0 ;
					break ;
				}
			}
			if (valid && days[brandIndex] < DAYS_IN_YEAR - 1) {
				updateCube(cube, days, &brandIndex, sales) ;
			}
		} else {
			printf("This brand is not valid\n") ;
		}
	}
}


void _2_enterEvery(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) {
	int nextAvailableDay = DAYS_IN_YEAR - 1 ;
	for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
		if (days[j] < nextAvailableDay) {
			nextAvailableDay = days[j] ;
		}
	}
	int filled = 0 ;
	while (!filled) {
		filled = 1 ;
		printf("No data for brands") ;
		for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
			if (days[j] == nextAvailableDay) {
				// if (cube[nextAvailableDay][j][0] == -1) {
				printf(" %s", brands[j]) ;
				// }
			}
		}
		printf("\nPlease complete the data\n") ;
		int brandIndex = -1 ;
		if (scanf(" %d %d %d %d %d", &brandIndex, &sales[0], &sales[1], &sales[2], &sales[3]) == 5) {
			if (brandIndex >= 0 && brandIndex < NUM_OF_BRANDS) {
				int valid = 1 ;
				if (cube[nextAvailableDay][brandIndex][0] == -1) {
					for (int i = 0 ; i < NUM_OF_TYPES ; i++) {
						if (sales[i] < 0) {
							valid = 0 ;
							break ;
						}
					}
				} else {
					printf("This brand is not valid\n") ;
					valid = 0 ;
				}
				if (valid) {
					updateCube(cube, days, &brandIndex, sales) ;
				}
			} else {
				printf("This brand is not valid\n") ;
			}
		} else {
			printf("This brand is not valid\n") ;
		}
		int c;
		while ((c = getchar()) != '\n' && c != EOF) ;
		for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
			if (days[j] == nextAvailableDay) {
				filled = 0 ;
				break ;
			}
		}
	}
}


void _3_dayStat(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) {

	int lastPossibleDay = 0 ;
	for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
		if (days[j] > lastPossibleDay) {
			lastPossibleDay = days[j] ;
		}
	}

	if (--lastPossibleDay >= 0) {
	
		printf("What day would you like to analyze?\n") ;

		int display = 0 ;
		while (!display) {

			int yom = -1 ;
			if (scanf(" %d", &yom) != 1 || yom < 0 || yom >= DAYS_IN_YEAR || yom > lastPossibleDay) {
				int c ;
				while ((c = getchar()) != '\n' && c != EOF) ;
				printf("Please enter a valid day\n"
						"Which day would you like to analyze?\n") ;
				continue ;
			}

			int valid = 0 ;
			for (int k = 0 ; k < NUM_OF_BRANDS ; k++) {
				if (days[k] > -1 && yom <= days[k] && yom <= lastPossibleDay) {
					valid = 1 ;
					break ;
				}
			}
			
			if (!valid) {
				int c ;
				while ((c = getchar()) != '\n' && c != EOF) ;
				printf("Please enter a valid day\n"
						"Which day would you like to analyze?\n") ;
				continue ;
			}

			int brandSize = 0 ;
			int typeSize = 0 ;
			
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
					if (cube[yom][i][j] != -1) {
						flattened[ind++] = cube[yom][i][j] ;
					}
				}
			}

			int salesTotal = getSum(flattened, ind) ;

			int bestBrand = -1 ;
			int bestBrand_sales = -1 ;
			int total_brand = 0 ;

			for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
				total_brand = getSum(cube[yom][i], NUM_OF_TYPES) ;
				// QUE: what if equally best?
				if (total_brand > bestBrand_sales) {
					bestBrand_sales = total_brand ;
					bestBrand = i ;
				}
			}
			
			// QUE: combine above and below?

			int bestType = -1 ;
			int bestType_sales = -1 ;
			int total_type = 0 ;
			for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
				int tempCube[NUM_OF_BRANDS] ;
				for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
					tempCube[i] = cube[yom][i][j] ;
				}
				total_type = getSum(tempCube, NUM_OF_BRANDS) ;
				// QUE: what if equally best?
				if (total_type > bestType_sales) {
					bestType_sales = total_type ;
					bestType = j ;
				}
			}
			display = 1 ;
			int c ;
			while ((c = getchar()) != '\n' && c != EOF) ;
			printf("In day number %d:\n"
					"The sales total was %d\n"
					"The best sold brand with %d sales was %s\n"
					"The best sold type with %d sales was %s\n",
					yom,
					salesTotal,
					bestBrand_sales, brands[bestBrand],
					bestType_sales, types[bestType]) ;
		}
	}
}


void _4_EntireData(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) {
	printf("*****************************************\n") ;
	for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
		printf("\nSales for %s:", brands[j]) ;
		for (int i = 0 ; i < DAYS_IN_YEAR ; i++) {
			if (i < days[j]) {
				printf("\nDay %d-", i) ;
			}
			for (int k = 0 ; k < NUM_OF_TYPES ; k++) {
				if (cube[i][j][k] > -1) {
					printf(" %s: %d", types[k], cube[i][j][k]) ;
				}
			}
		}
	}
	printf("\n\n*****************************************\n") ;
}


void _5_simpleInsight(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) {

	int lastPossibleDay = 0 ;

	for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
		if (days[j] > lastPossibleDay) {
			lastPossibleDay = days[j] ;
		}
	}

	if (--lastPossibleDay >= 0) {

		int previous_bestBrand = -1 ;
		int previous_bestType = -1 ;
		int bestBrand = -1 ;
		int bestBrand_sales = -1 ;
		int bestType = -1 ;
		int bestType_sales = -1 ;
		int total_type = 0 ;
		int bestDay = -1 ;
		int bestDay_sales = -1 ;
		int brandSize = 0 ;
		int typeSize = 0 ;

		for (int yom = 0 ; yom <= lastPossibleDay ; yom++) {
			
			brandSize = 0 ;
			typeSize = 0 ;
			
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
					if (cube[yom][i][j] != -1) {
						flattened[ind++] = cube[yom][i][j] ;
					}
				}
			}

			int salesTotal = getSum(flattened, ind) ;
			if (salesTotal > bestDay_sales) {
				bestDay_sales = salesTotal ;
				bestDay = yom ;
			}
			
			int total_brand = 0 ;

			for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
				total_brand = getSum(cube[yom][i], NUM_OF_TYPES) ;
				// QUE: what if equally best?
				if (total_brand > bestBrand_sales) {
					bestBrand_sales = total_brand ;
					bestBrand = i ;
				}
			}
 
			// QUE: combine above and below?

			total_type = 0 ;
			for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
				int tempCube[NUM_OF_BRANDS] ;
				for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
					tempCube[i] = cube[yom][i][j] ;
				}
				total_type = getSum(tempCube, NUM_OF_BRANDS) ;
				// QUE: what if equally best?
				if (total_type > bestType_sales) {
					bestType_sales = total_type ;
					bestType = j ;
				}
			}
		}
		printf("The best-selling brand overall is %s: %d$\n"
				"The best-selling type of car is %s: %d$\n"
				"The most profitable day was day number %d: %d$\n",
				brands[bestBrand], bestBrand_sales,
				types[bestType], bestType_sales,
				bestDay, bestDay_sales) ;
	}
}


void _6_avgDelta(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) {

	int lastPossibleDay = 0 ;

	for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
		if (days[j] > lastPossibleDay) {
			lastPossibleDay = days[j] ;
		}
	}

	if (--lastPossibleDay > 0) {

		int allSalesTotals[lastPossibleDay + 1] ;
		for (int i = 0 ; i <= lastPossibleDay ; i++) {
			allSalesTotals[i] = 0 ;
		}

		int differences[lastPossibleDay] ;
		for (int i = 0 ; i < lastPossibleDay ; i++) {
			differences[i] = 0 ;
		}

		int brandSize = 0 ;
		int typeSize = 0 ;

		for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {

			int previousDay = 0 ;

			for (int yom = 0 ; yom <= lastPossibleDay ; yom++) {

				brandSize = 0 ;
				typeSize = 0 ;
				
				int validData = 0 ;
				for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
					if (cube[yom][i][j] != -1) {
						validData = 1 ;
						break ;
					}
				}
				if (validData) {
					brandSize++ ;
					typeSize++ ;
				}

				int flattened[typeSize] ;
				int ind = 0 ;
			
				for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
					if (cube[yom][i][j] != -1) {
						flattened[ind++] = cube[yom][i][j] ;
					}
				}
				allSalesTotals[yom] = getSum(flattened, ind) ;
				if (yom > 0){
					previousDay = --yom ;
					differences[previousDay] = allSalesTotals[yom] - allSalesTotals[previousDay] ;
				}

			}
			float averageDelta = (float)getSum(differences, lastPossibleDay + 1) / (lastPossibleDay) ;
			printf("Brand: %s, Average Delta: %.6f\n", brands[i], averageDelta) ;
		}
	}
}
