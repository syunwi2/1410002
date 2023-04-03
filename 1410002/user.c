#include "user.h"
#include "menu.h"


#define LEFT 75			// ����Ű�� �ƽ�Ű�ڵ尪
#define RIGHT 77


// ============ �α��� �Ϸ�  ================
PERSON* UserPtr(PERSON user)
{
	// ����ü user �����޸� �Ҵ�
	PERSON* user_ptr = malloc(sizeof(PERSON));

	// ����ü ��� �� �Ҵ�
	strcpy(user_ptr->id, user.id);
	strcpy(user_ptr->name, user.name);
	strcpy(user_ptr->pw, user.pw);
	user_ptr->dept = user.dept;
	user_ptr->birthday = user.birthday;
	
	return user_ptr;
}


void LogOn(PERSON user, char(*dept_str)[20])
{
	PERSON* user_ptr = UserPtr(user);

	// ============ �α׿� ȭ�� ================


	system("cls");
	gotoxy(3, 1);
	// Heap���� ������ ���
	printf("ȯ���մϴ�. %s�� :) \n", user_ptr->name);
	printf("\n     id : %3s, �μ� : %3s  \n",
		user_ptr->id, dept_str[user_ptr->dept]);


	// �޷� ���
	Calender();


	//PrivateFileLoad();


	// menu ���
	Menu(user_ptr);


}