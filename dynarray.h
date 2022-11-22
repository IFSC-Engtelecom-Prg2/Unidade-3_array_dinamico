//
// Created by msobral on 05/07/22.
//

#ifndef PROJ3_DYNARRAY_H
#define PROJ3_DYNARRAY_H

// a definição da API do array dinâmico !
namespace prg2 {
    // a capacidade inicial default de um array dinãmico
    const int DefaultCapacity = 8;

    struct Dynarray {
        // ??? ainda não sei o que vai aqui dentro ...
        // a área de memória ???
        // a quantidade de dados armazenados ??
    };

    // As operações do array dinâmico

    // cria uma array dinâmico inicialmente vazio, mas com uma capacidade inicial
    // se omitida, a capacidade inicial predefinida tem valor DefaultCapacity
    Dynarray dynarray_cria(int capacidade=DefaultCapacity);

    // destroi uma array dinâmico
    void dynarray_destroi(Dynarray & v);

    // Acessa o dado da frente da array dinâmico
    // se array dinâmico vazia: o que acontece ????
    // DISPARA EXCEÇÃO do tipo invalid_argument
    int dynarray_frente(const Dynarray & v);

    // Acessa o dado do final da array dinâmico
    // se array dinâmico vazia: o que acontece ????
    // DISPARA EXCEÇÃO do tipo invalid_argument
    int dynarray_atras(const Dynarray & v);

    // esvazia uma array dinâmico
    void dynarray_limpa(Dynarray & v);

    // remove o dado do início
    // se array dinâmico vazia: DISPARA EXCEÇÃO do tipo invalid_argument
    void dynarray_remove_inicio(Dynarray & v);

    // remove o dado do fim
    // se array dinâmico vazia: DISPARA EXCEÇÃO do tipo invalid_argument
    void dynarray_remove_fim(Dynarray & v);

    // Anexa um dado à array dinâmico
    void dynarray_anexa(Dynarray & v, int dado);

    // Insere um dado no início da array dinâmico
    void dynarray_insere(Dynarray & v, int dado);

    // Insere um dado numa posição da array dinâmico
    // Se posição inálida, dispara exceção invalid_argument
    void dynarray_insere(Dynarray & v, int dado, int posicao);

    // Retorna o tamanho da array dinâmico
    int dynarray_tamanho(const Dynarray & v);

    // Verifica se array dinâmico está vazia
    bool dynarray_vazia(const Dynarray & v);

    // Acessa um dado de uma posição da array dinâmico
    // Se posição inálida, dispara exceção invalid_argument
    int dynarray_acessa(const Dynarray & v, int posicao);

}
#endif //PROJ3_DYNARRAY_H
