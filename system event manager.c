#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct event {
  char nama[50];
  char tanggal[20];
  char deskripsi[1000];
  struct event* next;
} event;
event* event_list = NULL;

typedef struct queue {
  event* depan;
  event* belakang;
} queue;
queue event_queue = {NULL, NULL};

typedef struct stack {
  event* top;
} stack;
stack undo_stack = {NULL};


