// queue::push/pop

#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Contacto.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe los datos del objeto contacto (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios contactos en un solo archivo
void escribir(string nombre_archivo, Contacto*contacto, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    out.seekp(24*posicion);
    out.write(contacto->nombre.c_str(),10);
    out.write(contacto->correo.c_str(),10);
    out.write((char*)&contacto->numero,4);
    out.close();

}

//Devuelve un contacto previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios contactos de un solo archivo
Contacto* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    char nombre[10];
    char correo[10];
    int numero;

    in.seekg(24*posicion);

    in.read(nombre,10);
    in.read(correo,10);
    in.read((char*)&numero,4);

    in.close();

    Contacto *c = new Contacto(nombre, correo, numero);

    return c;
}

//Devuelve un vector que contenga todos los nombres de los contactos previamente ingresados en el archivo con nombre dado
vector<string> getNombres(string nombre_archivo)
{
    int t;
    ifstream in(nombre_archivo.c_str());
    char nombre[10];
    in.seekg(0,ios::end);
    t=in.tellg()/24;
    in.seekg(0,ios::beg);
    vector<string>nombres;
    for(int i=0;i<t;i++)
    {
    in.read(nombre,10);
    nombres.push_back(nombre);
    }
    return nombres;

}

//Devuelve true si valor_buscado (dado) se encuentra dentro de mi_cola (dada), de lo contrario devuelve false
bool existe(queue<char> mi_cola, char valor_buscado)
{
//    for(queue<char>::iterator i=mi_cola.begin(); i!=mi_cola.end();i++)
//    {
//        if(*i==valor_buscado) return true;
//    }
    return false;
}

//Devuelve true si valor (dado) existe dentro de mi_set (dado)
bool existe(set<int> mi_set,int valor)
{

//    int num;
//    for(iterator::mi_set; iterator<mi_set.size(); iterator++)
//    if(mi_set->num==valor) return true;
    return false;
}

//Devuelve una lista inversa de mi_lista (dada)
list<double> invertir(list<double>mi_lista)
{
    list<double> invertida;
    return invertida;
}

//Devuelve la cantidad de nodos que contiene un arbol con raiz dada
int contar(NodoBinario* raiz)
{
    int number=0;
//    if(raiz==NULL) return;
//    cout<<raiz->valor<<endl;
//    Imprimir(raiz->hijo_izq);
//    Imprimir(raiz->hijo_der);
    if(raiz!=NULL) number=number+1;
    cout<<number<<endl;
    //contar(raiz->hijo_izq);
    //contar(raiz->hijo_der);
//    if(raiz->hijo_der!=NULL)contador=contador+1;
//    if(raiz->hijo_izq!=NULL)contador=contador+1;

    return number;
}

//Cambia todos los valores de un arbol con raiz dada
void cambiarValores(NodoBinario* raiz,int nuevo_valor)
{
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

