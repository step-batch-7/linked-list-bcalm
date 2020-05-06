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

#endif