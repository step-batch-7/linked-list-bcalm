#include "list.h"

void display_menu(void)
{
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n");
  printf("\nPlease enter the alphabet of the operation you would like to perform\n");
}

void give_acknowledgement(Status status)
{
  if (status == Success)
  {
    printf("\nCommand ran successfully\n");
  }
  else
  {
    printf("\nWrong command or invalid arguments\n");
  }
  printf("\n-------------------------------\n");
}

int read_number()
{
  int number;
  printf("Enter a number:");
  scanf("%d", &number);
  return number;
}

int read_position()
{
  int number;
  printf("Enter position:");
  scanf("%d", &number);
  return number;
}

void perform_action(List_ptr list)
{
  char command;
  display_menu();
  scanf("%c", &command);
  Status status = Failure;

  switch (command)
  {
  case 'a':
    status = add_to_end(list, read_number());
    break;

  case 'b':
    status = add_to_start(list, read_number());
    break;
  case 'c':
    status = insert_at(list, read_number(), read_position());
    break;

  case 'd':
    status = add_unique(list, read_number());
    break;

  case 'e':
    status = remove_from_start(list);
    break;

  case 'f':
    status = remove_from_end(list);
    break;

  case 'g':
    status = remove_at(list, read_position());
    break;

  case 'h':
    status = remove_first_occurrence(list, read_number());
    break;

  case 'i':
    status = remove_all_occurrences(list, read_number());
    break;

  case 'k':
  {
    if (has_number(list, read_number()))
    {
      printf("Number is present in the List\n");
    }
    else
    {
      printf("Number is not present in the List\n");
    }
    status = Success;
    break;
  }

  case 'l':
    display(list);
    status = Success;
    break;

  case EXIT:
    return;
    break;

  default:
    printf("Invalid option\n");
    break;
  }
  give_acknowledgement(status);
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
