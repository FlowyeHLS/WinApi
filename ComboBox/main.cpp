#include <Windows.h>
#include "resource.h"
#include <cstdio>




CONST CHAR* G_SZ_VALUES[] = { "This","is","my","First", "Combo","Box", "Хорошо", "Живет", "на ", "свете"};

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		//GetModuleHandle(NULL) - возвращает hInstance нашего .exe-файла
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);

		HWND hCombo = GetDlgItem(hwnd, IDC_COMBO);
		for (int i = 0; i < sizeof(G_SZ_VALUES) / sizeof(G_SZ_VALUES[0]); i++)
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)G_SZ_VALUES[i]);
		}
	}
		break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			CONST INT SIZE = 256;
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO);
			INT i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			CHAR sz_buffer[SIZE] = {};
			CHAR sz_message[SIZE] = {};
			SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_buffer);
			if(i == -1)strcpy(sz_message, "Type ur choice");

			else
				sprintf(sz_message, " Your type punct %i so znacheniem %s ",i , sz_buffer);
			//sz_message - та строка будет содержать результат форматирования
			//Вы выбрали - это строка содержит фармат, в ней нужно указать куда 
			// именно нужно вставить значение идущее после этой стрроки в данном 
			// случае это i и sz_buffer, sprintf()- это функция с произвольным 
			// числом параметров 
			//Спецификатор '%i' заменяется целочисленным значением 
			// Спецификатор '%s' заменяется строкой 
			// '%e' дробное число и т д 
			MessageBox(hwnd, sz_message, "Info", MB_OK | MB_ICONINFORMATION);
		}
			break;
		case IDCANCEL:EndDialog(hwnd, 0); break;
		}
	}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	}
	return FALSE;
}