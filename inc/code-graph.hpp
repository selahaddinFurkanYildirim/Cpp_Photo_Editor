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
#include <graphics.h>
#include <code.hpp>
using namespace std;

void kutu(int x1, int y1, int x2, int y2)
{
    line(x1, y1+5, x1, y2-5);
    line(x1+5, y1, x2-5, y1);
    line(x2, y1+5, x2, y2-5);
    line(x2-5, y2, x1+5, y2);
    return;
}
bool buton(int x1, int y1, int x2, int y2, char *a = "", char *name = "", colors c1 = LIGHTGRAY, colors c2 = DARKGRAY, colors onrenk = WHITE, colors arkarenk = BLACK)
{
    if (x1 < mousex() && x2 > mousex() && y1 < mousey() && y2 > mousey() && a != "")
    {
        setbkcolor(c1);
        setcolor(arkarenk);
        outtextxy(x1, y1 - 23, a);
        setcolor(onrenk);
        setbkcolor(arkarenk);
    }
    if (x1 < mousex() && x2 > mousex() && y1 < mousey() && y2 > mousey() && basilimi(FARENINSOLU) && basilimi(FARENINSOLU))
    {
        if (x1 < mousex() && x2 > mousex() && y1 < mousey() && y2 > mousey() && basilimi(FARENINSOLU))
        {
            line(x1, y1, x2, y1);
            line(x1, y2, x2, y2);
            line(x1, y2, x1, y1);
            line(x2, y2, x2, y1);
            setfillstyle(1, c2);
            bar(x1 + 2, y1 + 2, x2 - 1, y2 - 1);
            setfillstyle(1, WHITE);
            setbkcolor(c2);
            setcolor(onrenk);
            outtextxy(x1 + 2, (y1 + y2) / 2 - 5, name);
            setcolor(onrenk);
            setbkcolor(arkarenk);
            return 1;
        }
    }
    setfillstyle(1, c1);
    bar(x1 + 2, y1 + 2, x2 - 1, y2 - 1);
    setfillstyle(1, WHITE);
    //////////////////////////
    setbkcolor(c1);
    setcolor(arkarenk);
    outtextxy(x1 + 2, (y1 + y2) / 2 - 5, name);
    setcolor(onrenk);
    setbkcolor(arkarenk);
    return 0;
}
struct BUTON
{
    int x1;
    int y1;
    int x2;
    int y2;
    char *a = "";
    char *name = "";
    colors c1 = LIGHTGRAY, c2 = DARKGRAY;
    void degerAta(int a1, int b1, int a2, int b2)
    {
        x1 = a1;
        x2 = a2;
        y1 = b1;
        y2 = b2;
        return;
    }
    bool ciz()
    {
        return buton(x1, y1, x2, y2, a, name, c1, c2);
    }
};
void metinKutusu(int x1, int y1, int x2, int y2, string x, bool is_opened=0, colors arkarenk=BLACK, colors onrenk=WHITE)
{
    setcolor(onrenk);
    setbkcolor(arkarenk);
    kutu(x1 + 2, y1 + 2, x2 - 2, y2 - 2);
    if (is_opened && time(NULL) % 2)
        x.push_back('|');
    else
        x.push_back(' ');
    char a[x.size()];
    for (int i = 0; i < x.size(); i++)
    {
        a[i] = x[i];
        a[i + 1] = NULL;
        a[i + 2] = NULL;
        a[i + 3] = NULL;
        a[i + 4] = NULL;
    }
    outtextxy(x1 + 3, y1 + 3, a);
}
class METINKUTUSU
{
private:
    int SleepAfter=0;
public:
    bool is_opened = 0;
    string x = "";
    int x1 = 10, y1 = 10, x2 = 200, y2 = 50;
    void degerAta(int a1, int b1, int a2, int b2)
    {
        x1 = a1, y1 = b1, x2 = a2, y2 = b2;
    }
    void ciz(){
        metinKutusu(x1,y1,x2,y2,x,is_opened);
        Sleep(SleepAfter);
        SleepAfter=0;
    }
    void yenile(int appx=0, int appy=0)
    {
        if (is_opened)
        {
            for (int i = 65; i < 91; i++)
            {
                if (basilimi(i))
                {
                    if (basilimi(BUYUK))
                        x.push_back(char(i)), SleepAfter+=125;
                    else
                        x.push_back(char(i + 'z' - 'Z')), SleepAfter+=125;
                }
            }
            for (int i = 20; i < 65; i++)
            {
                if (basilimi(i))
                {
                    x.push_back(char(i)), SleepAfter+=125;
                }
            }
            for (int i = 91; i < 128; i++)
            {
                if (basilimi(i))
                {
                    x.push_back(char(i)), SleepAfter+=125;
                }
            }
            if (basilimi(GERI))
            {
                if (x.size())
                {
                    string y;
                    for (int i = 0; i < x.size() - 1; i++)
                        y += x[i];
                    x = y;
                    SleepAfter+=125;
                }
            }
        }
        else
            for (int i = 41; i < 91; i++)
            {
                if (basilimi(i))
                    ;
                if (basilimi(BOSLUK))
                    ;
                if (basilimi(GERI))
                    ;
            }
        if (basilimi(FARENINSOLU))
        {
            if (mousex() < x2 + appx && mousex() > x1 + appx && mousey() > y1 + appy && mousey() < y2 + appy)
            {
                is_opened = 1;
            }
            else
                is_opened = 0;
        }
    }
};

