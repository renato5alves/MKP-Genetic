#include "Individual.h"
using namespace std;
class Population
{
private:
    vector<Individual*> _Population;
    int _pSize;
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


  
    inline Individual* get_best_individual()
    {    
        int best = 0;
        for (int i = 1; i < this->_pSize; i++)
        {
            Individual *tmp = this->_Population[i];

            if(tmp->get_fit() > this->_Population[best]->get_fit()) best = i;
        }

        return this->_Population[best];
    }
    ~Population(){
        this->_Population.clear();
    };
};
