#include <iostream>
#include <windows.h>
#include "Conf.h"
#include <cstdio>
#include <cstdlib>
using namespace std;

//-----------------------------------------------CONSTRUCTOR
Conf::Conf()
{
    PantallaCompleta=false;
    GuardadoAutomatico=false;
    x=35;
    x2=33;
    x3=35;
}

//-----------------------------------------------PANTALLA COMPLETA
void Conf::Fullscreen(){
    COORD c;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    typedef BOOL (WINAPI *SetConsoleDisplayModeProc)( HANDLE hConsoleOutput, DWORD dwFlags, PCOORD lpNewScreenBufferDimensions );
    SetConsoleDisplayModeProc SetConsoleDisplayMode = (SetConsoleDisplayModeProc)::GetProcAddress(GetModuleHandle(("kernel32.dll")), "SetConsoleDisplayMode");
    if (PantallaCompleta){
    SetConsoleDisplayMode(hCon, 1, &c);
    } else {
        SetConsoleDisplayMode(hCon, 0, &c);
    }
}

//-----------------------------------------------LEER DE DISCO
bool Conf::LeerDeDisco(int pos){
    FILE *C;
    C = fopen("data/Conf.dat","rb");
    if (C==NULL) return false;
    fseek(C, sizeof *this*pos,0);
    bool leyo= fread(this, sizeof *this,1,C);
    fclose(C);
    return leyo;
}

//-----------------------------------------------MODIFICAR EN DISCO
void Conf::Modificar(int pos){
    FILE *C;
    C = fopen("data/Conf.dat","rb+");
    if (C==NULL) exit(1);
    fseek(C,sizeof *this*pos,0);
    fwrite(this, sizeof *this,1,C);
    fclose(C);
}

//-----------------------------------------------GRABAR EN DISCO
void Conf::Grabar(){
    FILE *C;
    C = fopen("data/Conf.dat","ab");
    if (C==NULL) return;
    fwrite(this, sizeof *this,1,C);
    fclose(C);
}

//-----------------------------------------------DESTRUCTOR
Conf::~Conf()
{
    //dtor
}
