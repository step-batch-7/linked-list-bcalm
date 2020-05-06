#include "../list.h"
#include "list_test.h"

void run_add_to_start()
{ 
  List_ptr list = create_list();
  describe("Add to start:");
  Status status = add_to_start(list, 1);
  assert_equal(status, 1, "should add in the list when list is empty");
  assert_equal(list->head->value, 1, "should update the head");
  assert_equal(list->last->value, 1, "should update the last");
  assert_equal(list->count, 1, "should update the list count");
  
  NEW_LINE;

  status = add_to_start(list, 2);
  assert_equal(status, 1, "should add in the list when list is not empty");
  assert_equal(list->head->value, 2, "should update the head");
  assert_equal(list->last->value, 1, "should not update the last");
  assert_equal(list->count, 2, "should update the list count");
}

void run_add_to_end(){
  List_ptr list = create_list();
  describe("Add to end");
  Status status = add_to_end(list, 1);
  assert_equal(status, 1, "should add in end when list is empty");
  assert_equal(list->head->value, 1, "should update the head");
  assert_equal(list->last->value, 1, "should update the last");
  assert_equal(list->count, 1, "should update the list count");

  NEW_LINE;
  status = add_to_end(list, 2);
  assert_equal(status, 1, "should add in end when list is not empty");
  assert_equal(list->head->value, 1, "should update the head");
  assert_equal(list->last->value, 2, "should not update the last");
  assert_equal(list->count, 2, "should update the list count");
}

void run_has_number(){
  List_ptr list = create_list();
  describe("has number");
  assert_equal(has_number(list, 1), 0, "should give false when list is empty");

  NEW_LINE;
  add_to_end(list, 1);
  assert_equal(has_number(list, 1), 1, "should give true when element is present in the list");
  
  NEW_LINE;
  assert_equal(has_number(list, 2), 0, "should give false when number is not present in the list");
}

void run_add_unique(){
  List_ptr list = create_list();
  
  describe("Add unique:");

  Status status = add_unique(list, 1);
  assert_equal(status, 1, "should add when list is empty");
  assert_equal(list->head->value, 1, "should update the head");
  assert_equal(list->last->value, 1, "should update the last");
  assert_equal(list->count, 1, "should update the count");

  NEW_LINE;
  status = add_unique(list, 1);
  assert_equal(status, 0, "should not add in the list if number is already exist");
  assert_equal(list->count, 1, "should not update the count");

  NEW_LINE;
  status = add_unique(list, 2);
  assert_equal(status, 1, "should add in the last of list if element is not exist");
  assert_equal(list->last->value, 2, "should update the last value in the list");
  assert_equal(list->count, 2, "should increase the list count");
}

void run_insert_at(){
  List_ptr list = create_list();

  describe("insert at");
  Status status = insert_at(list, 1, 1);
  assert_equal(status, 0, "should not insert in invalid position");

  NEW_LINE;
  status = insert_at(list, 1, -1);
  assert_equal(status, 0, "should not insert below zeroth position");

  NEW_LINE;
  status = insert_at(list, 1, 0);
  assert_equal(status, 1, "should insert in the zeroth position");
  assert_equal(list->count, 1, "should update the list count");
  assert_equal(list->head->value, 1, "should update the head value");
  assert_equal(list->last->value, 1, "should update the last value");

  NEW_LINE;
  status = insert_at(list, 2, 1);
  assert_equal(status, 1, "should insert at end of the list");
  assert_equal(list->count, 2, "should update the list count");
  assert_equal(list->head->value, 1, "should not modify the head");
  assert_equal(list->last->value, 2, "should update the last value");
  
  NEW_LINE;
  status = insert_at(list, 3, 1);
  assert_equal(status, 1, "should insert at middle of the list");
  assert_equal(list->count, 3, "should update the list count");
  assert_equal(list->head->next->value, 3, "should insert the value");
  assert_equal(list->last->value, 2, "should update the last value");
}

void run_remove_from_start()
{ 
  List_ptr list = create_list();
  describe("Remove from start: ");
  Status status = remove_from_start(list);
  assert_equal(status, 0, "should not remove if list is empty");
  assert_equal(list->count, 0, "should not change from list");

  NEW_LINE;
  add_to_start(list, 1);
  status = remove_from_start(list);
  assert_equal(status, 1, "should remove from the last position");
  assert_equal(list->count, 0, "should clear the list");

  NEW_LINE;
  add_to_start(list, 1);
  add_to_start(list, 2);
  status = remove_from_start(list);
  assert_equal(status, 1, "should remove from the long list");
  assert_equal(list->head->value, 1, "should update the head");
  assert_equal(list->count, 1, "should remove first element");
}

