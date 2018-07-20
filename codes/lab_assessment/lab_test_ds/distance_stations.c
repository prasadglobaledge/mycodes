/* function to calculate distance between any two stations */

#include "headers.h"

int distance_stations (station_details head)
{
    int index = 0;
    station_details *station1 = NULL; //pointer to traverse in the list
    station_details *station2 = NULL; //pointer to traverse in the list
    
    char *str = NULL;
    char *str1 = NULL; /*pointers to hold the stations code */
    int res = 0; //to hold the result

    str = (char *) malloc (MAX_ARR_SIZE);
    str1 = (char *) malloc (MAX_ARR_SIZE); //dynamic memory allocation

    if (str == NULL || str1 == NULL){  //validation of memory allocation
        fprintf (stdout, "malloc failed\n");
        exit (1);
    }

    fprintf (stdout, "enter the two stations CODES to calculate the distance\n");
    __fpurge (stdin);
    fgets (str, MAX_ARR_SIZE, stdin);

    while (*(str + index) != '\0'){  //to eliminate the \n from the string
        if (*(str + index) == '\n'){
            *(str + index) == '\0';
            break;
        }
        index++;
    }
    __fpurge (stdin);
    fgets (str1, MAX_ARR_SIZE, stdin);

    index = 0;
    while (*(str1 + index) != '\0'){  //to eliminate the \n from the string
        if (*(str1 + index) == '\n'){
            *(str1 + index) == '\0';
            break;
        }
        index++;
    }

    station1 = head; //make ptr ponit to the head node

    while (station1 != NULL){
        if (strcmp (station1 -> station_code, str) == 0){
            break;
        }
        station1 = station1 -> next;
    }

    while (station2 != NULL){
        if (strcmp (station2 -> station_code, str1) == 0){
            break;
        }
        station2 = station2 -> next;
    }
     
    res = station1 -> distance - station2 -> distance; //calculating distance

    if (res < 0){
        res = (-1) * res;
    }

    return res;

}
