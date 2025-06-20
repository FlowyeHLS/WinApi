#include <Windows.h>
#include "resource.h"

CONST CHAR g_sz_CLASS_NAME[] = "MyCalc";

INT WINAPI WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR LpCmdLine, INT nCmdShow)
{
	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(wClass));

	wClass.style = 0;
	wClass.cbSize = sizeof(wClass);
	wClass.cbWndExtra = 0;
	wClass.cbClsExtra = 0;

	wClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	wClass.hInstance = hInstance;
	wClass.lpszMenuName = NULL;
	wClass.lpszClassName = g_sz_CLASS_NAME;
	wClass.lpfnWndProc = (WNDPROC)WndProc;

	if (!RegisterClassEx(&wClass))
	{
		MessageBox(NULL, "Class registration faild", "", MB_OK | MB_ICONERROR);
		return 0;
	}

	HWND hwnd = CreateWindowEx

	(
		NULL,
		g_sz_CLASS_NAME,
		g_sz_CLASS_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);


	//Massege cicle

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

INT WINAPI WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		HWND hEditDisplay = CreateWindowEx
		(
			NULL, "Edit", "0",
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
			10, 10,
			460, 22,
			hwnd,
			(HMENU)IDC_EDIT_DISPLAY,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButton = CreateWindowEx
		(
			NULL, "Button", "0",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10, 35,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_0,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButton1 = CreateWindowEx
		(
			NULL, "Button", "1",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 35,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_1,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButton2 = CreateWindowEx
		(
			NULL, "Button", "2",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 35,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_2,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButton3 = CreateWindowEx
		(
			NULL, "Button", "3",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 35,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_3,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButton4 = CreateWindowEx
		(
			NULL, "Button", "4",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 35,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_4,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButton5 = CreateWindowEx
		(
			NULL, "Button", "5",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10, 65,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_5,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButton6 = CreateWindowEx
		(
			NULL, "Button", "6",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 65,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_6,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButton7 = CreateWindowEx
		(
			NULL, "Button", "7",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 65,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_7,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButton8 = CreateWindowEx
		(
			NULL, "Button", "8",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 65,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_8,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButton9 = CreateWindowEx
		(
			NULL, "Button", "9",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 65,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_9,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButtonPoint = CreateWindowEx
		(
			NULL, "Button", ".",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10, 130,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_POINT,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButtonPlus = CreateWindowEx
		(
			NULL, "Button", "+",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 130,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_PLUS,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButtonAster = CreateWindowEx
		(
			NULL, "Button", "*",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 130,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_ASTER,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButtonSlash = CreateWindowEx
		(
			NULL, "Button", "/",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 130,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_SLASH,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hwndButtonEqual = CreateWindowEx
		(
			NULL, "Button", "=",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 130,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_EQUAL,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButtonBackSpace = CreateWindowEx
		(
			NULL, "Button", "Back",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 190,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_BSP,
			GetModuleHandle(NULL),
			NULL
		);

		HWND hwndButtonClear = CreateWindowEx
		(
			NULL, "Button", "Clear",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 190,
			70, 25,
			hwnd,
			(HMENU)IDC_BUTTON_CLR,
			GetModuleHandle(NULL),
			NULL
		);





	}
		break;
	case WM_COMMAND:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default:return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}