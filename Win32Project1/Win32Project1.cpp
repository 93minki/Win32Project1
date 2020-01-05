// Win32Project1.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Win32Project1.h"
#include "resource.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_LOADSTRING 100

#define MAX_STACK_SIZE 30

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

char InputNum[MAX_STACK_SIZE];
char GetNum[MAX_STACK_SIZE];
char totalSign[10];
char arraytemp[MAX_STACK_SIZE];

char TempArray[MAX_STACK_SIZE];
char arrayclear[MAX_STACK_SIZE] = { '\0', };
int TempNum[MAX_STACK_SIZE];
char TempSign[MAX_STACK_SIZE];


char stack[MAX_STACK_SIZE];									// Stack
int top = -1;										// Init Stack Point

int Search_n = 0;									// Search Number 
int Search_s = 0;									// Search Sign

int StackNum[MAX_STACK_SIZE];									// Get Number in Stack
char StackSign[MAX_STACK_SIZE];								// Get Sign in Stack

int k = 0;
int arraySize;
int rstsum;
int Temp1;
int Temp2;
int Temp3;
double intoNum1;									// num1 배열을 int로 변환
double intoNum2;									// num2 배열을 int로 변환
double sum1;										// 결과 값
// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
//ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    DlgProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
	AllocConsole();
	freopen("CONOUT$", "wt", stdout);
	//AttachConsole(GetCurrentProcessId());
	//freopen("CON", "w", stdout);
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);

	return 0;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

bool IsEmpty() {
	if (top < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool IsFull() {
	if (top > MAX_STACK_SIZE) {
		return true;
	}
	else {
		return false;
	}
}

void push(char value) {
	if (IsFull() == true) {
		printf("Stack is Full");
	}
	else {
		stack[++top] = value;
	}
}

char pop() {
	if (IsEmpty() == true) {
		printf("Stack is Empty");
	}
	else {
		return stack[top--];
	}
}

void showNum(char num, HWND hDlg) {
	push(num);
	SetDlgItemText(hDlg, IDC_EDIT1, stack);

}

void showDot(char dot, HWND hDlg) {
	if (stack[top] == '.') {
		return;
	}
	else {
		push(dot);
	}
	SetDlgItemText(hDlg, IDC_EDIT1, stack);
}

void showSign(char sign, HWND hDlg) {
	if (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/') {
		stack[top] = sign;
	}
	else {
		push(sign);
	}
	
	SetDlgItemText(hDlg, IDC_EDIT1, stack);
}
// Get Stack Size 
int GetStackSize() {
	int StackSize;
	for (int a = 0; a < sizeof(stack); a++) {
		if (stack[a] == '\0') {
			StackSize = a;
			return StackSize;
		}
	}
}

void InitTempArray() {
	for (int i = 0; i < sizeof(TempArray); i++) {
		TempArray[i] = '\0';
	}
	
}

void showOutput(HWND hDlg) {
	printf("Get Number : %s\n", stack);
	printf("Size of Stack : %d\n", GetStackSize());
	int StackSize = GetStackSize();
	int tn = 0;
	int ts = 0;
	
	// Search Stack
	for (int i = 0; i < StackSize; i++) {
		// if Stack Value is Sign 
		if (stack[i] == '+' || stack[i] == '-' || stack[i] == '*' || stack[i] == '/') {
			Search_s = i;
			for (int tp = 0; Search_n < Search_s; Search_n++, tp++) {
				TempArray[tp] = stack[Search_n];
			}
			// Initialize TempArray
			InitTempArray();
			// Show Error MessageBox if last stack element is Arithmetic Symbol
			if (stack[i + 1] == '\0') {
				MessageBox(hDlg, "Wrong formula!!!", "Formula Error", MB_OK);
			}
			TempSign[ts] = stack[i];
			TempNum[tn] = atoi(TempArray) ;

			Search_n = Search_s + 1;
			tn++;
			ts++;
			
		}
		if (stack[i + 1] == '\0'){
			Search_s = i + 1;
			for (int tp = 0; Search_n < Search_s; Search_n++, tp++) {
				TempArray[tp] = stack[Search_n];
			}
			TempNum[tn] = atoi(TempArray);
			InitTempArray();
			
		}
	}


	for (int k = 0; k < MAX_STACK_SIZE; k++) {
		printf("Number in Stack  : %d \n", TempNum[k]);
		printf("Sign in Stack : %c \n", TempSign[k]);
		if (TempNum[k] == '\0' && TempSign[k] == '\0')
		{
			break;
		}
	}
	

	


}

void ClearArray(HWND hDlg) {
	for (int a = 0; a < sizeof(InputNum); a++) {
		InputNum[a] = '\0';
	}
	int i = 0;
	SetDlgItemText(hDlg, IDC_EDIT1, InputNum);
	
	printf("InputNum : %s \n", InputNum);
}
// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	//printf("DlgProc\n");
    UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:

		SetDlgItemText(hDlg, IDC_EDIT1, "0");
		printf("init\n");
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		//printf("btn0\n");
		switch (LOWORD(wParam)) {
		case IDC_BUTTON1:	// 0
			printf("0\n");
			showNum('0', hDlg);
			break;
		case IDC_BUTTON2:	// .
			printf(".\n");
			showDot('.', hDlg);
			break;
		case IDC_BUTTON3:	// Enter
			printf("Enter\n");
			showOutput(hDlg);
			break;
		case IDC_BUTTON4:	// 1
			printf("1\n");
			showNum('1', hDlg);
			break;
		case IDC_BUTTON5:	// 2
			printf("2\n");
			showNum('2', hDlg);
			break;
		case IDC_BUTTON6:	// 3
			printf("3\n");
			showNum('3', hDlg);
			break;
		case IDC_BUTTON7:	// 4
			printf("4\n");
			showNum('4', hDlg);
			break;
		case IDC_BUTTON8:	// 5
			printf("5\n");
			showNum('5', hDlg);
			break;
		case IDC_BUTTON9:	// 6
			printf("6\n");
			showNum('6', hDlg);
			break;
		case IDC_BUTTON10:	// 7
			printf("7\n");
			showNum('7', hDlg);
			break;
		case IDC_BUTTON11:	// 8
			printf("8\n");
			showNum('8', hDlg);
			break;
		case IDC_BUTTON12:	// 9
			printf("9\n");
			showNum('9', hDlg);
			break;
		case IDC_BUTTON13:	// /
			printf("/\n");
			showSign('/', hDlg);
			break;
		case IDC_BUTTON14:	// *
			printf("*\n");
			showSign('*', hDlg);
			break;
		case IDC_BUTTON15:	// -
			printf("-\n");
			showSign('-', hDlg);
			break;
		case IDC_BUTTON16:	// Clear
			printf("Clear\n");
			ClearArray(hDlg);
			break;
		case IDC_BUTTON17:	// +
			printf("+\n");
			showSign('+', hDlg);
			break;
		}
		break;
	case WM_CLOSE:
		FreeConsole();
		EndDialog(hDlg, LOWORD(wParam));
		return (INT_PTR)TRUE;
	}

	return (INT_PTR)FALSE;
}
		
