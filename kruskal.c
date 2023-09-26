#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Edge
{
  int first;
  int second;
  int weight;
} Edge;

void merge(Edge *arr, int start, int mid, int size);
void mergeSort(Edge *arr, int start, int size);
int find(int *set, int x);
bool Union(int *set, int *rank, int a, int b);

int main(int argc, char **argv)
{
  char aux;
  int numVert, numEdges;
  int first, second, weight;

  scanf("%d %d", &numVert, &numEdges);
  scanf("%c", &aux);

  Edge *edges = malloc(sizeof(Edge) * numEdges);

  int *rank = malloc(sizeof(int) * (numVert + 1));
  int *set = malloc(sizeof(int) * (numVert + 1));

  for (int i = 0; i < numEdges; i++)
  {
    scanf("%d %d %d", &first, &second, &weight);
    edges[i].first = first;
    edges[i].second = second;
    edges[i].weight = weight;
    scanf("%c", &aux);
  }

  mergeSort(edges, 0, numEdges);

  for (int i = 1; i <= numVert; i++)
  {
    set[i] = i;
    rank[i] = 0;
  }

  int sumWeights = 0;

  for (int i = 0; i < numEdges; i++)
    if (Union(set, rank, edges[i].first, edges[i].second))
      sumWeights += edges[i].weight;

  printf("%d", sumWeights);

  free(edges);
  free(rank);
  free(set);
}

void merge(Edge *arr, int start, int mid, int size)
{
  int i, j, pos;
  Edge *aux;

  aux = malloc((size - start) * sizeof(Edge));

  i = start;
  j = mid;
  pos = 0;

  while (i < mid && j < size)
  {
    if (arr[i].weight <= arr[j].weight)
    {
      aux[pos] = arr[i];
      i++;
    }
    else
    {
      aux[pos] = arr[j];
      j++;
    }

    pos++;
  }

  while (i < mid)
  {
    aux[pos] = arr[i];
    pos++;
    i++;
  }

  while (j < size)
  {
    aux[pos] = arr[j];
    pos++;
    j++;
  }

  for (i = start; i < size; i++)
    arr[i] = aux[i - start];

  free(aux);
}

void mergeSort(Edge *arr, int start, int size)
{
  if (start < size - 1)
  {
    int mid = (start + size) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid, size);
    merge(arr, start, mid, size);
  }
}

int find(int *set, int vert)
{
  if (vert != set[vert])
    set[vert] = find(set, set[vert]);
  return set[vert];
}

bool Union(int *set, int *rank, int first, int second)
{
  first = find(set, first);
  second = find(set, second);

  if (first != second)
  {
    if (rank[first] < rank[second])
      set[first] = second;
    else
    {
      set[second] = first;
      if (rank[first] == rank[second])
        rank[first] += 1;
    }

    return true;
  }

  return false;
}