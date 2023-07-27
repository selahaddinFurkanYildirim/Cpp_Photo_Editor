#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <sstream>
#include <time.h>
#include <algorithm>
#include <array>
#include <limits.h>
#include <conio.h>
#include <limits>
#include <windows.h>
#include <fstream>
#include <locale.h>
#define diziOku(arr, n)         \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define diziYaz(arr, n, aralarina)  \
    for (int i = 0; i < n - 1; i++) \
    {                               \
        cout << arr[i];             \
        cout << aralarina;          \
    }                               \
    cout << arr[n - 1];
#define randomize srand(time(NULL))
#define stdKrtBklSur 0.02
using namespace std;

struct yonluGraph
{
private:
    vector<int> yollar[10000];
    bool ziyaret[10000];

public:
    void kenarEkle(int x, int y)
    {
        yollar[x].push_back(y);
    }
    bool ziyaretEdildimi(int k)
    {
        return ziyaret[k];
    }
    bool kenarVarmi(int x, int y)
    {
        for (int i = 0; i < yollar[x].size(); i++)
        {
            if (yollar[x][i] == y)
                return 1;
        }
        return 0;
    }
    void sifirla()
    {
        for (int i = 0; i < 10000; i++)
        {
            ziyaret[i] = 0;
        }
        return;
    }
    void dfs(int k)
    {
        if (!ziyaret[k])
        {
            ziyaret[k] = true;
            for (int i = 0; i < yollar[k].size(); i++)
            {
                if (!ziyaret[yollar[k][i]])
                {
                    dfs(yollar[k][i]);
                }
            }
        }
    }
    void bfs(int k)
    {
        queue<int> q;
        ziyaret[k] = 1;
        q.push(k);
        while (!q.empty())
        {
            int h = q.front();
            q.pop();
            for (int i = 0; i < yollar[h].size(); i++)
            {
                if (!ziyaret[yollar[h][i]])
                {
                    ziyaret[yollar[h][i]] = 1;
                    q.push(yollar[h][i]);
                }
            }
        }
        return;
    }
};
struct Graph
{
private:
    vector<int> yollar[10000];
    bool ziyaret[10000];

public:
    void kenarEkle(int x, int y)
    {
        yollar[x].push_back(y);
        yollar[y].push_back(x);
    }
    bool ziyaretEdildimi(int k)
    {
        return ziyaret[k];
    }
    void sifirla()
    {
        for (int i = 0; i < 10000; i++)
        {
            ziyaret[i] = 0;
        }
        return;
    }
    void dfs(int k)
    {
        if (!ziyaret[k])
        {
            ziyaret[k] = true;
            for (int i = 0; i < yollar[k].size(); i++)
            {
                if (!ziyaret[yollar[k][i]])
                {
                    dfs(yollar[k][i]);
                }
            }
        }
        return;
    }
    void bfs(int k)
    {
        queue<int> q;
        ziyaret[k] = 1;
        q.push(k);
        while (!q.empty())
        {
            int h = q.front();
            q.pop();
            for (int i = 0; i < yollar[h].size(); i++)
            {
                if (!ziyaret[yollar[h][i]])
                {
                    ziyaret[yollar[h][i]] = 1;
                    q.push(yollar[h][i]);
                }
            }
        }
        return;
    }
};
enum RENK
{
    SIYAH = 0,
    MAVI = 1,
    YESIL = 2,
    DENIZ_MAVISI = 3,
    KIRMIZI = 4,
    MOR = 5,
    SARI = 6,
    BEYAZ = 7,
    GRI = 8,
    ACIK_MAVI = 9,
    ACIK_YESIL = 10,
    ACIK_DENIZ_MAVISI = 11,
    ACIK_KIRMIZI = 12,
    ACIK_MOR = 13,
    ACIK_SARI = 14,
    PARLAK_BEYAZ = 15
};
class aramaAlgoritmalari
{
public:
    int ikiliArama(int arr[], int n, int aranan)
    {
        int l = 0, r = n - 1;
        while (l < r)
        {
            int a = (l + r) / 2;
            if (arr[a] == aranan)
                return a;
            if (arr[a] > aranan)
                r = a + 1;
            else
                l = a + 1;
        }
        return -1;
    }
    long long int linearSearch(long long int arr[], long long int n, long long int aranan)
    {
        for (long long int i = 0; i < n; i++)
            if (arr[i] == aranan)
                return i;
        return -1;
    }
} aramaAlgoritmalari;
class siralamaAlgoritmalari
{
    void degistir(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    int hizliSiralamaElemani(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                degistir(&arr[i], &arr[j]);
            }
        }
        degistir(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    int ikiliArama(int arr[], int item, int low, int high)
    {
        if (high <= low)
            return (item > arr[low]) ? (low + 1) : low;
        int mid = (low + high) / 2;
        if (item == arr[mid])
            return mid + 1;
        if (item > arr[mid])
            return ikiliArama(arr, item, mid + 1, high);
        return ikiliArama(arr, item, low, mid - 1);
    }
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pivot = hizliSiralamaElemani(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }
#define BEAD(i, j) beads[i * max + j]
    int getMax(int arr[], int n)
    {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }
    void countSort(int arr[], int n, int exp)
    {
        int output[n];
        int i, count[10] = {0};
        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }

public:
    void radixsort(int arr[], int n)
    {
        int m = getMax(arr, n);
        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(arr, n, exp);
    }
    void gnomeSort(int arr[], int n)
    {
        int index = 0;
        while (index < n)
        {
            if (index == 0)
                index++;
            if (arr[index] >= arr[index - 1])
                index++;
            else
            {
                swap(arr[index], arr[index - 1]);
                index--;
            }
        }
        return;
    }
    void beadSort(int *a, int len)
    {
        int max = a[0];
        for (int i = 1; i < len; i++)
            if (a[i] > max)
                max = a[i];
        unsigned char beads[max * len];
        memset(beads, 0, sizeof(beads));
        for (int i = 0; i < len; i++)
            for (int j = 0; j < a[i]; j++)
                BEAD(i, j) = 1;
        for (int j = 0; j < max; j++)
        {
            int sum = 0;
            for (int i = 0; i < len; i++)
            {
                sum += BEAD(i, j);
                BEAD(i, j) = 0;
            }
            for (int i = len - sum; i < len; i++)
                BEAD(i, j) = 1;
        }
        for (int i = 0; i < len; i++)
        {
            int j;
            for (j = 0; j < max && BEAD(i, j); j++)
                ;
            a[i] = j;
        }
    }
    void quickSort(int arr[], int size)
    {
        quickSort(arr, 0, size - 1);
        return;
    }
    void shellSort(int arr[], int n)
    {
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i += 1)
            {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
        return;
    }
    void binarySort(int arr[], int n)
    {
        int i, loc, j, k, selected;
        for (i = 1; i < n; ++i)
        {
            j = i - 1;
            selected = arr[i];
            loc = ikiliArama(arr, selected, 0, j);
            while (j >= loc)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = selected;
        }
    }
    void countSort(int array[], int size)
    {
        int output[10];
        int count[10];
        int max = array[0];
        for (int i = 1; i < size; i++)
        {
            if (array[i] > max)
                max = array[i];
        }
        for (int i = 0; i <= max; ++i)
        {
            count[i] = 0;
        }
        for (int i = 0; i < size; i++)
        {
            count[array[i]]++;
        }
        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
        }
        for (int i = size - 1; i >= 0; i--)
        {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }
        for (int i = 0; i < size; i++)
        {
            array[i] = output[i];
        }
    }
    void bubbleSort(int dizi[], int eleman_sayisi)
    {
        for (int i = 0; i < eleman_sayisi; i++)
            for (int j = i + 1; j < eleman_sayisi; j++)
                if (dizi[i] > dizi[j])
                {
                    int gecici = dizi[i];
                    dizi[i] = dizi[j];
                    dizi[j] = gecici;
                }
        return;
    }
} siralamaAlgoritmalari;
enum YON
{
    SAG = 1,
    SOL = 2,
    UST = 4,
    ALT = 8
};
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
enum FARE
{
    FARENINSOLU = VK_LBUTTON,
    FARENINSAGI = VK_RBUTTON
};
COORD ekranBoyutu()
{
    HWND konsol = GetConsoleWindow();
    RECT r;
    GetWindowRect(konsol, &r);
    COORD a;
    a.X = r.right;
    a.Y = r.bottom;
    return a;
}
COORD ekranKonumu()
{
    HWND consol = GetConsoleWindow();
    RECT r;
    GetWindowRect(consol, &r);
    COORD a;
    a.X = r.left;
    a.Y = r.top;
    return a;
}
COORD ekranBoyutu(int x, int y)
{
    HWND konsol = GetConsoleWindow();
    RECT r;
    GetWindowRect(konsol, &r);
    MoveWindow(konsol, r.left, r.top, x, y, true);
    COORD a;
    a.X = r.right;
    a.Y = r.bottom;
    return a;
}
COORD ekranKonumu(int x, int y)
{
    HWND consol = GetConsoleWindow();
    RECT r;
    GetWindowRect(consol, &r);
    MoveWindow(consol, x, y, r.right, r.bottom, true);
    COORD a;
    a.X = r.left;
    a.Y = r.top;
    return a;
}
void ekranGorunumu(int x, int y, int genislik, int yukseklik)
{
    HWND consol = GetConsoleWindow();
    RECT r;
    GetWindowRect(consol, &r);
    MoveWindow(consol, x, y, genislik, yukseklik, true);
    return;
}
bool basilimi(int x)
{
    return GetAsyncKeyState(x);
}
long long int us(long long int x, int y)
{
    long long int sonuc = 1;
    for (long long int i = 0; i < y; i++)
        sonuc *= x;
    return sonuc;
}
int basamakSayisi(long long int x)
{
    long long int sonuc = 0;
    for (sonuc = 0; x >= us(10, sonuc); sonuc++)
        ;
    return sonuc;
}
int yuvarla(float x)
{
    if (((int)((x * 10)) % 10) < 5)
        return (int)x;
    return (int)x + 1;
}
int lerBasamagi(double sayi, long long basamak)
{
    if (basamak > 0)
        return ((int)(sayi / us(10, basamak - 1))) % 10;
    if (basamak < 0)
        return ((int)(sayi * us(10, basamak + 1))) % 10;
    return 0;
}
int lerBasamagi(long long int sayi, long long basamak)
{
    if (basamak > 0)
        return ((long long int)(sayi / us(10, basamak - 1))) % 10;
    if (basamak < 0)
        return 0;
    return 0;
}
double lerBasamaginiYap(double sayi, int basamak, int deger)
{
    if (basamak > 0)
        return sayi - lerBasamagi(sayi, basamak) * us(10, basamak - 1) + deger * us(10, basamak - 1);
    if (basamak < 0)
        return sayi - lerBasamagi(sayi, basamak) * us(10, basamak + 1 - 1) + deger * us(10, basamak);
    return 0.0;
}
bool ikiliArama(int dizi[], int eleman_sayisi, int sayi)
{
    int sag = eleman_sayisi - 1, sol = 0;
    while (sol < sag)
    {
        if (sayi >= dizi[((sol + sag + 1) / 2)])
            sol = ((sol + sag + 1) / 2) + 1;
        else if (sayi < dizi[((sol + sag + 1) / 2)])
            sag = ((sol + sag + 1) / 2) - 1;
        else
            return 1;
    }
    return 0;
}
bool cumleKarsilastir(char a[], string b, int x = 0)
{
    for (int i = 0; i < b.size(); i++)
        if (a[i + x] != b[i])
        {
            return false;
        }
    return true;
}
bool cumleKarsilastir(string a, string b, int x = 0)
{
    for (int i = 0; i < b.size(); i++)
        if (a[i + x] != b[i])
        {
            return false;
        }
    return true;
}
bool icindeVarmi(char a[], string b)
{
    for (int i = 0; i <= strlen(a) - b.size(); i++)
        if (cumleKarsilastir(a, b, i))
            return 1;
    return 0;
}
bool icindeVarmi(string a, string b)
{
    for (int i = 0; i <= a.size() - b.size(); i++)
        if (cumleKarsilastir(a, b, i))
            return 1;
    return 0;
}
bool icindeVarmi(vector<string> a, string b)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == b)
            return i + 1;
    return 0;
}
bool icindeVarmi(vector<int> a, int b)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == b)
            return i + 1;
    return 0;
}
bool operator==(COORD a, COORD b)
{
    return (a.X == b.X) && (b.Y == a.Y);
}
template <typename T>
bool icindeVarmi(vector<T> a, T b)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == b)
            return i + 1;
    return 0;
}
void bekle(float saniye)
{
    Sleep(saniye * 1000.0);
    return;
}
vector<int> tumCarpanlari(int x)
{
    vector<int> sonuc;
    for (int i = 2; x != 1; i++)
    {
        if (x % i == 0)
        {
            sonuc.push_back(i);
            x /= i;
            i--;
        }
    }
    return sonuc;
}
bool asalmi(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
vector<int> asalCarpanlari(int x)
{
    vector<int> sonuc;
    for (int i = 2; x != 1; i++)
    {
        if (x % i == 0)
        {
            if (asalmi(i))
                sonuc.push_back(i);
            x /= i;
        }
    }
    return sonuc;
}
template <typename T>
void vectorYaz(vector<T> x, char basina = '[', char aralarina = ',', char sonuna = ']')
{
    cout << basina;
    for (int i = 0; i < x.size() - 1; i++)
    {
        cout << x[i] << aralarina;
    }
    cout << x[x.size() - 1];
    cout << sonuna;
    return;
}
int sayisindanKucukSayisiylaArasindaAsalSayilar(int x)
{
    double sonuc = x;
    vector<int> a = asalCarpanlari(x);
    for (int i = 0; i < a.size(); i++)
    {
        sonuc *= 1.0 - 1.0 / a[i];
    }
    return sonuc;
}
int fiTeoremi(int x)
{
    return sayisindanKucukSayisiylaArasindaAsalSayilar(x);
}
string Input()
{
    string a = "";
    while (a == "")
    {
        char b[100];
        gets(b);
        a = (string)b;
    }
    return a;
}
string charArrayString(char x[])
{
    return x;
}
string Input(string x)
{
    cout << x;
    string a = "";
    bool c = false;
    while (a == "" || c)
    {
        if (c)
            c = false;
        char b[100];
        gets(b);
        a += (string)b;
    }
    return a;
}
string Input(string x, string y)
{
    cout << x << y;
    string a = "";
    bool c = false;
    while (a == "" || c)
    {
        if (c)
            c = false;
        char b[100];
        gets(b);
        a += (string)b;
    }
    return a;
}
string Input(string x, string y, string z)
{
    cout << x << y << z;
    string a = "";
    bool c = false;
    while (a == "" || c)
    {
        if (c)
            c = false;
        char b[100];
        gets(b);
        a += (string)b;
    }
    return a;
}
string intString(long long int x)
{
    if (x == 0)
        return "0";
    if (x == 1)
        return "1";
    if (x == 10)
        return "10";
    char a[basamakSayisi(x)] = {""};
    for (int i = 0; i < basamakSayisi(x); i++)
    {
        a[basamakSayisi(x) - i - 1] = lerBasamagi(x, i + 1) + 48;
    }
    return a;
}
string secim(string a, int x, int y)
{
    char ans[y - x + 10] = "          ";
    for (int i = x; i < y; i++)
    {
        ans[i - x] = a[i];
    }
    return ans;
}
int stringInt(string x)
{
    stringstream geek(x);
    int ans = 0;
    geek >> ans;
    return ans;
}
double stringDouble(string x)
{
    bool ca = true;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '.')
            ca = false;
    }
    if (ca)
        return (double)stringInt(x);
    if (x.size() <= 0)
        return 0.0;
    double a = 0.0;
    double q = 0;
    bool bo = true;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] >= 48 && x[i] <= 57)
        {
            a *= 10;
            a += x[i] - 48;
        }
        else if (bo && (x[i] == '.'))
        {
            q = (double)i;
            bo = false;
        }
        else
            return 0.0;
    }
    return a / us(10, x.size() - q - 1);
}
void ekranBasliginiDegistir(char *x)
{
    SetConsoleTitleA(x);
    return;
}
string buyukHarfYap(string a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > 'Z')
            a[i] -= 32;
    }
    return a;
}
char buyukHarfYap(char a)
{
    if (a > 'Z')
        a -= 32;
    return a;
}
void renklendir(int x)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    return;
}
void renklendir(int arkaplan, int yazi)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arkaplan * 16 + yazi);
    return;
}
void dil(char kelime[100])
{
    setlocale(LC_ALL, kelime);
    return;
}
void kursorGorunurlugu(bool durum)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorinfo;
    GetConsoleCursorInfo(out, &cursorinfo);
    cursorinfo.bVisible = durum;
    SetConsoleCursorInfo(out, &cursorinfo);
    return;
}
void kursorKonumu(short satir, short sutun)
{
    COORD coord;
    coord.X = satir;
    coord.Y = sutun;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}
