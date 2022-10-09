/*
The header file for insertion and deletion of songs from the playlist
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"

#ifndef DEL
#define DEL

// Inserting a song at the end of the playist
void insert()
{
  printf("Enter name of the song: \n");
  while (getchar() != '\n')
    ;
  scanf("%[^\n]%*c", temp);
  printf("\nEnter the song duration: ");
  scanf("%u", &song_time);
  Song *new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for new node
  strcpy(new_node->song, temp);
  new_node->song_time = song_time;
  // Adding the new node to current node
  if (head == NULL)
  {
    new_node->next = new_node->previous = new_node;
    head = current_node = new_node;
    return;
  }
  struct node *last = head->previous;
  new_node->previous = last;
  last->next = new_node;
  new_node->next = head;
  head->previous = new_node;
};

// Deleting a song at the end of the playist
void delete_song()
{
  if (head == NULL)
  {
    printf("There is no in this playlist!!\n");
    return;
  }
  printf("\nAvailable songs in the playlist\n");
  display();
  printf("\nEnter name of the song need to be deleted: ");
  while (getchar() != '\n')
    ;
  scanf("%[^\n]%*c", temp);
  Song *ptr = head;
  // check the song from the playlist
  do
  {
    if (ptr->next == ptr && strcmp(ptr->song, temp) == 0)
    {
      printf("ONE SONG DELETED\n");
      printf("PLAYLIST IS EMPTY NOW.");
      head == NULL;
      free(ptr);
      return;
    }
    else if (strcmp(ptr->song, temp) == 0)
    {
      struct node *previous = ptr->previous;
      struct node *next = ptr->next;
      previous->next = next;
      next->previous = previous;
      head = next;
      free(ptr);
      printf("SONG IS DELETED SUCCESSFULLY\n");
      return;
    }
    ptr = ptr->next;
  } while (ptr != head);
  printf("The indicated song is not present\n");
}
#endif