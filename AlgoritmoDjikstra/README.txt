Trabalho implementação do algoritmo Dijsktra

---Informações---

Lucas Simões Ferreira - 20102119
lsferreira@inf.ufpel.edu.br
https://github.com/lcsferreira/AED2/tree/master/AlgoritmoDjikstra

---Enunciado---

Implementar um programa C para calcular os caminhos mínimos entre os vértices de um grafo utilizando o algoritmo de Dijsktra

1- Permitir o armazenamento de até 20 vértices

2- Fazer a leitura dos pesos das arestas de cada vértice

3- Considerar sempre vértices positivos

4- Mostrar o caminho mínimo entre ddois vértices solicitados

--- Desenvolvimento ---

O usuário irá inserir a quantidade de vértices do grafo e irá digitar o peso da aresta entre cada vértice.
O programa foi pensado montando uma matriz de adjacência e utilizando ela para procurar os caminohs mínimos.

é utilizado um vetor de visitados que indica quais vértices ja foram visitados em busca do menor caminho. Um vetor de distancias que armazena a menor distancia entre um vertice em relação a todos os outros do grafo.

INFINITO representa que não há ligação entre os dois vértices indicados, assim como informa o programa.