void kursorKonumu(COORD coord)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}
COORD fareKonumu()
{
    COORD x;
    POINT p;
    GetCursorPos(&p);
    x.X = p.x - ekranKonumu().X;
    x.Y = p.y - ekranKonumu().Y - 30;
    if (x.X < 0 || x.Y < 0)
    {
        x.X = 0;
        x.Y = 0;
    }
    return x;
}
COORD fareKonumu(COORD c)
{
    int x = c.X, y = c.Y;
    SetCursorPos(x, y);
    COORD a;
    a.X = x;
    a.Y = y;
    return a;
}
COORD fareKonumu(int x, int y)
{
    SetCursorPos(x, y);
    COORD a;
    a.X = x;
    a.Y = y;
    return a;
}
void yaz(string x, float beklemeSuresi = 0.0)
{
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i];
        bekle(beklemeSuresi);
    }
    return;
}
void yaz(long long int a, float beklemeSuresi = 0.0)
{
    string x = intString(a);
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i];
        bekle(beklemeSuresi);
    }
    return;
}
void fareyeBasSol()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, fareKonumu().X, fareKonumu().Y, 0, 0);
    return;
}
void fareyiBirakSol()
{
    mouse_event(MOUSEEVENTF_LEFTUP, fareKonumu().X, fareKonumu().Y, 0, 0);
    return;
}
void fareninSolunaTikla()
{
    fareyeBasSol();
    fareyiBirakSol();
    return;
}
struct tm *suan()
{
    struct tm *a;
    time_t b;
    time(&b);
    a = localtime(&b);

