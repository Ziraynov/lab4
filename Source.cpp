#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void number_of_lines_and_colones(int line,int colone,int *retline,int *retcolone)
{
	printf("enter size of square matrix:");
	while (scanf_s("%d", &line) != 1 || line > 100 || line <=1 || getchar() != '\n')
	{
		printf("error,try againg");
		rewind(stdin);

	}
	*retline = line;
	*retcolone = line;

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
void sum_elements_when_even(int array[100][100], int line, int colone, int j, int i, int sum,int flag)
{
	
	for (j=colone-1; j >= colone/2; j--)
	{
		
		
			for (i=flag; i < line; i++)
			{
				sum += array[i][j];
			}
			
			flag++;
		    line--;
	}
	printf("%d", sum);
}
void sum_elements_when_noteven(int array[100][100], int line, int colone, int j, int i, int sum,int flag)
{
	for (j = colone - 1; j >= colone / 2+1; j--)
	{


		for (i = flag; i < line; i++)
		{
			sum += array[i][j];
		}

		flag++;
		line--;
	}
	sum += array[(colone) / 2][(colone) / 2];
	printf("%d", sum);
}
int main() 
{
	int array[100][100], choice = 0, line = 0, colone = 0, i = 0, j = 0, sum = 0, k = 0, flag = 0;
	number_of_lines_and_colones(line,colone,&line,&colone);
	choice = choice1(choice);
	if (choice == 1)
	{
		random(array, i, j, line, colone);
	}
	else
	{
		personal_input(array, i, j, line, colone);
	}
	if (line % 2 == 0)
		sum_elements_when_even(array, line, colone, j, i, sum,flag);
	else
		sum_elements_when_noteven(array, line, colone, j, i, sum,flag);
	return 0;
}