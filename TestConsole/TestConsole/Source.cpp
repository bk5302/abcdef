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
		printf("���ӽ���\n");
		printf("�켱 ���� ������ ī�带 �޽��ϴ�.\n");
		system("pause");
		system("cls");
		srand(time(NULL));
		a = (rand() % 11) + 1;
		b = (rand() % 11) + 1;
		printf("���� �Ⱥ�����%d,�� %d\n", a, b);
		c = (rand() % 11) + 1;
		d = (rand() % 11) + 1;
		printf("���� %d,�� %d\n", c, d);
		p1 = a + c;
		p2 = b + d;
		while (1)
		{
		if (p1 < 21 && p2 < 21)
		if (cnum1 != 5, cnum2 != 5)
		{
		
		if (p1 > 16)
			diller = (rand() % 2) + 1;
		if (diller == 1)//����ī�����������
		{
			
			printf("���� %d\n", c);
			cnum1++;
			p1 = p1 + c;
		}
		printf("ī�带�����ðڽ��ϱ�? y or n\n");
		scanf("%c", &yorn);
		switch (yorn)
		{

		case 'y':
		case 'Y':
		d = (rand() % 11) + 1;
		printf("�� %d", d);
		p2 = p2 + d;
		cnum2++;
		break;
		case 'n':
		case 'N':
			printf("ī�带 �ȹ޾ҽ��ϴ�");
			printf("������ �����ðڽ��ϱ�");
			{

			}
		break;

		}
		if (p1 > 21 || p2 > 21)
		{
			if (p1 > 21)
			{
				printf("�����̱�");
			}
			if (p2 > 21)
			{
				printf("������");
			}
		}
			if (cnum1 == 5 && cnum2 == 5)
			{

			}

		


		}
	}
}