/*
The header file for playing functionalities of the Music Player.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"
#include <time.h>

#ifndef PLAY
#define PLAY

// Delay for playing the song
void time_delay(unsigned int song_time)
{
  unsigned int retTime = time(0) + song_time;
  while (time(0) < retTime)
    ;
}

// Playing the song from the playlist
void play()
{
  if (head == NULL)
  {
    printf("THE PLAYLIST IS EMPTY!!\n");
    return;
  }
  Song *play_song = head;
  int i = 1;
  printf("\nPlaying the songs from the playlist\n\n");
  printf("Current Playing|  Duration\n");
  printf("---------------------------\n");
  do
  {
    printf(" %s               %u\n", play_song->song, play_song->song_time);
    time_delay(play_song->song_time);
    i++;
    play_song = play_song->next;
  } while (play_song != head);
}

#endif