    return a;
}
void fareyeBasSag()
{
    mouse_event(MOUSEEVENTF_RIGHTDOWN, fareKonumu().X, fareKonumu().Y, 0, 0);
    return;
}
void fareyiBirakSag()
{
    mouse_event(MOUSEEVENTF_RIGHTUP, fareKonumu().X, fareKonumu().Y, 0, 0);
    return;
}
void fareninSaginaTikla()
{
    fareyeBasSag();
    fareyiBirakSag();
    return;
}
void siteyeGit(char url[])
{
    char ans[strlen(url) + 100] = "start https://                                                                                                    ";
    for (int i = 0; i < strlen(url); i++)
        ans[i + 14] = url[i];
    system(ans);
    return;
}
void dosyayaGit(char url[])
{
    char ans[strlen(url) + 100] = "start                                                                                                             ";
    for (int i = 0; i < strlen(url); i++)
        ans[i + 6] = url[i];
    system(ans);
    return;
}
void dosyaAc(char url[])
{
    char ans[strlen(url) + 100] = "start                                                                                                             ";
    for (int i = 0; i < strlen(url); i++)
        ans[i + 6] = url[i];
    system(ans);
    return;
}
int strlen(string x)
{
    return x.size();
}
void dosyayaGit(string url)
{
    char ans[strlen(url) + 100] = "start                                                                                                             ";
    for (int i = 0; i < strlen(url); i++)
        ans[i + 6] = url[i];
    system(ans);
    return;
}
void fareyiHareketlendir(int x, int y)
{
    fareKonumu(fareKonumu().X + x, fareKonumu().Y - y);
    return;
}
void tusaBas(int x)
{
    keybd_event(x, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    return;
}
void tusuBirak(int x)
{
    keybd_event(x, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    return;
}
void tusaTikla(int x)
{
    keybd_event(x, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
    keybd_event(x, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    return;
}
void tuslaraBas(string x, float y = 0.0)
{
    if (x == "0")
    {
        keybd_event('0', 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
        keybd_event('0', 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
        return;
    }
    if (x == "1")
    {
        keybd_event('1', 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
        keybd_event('1', 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
        return;
    }
    if (x == "10")
    {
        keybd_event('1', 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
        keybd_event('1', 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
        keybd_event('0', 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
        keybd_event('0', 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
        return;
    }
    x = buyukHarfYap(x);
    for (int i = 0; i < x.size(); i++)
    {
        if(x[i]=='\n') tusaTikla(ALTSATIR); 
        keybd_event(x[i], 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
        keybd_event(x[i], 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
        if (i != x.size() - 1)
            bekle(y);
    }
    return;
}
void sifreKir(long long int x, long long int y, double s, char q = 'Q')
{
    for (long long int i = x; i < y && !basilimi(q); i++)
    {
        tuslaraBas(intString(i));
        tusaBas(ALTSATIR);
        tusuBirak(ALTSATIR);
        bekle(s);
    }
    return;
}
pair<long long int, long long int> sifreOlustur(long long int x = rand())
{
    long long int a, i = 0;
    cin >> a;
    while (a != x)
    {
        cin >> a;
        i++;
    }
    return make_pair(x, i);
}
long long int salla(long long int x = 0, long long int y = -1)
{
    if (x > y)
    {
        int g = x;
        x = y;
        y = g;
    }
    long long int ans = LLONG_MIN;
    while (ans < x)
        ans = rand() % (y + 1);
    return ans;
}
pair<long long int, long long int> sifreOlustur(long long int x, long long int y)
{
    long long int a, i = 0;
    if (y < 0)
        return make_pair(0, 0);
    x = salla(x, y);
    cin >> a;
    while (a != x)
    {
        cin >> a;
        i++;
    }
    return make_pair(x, i);
}
void googleCeviri(string a)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == ' ')
            a[i] = '+';
    char b[a.size() + 100] = "translate.google.com.tr/?text=                                                                      ";
    for (int i = 0; i < a.size(); i++)
    {
        b[i + 30] = a[i];
    }
    siteyeGit(b);
    return;
}
void googleArama(string a)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == ' ')
            a[i] = '+';
    char b[a.size() + 100] = "www.google.com/search?q=                                                                            ";
    for (int i = 0; i < a.size(); i++)
    {
        b[i + 24] = a[i];
    }
    siteyeGit(b);
    return;
}
void bingArama(string a)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == ' ')
            a[i] = '+';
    char b[a.size() + 100] = "www.bing.com/search?q=                                                                              ";
    for (int i = 0; i < a.size(); i++)
    {
        b[i + 24] = a[i];
    }
    siteyeGit(b);
    return;
}
void youtubeArama(string a)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == ' ')
            a[i] = '+';
    char b[a.size() + 100] = "www.youtube.com/results?search_query=                                                               ";
    for (int i = 0; i < a.size(); i++)
    {
        b[i + 37] = a[i];
    }
    siteyeGit(b);
    return;
}
void yandexArama(string a)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == ' ')
            a[i] = '+';
    char b[a.size() + 100] = "yandex.com.tr/search/?text=                                                                         ";
    for (int i = 0; i < a.size(); i++)
    {
        b[i + 27] = a[i];
    }
    siteyeGit(b);
    return;
}
void yandexCeviri(string a)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == ' ')
            a[i] = '+';
    char b[a.size() + 100] = "ceviri.yandex.com.tr/?text=                                                                         ";
    for (int i = 0; i < a.size(); i++)
    {
        b[i + 27] = a[i];
    }
    siteyeGit(b);
    return;
}
long long int faktoriyel(long long int x)
{
    if (x == 0)
        return 1;
    return x * faktoriyel(x - 1);
}
long long int araligiTopla(long long int baslangic, long long int bitis, long long int artismiktari = 1)
{
    if (artismiktari == 0)
        return -1;
    return (bitis - baslangic) / artismiktari + 1;
}
int kacinciElemani(vector<string> x, string a)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == a)
            return i;
    }
    return -1;
}
int kacinciElemani(vector<int> x, int a)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == a)
            return i;
    }
    return -1;
}
int kacinciElemani(vector<float> x, float a)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == a)
            return i;
    }
    return -1;
}
long long int permutasyon(long long int x, long long int y)
{
    return faktoriyel(x) / faktoriyel(y);
}
long long int kombinasyon(long long int x, long long int y)
{
    return permutasyon(x, y) / faktoriyel(y);
}
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    return;
}
void sesCal(char x[], string sourge)
{
    if (x == ".m4a")
    {
        tusaBas(WINDOWS);
        tusuBirak(WINDOWS);
        tuslaraBas("Voice Recorder", 0.0);
        tusaBas(ALTSATIR);
        tusuBirak(ALTSATIR);
        return;
    }
    else
    {
        if (sourge != "")
            dosyayaGit((string)sourge + (string) "/" + (string)x);
        else
            dosyayaGit((string)x);
    }
    return;
}
void uygulamaAc(string ad)
{
    tusaBas(WINDOWS);
    tusuBirak(WINDOWS);
    Sleep(100);
    tuslaraBas(ad);
    Sleep(200);
    tusaBas(ALTSATIR);
    tusuBirak(ALTSATIR);
    return;
}
void soyle(string x, string sourge = "")
{
    sesCal("g.m4a", sourge);
    Sleep(200);
    for (int i = 0; i < x.size(); i++)
    {
        char a[5];
        a[0] = x[i];
        a[1] = '.';
        a[2] = 'm';
        a[3] = '4';
        a[4] = 'a';
        if (x[i] == ' ')
        {
            Sleep(200);
            continue;
        }
        sesCal(a, sourge);
        Sleep(200);
    }
    return;
}
void sesiYap(int a)
{
    COORD b = fareKonumu();
    fareKonumu(1111, 750);
    fareninSolunaTikla();
    Sleep(750);
    fareKonumu(1075 + 2.25 * a, 700);
    fareninSolunaTikla();
    fareKonumu(950, 750);
    fareninSolunaTikla();
    fareKonumu(b);
    return;
}
void isigiYap(int a)
{
    COORD b = fareKonumu();
    fareKonumu(1330, 750);
    fareninSolunaTikla();
    Sleep(750);
    fareKonumu(1055 + 2.45 * a, 671);
    fareninSolunaTikla();
    Sleep(750);
    fareKonumu(950, 750);
    fareninSolunaTikla();
    fareKonumu(b);
    return;
}
void interneteBaglan()
{
    COORD b = fareKonumu();
    fareKonumu(1166, 750);
    fareninSolunaTikla();
    Sleep(750);
    fareKonumu(1205, 185);
    fareninSolunaTikla();
    Sleep(750);
    fareKonumu(1205, 275);
    fareninSolunaTikla();
    fareKonumu(950, 750);
    fareninSolunaTikla();
    fareKonumu(b);
    return;
}
void solMasaustu(int x = 0)
{
    tusaBas(KONTROL);
    tusaBas(WINDOWS);
    tusaBas(SOLOK);
    tusuBirak(SOLOK);
    tusuBirak(WINDOWS);
    tusuBirak(KONTROL);
    Sleep(x);
    return;
}
void sagMasaustu(int x = 0)
{
    tusaBas(KONTROL);
    tusaBas(WINDOWS);
    tusaBas(SAGOK);
    tusuBirak(SAGOK);
    tusuBirak(WINDOWS);
    tusuBirak(KONTROL);
    Sleep(x);
    return;
}
// zaman
#define salise suan()->
#define saniye suan()->tm_sec
#define dakika suan()->tm_min
#define saat suan()->tm_hour
#define gun suan()->tm_yday
#define ay suan()->tm_mon
#define yil suan()->tm_year
// nota
#define do 261.6
#define re 293.7
#define mi 329.6
#define fa 349.2
#define sol 392.0
#define la 440.0

