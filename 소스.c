#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define INSERT 1

#define PRINT 2

#define QUIT 3

#define S_SIZE 50

typedef struct data {

	char title[S_SIZE];
	char genre[S_SIZE];
	int year;
	char num[S_SIZE];
}

DATA;

typedef struct NODE {

	DATA data;

	struct NODE* link;

}

NODE;

NODE* insert_node(NODE* plist, NODE* pprev, DATA item) {

	NODE* pnew = NULL;

	if (!(pnew = (NODE*)malloc(sizeof(NODE)))) {

		printf("메모리 동적 할당 오류\n");

		exit(1);

	}

	pnew->data = item;

	if (pprev == NULL) {

		pnew->link = plist;

		plist = pnew;

	}
	else {

		pnew->link = pprev->link;

		pprev->link = pnew;

	}

	return plist;

}

void display_menu() {

	printf("-------------------------------------\n");

	printf("1. 영화 정보 추가\n");

	printf("2. 영화 정보 출력\n");

	printf("3. 종료\n");

	printf("-------------------------------------\n");

}

int get_selectde_menu() {

	int selmenu = 0;

	printf("번호를 선택하시오 : ");

	scanf("%d", &selmenu);

	return selmenu;

}

DATA get_input() {

	DATA input;

	printf("영화의 제목을 입력하시오 : ");

	scanf("%s", input.title);

	printf("영화의 장르를 입력하시오 : ");

	scanf("%s", input.genre);

	printf("영화의 개봉 연도를 입력하시오 : ");

	scanf("%d", &input.year);

	printf("영화의 관객 수를 입력하시오 : ");

	scanf("%s", &input.num);
	return input;

}

void print_list(NODE* plist) {

	NODE* ptr;

	for (ptr = plist; ptr; ptr = ptr->link) {

		printf("-------------------------------------\n");

		printf("제 목 : %s\n", ptr->data.title);
		printf("장 르 : %s\n", ptr->data.genre);
		printf("개봉 연도 : %d\n", ptr->data.year);
		printf("관객 수 : %s\n", ptr->data.num);
	}

	printf("-------------------------------------\n");

}

void destroy_nodes(NODE* plist) {

	NODE* temp;

	while (plist) {

		temp = plist;

		plist = plist->link;

		free(temp);

	}

}

int main(void) {

	NODE* plist = NULL;

	int selected = 0;

	DATA d;

	while (selected != QUIT) {

		display_menu();

		selected = get_selectde_menu();

		switch (selected) {

		case INSERT:

			d = get_input();

			plist = insert_node(plist, NULL, d);

			break;

		case PRINT:

			print_list(plist);

			break;

		case QUIT:

			destroy_nodes(plist);
			printf("종료되었습니다.");
			break;

		}

	}

	return 0;

}