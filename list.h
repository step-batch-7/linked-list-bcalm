#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>
#define EXIT 'm'

typedef enum
{
  False,
  True
} Boolean;

typedef enum
{
  Failure,
  Success
} Status;

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node *head;
  Node *last;
  int count;
} List;

typedef List *List_ptr;

List_ptr create_list(void);
void display_menu(void);
void perform_action(List_ptr);
int read_number(void);
int read_position(void);
void give_acknowledgement(Status);
Boolean has_number(List_ptr, int);

Status add_to_end(List_ptr, int value);
Status add_to_start(List_ptr, int value);
Status insert_at(List_ptr, int value, int position);
Status add_unique(List_ptr, int value);

void display(List_ptr);

Status remove_from_start(List_ptr);
Status remove_from_end(List_ptr);
Status remove_at(List_ptr, int position);

Status remove_first_occurrence(List_ptr, int value);
Status remove_all_occurrences(List_ptr, int value);

Status clear_list(List_ptr); // Removes all elements in the list

void destroy_list(List_ptr); // Frees the elements and the list structure from memory

#endif