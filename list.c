#include "list.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
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

void display(List_ptr list)
{
  if (list->head == NULL)
  {
    printf("List is empty \n");
    return;
  }
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("Value is %d\n", p_walk->value);
    p_walk = p_walk->next;
  }
}

Status remove_from_start(List_ptr list)
{
  if (list->head == NULL)
  {
    return Failure;
  }
  Node_ptr next_node = list->head->next;
  free(list->head);
  list->head = next_node;
  list->count--;
  return Success;
}

Status remove_from_end(List_ptr list)
{
  if (list->head == NULL)
  {
    return Failure;
  }
  list->count--;
  if (list->head->next == NULL)
  {
    free(list->head);
    list->head = NULL;
    return Success;
  }

  Node_ptr current = list->head;
  while (current->next->next != NULL)
  {
    current = current->next;
  }

  free(current->next);
  current->next = NULL;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node == NULL || list->count + 1 < position || position <= 0)
  {
    return Failure;
  }
  new_node->value = value;
  new_node->next = NULL;

  if (position == 1)
  {
    return add_to_start(list, value);
  }

  Node_ptr current = list->head;
  for (int count = 1; count < position - 1; count++)
  {
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
  list->count++;
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if (list->head == NULL || list->count < position || position <= 0)
  {
    return Failure;
  }
  list->count--;
  if (position == 1)
  {
    return remove_from_start(list);
  }
  Node_ptr current = list->head;
  for (int count = 1; count < position - 1; count++)
  {
    current = current->next;
  }

  Node_ptr removed_node = current->next;
  Node_ptr next_node = removed_node->next;
  current->next = next_node;
  free(removed_node);
  return Success;
}
