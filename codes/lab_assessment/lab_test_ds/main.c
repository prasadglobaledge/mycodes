/* Implementation of KSR bangalore to Chennai central railway station info
 * portal using DLL data structures */

//header file inclusion

#include "headers.h"

int main (void) 
{
    station_details head = NULL; //head node of the list 
    int choice = 0; //to select the choice for operations
    char *str = NULL; // string to get the choice from the user
    int res = 0; //to collect the return value
    t_time_arr res_time_arr; //to collect the time of arrival return value
    t_time_dept res_time_dept; //to collect the time of departure return value

    str = (char *) malloc (MAX_ARR_SIZE);
    assert (str); //validation for malloc

    fprintf (stdout, "***** Welcome to the Indian Railways*****\n");
    fprintf (stdout, "Enter the options below to see the info of KSR Bangalore\
            \rto Chennai central train\n");
    fprintf (stdout, "My system is case sensitive carefull !!!!!\n");

    head = create_database (head); //creating a static database

    fprintf (stdout, "Now enter the values and strings according to the table\n");

    for ( ; ;){     //continuos loop to provide a menu for user interface
        fprintf (stdout, "enter the choice :\n1.Distance_b_stations
                                          \n\r2.Distance_from_origin
                                          \n\r3.Slowest_time
                                          \n\r4.Fastest_time
                                          \n\r5.Next_name
                                          \n\r6.Prev_name
                                          \n\r7.Time_b_stations 
                                          \n\r8.Time_from_orgin 
                                          \n\r9.Remaining_time\n"};

        choice = atoi (fgets (str, MAX_ARR_SIZE, stdin)); //collecting a choice
        if (!choice){                    //validating the input
            fprintf ("enter the true choice\n");
            continue;
        }

        switch (choice){  //switch case to call a function of user choice

            case Distance_b_stations : res = distance_b_stations (head);
                                       fprintf (stdout, "distance between the\
                                           \rstations is : %d\n", res);
                                       break;

            case Distance_from_origin : res = distance_from_origin (head);
                                       fprintf (stdout, "distance from  the\
                                           \rorigin to station is : %d\n", res);
                                       break;

            case Slowest_time : res_time_arr = slowest_time (head);
                                       fprintf (stdout, "slowest time between \
                                       two stations is : %d:%d\n", res_time_arr
                                       -> hours, res_time_arr -> minutes);
                                       break;

            case Fastest_time : res_time_arr = fastest_time (head);
                                       fprintf (stdout, "fastest time between \
                                       \rtwo stations is : %d:%d\n", res_time_arr
                                       -> hours, res_time_arr -> minutes);
                                       break;

            case Next_name : str = next_station_name (head);
                             fprintf (stdout, "name/code of the next station \
                                     \ris : %s\n", str);
                             break;

            case Prev_name : str = prev_station_name (head);
                             fprintf (stdout, "name/code of the prev station \
                                     \ris : %s\n", str);
                             break;

            case Time_b_stations : res_time_dept = time_b_stations (head);
                                    fprintf (stdout, "time between \
                                    \rtwo stations is : %d:%d\n", res_time_dept
                                    -> hours, res_time_dept -> minutes);
                                    break;

            case Time_from_origin : res_time_dept = time_from_origin (head);
                                    fprintf (stdout, "time from the origin \
                                    \ris : %d:%d\n", res_time_dept
                                    -> hours, res_time_dept -> minutes);
                                    break;

            case Remaining_time : res_time_dept = remaining_time (head);
                                    fprintf (stdout, "time remaining to reach \
                                    \ris : %d:%d\n", res_time_arr
                                    -> hours, res_time_arr -> minutes);
                                    break;

            default : fprintf (stdout, "wrong choice entered\n");
                      break;
        }
    }
}
