#include <iostream>
#include <Menu.h>
#include <Conf.h>
using namespace std;

int main() {
    Conf c;
    if (c.LeerDeDisco(0)==false){
        c.Grabar();
    }
    if (c.getfullscreen()){ c.Fullscreen();
        c.setx(60);
        c.setx2(58);
        c.Modificar(0);
    } else {
    c.setx(35);
    c.setx2(33);
    c.Modificar(0);
    }
    MPrincipal mp;
    mp.AbrirMenuPrincipal();
    return 0;
}
