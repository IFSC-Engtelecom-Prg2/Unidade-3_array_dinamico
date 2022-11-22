//
// Created by msobral on 22/11/2022.
//

//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <fstream>
#include <list>
#include <string>
#include "dynarray.h"
#include "gtest/gtest.h"

using namespace std;

class TesteDynarray: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }

    void escreva_lista(list<int> & l, const string & sep, ostream & out) {
        if (l.empty()) return;
        int n = l.size();
        auto it=l.begin();
        for (; n > 1; it++, n--) out << *it << sep;
        out << *it;
    }

};

TEST_F(TesteDynarray, CriarVazio) {
    auto v = prg2::dynarray_cria();
    ASSERT_TRUE(prg2::dynarray_vazio(v));
    ASSERT_EQ(prg2::dynarray_tamanho(v), 0);
}

TEST_F(TesteDynarray, CriarComCapacidade) {
    const int InitCap = 64;
    auto v = prg2::dynarray_cria(InitCap);
    ASSERT_TRUE(prg2::dynarray_vazio(v));
    ASSERT_EQ(prg2::dynarray_tamanho(v), InitCap);
}

TEST_F(TesteDynarray, DestroiArray) {
    auto v = prg2::dynarray_cria();
    ASSERT_NO_THROW(prg2::dynarray_destroi(v));
}

TEST_F(TesteDynarray, AnexarSemExpandir) {
    auto v = prg2::dynarray_cria();

    for (auto j=0; j < prg2::DefaultCapacity; j++) {
        prg2::dynarray_anexa(v, j);
        ASSERT_FALSE(prg2::dynarray_vazio(v));
        ASSERT_EQ(prg2::dynarray_tamanho(v), j+1);
    }
}

TEST_F(TesteDynarray, InserirSemExpandir) {
    auto v = prg2::dynarray_cria();

    for (auto j=0; j < prg2::DefaultCapacity; j++) {
        prg2::dynarray_insere(v, j);
        ASSERT_FALSE(prg2::dynarray_vazio(v));
        ASSERT_EQ(prg2::dynarray_tamanho(v), j+1);
    }
}

TEST_F(TesteDynarray, FrenteVazio) {
    auto v = prg2::dynarray_cria();

    ASSERT_THROW(prg2::dynarray_frente(v), std::invalid_argument);
}

TEST_F(TesteDynarray, AtrasVazio) {
    auto v = prg2::dynarray_cria();

    ASSERT_THROW(prg2::dynarray_atras(v), std::invalid_argument);
}

TEST_F(TesteDynarray, AnexarAcessar) {
    auto v = prg2::dynarray_cria();
    const int Val = 5;

    for (auto j=0; j < prg2::DefaultCapacity; j++) {
        prg2::dynarray_anexa(v, j+Val);
        ASSERT_EQ(prg2::dynarray_atras(v), j+Val);
    }
}

TEST_F(TesteDynarray, InserirAcessar) {
    auto v = prg2::dynarray_cria();
    const int Val = 5;

    for (auto j=0; j < prg2::DefaultCapacity; j++) {
        prg2::dynarray_insere(v, j+Val);
        ASSERT_EQ(prg2::dynarray_frente(v), j+Val);
    }
}

TEST_F(TesteDynarray, AnexarComExpansao) {
    auto v = prg2::dynarray_cria();

    for (auto j=0; j < 2*prg2::DefaultCapacity; j++) {
        prg2::dynarray_anexa(v, j);
        ASSERT_EQ(prg2::dynarray_atras(v), j);
        ASSERT_EQ(prg2::dynarray_tamanho(v), j+1);
    }
}

TEST_F(TesteDynarray, InserirComExpansao) {
    auto v = prg2::dynarray_cria();

    for (auto j=0; j < 2*prg2::DefaultCapacity; j++) {
        prg2::dynarray_insere(v, j);
        ASSERT_EQ(prg2::dynarray_frente(v), j);
        ASSERT_EQ(prg2::dynarray_tamanho(v), j+1);
    }
}

