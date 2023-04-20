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
        // Knapsack *knapsack = new Knapsack((char*)argv[1])/*arquivo de entrada*/;
        // knapsack->build();
        
        int pop_size = atoi(argv[2]);
        int n_generations = atoi(argv[3]);

        Genetic *genetic;
        

        genetic = new Genetic((char*)argv[1], pop_size);
        genetic->start_new_population();
        Individual *gbest = NULL;
        printf("fit\tgap\n");

        for(int generation = 0 ; generation < n_generations ; generation++)
        {

            vector<Individual*> new_generation;
            for (int i = 0; i < pop_size; i++)
            {
                int rf = rand() % 100; /*randon factor*/
                int p1 = -1, p2 = -1;
                while(p1 == p2)
                {
                    p1 = genetic->selection();
                    p2 = genetic->selection();
                }

                Individual *novo = NULL;
                novo = genetic->crossover(p1, p2);   
                // for (int m = 0; m < genetic->_k->get_n(); m++)
                // {
                //     printf("%d", novo->get_genes()[i]);
                // }
                // printf("\n");
                novo->mutation(genetic->_k->get_n());
                novo->repair(genetic->_k);
                for (int m = 0; m < genetic->_k->get_n(); m++)
                {
                    printf("%d", novo->get_genes()[i]);
                }
                printf("\n");
                new_generation.push_back(novo);
            }
            
            Population *new_population = new Population(pop_size, new_generation);
            genetic->set_population(new_population);

            Individual *best = genetic->get_population()->get_best_individual();
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
            printf("\t%d", fit);
            printf("\t%lf\t%d\t%lf\n", gap, gbest->get_fit(), gbest->get_gap(genetic->_k->get_w()));
            
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
            

        




        
        printf("\nfinalizou\n");
        //printf("%d\n", teste->get_value());
        //delete(knapsack);
    } else {
        printf("ERRO INVALID ENTRY\n");
        exit(0);
    }


  return 0;
}
