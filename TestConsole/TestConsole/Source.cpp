// A�� ���� 1�ιۿ� ����;;
// rand�Լ����� ���� �õ尪�� ��ӵ�;;  --> Sleep �Լ��θ���;; �׷��� ī�尡 2�ʸ��� �ϳ�������

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

char Sdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' }; //�ϴ� A�� 1�̶�� ������
char Cdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' };
char Ddeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' };
char Hdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' };
char mark[4][4] = { "��", "��", "��", "��" };

int pick(); //�������� ��ġ�� �ʴ� ī�带 �̴��Լ�
int pick2(); //������ ���� �������л���
int ace = 0;
int ace2 = 0;
void main()
{
	int player[50]; //������ ��Ÿ����
	char *pmark[5];//������ ��Ÿ���� 

	int i, j;//ī�带 �����ϱ����� ����
	int k, l;
	int sum = 0; //�÷��̾�
	int sum1 = 0; //����
	int sum2 = 0;

	char cho;


must:
	sum = 0;
	sum1 = 0;
	printf("���ӽ���\n");
	printf("�켱 ���� ������ ī�带 �޽��ϴ�.\n\n");

	system("pause");
	system("cls");

	printf("������ ��\n");
	printf("�� "); //���尡���� ��
	sum1 = sum1 + pick2();
	sum1 = sum1 + pick2();



	while (1)
	{
	must3:
		if (sum1 < 17)
			sum1 = sum1 + pick2();

		else if (sum1 > 21)
			break;
		else
			break;
	}
	if (ace2 == 1)
	{
		if (sum1 > 21)
		{
			sum1 = sum1 - 10;
			--ace2;
		}
		else if (ace2 == 2)
		{
			sum1 = sum1 - 10;
			--ace2;
		}
		goto must3;
	}
	printf("\n������ ������ %d�Դϴ�.", sum1);
	if (sum1 > 21)
	{
		printf("\n������ �а� 21�� �Ѿ� �÷��̾ �¸��ϼ̽��ϴ�.\n");
		goto must1;
	}
	printf("\n\n\n\n\n");

	printf("�÷��̾��� ��\n");
	for (k = 0; k < 2; k++) //�÷��̾��� ��
		sum = sum + pick();


	while (1) //�÷��̾��� ��

	{
	must2:
		if (sum >= 21)
			break;

		printf("\n���� %d���Դϴ�.\n", sum);
		printf("ī�带 �� ������ �����Ͻÿ�(Y/N) :  ");
		fflush(stdin);
		scanf("%c", &cho);
		if (cho == 'y' || cho == 'Y') //�ѹ��� �ް������ ������
		{
			sum = sum + pick();

			if (sum > 21)
				break;
		}
		else if (cho == 'N' || cho == 'n')
		{
			printf("�� %d���Դϴ�.\n\n", sum);
			break; // �ޱ� ������ ���Ϲ����� ��������
		}
		else if (sum > 21)
			break;


	}//�÷��̾� ���Ϲ� ��

	//�÷��̾�� ������ ���� ��
	//sum = player     sum1 = dealer
	if (sum>21)
	{
		if (ace == 1)
		{
			sum = sum - 10;
			--ace;
		}
		else if (ace == 2)
		{
			sum = sum - 10;
			--ace;
		}
		goto must2;
	}



	if (sum <= 21 && sum1 <= 21)
	{
		if (sum > sum1)
			printf("�÷��̾ %d �� %d�� �¸��ϼ̽��ϴ�\n.", sum, sum1);
		else if (sum<sum1)
			printf("�÷��̾�� %d �� %d�� �й��ϼ̽��ϴ�.\n", sum, sum1);
		else if (sum == sum1)
			printf("�÷��̾� %d���� ���� %d������ ���º��Դϴ�.\n", sum, sum1);
	}
	else if (sum > 21 && sum1 <= 21)
		printf("�÷��̾��� �а� 21�� �Ѿ� �й��ϼ̽��ϴ�.\n");
	else if (sum > 21 && sum1 > 21)
		printf("�÷��̾�� ���� ���21�� �Ѿ� ���º��Դϴ�.\n");


must1:
	printf("\n\n �ѹ� �� �Ͻðڽ��ϱ�(Y/N) ?  ");
	fflush(stdin);
	scanf("%c", &cho);
	if (cho == 'Y' || cho == 'y')
	{
		system("pause");
		system("cls");
		goto must;
	}
	else
		printf("\n������ �����մϴ�.\n\n");


}

