#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

void display_menu(void)
{
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(m) exit\n");
  printf("\nPlease enter the alphabet of the operation you would like to perform\n");
}

Status add_to_end(List_ptr list, int number)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node == NULL)
  {
    return Failure;
  }
  new_node->value = number;
  new_node->next = NULL;
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count += 1;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node == NULL)
  {
    return Failure;
  }
  new_node->value = value;
  new_node->next = list->head;
  list->head = new_node;
  list->count++;
  return Success;
}

void perform_action(List_ptr list)
{
  char command;
  display_menu();
  scanf("%c", &command);

  if (command == EXIT)
  {
    return;
  }
  if (command == 'a')
  {
    int number;
    printf("Enter a number:");
    scanf("%d", &number);
    Status status = add_to_end(list, number);
  }
  if (command == 'b')
  {
    int number;
    printf("Enter a number:");
    scanf("%d", &number);
    Status status = add_to_start(list, number);
  }

  while ((getchar()) != '\n')
    ;
  return perform_action(list);
}

int main(void)
{
  char command;
  List_ptr list = create_list();
  perform_action(list);
  return 0;
}