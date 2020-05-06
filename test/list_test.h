#ifndef __LIST_TEST_H
#define __LIST_TEST_H

typedef char * Char_ptr;
#define NEW_LINE printf("\n")

void print_status(Status);
void assert_equal(int, int, Char_ptr);
void describe(Char_ptr);
void runtests();
void run_add_to_start();
void run_add_to_end();
void run_has_number();
void run_add_unique();
void run_insert_at();
void run_remove_from_start();
void run_remove_from_end();
void run_remove_at();
void run_remove_first_occurrence();
void run_remove_all_occurrences();
void run_clear_list();

#endif