#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>
//#include "Knapsack.h"
//#include "Individual.h"
//#include "population.h"
#include "Genetic.h"
using namespace std;

int main(int argc, char const *argv[])
{
    printf("programa iniciou\n");
    if(argv[1] != NULL)
    {
        srand(time(NULL));
        printf("started knapsack algorithm\n");
        Knapsack *knapsack = new Knapsack((char*)argv[1])/*arquivo de entrada*/;
        knapsack->build();
        
        Genetic *genetic;

        genetic = new Genetic(knapsack, atoi(argv[2]));
        genetic->start_new_population();

        genetic->crossover();
        
        printf("\nfinalizou\n");
        //printf("%d\n", teste->get_value());
        //delete(knapsack);
    } else {
        printf("ERRO INVALID ENTRY\n");
        exit(0);
    }


  return 0;
}
