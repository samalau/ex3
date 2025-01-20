/******************
Name: Samantha Newmark
ID: ---------
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

int choice = 0 ;

char brands[NUM_OF_BRANDS][BRANDS_NAMES] = {"Toyoga", "HyunNight", "Mazduh", "FolksVegan", "Key-Yuh"} ;
char types[NUM_OF_TYPES][TYPES_NAMES] = {"SUV", "Sedan", "Coupe", "GT"} ;

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
		sales[i] = initAsValue ;
	}
}


void initDays(int days[NUM_OF_BRANDS], int initAsValue) {
	for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
		days[i] = initAsValue ;
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
	initDays(days, 0) ;

	int sales[NUM_OF_TYPES] ;
	initSales(sales, -1) ;

	int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES] ;
	initCube(cube, -1) ;

	while(choice != done) {

		printMenu() ;

		int input = scanf(" %d", &choice) ;

		if (input == EOF) {
			choice = done ;
			break ;
		} else if (input != 1) {
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
				scanf("%*[^\n]") ;
				scanf("%*c") ;
				printf("Invalid input\n") ;
		}
	}
	printf("Goodbye!\n") ;
	return 0 ;
}


void _1_enterSingle(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS], int sales[NUM_OF_TYPES]) {
	int brandIndex ;
	printf("What brand?\n") ;
	if (brandIndex >= NUM_OF_BRANDS || brandIndex < 0) {
		scanf("%*[^\n]") ;
		scanf("%*c") ;
		printf("This brand is not valid\n") ;
	} else {
		int saleInput = scanf(" %d %d %d %d", &sales[0], &sales[1], &sales[2], &sales[3]) ;
		if (saleInput == EOF) {
			choice = done ;
			return ;
		} else if (saleInput != 4 || brandIndex >= NUM_OF_BRANDS || brandIndex < 0) {
			scanf("%*[^\n]") ;
			scanf("%*c") ;
			printf("This brand is not valid\n") ;
		} else {
			int valid = 0 ;
			if (brandIndex >= 0 && brandIndex < NUM_OF_BRANDS) {
				valid = 1 ;
				for (int i = 0 ; i < NUM_OF_TYPES ; i++) {
					if (sales[i] < 0) {
						valid = 0 ;
						break ;
					}
				}
				if (valid && days[brandIndex] < DAYS_IN_YEAR - 1) {
					updateCube(cube, days, &brandIndex, sales) ;
				} else {
					scanf("%*[^\n]") ;
					scanf("%*c") ;
					printf("This brand is not valid\n") ;
				}
			} else {
				scanf("%*[^\n]") ;
				scanf("%*c") ;
				printf("This brand is not valid\n") ;
			}
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

	if (nextAvailableDay < DAYS_IN_YEAR) {
		int filled = 0 ;
		while (!filled) {
			int valid = 1 ;
			printf("No data for brands") ;
			for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
				if (days[j] == nextAvailableDay) {
					printf(" %s", brands[j]) ;
				}
			}
			printf("\nPlease complete the data\n") ;

			int brandIndex = -1 ;
			int brandCheck = scanf(" %d", &brandIndex) ;
			if (brandCheck == EOF) {
				choice = done;
				return;
			}

			if (brandCheck != 1 || brandIndex < 0 || brandIndex >= NUM_OF_BRANDS || cube[nextAvailableDay][brandIndex][0] != -1) {
				scanf("%*[^\n]") ;
				scanf("%*c") ;
				printf("This brand is not valid\n") ;
				valid = 0 ;
				break;
			}

			if (scanf(" %d %d %d %d", &sales[0], &sales[1], &sales[2], &sales[3]) != 4) {
				scanf("%*[^\n]") ;
				scanf("%*c") ;
				printf("This brand is not valid\n") ;
				valid = 0 ;
				continue;
			}

			for (int i = 0; i < NUM_OF_TYPES; i++) {
				if (sales[i] < 0) {
					valid = 0;
					printf("This brand is not valid\n");
					break;
				}
			}

			if (valid) {
				updateCube(cube, days, &brandIndex, sales);
			}

			filled = 1;
			for (int j = 0; j < NUM_OF_BRANDS; j++) {
				if (days[j] == nextAvailableDay) {
					filled = 0;
					break;
				}
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

	if (lastPossibleDay > 0) {
	
		printf("What day would you like to analyze?\n") ;

		int display = 0 ;
		while (!display) {

			int yom = -1 ;
			int input = scanf(" %d", &yom) ;
			if (input == EOF) {
				choice = done ;
				break ;
			} else if (input != 1 || yom < 1 || yom > DAYS_IN_YEAR || yom > lastPossibleDay) {
				scanf("%*[^\n]") ;
				scanf("%*c") ;
				printf("Please enter a valid day.\n"
						"What day would you like to analyze?\n") ;
				continue ;
			}

			int valid = 0 ;
			for (int k = 0 ; k < NUM_OF_BRANDS ; k++) {
				if (days[k] > 0 && yom - 1 < days[k]) {
					valid = 1 ;
					break ;
				}
			}
			
			if (!valid) {
				scanf("%*[^\n]") ;
				scanf("%*c") ;
				printf("Please enter a valid day.\n"
						"What day would you like to analyze?\n") ;
				continue ;
			}

			int brandSize = 0 ;
			int typeSize = 0 ;
			
			for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
				int validData = 0 ;
				for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
					if (cube[yom - 1][i][j] != -1) {
						validData = 1 ;
						break ;
					}
				}
				if (validData) {
					brandSize++ ;
				}
			}

			for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
				int validData = 0 ;
				for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
					if (cube[yom - 1][i][j] != -1) {
						validData = 1 ;
						break ;
					}
				}
				if (validData) {
					typeSize++ ;
				}
			}

			if (brandSize == 0 || typeSize == 0) {
				scanf("%*[^\n]") ;
				scanf("%*c") ;
				printf("Please enter a valid day.\n"
						"Which day would you like to analyze?\n") ;
				continue ;
			}

			int flattened[brandSize * typeSize] ;
			int ind = 0 ;
			for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
				for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
					if (cube[yom - 1][i][j] != -1) {
						flattened[ind++] = cube[yom - 1][i][j] ;
					}
				}
			}

			if (ind == 0) {
				scanf("%*[^\n]") ;
				scanf("%*c") ;
				printf("Please enter a valid day.\n"
						"Which day would you like to analyze?\n") ;
				continue ;
			}

			int salesTotal = getSum(flattened, ind) ;

			int bestBrand = -1 ;
			int bestBrand_sales = -1 ;
			int total_brand = 0 ;

			for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
				total_brand = getSum(cube[yom - 1][i], NUM_OF_TYPES) ;
				if (total_brand > bestBrand_sales) {
					bestBrand_sales = total_brand ;
					bestBrand = i ;
				}
			}

			int bestType = -1 ;
			int bestType_sales = -1 ;
			int total_type = 0 ;
			for (int j = 0 ; j < NUM_OF_TYPES ; j++) {
				int tempCube[NUM_OF_BRANDS] ;
				for (int i = 0 ; i < NUM_OF_BRANDS ; i++) {
					tempCube[i] = cube[yom - 1][i][j] ;
				}
				total_type = getSum(tempCube, NUM_OF_BRANDS) ;
				if (total_type > bestType_sales) {
					bestType_sales = total_type ;
					bestType = j ;
				}
			}

			display = 1 ;
			scanf("%*[^\n]") ;
			scanf("%*c") ;
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
	
	printf("*****************************************") ;

	for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
		printf("\nSales for %s:", brands[j]) ;

		for (int i = 0 ; i < DAYS_IN_YEAR ; i++) {
			if (i < days[j]) {
				printf("\nDay %d-", i + 1) ;
			}

			for (int k = 0 ; k < NUM_OF_TYPES ; k++) {
				if (cube[i][j][k] > -1) {
					printf(" %s: %d", types[k], cube[i][j][k]) ;
				}
			}
		}
	}
	printf("\n*****************************************\n") ;
}


void _5_simpleInsight(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) {

	int lastPossibleDay = 0 ;
	for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
		if (days[j] > lastPossibleDay) {
			lastPossibleDay = days[j] ;
		}
	}

	--lastPossibleDay ;

	if (lastPossibleDay >= 0) {

		int bestBrand = -1 ;
		int bestBrand_sales = -1 ;
		int bestType = -1 ;
		int bestType_sales = -1 ;
		int bestDay = -1 ;
		int bestDay_sales = -1 ;

		int collectionBrandSales[NUM_OF_BRANDS] = {0} ;
		int collectionTypeSales[NUM_OF_TYPES] = {0} ;

		for (int yom = 0 ; yom <= lastPossibleDay ; yom++) {
			
			int salesTotal = 0 ;
			
			for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {

				for (int k = 0 ; k < NUM_OF_TYPES ; k++) {
					if (cube[yom][j][k] != -1) {
						salesTotal += cube[yom][j][k] ;
						collectionBrandSales[j] += cube[yom][j][k] ;
						collectionTypeSales[k] += cube[yom][j][k] ;
					}
				}
			}

			if (salesTotal > bestDay_sales) {
				bestDay_sales = salesTotal ;
				bestDay = yom ;
			}
		}

		for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
			if (collectionBrandSales[j] > bestBrand_sales) {
				bestBrand_sales = collectionBrandSales[j] ;
				bestBrand = j ;
			}
		}

		for (int k = 0 ; k < NUM_OF_TYPES ; k++) {
			if (collectionTypeSales[k] > bestType_sales) {
				bestType_sales = collectionTypeSales[k] ;
				bestType = k ;
			}
		}

		if (bestBrand != -1 && bestType != -1 && bestDay!= -1) {
			printf("The best-selling brand overall is %s: %d$\n"
					"The best-selling type of car is %s: %d$\n"
					"The most profitable day was day number %d: %d$\n",
					brands[bestBrand], bestBrand_sales,
					types[bestType], bestType_sales,
					bestDay + 1, bestDay_sales) ;
		}
	}
}


void _6_avgDelta(int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int days[NUM_OF_BRANDS]) {

	int lastPossibleDay = 0 ;

	for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {
		if (days[j] > lastPossibleDay) {
			lastPossibleDay = days[j] ;
		}
	}

	if (lastPossibleDay > 1) {

		for (int j = 0 ; j < NUM_OF_BRANDS ; j++) {

			int sumDifferences = 0 ;
			int validDifferences = 0 ;

			for (int i = 1 ; i < days[j] ; i++) {

				int a = 0, b = 0 ;

				for (int k = 0 ; k < NUM_OF_TYPES ; k++) {
					if (cube[i - 1][j][k] >= 0) {
						a += cube[i - 1][j][k] ;
					}

					if (cube[i][j][k] >= 0) {
						b += cube[i][j][k] ;
					}
				}

				if ((a >= 0 && b >= 0)) {
					int difference = b - a ;
					sumDifferences += difference ;
					validDifferences++ ;
				}
			}
			if (validDifferences > 0) {
				float averageDelta = (float)sumDifferences / validDifferences ;
				printf("Brand: %s, Average Delta: %.6f\n", brands[j], averageDelta) ;
			}
		}
	}
}
