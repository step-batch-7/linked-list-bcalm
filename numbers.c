#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node_ptr create_node(int value)
{
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

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
  printf("Please enter the alphabet of the operation you would like to perform\n");
}

int main(void)
{
  List_ptr list = create_list();
  display_menu();
  return 0;
}