TEST_F(TesteDynarray, AnexarIterar) {
    auto v = prg2::dynarray_cria();
    const int Val = 7;

    for (auto j=0; j < 2*prg2::DefaultCapacity; j++) {
        prg2::dynarray_anexa(v, j+Val);
    }
    for (auto j=0; j < 2*prg2::DefaultCapacity; j++) {
        ASSERT_EQ(prg2::dynarray_acessa(v, j), j+Val);
    }

    // posição inválida
    ASSERT_THROW(prg2::dynarray_acessa(v, 100), std::invalid_argument);
    ASSERT_THROW(prg2::dynarray_acessa(v, prg2::dynarray_tamanho(v)), std::invalid_argument);
}

TEST_F(TesteDynarray, InserirIterar) {
    auto v = prg2::dynarray_cria();
    const int Val = 7;

    for (auto j=0; j < 2*prg2::DefaultCapacity; j++) {
        prg2::dynarray_insere(v, j+Val);
    }
    for (auto j=2*prg2::DefaultCapacity-1; j >= 0; j--) {
        ASSERT_EQ(prg2::dynarray_acessa(v, j), j+Val);
    }
}

TEST_F(TesteDynarray, Limpa) {
    auto v = prg2::dynarray_cria();

    for (auto j = 0; j < 2 * prg2::DefaultCapacity; j++) {
        prg2::dynarray_insere(v, j);
    }
    ASSERT_FALSE(prg2::dynarray_vazio(v));
    prg2::dynarray_limpa(v);
    ASSERT_TRUE(prg2::dynarray_vazio(v));
    ASSERT_EQ(prg2::dynarray_tamanho(v), 0);
}

TEST_F(TesteDynarray, RemoveInicio) {
    auto v = prg2::dynarray_cria();
    ASSERT_THROW(prg2::dynarray_remove_inicio(v), std::invalid_argument);

    for (auto j=0; j < prg2::DefaultCapacity; j++) {
        prg2::dynarray_anexa(v, j);
    }
    for (auto j=0; j < prg2::DefaultCapacity; j++) {
        ASSERT_EQ(prg2::dynarray_frente(v), j);
        prg2::dynarray_remove_inicio(v);
        ASSERT_EQ(prg2::dynarray_tamanho(v), prg2::DefaultCapacity-(j+1));
    }
}

TEST_F(TesteDynarray, RemoveFim) {
    auto v = prg2::dynarray_cria();
    ASSERT_THROW(prg2::dynarray_remove_fim(v), std::invalid_argument);

    for (auto j=0; j < prg2::DefaultCapacity; j++) {
        prg2::dynarray_insere(v, j);
    }
    for (auto j=0; j < prg2::DefaultCapacity; j++) {
        ASSERT_EQ(prg2::dynarray_atras(v), j);
        prg2::dynarray_remove_inicio(v);
        ASSERT_EQ(prg2::dynarray_tamanho(v), prg2::DefaultCapacity-(j+1));
    }
}

TEST_F(TesteDynarray, InserePosicao) {
    auto v = prg2::dynarray_cria();

    for (auto j = 0; j < prg2::DefaultCapacity/2; j++) {
        prg2::dynarray_insere(v, j);
    }
    auto len = prg2::dynarray_tamanho(v);
    // no meio
    prg2::dynarray_insere(v, 11, len/2);
    ASSERT_EQ(prg2::dynarray_acessa(v, len/2), 11);
    ASSERT_EQ(prg2::dynarray_tamanho(v), len+1);

    // no inicio
    prg2::dynarray_insere(v, 55, 0);
    ASSERT_EQ(prg2::dynarray_frente(v), 55);
    ASSERT_EQ(prg2::dynarray_tamanho(v), len+2);

    // no final
//    prg2::dynarray_insere(v, 11, len);
//    ASSERT_EQ(prg2::dynarray_atras(v), 77);
//    ASSERT_EQ(prg2::dynarray_tamanho(v), len+3);

    // posição inválida
    ASSERT_THROW(prg2::dynarray_insere(v, 11, len), std::invalid_argument);
//    ASSERT_EQ(prg2::dynarray_atras(v), 77);
//    ASSERT_EQ(prg2::dynarray_tamanho(v), len+3);

}