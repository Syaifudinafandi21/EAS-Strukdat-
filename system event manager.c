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

void tambah_event (char* nama, char* tanggal, char* deskripsi){
  event* newEvent = (event*)malloc(sizeof(event));
  strcpy (newEvent -> nama, nama);
  strcpy (newEvent -> tanggal, tanggal);
  strcpy (newEvent -> deskripsi, deskripsi);
  newEvent -> next = NULL;

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

void undo_delete(){
  if(undo_stack.top == NULL){
      printf("Tidak ada acara yang bisa di-undo.\n");
      return;
  }

  event* restored_event = undo_stack.top;
  undo_stack.top = undo_stack.top->next;
  restored_event->next = NULL;
}

void dequeue() {
  if (event_queue.depan == NULL) {
      printf("Antrian kosong. Tidak ada acara selesai.\n");
      return;
  }

event* temp = event_queue.depan;
event_queue.depan = event_queue.depan->next;