void metinxy(int x1,int y1,string x){
    char a[x.size()];
    for (int i = 0; i < x.size(); i++)
    {
        a[i] = x[i];
        a[i + 1] = NULL;
        a[i + 2] = NULL;
        a[i + 3] = NULL;
        a[i + 4] = NULL;
    }
    outtextxy(x1, y1, a);
    return;
}
class BILDIRIKUTUSU
{
private:
public:
    string x = "";
    int x1 = 10, y1 = 10, x2 = 200, y2 = 50;
    void degerAta(int a1, int b1, int a2, int b2)
    {
        x1 = a1, y1 = b1, x2 = a2, y2 = b2;
    }
};
void bildiriKutusu(int x1, int y1, int x2, int y2, string x)
{
    kutu(x1 + 2, y1 + 2, x2 - 2, y2 - 2 + 25);
    char a[x.size()];
    for (int i = 0; i < x.size(); i++)
    {
        a[i] = x[i];
        a[i + 1] = NULL;
        a[i + 2] = NULL;
        a[i + 3] = NULL;
        a[i + 4] = NULL;
    }
    outtextxy(x1 + 3, y1 + 3, a);
    return;
}
struct CIZGI
{
    int x1, y1, x2, y2;
};
class AppPage
{
private:
public:
    bool fullscr = 0;
    bool is_hide = 0;
    bool is_opened = 1;
    vector<CIZGI> cizgiler;
    vector<BUTON> butonlar;
    vector<METINKUTUSU> metinler;
    vector<BILDIRIKUTUSU> bildiriler;
    bool is_open = 0;
    colors onrenk = BLACK, arkarenk = WHITE;
    string name = "My Application";
    int x1 = 25, y1 = 25, x2 = 350, y2 = 250;
    void sifirla()
    {
        while (cizgiler.size())
            cizgiler.pop_back();
        while (butonlar.size())
            butonlar.pop_back();
        while (metinler.size())
            metinler.pop_back();
        while (bildiriler.size())
            bildiriler.pop_back();
    }
    void ciz(int sayfaSayisi = 1)
    {
        if (fullscr)
        {
            x1 = 2;
            x2 = getmaxx() - 2;
            y1 = 2;
            y2 = getmaxy() - 27;
        }
        if (!is_opened)
            return;
        char namec[1000];
        for (int i = 0; i < name.size(); i++)
        {
            namec[i] = name[i];
            namec[i + 1] = NULL;
            namec[i + 2] = NULL;
            namec[i + 3] = NULL;
            namec[i + 4] = NULL;
        }
        if (is_hide)
        {
        if (buton(25 * sayfaSayisi - 25, getmaxy() - 25, 25 * sayfaSayisi, getmaxy(), namec, "+"))
            is_hide = !is_hide, delay(50);
            return;
        }
        setcolor(onrenk);
        setbkcolor(arkarenk);
        char a[name.size()] = "                   ";
        for (int i = 0; i < name.size(); i++)
            a[i] = name[i], a[i + 1] = NULL;
        kutu(x1, y1, x2, y2);
        if (buton(x1, y1, x2, y1 + 25, "", a))
            is_open = 1;
        else
            is_open = 0;
        
        for (int i = 0; i < butonlar.size(); i++)
        {
            if (butonlar[i].x2 < x2 - x1 && butonlar[i].y2 < y2 - y1 - 25)
                buton(butonlar[i].x1 + x1, butonlar[i].y1 + y1 + 25, butonlar[i].x2 + x1, butonlar[i].y2 + y1 + 25, butonlar[i].a, butonlar[i].name, butonlar[i].c1, butonlar[i].c2);
        }
        setcolor(onrenk);
        setbkcolor(arkarenk);
        for (int i = 0; i < bildiriler.size(); i++)
        {
            if (bildiriler[i].x2 < x2 - x1 && bildiriler[i].y2 < y2 - y1 - 50)
                bildiriKutusu(bildiriler[i].x1 + x1, bildiriler[i].y1 + y1 + 25, bildiriler[i].x2 + x1, bildiriler[i].y2 + y1 + 25, bildiriler[i].x);
        }
        for (int i = 0; i < cizgiler.size(); i++)
        {
            if (cizgiler[i].x2 < x2 - x1 && cizgiler[i].y2 < y2 - y1 - 25)
                line(cizgiler[i].x1 + x1, cizgiler[i].y1 + y1 + 25, cizgiler[i].x2 + x1, cizgiler[i].y2 + y1 + 25);
        }
        for (int i = 0; i < metinler.size(); i++)
        {
            if (metinler[i].x2 < x2 - x1 && metinler[i].y2 < y2 - y1 - 25)
                metinKutusu(metinler[i].x1 + x1, metinler[i].y1 + y1 + 25, metinler[i].x2 + x1, metinler[i].y2 + y1 + 25, metinler[i].x, metinler[i].is_opened, arkarenk, onrenk);
        }
        if (buton(x2 - 25, y1, x2, y1 + 25, "Kapat", " x", LIGHTGRAY, RED))
        {
            string b = name;
            name = "BYE";
            delay(100);
            ciz();
            name = b;
            is_opened = 0;
        }
        if (buton(x2 - 50, y1, x2 - 25, y1 + 25, "Tam Ekran", "", LIGHTGRAY, WHITE))
        {
            if (fullscr)
            {
                x1 = 50;
                y1 = 50;
                x2 = 350;
                y2 = 350;
                fullscr = 0;
                delay(100);
            }
            else
            {
                x1 = 1;
                y1 = 1;
                x2 = getmaxx() - 2;
                y2 = getmaxy() - 26;
                delay(100);
                fullscr = 1;
            }
        }
        if (buton(x2 - 75, y1, x2 - 50, y1 + 25, "Kucult", " -", LIGHTGRAY, WHITE))
        {
            is_hide = 1;
        }
        setcolor(BLACK);
        kutu(x2 - 42, y1 + 7, x2 - 32, y1 + 18);
        setcolor(onrenk);
        setbkcolor(arkarenk);
    }
    void yenile()
    {
        if (is_hide)
            return;
        ciz();
        if (is_open && !is_hide)
        {
            setcolor(onrenk);
            setbkcolor(arkarenk);
            int a = mousex(), b = mousey();
            int x = mousex(), y = mousey();
            while (basilimi(FARENINSOLU))
            {
                delay(1);
                if(a!=mousex() || b!=mousey()) fullscr=0;
                a = mousex(), b = mousey();
                x1 += (a - x);
                x2 += (a - x);
                y1 += (b - y);
                y2 += (b - y);
                cleardevice();
                ciz();
                x = mousex(), y = mousey();
            }
        }
        if (mousex() - 2 < x2 && mousex() + 2 > x1 && !is_hide && abs(mousey() - y2) < 5)
        {
            int x = mousex(), y = mousey();
            while (basilimi(FARENINSOLU))
            {
                delay(1);
                int a = mousex(), b = mousey();
                if (y1 < y2 + b - y - 25)
                    y2 += (b - y);
                cleardevice();
                ciz();
                x = mousex(), y = mousey();
            }
        }
        if (mousey() - 2 < y2 && mousey() + 2 > y1 && !is_hide && abs(mousex() - x2) < 5)
        {
            int x = mousex(), y = mousey();
            while (basilimi(FARENINSOLU))
            {
                delay(1);
                int a = mousex(), b = mousey();
                if (x1 < x2 + a - x - 100)
                    x2 += (a - x);
                cleardevice();
                ciz();
                x = mousex(), y = mousey();
            }
        }
        if (mousex() - 2 < x2 && mousex() + 2 > x1 && !is_hide && abs(mousey() - y1) < 5)
        {
            int x = mousex(), y = mousey();
            while (basilimi(FARENINSOLU))
            {
                delay(1);
                int a = mousex(), b = mousey();
                if (y2 > y1 + b - y + 25)
                    y1 += (b - y);
                cleardevice();
                ciz();
                x = mousex(), y = mousey();
            }
        }
        if (mousey() - 2 < y2 && mousey() + 2 > y1 && !is_hide && abs(mousex() - x1) < 5)
        {
            int x = mousex(), y = mousey();
            while (basilimi(FARENINSOLU))
            {
                delay(1);
                int a = mousex(), b = mousey();
                if (x1 + a - x + 100 < x2)
                    x1 += (a - x);
                cleardevice();
                ciz();
                x = mousex(), y = mousey();
            }
        }
        for (int i = 0; i < metinler.size(); i++)
        {
            metinler[i].yenile(x1, y1 + 25);
        }
        setcolor(onrenk);
        setbkcolor(arkarenk);
    }
    int butonEkle(int _x1, int _y1, int _x2, int _y2, char *a = "", char *name = "", colors c1 = LIGHTGRAY, colors c2 = DARKGRAY)
    {
        BUTON b;
        b.degerAta(_x1, _y1, _x2, _y2);
        b.a = a;
        b.c1 = c1;
        b.c2 = c2;
        b.name = name;
        butonlar.push_back(b);
        return butonlar.size() - 1;
    }
    void butonSil(int i)
    {
        butonlar[i].degerAta(1, 1, 0, 0);
        butonlar[i].name = "";
        butonlar[i].a = "";
    }
    bool butonaDokundumu(int i)
    {
        if (x1 + butonlar[i].x1 < mousex() && x1 + butonlar[i].x2 > mousex() && y1 + 25 + butonlar[i].y1 < mousey() && y1 + 25 + butonlar[i].y2 > mousey() && basilimi(FARENINSOLU))
        {
            return 1;
        }
        else
            return 0;
    }
    bool metineDokundumu(int i)
    {
        if (x1 + metinler[i].x2 - 50 < mousex() && x1 + metinler[i].x2 > mousex() && y1 + metinler[i].y2 < mousey() && y1 + 25 + metinler[i].y2 > mousey() && basilimi(FARENINSOLU))
        {
            delay(100);
            return 1;
        }
        else if (metinler[i].is_opened && basilimi(ALTSATIR))
        {
            delay(100);
            return 1;
        }
        else
            return 0;
    }
    int metinEkle(int a1, int b1, int a2, int b2)
    {
        METINKUTUSU b;
        b.degerAta(a1, b1, a2, b2);
        metinler.push_back(b);
        return metinler.size() - 1;
    }
    void metinSil(int i)
    {
        metinler[i].degerAta(0, 0, 0, 0);
        metinler[i].x = "";
        return;
    }
    int bildiriEkle(int a1, int b1, int a2, int b2, string x)
    {
        BILDIRIKUTUSU b;
        b.degerAta(a1, b1, a2, b1);
        b.x = x;
        bildiriler.push_back(b);
        return bildiriler.size() - 1;
    }
    void bildiriSil(int i)
    {
        bildiriler[i].degerAta(0, 0, 0, 0);
        bildiriler[i].x = "";
        return;
    }
    int cizgiEkle(int x1, int y1, int x2, int y2)
    {
        CIZGI b;
        b.x1 = x1;
        b.x2 = x2;
        b.y1 = y1;
        b.y2 = y2;
        cizgiler.push_back(b);
        return cizgiler.size() - 1;
    }
};
class firkOS
{
private:
public:
    string fileName;
    firkOS(string fn)
    {
        fileName = fn;
    }
    vector<AppPage> sayfalar;
    int sayfaEkle(int x1, int y1, int x2, int y2, string name)
    {
        AppPage b;
        b.x1 = x1;
        b.y1 = y1;
        b.x2 = x2;
        b.y2 = y2;
        b.name = name;
        sayfalar.push_back(b);
        return sayfalar.size() - 1;
    }
    void ciz()
    {
        int sayfaSayisi = 0;
        for (int i = 0; i < sayfalar.size(); i++)
            if (sayfalar[i].is_opened)
                sayfaSayisi++;
        if (sayfaSayisi)
        {
            setcolor(sayfalar[0].onrenk);
            setbkcolor(sayfalar[0].arkarenk);
            setfillstyle(1, DARKGRAY);
            bar(0, getmaxy() - 25, getmaxx(), getmaxy());
            if (buton(2, getmaxy() - 23, 23, getmaxy() - 2, "Terminal", "T"))
                terminal();
            for (int i = 0; i < sayfalar.size(); i++)
                sayfalar[i].ciz(i + 2);
        }
        else
        {
            terminal();
        }
    }
    void terminal()
    {
        AppPage term;
        term.x1 = 0;
        term.y1 = 0;
        term.x2 = getmaxx();
        term.y2 = getmaxy();
        term.metinEkle(25, 25, getmaxx() - 25, getmaxy() - 50);
        term.name = "Terminal";
        while (!term.metineDokundumu(0))
        {
            term.metinler[0].is_opened = 1;
            term.is_hide = 0;
            term.metinler[0].x1 = 25;
            term.metinler[0].y1 = 25;
            term.metinler[0].x2 = getmaxx() - 25;
            term.metinler[0].y2 = getmaxy() - 50;
            term.x1 = 0;
            term.y1 = 0;
            term.x2 = getmaxx();
            term.y2 = getmaxy();
            term.yenile();
            term.ciz(-1);
            delay(1);
            cleardevice();
        }
        string x = term.metinler[0].x;
        if (x == "exit")
            exit(1);
        if (x == "reboot")
            system(("start " + fileName).c_str()), exit(1);
        if (x == "list")
            for(int i=0;i<sayfalar.size();i++)
                metinxy(0,i*30,sayfalar[i].name),delay(1000);
        for (int i = 0; i < sayfalar.size(); i++)
            if (sayfalar[i].name == x)
                sayfalar[i].is_opened = 1;
    }
    void yenile()
    {
        if(basilimi(KONTROL) && basilimi(ALTGR) && basilimi('T')) terminal();
        for (int i = 0; i < sayfalar.size(); i++)
            sayfalar[i].yenile();
    }
};
#define isletimSistemi firkOS
#define APP int
void line3D(double ax1, double ay1, double az1, double ax2, double ay2, double az2,double cx,double cy,double cz,double ox,double oy,double oz)
{
    double dx1, dy1, dz1, dx2, dy2, dz2;
    double bx1, by1, bx2, by2;
    double x1, y1, z1, x2, y2, z2;
    double ex1, ey1, ez1, ex2, ey2, ez2;
    ex1 = ax1 - cx;
    ey1 = ay1 - cy;
    ez1 = az1 - cz;
    ex2 = ax2 - cx;
    ey2 = ay2 - cx;
    ez2 = az2 - cx;
    x1 = ax1 - cx;
    y1 = ay1 - cy;
    z1 = az1 - cz;
    x2 = ax2 - cx;
    y2 = ay2 - cy;
    z2 = az2 - cz;
    dx1 = cos(oy) * (sin(oz) * y1 + cos(oz) * x1) - sin(oy) * z1;
    dy1 = sin(ox) * (cos(oy) * z1 + sin(oy) * (sin(oz) * y1 + cos(oz) * x1)) + cos(ox) * (cos(oz) * y1 - sin(oz) * x1);
    dz1 = cos(ox) * (cos(oy) * z1 + sin(oy) * (sin(oz) * y1 + cos(oz) * x1)) - sin(ox) * (cos(oz) * y1 - sin(oz) * x1);
    dx2 = cos(oy) * (sin(oz) * y2 + cos(oz) * x2) - sin(oy) * z2;
    dy2 = sin(ox) * (cos(oy) * z2 + sin(oy) * (sin(oz) * y2 + cos(oz) * x2)) + cos(ox) * (cos(oz) * y2 - sin(oz) * x2);
    dz2 = cos(ox) * (cos(oy) * z2 + sin(oy) * (sin(oz) * y2 + cos(oz) * x2)) - sin(ox) * (cos(oz) * y2 - sin(oz) * x2);
    dz1 = dz1 - cz;
    dz2 = dz2 - cz;
    if (!(0 >= dz1 || 0 >= dz2))
    {
        bx1 = dx1 / dz1;
        by1 = dy1 / dz1;
        bx2 = dx2 / dz2;
        by2 = dy2 / dz2;
    }
    else if (0 < dz1)
    {
        bx1 = dx1 / dz1;
        by1 = dy1 / dz1;
        bx2 = dx2;
        by2 = dy2;
    }
    else if (0 < dz2)
    {
        bx1 = dx1;
        by1 = dy1;
        bx2 = dx2 / dz2;
        by2 = dy2 / dz2;
    }
    line(180 * bx1 + getmaxx() / 2, 180 * by1 + getmaxy() / 2, 180 * bx2 + getmaxx() / 2, 180 * by2 + getmaxy() / 2);
    return;
}
/*
void line3D(double x1,double y1,double z1,double x2,double y2,double z2,double cx,double cy,double cz){
    double z;
    if(min(z1,z2)==z2){
        z=z2;
        z2=z1;
        z1=z;
    }
    if(z1==cz || z2==cz) z1--;
    if(cz<z1){
        line(((getmaxx()+getmaxy())/3)*(x1-cx)/(z1-cz)+getmaxx()/2,((getmaxx()+getmaxy())/3)*(y1-cy)/(z1-cz)+getmaxy()/2,((getmaxx()+getmaxy())/3)*(x2-cx)/(z2-cz)+getmaxx()/2,((getmaxx()+getmaxy())/3)*(y2-cy)/(z2-cz)+getmaxy()/2);
    }
    else if(z2>cz){
        line(((getmaxx()+getmaxy())/3)*(x1-cx)+getmaxx()/2,((getmaxx()+getmaxy())/3)*(y1-cy)+getmaxy()/2,((getmaxx()+getmaxy())/3)*(x2-cx)/(z2-cz)+getmaxx()/2,((getmaxx()+getmaxy())/3)*(y2-cy)/(z2-cz)+getmaxy()/2);
    }
}
*/
COORD boyutlarArasi(int x,int y,int z,int cx,int cy,int cz){
    COORD ans;
    ans.X=-5;
    ans.Y=-5;
    if(z<=cz) return ans;
    int a=50*(x-cx)/(z-cz)+getmaxx()/2,b=50*(y-cy)/(z-cz)+getmaxy()/2;
    ans.X=a;
    ans.Y=b;
    return ans;
}
void hizlandir(){
    static int a=0;
    setactivepage(a);
    a=1-a;
    setvisualpage(a);
    return;
}
int pencereOlustur(int x=500,int y=500,string title="",int SOL=0,int UST=0){
    ShowWindow(GetConsoleWindow(),SW_HIDE);
    int rv=initwindow(x,y,title.c_str(),SOL-5,UST-3);
    setfillstyle(SOLID_FILL,BLACK);
    setcolor(BLACK);
    setbkcolor(WHITE);
    cleardevice();
    hizlandir();
    setfillstyle(SOLID_FILL,BLACK);
    setcolor(BLACK);
    setbkcolor(WHITE);
    cleardevice();
    hizlandir();
    setfillstyle(SOLID_FILL,BLACK);
    setcolor(BLACK);
    setbkcolor(WHITE);
    cleardevice();
    return rv;
}
string fileOpen() {
    HWND hwnd=GetActiveWindow();
    OPENFILENAME ofn;
    char szFileName[MAX_PATH];
    ZeroMemory(&ofn, sizeof(ofn));
    szFileName[0] = 0;
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = LPCSTR("Foto Images (*.bmp)\0*.*\0\0");
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_OVERWRITEPROMPT;
    ofn.lpstrDefExt = LPCSTR("bmp");
    GetOpenFileName(&ofn);
    return szFileName;
}
