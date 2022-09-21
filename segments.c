#include "segments.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* textFunc1(){
  return "text 1";
}

char* textFunc2(){
  return "text 2";
}

char* stackFunc2(){
  char* f2 = "stack 2";
  return f2;
}

char* stackFunc1(){
  char* f1 = "stack 1";
  stack_ptr_2 = stackFunc2();
  return f1;
}

void init_pointers()
{
  text_ptr_1 = &textFunc1;
  text_ptr_2 = &textFunc2;

  data_ptr_1 = "data 1";
  data_ptr_2 = "data 2";

  static char bss1[6];
  strcpy(bss1, "bss 1");
  bss_ptr_1 = bss1;

  static char bss2[6];
  strcpy(bss2, "bss 2");
  bss_ptr_2 = bss2;
  
  char* htemp1 = "heap 1";
  char* htemp2 = "heap 2";
  heap_ptr_1 = malloc(sizeof(char)*strlen(htemp1));
  heap_ptr_2 = malloc(sizeof(char)*strlen(htemp2));
  strcpy(heap_ptr_1, htemp1);
  strcpy(heap_ptr_2, htemp2);

  stack_ptr_1 = stackFunc1();
}

void free_pointers()
{
  free(heap_ptr_1);
  free(heap_ptr_2);
  heap_ptr_1 = NULL;
  heap_ptr_2 = NULL;
}
