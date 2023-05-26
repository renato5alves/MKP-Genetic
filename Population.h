#include "Individual.h"
using namespace std;
class Population
{
private:
    int _pSize;
    vector<Individual*> _Population;
public:
    Population(int size){
        this->_pSize = size;
    }
    inline 
    void create_init_population(Knapsack* Knapsack)
    {
        for (int i = 0; i < this->_pSize; i++)
        {
            Individual *newIndividual = new Individual(Knapsack);
            newIndividual->repair(Knapsack);
            
            this->_Population.push_back(newIndividual);            
        } 
    };
    inline
    int get_pSize(){ return this->_pSize; };
    Individual* search_Individual(int id){
        
        return this->_Population[id];
    };
    
    Population(int size, vector<Individual*> population)
    {
        this->_pSize = size;
        this->_Population = population;
    }
  
    inline Individual* get_best_individual()/* Essa busca retorna O PIOR individuo da população*/
    {    
        int best = 0;
        for (int i = 1; i < this->_pSize; i++)
        {
            Individual *tmp = this->_Population[i];
            if(tmp->get_fit() > this->_Population[best]->get_fit()) best = i;
        }
        Individual *ibest = this->_Population[best];
        return ibest;
    }
    inline int get_worst_individual() /* Essa busca retorna O INDICE para o pior individuo da população*/
    {    
        int worst = 0;
        for (int i = 1; i < this->_pSize; i++)
        {
            Individual *tmp = this->_Population[i];
            if(tmp->get_fit() < this->_Population[worst]->get_fit())/*then*/ worst = i;
        }
        Individual *iworst = this->_Population[worst];
        return worst;
    }
    inline void replace_worst(Individual* replace)
    {
        int i = this->get_worst_individual();
        this->_Population[i]->replace(replace);

    }
    ~Population(){
        this->_Population.clear();
    };
};
