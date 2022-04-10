#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INFINITO 99999

void algoritmoDjikstra(int verticeDestino, int verticeOrigem, int matrizAdj[MAX][MAX], int qtdVertices);
int menu();

int main() {
  int qtdVertices = 0, matrizAdj[MAX][MAX], verticeOrigem, verticeDestino;

  do {
    switch (menu()) {
    case 1:
      do {
        printf("\nInsira o numero de vertices (entre 2 e %d): ", MAX);
        scanf("%d", &qtdVertices);
      } while (qtdVertices < 2 || qtdVertices > MAX);
      for (int i = 0; i < qtdVertices; i++) {
        for (int j = 0; j < qtdVertices; j++) {
          if (j <= i) {
            matrizAdj[i][j] = 0;
          } else {
            do {
              printf("\nPeso entre o vertice %d e vertice %d: ", i + 1, j + 1);
              scanf("%d", &matrizAdj[i][j]);
            } while (matrizAdj[i][j] < 0);
          }
        }
      }
      break;
    case 2:
      if (qtdVertices == 0) {
        printf("\nNao ha vertices do grafo!");
      } else {
        do {
          printf("\nInsira o vertice de origem: ");
          scanf("%d", &verticeOrigem);
        } while (verticeOrigem < 1 || verticeOrigem > MAX);
        do {
          printf("\nInsira o vertice de destino: ");
          scanf("%d", &verticeDestino);
        } while ((verticeDestino < 1 || verticeDestino > MAX) && verticeDestino == verticeOrigem);
        verticeDestino--;
        verticeOrigem--;
        algoritmoDjikstra(verticeDestino, verticeOrigem, matrizAdj, qtdVertices);
      }
      break;
    case 3:
      printf("\nSaindo...\n\tAte mais :)\n");
      exit(0);
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }

  } while (1);
}

void algoritmoDjikstra(int verticeDestino, int verticeOrigem, int matrizAdj[MAX][MAX], int qtdVertices) {
  int distancias[qtdVertices], visitados[qtdVertices];
  int contador = 0;
  int indexMenorDistancia = verticeOrigem, menorDistancia;

  for (int i = 0; i < qtdVertices; i++) {
    distancias[i] = INFINITO;
    visitados[i] = 0;
  }

  distancias[verticeOrigem] = 0;
  contador++;

  while (contador < qtdVertices) {
    menorDistancia = INFINITO;

    for (int i = 0; i < qtdVertices; i++) {
      if (distancias[i] < menorDistancia && visitados[i] == 0) {
        menorDistancia = distancias[i];
        indexMenorDistancia = i;
      }
    }

    visitados[indexMenorDistancia] = 1;

    for (int i = 0; i < qtdVertices; i++) {
      if (matrizAdj[indexMenorDistancia][i] != 0) {
        if (visitados[i] == 0) {
          if (menorDistancia + matrizAdj[indexMenorDistancia][i] < distancias[i]) {
            distancias[i] = menorDistancia + matrizAdj[indexMenorDistancia][i];
          }
        }
      }
    }
    contador++;
  }

  if (distancias[verticeDestino] == INFINITO) {
    printf("Nao tem caminhos validos\n");
  } else {
    printf("A menor distancia entre o vertice %d e o vertice %d: %d\n", verticeOrigem + 1, verticeDestino + 1, distancias[verticeDestino]);
  }
}

int menu() {
  int escolha;
  printf("\n--- MENU ---- \n");
  printf("\t 1 - Inserir o peso das arestas do grafo\n");
  printf("\t 2 - Buscar menor caminho entre dois vertices\n");
  printf("\t 3 - Sair\n");

  printf("Insira a escolha: \n");
  scanf("%d", &escolha);
  return escolha;
}