int pick()
{
	int player[50]; //������ ��Ÿ����
	int a;
	char *pmark[5];
	int dealer;
	int i, j;//ī�带 �����ϱ����� ����
	char cho;
	int sum = 0;


	i = 0;
	j = 0;

	Sleep(1001);  // �����Լ��� srand�� �ȴ��߸� �ð����� �ʹ� ª�Ƽ� ���� ������ ī�尡 ��� ����;;
	srand(time(NULL));

	i = rand() % 4;  //���⼭ ���� ������ ����

	if (i == 0) //���翡 ���� ���ڰ��� ������
	{
		while (1)
		{

			j = rand() % 13;
			a = j;
			if (Sdeck[j] != 0)
				break;
		}
		player[a] = Sdeck[j];
		Sdeck[j] = 0;
		if (j == 0)
			ace++;
	}
	else if (i == 1)
	{
		while (1)
		{
			j = rand() % 13;
			a = j;
			if (Cdeck[j] != 0)
				break;
		}
		player[a] = Cdeck[j];
		Cdeck[j] = 0;
		if (j == 0)
			ace++;
	}
	else if (i == 2)
	{
		while (1)
		{
			j = rand() % 13;
			a = j;
			if (Ddeck[j] != 0)
				break;
		}
		player[a] = Ddeck[j];
		Ddeck[j] = 0;
		if (j == 0)
			ace++;
	}
	else
	{
		while (1)
		{
			j = rand() % 13;
			a = j;
			if (Hdeck[j] != 0)
				break;
		}
		player[a] = Hdeck[j];
		Hdeck[j] = 0;
		if (j == 0)
			ace++;
	}

	if (j > 9 && j < 13)
		sum = 10;
	else if (j == 0)
		sum = 11;
	else
		sum = (j + 1);

	if (j == 9)
	{
		player[9] = 10;
		printf("%s%d ", &mark[i], player[9]);
	}
	else
		printf("%s%c ", &mark[i], player[a]);

	return sum; //������ ī�尪 ����
}

int pick2()
{
	int player[50]; //������ ��Ÿ����
	int a;
	char *pmark[5];
	int dealer;
	int i, j;//ī�带 �����ϱ����� ����
	char cho;
	int sum = 0;


	i = 0;
	j = 0;

	Sleep(1001);  // �����Լ��� srand�� �ȴ��߸� �ð����� �ʹ� ª�Ƽ� ���� ������ ī�尡 ��� ����;;
	srand(time(NULL));

	i = rand() % 4;  //���⼭ ���� ������ ����

	if (i == 0) //���翡 ���� ���ڰ��� ������
	{
		while (1)
		{

			j = rand() % 13;
			a = j;
			if (Sdeck[j] != 0)
				break;
		}
		player[a] = Sdeck[j];
		Sdeck[j] = 0;
		if (j == 0)
			ace2++;
	}
	else if (i == 1)
	{
		while (1)
		{
			j = rand() % 13;
			a = j;
			if (Cdeck[j] != 0)
				break;
		}
		player[a] = Cdeck[j];
		Cdeck[j] = 0;
		if (j == 0)
			ace2++;
	}
	else if (i == 2)
	{
		while (1)
		{
			j = rand() % 13;
			a = j;
			if (Ddeck[j] != 0)
				break;
		}
		player[a] = Ddeck[j];
		Ddeck[j] = 0;
		if (j == 0)
			ace2++;
	}
	else
	{
		while (1)
		{
			j = rand() % 13;
			a = j;
			if (Hdeck[j] != 0)
				break;
		}
		player[a] = Hdeck[j];
		Hdeck[j] = 0;
		if (j == 0)
			ace2++;
	}

	if (j > 9 && j < 13)
		sum = 10;
	else if (j == 0)
		sum = 11;
	else
		sum = (j + 1);

	if (j == 9)
	{
		player[9] = 10;
		printf("%s%d ", &mark[i], player[9]);
	}
	else
		printf("%s%c ", &mark[i], player[a]);

	return sum; //������ ī�尪 ����
}
