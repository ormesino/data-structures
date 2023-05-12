#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *next;
} Node;

Node *push(Node *top)
{
  Node *new = malloc(sizeof(Node));
  int value;
  printf("\nDigite o valor desejado:\n");
  scanf("%d", &value);

  if (new)
  {
    new->key = value;
    new->next = top;
    top = new;
    return new;
  }
  else
  {
    printf("\nFalha ao inserir um novo elemento na pilha...\n");
    return NULL;
  }
}

void pop(Node **top)
{
  if (*top)
  {
    Node *remove = *top;
    *top = remove->next;
    free(remove);
  }
  else
    printf("\nSem elementos na pilha...\n");
}

void printStack(Node *top)
{
  printf("\nInicio da pilha:\n");
  while (top)
  {
    printf("\t%d\t", top->key);
    top = top->next;
  }
}

int main(int argc, char const *argv[])
{
  Node *top = NULL;
  int opcao = 0;
  while (opcao != 4)
  {
    printf("\nEscolha uma das opcoes:\n1 - Empilhar\n2 - Remover\n3 - Imprimir a pilha\n4 - Sair\n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
      top = push(top);
      break;
    case 2:
      pop(&top);
      break;
    case 3:
      printStack(top);
      break;

    default:
      break;
    }
  }

  return 0;
}
