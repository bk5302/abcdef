// A를 아직 1로밖에 못씀;;
// rand함수에서 같은 시드값이 계속들어감;;  --> Sleep 함수로막음;; 그래서 카드가 2초마다 하나씩뽑힘

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

char Sdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' }; //일단 A는 1이라고만 생각함
char Cdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' };
char Ddeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' };
char Hdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' };
char mark[4][4] = { "♤", "♧", "◇", "♡" };

int pick(); //무작위로 겹치지 않는 카드를 뽑는함수
int pick2(); //딜러의 패중 숨겨진패뽑음
int ace = 0;
int ace2 = 0;
void main()
{
	int player[50]; //게임중 나타나는
	char *pmark[5];//게임중 나타나는 

	int i, j;//카드를 선택하기위한 변수
	int k, l;
	int sum = 0; //플레이어
	int sum1 = 0; //딜러
	int sum2 = 0;

	char cho;


must:
	sum = 0;
	sum1 = 0;
	printf("게임시작\n");
	printf("우선 각각 두장의 카드를 받습니다.\n\n");

	system("pause");
	system("cls");

	printf("딜러의 패\n");
	printf("■ "); //한장가리는 패
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
	printf("\n딜러의 점수는 %d입니다.", sum1);
	if (sum1 > 21)
	{
		printf("\n딜러의 패가 21이 넘어 플레이어가 승리하셨습니다.\n");
		goto must1;
	}
	printf("\n\n\n\n\n");

	printf("플레이어의 패\n");
	for (k = 0; k < 2; k++) //플레이어의 패
		sum = sum + pick();


	while (1) //플레이어의 패

	{
	must2:
		if (sum >= 21)
			break;

		printf("\n현재 %d점입니다.\n", sum);
		printf("카드를 더 받을지 선택하시오(Y/N) :  ");
		fflush(stdin);
		scanf("%c", &cho);
		if (cho == 'y' || cho == 'Y') //한번더 받고싶으면 더받음
		{
			sum = sum + pick();

			if (sum > 21)
				break;
		}
		else if (cho == 'N' || cho == 'n')
		{
			printf("총 %d점입니다.\n\n", sum);
			break; // 받기 싫으면 와일문에서 빠져나감
		}
		else if (sum > 21)
			break;


	}//플레이어 와일문 끝

	//플레이어와 딜러의 점수 비교
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
			printf("플레이어가 %d 대 %d로 승리하셨습니다\n.", sum, sum1);
		else if (sum<sum1)
			printf("플레이어가가 %d 대 %d로 패배하셨습니다.\n", sum, sum1);
		else if (sum == sum1)
			printf("플레이어 %d점과 딜러 %d점으로 무승부입니다.\n", sum, sum1);
	}
	else if (sum > 21 && sum1 <= 21)
		printf("플레이어의 패가 21이 넘어 패배하셨습니다.\n");
	else if (sum > 21 && sum1 > 21)
		printf("플레이어와 딜러 모두21이 넘어 무승부입니다.\n");


must1:
	printf("\n\n 한번 더 하시겠습니까(Y/N) ?  ");
	fflush(stdin);
	scanf("%c", &cho);
	if (cho == 'Y' || cho == 'y')
	{
		system("pause");
		system("cls");
		goto must;
	}
	else
		printf("\n게임을 종료합니다.\n\n");


}

int pick()
{
	int player[50]; //게임중 나타나는
	int a;
	char *pmark[5];
	int dealer;
	int i, j;//카드를 선택하기위한 변수
	char cho;
	int sum = 0;


	i = 0;
	j = 0;

	Sleep(1001);  // 슬립함수로 srand를 안늦추면 시간텀이 너무 짧아서 같은 문양의 카드가 계속 뽑힘;;
	srand(time(NULL));

	i = rand() % 4;  //여기서 앞의 문양이 결정

	if (i == 0) //문양에 따라서 숫자값을 가져감
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

	return sum; //저장한 카드값 리턴
}

int pick2()
{
	int player[50]; //게임중 나타나는
	int a;
	char *pmark[5];
	int dealer;
	int i, j;//카드를 선택하기위한 변수
	char cho;
	int sum = 0;


	i = 0;
	j = 0;

	Sleep(1001);  // 슬립함수로 srand를 안늦추면 시간텀이 너무 짧아서 같은 문양의 카드가 계속 뽑힘;;
	srand(time(NULL));

	i = rand() % 4;  //여기서 앞의 문양이 결정

	if (i == 0) //문양에 따라서 숫자값을 가져감
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

	return sum; //저장한 카드값 리턴
}
