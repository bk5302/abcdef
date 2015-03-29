#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	
		int a, b, c, d;
		int p1, p2;
		char yorn;
		int diller;
		int cnum1 = 2, cnum2 = 2;
		printf("게임시작\n");
		printf("우선 각각 두장의 카드를 받습니다.\n");
		system("pause");
		system("cls");
		srand(time(NULL));
		a = (rand() % 11) + 1;
		b = (rand() % 11) + 1;
		printf("딜러 안보여줌%d,나 %d\n", a, b);
		c = (rand() % 11) + 1;
		d = (rand() % 11) + 1;
		printf("딜러 %d,나 %d\n", c, d);
		p1 = a + c;
		p2 = b + d;
		while (1)
		{
		if (p1 < 21 && p2 < 21)
		if (cnum1 != 5, cnum2 != 5)
		{
		
		if (p1 > 16)
			diller = (rand() % 2) + 1;
		if (diller == 1)//딜러카드받을지말지
		{
			
			printf("딜러 %d\n", c);
			cnum1++;
			p1 = p1 + c;
		}
		printf("카드를받으시겠습니까? y or n\n");
		scanf("%c", &yorn);
		switch (yorn)
		{

		case 'y':
		case 'Y':
		d = (rand() % 11) + 1;
		printf("나 %d", d);
		p2 = p2 + d;
		cnum2++;
		break;
		case 'n':
		case 'N':
			printf("카드를 안받았습니다");
			printf("게임을 끝내시겠습니까");
			{

			}
		break;

		}
		if (p1 > 21 || p2 > 21)
		{
			if (p1 > 21)
			{
				printf("내가이김");
			}
			if (p2 > 21)
			{
				printf("내가짐");
			}
		}
			if (cnum1 == 5 && cnum2 == 5)
			{

			}

		


		}
	}
}