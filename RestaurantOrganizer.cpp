/*
Student Name:Yagmur Goktas
Student Number:2017400018
Project Number: 2
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "RestaurantOrganizer.h"

using namespace std;

RestaurantOrganizer::RestaurantOrganizer(const vector<int>& tableCapacityInput){

    numberOfTables = tableCapacityInput.size();
    for(int i=0;i<numberOfTables;i++){
        tableCapacity[i] = tableCapacityInput[i];

        heap[i] = i;
        heapUp(i);
    }
}

void RestaurantOrganizer::addNewGroup(int groupSize, ofstream& outFile){
    // IMPLEMENT ME
     if(tableCapacity[heap[0]]<groupSize ){
        outFile << -1 << endl ;
    }
    else {
        tableCapacity[heap[0]] = tableCapacity[heap[0]] - groupSize;

        outFile << heap[0] << endl;
        heapDown(0);
    }
}

void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

int getleftchild(int index){
    return (index+1)*2 -1;
}
int getrightchild(int index){

    return (index+1)*2 ;
}
int getParent(int index){
    if((index+1)/2 -1 >= 0) {
        return (index + 1) / 2 - 1;
    }else{
        return -1;
    }

}


void RestaurantOrganizer::heapUp(int index){
    // IMPLEMENT ME!


    if(getParent(index)>= 0 && tableCapacity[heap[index]]>tableCapacity[heap[getParent(index)]] ){

        swap(&heap[index],&heap[getParent(index)] );
        heapUp(getParent(index));
    }
    else if(getParent(index)>= 0 && tableCapacity[heap[index]]==tableCapacity[heap[getParent(index)]] ){
        if(heap[index]<heap[getParent(index)]) {
            swap(&heap[index], &heap[getParent(index)]);
            heapUp(getParent(index));
        }
    }


}


void RestaurantOrganizer::heapDown(int index){
    // IMPLEMENT ME!


  if(getrightchild(index)>=numberOfTables && getleftchild(index)>=numberOfTables){
        return;
    }
    else if(getleftchild(index)<numberOfTables && getrightchild(index)>=numberOfTables){
        if(tableCapacity[heap[getleftchild(index)]]>tableCapacity[heap[index]]) {
            swap(&heap[index], &heap[getleftchild(index)]);
            heapDown(getleftchild(index));
        }
        else if(tableCapacity[heap[getleftchild(index)]]==tableCapacity[heap[index]]){
            if (heap[getrightchild(index)] < heap[index]) {
                swap(&heap[index], &heap[getrightchild(index)]);
                heapDown(getrightchild(index));
            }
        }
    }
    else {
            if(tableCapacity[heap[getleftchild(index)]]>tableCapacity[heap[getrightchild(index)]]){
            if (tableCapacity[heap[index]] < tableCapacity[heap[getleftchild(index)]] ) {

                    swap(&heap[index], &heap[getleftchild(index)]);
                    heapDown(getleftchild(index));
                } else if (tableCapacity[heap[index]] == tableCapacity[heap[getleftchild(index)]]) {
                    if (heap[getleftchild(index)] < heap[index]) {
                        swap(&heap[index], &heap[getleftchild(index)]);
                        heapDown(getleftchild(index));
                    }
                }
            }
                if(tableCapacity[heap[getleftchild(index)]]<tableCapacity[heap[getrightchild(index)]]){

                    if (tableCapacity[heap[index]] < tableCapacity[heap[getrightchild(index)]]) {
                        swap(&heap[index], &heap[getrightchild(index)]);
                        heapDown(getrightchild(index));
                    } else if (tableCapacity[heap[index]] == tableCapacity[heap[getrightchild(index)]]) {
                        if (heap[getrightchild(index)] < heap[index]) {
                            swap(&heap[index], &heap[getrightchild(index)]);
                            heapDown(getrightchild(index));
                        }
                    }

                }
             else if (tableCapacity[heap[index]] <= tableCapacity[heap[getleftchild(index)]] &&
                       tableCapacity[heap[index]] <= tableCapacity[heap[getrightchild(index)]]) {
                if (tableCapacity[heap[index]] < tableCapacity[heap[getleftchild(index)]] &&
                    tableCapacity[heap[index]] < tableCapacity[heap[getrightchild(index)]]) {
                    if (heap[getleftchild(index)] < heap[getrightchild(index)]) {
                        swap(&heap[index], &heap[getleftchild(index)]);
                        heapDown(getleftchild(index));
                    } else if (heap[getrightchild(index)] < heap[getleftchild(index)]) {
                        swap(&heap[index], &heap[getrightchild(index)]);
                        heapDown(getrightchild(index));
                    }
                } else if (tableCapacity[heap[index]] == tableCapacity[heap[getleftchild(index)]] &&
                           tableCapacity[heap[index]] == tableCapacity[heap[getrightchild(index)]]) {
                    if (heap[getleftchild(index)] < heap[getrightchild(index)] &&
                        heap[getleftchild(index)] < heap[index]) {
                        swap(&heap[index], &heap[getleftchild(index)]);
                        heapDown(getleftchild(index));
                    } else if (heap[getrightchild(index)] < heap[getleftchild(index)] &&
                               heap[getrightchild(index)] < heap[index]) {
                        swap(&heap[index], &heap[getrightchild(index)]);
                        heapDown(getrightchild(index));
                    }
                }
            }

        }
    }




void RestaurantOrganizer::printSorted(ofstream& outFile){
    // IMPLEMENT ME!

    int i=0;

    while(i<numberOfTables){
       outFile << tableCapacity[heap[0]] << " ";
       tableCapacity[heap[0]]=-1;
       heapDown(0);
        i++;
    }





}

// YOU CAN ADD YOUR HELPER FUNCTIONS

