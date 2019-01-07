/*
2016년 6월 7일 발표
2조(교수님과제좀줄여주시조)

소요시간은 [(이동시간 * 2 ) + 30분] 입니다.

*/


#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

// 파이값 정의
#define PI 3.14


// 필요한 장소 정의
#define FOOD 10
#define HOSPITAL 11
#define CAFE 12
#define CULTURE 13

#define LAT1 37.4860346
#define LONG1 126.8064405

/* 필요한 함수 선언*/
// 초기 시작
void control();
// 거리 계산
double gc_distance(double lat1, double long1, double lat2, double long2);
// 위치 입력, 그외의 잡다한 입력
void input();
// 지도 출력
void mapDisplay(int place);
// 메인 메뉴
int menu();
// 도움말 출력
void help();
// 필터링?
void calculator(int kind, int destination, int vehicle, int time);
// 로딩 화면
void loading();
// 시간이 충분한 지 확인
void isEnough(int empty, double time);



// 메인 함수
int main()
{
	control();
	return 0;
}


/*함수 정의*/
void control()
{
	int n;
	do {

		n = menu();
		switch (n)
		{
		case 1:
			input();
			break;
		case 2:
			help();
			break;
		case 0:

			printf("\n\n\n프로그램을 종료합니다...\n\n");
			Sleep(500);
			return 0;
			break;
		default:
			printf("다시 입력해주세요...\n");
			Sleep(500);
		}
	} while (n != 0);
}
void input()
{
	int time, kind, destination, vehicle = 0;
	double lat1, lat2, long1, long2;
	int i = 0;

	system("cls");
	printf("\n───────────────────────────────────\n");
	printf("\t\t\t공강 시간이 몇 시간인가요?\n");
	printf("\n\t\t\t입력: ");
	scanf("%d", &time);
	printf("\n───────────────────────────────────\n");
	printf("\n\t\t\t어디에 가실건가요?\n\n");
	printf("\t\t\t1. 식사\n\n\t\t\t2. 카페\n\n\t\t\t3. 병원\n\n\t\t\t4. 기타\n\n\t\t\t입력: ");
	scanf("%d", &kind);
	printf("\n───────────────────────────────────\n");

	switch (kind)
	{
	case 1:
		kind = FOOD;
		break;
	case 2:
		kind = CAFE;
		break;
	case 3:
		kind = HOSPITAL;
		break;
	case 4:
		kind = CULTURE;
	}
	mapDisplay(kind);
	printf("\n  ** 가고 싶은 곳 입력: ");
	scanf("%d", &destination);
	printf("\n  ** 어떻게 가실건가요?");
	printf("\n  1. 걸어서\n  2. 자전거를 타고\n  입력: ");
	scanf("%d", &vehicle);
	loading();
	loading();

	calculator(kind, destination, vehicle, time);
	getch();

}

double gc_distance(double lat1, double long1, double lat2, double long2)
{
	double rho, phi, theta, gamma, dot, dist1, dist2, x1, y1, z1, x2, y2, z2;

	// 경도 위도를 직교 좌표로 전환

	rho = 3960;
	phi = (90 - lat1) * (PI / 180.0);
	theta = (360 - long1)*(PI / 180.0);
	// 위치 1
	x1 = rho*sin(phi) *cos(theta);
	y1 = rho*sin(phi) *sin(theta);
	z1 = rho*cos(phi);
	phi = (90 - lat2) * (PI / 180.0);
	theta = (360 - long2)*(PI / 180.0);
	// 위치 2
	x2 = rho*sin(phi) *cos(theta);
	y2 = rho*sin(phi) *sin(theta);
	z2 = rho*cos(phi);

	// 벡터 사이의 각을 계산
	dot = x1* x2 + y1* y2 + z1* z2;
	dist1 = sqrt(x1* x1 + y1* y1 + z1* z1);
	dist2 = sqrt(x2* x2 + y2* y2 + z2* z2);
	gamma = acos(dot / (dist1 * dist2));

	return gamma * rho * 1.6;

}

