#include "Population.h"

class Genetic
{
private:
    Population *_population;
public:

    Knapsack *_k;


    Genetic(char *EntryFlie, int pSize){
        this->_k = new Knapsack(EntryFlie);
        this->_k->build();
        this->_population = new Population(pSize);
    };
    inline void start_new_population()
    {
        this->_population->create_init_population(this->_k);
        printf("saiu\n");
        
    };

    inline int selection()
    {
        int a = -1; // first parent
        int b = -1; // second parent
        int *winners = new int[2];
        while( a == b){
            a = rand() % this->_population->get_pSize();
            b = rand() % this->_population->get_pSize();
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
    
    inline Individual* crossover(int p1, int p2)
    {
       
        Individual *Parent1 = this->_population->search_Individual(p1);
        Individual *Parent2 = this->_population->search_Individual(p2); 

        int *child = new int[this->_k->get_n()];
        int sorteio;
        for (int i = 0; i < this->_k->get_n(); i++)
        {
            sorteio = rand() % 100;
            if(sorteio / 2 == 0) child[i] = (Parent1->get_genes())[i];
            else child[i] = (Parent2->get_genes())[i];
            
        }
        
        // for (int i = 0; i < this->_k->get_n(); i++)
        // {
        //     printf("%d",  child[i]);   
        // }
       
                            

       Individual *novo = new Individual(this->_k, child);
        
        // for (int i = 0; i < this->_k->get_n(); i++)
        // {
        //     printf("%d",  novo->get_genes()[i]);   
        // }
        // printf("\n");
        return novo;
    }
    inline void set_population(Population *new_population){
        if(this->_population != NULL)
        {
            delete this->_population;  
            this->_population = new_population;
        }
        else{
            this->_population = new_population;
        }
    }
   
    inline Population* get_population()
    {
        return this->_population;
    }

    ~Genetic();
};

