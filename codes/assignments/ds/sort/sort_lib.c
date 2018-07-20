/* definition of all sorting functions */

#include "sort_headers.h"

int selection_ascending(){

    int pos = 0;  // to track the position
    int index1 = 0;
    int index2;

    while(index1 < SIZE){          //passing and comparing to get min value
                                    //of the  array list            
        pos = index1;
        index2 = 1;

        while(index2 < SIZE){
            if(*(array + index1) > *(array + index2)){
                index1 = index2;
            }
            index2++;
        }
        if(pos != index1){
            *(array + index1) = *(array + index1) ^ *(array + pos);
            *(array + pos) = *(array + index1) ^ *(array + pos);
            *(array + index1) = *(array + index1) ^ *(array + pos);
        }
    }
    fprintf(stdout, "the elements of the array after sorting is\n");
    index1 = 0;
    while(index1 < SIZE){            //printing the sorted elements
  
        fprintf(stdout, "%d\n", *(array + index1));
        return 1;
    }
}

int selection_descending(){

    int pos = 0;  // to track the position
    int index1 = 0;
    int index2;

    while(index1 < SIZE){          //passing and comparing to get min value
                                    //of the  array list            
        pos = index1;
        index2 = 1;

        while(index2 > SIZE){
            if(*(array + index1) > *(array + index2)){
                index1 = index2;
            }
            index2++;
        }
        if(pos != index1){
            *(array + index1) = *(array + index1) ^ *(array + pos);
            *(array + pos) = *(array + index1) ^ *(array + pos);
            *(array + index1) = *(array + index1) ^ *(array + pos);
        }
    }
    fprintf(stdout, "the elements of the array after sorting is\n");
    index1 = 0;
    while(index1 < SIZE){            //printing the sorted elements
  
        fprintf(stdout, "%d\n", *(array + index1));
        return 1;
    }
}