void mapDisplay(int place)
{
	double start;

	switch (place)
	{
	case FOOD:

		system("cls");
		printf("\t\t\t** 학교 주변 지도**\n");
		printf(" 정문\n");
		printf("  ◈━━━━━━━━┳━━━━┳━━━━┳━━━━━━━━━━━━━━━━┓\n");
		printf("  ┃ ＼             ┃        ┃        ┃                              ⑧┃\n");
		printf("  ┃   ＼           ┃        ┃        ┃                      브라운치킨┃\n");
		printf("  ┃    ┣━━━━━┫        ┣━━━━┫                                ┃\n");
		printf("  ┃    ┃          ┃        ┃        ┃                                ┃\n");
		printf("  ┃    ┃          ┃        ┃        ┃                                ┃\n");
		printf("  ┣━━╋━━━━━╋━━━━┻━━━━╋━━━━━━━━┳━━━━━━━┫\n");
		printf("  ┃    ┃          ┃                  ┃                ┃              ┃\n");
		printf("  ┃    ┃          ┃                  ┃                ┃              ┃\n");
		printf("  ┃    ┃          ┣━━━━━━━━━╋━━━━━━━━╋━━━━━━━┫\n");
		printf("  ┃    ┃          ┃                  ┃복사골  만득이네┃ 롯데리아     ┃\n");
		printf("  ┃    ┃          ┃                  ┃⑤          ⑥  ┃    ⑦        ┃\n");
		printf("  ┣━━┻━━━━━┻━━━━━━━━━┻━━━━━━━━┻━━━━━━━┫\n");
		printf("  ┃            ②         ③               ④                            ┃\n");
		printf("  ┃        대가닭갈비   피자마루         신의주                        역곡역\n");
		printf(" |┃|=====================================================================▣\n");
		printf("  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  ");
		printf("          ①                                                                \n");
		printf("      피자헛                                                              \n");
		break;
	case CAFE:
		system("cls");
		printf("\t\t\t** 학교 주변 지도**\n");
		printf(" 정문\n");
		printf("  ◈━━━━━━━━┳━━━━┳━━━━┳━━━━━━━━━━━━━━━━┓\n");
		printf("  ┃ ＼   ① 이디야 ┃        ┃        ┃                                ┃\n");
		printf("  ┃   ＼           ┃        ┃        ┃                                ┃\n");
		printf("  ┃    ┣━━━━━┫        ┣━━━━┫                                ┃\n");
		printf("  ┃    ┃    ②    ┃        ┃        ┃                                ┃\n");
		printf("  ┃    ┃ No.1 등  ┃        ┃        ┃                                ┃\n");
		printf("  ┣━━╋━━━━━╋━━━━┻━━━━╋━━━━━━━━┳━━━━━━━┫\n");
		printf("  ┃    ┃          ┃                  ┃                ┃              ┃\n");
		printf("  ┃    ┃          ┃                  ┃                ┃              ┃\n");
		printf("  ┃    ┃          ┣━━━━━━━━━╋━━━━━━━━╋━━━━━━━┫\n");
		printf("  ┃    ┃          ┃     요거프레소   ┃                ┃              ┃\n");
		printf("  ┃    ┃          ┃         ④       ┃                ┃              ┃\n");
		printf("  ┣━━┻━━━━━┻━━━━━━━━━┻━━━━━━━━┻━━━━━━━┫\n");
		printf("  ┃                                                          던킨도너츠⑤┃\n");
		printf("  ┃                                                                   역곡역\n");
		printf(" |┃|=====================================================================▣\n");
		printf("  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  ");
		printf("                       ③                                                  \n");
		printf("                    스타벅스                                               \n");
		break;
	case HOSPITAL:
		system("cls");
		printf("\t\t\t** 학교 주변 지도**\n");
		printf(" 정문\n");
		printf("  ◈━━━━━━━━┳━━━━┳━━━━┳━━━━━━━━━━━━━━━━┓\n");
		printf("  ┃ ＼             ┃        ┃        ┃                                ┃\n");
		printf("  ┃   ＼           ┃        ┃        ┃                                ┃\n");
		printf("  ┃    ┣━━━━━┫        ┣━━━━┫                                ┃\n");
		printf("  ┃    ┃          ┃        ┃        ┃                                ┃\n");
		printf("  ┃    ┃          ┃        ┃        ┃                                ┃\n");
		printf("  ┣━━╋━━━━━╋━━━━┻━━━━╋━━━━━━━━┳━━━━━━━┫\n");
		printf("  ┃    ┃          ┃                  ┃                ┃              ┃\n");
		printf("  ┃    ┃          ┃                  ┃                ┃              ┃\n");
		printf("  ┃    ┃          ┣━━━━━━━━━╋━━━━━━━━╋━━━━━━━┫\n");
		printf("  ┃    ┃          ┃                  ┃                ┃    김앤정외과┃\n");
		printf("  ┃    ┃          ┃                  ┃                ┃            ④┃\n");
		printf("  ┣━━┻━━━━━┻━━━━━━━━━┻━━━━━━━━┻━━━━━━━┫\n");
		printf("  ┃                           ①                                         ┃\n");
		printf("  ┃                      연세사랑병원                                  역곡역\n");
		printf(" |┃|=====================================================================▣\n");
		printf("  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  ");
		printf("                                   ②                       ③              \n");
		printf("                              현대정형외과          서울 중앙내과의원       \n\n");
		break;
	case CULTURE:
		system("cls");
		printf("\t\t\t** 학교 주변 지도**\n");
		printf(" 정문\n");
		printf("  ◈━━━━━━━━┳━━━━┳━━━━┳━━━━━━━━━━━━━━━━┓\n");
		printf("  ┃ ＼             ┃        ┃        ┃                                ┃\n");
		printf("  ┃   ＼           ┃        ┃        ┃                                ┃\n");
		printf("  ┃    ┣━━━━━┫        ┣━━━━┫                                ┃\n");
		printf("  ┃    ┃          ┃        ┃        ┃                                ┃\n");
		printf("  ┃    ┃          ┃        ┃        ┃                                ┃\n");
		printf("  ┣━━╋━━━━━╋━━━━┻━━━━╋━━━━━━━━┳━━━━━━━┫\n");
		printf("  ┃    ┃          ┃                  ┃                ┃              ┃\n");
		printf("  ┃    ┃          ┃                  ┃                ┃              ┃\n");
		printf("  ┃    ┃          ┣━━━━━━━━━╋━━━━━━━━╋━━━━━━━┫\n");
		printf("  ┃    ┃          ┃                  ┃                ┃              ┃\n");
		printf("  ┃    ┃          ┃                  ┃                ┃              ┃\n");
		printf("  ┣━━┻━━━━━┻━━━━━━━━━┻━━━━━━━━┻━━━━━━━┫\n");
		printf("  ┃                                                                      ┃\n");
		printf("  ┃                                                                    역곡역\n");
		printf(" |┃|=====================================================================▣\n");
		printf("  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  ");
		printf("                                                              ①           \n");
		printf("                                                           역곡 CGV        \n\n");
		break;
	default:
		break;
	}
}

