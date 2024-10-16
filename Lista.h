#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template<typename Tipo>
class Lista {
    public:
        Lista();
        void push_back(Tipo);
        void push_front(Tipo);
        void pop_back();
        void pop_front();
        int size();
        bool empty();
        Nodo<Tipo> *front();
        Nodo<Tipo> *back();
        void clear();
        void insert(int, int, Tipo);
        class iterador;
        iterador inicio();
        iterador final();

    private:
        Nodo<Tipo> *primerNodo;
        Nodo<Tipo> *ultimoNodo;
};

template <typename Tipo>
Lista<Tipo>::Lista() {
    this->primerNodo = nullptr;
    this->ultimoNodo = nullptr;
}

template <typename Tipo>
void Lista<Tipo>::push_back(Tipo valor) {
    Nodo<Tipo>* nuevoNodo = new Nodo<Tipo>(valor);
    if (empty()) {
        this->primerNodo = nuevoNodo;
        this->ultimoNodo = nuevoNodo;
    } else {
        Nodo<Tipo>* temporal = this->ultimoNodo;
        this->ultimoNodo = nuevoNodo;
        temporal->definirSiguiente(ultimoNodo);
        this->ultimoNodo->definirAnterior(temporal);
    }
}

template <typename Tipo>
void Lista<Tipo>::pop_back() {
    if (!empty()) {
        Nodo<Tipo>* temporal = back();
        if (this->front() == this->back()) {
            this->primerNodo = nullptr;
            this->ultimoNodo = nullptr;
        } else {
            ultimoNodo = temporal->obtenerAnterior();
            if (this->ultimoNodo != nullptr) {
                this->ultimoNodo->definirSiguiente(nullptr);
            }
        }
        delete temporal;
    }
}

template <typename Tipo>
void Lista<Tipo>::push_front(Tipo valor) {
    Nodo<Tipo>* nuevoNodo = new Nodo<Tipo>(valor);
    if (empty()) {
        this->primerNodo = nuevoNodo;
        this->ultimoNodo = nuevoNodo;
    } else {
        nuevoNodo->definirSiguiente(this->primerNodo);
        this->primerNodo->definirAnterior(nuevoNodo);
        this->primerNodo = nuevoNodo;
    }
}

template <typename Tipo>
void Lista<Tipo>::pop_front() {
    if (!empty()) {
        Nodo<Tipo>* temporal = this->primerNodo();
        if (this->front() == this->back()) {
            this->primerNodo = nullptr;
            this->ultimoNodo = nullptr;
        } else {
            this->primerNodo = temporal->obtenerSiguiente();
            this->primerNodo->definirAnterior(nullptr);
        }
        delete temporal;
    }
}

template <typename Tipo>
bool Lista<Tipo>::empty() {
    return this->primerNodo == nullptr;
}

template <typename Tipo>
Nodo<Tipo>* Lista<Tipo>::back() {
    if (empty()) {
        return nullptr;
    }
    return this->ultimoNodo;
}

template <typename Tipo>
Nodo<Tipo>* Lista<Tipo>::front() {
    if (empty()) {
        return nullptr;
    }
    return this->primerNodo;
}

template <typename Tipo>
int Lista<Tipo>::size() {
    int contador = 0;
    Nodo<Tipo>* actual = this->primerNodo;

    while (actual != nullptr) {
        contador++;
        actual = actual->obtenerSiguiente();
    }

    return contador;
}

template <typename Tipo>
void Lista<Tipo>::insert(int posicion, int cantidad, Tipo valor) {
    if (posicion < 0 || posicion > size()) {
        return;
    }

    if (posicion == 0) {
        for (int i = 0; i < cantidad; ++i) {
            push_front(valor);
        }
        return;
    }

    if (posicion == size()) {
        for (int i = 0; i < cantidad; ++i) {
            push_back(valor);
        }
        return;
    }

    iterador it = inicio();
    for (int i = 0; i < posicion; ++i) {
        ++it;
    }

    Nodo<Tipo>* siguiente = it.nodoActual;
    Nodo<Tipo>* anterior = siguiente->obtenerAnterior();

    for (int i = 0; i < cantidad; ++i) {
        Nodo<Tipo>* nuevoNodo = new Nodo<Tipo>(valor);
        nuevoNodo->definirSiguiente(siguiente);
        nuevoNodo->definirAnterior(anterior);
        anterior->definirSiguiente(nuevoNodo);
        siguiente->definirAnterior(nuevoNodo);
        anterior = nuevoNodo;
    }
}

template <typename Tipo>
typename Lista<Tipo>::iterador Lista<Tipo>::inicio() {
    return iterador(this->front());
}

template <typename Tipo>
typename Lista<Tipo>::iterador Lista<Tipo>::final() {
    return iterador(this->back()->obtenerSiguiente());
}

template <typename Tipo>
void Lista<Tipo>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename Tipo>
class Lista<Tipo>::iterador {
    public:
        using pointer = Tipo*;
        using reference = Tipo&;

        iterador(Nodo<Tipo> *nodo = nullptr) {
            this->nodoActual = nodo;
        }

        reference operator*() {
            return this->nodoActual->obtenerValor();
        }

        pointer operator->() {
            return &(this->nodoActual->obtenerValor());
        }

        iterador& operator++() {
            if(this->nodoActual != nullptr) {
                this->nodoActual = this->nodoActual->obtenerSiguiente();
            }
            return *this;
        }

        iterador& operator--() {
            if(this->nodoActual != nullptr) {
                this->nodoActual = this->nodoActual->obtenerAnterior();
            }
            return *this;
        }

        bool operator==(iterador otro) {
            return this->nodoActual == otro.nodoActual;
        }

        bool operator!=(iterador otro) {
            return this->nodoActual != otro.nodoActual;
        }


    private:
        Nodo<Tipo>* nodoActual;

    friend class Lista;
};

#endif
