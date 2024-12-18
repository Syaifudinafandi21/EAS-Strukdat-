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

  if (event_list == NULL){
    event_list = newEvent;
    event_list -> next = event_list;
  } else {
    event* temp = event_list;
    while (temp -> next != event_list) {
      temp = temp -> next;
    }
  temp -> next = newEvent;
  newEvent -> next = event_list;
  }
}

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

void hapus_event(char* nama){
  if (event_list == NULL){
    printf("tidak ada acara untuk dihapus");
    return;
  }

  event *temp = event_list, *prev = NULL;
   do {
        if (strcmp(temp->nama, nama) == 0) {
            if (temp == event_list) {
                if (temp->next == temp) { 
                    event_list = NULL;
                } else {
                    event* last = event_list;
                    while (last->next != event_list) {
                        last = last->next;
                    }
                    event_list = event_list->next;
                    last->next = event_list;
                }
            } else {
                prev->next = temp->next;
            }
           event *curr = event_queue.depan, *queue_prev = NULL;
            while (curr != NULL) {
                if (strcmp(curr->nama, nama) == 0) {
                    if (queue_prev == NULL) {
                        event_queue.depan = curr->next;
                        if (event_queue.depan == NULL) {
                            event_queue.belakang = NULL;
                        }
                    } else {
                        queue_prev->next = curr->next;
                        if (queue_prev->next == NULL) {
                            event_queue.belakang = queue_prev;
                        }
                    }
                    free(curr);
                    break;
                }
                queue_prev = curr;
                curr = curr->next;
            }
          temp->next = undo_stack.top;
          undo_stack.top = temp;

          printf("acara '%s' telah dihapus.\n", nama);
          return;
        }
        prev = temp;
        temp = temp->next;
   }while (temp != event_list);
    printf("acara '%s' tidak ditemukan.\n", nama);
}
          
void enqueue(char* nama, char* tanggal, char* deskripsi) {
    event* newEvent = (event*)malloc(sizeof(event));
    strcpy(newEvent->nama, nama);
    strcpy(newEvent->tanggal, tanggal);
    strcpy(newEvent->deskripsi, deskripsi);
    newEvent->next = NULL;

    if (event_queue.depan == NULL || strcmp(newEvent->tanggal, event_queue.depan->tanggal) < 0) {
        newEvent->next = event_queue.depan;
        event_queue.depan = newEvent;
        if (event_queue.belakang == NULL) {
            event_queue.belakang = newEvent;
        }
    } else {
        event* temp = event_queue.depan;
        while (temp->next != NULL && strcmp(newEvent->tanggal, temp->next->tanggal) >= 0) {
            temp = temp->next;
        }
        newEvent->next = temp->next;
        temp->next = newEvent;
        if (newEvent->next == NULL) {
            event_queue.belakang = newEvent;
        }
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

  if(event_list == NULL){
      event_list == restored_event;
      event_list->next = event_list;
  }else{
      event* temp = event_list;
      event* prev = NULL;

    do{
      if(strcmp(restored_event->tanggal, temp->tanggal) < 0){
          break;
      }
      prev = temp;
      temp = temp->next;
    }while (temp != event_list);
  }
}

void dequeue() {
  if (event_queue.depan == NULL) {
      printf("Antrian kosong. Tidak ada acara selesai.\n");
      return;
  }

event* temp = event_queue.depan;
event_queue.depan = event_queue.depan->next;
