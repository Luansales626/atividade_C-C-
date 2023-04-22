// - Desenvolva um Programa em C++ usando comandos de repetição
// e Matriz.
// Em Nova York foi realizado um levantamento da quantidade de acidentes
// nos cruzamentos das avenidas (1ª a 10ª) com as ruas (11 a 29) nos anos de
// 2016 a 2019. Usando matriz TRIDIMENSIONAL determine os valores abaixo :

// b) Quantos acidentes ocorreram no cruzamento da 3ª avenida com a rua 27
// durante o período pesquisado ? Pesquisa por CRUZAMENTO
// c) Quais os cruzamentos com mais de 10 acidentes no período pesquisado ?
// Pesquisa por QTDE
// d) Qual o cruzamento mais perigoso de todos, e em que ano ocorreu ?

// ************************************************************************
// PROGRAMA: PARA LER OS ACIDENTES NO ARQUIVO TXT E TRANSFORMAR EM INTEIROS
//           EM VERSÕES MAIS MODERNAS DO C++, VOCÊ PODE USAR STOI() PARA
//           CONVERTER STRING PARA INTEIROS, NA MINHA VERSÃO USEI CAST()
// ************************************************************************
#include <string>
// #include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <typeinfo>

#include "item1.cpp"
using namespace std;

int main(int argc, char *argv[])
{
  FILE *arq;
  char Linha[11];
  char *result;
  int i, mat;
  int av1, r1, a1, qt1;
  struct acidente
  {
    string(av);
    string(rua);
    string(ano);
    string(qt);
  };
  acidente a;
  system("cls");
  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("ACIDENTES.txt", "rt");
  if (arq == NULL)
  {
    printf("Problemas na abertura do arquivo\n");
    system("pause");
    return 0;
  }
  i = 1;
  cout << "AV "
       << "R "
       << "AN "
       << "QT\n";
  while (!feof(arq))
  {
    // Lê uma linha (inclusive com o '\n')
    result = fgets(Linha, 100, arq); // o 'fgets' lê até 99 ou até o '\n'
    if (result)
    {
      a.av = string(Linha, 2);
      av1 = ((static_cast<int>(a.av[0]) - 48) * 10) + static_cast<int>(a.av[1]) - 48;
      a.rua = string(Linha + 2, 2);
      r1 = ((static_cast<int>(a.rua[0]) - 48) * 10) + static_cast<int>(a.rua[1]) - 48;
      a.ano = string(Linha + 4, 4);
      a1 = ((static_cast<int>(a.ano[2]) - 48) * 10) + static_cast<int>(a.ano[3]) - 48;
      a.qt = string(Linha + 8, 2);
      qt1 = ((static_cast<int>(a.qt[0]) - 48) * 10) + static_cast<int>(a.qt[1]) - 48;

      // cout << av1 << " " << r1 << " " << a1 << " " << qt1 << "\n";
      //    A partir daqui é com vocês ..............

      Items::acidentesNaOitavaAvenidaEm2018(av1, a1, qt1);
    }
    i++;
  }
  fclose(arq);
  system("pause");
}
