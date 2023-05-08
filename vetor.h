//
// Created by aluno on 08/05/23.
//

#ifndef DYNARRAY_VETOR_H
#define DYNARRAY_VETOR_H

namespace prg2 {

    // tamanho de cada expansão de capacidade do vetor, em posições
    const int MinSize = 8;

    // O tipo VetorDinamico
    struct VetorDinamico {
        // ???
    };

    // operações do VetorDinamico

    // cria um VetorDinamico com capacidade inicial dada por
    // MinSize
    VetorDinamico vetor_cria();

    // Destroi um vetor (destrutor)
    void vetor_destroi(VetorDinamico &v);

    // Acrescenta um valor ao final do vetor
    // Expande o vetor, caso necessário. A expansão
    // aloca uma capacidade adicional dada por MinSize
    void vetor_anexa(VetorDinamico &v, int valor);

    // Insere um valor no início do vetor
    // Expande o vetor, caso necessário. A expansão
    // aloca uma capacidade adicional dada por MinSize
    void vetor_insere(VetorDinamico &v, int valor);

    // Insere um valor na posição pos do vetor
    // Expande o vetor, caso necessário. A expansão
    // aloca uma capacidade adicional dada por MinSize
    // Dispara exceção se pos > tamanho do vetor
    void vetor_insere(VetorDinamico &v, int pos, int valor);

    // Acessa o dado da frente da vetor
    // se vetor vazia: o que acontece ????
    // DISPARA EXCEÇÃO do tipo invalid_argument
    int& vetor_frente(VetorDinamico & v);

    // Acessa o dado do final do vetor
    // se vetor vazia: o que acontece ????
    // DISPARA EXCEÇÃO do tipo invalid_argument
    int& vetor_atras(VetorDinamico & v);

    // remove o dado do início
    // se vetor vazia: DISPARA EXCEÇÃO do tipo invalid_argument
    void vetor_remove_inicio(VetorDinamico & v);

    // remove o dado do fim
    // se vetor vazia: DISPARA EXCEÇÃO do tipo invalid_argument
    void vetor_remove_fim(VetorDinamico & v);

    // retorna true se vetor estiver vazio
    bool vetor_vazio(const VetorDinamico & v);

    // Acessa um dado que está na posição pos do vetor
    // Obtém uma referência ao dado
    // Se pos > tamanho-1, dispara exceção
    int &vetor_obtem(VetorDinamico &v, int pos);

    // Remove um dado da posição pos do vetor
    // Se pos > tamanho-1, dispara exceção
    void vetor_remove(VetorDinamico &v, int pos);

    // Obtem o tamanho do vetor
    int vetor_tamanho(const VetorDinamico &v);

    // Obtem a capacidade do vetor (quantos dados cabem no total com a memória atualmente alocada)
    int vetor_capacidade(const VetorDinamico & v);

    // Esvazia o vetor
    void vetor_limpa(VetorDinamico &v);

    // Ordena o vetor
    void vetor_ordena(VetorDinamico &v);

    // Inverte o vetor
    void vetor_inverte(VetorDinamico &v);

    // Remove dados contíguos duplicados
    void vetor_unicos(VetorDinamico &v);

    // Expande a capacidade do vetor
    // A nova capacidade será >= capacidade solicitada
    // capacidade deve ser maior que capacidade atual, senão dispara
    // exceção
    void vetor_expande(VetorDinamico &v, int capacidade);

    // Contrai o vetor para caberem exatamente os dados atuais
    void vetor_contrai(VetorDinamico &v);

}
#endif //DYNARRAY_VETOR_H
