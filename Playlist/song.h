/*
The header file for storing the Song information.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

#ifndef SONG
#define SONG

// defining the song structure which will be called as node
// to the linked list

typedef struct node
{
    char song[MAX_SIZE];
    struct node *next;
    struct node *previous;
    unsigned int song_time;
} Song;

// Declaring variable that will store our songs information

char temp[MAX_SIZE];
unsigned int song_time;
struct node *head;
Song *current_node;
int song_count;

// Initializing the song pointers
void initialize()
{
    head = NULL;
    current_node = NULL;
};

// Displaying the playlist contents.
void display()
{
    if (head == NULL)
    {
    printf("THE PLAYLIST IS EMPTY!!\n");
    return;
    }
    Song *display_ptr = head;
    int i = 1;
    printf("DISPLAYING PLAYLIST: \n");
    printf("\nSr.No| SONG NAME | Duration\n");
    printf("------------------------------\n");
    do
    {
    printf(" %d       %s             %u\n", i, display_ptr->song, display_ptr->song_time);
    i++;
    display_ptr = display_ptr->next;
    } while (display_ptr != head);
    free(display_ptr);
};

// Counting the number of songs available in the playlist.
void count_songs()
{
    if (head == NULL)
    {
      printf("THE PLAYLIST IS EMPTY!!\n");
      return;
    }
    Song *songs = head;
    int i = 1;
    do
    {
      i++;
      songs = songs->next;
    } while (songs != head);
    song_count = i-1;
};
#endif