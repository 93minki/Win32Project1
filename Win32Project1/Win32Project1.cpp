// Win32Project1.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Win32Project1.h"
#include "resource.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

char InputNum[128];
char GetNum[128];
char totalSign[10];
char arraytemp[128];

char TempArray[128];
char arrayclear[128] = { 0, };
int TempNum[128];

int i;

int k = 0;
int arraySize;
int rstsum;
int Temp1;
int Temp2;
int Temp3;
double intoNum1;									// num1 �迭�� int�� ��ȯ
double intoNum2;									// num2 �迭�� int�� ��ȯ
double sum1;										// ��� ��
// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
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



    // TODO: ���⿡ �ڵ带 �Է��մϴ�.
	AllocConsole();
	freopen("CONOUT$", "wt", stdout);
	//AttachConsole(GetCurrentProcessId());
	//freopen("CON", "w", stdout);
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	/*
    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
    //MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

    MSG msg;
	

    // �⺻ �޽��� �����Դϴ�.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
	
    return (int) msg.wParam;
	*/
	return 0;
}




BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

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

void showNum(char sign, HWND hDlg) {
	for (; i < sizeof(InputNum); i++) {
		if (InputNum[i + 1] == '\0') {
			InputNum[i] =sign;
			SetDlgItemText(hDlg, IDC_EDIT1, InputNum);
			i++;
			printf("InputNum : %s \n", InputNum);
			break;
		}
	}
}

void showDot(char sign, HWND hDlg) {
	for (; i < sizeof(InputNum); i++) {
		if (InputNum[i - 1] == sign) {
			break;
		}
		if (InputNum[i + 1] == '\0') {
			InputNum[i] = sign;
			SetDlgItemText(hDlg, IDC_EDIT1, InputNum);
			i++;
			printf("InputNum : %s \n", InputNum);
			break;
		}
	}
}

void showSign(char sign, HWND hDlg) {
	for (; i < sizeof(InputNum); i++) {
		if((InputNum[i-1] == '+') || (InputNum[i-1] == '-') || (InputNum[i-1] == '*') || (InputNum[i-1] == '/'))
		{
			InputNum[i - 1] = sign;
			SetDlgItemText(hDlg, IDC_EDIT1, InputNum);
			printf("InputNum : %s \n", InputNum);
			break;
		}
		else {
			InputNum[i] = sign;
			SetDlgItemText(hDlg, IDC_EDIT1, InputNum);
			i++;
			printf("InputNum : %s \n", InputNum);
			break;
		}
	}
}

void showOutput(HWND hDlg) {
	GetDlgItemText(hDlg, IDC_EDIT1, GetNum, 128);
	printf("Get Number : %s\n", GetNum);
	int c = 0;
	int d = 0;
	for (int a = 0; a < sizeof(GetNum); a++)
	{
		if (GetNum[a] == '+' || GetNum[a] == '-' || GetNum[a] == '*' || GetNum[a] == '/') {
			totalSign[c] = GetNum[a];
			for (int b = 0; b < a; b++)
			{
				TempArray[b] = GetNum[b];
			}
			TempNum[d] = atoi(TempArray);
			c++;
			d++;
		}
		if (GetNum[a + 1] == '\0') {

		}

	}
	printf("totalSign :%s \n", totalSign);
	printf("TempNum1 :%d \n", TempNum[0]);
	printf("TempNum2 :%d \n", TempNum[1]);
}

void ClearArray(HWND hDlg) {
	for (int a = 0; a < sizeof(InputNum); a++) {
		InputNum[a] = '\0';
	}
	i = 0;
	SetDlgItemText(hDlg, IDC_EDIT1, InputNum);
	
	printf("InputNum : %s \n", InputNum);
}
// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
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
		
