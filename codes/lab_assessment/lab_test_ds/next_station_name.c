/* function to findout the next coming station */

#include "headers.h"

char *next_station_name (station_details *head)
{
    int index = 0;
    station_details *station1 = NULL; //pointer to traverse
    char *str = NULL;

    str = (char *) malloc (MAX_ARR_SIZE);
    assert (str); //validating the pointer

    fprintf (stdout, "enter the station code to know next station\n");
    fgets (str, MAX_ARR_SIZE, stdin);
    
    while (*(str + index) != '\0'){  //to eliminate the \n from the string
        if (*(str + index) == '\n'){
            *(str + index) == '\0';
            break;
        }
        index++;
    }

    station1 = head; //to traverse

    while (station1 != NULL){       // traversing till string is found
        if (strcmp (station1 -> station_code, str) == 0){
            station1 = station1 -> next;
            break;
        }
        station1 = station1 -> next;
    }
    
    str = station -> station_code; 

    return str;  //returning next station code
}
