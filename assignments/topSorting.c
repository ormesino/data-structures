#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  int degree;
  int next[10];
} Node;

int main(int argc, char const *argv[])
{
  int vertices, edges;
  int result[vertices];
  char line[500];

  scanf("%d %d", &vertices, &edges);
  Node *graph[vertices];
  getchar();

  for (int i = 0; i < vertices; i++)
  {
    graph[i] = (Node *)malloc(sizeof(Node));
    graph[i]->degree = 0;
  }

  for (int i = 0; i < vertices; i++)
  {

    fgets(line, 100, stdin);

    char *token = strtok(line, " ");
    int j = 0;
    while (token != NULL)
    {
      if (token[0] == '\n')
      {
        break;
      }
      int value = atoi(token);
      graph[value - 1]->degree++;
      graph[i]->next[j] = value;
      j++;

      token = strtok(NULL, " ");
    }
  }

  for (int i = 0; i < vertices; i++)
  {
    printf("Nó %i tem o grau: %d\n", i + 1, graph[i]->degree);
  }

  // Ainda falta o restante
  return 0;
}