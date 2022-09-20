#include "segments.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* textFunc1(){
  char* p = malloc(sizeof(char)*strlen("text 1"));
  strcpy(p,"text 1");
  return p;
}

char* textFunc2(){
  char* p = malloc(sizeof(char)*strlen("text 2"));
  strcpy(p,"text 2");
  return p;
}

char* stackFunc1(){
  char* f1;
  f1 = "stack 1";
  return f1;
}

char* stackFunc2(){
  char* f2;
  f2 =  "stack 2";
  return f2;
}

void init_pointers()
{
  char* temp1 = "heap 1";
  char* temp2 = "heap 2";
  heap_ptr_1 = malloc(sizeof(char)*strlen(temp1));
  heap_ptr_2 = malloc(sizeof(char)*strlen(temp2));
  strcpy(heap_ptr_1, temp1);
  strcpy(heap_ptr_2, temp2);

  static char* global1 = "data 1";
  static char* global2 = "data 2";
  data_ptr_1 = global1;
  data_ptr_2 = global2;

  bss_ptr_1 = "bss 1";
  bss_ptr_2 = "bss 2";

  text_ptr_1 = &textFunc1;
  text_ptr_2 = &textFunc2;
   
  stack_ptr_1 = stackFunc1();
  stack_ptr_2 = stackFunc2();
  
}

void free_pointers()
{
  free(heap_ptr_1);
  free(heap_ptr_2);
  heap_ptr_1 = NULL;
  heap_ptr_2 = NULL;

  /* char* tp1;
  char* tp2;
  tp1 = 
  tp2 = 
  free(*text_ptr_1);
  free(*text_ptr_2);
  text_ptr_1 = NULL;
  text_ptr_2 = NULL;*/
}
