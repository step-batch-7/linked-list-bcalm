#include "list.h"

void display_menu(void)
{
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n");
  printf("\nPlease enter the alphabet of the operation you would like to perform\n");
}

int read_number()
{
  int number;
  printf("Enter a number:");
  scanf("%d", &number);
  return number;
}

void perform_action(List_ptr list)
{
  char command;
  display_menu();
  scanf("%c", &command);

  switch (command)
  {
  case a:
  {
    Status status = add_to_end(list, read_number());
    break;
  }

  case b:
  {
    Status status = add_to_start(list, read_number());
    break;
  }

  case e:
  {
    Status status = remove_from_start(list);
    break;
  }

  case f:
  {
    Status status = remove_from_end(list);
    break;
  }

  case l:
  {
    display(list);
    break;
  }

  case m:
    return;
    break;

  default:
    printf("Invalid option\n");
    break;
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
