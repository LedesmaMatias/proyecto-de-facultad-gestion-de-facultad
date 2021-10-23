#ifndef CONF_H
#define CONF_H


class Conf {
private:
    bool PantallaCompleta;
    bool GuardadoAutomatico;
    int x,x2,x3;
public:
    Conf();
    bool LeerDeDisco(int );
    void Modificar (int );
    void Grabar();
    void Fullscreen();
    void Fullscreenoff();
    /*sets*/
    void setx (int newx) {x= newx;}
    void setx2 (int newx2) {x2= newx2;}
    void setguardado (bool newguardado) {GuardadoAutomatico=newguardado;}
    void setscreen (bool newscreen) {PantallaCompleta=newscreen;}
    /*gets*/
    int getx3 () {return x3;}
    int getx2 () {return x2;}
    int getx () {return x;}
    bool getguardadoautomatico () {return GuardadoAutomatico;}
    bool getfullscreen () {return PantallaCompleta;}
    virtual ~Conf();
};

#endif // CONF_H
