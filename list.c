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
  Node_ptr *ptr_to_set = &list->head;
  if (list->head != NULL)
  {
    ptr_to_set = &list->last->next; 
  }
  (*ptr_to_set) = new_node; 
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

  if(list->count == 0){
    list->last = new_node;
  }
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
    printf("Element is %d\n", p_walk->value);
    p_walk = p_walk->next;
  }
  printf("Total elements in list is/are %d", list->count);
}

Status remove_from_start(List_ptr list)
{
  if (list->head ==NULL){
    return Failure;
  }
  Node_ptr first_node = list->head;
  list->head = first_node->next;
  free(first_node);
  list->count -= 1;
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
    list->last = NULL;
    return Success;
  }

  Node_ptr current = list->head;
  while (current->next->next != NULL)
  {
    current = current->next;
  }

  free(current->next);
  current->next = NULL;
  list->last = current;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node == NULL || list->count < position || position < 0)
  {
    return Failure;
  }
  new_node->value = value;
  new_node->next = NULL;

  if (position == 0)
  {
    return add_to_start(list, value);
  }

  Node_ptr current = list->head;
  for (int count = 0; count < position - 1; count++)
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
  if (list->head == NULL || list->count - 1 < position || position < 0)
  {
    return Failure;
  }
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position == list->count-1)
  {
    return remove_from_end(list);
  }
  Node_ptr current = list->head;
  for (int count = 0; count < position - 1; count++)
  {
    current = current->next;
  }

  Node_ptr removed_node = current->next;
  Node_ptr next_node = removed_node->next;
  current->next = next_node;
  free(removed_node);
  list->count--;
  return Success;
}

Boolean has_number(List_ptr list, int number)
{
  Node_ptr p_walk = list->head;
  int count = 1;
  while (count <= list->count)
  {
    if (p_walk->value == number)
    {
      return True;
    }
    count++;
    p_walk = p_walk->next;
  }
  return False;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  if (!has_number(list, value))
  {
    return Failure;
  }
  Node_ptr p_walk = list->head;
  int count = 0;
  while (count <= list->count)
  {
    if (p_walk->value == value)
    {
      break;
    }
    count++;
    p_walk = p_walk->next;
  }
  return remove_at(list, count);
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Status status = remove_first_occurrence(list, value);

  if (!has_number(list, value))
  {
    return status;
  }

  return remove_all_occurrences(list, value);
}

Status add_unique(List_ptr list, int value)
{
  if (has_number(list, value))
  {
    return Failure;
  }
  return add_to_end(list, value);
}

Status clear_list(List_ptr list)
{
  Status status = remove_from_end(list);
  if (list->count == 0)
  {
    return status;
  }
  return clear_list(list);
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
}