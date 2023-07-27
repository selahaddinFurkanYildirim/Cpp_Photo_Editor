#include <code-graph.hpp>
HWND myWindow;
int mesajKutusu(string baslik,string uyari){
    return MessageBoxA(GetConsoleWindow(),(LPCSTR)(uyari.c_str()),(LPCSTR)(baslik.c_str()),MB_YESNO);
}
string convertBMP(string x){
    string filenamex=x;
    if(1)
    {
        ofstream bat("C:\\ProgramData\\a.bat");
        bat <<"\"C:\\Program Files (x86)\\Easy2Convert Software\\PNG to BMP\\png2bmp.exe\" -i \""
            <<x
            <<"\" -o \"C:\\ProgramData\"";
        bat.close();
    }
    ifstream bat("C:\\ProgramData\\a.bat");
    getline(bat,x);
    bat.close();
    system((string("cmd /c \"")+x+string("\"")).c_str());
    int inde=0;
    for(int i=0;i<filenamex.size();i++){
        if(filenamex[i]=='\\') inde=i;
    }
    string b="C:\\ProgramData";
    for(int i=inde;i<filenamex.size();i++) b.push_back(filenamex[i]);
    b[b.size()-1]='p';
    b[b.size()-2]='m';
    b[b.size()-3]='b';
    return b;
}

