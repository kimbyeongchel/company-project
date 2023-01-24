//21912117 �躴ö
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNING
#pragma warning(disable : 4996)

typedef struct work {
	int arr_time;
	int amount;
	int priority;
}work;

int rear = -1, front = -1, number;

void addq(work element, work* fifo)
{
	if (rear >= (number - 1))
	{
		printf("queue full!!\n");
		return;
	}
	fifo[++rear] = element;
}

work deleteq(work* fifo)
{
	if (rear == front) {
		printf("queue empty!!\n");
		exit(1);
	}
	else
		return fifo[++front];
}

int main()
{
	int run_t, wait_t, end_t = 0;
	int s_wait = 0, s_run = 0;
	char name[80];
	work* fifo, element;

	printf("�Է����� �̸�? ");
	scanf("%s", name);

	FILE* fp = fopen(name, "r");
	if (fp == NULL) {
		puts("���� ���� ����");
		return -1;
	}

	fscanf_s(fp, "%d", &number);

	fifo = (work*)malloc(number * sizeof(work));

	for (int i = 0; i < number; i++) {
		fscanf(fp, "%d %d %d", &element.arr_time, &element.amount, &element.priority);
		addq(element, fifo);
	}
	fclose(fp);

	element = deleteq(fifo);
	end_t += element.arr_time + element.amount;
	s_run += end_t - element.arr_time;

	while (front != rear)
	{
		element = deleteq(fifo);
		end_t += element.amount;
		run_t = end_t - element.arr_time;
		wait_t = run_t - element.amount;
		s_run += run_t;
		s_wait += wait_t;
	}

	printf("FIFO Scheduling�� ���� ���:\n");
	printf("\t�۾� �� = %d, ����ð� = %d, ��� ����ð� = %.2f, ��� ���ð� %.2f\n", number, end_t, (double)s_run / number, (double)s_wait / number);

	free(fifo);
}