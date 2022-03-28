/*
TRABALHO DE IMPLEMENTAÇÃO DE GRAFOS
Lucas Simões Ferreira - 20102119
Algoritmos e Estrutura de Dados II
*/

#include <stdio.h>
#include <stdlib.h>

int menu();
void adicionarVertice(int matrizAdj[20][20], int qtdVertices);
void imprimeMatriz(int matrizAdj[20][20], int qtdVertices);

int main() {
  int matrizAdj[20][20];
  int qtdVertices = 0;

  do {
    switch (menu()) {
    case 1:
      adicionarVertice(matrizAdj, qtdVertices);
      qtdVertices++;
      break;
    case 2:
      imprimeMatriz(matrizAdj, qtdVertices);
      break;
    case 3:
      printf("\nSaindo...\n\tAte mais :)\n");
      exit(0);
      break;
    default:
      printf("Opção inválida!\n");
      break;
    }

  } while (1);

  return 0;
}

int menu() {
  int escolha;
  printf("\n--- MENU ---- \n");
  printf("\t 1 - Adicionar vertice\n");
  printf("\t 2 - Mostrar Matriz de adjacencia\n");
  printf("\t 3 - Sair\n");

  printf("Insira a escolha: \n");
  scanf("%d", &escolha);
  return escolha;
}

void adicionarVertice(int matrizAdj[20][20], int qtdVertices) {
  int peso = 0;
  int index = 0;
  if (qtdVertices == 0) {
    matrizAdj[0][0] = 0;
    printf("\nPrimeiro vertice adicionado no grafo!");
  } else {
    printf("\nAdicione o peso das arestas do vertice: ");
    printf("\n(Caso nao possua aresta, peso = 0)");
    while (index < qtdVertices) {
      printf("\nAresta com o %d vertice:", index + 1);
      scanf("%d", &peso);
      matrizAdj[index][qtdVertices] = peso;
      matrizAdj[qtdVertices][index] = peso;
      index++;
    }
    matrizAdj[qtdVertices][qtdVertices] = 0;
  }
  return;
}

void imprimeMatriz(int matrizAdj[20][20], int qtdVertices) {
  if (qtdVertices == 0) {
    printf("\nNenhum vertice foi adicionado ao grafo!");
  }
  printf("   ");
  for (int i = 0; i < qtdVertices; i++) {
    printf(" V%d", i + 1);
  }
  printf("\n");
  for (int i = 0; i < qtdVertices; i++) {
    for (int j = 0; j < qtdVertices; j++) {
      if (j == 0) {
        printf(" V%d ", i + 1);
      }
      printf(" %d ", matrizAdj[i][j]);
    }
    printf("\n");
  }
}