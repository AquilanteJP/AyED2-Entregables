#include "Lista.h"
#include <cassert>

Lista::Lista() {
    prim=nullptr;
    ult=nullptr;
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    copiarNodos(l);
}

Lista::~Lista() {
    destruirNodos();
}

void Lista::destruirNodos(){
    Nodo* actual = prim;
    prim=nullptr;
    ult=nullptr;
    while(actual != nullptr){
        Nodo* siguiente = actual->sig;
        delete actual;
        actual=siguiente;
    }
}

void Lista::copiarNodos(const Lista &o) {
    Nodo* actual = o.prim;
    while (actual != nullptr) {
        agregarAtras(actual->valor);
        actual = actual->sig;
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo= new Nodo(elem,prim,nullptr); //prim o this->prim?
    if(prim==nullptr){
        prim=nuevo;
        ult=nuevo;
        return;
    }
    Nodo* segundo=prim;
    segundo->ant=nuevo;
    prim=nuevo;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo= new Nodo(elem,nullptr,ult); //prim o this->prim?
    if(ult==nullptr){
        prim=nuevo;
        ult=nuevo;
        return;
    }
    Nodo* anteultimo=ult;
    anteultimo->sig=nuevo;
    ult=nuevo;
}

void Lista::eliminar(Nat i) {
    if (this->longitud() == 0) {
        return;
    }

    Nat cont = 0;
    Nodo *iesimo = prim;
    while (cont < i) {
        iesimo = iesimo->sig;
        cont++;
    }
    if (this->longitud() == 1) {
        prim=nullptr;
        ult=nullptr;
        delete iesimo;
        return;
    }

    Nodo *anterior = iesimo->ant;
    Nodo *siguiente = iesimo->sig;
    iesimo->ant = nullptr;
    iesimo->sig = nullptr;

    if (anterior == nullptr) {
        siguiente->ant = nullptr;
        prim = siguiente;
        delete iesimo;
    } else if (siguiente == nullptr) {
        anterior->sig = nullptr;
        ult = anterior;
        delete iesimo;
    } else {
        delete iesimo;
        siguiente->ant=anterior;
        anterior->sig=siguiente;
    }
}

int Lista::longitud() const {
    int res=0;
    Nodo* inicio=prim;
    while(inicio!=nullptr){ //inicio, no inicio->sig, boludo
        Nodo *sig = inicio->sig;
        inicio = sig;
        res++;
    }
    return res;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* inicio=prim;
    Nat cont=0;
    while(cont<i){
        inicio=inicio->sig;
        cont++;
    }
    return inicio->valor;
}

int& Lista::iesimo(Nat i) {
    Nodo* inicio=prim;
    Nat cont=0;
    while(cont<i){
        inicio=inicio->sig;
        cont++;
    }
    return inicio->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}
