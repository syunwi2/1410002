#include <stdio.h>
#include "schedule.h"
#include "create.h"
#include "delete.h"
#include "screen.h"

void test();

int main() 
{
	system("mode con cols=86 lines=35");  // 콘솔 사이즈 조절 함수
	MainScreen();						  // 메인 화면 출력 
}