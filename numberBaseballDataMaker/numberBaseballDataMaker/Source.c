#include <stdio.h>

void main() {
	
	int max = 1;
	int input;
	char number[100][100][3] = { 0 };

	printf("This program is numberBaseballDataMaker.\n\n");
	printf("This program can be calculated up to two digits.\n");
	printf("If you enter 0, the program will shut down\n");
	while (1) {
		printf("Enter an integer : ");
		scanf("%d", &input);
		if (0 < input&&input < 3)
			break;
		else
			printf("It does not belong to the range. Please re-enter.\n");
	}

	for (input; input > 0; input--) {
		max *= 10;
	}
	printf("\nCalculate to %d.\n", max-1);

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			for (int k = 0; k < 3; k++) {
				number[i][j][k];//TODO
			}
		}
	}


	while (1)
	{

	}
}