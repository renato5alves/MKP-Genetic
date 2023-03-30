#include "Knapsack.h"
class Individual
{
private:
    int *_genes;
    int  _fit;
    int *_constraints;
    bool isFeasible;
public:
    Individual
    (Knapsack *k)
    {
        
        int n = k->get_n();
        int m = k->get_m();
        this->_genes = new int[n];
        this->_constraints = (int*) calloc(m, sizeof(int));
        this->_fit = 0;
        
        for (int i = 0; i < n; i++)
        {
            int r = rand() % 100;
            if (r%2 == 0)
                this->_genes[i] = 0;
            else 
                this->_genes[i] = 1;
            
        }
      
        for (int i = 0; i < n; i++)
        {
            int *c, f;
            Item *item = k->get_item(i);
            //printf("\n%d\n", item->get_value());
            //printf("%f\n", item->get_media());
            c = (int*) item->get_Constraints();
            f = item->get_value();
            if(this->_genes[i] == 1)
            {
                for(int j=0 ;j<m;j++)
                {
                    this->_constraints[j]+= c[j];
                    //printf("--[%d]", this->_constraints[j]);
                }
                //printf("\n");
                this->_fit += f;
            }
        }
        this->set_isFeasible(k);
        //this->repair(k);

    };
    int* 
    get_genes(){return this->_genes;};
    inline 
    int  get_fit(){return this->_fit;};
    inline 
    int* get_constraints(){return this->_constraints;};
    inline 
    void set_isFeasible(Knapsack *k){
        this->isFeasible = true;
        int *c;
        c = k->get_constraints();
        for ( int i = 0; i < k->get_m(); i++)
        {
            //printf("%d < %d\n", c[i], this->_constraints[i]);
            if(c[i] < this->_constraints[i])
            {
                this->isFeasible = false;
            }
        }
        //return this->isFeasible;
    };
    inline
    bool get_isFeasible()
    {
       return this->isFeasible; 
    };
    inline
    void repair(Knapsack *Knapsack)
    {
        this->_drop(Knapsack);
    }
    inline 
    void _drop(Knapsack* Knapsack)
    {
        int maior;
        while(!(this->get_isFeasible()))
        {
            maior = -1;
            for (int i = 0; i < Knapsack->get_n(); i++)
            {
                if(this->_genes[i] == 1)
                {
                    Item *tmp = Knapsack->get_item(i);
                    if(tmp->get_media() > maior)
                        maior = i;

                }
                
            }
        
        this->_genes[maior] = 0;
        Item *tmp =  Knapsack->get_item(maior);
        int  *removed = tmp->get_Constraints();
        for (int i = 0; i < Knapsack->get_m(); i++)
            this->_constraints[i] -= removed[i];
        set_isFeasible(Knapsack);
        }
        
    
    }
    ~Individual();
};


