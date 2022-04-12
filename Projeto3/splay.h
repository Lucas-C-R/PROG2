#ifndef SPLAY_SPLAY_H
#define SPLAY_SPLAY_H

namespace splay {

    template <typename T> struct Nodo {
        Nodo<T> *esq, *dir, *pai;
        T dado;
    };

    template <typename T> struct Splay {
        Nodo<T> * raiz;
    };

    template <typename T> void zig(Nodo<T> * nodoB);

    template <typename T> void zag(Nodo<T> * nodoA);

    template <typename T> bool na_esquerda(Nodo<T> * ptr);

    template <typename T> bool caso_zig_zig(Nodo<T> * ptr);

    template <typename T> bool caso_zag_zag(Nodo<T> * ptr);

    template <typename T> bool caso_zig_zag(Nodo<T> * ptr);

    template <typename T> bool caso_zag_zig(Nodo<T> * ptr);

    // Move um nodo para a raiz
    template <typename T> void move_raiz(Nodo<T> * ptr, Splay<T> & arv);


    // cria uma árvore splay vazia
    template <typename T> Splay<T> cria_splay();

    // destroi uma arvore
    template <typename T> void destroi_splay(Splay<T> & arv);

    // retorna true se se árvore estiver vazia
    template <typename T> bool splay_vazia(Splay<T> & arv);

    // adiciona "algo" à árvore.
    // ao final, esse novo valor se tornará a nova raiz da árvore
    template <typename T> bool splay_adiciona(Splay<T> & arv, const T & algo);

    // Acessa um valor na arvore
    template <typename T> T& splay_acessa(Splay<T> & arv, const T & algo);

    template <typename T> T& obtem_maior(Splay<T> & arv);

    template <typename T> T& obtem_menor(Splay<T> & arv);

    template <typename T> void destroi_subarvore(Nodo<T> * ptr);

    template <typename T> void destroi_splay(Splay<T> & arv);

}

#endif //SPLAY_SPLAY_H

#include "splay-impl.h"
