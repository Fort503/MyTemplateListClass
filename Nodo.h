#ifndef NODO_H
#define NODO_H

template<typename Tipo>
class Lista;

template<typename Tipo>
class Nodo {
public:
    Nodo(Tipo valor) {
        this->valor = valor;
        this->siguiente = nullptr;
        this->anterior = nullptr;
    }

    void definirSiguiente(Nodo<Tipo>* nodo) {
        siguiente = nodo;
    }

    void definirAnterior(Nodo<Tipo>* nodo) {
        anterior = nodo;
    }

    Nodo<Tipo>* obtenerSiguiente() {
        return siguiente;
    }

    Nodo<Tipo>* obtenerAnterior() {
        return anterior;
    }

    Tipo& obtenerValor() {
        return this->valor;
    }

private:
    Tipo valor;
    Nodo<Tipo>* siguiente;
    Nodo<Tipo>* anterior;

    friend class Lista<Tipo>;
};

#endif
