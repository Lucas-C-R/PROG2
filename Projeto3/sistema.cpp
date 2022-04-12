#include <iostream>
#include "sistema.h"
#include <algorithm>
#include <random>

// A função separa pega a linha do arquivo que foi lida com getline, separa ela em
// substrings retirando a virgula e as adiciona a uma fila.
void separa(const string & linha, const char & delim, queue<string> & palavras)
{
    int inic = 0, fim = 0;

    while(fim != linha.size()){
        fim = linha.find(delim, inic + 1);

        if(fim == string::npos){
            fim = linha.size();
        }

        palavras.push(linha.substr(inic, fim - inic));

        inic = fim + 1;
    }
}

// Essa funçao serve para encontrar a posiçao das colunas desejadas dentro da linha a partir
// da contagem de virgulas e as armazena em uma lista
void conta_colunas(const string & linha, const list<string> & nome_colunas, list<int> & conta_virg)
{
    for(auto & it: nome_colunas){
        int aux = linha.find(it);
        int quant_vir = 0;

        for(int virg = linha.find(','); virg < aux; virg = linha.find(',', virg + 1)){
            if(virg == string::npos){
                break;
            }
            quant_vir++;
        }

        conta_virg.push_back(quant_vir);
    }
}

void cria_vetor(ifstream & arq, unordered_map<string, vector<dados>> & tab_vetor, list<string> & nome_das_colunas)
{
    // O programa utiliza uma palavras_sep com cada valor de cada linha, que e apagado apos a linha ser processada
    // Alem disso, utiliza uma tabela hash que contem vetores com a indexação, de forma a facilitar a consulta por coluna
    // E utilizada uma nome_das_colunas com o nome de cada coluna ( Ex: Nome, CPF, etc...)

    string linha;
    list<int> conta_virg;

    arq.seekg(0);
    getline(arq,linha);

    // Pega a posicao da coluna desejada e armazena na lista
    conta_colunas(linha, nome_das_colunas, conta_virg);

    // Atualiza a variável com a posição da linha atual no arquivo
    int pos_linha = arq.tellg();

    while(getline(arq,linha)){
        queue<string> palavras_sep;

        separa(linha, ',', palavras_sep);

        // Cria um iterador para a lista que contem a posicao das colunas
        auto it = conta_virg.begin();

        // Itera a lista de colunas desejadas
        for(auto & k: nome_das_colunas){
            dados Dados;
            queue<string> palavras_aux = palavras_sep;

            // Itera a fila que contem as palavras da linha, ate encontrar a coluna desejada
            for(int n = 0; n < *it; n++){
                palavras_aux.pop();
            }

            Dados.inf = palavras_aux.front();

            bool existe = false;

            // Verifica se ja exite um vetor com a "inf" contida em Dados
            for(auto & itera: tab_vetor[k]){
                // Se ja existir, adiciona a posicao da nova linha, a lista
                if(Dados.inf == itera.inf){
                    itera.posicao.push_back(pos_linha);
                    existe = true;
                }
            }

            // Se nao existir, cria um vetor contendo o "Dados"
            if(! existe){
                Dados.posicao.push_back(pos_linha);
                tab_vetor[k].push_back(Dados);
            }

            it++;
        }

        // Atualiza com a posicao da linha atual
        pos_linha = arq.tellg();
    }

    // Retira a flag de erro, da leitura do arquivo
    arq.clear();

    // Randomiza os vetores associados a coluna desejada, deixando eles
    // completamente aleatorios, para melhorar a distribuicao na arvore
    for(auto & it: nome_das_colunas){
        auto semente = clock();
        default_random_engine rng(semente);
        shuffle(tab_vetor[it].begin(),tab_vetor[it].end(), rng);
    }
}

void cria_arvores(unordered_map<string, vector<dados>> & tab_vetor, unordered_map<string, Splay<dados>> & tab, list<string> & nome_das_colunas)
{
    // Copia as "struct dados" contidas nos vetores, para dentro das arvores Splay
    for(auto & it: nome_das_colunas){
        for(auto & k: tab_vetor[it]){
            splay_adiciona(tab[it], k);
        }
    }
}

void procura_na_arvore(ifstream & arq, queue<string> & coluna, queue<string> & valor, unordered_map<string, Splay<dados>> & tab, list<string> & lista_linhas)
{
    string linha;
    try {
        dados aux;
        aux.inf = valor.front();

        // Pega a arvore da coluna desejada na tabela
        aux = splay_acessa(tab[coluna.front()],aux);

        // Itera a lista de posicoes, encontrando as posicoes no arquivo
        // e salvando cada linha em uma lista
        for(auto & it: aux.posicao){
            // Vai no arquivo ate a posicao contida na lista de posiçoes
            arq.seekg(it);

            queue<string> valor_aux = valor;

            getline(arq,linha);

            valor_aux.pop();
            while(! valor_aux.empty()){
                if(linha.find(valor_aux.front()) == string::npos){
                    linha.clear();
                    break;
                }
                valor_aux.pop();
            }

            if(! linha.empty()){
                lista_linhas.push_back(linha);
            }
        }
    } catch (...){
        lista_linhas.push_back("Dado inexistente");
    }

    if(lista_linhas.empty()){
        lista_linhas.push_back("Dado inexistente");
    }
}

// Essa daqui o nome já diz tudo... Verifica se as colunas digitadas pelo usuario existem na tabela
bool verifica_se_colunas_existem(ifstream & arq, queue<string> colunas)
{
    string linha;
    queue<string> nome_coluna;
    getline(arq,linha);
    arq.clear();

    arq.seekg(0);
    getline(arq,linha);

    separa(linha,',',nome_coluna);

    // Compara o(s) nome(s) digitado(s) com os valores da primeira linha do arquivo
    int x = colunas.size();
    for(int n = 0; n < x; n++){
        queue<string> aux = nome_coluna;
        while(! aux.empty()){

            // Se o valor digitado que esta na frente da fila existir, sera apagado
            if(aux.front() == colunas.front()){
                colunas.pop();
            }

            aux.pop();
        }
    }

    // Se todos os valores digitados existirem, a funcao retorna "true", se nao, "false"
    return (colunas.empty());
}