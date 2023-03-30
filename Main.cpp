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
        Knapsack *knapsack = new Knapsack((char*)argv[1])/*arquivo de entrada*/;
        knapsack->build();
        
        Population *population = new Population(atoi(argv[2]/*tamanho da população inicial*/));
        printf("population size: [%d]\n", population->get_pSize());
        population->create_init_population(knapsack);
        

        for (int i = 0; i < atoi(argv[2]); i++)
        {
            Individual *tmp = population->search_Individual(i);
            printf("%d\n", tmp->get_fit());
            int *tc = tmp->get_constraints();
            for (int i = 0; i < knapsack->get_m(); i++)
            {
                printf("%d ", tc[i]);
            }
            printf("\n");
            
            for (int j = 0; j < knapsack->get_n(); j++)
            {
               int *g = tmp->get_genes();
                printf(" %d ",g[j]);
            }
            printf("\n");
        }
        
        printf("\nfinalizou\n");
        //printf("%d\n", teste->get_value());
        //delete(knapsack);
    } else {
        printf("ERRO INVALID ENTRY\n");
        exit(0);
    }


  return 0;
}
