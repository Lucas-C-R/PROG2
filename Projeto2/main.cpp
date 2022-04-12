#include <iostream>
#include "sistema.h"

int main()
{
    // O usuario deve digitar o nome do arquivo que sera usado
    string arquivo;
    queue<string> indexar;
    getline(cin,arquivo);

    separa(arquivo, ',', indexar);

    arquivo = indexar.front();

    // Abre o arquivo
    ifstream arq(arquivo);
    indexar.pop();

    // Se houver algum erro na abertura do arquivo, mostra na tela
    if(! arq.is_open()){
        perror("Erro ao abrir o arquivo!!");
        return errno;
    }

    if(indexar.empty()){
        perror("Voce deve informar as colunas que deseja!!");
        return errno;
    } else if(! verifica_se_colunas_existem(arq, indexar)){
        perror("Coluna(s) Inexistente(s)!!");
        return errno;
    }

    // Tabela onde serão armazenadas as árvores de indexação
    unordered_map<string, arvore<dados>> tab;
    list<string> nome_das_colunas;

    while(! indexar.empty()){
        nome_das_colunas.push_back(indexar.front());
        indexar.pop();
    }

    cria_arvores(arq, tab, nome_das_colunas);


    while(true){
        string coluna;
        queue<string> colunas;

        // Imprime o "menu" na tela e recebe o nome da coluna desejada
        cout << endl << "coluna > ";
        getline(cin,coluna);
        separa(coluna, ',', colunas);

        // Se o usuario nao digitar nada, ou seja, apenas der ENTER, ele encerra o programa
        if(coluna.empty()){
            break;
            // Senao, pesquisa se a coluna digitada existe na tabela
        } else if(! verifica_se_colunas_existem(arq, colunas)){
            cout << endl << "Coluna(s) inexistente(s)" << endl;
        } else
            // Se a coluna digitada existe
            while(true){
                string valor;
                queue<string> valores;

                // Pede para que o usuario digite o valor/conteudo desejado
                cout << endl << "valor > ";
                getline(cin,valor);

                // Se o usuario nao digitar nada, apenas der ENTER, ele repete o pedido
                if(valor.empty()){
                    break;
                } else {
                    separa(valor, ',', valores);

                    // Verifica se o numero de valores e colunas digitados sao iguais
                    if(colunas.size() != valores.size()){
                        cout << endl << "Numero de colunas e valores digitados deve ser igual" << endl;
                        break;
                    }
                }

                // Lista que contém todas as linhas buscadas
                list<string> lista_linhas;

                arq.clear();

                // Procura por todas as linhas que possuem os valores desejados pelo usuario
                procura_na_arvore(arq, colunas, valores, tab, lista_linhas);

                // Mostra as linhas
                cout << endl;
                for(auto & it: lista_linhas){
                    cout << it << endl;
                }

                // Encerra o loop
                break;
            }
    }

    return 0;
}