void noktaKoy(int x, int y, char k = 219, int r = BEYAZ)
{
    renklendir(r);
    kursorKonumu(x, y);
    cout << k;
    return;
}
void noktaKoy(COORD coord, char k = 219, int r = BEYAZ)
{
    renklendir(r);
    kursorKonumu(coord);
    cout << k;
    return;
}
void cizgi(int x1, int y1, int x2, int y2, char k = 219)
{
    int my = 0;
    if (abs(x2 - x1) >= abs(y2 - y1))
    {
        if (x2 >= x1)
        {
            float x = abs(x2 - x1), y = abs(y2 - y1), oran = y / x;
            for (int i = 0; i < x; i++)
            {
                kursorKonumu(i + x1, y1 + i * oran * -1);
                cout << k;
                if (y > my)
                    my = y;
            }
        }
        else
        {
            float x = abs(x2 - x1), y = abs(y2 - y1), oran = y / x;
            for (int i = 0; i < x; i++)
            {
                kursorKonumu(-1 * i + x1, y1 + i * oran);
                cout << k;
                if (my < y)
                    my = y;
            }
        }
        kursorKonumu(0, my);
    }
    else
    {
        if (y1 >= y2)
        {
            float x = abs(x2 - x1), y = abs(y2 - y1), oran = x / y;
            for (int i = 0; i < y; i++)
            {
                kursorKonumu(max(x1, x2) - (oran * i + min(x1, x2)), min(y1, y2) + i);
                cout << k;
            }
        }
    }
    return;
}
void doluUcgen(int h, int x, int y, char k = 219)
{
    for (int i = 1; i <= h; i = i + 1)
    {
        kursorKonumu(x - i, y + i - 1);
        for (int k1 = 1; k1 <= i + i - 1; k1 = k1 + 1)
            cout << k;
    }
    return;
}
void ucgen(int h, int x, int y, char k = 219)
{
    for (int i = 1; i <= h; i = i + 1)
    {
        kursorKonumu(x - i, y + i - 1);
        cout << k;
        for (int k = 1; k <= i + i - 1; k = k + 1)
            noktaKoy(x + i - 1, y + i - 1);
        if (i == h)
        {
            kursorKonumu(x - i, y + i - 1);
            for (int i = 0; i < h * 2; i++)
            {
                cout << (char)219;
            }
        }
    }
    return;
}
void doluKare(int x1, int y1, int x2, int y2, char k = 219)
{
    for (int i = y1; i < y2; i++)
        for (int j = x1; j < x2; j++)
            noktaKoy(i, j, k);
    return;
}
void kare(int x1, int y1, int x2, int y2, char k = 219)
{
    for (int i = y1; i < y2; i++)
    {
        if (i == y1 || i == y2 - 1)
        {
            for (int j = x1; j < x2; j++)
                noktaKoy(j, i, k);
            continue;
        }
        noktaKoy(x1, i);
        noktaKoy(x2 - 1, i);
    }
    return;
}
void dusun(string k, float bs, int s)
{
    yaz(k, bs);
    cout << ".";
    Sleep(bs * 1000.0);
    cout << ".";
    Sleep(bs * 1000.0);
    cout << ".";
    Sleep(bs * 1000.0);
    for (int i = 0; i < s; i++)
    {
        printf("\b \b");
        Sleep(500);
        printf(".");
        Sleep(500);
    }
    for (int i = 0; i < k.size() + 3; i++)
    {
        printf("\b \b");
    }
    return;
}
int zarAt()
{
    return salla(1, 6);
}
void basla(bool f = 1, bool d = 1, bool r = 1)
{
    if (f)
        fast();
    if (d)
        dil("Turkish");
    if (r)
        randomize;
    return;
}
void start(bool f = 1, bool d = 1, bool r = 1)
{
    if (f)
        fast();
    if (d)
        dil("Turkish");
    if (r)
        randomize;
    return;
}
#define dongudenC�k break
#define donguyeDevam continue
int renk(bool r, bool g, bool b)
{
    int c = r * 100 + g * 10 + b;
    if (c == 0)
        return SIYAH;
    if (c == 111)
        return BEYAZ;
    if (c == 1)
        return MAVI;
    if (c == 10)
        return YESIL;
    if (c == 100)
        return KIRMIZI;
    if (c == 110)
        return SARI;
    if (c == 101)
        return MOR;
    if (c == 11)
        return ACIK_DENIZ_MAVISI;
}
void dosyayiSil(string a)
{
    remove(a.c_str());
    return;
}
void dosyaOlustur(string a)
{
    ofstream x(a.c_str());
    x.close();
    return;
}
void dosyayaYaz(string url, string yazi)
{
    fstream a(url.c_str());
    if (!a)
    {
        dosyaOlustur(url);
        a.open(url.c_str());
    }
    a << yazi;
    a.close();
    return;
}
void kursorFareKonumuna()
{
    COORD fare = fareKonumu();
    int x = fare.X;
    int y = fare.Y;
    kursorKonumu(x / 11, y / 23 >= 3 ? ((y) / 23 - 1) : (y / 23));
    return;
}
pair<double,double> cemberinAcidakiDegerleri(double x, double y, double r, double d)
{
    pair<double,double> a;
    double radyan = d * 3.14159265358979 / 180.0;
    a.first = cos(radyan) * r + x;
    a.second = sin(radyan) * r + y;
    return a;
}
void cember(int r, int x, int y, int s = 0, int d1 = 0, int d2 = 360, char k = 219)
{
    int my = INT_MIN;
    for (int derece = d1; derece < d2; derece++)
    {
        double radyan = derece * 3.14159265358979 / 180.0;
        double X = cos(radyan) * r;
        double Y = sin(radyan) * r;
        if (Y < r && X < r)
        {
            kursorKonumu(x + X, Y + y);
            cout << k;
        }
        if ((Y + y) > my)
            my = y + Y;
        Sleep(s);
    }
    if (my < y)
        my = y;
    kursorKonumu(0, my);
    return;
}
void daire(int r, int x, int y, int s = 0, int d1 = 0, int d2 = 360, char k = 219)
{
    for (int i = 1; i <= r; i++)
    {
        cember(i, x, y, 0, d1, d2, k);
        Sleep(s);
    }
    return;
}
void noktaUzerindeSallan(int kx, int ky, int x, int y, int d1, int d2, int s = 10)
{
    int ux = kx - x;
    int uy = ky - y;
    int r = sqrt(ux * ux + uy * uy);
    if (d1 > d2)
        for (int i = d1; !basilimi(BOSLUK) && i > d2; i--)
        {
            pair<double,double> a = cemberinAcidakiDegerleri(x, y, r, i + 1);
            noktaKoy(a.first,a.second, ' ');
            a = cemberinAcidakiDegerleri(x, y, r, i);
            noktaKoy(a.first,a.second);
            Sleep(s);
        }
    else
        for (int i = d1; !basilimi(BOSLUK) && i < d2; i++)
        {
            pair<double,double> a = cemberinAcidakiDegerleri(x, y, r, i - 1);
            noktaKoy(a.first,a.second, ' ');
            a = cemberinAcidakiDegerleri(x, y, r, i);
            noktaKoy(a.first,a.second);
            Sleep(s);
        }
    return;
}
class monopolyMenajer
{
public:
    string ad;
    int para;
    monopolyMenajer()
    {
        system("cls");
        yaz("Ad�n�z:\n", 0.02);
        cin >> ad;
        system("cls");
        yaz("Paran�z:\n", 0.02);
        cin >> para;
        system("cls");
    }
    void menu()
    {
        system("cls");
        int ans;
        yaz("Se�enekler:\n1)Kart alma\n2)Zar atma\n3)Kira alma\n4)Para sorgulama\n5)�cret verme\n", 0.02);
        cin >> ans;
        if (ans == 1)
        {
            kartAl();
            system("cls");
            return;
        }
        if (ans == 2)
        {
            system("cls");
            int a = zarAt(), b = zarAt(), c = a + b;
            cout << a;
            Sleep(20);
            cout << "+";
            Sleep(20);
            cout << b;
            Sleep(20);
            cout << "=";
            Sleep(20);
            cout << c << endl;
            Sleep(20);
            getch();
            system("cls");
            return;
        }
        if (ans == 3)
        {
            system("cls");
            int a = 0;
            yaz("Ka� lira kira al�nacak:\n", 0.02);
            cin >> a;
            para += a;
            system("cls");
            return;
        }
        if (ans == 4)
        {
            system("cls");
            yaz("Hesab�n�zda ", 0.02);
            cout << para;
            yaz(" lira bulunmakta.\n", 0.02);
            getch();
            system("cls");
            return;
        }
        if (ans == 5)
        {
            system("cls");
            int a = 0;
            yaz("Ka� lira verilecek:\n", 0.02);
            cin >> a;
            para -= a;
            system("cls");
            return;
        }
    }

private:
    bool kartAlinsinMi(int toplamAyniRenk, int param, int maaliyet, int kartinIlkKari, int kartinSonKari, int ayniRenk)
    {
        if (param < maaliyet)
        {
            system("cls");
            yaz("Kart al�nmamal�(Para yetersiz)\n", 0.02);
            getch();
            system("cls");
            return 0;
        }
        if (maaliyet < 50)
        {
            system("cls");
            yaz("Kart al�nmal�(<50 kural�)\n", 0.02);
            getch();
            system("cls");
            return 1;
        }
        if (toplamAyniRenk - ayniRenk == 1)
        {
            system("cls");
            yaz("Kart al�nmal�(renk tamamlama kural�)\n", 0.02);
            getch();
            system("cls");
            return 1;
        }
        if (param < maaliyet * 5)
        {
            system("cls");
            yaz("Kart al�nmamal�(�ok pahal�)\n", 0.02);
            getch();
            system("cls");
            return 0;
        }
        if (kartinIlkKari + kartinSonKari < maaliyet * 3)
        {
            system("cls");
            yaz("Kart al�nmamal�(toplam kar maliyeti tutmuyor)\n", 0.02);
            getch();
            system("cls");
            return 0;
        }
        system("cls");
        yaz("Kart al�nmal�\n", 0.02);
        getch();
        system("cls");
        return 1;
    }
    void kartAl()
    {
        system("cls");
        int toplamAyniRenk, maaliyet, kartinIlkKari, kartinSonKari, ayniRenk;
        yaz("�uan bulundu�um kart�n maaliyeti ne kadar:\n", 0.02);
        cin >> maaliyet;
        yaz("�uan bulundu�um kart�n ilk ve son kar� ne kadar:\n", 0.02);
        cin >> kartinIlkKari >> kartinSonKari;
        yaz("�uan bulundu�um kart ile ayn� renkten olan ka� kart benim:\n", 0.02);
        cin >> ayniRenk;
        yaz("�uan bulundu�um kart ile ayn� renkten olan kart say�s� ne kadar:\n", 0.02);
        cin >> toplamAyniRenk;
        system("cls");
        dusun("Veri y�kleniyor", 0.02, 3);
        if (kartAlinsinMi(toplamAyniRenk, para, maaliyet, kartinIlkKari, kartinSonKari, ayniRenk))
        {
            bool xyz;
            int xyz2;
            yaz("Kart al�ns�nm�:\n1:evet\n2:hay�r\n");
            cin >> xyz2;
            if (xyz2 == 1)
                para -= maaliyet;
        }
        return;
    }
};
void fareKontrolu(int sagh, int solh, int usth, int alth, int sagtik, int soltik, int s, int h)
{
    if (sagh != -1)
        if (basilimi(sagh))
            fareyiHareketlendir(h, 0);
    if (solh != -1)
        if (basilimi(solh))
            fareyiHareketlendir(-1 * h, 0);
    if (usth != -1)
        if (basilimi(usth))
            fareyiHareketlendir(0, h);
    if (alth != -1)
        if (basilimi(alth))
            fareyiHareketlendir(0, -1 * h);
    if (sagtik != -1)
        if (basilimi(sagtik))
        {
            fareninSaginaTikla();
            Sleep(s * 50);
        }
    if (soltik != -1)
        if (basilimi(soltik))
        {
            fareninSolunaTikla();
            Sleep(s * 50);
        }
    Sleep(s);
    return;
}
void uygulamaKapat(string a)
{
    string b = (string) "taskkill /pid " + a;
    system(b.c_str());
    system("cls");
    return;
}
void acikUygulamalariGoster()
{
    system("Tasklist");
    return;
}
void zorlaUygulamaKapat(string a)
{
    string b = (string) "taskkill /pid " + a + (string) "/f";
    system(b.c_str());
    system("cls");
    return;
}
void urunAnahtariBulma()
{
    system("wmic path softwarelicensingservice get OA3xOriginalProductKey");
    return;
}
void cmd(string a)
{
    system(a.c_str());
    return;
}
void cmd(char a[])
{
    system(a);
    return;
}
void bilgisayariHizlandir()
{
    system("sfc /scannow");
    return;
}
COORD intCoord(int x, int y)
{
    COORD a;
    a.X = x;
    a.Y = y;
    return a;
}
void python(string a)
{
    dosyayaYaz("main.py", a);
    dosyaAc("main.py");
    return;
}
void beatch(string a)
{
    dosyayaYaz("main.bat", (string) "echo off\ncls\n" + a + (string) "\nexit();\n");
    dosyaAc("main.bat");
    return;
}
void yuklemeCizgisi(int x, int y, int s, int bas, int son, string yazi)
{
    kursorKonumu(x, y);
    kursorGorunurlugu(0);
    cout << yazi;
    for (int i = 0; i < bas; i++)
        cout << (char)219;
    for (int i = 1; i <= son - bas; i++)
    {
        int a = (i * 100) / son;
        kursorKonumu(x + i - 1 + yazi.size(), y);
        cout << (char)219;
        kursorKonumu(x + son + yazi.size(), y);
        cout << "%" << a << "      ";
        for (int i = 0; i < basamakSayisi(y) + 7; i++)
            cout << "\b";
        Sleep(s);
    }
    kursorGorunurlugu(1);
    return;
}
void ascii()
{
    for (int i = 14; i < 100; i++)
    {
        cout << i << "  -> " << (char)i << "    ";
        if ((i - 5) % 8 == 0)
            cout << endl;
    }
    for (int i = 100; i < 255; i++)
    {
        cout << i << " -> " << (char)i << "    ";
        if ((i - 5) % 8 == 0)
            cout << endl;
    }
    return;
}
double kareKok(double x)
{
    for (double i = 0; i < x; i++)
    {
        if (i * i == x)
            return i;
        else if (i * i > x)
            return i + (x - (i - 1) * (i - 1)) / (i * i - (i - 1) * (i - 1)) - 1;
    }
}
void getHtml(string site, string fileName)
{
    system((string("curl ") + site + string(" > ") + fileName).c_str());
    return;
}
void klavyeOku(char *tuslar)
{
    for (int i = 0; i < 256; i++)
        tuslar[i] = char(GetAsyncKeyState(i) >> 8);
    return;
}
void uygulamalriGoster(){
    system("tasklist");
    return;
}
void uygulamaBaslat(string a){
    system((string("taskkill -im ")+a+string(".exe /f")).c_str());
    return;
}
int islem(string x){
    system((string("set /a ")+x+string(" > a.txt")).c_str());
    fstream a("a.txt",ios::in);
    int i;
    a>>i;
    a.close();
    system("del a.txt");
    return i;
}
void fonksyonCagir(int (*func)(void)){
    func();
}
int f(){
    cout<<"parametre Olarak bu fonksyonu aldi";
}
#define sayi 1
#define kelime "1"
#define karakter '1'

template<typename T>
struct degisken{
	void ekle(string name,T x){
		fstream w("val.log",ios::out|ios::ate);
		w<<name<<" "<<x;
		w.close();
		return;
	}
	T deger(string name){
        T ornek;
		fstream w("val.log",ios::in);
		string x;
		while(x!=name){
			w>>x;
			w>>ornek;
		}
		w.close();
		return ornek;
	}
	T degis(string name,T deger){
		fstream w("val.log",ios::in|ios::out);
		string x;
		while(x!=name){
			w>>x;
			if(x==name) break;
			w>>deger;
		}
		w<<" "<<deger<<"                    ";
		w.close();
		return deger;
	}
};
void seslendir(string a){
    ofstream x("a.txt");
    x<<a;
    x.close();
    system("seslendir < a.txt && rm a.txt");
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

void __attribute__((constructor)) merhaba();
void __attribute__((destructor)) bye();
function<int(int,int)> fonksyonIcindeFonksyon = [](int x,int y){
    return x+y;
};
void arkaPlandaAc(string x){
    system((string("powershell Start-Process -WindowStyle hidden -FilePath ")+x).c_str());
    return;
}