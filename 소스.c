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

		printf("�޸� ���� �Ҵ� ����\n");

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

	printf("1. ��ȭ ���� �߰�\n");

	printf("2. ��ȭ ���� ���\n");

	printf("3. ����\n");

	printf("-------------------------------------\n");

}

int get_selectde_menu() {

	int selmenu = 0;

	printf("��ȣ�� �����Ͻÿ� : ");

	scanf("%d", &selmenu);

	return selmenu;

}

DATA get_input() {

	DATA input;

	printf("��ȭ�� ������ �Է��Ͻÿ� : ");

	scanf("%s", input.title);

	printf("��ȭ�� �帣�� �Է��Ͻÿ� : ");

	scanf("%s", input.genre);

	printf("��ȭ�� ���� ������ �Է��Ͻÿ� : ");

	scanf("%d", &input.year);

	printf("��ȭ�� ���� ���� �Է��Ͻÿ� : ");

	scanf("%s", &input.num);
	return input;

}

void print_list(NODE* plist) {

	NODE* ptr;

	for (ptr = plist; ptr; ptr = ptr->link) {

		printf("-------------------------------------\n");

		printf("�� �� : %s\n", ptr->data.title);
		printf("�� �� : %s\n", ptr->data.genre);
		printf("���� ���� : %d\n", ptr->data.year);
		printf("���� �� : %s\n", ptr->data.num);
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
			printf("����Ǿ����ϴ�.");
			break;

		}

	}

	return 0;

}