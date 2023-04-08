#include "Population.h"

class Genetic
{
private:

    Population *_poputation;
    Knapsack *_k;

public:
    Genetic(Knapsack *k, int pSize){
        this->_k = k;
        this->_poputation = new Population(pSize);
    };
    inline void start_new_population()
    {
        this->_poputation->create_init_population(this->_k);
        
    };

    inline int selection()
    {
        int a = -1; // first parent
        int b = -1; // second parent
        int *winners = new int[2];
        while( a == b){
            a = rand() % this->_poputation->get_pSize();
            b = rand() % this->_poputation->get_pSize();
        }

        int rnd = rand() % 100;

        if(rnd == 0)
        {
            return a;
        }
        else{
            return b;
        }   
    };
    
    inline int crossover()
    {
        int rf = rand() % 100; /*randon factor*/
        int p1 = -1, p2 = -1;


        while(p1 == p2)
        {
            p1 = this->selection();
            p2 = this->selection();
        }
        Individual *tmp;
        for (int i = 0; i < this->_k->get_m(); i++)
        {
            printf("\t%d", (this->_k->get_constraints())[i]);
        }
        printf("\n");
        for(int i = 0 ; i < this->_poputation->get_pSize(); i++)
        {
            tmp = this->_poputation->search_Individual(i);
            int *g = tmp->get_genes();
            int *c = tmp->get_constraints();
            printf("%d ", tmp->get_fit());
            
            
            for (int i = 0; i < this->_k->get_m(); i++)
            {
                printf("\t%d ", c[i]);   
            }
            
            printf("\t%f ",tmp->get_gap(this->_k->get_w()));
            
            printf("\n");

        }

        return 1;;
    }


    ~Genetic();
};

