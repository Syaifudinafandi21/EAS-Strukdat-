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

void tampilkan_event_berdasarkan_tanggal () {
  if (event_queue.depan == NULL) {
      printf("Tidak ada acara yang terdaftar berdasarkan tanggal.\n");
      return;
  }

event* temp = event_queue.depan;
while (temp != NULL) {
   printf("Nama       : %s\n", temp->nama);
   printf("Tanggal    : %s\n", temp->tanggal);
   printf("Deskripsi  : %s\n\n", temp->deskripsi);
   temp = temp->next;
}
}

