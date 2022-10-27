#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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
void random(int array[10][12], int i, int j)
{
	srand(time(0));
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 12; j++)
		{
			array[i][j] = rand() % 11;
			printf("%4d", array[i][j]);
		}
		printf("\n");
	}
}
void personal_input(int array[10][12], int i, int j)
{
	printf("Input array: \n");
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 12; j++)
		{
			while (scanf_s("%d", &array[i][j]) !=1)
			{  
				printf("try again\n");
				rewind(stdin);
			}
		}	
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 12; j++)
		{
			printf("%4d", array[i][j]);
		}
		printf("\n");
	}
}
/*1 2 3 1 4 5 6 7 8 9 9 9 
  0 0 4 0 0 0 0 0 0 0 0 0 
  0 0 4 0 0 0 0 0 0 0 0 0 
  0 0 4 0 0 0 0 0 0 0 0 0 
  0 0 4 0 0 0 0 0 0 0 0 0 
  0 1 2 1 1 1 1 1 1 1 1 1  
  0 0 4 0 0 0 0 0 0 0 0 0 
  0 0 4 0 0 0 0 0 0 0 0 0 
  0 0 4 0 0 0 0 0 0 0 0 0 
  0 0 4 0 0 0 0 0 0 0 0 0 
*/
int main()
{
	int array[10][12], i = 0, j = 0, choice = 0, min = 99999,itwas=1;
	choice = choice1(choice);
	if (choice == 1)
	{
		random(array, i, j);
	}
	else
	{
		personal_input(array, i, j);
	}
	int flag = 1;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (min > array[i][j])
			{
				min = array[i][j];
			}
		}
		for (int l = 0; l < 12; l++)
		{
			if (array[i][l] == min)
			{
				for (int b=0; b < 10; b++)
				{
					if (min < array[b][l])
					{
						flag = 0;
					}
				}
				if (flag == 1)
				{
					printf("stroka %d stolbec %d :%d\t\n", i + 1, l + 1, min);
					itwas = 0;
				}
			}
			flag = 1;
		}
		flag = 1;
		min = 99999;
	}
	flag = 1; min = 99999;
	printf("\n");
	for (j = 0; j < 12; j++)
	{
		for (i = 1; i < 10; i++)
		{
			if (min > array[i][j])
				min = array[i][j];
	    }
		for (int l = 0; l < 10; l++)
		{
			if (array[l][j] == min)
			{
				for (int b = 0; b < 12; b++)
				{
					if (min < array[l][b])
					{
						flag = 0;

					}
				}
				if (flag == 1)
				{
					printf("stolbes %d stroca %d %d\n ", j + 1, l + 1, min);
					itwas = 0;
				}
			}
			flag = 1;
		}
		flag = 1;
		min = 9999999;
	}
	if (itwas == 1)
		printf("not founded");
	return 0;
}
