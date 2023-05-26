#include "Population.h"

class Genetic
{
private:
public:
    Population *_population;
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
    
    inline int* crossover(int p1, int p2)
    {
       
        Individual *Parent1 = this->_population->search_Individual(p1);
        Individual *Parent2 = this->_population->search_Individual(p2); 
        int *gp1, *gp2;
        int *child = new int[this->_k->get_n()];
        int sorteio;
        gp1 = Parent1->get_genes();
        gp2 = Parent2->get_genes();
        for (int i = 0; i < this->_k->get_n(); i++)
        {
            sorteio = rand() % 100;
            if(sorteio % 2 == 0) child[i] = gp1[i];
            else child[i] = gp2[i];
            
        }   
       
        return child;
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

