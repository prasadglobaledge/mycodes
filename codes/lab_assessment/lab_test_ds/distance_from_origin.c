/* function to calculate distance of a station fron origin */

#include "headers.h"

int distance_from_origin (station_details *head)
{
    int res = 0; //to hold the result
    int index = 0;
    station_details *station2 = NULL; // pointer to traverse in the list
    char *str = NULL;

    str = (char *) malloc (MAX_ARR_SIZE);
    assert (str); //validating memory allocation

    fprintf (stdout, "enter the station CODE to calculate distance from the\
            \rorigin\n");
    fgets (str, MAX_ARR_SIZE, stdin); //receiving the station code from user

    while (*(str + index) != '\0'){  //to eliminate the \n from the string
        if (*(str + index) == '\n'){
            *(str + index) == '\0';
            break;
        }
        index++;
    }
    station1 = head; //to traverse till we get the node
    while (station1 != NULL){
        if (strcmp (station1 -> station_code, str) == 0){
            break;                   //if the string is found break the loop
        }
        station1 = station1 -> next;
    }

    res = station1 -> distance - head -> distance; //calculating the distance

    return res;

} 
