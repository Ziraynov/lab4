#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int number_of_lines(int line)
{
	printf("enter number of lines:");
	while (scanf_s("%d", &line) != 1 || line > 100 || line <= 0 || getchar() != '\n')
	{
		printf("error,try againg");
		rewind(stdin);

	}
	return line;

}

int number_of_colones(int colone)
{
	printf("enter number of colones:");
	while (scanf_s("%d", &colone) != 1 || colone > 100 || colone <= 0 || getchar() != '\n')
	{
		printf("error,try againg");
		rewind(stdin);

	}
	return colone;
}

int choice1(int choice)
{
	printf("Choose a method for entering elements:\nrandom-1;by yourself-2\n");
	while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2) || getchar() != '\n')
	{
		printf("error,try againg ");

		rewind(stdin);

	}

	
	return choice;
}

void random(int array[100][100], int i, int j, int lines, int colones)
{
	srand(time(0));
	for (i = 0; i < lines; i++)
	{
		for (j = 0; j < colones; j++)
		{
			array[i][j] = rand() % 31 - 20;
			printf("%2d\t ", array[i][j]);
		}
		printf("\n");
	}

}

void personal_input(int array[100][100], int i, int j, int line, int colone)
{
	for (i = 0; i < line; i++)
	{

		for (j = 0; j < colone; j++)
		{
			printf("input %d %d :", i + 1, j + 1);
			while (scanf_s("%d", &array[i][j]) != 1 || getchar() != '\n')
			{
				printf("error,try againg ");

				rewind(stdin);

			}

		}
	}
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < colone; j++)
		{
			printf("%2d ", array[i][j]);
		}
		printf("\n");
	}
}

void negative(int array[100][100], int i, int j, int line, int colone, int flag, int itwas, int negativeline, int* retitwas, int* retnegativeline) {
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < colone; j++)
		{
			if (array[i][j] >= 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			itwas = 1;
			negativeline = i;
			break;
		}
		flag = 0;
	}
	*retitwas = itwas;
	*retnegativeline = negativeline;


}
void newmatrix(int negativeline, int i, int j, int array[100][100], int line, int colone) {
	for (j = 0; j < colone; j++)
	{
		printf("%d", array[negativeline][j]);
	}
	int firstnegative = array[negativeline][0];
	printf("\nfirst negative element%d\n", array[negativeline][0]);
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < colone; j++)
		{
			array[i][j] *=firstnegative;

		}
	}
	printf("new matrix:\n");
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < colone; j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}

}

int main()
{
	int array[100][100], choice = 0, line = 0, colone = 0, i = 0, j = 0, flag = 0, itwas = 0, negativeline = 0;
	line = number_of_lines(line);
	colone = number_of_colones(colone);
	choice = choice1(choice);
	if (choice == 1)
	{
		random(array, i, j, line, colone);
	}
	else
	{
		personal_input(array, i, j, line, colone);
	}
	negative(array, i, j, line, colone, flag, itwas, negativeline, &itwas, &negativeline);
	if (itwas == 0)
		printf("not foundeed");
	else
	{
		printf("negative line: %d\nelements of this line: ", negativeline + 1);
		newmatrix(negativeline, i, j, array, line, colone);
	}
	return 0;

}