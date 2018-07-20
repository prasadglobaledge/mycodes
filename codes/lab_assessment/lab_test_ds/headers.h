/* South western Railway portal 
 * created by : Basava prasad s j (31067)
 * date : june 14 2018 */

//header guards 

#ifndef HEADERS_H
#define HEADERS_H

//header files inclusion

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

//macro definitions

#define MAX_ARR_SIZE 100
#define SUCCESS 1
#define FAIL 0

//data structure declarations

typedef struct station{
    struct station *prev; //pointer to hold previous node address
    char *station_code; //code of the station
    char *station_name; //name of the station

    typedef struct arr_time{    //structure for arrival time
        int arr_hours : 8;
        int arr_minutes : 8;
    }t_time_arr;

    typedef struct dept_time{   //struture for departure time    
        int dept_hours : 8;
        int dept_minutes : 8;
    }t_time_dept;

    int halt_time : 8; //halting time in a station
    int num_days : 8; //number of days to travel
    int distance;    //distance between the stations
    struct station *next: //pointer to hold next node address
        ;
} station_details;

//enum declaration for operations choice

enum tag {Distance_b_stations = 1, Distance_from_origin, Slowest_time, 
         Fastest_time, Next_name, Prev_name, Time_b_stations, Time_from_origin,
         Remaining_time};

//functions declarations

void display (station_details *head);
char *prev_station_name (station_details *head);
char *next_station_name (station_details *head);
int distance_b_stations (station_details *head);
int distance_from_origin (station_details *head);
station_details *create_database (station_details *head);
station_details *insert_node (station_details newnode, station_details *head);
t_time_arr slowest_time (station_details *head);
t_time_arr fastest_time (station_details *head);
t_time_dept time_b_stations (station_details *head);
t_time_dept time_from_origin (station_details *head);
t_time_arr remaining_time (station_details *head);

//end of header guards

#endif



