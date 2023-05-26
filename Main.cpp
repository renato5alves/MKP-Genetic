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
        // printf("started knapsack algorithm\n");
        // Knapsack *knapsack = new Knapsack((char*)argv[1])/*arquivo de entrada*/;
        // knapsack->build();
        
        int pop_size = atoi(argv[2]);
        int n_generations = atoi(argv[3]);

        Genetic *genetic;
        
        //printf("\n");
        genetic = new Genetic((char*)argv[1], pop_size);
        genetic->start_new_population();
        Individual *gbest = NULL;
        int *c = genetic->_k->get_constraints(); 

        // for (int i = 0; i < genetic->_k->get_m(); i++)
        // {
        //     printf("%d ", c[i]);
        // }
        // printf("fit\tgap\n");
        
        // for (int i = 0; i < genetic->_k->get_n(); i++)
        // {
        //     Item *item = genetic->_k->get_item(i);
        //     int *c = item->get_constraints();
        //     for (int j = 0; j < genetic->_k->get_m(); j++)
        //         printf("%d ", c[j]);
        //     printf("\n");
        // }
        for(int generation = 0 ; generation < n_generations ; generation++)
        {
            vector<Individual*> new_generation;
        
            int rf = rand() % 100; /*randon factor*/
            int p1 = -1, p2 = -1;
            while(p1 == p2)
            {
                p1 = genetic->selection();
                p2 = genetic->selection();
            }
            int *newgenes;
            newgenes = (int*)genetic->crossover(p1, p2);   
            Individual *novo = new Individual(genetic->_k, newgenes);
            novo->mutation(genetic->_k);
            novo->repair(genetic->_k);
            novo->set_fit(genetic->_k);
            genetic->_population->replace_worst(novo);
            
        
            //genetic->set_population(new_population);
            Individual *best = genetic->get_population()->get_best_individual();
             int *c = genetic->_k->get_constraints(); 

            // for (int i = 0; i < genetic->_k->get_m(); i++)
            // {
            //     printf("%d\t", c[i]);
            // }
            // printf("\n");
            // int *restrictions = best->get_constraints();
            // for (int i = 0; i < genetic->_k->get_m(); i++)
            // {
            //     printf("%d\t", restrictions[i]);
            // }
            // printf("\n");
            // printf("\n");
            if(gbest == NULL)
            {
                gbest = best;
            }else{
                if(best->get_fit() > gbest->get_fit())
                    gbest = best;
            }

            int fit = best->get_fit();
            int *genes = best->get_genes();
            int *contraints = best->get_constraints();
            double gap = best->get_gap(genetic->_k->get_w());
            // printf("============================================\n");
            // printf("\t%d", fit);
            
            // printf("\t%lf\t%d\t%lf\n", gap, gbest->get_fit(), gbest->get_gap(genetic->_k->get_w()));
            
            // for (int j = 0; j < genetic->_k->get_m(); j++)
            // {
            //     printf("c_use[%d]:\t%d\t", j, contraints[j]);
            // }
            // printf("\n");
            // for (int j = 0; j < genetic->_k->get_n(); j++)
            // {
            //     printf("%d", genes[j]);
            // }
            //printf("============================================\n");

        }        
        
        printf("fit\tgap\n");
        printf("%d\t%lf\n", gbest->get_fit(), gbest->get_gap(genetic->_k->get_w()));
        
       
        

        
        // printf("\nfinalizou\n");
        //printf("%d\n", teste->get_value());
        //delete(knapsack);
    } else {
        printf("ERRO INVALID ENTRY\n");
        exit(0);
    }


  return 0;
}
