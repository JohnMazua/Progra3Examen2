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
//    ifstream in(nombre_archivo.c_str());
//    char nombre[10];
//    char correo[10];
//    int numero;
//
//    in.seekg(24*posicion);
//    in.read(nombre,10);

    vector<string>nombres;

    return nombres;

}

//Devuelve true si valor_buscado (dado) se encuentra dentro de mi_cola (dada), de lo contrario devuelve false
bool existe(queue<char> mi_cola, char valor_buscado)
{
    char buscador;
    while (!mi_cola.empty())
    {
    if (mi_cola.front()==valor_buscado) return true;
    mi_cola.pop();
    }
    return false;
}

//Devuelve true si valor (dado) existe dentro de mi_set (dado)
bool existe(set<int> mi_set,int valor)
{
    int buscador;
    for (set<int>::iterator i=mi_set.begin();i!=mi_set.end();i++)
    {
    buscador=*i;
    if(buscador==valor)
    return true;
    }

    return false;
}

//Devuelve una lista inversa de mi_lista (dada)
list<double> invertir(list<double>mi_lista)
{
    double number;
    list<double> invert_list;
    for (list<double>::iterator i=mi_lista.begin();i!=mi_lista.end();i++)
    {
    number=*i;
    invert_list.push_front(number);
    }
    return invert_list;
}

//Devuelve la cantidad de nodos que contiene un arbol con raiz dada
int contar(NodoBinario* raiz)
{
    int number=0;
    if(raiz==NULL) return 0;
        number=number+1;
        contar(raiz->hijo_izq);
        contar(raiz->hijo_der);
    return number;
}

//Cambia todos los valores de un arbol con raiz dada
void cambiarValores(NodoBinario* raiz,int nuevo_valor)
{
    if(raiz==NULL) return;
    if(raiz->valor!=nuevo_valor) raiz->valor=nuevo_valor;
    cambiarValores(raiz->hijo_der,nuevo_valor);
    cambiarValores(raiz->hijo_izq,nuevo_valor);
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

