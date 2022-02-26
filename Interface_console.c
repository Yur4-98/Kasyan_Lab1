
#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>


void dialog() 
{
//	printf("-_-");
	//struct Matrix* a = NULL;
	int q = 1, res;
	int input = 0;

	struct Matrix* m1 = NULL,*m2 = NULL, *m3 = NULL;

	do 
	{
		printf("Menu:\n1 - Input\n2 - Output\n3 - Operations\n0 - Exit\n");
		input = -1;
		res = scanf("%d", &input);
		switch (input)
		{
		case 1:
			input = -1;
			printf("Input:\nFrom console - 1\nGeneration - 2\n");
			res = scanf("%d", &input);
			switch (input)
			{
			case 1:
				free_M(m1);
				printf("Enter matrix1\n");
				m1 = input_M();
				free_M(m2);
				printf("Enter matrix2\n");
				m2 = input_M();
				break;
			case 2:
				//later
				break;
			default:
				break;
			}
			break;
		
		case 2:
			printf("Matrix1:\n");
			output_M(m1);
			printf("Matrix2:\n");
			output_M(m2);
			printf("Matrix3:\n");
			output_M(m3);
			break;
		case 3:
			input = -1;
			printf("Operations:\nMatrix sum(m3=m1+m2) - 1\nMatrix mult(m3=m1*m2) - 2\nTransposition(m1->m3) - 3\n");
			res = scanf("%d", &input);
			switch (input)
			{
			case 1:
				free_M(m3);
				m3 = sum_m(m1, m2);
				break;
			case 2:
				free_M(m3);
				m3 = mult_m(m1, m2);
				break;
			case 3:
				free_M(m3);
				m3 = transposition(m1);
				break;
			default:
				break;
			}
			break;
		case 0:
			free_M(m1);
			free_M(m2);
			free_M(m3);
			q = 0;
			break;
		default:
			break;
		}
		
	} while (q);
}
