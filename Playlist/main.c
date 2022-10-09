#include <stdio.h>
#include <stdlib.h>
#include "song.h"
#include "insertion.h"
#include "playing.h"

int main()
{
    printf("\nWelcome to the Music player!!!\n");
    initialize();
    int select;
selection:
    printf("\n\n--------MENU--------\n");
    printf("\n1. ADD A SONG\n");
    printf("\n2. REMOVE A SONG\n");
    printf("\n3. DISPLAY PLAYLIST\n");
    printf("\n4. PLAY ALL SONGS\n");
    printf("\n5. COUNT ALL SONGS\n");
    printf("\n6. EXIT\n");
    printf("---------\n");

    scanf("%d", &select);

    if (select == 1)
        insert();

    else if (select == 2)
        delete_song();

    else if (select == 3)
        display();

    else if (select == 4)
        play();
    else if (select == 5)
    {  
        count_songs();
        printf("\n TOTAL SONGS - %d ", song_count);
    }
    else
        goto thankyou;
    goto selection;
thankyou:
    system("clear");
    printf("\nThank you for using our application");
    printf("\u263A\n");
    exit(0);
}
