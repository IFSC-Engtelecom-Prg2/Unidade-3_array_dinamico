# Unidade-3_vetor_dinamico

* [Mais informações sobre o vetor dinâmico](https://moodle.ifsc.edu.br/mod/book/view.php?id=650470&chapterid=110230)

Aqui você encontra o código inicial para a implementação do vetor dinâmico. Esse código define a [API ](https://pt.wikipedia.org/wiki/Interface_de_programa%C3%A7%C3%A3o_de_aplica%C3%A7%C3%B5es) do vetor dinâmico, na forma de um conjunto de funções declaradas em [vetor.h](/vetor.h). Para implementar o seu vetor dinâmico, você deve:
* Completar a declaração do tipo de dados [VetorDinamico](https://github.com/IFSC-Engtelecom-Prg2/Unidade-3_array_dinamico/blob/22b6cd9df78271a133fdeb2ca52bbf1a09e8836e/vetor.h#L14), o qual representa arrays dinâmicos neste estudo de caso
* Implementar as funções que correspondem as operações do array dinâmico (implemente-as em [vetor.cpp](/vetor.cpp))

## Teste do vetor dinâmico

A sua implementação do vetor dinâmico pode ser testada. Junto com o projeto CLion, existem testes das operações do vetor, então você pode realizar esses testes à medida que desenvolve as funções. Se os testes derem certo, então muito provavelmente seu vetor dinâmico está correto !

Para rodar os testes, selecione a configuração _runTest_, como indicado na figura a seguir:

![Selecionando configuração runTest](pics/clion-dynarray-config.png)

Para executar os testes, clique no botão _Run_, e observe os resultados no painel inferior do CLion:

![Execução dos testes](pics/clion-dynarray-exec-ok.png)

Além desses testes, você pode criar seus próprios testes em [main.cpp](/main.cpp). Veja que ali já há um código para realizar alguns testes do array dinâmico.