int menu()
{
	int n = -1;
	system("cls");
	printf("\n┌──────────────────────────────────┐\n");
	printf("│                      공강 시간 활용하기                            │\n");
	printf("└──────────────────────────────────┘\n");
	printf("\n\n");
	printf("\t\t\t1. 시작\n\n");
	printf("\t\t\t2. 도움말\n\n");
	printf("\t\t\t0. 종료\n\n");
	printf("───────────────────────────────────\n");
	printf("\t\t\t입력: ");
	scanf("%d", &n);
	return n;
}

void help()
{
	system("cls");
	printf("\n┌──────────────────────────────────┐\n");
	printf("│                               도움말                               │\n");
	printf("└──────────────────────────────────┘\n");
	printf("\n\n");

	printf("\t\t\t1. 이 프로그램은 공강시간 때 시간 활용을 도와주는\n\n");
	printf("\t\t\t   프로그램입니다.\n\n");
	printf("\t\t\t2. 예상시간은 (이동시간 * 2 ) + 30분입니다.\n\n");
	printf("\t\t\t ");
	printf("\t\t\t(계속하려면 아무키나 누르세요)");

	getch();
}

void calculator(int kind, int destination, int vehicle, int time)
{
	double distance = 0;
	mapDisplay(kind);
	printf("☞정문부터 ");
	switch (kind)
	{
	case FOOD:
	{
		switch (destination)
		{
		case 1:
			printf("피자헛");
			distance = gc_distance(LAT1, LONG1, 37.4818353, 126.8064405); // 정문 -> 피자헛
			break;
		case 2:
			printf("대가닭갈비");
			distance += gc_distance(LAT1, LONG1, 37.4837184, 126.8055781);            // 정문 -> 은강장로교회
			distance += gc_distance(37.4837184, 126.8055781, 37.48446, 126.8078028);   // 은강장로교회 -> 대가닭갈비
			break;
		case 3:
			printf("피자마루");
			distance += gc_distance(LAT1, LONG1, 37.4870596, 126.8078);               // 정문 -> 삼신부동산 컨설팅
			distance += gc_distance(37.4870596, 126.8078, 37.4850177, 126.8095227);      // 삼신부동산컨설팅 -> 피자마루 
			break;
		case 4:
			printf("신의주");
			distance += gc_distance(LAT1, LONG1, 37.4857482, 126.805541);            // 정문 -> 일퍼센트
			distance += gc_distance(37.4857482, 126.805541, 37.484342, 126.806324);      // 일퍼센트 -> OK카서비스
			distance += gc_distance(37.484342, 126.806324, 37.4848979, 126.8089087);   // OK카서비스 -> 신의주
			break;
		case 5:
			printf("복사골");
			distance += gc_distance(LAT1, LONG1, 37.487907, 26.810414);               // 정문 -> 김옥 헤어샵
			distance += gc_distance(37.487907, 26.810414, 37.4876144, 126.8105781);      // 김옥헤어샵 -> 복사골
			break;
		case 6:
			printf("만득이네");
			distance += gc_distance(LAT1, LONG1, 37.4870596, 126.8078);               // 정문 -> 삼신부동산 컨설팅
			distance += gc_distance(37.4870596, 126.8078, 37.4852063, 126.8087225);      // 삼신부동산 -> CU 역곡2동점
			distance += gc_distance(37.4852063, 126.8087225, 37.485504, 126.8099261);   // CU 역곡2동점 -> 만득이네
			break;
		case 7:
			printf("롯데리아");
			distance += gc_distance(LAT1, LONG1, 37.4870596, 126.8078);               // 정문 -> 삼신부동산 컨설팅
			distance += gc_distance(37.4870596, 126.8078, 37.4852063, 126.8087225);      // 삼신부동산 -> CU 역곡2동점
			distance += gc_distance(37.4852063, 126.8087225, 37.4858194, 126.8106152);   // CU 역곡2동점 -> 롯데리아 역곡역점
			break;
		case 8:
			printf("브라운치킨");
			distance += gc_distance(LAT1, LONG1, 37.487907, 26.810414);               // 정문 -> 김옥 헤어샵
			distance += gc_distance(37.487907, 26.810414, 37.487764, 126.8105065);      // 김옥헤어샵 -> 브라운치킨
			break;
		}
	}
	break;
	case CAFE:
	{
		switch (destination)
		{
		case 1:
			printf("이디야 커피");
			distance += gc_distance(LAT1, LONG1, 37.48618, 126.8051319);            // 정문 -> 이디야 커피
			break;
		case 2:
			printf("No.1, 다방구 등등");
			distance += gc_distance(LAT1, LONG1, 37.4857482, 126.8058625);            // 정문 -> 일퍼센트
			distance += gc_distance(37.4857482, 126.8058625, 37.4852263, 126.8058625);   // 일퍼센트 -> 다방구 등등
			break;
		case 3:
			printf("스타벅스");
			distance += gc_distance(LAT1, LONG1, 37.482308, 126.8060405);            // 정문 -> 통일기계
			distance += gc_distance(37.482308, 126.8060405, 37.4835098, 126.8092870);   // 통일기계 -> 스타벅스
			break;
		case 4:
			printf("요거프레소");
			distance += gc_distance(LAT1, LONG1, 37.4857482, 126.805541);            // 정문 -> 일퍼센트
			distance += gc_distance(37.4857482, 126.805541, 37.484342, 126.806324);      // 일퍼센트 -> OK카서비스
			distance += gc_distance(37.484342, 126.806324, 37.484995, 126.808245);      // OK카서비스 -> 요거프레소
			break;
		case 5:
			printf("던킨도너츠");
			distance += gc_distance(LAT1, LONG1, 37.4870596, 126.8078);               // 정문 -> 삼신부동산 컨설팅
			distance += gc_distance(37.4870596, 126.8078, 37.4852063, 126.8087225);      // 삼신부동산 -> CU 역곡2동점
			distance += gc_distance(37.4852063, 126.8087225, 37.4856305, 126.8115001);   // CU 역곡2동점 -> 던킨도너츠 역곡북부점
			break;
		default:
			break;
		}
	}
	break;
	case HOSPITAL:
	{
		switch (destination)
		{
		case 1:
			printf("연세사랑병원");
			distance += gc_distance(LAT1, LONG1, 37.4857482, 126.805541);            // 정문 -> 일퍼센트
			distance += gc_distance(37.4857482, 126.805541, 37.484342, 126.806324);      // 일퍼센트 -> OK카서비스
			distance += gc_distance(37.484342, 126.806324, 37.4846747, 126.8083694);   // OK카서비스 -> 연세사랑병원
			break;
		case 2:
			printf("현대정형외과");
			distance += gc_distance(LAT1, LONG1, 37.4823263, 126.8060375);            // 정문 -> 통일기계
			distance += gc_distance(37.4823263, 126.8060375, 37.4828519, 126.8091027);   // 통일기계 -> 현대정형외과
			break;
		case 3:
			printf("서울 중앙내과의원");
			distance += gc_distance(LAT1, LONG1, 37.4823263, 126.8060375);            // 정문 -> 통일기계
			distance += gc_distance(37.4823263, 126.8060375, 37.4829817, 126.8092769);   // 통일기계 -> 토성잠실감자탕
			distance += gc_distance(37.4829817, 126.8092769, 37.4827353, 126.8098152);   // 토성잠실감자탕 -> 엄마약국
			distance += gc_distance(37.4827353, 126.8098152, 37.4828258, 126.8106412);   // 엄마약국 -> 서울 중앙내과의원
			break;
		case 4:
			printf("김앤장외과");
			distance += gc_distance(LAT1, LONG1, 37.4870596, 126.8078);               // 정문 -> 삼신부동산 컨설팅
			distance += gc_distance(37.4870596, 126.8078, 37.4852063, 126.8087225);      // 삼신부동산 -> CU 역곡2동점
			distance += gc_distance(37.4852063, 126.8087225, 37.485974, 126.8113071);   // CU 역곡2동점 ->
			break;
		}
	}
	break;
	case CULTURE:
	{
		switch (destination)
		{
		case 1:
			printf("역곡 CGV");
			distance += gc_distance(LAT1, LONG1, 37.4823263, 126.8060375);            // 정문 -> 통일기계
			distance += gc_distance(37.4823263, 126.8060375, 37.4843846, 126.81125);   // 통일기계 -> 역곡 CGV
			break;

		}
	}
	break;
	default:
		break;
	}
	printf("까지의 거리: %.3fm\n", distance * 1000);


	if (vehicle == 1)
		vehicle = 4;
	else
		vehicle = 15;


	printf("☞이동 시간: 약 %.1lf분", distance / vehicle * 60);

	printf("\n");
	isEnough(time, distance / vehicle * 60);
	getch();
}

void loading()
{
	int i = 0, j = 0;
	do
	{
		system("cls");
		printf("\n\n\n거리와 소요시간을 계산하는 중");
		for (j = 0; j < i + 1; j++)
			printf(".");
		Sleep(150);
		i++;
	} while (i < 5);
}

void isEnough(int empty, double time)
{
	char ch;
	printf("☞예상 소요시간: %.1lf분", (time * 2 + 30));
}
