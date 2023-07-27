#include <tchar.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
#include <iterator>
using namespace std;

#define IsButtonClicked(ID, wParam) (ID == LOWORD(wParam))
#define TEXTBOX HWND

enum TUSLAR
{
    CAPSLOCK = VK_CAPITAL,
    SAGOK = VK_RIGHT,
    WINDOWS = VK_RWIN,
    NUMLOCK = VK_NUMLOCK,
    SOLOK = VK_LEFT,
    ALTOK = VK_DOWN,
    USTOK = VK_UP,
    BUYUK = VK_SHIFT,
    BOSLUK = VK_SPACE,
    TAB = VK_TAB,
    ESC = VK_ESCAPE,
    KONTROL = VK_CONTROL,
    GERI = VK_BACK,
    ALTSATIR = VK_RETURN,
    ALTGR = VK_MENU,
    SIL = VK_DELETE,
    SES_AZALTMA = VK_VOLUME_DOWN,
    SES_ARTTIRMA = VK_VOLUME_UP,
    SES_SIFIRLAMA = VK_VOLUME_MUTE,
    F1 = VK_F1,
    F2 = VK_F2,
    F3 = VK_F3,
    F4 = VK_F4,
    F5 = VK_F5,
    F6 = VK_F6,
    F7 = VK_F7,
    F8 = VK_F8,
    F9 = VK_F9,
    F10 = VK_F10,
    F11 = VK_F11,
    F12 = VK_F12,
    F13 = VK_F13,
    F14 = VK_F14,
    F15 = VK_F15,
    F16 = VK_F16,
    F17 = VK_F17,
    F18 = VK_F18,
    F19 = VK_F19,
    F20 = VK_F20,
    F21 = VK_F21,
    F22 = VK_F22,
    F23 = VK_F23,
    F24 = VK_F24
};
struct BUTTON
{
    int butonID;
    HWND butonHwnd;
};
vector<LPCSTR> sbszFileName;
vector<int> sbx1;
vector<int> sby1;
vector<int> sbx2;
vector<int> sby2;
vector<HWND> sbhwnd;
bool showBitmap(LPCSTR szFileName, int x1, int y1, int x2 = 0, int y2 = 0, HWND hwnd = GetActiveWindow())
{
    sbszFileName.push_back(szFileName);
    sbx1.push_back(x1);
    sby1.push_back(y1);
    sbx2.push_back(x2);
    sby2.push_back(y2);
    sbhwnd.push_back(hwnd);
    if (x2 == 0)
    {
        x2 = x1;
    }
    if (y2 == 0)
    {
        y2 = y1;
    }
    PAINTSTRUCT ps;
    static HWND a = hwnd;
    static HDC hWinDC = BeginPaint(a, &ps);
    if (a != hwnd)
        hWinDC = BeginPaint(hwnd, &ps);
    HBITMAP hBitmap;
    hBitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, x2 - x1, y2 - y1, LR_LOADFROMFILE);
    if (hBitmap == NULL)
    {
        ::MessageBox(NULL, __T("LoadImage Failed"), __T("Error"), MB_OK);
        return false;
    }
    HDC hLocalDC;
    hLocalDC = ::CreateCompatibleDC(hWinDC);
    if (hLocalDC == NULL)
    {
        ::MessageBox(NULL, __T("CreateCompatibleDC Failed"), __T("Error"), MB_OK);
        return false;
    }
    BITMAP qBitmap;
    int iReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP), reinterpret_cast<LPVOID>(&qBitmap));
    if (!iReturn)
    {
        ::MessageBox(NULL, __T("GetObject Failed"), __T("Error"), MB_OK);
        return false;
    }
    HBITMAP hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);
    if (hOldBmp == NULL)
    {
        ::MessageBox(NULL, __T("SelectObject Failed"), __T("Error"), MB_OK);
        return false;
    }
    BOOL qRetBlit = ::BitBlt(hWinDC, x1, y1, qBitmap.bmWidth, qBitmap.bmHeight, hLocalDC, 0, 0, SRCCOPY);
    if (!qRetBlit)
    {
        ::MessageBox(NULL, __T("Blit Failed"), __T("Error"), MB_OK);
        return false;
    }
    ::SelectObject(hLocalDC, hOldBmp);
    ::DeleteDC(hLocalDC);
    ::DeleteObject(hBitmap);
    return true;
}
bool showBitmapH(LPCSTR szFileName, int x1, int y1, int x2 = 0, int y2 = 0, HWND hwnd = GetActiveWindow())
{
    if (x2 == 0)
    {
        x2 = x1;
    }
    if (y2 == 0)
    {
        y2 = y1;
    }
    PAINTSTRUCT ps;
    static HWND a = hwnd;
    static HDC hWinDC = BeginPaint(a, &ps);
    if (a != hwnd)
        hWinDC = BeginPaint(hwnd, &ps);
    HBITMAP hBitmap;
    hBitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, x2 - x1, y2 - y1, LR_LOADFROMFILE);
    if (hBitmap == NULL)
    {
        ::MessageBox(NULL, __T("LoadImage Failed"), __T("Error"), MB_OK);
        return false;
    }
    HDC hLocalDC;
    hLocalDC = ::CreateCompatibleDC(hWinDC);
    if (hLocalDC == NULL)
    {
        ::MessageBox(NULL, __T("CreateCompatibleDC Failed"), __T("Error"), MB_OK);
        return false;
    }
    BITMAP qBitmap;
    int iReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP), reinterpret_cast<LPVOID>(&qBitmap));
    if (!iReturn)
    {
        ::MessageBox(NULL, __T("GetObject Failed"), __T("Error"), MB_OK);
        return false;
    }
    HBITMAP hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);
    if (hOldBmp == NULL)
    {
        ::MessageBox(NULL, __T("SelectObject Failed"), __T("Error"), MB_OK);
        return false;
    }
    BOOL qRetBlit = ::BitBlt(hWinDC, x1, y1, qBitmap.bmWidth, qBitmap.bmHeight, hLocalDC, 0, 0, SRCCOPY);
    if (!qRetBlit)
    {
        ::MessageBox(NULL, __T("Blit Failed"), __T("Error"), MB_OK);
        return false;
    }
    ::SelectObject(hLocalDC, hOldBmp);
    ::DeleteDC(hLocalDC);
    ::DeleteObject(hBitmap);
    return true;
}
void yenile(){
    for(int i=0;i<sbszFileName.size();i++){
        showBitmapH(sbszFileName[i], sbx1[i], sby1[i], sbx2[i],sby2[i],sbhwnd[i]);
    }
}
BUTTON CreateButton(std::string name, int x1, int y1, int x2, int y2, HWND hwnd = GetActiveWindow(),LPCSTR buttonimage=NULL)
{
    static int b = 1;
    BUTTON rv;
    rv.butonID = b;
    rv.butonHwnd = CreateWindow(_T("button"), _T(name.c_str()), WS_VISIBLE | WS_BORDER, x1, y1, x2 - x1, y2 - y1, NULL, HMENU(b), NULL, NULL);
    if(buttonimage!=NULL) showBitmap(buttonimage,x1+3,y1+3,x2-3,y2-3,hwnd);
    b++;
    return rv;
}
HWND CreateTextBox(std::string name, int x1, int y1, int x2, int y2, HWND hwnd = GetActiveWindow())
{
    return CreateWindow(_T("edit"), _T(name.c_str()), WS_HSCROLL | WS_VSCROLL | ES_MULTILINE | WS_VISIBLE | WS_CHILD | ES_WANTRETURN | WS_BORDER, x1, y1, x2 - x1, y2 - y1, hwnd, NULL, GetModuleHandle(NULL), NULL);
}
char *getText(HWND textBox)
{
    int s = GetWindowTextLength(textBox);
    char *d = new char[s + 1];
    GetWindowText(textBox, d, s + 1);
    return d;
}
void setText(HWND textBox, LPCSTR data)
{
    SetWindowText(textBox, data);
    return;
}
RECT getScreenInfo(HWND hwnd)
{
    RECT rc;
    GetClientRect(hwnd, &rc);
    return rc;
}
void setScreenPos(HWND textBox, int x1, int y1, int x2, int y2)
{
    MoveWindow(textBox, x1, y1, -x1+x2,-y1+y2, TRUE);
    return;
}
void fareDesgisBitmap(string a){
    HBITMAP p = (HBITMAP)LoadImage(0, a.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    HBITMAP pMask = (HBITMAP)LoadImage(0, a.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    ICONINFO Ico;
    Ico.fIcon = false;
    Ico.hbmColor = p;
    Ico.hbmMask = pMask;
    Ico.xHotspot = 30;
    Ico.yHotspot = 5;
    HCURSOR c = CreateIconIndirect(&Ico);
    SetSystemCursor(c,32512);
}
void fareDegisIco(string a){
    HICON I = (HICON)LoadImage(0, a.c_str(), IMAGE_ICON, 30, 30, LR_LOADFROMFILE);
    ICONINFO Ico;
    GetIconInfo(I, &Ico);
    Ico.xHotspot = 0;
    Ico.yHotspot = 0;
    HCURSOR c = CreateIconIndirect(&Ico);
    SetSystemCursor(c, 32512);
}
HWND createWindow(HINSTANCE hInstance, WNDPROC a, string name, int x1 = 0, int y1 = 0, int x2 = 1366, int y2 = 700)
{
    WNDCLASSEX wc;
    HWND hwnd;
    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = a;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = _T("WindowClass");
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, _T("Window Registration Failed!"), _T("Error!"), MB_ICONEXCLAMATION | MB_OK);
        return NULL;
    }
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, _T("WindowClass"), _T(name.c_str()), WS_BORDER | WS_VISIBLE | WS_OVERLAPPEDWINDOW, x1, y1, x2, y2, NULL, NULL, hInstance, NULL);
    if (hwnd == NULL)
    {
        MessageBox(NULL, _T("Window Creation Failed!"), _T("Error!"), MB_ICONEXCLAMATION | MB_OK);
        return NULL;
    }
    return hwnd;
}
COORD ekranKonumu(HWND hwnd = GetActiveWindow())
{
    RECT r;
    GetWindowRect(hwnd, &r);
    COORD a;
    a.X = r.left;
    a.Y = r.top;
    return a;
}
COORD fareKonumu(HWND hwnd = GetActiveWindow())
{
    COORD x;
    POINT p;
    GetCursorPos(&p);
    x.X = p.x - ekranKonumu(hwnd).X;
    x.Y = p.y - ekranKonumu(hwnd).Y;
    return x;
}
bool basilimi(char x)
{
    return GetAsyncKeyState(x);
}
void line(int x1, int y1, int x2, int y2, int size = 3, HWND hwnd = GetActiveWindow())
{
    PAINTSTRUCT ps;
    static HWND a = hwnd;
    static HDC hDC = BeginPaint(hwnd, &ps);
    if (a != hwnd)
        hDC = BeginPaint(hwnd, &ps);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            MoveToEx(hDC, x1 + i, y1 + j, NULL);
            LineTo(hDC, x2 + i, y2 + j);
        }
    }
    return;
}
COORD ekranBoyutu(HWND konsol = GetConsoleWindow())
{
    RECT r;
    GetWindowRect(konsol, &r);
    COORD a;
    a.X = r.right;
    a.Y = r.bottom;
    return a;
}
string fileOpen(HWND hwnd) {
	OPENFILENAME ofn;
	char szFileName[MAX_PATH];
	ZeroMemory(&ofn, sizeof(ofn));
	szFileName[0] = 0;
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = _T("All Files (*.*)\0*.*\0\0");
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_OVERWRITEPROMPT;
	ofn.lpstrDefExt = _T("txt");
    GetOpenFileName(&ofn);
	return szFileName;
}
void seslendir(string a){
    system((string("echo \"")+a+string("\">a.txt && seslendir<a.txt && rm a.txt")).c_str());
    return;
}
string kucukHarfYap(string s)
{
	for(int i=0;i<s.length();i++)
	{
		s[i]=tolower(s[i]);
	}
	return s;
}
string dinle(){
    setlocale(LC_ALL,"Turkish");
    string str;
    system("dinle > a.txt");
    ifstream a("a.txt");
    getline(a,str);
    a.close();
    system("del a.txt");
    str=kucukHarfYap(str);
    return str;
}
/*
#include <tchar.h>
#include <windows.h>
#include <windowsx.h>
#include <code-windows.hpp>

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch (Message)
    {
    case WM_COMMAND:
    {
        break;
    }
    case WM_CREATE:
    {
        break;
    }
    case WM_SIZE:
    {
        break;
    }
    case WM_CLOSE:
    {
        if (MessageBox(NULL, _T("Uygulama Kapaniyor!!!"), _T("Dikkat"), MB_OKCANCEL) == IDOK)
            PostQuitMessage(0);
        break;
    }
    case WM_HELP:
    {
        MessageBox(NULL, _T("Henuz yardim menusu hazir dagil!!!"), _T("Dikkat"), MB_OK);
        break;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hwnd, Message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg;
    HWND hwnd = createWindow(hInstance, WndProc, "Un Named");
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
*/
