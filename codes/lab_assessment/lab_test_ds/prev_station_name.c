/* function to findout the previous station */

#include "headers.h"

char *prev_station_name (station_details *head)
{
    int index = 0;
    station_details *station1 = NULL; //pointer to traverse
    char *str = NULL;

    str = (char *) malloc (MAX_ARR_SIZE);
    assert (str); //validating the pointer

    fprintf (stdout, "enter the station code to know previous station\n");
    fgets (str, MAX_ARR_SIZE, stdin);

    while (*(str + index) != '\0'){  //to eliminate the \n from the string
        if (*(str + index) == '\n'){
            *(str + index) == '\0';
            break;
        }
        index++;
    }

    station1 = head; //to traverse

    while (station1 != NULL){     //traverse till we found the string entered
         if (strcmp (station1 -> station_code, str) == 0){ // comparing strings
            station1 = station1 -> prev;
            break;
        }
        station1 = station1 -> next;
    }
    
    str = station -> station_code;

    return str; // returning the previous station code
}
