#include "resource.h"
#include <Windows.h>

#define MY_LOGIN "Введите имя пользователя"

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
    switch (uMsg) {
    case WM_INITDIALOG: {
        HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
        SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)MY_LOGIN);
       // SendMessage(hEditLogin, EM_SETSEL, 0, -1);  
        break;
    }

    case WM_COMMAND:
        switch (LOWORD(wParam)) 
        {
        case IDC_EDIT_LOGIN: 
        {
            if (HIWORD(wParam) == EN_SETFOCUS)
            {
                HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
                CONST INT SIZE = 256;
                CHAR sz_buffer[SIZE] = {};
                SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);


                if (strcmp(sz_buffer, MY_LOGIN) == 0) {
                    SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");
                    SendMessage(hEditLogin, EM_SETSEL, 0, 0);
                }
            }
            if (HIWORD(wParam) == EN_KILLFOCUS)
            {
                HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
                CONST INT SIZE = 256;
                CHAR sz_buffer[SIZE] = {};
                SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);

                if (sz_buffer[0] == '\0')
                {
                    SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)MY_LOGIN);
                }
            }
        }
            break;
        case IDC_BUTTON_COPY: {
            HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
            HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
            CONST INT SIZE = 256;
            CHAR sz_buffer[SIZE] = {};
            SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
            SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
            break;
        }

        case IDOK:
            MessageBox(hwnd, "Кнопка ОК нажата", "Info", MB_OK | MB_ICONINFORMATION);
            break;
        case IDCANCEL:
            EndDialog(hwnd, 0);
            break;
        }
        break;

    case WM_CLOSE:
        EndDialog(hwnd, 0);
        break;
    }

    return FALSE;
}

