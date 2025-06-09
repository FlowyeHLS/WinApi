#include"resource.h"
#include<Windows.h>

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//#define MESSAGE_BOX

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR LpCmdLLine, INT nCmdShow)
{

#ifdef MESSAGE_BOX
	MessageBox
	(
		NULL,
		"Привет WinApi\nЭто самое простое окно - окно сообщения",
		"Привет!",
		MB_ABORTRETRYIGNORE | MB_ICONINFORMATION | MB_HELP
		| MB_SYSTEMMODAL
	);
#endif // MESSAGE_BOX

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);

	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_COPY :
		{
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
			break;
		case IDOK:
			MessageBox(hwnd, "Была нажата кнопка ок", "Info", MB_OK | MB_ICONINFORMATION);
			break;
		case IDCANCEL:EndDialog(hwnd, 0);
			break;

		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	}
	return FALSE;
}

