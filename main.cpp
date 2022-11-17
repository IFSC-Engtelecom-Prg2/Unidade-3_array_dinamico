#include <iostream>
#include <string>
#include "dynarray.h"

using std::cout;
using std::endl;
using std::string;

// gera uma string com uma representação do conteúdo do array dinâmico
// Parâmetros:
//  q: o array dinâmico
// delim: um caractere a ser usado como delimitador entre os valores do array dinâmico na string
// Resultado: uma string com o conteúdo do array dinâmico
string dynarray2string(const prg2::dynarray<int> & q, char delim=',') {
    string r;

    // somente gera a string de resultado se deque não estiver vazio
    if (! prg2::dynarray_vazio(q)) {
        auto len = prg2::dynarray_tamanho(q);
        // itera o deque, convertendo seus valores para string e unindo-os com o caractere delim
        for (int j = 0; j < len; j++) {
            r += std::to_string(prg2::dynarray_acessa(q, j)) + delim;
        }
        // remove o caractere delimitador em excesso
        r.pop_back();
    }

    return r;
}

int main() {
    // cria um deque que armazena int
    prg2::dynarray<int> q1;

    // acrescenta dados ao início
    prg2::dynarray_insere(q1, 7);
    prg2::dynarray_insere(q1, 9);
    cout << "Deque após inserir alguns dados: " << dynarray2string(q1) << endl;

    // acrescenta dados ao final
    prg2::dynarray_anexa(q1, 2);
    prg2::dynarray_anexa(q1, 4);
    cout << "Deque após anexar mais alguns dados: " << dynarray2string(q1) << endl;

    // Remove um dado do início
    prg2::dynarray_remove_inicio(q1);
    cout << "Deque após remover do início: " << dynarray2string(q1) << endl;

    // Remove um dado do final
    prg2::dynarray_remove_final(q1);
    cout << "Deque após remover do final: " << dynarray2string(q1) << endl;

    return 0;
}
