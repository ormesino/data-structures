#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int key;
  struct node *next;
} Node;

void push(Node *top)
{
  Node *new = malloc(sizeof(Node));
  int temp;
  printf("\nDigite o valor desejado:\n");
  scanf("%d", &temp);

  if (new)
  {
    new->key = temp;
    new->next = top;
    top = new;
  }
  else
  {
    printf("\nFalha ao inserir um novo elemento na pilha...\n");
    return NULL;
  }
}

int main(int argc, char const *argv[])
{
  Node *top = NULL;
  int opcao = 0;
  while (opcao != 3)
  {
    printf("\nEscolha uma das opcoes:\n1 - Empilhar\n2 - Remover\n3 - Sair\nR: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
      push(top);
      break;
    case 2:
      break;

    default:
      break;
    }
  }

  return 0;
}