void run_remove_from_end()
{ 
  List_ptr list = create_list();
  describe("Remove from end");
  Status status = remove_from_end(list);
  assert_equal(status, 0, "should not remove when list is empty");
  assert_equal(list->count, 0, "should not change from list");

  NEW_LINE;
  add_to_start(list, 1);
  status = remove_from_end(list);
  assert_equal(status, 1, "should remove from the last position");
  assert_equal(list->count, 0, "should clear the list");

  NEW_LINE;
  add_to_start(list, 1);
  add_to_start(list, 2);
  status = remove_from_end(list);
  assert_equal(status, 1, "should remove from the long list");
  assert_equal(list->head->value, 2, "should update the head");
  assert_equal(list->count, 1, "should remove first element");
}

void run_remove_at()
{ 
  List_ptr list = create_list();

  describe("remove at");
  Status status = remove_at(list, 1);
  assert_equal(status, 0, "should not remove when list is empty");
  assert_equal(list->count, 0, "should not remove in invalid position");

  NEW_LINE;
  status = remove_at(list, -1);
  assert_equal(status, 0, "should not remove for invalid position");
  assert_equal(list->count, 0, "should not remove below zeroth position");

  NEW_LINE;
  add_to_start(list, 1);
  status = remove_at(list, 0);
  assert_equal(status, 1, "should remove from 0th position");
  assert_equal(list->count, 0, "should update the list count");

  NEW_LINE;
  add_to_start(list, 1);
  add_to_start(list, 2);
  status = remove_at(list, 1);
  assert_equal(status, 1, "should remove from last position");
  assert_equal(list->count, 1, "should update the list count");
  assert_equal(list->head->value, 2, "should not modify the head");
  assert_equal(list->last->value, 2, "should update the last value");
  
  NEW_LINE;
  add_to_start(list, 1);
  add_to_start(list, 2);
  status = remove_at(list, 1);
  assert_equal(status, 1, "should remove from middle of the list");
  assert_equal(list->count, 2, "should update the list count");
}

void run_remove_first_occurrence(){
  List_ptr list = create_list();
  add_to_start(list, 1);
  add_to_start(list, 2);

  describe("Remove first occurrence:");
  Status status = remove_first_occurrence(list, 1);
  assert_equal(status, 1, "should remove the first occurrence of given number");
  assert_equal(list->count, 1, "should update the list count");

  NEW_LINE;
  status = remove_first_occurrence(list, 1);
  assert_equal(status, 0, "should not remove if given number is not present in the list");
  assert_equal(list->count, 1, "should update the list count");
}

void run_remove_all_occurrences(){
  List_ptr list = create_list();
  add_to_start(list, 1);
  add_to_start(list, 2);
  add_to_start(list, 1);
  add_to_start(list, 2);

  describe("Remove all occurrence:");
  Status status = remove_all_occurrences(list, 1);
  assert_equal(status, 1, "should remove the first occurrence of given number");
  assert_equal(list->count, 2, "should update the list count");

  NEW_LINE;
  status = remove_all_occurrences(list, 3);
  assert_equal(status, 0, "should not remove if given number is not present in the list");
  assert_equal(list->count, 2, "should update the list count");
}

void run_clear_list(){
  List_ptr list = create_list();
  add_to_start(list, 1);
  add_to_start(list, 1);
  add_to_start(list, 1);
  add_to_start(list, 1);

  describe("Clear List:");
  Status status = clear_list(list);
  assert_equal(status, 1, "should clear the list");
  assert_equal(list->count, 0, "should make list count 0");
  NEW_LINE;
  status = clear_list(list);
  assert_equal(status, 0, "should not clear the list if list has no element");
}

void runtests(){
  run_add_to_start();
  run_add_to_end();
  run_has_number();
  run_add_unique();
  run_insert_at();
  run_remove_from_start();
  run_remove_from_end();
  run_remove_at();
  run_remove_first_occurrence();
  run_remove_all_occurrences();
  run_clear_list();
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