int main(){
    int pencerem=0;
    int isThisFirst=1;
    pencereOlustur(250,100,"",getmaxwidth()/2-125,getmaxheight()/2-50);
    system("curl -L \"https://www.dropbox.com/s/4mjuvopnib4bvx1/ara.bmp?dl=0\" --output C:/ProgramData/search.bmp &");
    bar(0,0,80,100);
    swapbuffers();
    system("curl -L \"https://www.dropbox.com/s/zoijy1xgoeioe07/kaydet.bmp?dl=0\" --output C:/ProgramData/save.bmp &");
    bar(0,0,170,100);
    swapbuffers();
    system("curl -L \"https://www.dropbox.com/s/l5bqs7pr5k9afiu/kapat.bmp?dl=0\" --output C:/ProgramData/cross.bmp &");
    bar(0,0,250,100);
    swapbuffers();
    Sleep(1000);
    closegraph();
    if(basilimi('F'))
        pencerem=pencereOlustur(getmaxwidth()+10,getmaxheight()+30);
    else
        pencerem=pencereOlustur(getmaxwidth()/2+5, getmaxheight()/2+15,"",getmaxwidth()/4, getmaxheight()/4);
    myWindow=GetForegroundWindow();
    delay(100);
    Sleep(100);
    int oldx=mousex(), oldy=mousey(), x = mousex(), y = mousey();
    vector<int > cizgilerx1;
    vector<int > cizgilery1;
    vector<int > cizgilerx2;
    vector<int > cizgilery2;
    vector<int > cizgilerrenk;
    vector<int > cizgilerx1s;
    vector<int > cizgilery1s;
    vector<int > cizgilerx2s;
    vector<int > cizgilery2s;
    vector<int > cizgilerrenks;
    vector<int > resimlerx1;
    vector<int > resimlery1;
    vector<int > resimlerx2;
    vector<int > resimlery2;
    vector<string> resimler;
    vector<int > fillx;
    vector<int > filly;
    vector<int > fillc;
    vector<int > karex1;
    vector<int > karey1;
    vector<int > karex2;
    vector<int > karey2;
    vector<int > karerenk;
    map<pair<int,int>,int > m;
    map<pair<int,int>,int > ms;
    map<pair<int,int>,int > mfill;
    int renk=0;
    function<void(int,int,int,int,int)> ekle=[&](int x1,int y1,int x2,int y2,int col){
        line(x1,y1,x2,y2);
        if(x1!=-1 || x2!=-1 || y1!=-1 || y2!=-1){
            if(m[make_pair(x1,y1)] && m[make_pair(x2,y2)]) return;
            cizgilerrenks.clear();
            cizgilerx1s.clear();
            cizgilerx2s.clear();
            cizgilery1s.clear();
            cizgilery2s.clear();
        }
        cizgilerx1.push_back(x1);
        cizgilery1.push_back(y1);
        cizgilerx2.push_back(x2);
        cizgilery2.push_back(y2);
        cizgilerrenk.push_back(col);
        m[make_pair(x1,y1)]=cizgilerx1.size()-1;
        m[make_pair(x2,y2)]=cizgilerx1.size()-1;
        return;
    };
    function<void()> ekranyenile=[&](){
        delay(1);
        setlinestyle(SOLID_LINE,1,3);
        swapbuffers();
        cleardevice();
        setlinestyle(DOTTED_LINE,1,1);
        int maxx=getmaxx();
        int maxy=getmaxx();
        setfillstyle(HATCH_FILL,BLACK);
        // floodfill(500,500,0);
        setlinestyle(SOLID_LINE,1,3);
        setcolor(BLACK);
        setfillstyle(SOLID_FILL,BLACK);
        for(int i=0;i<resimler.size();i++){
            if(resimler[i]=="NULL") continue;
            bar(resimlerx1[i],resimlery1[i]-25,resimlerx2[i],resimlery1[i]);
            readimagefile("C:/ProgramData/cross.bmp",resimlerx2[i]-25,resimlery1[i]-25,resimlerx2[i],resimlery1[i]);
            readimagefile("C:/ProgramData/save.bmp",resimlerx2[i]-60,resimlery1[i]-25,resimlerx2[i]-35,resimlery1[i]);
            readimagefile("C:/ProgramData/search.bmp",resimlerx1[i],resimlery1[i]-25,resimlerx1[i]+35,resimlery1[i]);
            readimagefile(resimler[i].c_str(),resimlerx1[i]+1,resimlery1[i]+1,resimlerx2[i]-1,resimlery2[i]-1);
            rectangle(resimlerx1[i],resimlery1[i]-25,resimlerx2[i],resimlery2[i]);
            line(resimlerx1[i],resimlery1[i],resimlerx2[i],resimlery1[i]);
        }
        setcolor(renk);
        setfillstyle(SOLID_FILL,renk);
        for(int i=0;i<cizgilerx1.size();i++){
            setcolor(cizgilerrenk[i]);
            line(cizgilerx1[i],cizgilery1[i],cizgilerx2[i],cizgilery2[i]);
        }
        for(int i=0;i<karex1.size();i++){
            setcolor(karerenk[i]);
            rectangle(karex1[i],karey1[i],karex2[i],karey2[i]);
        }
        setcolor(renk);
        for(int i=0;i<fillx.size();i++){
            if(mfill[make_pair(fillx[i],filly[i])]==-1) continue;
            setfillstyle(SOLID_FILL,fillc[i]);
            floodfill(fillx[i],filly[i],fillc[i]);
            setfillstyle(SOLID_FILL,WHITE);
            fillellipse(fillx[i],filly[i],5,5);
            setfillstyle(SOLID_FILL,BLACK);
        }
        readimagefile("C:/ProgramData/search.bmp",0,0,60,60);
        readimagefile("C:/ProgramData/cross.bmp",getmaxx()-45,-1,getmaxx(),40);
        readimagefile("C:/ProgramData/save.bmp",getmaxx()-90,-1,getmaxx()-45,40);
        return;
    };
    function<void()> yenile=[&](){
        delay(1);
        if(basilimi(KONTROL) && basilimi('Z')){
            setcolor(WHITE);
            int oldrenk;
            while(basilimi(KONTROL) && basilimi('Z') && cizgilerrenk.size()){
                int i=cizgilerrenk.size()-1;
                for(int i=0;i<resimler.size()*3+1 && cizgilerrenk.size();i++){
                    m[make_pair(cizgilerx1[i],cizgilery1[i])]=0;
                    m[make_pair(cizgilerx2[i],cizgilery2[i])]=0;
                    oldrenk=cizgilerrenk[cizgilerrenk.size()-1];
                    cizgilerrenks.push_back(cizgilerrenk[cizgilerrenk.size()-1]);
                    cizgilerx1s.push_back(cizgilerx1[cizgilerx1.size()-1]);
                    cizgilerx2s.push_back(cizgilerx2[cizgilerx2.size()-1]);
                    cizgilery1s.push_back(cizgilery1[cizgilery1.size()-1]);
                    cizgilery2s.push_back(cizgilery2[cizgilery2.size()-1]);
                    cizgilerrenk.pop_back();
                    cizgilerx1.pop_back();
                    cizgilerx2.pop_back();
                    cizgilery1.pop_back();
                    cizgilery2.pop_back();
                }
                ekranyenile();
            }
            setcolor(renk);
            ekranyenile();
        }
        if(basilimi(KONTROL) && basilimi('Y')){
            setcolor(WHITE);
            while(basilimi(KONTROL) && basilimi('Y') && cizgilerrenks.size()){
                int i=cizgilerrenk.size()-1;
                for(int i=0;i<resimler.size()*2+1 && cizgilerrenks.size();i++){
                    m[make_pair(cizgilerx1s[i],cizgilery1s[i])]=1;
                    m[make_pair(cizgilerx2s[i],cizgilery2s[i])]=1;
                    cizgilerrenk.push_back(cizgilerrenks[cizgilerrenks.size()-1]);
                    cizgilerx1.push_back(cizgilerx1s[cizgilerx1s.size()-1]);
                    cizgilerx2.push_back(cizgilerx2s[cizgilerx2s.size()-1]);
                    cizgilery1.push_back(cizgilery1s[cizgilery1s.size()-1]);
                    cizgilery2.push_back(cizgilery2s[cizgilery2s.size()-1]);
                    cizgilerrenks.pop_back();
                    cizgilerx1s.pop_back();
                    cizgilerx2s.pop_back();
                    cizgilery1s.pop_back();
                    cizgilery2s.pop_back();
                }
                ekranyenile();
            }
            if(cizgilerrenk.size() && cizgilerx1[cizgilerx1.size()-1]!=-1 ){
                cizgilerrenk.push_back(cizgilerrenk[cizgilerx1.size()-1]);
            }
            setcolor(renk);
            ekranyenile();
        }
        if(mousex()<getmaxx() && mousex()>getmaxx()-45 && mousey()<40 && mousey()>0 && !basilimi(FARENINSOLU)){
            while((!basilimi(FARENINSOLU)) && mousex()<getmaxx() && mousex()>getmaxx()-45 && mousey()<40 && mousey()>0){
                delay(10);
                Sleep(10);
            }
            if(mousex()<getmaxx() && mousex()>getmaxx()-45 && mousey()<40 && mousey()>0 && basilimi(FARENINSOLU)){
                if(myWindow==GetForegroundWindow())
                exit(0);
            }
        }
        setlinestyle(SOLID_LINE,1,3);
        for(int i=0;i<resimler.size();i++){
            if(resimler[i]=="NULL") continue;
            if(mousex()<resimlerx2[i]+5 && mousex()>resimlerx2[i]-30 && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                if(!basilimi(FARENINSOLU)){
                    while((!basilimi(FARENINSOLU)) && mousex()<resimlerx2[i]+5 && mousex()>resimlerx2[i]-30 && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                        delay(10);
                        Sleep(10);
                    }
                    if(mousex()<resimlerx2[i]+5 && mousex()>resimlerx2[i]-30 && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                        resimler[i]="NULL";
                        ekranyenile();
                        ekranyenile();
                        while(basilimi(FARENINSOLU)) Sleep(10),delay(10);
                    }
                }
            }
            if(mousex()<resimlerx2[i]-30 && mousex()>resimlerx2[i]-65 && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                if(!basilimi(FARENINSOLU)){
                    while((!basilimi(FARENINSOLU)) && mousex()<resimlerx2[i]-30 && mousex()>resimlerx2[i]-65 && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                        delay(10);
                        Sleep(10);
                    }
                    if(mousex()<resimlerx2[i]-30 && mousex()>resimlerx2[i]-65 && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                        OPENFILENAME ofn;
                        char szFileName[MAX_PATH] = "";
                        ZeroMemory(&ofn, sizeof(ofn));
                        ofn.lStructSize = sizeof(ofn); 
                        ofn.hwndOwner = NULL;
                        ofn.lpstrFilter = (LPCSTR)"BMP File (*.bmp)\0*.bmp\0";
                        ofn.lpstrFile = (LPSTR)szFileName;
                        ofn.nMaxFile = MAX_PATH;
                        ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
                        ofn.lpstrDefExt = (LPCSTR)"BMP";
                        GetSaveFileName(&ofn);
                        writeimagefile((char*)ofn.lpstrFile,resimlerx1[i]+3,resimlery1[i],resimlerx2[i]-3,resimlery2[i]-3);
                    }
                }
            }
            if(mousex()<resimlerx1[i]+35 && mousex()>resimlerx1[i] && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                if(!basilimi(FARENINSOLU)){
                    while((!basilimi(FARENINSOLU)) && mousex()<resimlerx1[i]+35 && mousex()>resimlerx1[i] && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                        delay(10);
                        Sleep(10);
                    }
                    if(mousex()<resimlerx1[i]+35 && mousex()>resimlerx1[i] && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                        string filenamex=fileOpen();
                        if(filenamex[filenamex.size()-1]=='g' && filenamex[filenamex.size()-2]=='n' && filenamex[filenamex.size()-3]=='p'){
                            resimler[i]=(convertBMP(filenamex));
                        }
                        else{
                            resimler[i]=(filenamex);
                        }
                        ekranyenile();
                        ekranyenile();
                    }
                }
            }
            if(mousex()<resimlerx2[i]-30 && mousex()>resimlerx1[i]-5 && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                if(!basilimi(FARENINSOLU)){
                    while((!basilimi(FARENINSOLU)) && mousex()<resimlerx2[i]-30 && mousex()>resimlerx1[i]-5 && mousey()<resimlery1[i]+5 && mousey()>resimlery1[i]-30){
                        delay(10);
                        Sleep(10);
                    }
                    int oldxfark=mousex(),oldyfark=mousey(),xfark=mousex(),yfark=mousey();
                    while (basilimi(FARENINSOLU)){
                        resimlerx1[i]+=xfark-oldxfark;
                        resimlerx2[i]+=xfark-oldxfark;
                        resimlery1[i]+=yfark-oldyfark;
                        resimlery2[i]+=yfark-oldyfark;
                        oldxfark=xfark;
                        oldyfark=yfark;
                        xfark=mousex();
                        yfark=mousey();
                        ekranyenile();
                        ekranyenile();
                    }
                }
            }
            if(mousex()<resimlerx2[i]+5 && mousex()>resimlerx2[i]-15 && mousey()<resimlery2[i]+5 && mousey()>resimlery2[i]-15){
                if(!basilimi(FARENINSOLU)){
                    while((!basilimi(FARENINSOLU)) && mousex()>resimlerx2[i]-15 && mousey()<resimlery2[i]+5 && mousey()>resimlery2[i]-15){
                        delay(10);
                        Sleep(10);
                    }
                    int farex=mousex(),farey=mousey();
                    while (basilimi(FARENINSOLU)){
                        if(farex>resimlerx1[i]+100){
                            resimlerx2[i]=farex;
                        }
                        else{
                            resimlerx2[i]=resimlerx1[i]+100;
                        }
                        if(farey>resimlery1[i]+100){
                            resimlery2[i]=farey;
                        }
                        else{
                            resimlery2[i]=resimlery1[i]+100;
                        }
                        farex=mousex();
                        farey=mousey();
                        ekranyenile();
                        ekranyenile();
                    }
                }
            }
        }
        return;
    };
    int farebasilimi=0,farklilik=1,firstx=0,firsty=0;
    while (1){
        for(int i=0;i<10;i++){
            basilimi(ALTGR);
            basilimi('C');
        }
        if(basilimi(ALTGR) && basilimi('C')){
            myWindow=GetForegroundWindow();
        }
        if(myWindow!=GetForegroundWindow()){
            continue;
        }
        setcolor(renk);
        if(basilimi(VK_NUMPAD0)){
            renk=0;
        }
        if(basilimi(VK_NUMPAD1)){
            renk=1;
        }
        if(basilimi(VK_NUMPAD2)){
            renk=2;
        }
        if(basilimi(VK_NUMPAD3)){
            renk=3;
        }
        if(basilimi(VK_NUMPAD4)){
            renk=4;
        }
        if(basilimi(VK_NUMPAD5)){
            renk=5;
        }
        if(basilimi(VK_NUMPAD6)){
            renk=6;
        }
        if(basilimi(VK_NUMPAD7)){
            renk=7;
        }
        if(basilimi(VK_NUMPAD8)){
            renk=8;
        }
        if(basilimi(VK_NUMPAD9)){
            renk=9;
        }
        yenile();
        if(farklilik){
            farklilik=0;
            ekranyenile();
            ekranyenile();
        }
        if(basilimi('C')){
            cout<<endl<<endl<<cizgilerx1.size()<<" "<<x<<" "<<y<<endl;
            for(int i=0;i<cizgilerx1.size();i++){
                cout<<cizgilerx1[i]<<" "<<cizgilerx1[i]<<" "<<cizgilerx1[i]<<" "<<cizgilery2[i]<<endl;
            }
        }
        while(basilimi('R')){
            delay(1);
            x=mousex();
            y=mousey();
            oldx=x;
            oldy=y;
            while (basilimi(FARENINSOLU)){
                rectangle(min(oldx,x),min(oldy,y),max(oldx,x),max(oldy,y));
                ekranyenile();
                delay(1);
                x=mousex();
                y=mousey();
            }
            rectangle(min(oldx,x),min(oldy,y),max(oldx,x),max(oldy,y));
            karex1.push_back(min(oldx,x));
            karex2.push_back(max(oldx,x));
            karey1.push_back(min(oldy,y));
            karey2.push_back(max(oldy,y));
            karerenk.push_back(renk);
            ekranyenile();
            ekranyenile();
        }
        if(basilimi('E')){
            m.clear();
            mfill.clear();
            cizgilerrenks.clear();
            cizgilerx1s.clear();
            cizgilerx2s.clear();
            cizgilery1s.clear();
            cizgilery2s.clear();
            fillc.clear();
            filly.clear();
            fillx.clear();
            cizgilerx1.clear();
            cizgilery1.clear();
            cizgilerx2.clear();
            cizgilery2.clear();
            cizgilerrenk.clear();
            karex1.clear();
            karey1.clear();
            karex2.clear();
            karey2.clear();
            karerenk.clear();
            ekranyenile();
            ekranyenile();
            ekranyenile();
        }
        if(basilimi('F')){
            if(getmaxx()==getmaxwidth()+9){
                closegraph(pencerem);
                pencerem=pencereOlustur(getmaxwidth()/2+5, getmaxheight()/2+15,"",getmaxwidth()/4, getmaxheight()/4);
                ekranyenile();
                ekranyenile();
                myWindow=GetForegroundWindow();
            }
            else{
                closegraph(pencerem);
                pencerem=pencereOlustur(getmaxwidth()+10, getmaxheight()+30);
                ekranyenile();
                ekranyenile();
                myWindow=GetForegroundWindow();
            }
            SetActiveWindow(GetActiveWindow());
            while (basilimi('F')){
                delay(100);
                Sleep(100);
            }
        }
        if(basilimi(VK_MBUTTON)){
            oldx=x;
            oldy=y;
            x=mousex();
            y=mousey();
            if(mfill[make_pair(x,y)]==0){
                fillx.push_back(x);
                filly.push_back(y);
                fillc.push_back(renk);
                mfill[make_pair(x,y)]=fillx.size();
                ekranyenile();
                ekranyenile();
            }
        }
        if(basilimi(FARENINSOLU)){
            if(farebasilimi==0){
                firstx=mousex();
                firsty=mousey();
                delay(10);
                if(x<getmaxx()-45 && x>getmaxx()-90 && y<40 && y>0){
                    while(basilimi(FARENINSOLU)) Sleep(10),delay(10);
                    while(!basilimi(FARENINSOLU)) Sleep(10),delay(10);
                    if(myWindow==GetForegroundWindow()){
                        x=mousex();
                        y=mousey();
                        oldx=x;
                        oldy=y;
                        while (basilimi(FARENINSOLU)){
                            setfillstyle(XHATCH_FILL,renk);
                            bar(0,0,getmaxx(),min(oldy,y));
                            bar(0,max(oldy,y),getmaxx(),getmaxy());
                            bar(0,0,min(oldx,x),getmaxy());
                            bar(max(oldx,x),0,getmaxx(),getmaxy());
                            rectangle(min(oldx,x),min(oldy,y),max(oldx,x),max(oldy,y));
                            setfillstyle(SOLID_FILL,renk);
                            ekranyenile();
                            x=mousex();
                            y=mousey();
                        }
                        OPENFILENAME ofn;
                        char szFileName[MAX_PATH] = "";
                        ZeroMemory(&ofn, sizeof(ofn));
                        ofn.lStructSize = sizeof(ofn); 
                        ofn.hwndOwner = NULL;
                        ofn.lpstrFilter = (LPCSTR)"BMP File (*.bmp)\0*.bmp\0";
                        ofn.lpstrFile = (LPSTR)szFileName;
                        ofn.nMaxFile = MAX_PATH;
                        ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
                        ofn.lpstrDefExt = (LPCSTR)"BMP";
                        GetSaveFileName(&ofn);
                        writeimagefile((char*)ofn.lpstrFile,min(oldx,x),min(oldy,y),max(oldx,x),max(oldy,y));
                        ekranyenile();
                        ekranyenile();
                        ekranyenile();
                    }
                }
                if(x<65 && y<50){
                    while(basilimi(FARENINSOLU)) Sleep(10),delay(10);
                    while(!basilimi(FARENINSOLU)) Sleep(10),delay(10);
                    delay(10);
                    if(myWindow==GetForegroundWindow()){
                        int x1=mousex(),y1=mousey();
                        while(basilimi(FARENINSOLU)){
                            setfillstyle(XHATCH_FILL,renk);
                            bar(x1,y1,mousex(),mousey());
                            rectangle(x1,y1,mousex(),mousey());
                            setfillstyle(SOLID_FILL,renk);
                            ekranyenile();
                        }
                        ekranyenile();
                        ekranyenile();
                        oldx=x1;
                        oldy=y1;
                        x=mousex();
                        y=mousey();
                        string filenamex=fileOpen();
                        if(filenamex==""){
                            continue;
                        }
                        resimlerx1.push_back(min(oldx,x));
                        resimlery1.push_back(min(oldy,y));
                        resimlerx2.push_back(max(min(oldx,x)+100,max(x,oldx)));
                        resimlery2.push_back(max(min(oldy,y)+100,max(y,oldy)));
                        if(filenamex[filenamex.size()-1]=='g' && filenamex[filenamex.size()-2]=='n' && filenamex[filenamex.size()-3]=='p'){
                            resimler.push_back(convertBMP(filenamex));
                        }
                        else{
                            resimler.push_back(filenamex);
                        }
                        farklilik=1;
                        while(basilimi(FARENINSOLU)) Sleep(10),delay(10);
                        delay(100);
                    }
                }
                else{
                    ekle(-1,-1,-1,-1,-1);
                    farebasilimi=1;
                    oldx=x;
                    oldy=y;
                    x=mousex();
                    y=mousey();
                }
                Sleep(10);
            }
        }
        oldx=x;
        oldy=y;
        x=mousex();
        y=mousey();
        while (farebasilimi){
            delay(10);
            ekle(x,y,oldx,oldy,renk);
            line(x,y,oldx,oldy);
            oldx = x;
            oldy = y;
            x = mousex();
            y = mousey();
            setvisualpage(getactivepage());
            if(!basilimi(FARENINSOLU)){
                ekle(-1,-1,-1,-1,-1);
                if(firstx==x && firsty==y){
                    ekle(x+1,y-1,x+1,y+1,renk);
                    ekle(x,y-1,x,y+1,renk);
                    ekle(x-1,y-1,x-1,y+1,renk);
                    ekle(-1,-1,-1,-1,-1);
                    ekranyenile();
                    ekranyenile();
                }
                farebasilimi=0;
            }
        }
        while (basilimi(FARENINSAGI)){
            farklilik=1;
            setvisualpage(getactivepage());
            int is=0,n;
            for(int i=-10;i<=10;i++){
                for(int j=-10;j<=10;j++){
                    if(m[make_pair(i+x,j+y)]){
                        is=1;
                        n=m[make_pair(i+x,j+y)];
                        i=10;
                    }
                }
            }
            setcolor(WHITE);
            if(is){
                farklilik=1;
                for(int i=n;i<cizgilerx1.size() && (cizgilerx1[i]!=-1 ||cizgilery1[i]!=-1 || cizgilerx2[i]!=-1 || cizgilery2[i]!=-1);i++){
                    m.erase(make_pair(cizgilerx1[i],cizgilery1[i]));
                    m.erase(make_pair(cizgilerx2[i],cizgilery2[i]));
                    line(cizgilerx1[i],cizgilery1[i],cizgilerx2[i],cizgilery2[i]);
                    cizgilerx1[i]=-1;
                    cizgilery1[i]=-1;
                    cizgilerx2[i]=-1;
                    cizgilery2[i]=-1;
                }
                for(int i=n-1;(cizgilerx1[i]!=-1 ||cizgilery1[i]!=-1 || cizgilerx2[i]!=-1 || cizgilery2[i]!=-1) && i>0;i--){
                    m.erase(make_pair(cizgilerx1[i],cizgilery1[i]));
                    m.erase(make_pair(cizgilerx2[i],cizgilery2[i]));
                    line(cizgilerx1[i],cizgilery1[i],cizgilerx2[i],cizgilery2[i]);
                    cizgilerx1[i]=-1;
                    cizgilery1[i]=-1;
                    cizgilerx2[i]=-1;
                    cizgilery2[i]=-1;
                }
            }
            for(int i=0;i<karerenk.size();i++){
                if(karex1[i]<=x && karex2[i]>=x){
                    if(abs(karey1[i]-y)<5){
                        rectangle(karex1[i],karey1[i],karex2[i],karey2[i]);
                        karex1[i]=-1;
                        karex2[i]=-1;
                        karey2[i]=-1;
                        karey1[i]=-1;
                    }
                    if(abs(karey2[i]-y)<5){
                        rectangle(karex1[i],karey1[i],karex2[i],karey2[i]);
                        karex1[i]=-1;
                        karex2[i]=-1;
                        karey2[i]=-1;
                        karey1[i]=-1;
                    }
                }
                if(karey1[i]<=y && karey2[i]>=y){
                    if(abs(karex1[i]-x)<5){
                        rectangle(karex1[i],karey1[i],karex2[i],karey2[i]);
                        karex1[i]=-1;
                        karex2[i]=-1;
                        karey2[i]=-1;
                        karey1[i]=-1;
                    }
                    if(abs(karex2[i]-x)<5){
                        rectangle(karex1[i],karey1[i],karex2[i],karey2[i]);
                        karex1[i]=-1;
                        karex2[i]=-1;
                        karey2[i]=-1;
                        karey1[i]=-1;
                    }
                }
            }
            setcolor(renk);
            for(int i=-15;i<=15;i++){
                for(int j=-15;j<=15;j++){
                    if(mfill[make_pair(i+x,j+y)] && mfill[make_pair(i+x,y+j)]+1){
                        mfill[make_pair(i+x,j+y)]=-1;
                        ekranyenile();
                        ekranyenile();
                        i=10;
                    }
                }
            }
            oldx = x;
            oldy = y;
            x = mousex();
            y = mousey();
            delay(10);
        }
        delay(10);
        oldx = x;
        oldy = y;
        x = mousex();
        y = mousey();
    }
    getch();
    return 0;
}