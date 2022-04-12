#include <iostream>
#include "sistema.h"

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

void cria_arvores(ifstream & arq, unordered_map<string, arvore<dados>> & tab, list<string> & nome_das_colunas)
{
    // O programa utiliza uma palavras_sep com cada valor de cada linha, que e apagado apos a linha ser processada
    // Alem disso, utiliza uma tabela hash que contem arvores com a indexação, de forma a facilitar a consulta por coluna
    // E utilizada uma nome_das_colunas com o nome de cada coluna ( Ex: Nome, CPF, etc...)

    string linha;
    list<int> conta_virg;

    arq.seekg(0);
    getline(arq,linha);

    // Pega a posicao da coluna desejada e armazena na lista
    conta_colunas(linha, nome_das_colunas, conta_virg);

    // Atualiza a variável com a posição da linha atual no arquivo
    int pos_linha = arq.tellg();

    // Pega a linha atual, separa em substrings, itera a nome_das_colunas e adiciona a struct contendo
    // os valores armazenados na palavras_sep e tambem a posiçao da linha em suas respectivas árvores de colunas.
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

            try {
                // Tenta obter da tabela uma struct ja existente e insere a posicao atual na lista
                dados & estrutura = (dados&)
                        tab[k].obtem(Dados);

                estrutura.posicao.push_back(pos_linha);
            } catch (...){
                // Senao, caso esteja vazia, por exemplo, apenas insere a nova struct
                // com a posicao atual na lista
                Dados.posicao.push_back(pos_linha);

                tab[k].adiciona(Dados);
            }

            it++;
        }
        // Atualiza com a posicao da linha atual
        pos_linha = arq.tellg();
    }

    // Balanceia ao maximo todas as arvores armazenadas na tabela hash.
    for(auto & par: tab){
        par.second.balanceia(true);
    }

    // Retira a flag de erro, da leitura do arquivo
    arq.clear();
}

void procura_na_arvore(ifstream & arq, queue<string> & coluna, queue<string> & valor, unordered_map<string, arvore<dados>> & tab, list<string> & lista_linhas)
{
    string linha;
    try {
        dados aux;
        aux.inf = valor.front();

        // Pega a arvore da coluna desejada na tabela
        auto & k = tab[coluna.front()].obtem(aux);

        // Itera a lista de posicoes, encontrando as posicoes no arquivo
        // e salvando cada linha em uma lista
        for(auto & it: k.posicao){
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