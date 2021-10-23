#ifndef FECHA_H
#define FECHA_H


class Fecha
{
   int dia,mes,anio;
   long x;
public:
    Fecha(){
        x=0;
    };
    /** gets */
    int getdia(){return dia;}
    int getmes(){return mes;}
    int getanio(){return anio;}
    long getx() {return x;}
    /** sets */
    void setdia(int d){dia = d;}
    void setmes(int m) {mes = m;}
    void setanio(int a){anio = a;}
    void setx (long newx) {x= newx;}
};

#endif // FECHA_H
