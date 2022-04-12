#ifndef SPLAY_SPLAY_IMPL_H
#define SPLAY_SPLAY_IMPL_H

#include "splay.h"

namespace splay {

    template <typename T> Nodo<T> * cria_nodo(const T & algo, Nodo<T> * pai){
        Nodo<T> * p_nodo = new Nodo<T>;

        p_nodo->dado = algo;

        p_nodo->esq = nullptr;
        p_nodo->dir = nullptr;
        p_nodo->pai = pai;

        return p_nodo;
    }

    template <typename T> void zig(Nodo<T> * nodoB){
        // nodoA é o pai do nodoB
        Nodo<T> * nodoA = nodoB->pai;

        // sub2 esta a direita do nodoB
        Nodo<T> * sub2 = nodoB->dir;

        // Deve-se atualizar o nodo pai do nodoA, o qual
        // deve ser o mesmo pai do nodoB (se nodoB não for a raiz)

        Nodo<T> * paiA = nodoA->pai;
        nodoB->pai = paiA;
        if(paiA!=nullptr){
            if(na_esquerda(nodoA)) paiA->esq = nodoB;
            else paiA->dir = nodoB;
        }

        // sub2 deve ir para a esquerda do nodoA
        nodoA->esq = sub2;
        if(sub2 != nullptr) sub2->pai = nodoA;

        // nodoA deve estar na direita do nodoB
        nodoB->dir = nodoA;
        nodoA->pai = nodoB;

    }

    template <typename T> void zag(Nodo<T> * nodoA){
        // NodoB é o pai do nodoA
        Nodo<T> * nodoB = nodoA->pai;

        // sub2 esta a esquerda do nodoA
        Nodo<T> * sub2 = nodoA->esq;

        // Deve-se atualizar o nodo pai do nodoA, o qual
        // deve ser o mesmo pai do nodoB (se nodoB não for a raiz)

        Nodo<T> * paiB = nodoB->pai;
        nodoA->pai = paiB;
        if(paiB!=nullptr){
            if(na_esquerda(nodoB)) paiB->esq = nodoA;
            else paiB->dir = nodoA;
        }

        // sub2 deve estar a direita do nodoB
        nodoB->dir = sub2;
        if(sub2 != nullptr) sub2->pai = nodoB;

        // NodoB deve estar a esquerda do nodoA
        nodoA->esq = nodoB;
        nodoB->pai = nodoA;



    }

    template <typename T> bool na_esquerda(Nodo<T> * ptr){
        Nodo<T> * pai = ptr->pai;
        return pai->esq == ptr;
    }

    template <typename T> bool caso_zig_zig(Nodo<T> * ptr){
        return na_esquerda(ptr) && na_esquerda(ptr->pai);
    }

    template <typename T> bool caso_zag_zag(Nodo<T> * ptr){
        return !na_esquerda(ptr) && !na_esquerda(ptr->pai);
    }

    template <typename T> bool caso_zig_zag(Nodo<T> * ptr){
        return na_esquerda(ptr) && !na_esquerda(ptr->pai);
    }

    template <typename T> bool caso_zag_zig(Nodo<T> * ptr){
        return !na_esquerda(ptr) && na_esquerda(ptr->pai);
    }

    template <typename T> void move_raiz(Nodo<T> * ptr, Splay<T> & arv){
        // Move o nodo apontado por ptr para a raiz
        // deve aplicar as transformações necessárias, possivelmente
        // de forma sucessiva.

        //enquanto não for a raiz
        while(ptr->pai!=nullptr){
            //testa qual função aplicar
            // a efetua
            // A transformação pode ser simples (zig ou zag)
            // ou uma combinação delas (zigzig, zagzag, zigzag, zagzig)
            if(ptr->pai->pai == nullptr){
                if(na_esquerda(ptr)) zig(ptr);
                else zag(ptr);
            }
            else{
                if(caso_zig_zig(ptr)){
                    zig(ptr->pai);
                    zig(ptr);
                }
                else if(caso_zag_zag(ptr)){
                    zag(ptr->pai);
                    zag(ptr);
                }
                else if(caso_zig_zag(ptr)){
                    zig(ptr);
                    zag(ptr);
                }
                else if(caso_zag_zig(ptr)){
                    zag(ptr);
                    zig(ptr);
                }
            }
        }
        arv.raiz = ptr;
    }


    template <typename T> Splay<T> cria_splay() {
        Splay<T> arv;
        arv.raiz = nullptr;

        return arv;
    }

    template <typename T> bool splay_vazia(Splay<T> & arv) {
        return arv.raiz == nullptr;
    }

    template <typename T> bool splay_adiciona(Splay<T> & arv, T & algo) {

        if(arv.raiz == nullptr){
            arv.raiz = cria_nodo<T>(algo, nullptr);
        }
        else {
            Nodo<T> * ptr = arv.raiz;
            while(true){
                if(ptr->dado == algo){
                    ptr->dado = algo;
                    move_raiz(ptr, arv);
                    break;
                }
                else if(algo < ptr->dado){
                    if(ptr->esq != nullptr){
                        ptr = ptr->esq;
                    }
                    else{
                        ptr->esq = cria_nodo<T>(algo, ptr);
                        move_raiz(ptr->esq, arv);
                        break;
                    }
                }
                else{
                    if(ptr->dir != nullptr){
                        ptr = ptr->dir;
                    }
                    else{
                        ptr->dir = cria_nodo<T>(algo, ptr);
                        move_raiz(ptr->dir, arv);
                        break;
                    }
                }
            }

        }
    }

    template <typename T> T& splay_acessa(Splay<T> & arv, T & algo){
        Nodo<T> * ptr = arv.raiz;

        while(ptr!=nullptr){
            if(algo==ptr->dado){
                move_raiz(ptr, arv);
                return ptr->dado;
            }
            if(algo<ptr->dado) ptr = ptr->esq;
            else ptr = ptr->dir;
        }

        throw std::exception();
    }

    template <typename T> T& obtem_maior(Splay<T> & arv){
        Nodo<T> * ptr = arv.raiz;
        while(ptr->dir != nullptr){
            ptr = ptr->dir;
        }
        return ptr->dado;
    }

    template <typename T> T& obtem_menor(Splay<T> & arv){
        if(arv.raiz == nullptr) throw std::exception();
        Nodo<T> * ptr = arv.raiz;
        while(ptr->esq != nullptr){
            ptr = ptr->esq;
        }
        return ptr->dado;
    }

    template <typename T> void destroi_splay(Splay<T> & arv){
        // Se a arvore estiver vazia, não faz nada
        if(arv.raiz == nullptr) return;

        destroi_subarvore(arv.raiz);

        // É necessario deixar a raiz como nullptr por conta da splay_vazia
        arv.raiz = nullptr;
    }

    template <typename T> void destroi_subarvore(Nodo<T> *ptr){
        // Roda a subarvore da esquerda e a destroi
        if(ptr->esq != nullptr){
            destroi_subarvore(ptr->esq);
        }

        // Roda a subarvore da direita e a destroi
        if(ptr->dir != nullptr){
            destroi_subarvore(ptr->dir);
        }

        delete ptr;
    }


}
#endif //SPLAY_SPLAY_IMPL_H