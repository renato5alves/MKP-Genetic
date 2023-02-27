#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>
//#include "Knapsack.h"
//#include "Individual.h"
#include "population.h"
using namespace std;

int main(int argc, char const *argv[])
{
    printf("programa iniciou\n");
    if(argv[1] != NULL)
    {
        srand(time(NULL));
        printf("started knapsack algorithm\n");
        Knapsack *knapsack = new Knapsack((char*)argv[1]);
        knapsack->build();
        
        Population *population = new Population(atoi(argv[2]));
        printf("population size: [%d]", population->get_pSize());

        printf("\nfinalizou\n");
        //printf("%d\n", teste->get_value());
        //delete(knapsack);
    } else {
        printf("ERRO INVALID ENTRY\n");
        exit(0);
    }


  return 0;
}
