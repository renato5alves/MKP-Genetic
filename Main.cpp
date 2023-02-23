#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>
//#include "Knapsack.h"
#include "Individual.h"

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

        // for (int i = 0; i < knapsack->get_n(); i++)
        // {
        //     int *c;
        //     Item* it = knapsack->get_item(i);
        //     c = it->get_Constraints();
        //     for (int j = 0; j < knapsack->get_m(); j++)
        //     {
        //         printf("%d ", c[j]);
        //     }
        //     printf("\n");
            
        // }
        

        Individual *i;

        i = new Individual(knapsack);
        
        printf("\nfinalizou\n");
        //printf("%d\n", teste->get_value());
        //delete(knapsack);
    } else {
        printf("ERRO INVALID ENTRY\n");
        exit(0);
    }


  return 0;
}
