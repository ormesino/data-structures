#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct List
{
  int num;
  struct List *next;
} List;

void insert(int x, List **pt)
{
  List *newNode = malloc(sizeof(List));
  newNode->next = *pt;
  newNode->num = x;
  *pt = newNode;
}

void topSort(List **adj, int vertices)
{
  List *pt;
  int beginning = 0;
  int end = 0;

  int *gent = malloc(sizeof(int) * (1 + vertices));
  int *sequence = malloc(sizeof(int) * vertices);

  for (int i = 1; i <= vertices; i++) {
    gent[i] = 0;
  }

  for (int i = 0; i < vertices; i++){
    sequence[i] = 0;
  }

  for (int i = 1; i <= vertices; i++)
  {
    pt = adj[i];

    while (pt != NULL)
    {
      gent[pt->num]++;
      pt = pt->next;
    }
  }

  for (int i = 1; i <= vertices; i++)
  {
    if (gent[i] == 0)
    {
      sequence[end] = i;
      end++;
    }
  }

  while (beginning != end)
  {
    int v = sequence[beginning];
    beginning++;
    pt = adj[v];

    while (pt != NULL)
    {
      gent[pt->num]--;

      if (gent[pt->num] == 0)
      {
        sequence[end] = pt->num;
        end++;
      }

      pt = pt->next;
    }
  }

  for (int i = 0; i < vertices; i++)
    printf("%d ", sequence[i]);
}

int main(int argc, char **argv)
{
  char entrys[500];
  char *token;
  char temp;
  int vertices, edges;

  scanf("%[^\n]", entrys);
  sscanf(entrys, "%d %d", &vertices, &edges);
  scanf("%c", &temp);

  List **adj = malloc(sizeof(List *) * (vertices + 1));

  for (int i = 0; i <= vertices; i++){
    adj[i] = NULL;
  }

  entrys[0] = '\0';
  for (int i = 1; i <= vertices; i++)
  {
    scanf("%[^\n]", entrys);
    token = strtok(entrys, " ");

    if (token != NULL)
    {
      insert(atoi(token), &adj[i]);
    }

    while (token != NULL)
    {
      token = strtok(NULL, " ");

      if (token != NULL)
      {
        insert(atoi(token), &adj[i]);
      }
    }

    scanf("%c", &temp);
    entrys[0] = '\0';
  }

  topSort(adj, vertices);
}