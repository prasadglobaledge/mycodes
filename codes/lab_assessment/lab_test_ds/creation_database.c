/* creating a staic database of the route */

#include "headers.h"

station_details *create_database (station_details *head)
{
    station_details *newnode = NULL;

    newnode = (station_details *) malloc (sizeof (station_details));/* allocati
                                                                    ng memory*/
    assert (newnode); //validating the memory allocation

    newnode -> station_code = (char *) malloc (MAX_ARR_SIZE);
    newnode -> station_name = (char *) malloc (MAX_ARR_SIZE);

    if (newnode -> station_code == NULL || newnode -> station_name == NULL){
        fprintf (stdout, "malloc allocation failed");
        exit (1);
    }
// from here static database creation for different station details

    newnode -> station_code = "SBC";
    newnode -> station_name = "KSR BENGALURU";
    newnode -> t_time_arr. arr_hours = 22;
    newnode -> t_time_arr.arr_minutes = 30;
    newnode -> t_time_dept.dept_hours = 22;
    newnode -> t_time_dept.dept_minutes = 40;
    newnode -> halt_time = 0;
    newnode -> distance = 0;
    newnode -> num_days = 1;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    head = insert_node (newnode, head); // calling insert_node function

    newnode -> station_code = "BNC";
    newnode -> station_name = "BENGALURU CANT";
    newnode -> t_time_arr. arr_hours = 22;
    newnode -> t_time_arr.arr_minutes = 50;
    newnode -> t_time_dept.dept_hours = 22;
    newnode -> t_time_dept.dept_minutes = 52;
    newnode -> halt_time = 2;
    newnode -> distance = 4;
    newnode -> num_days = 1;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    head = insert_node (newnode, head); // calling insert_node function

    newnode -> station_code = "BWT";
    newnode -> station_name = "BANGARPET";
    newnode -> t_time_arr. arr_hours = 23;
    newnode -> t_time_arr.arr_minutes = 43;
    newnode -> t_time_dept.dept_hours = 23;
    newnode -> t_time_dept.dept_minutes = 45;
    newnode -> halt_time = 2;
    newnode -> distance = 70;
    newnode -> num_days = 1;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    head = insert_node (newnode, head); // calling insert_node function
    
    newnode -> station_code = "JTJ";
    newnode -> station_name = "JOLARPETTAI";
    newnode -> t_time_arr. arr_hours = 0;
    newnode -> t_time_arr.arr_minutes = 58;
    newnode -> t_time_dept.dept_hours = 1;
    newnode -> t_time_dept.dept_minutes = 0;
    newnode -> halt_time = 2;
    newnode -> distance = 148;
    newnode -> num_days = 2;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    head = insert_node (newnode, head); // calling insert_node function
    
    newnode -> station_code = "KPD";
    newnode -> station_name = "KATPADI JN";
    newnode -> t_time_arr. arr_hours = 2;
    newnode -> t_time_arr.arr_minutes = 8;
    newnode -> t_time_dept.dept_hours = 2;
    newnode -> t_time_dept.dept_minutes = 10;
    newnode -> halt_time = 2;
    newnode -> distance = 231;
    newnode -> num_days = 2;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    head = insert_node (newnode, head); // calling insert_node function
    
    newnode -> station_code = "AJJ";
    newnode -> station_name = "ARAKKONAM";
    newnode -> t_time_arr. arr_hours = 2;
    newnode -> t_time_arr.arr_minutes = 58;
    newnode -> t_time_dept.dept_hours = 3;
    newnode -> t_time_dept.dept_minutes = 0;
    newnode -> halt_time = 2;
    newnode -> distance = 292;
    newnode -> num_days = 2;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    head = insert_node (newnode, head); // calling insert_node function
    
    newnode -> station_code = "PER";
    newnode -> station_name = "PERAMBUR";
    newnode -> t_time_arr. arr_hours = 3;
    newnode -> t_time_arr.arr_minutes = 48;
    newnode -> t_time_dept.dept_hours = 3;
    newnode -> t_time_dept.dept_minutes = 50;
    newnode -> halt_time = 2;
    newnode -> distance = 361;
    newnode -> num_days = 2;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    head = insert_node (newnode, head); // calling insert_node function
    
    newnode -> station_code = "MAS";
    newnode -> station_name = "CHENNAI CEANTRAL";
    newnode -> t_time_arr. arr_hours = 4;
    newnode -> t_time_arr.arr_minutes = 35;
    newnode -> t_time_dept.dept_hours = 5;
    newnode -> t_time_dept.dept_minutes = 0;
    newnode -> halt_time = 0;
    newnode -> distance = 367;
    newnode -> num_days = 2;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    head = insert_node (newnode, head); // calling insert_node function

    display (head);

    return head;
}


station_details *insert_node (station_details *newnode, station_details *head)
{
    station_details *cur = NULL; // pointer to traverse

    if (head == NULL){
        head = newnode;
        return head;
    }    

    cur = head; //pointer to traverse till the end of the list
    while (cur != NULL){
        cur = cur -> next;
    }

    cur -> next = newnode; //inserting at the last position
    newnode -> prev = cur;

    return head;
}

void display (station_details *head)
{
    station_details *ptr = NULL; //pointer to traverse through the list

    ptr = head; //pointing to the head node

    fprintf (stdout, "|Code |\tName\t|Arrives|Dept.|Halt|Dist.|Day|\n");

    while (ptr != NULL){
        fprintf (stdout, "|%s|%s|%d:%d|%d:%d|%d|%d|%d|\n", ptr -> station_code,
                ptr -> station_name, ptr -> t_time_arr.hours, ptr -> t_time_
                arr.minutes, ptr -> t_time_dept.hours, ptr -> t_time_dept.
               minutes, ptr -> halt_time, ptr -> num_days, ptr -> distance);
       
        ptr = ptr -> next;
    }
}
