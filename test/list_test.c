#include "../list.h"
#include "list_test.h"

void print_status(Status status)
{
  if (status)
    printf("✅");
  else
    printf("❌");
}

void run_add_to_start(){
  List_ptr list = create_list();
  Status flag = add_to_start(list, 1);
  Status isElementInserted = list->head->value ==1 && list->last->value == 1;
  Status isCountIncreased = list->count == 1;
  Status status = flag && isCountIncreased && isElementInserted;
  print_status(status);
  printf(" Should add to the start of the list when list is empty\n");
  flag = add_to_start(list, 2);
  isElementInserted = list->head->value ==2 && list->last->value == 1;
  isCountIncreased = list->count == 2;
  status = flag && isCountIncreased && isElementInserted;
  print_status(status);
  printf(" Should add to the start of the list when list is not empty\n");
}

void run_add_to_end(){
  List_ptr list = create_list();
  Status flag = add_to_end(list, 1);
  Status isElementInserted = list->head->value ==1 && list->last->value == 1;
  Status isCountIncreased = list->count == 1;
  Status status = flag && isCountIncreased && isElementInserted;
  print_status(status);
  printf(" Should add to the end of the list when list is empty\n");
  flag = add_to_end(list, 2);
  isElementInserted = list->head->value ==1 && list->last->value == 2;
  isCountIncreased = list->count == 2;
  status = flag && isCountIncreased && isElementInserted;
  print_status(status);
  printf(" Should add to the end of the list when list is not empty\n");
}

void run_has_number(){
  List_ptr list = create_list();
  print_status(!has_number(list, 1));
  printf(" Should give false if number is not present in the list and list is empty\n");
  add_to_start(list, 2);
  print_status(has_number(list, 2));
  printf(" Should give true if number is present in the list\n");
  print_status(!has_number(list, 3));
  printf(" Should give false if number is present in the list and list is not empty\n");
}

void run_add_unique(){
  List_ptr list = create_list();
  Status flag = add_unique(list, 1);
  Status isElementInserted = list->head->value ==1 && list->last->value == 1;
  Status isCountIncreased = list->count == 1;
  Status status = flag && isCountIncreased && isElementInserted;
  print_status(status);
  printf(" Should add to the element when element is not present in the list\n");
  flag = add_unique(list, 1);
  isElementInserted = list->head->value ==1 && list->last->value == 1;
  isCountIncreased = list->count == 1;
  status = flag && isCountIncreased && isElementInserted;
  print_status(!status);
  printf(" Should not add in the list when element is already present in the list\n");
}

void runtests(){
  run_add_to_start();
  run_add_to_end();
  run_has_number();
  run_add_unique();
}


int main(void)
{
  printf("Testing start\n");
  printf(".............\n");
  runtests();
  printf(".............\n");
  printf("Testing end\n");
  return 0;
}