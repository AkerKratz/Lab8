#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROWS 10
#define COLS 8

int main() {
    int arr[ROWS][COLS];
    int i, j;
    int max = -1;
    int max_row = -1;
    int max_col = -1;

    srand(time(0)); // initialize random seed

    // initialize array with random numbers between 0 and 99
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 100;
        }
    }
	FILE* file;
	file = fopen("bander.txt", "w");
    // print array
    printf("Array:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
            fprintf(file,"%d ", arr[i][j]);
        }
        fprintf(file,"\n");
        printf("\n");
    }
	fclose(file);
    puts("");
	file = fopen("bander.txt", "a+");
	int arr2[ROWS][COLS];
    // find maximum element and its coordinates
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            fscanf(file, "%d ",&arr2[i][j]);
        if (arr2[i][j] > max) {
                max = arr2[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    fprintf(file, "\nMaximum element: %d \nCoordinates: (%d, %d)", max, max_row, max_col);
	fclose(file);

    // print maximum element and its coordinates
    printf("Maximum element: %d\n", max);
    printf("Coordinates: (%d, %d)\n", max_row, max_col);

    return 0;
}
