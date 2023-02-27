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
        for (int i = 0; i < m; i++)
        {
            printf("%d ",this->_constraints[i]);
        }
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            int r = rand() % 100;
            if (r%2 == 0)
                this->_genes[i] = 0;
            else 
                this->_genes[i] = 1;
            printf("%d ", this->_genes[i]);
        }
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            int *c;
            Item *item = k->get_item(i);
            //printf("\n%d\n", item->get_value());
            //printf("%f\n", item->get_media());
            c = (int*) item->get_Constraints();
            if(this->_genes[i] == 1)
            {
                for(int j=0 ;j<m;j++)
                {
                    this->_constraints[j]+= c[j];
                    //printf("--[%d]", this->_constraints[j]);
                }
                //printf("\n");
            }
        }
        for ( int i = 0; i < m; i++)
        {
            if(k->get_constraints(i) < this->_constraints[i])
            {
                this->isFeasible = false;
            }else{
                this->isFeasible = true;
            }
        }
        

    };
    int* get_genes(){return this->_genes;};
    inline int  get_fit(){return this->_fit;};
    inline int* get_constraints(){return this->_constraints;};
    inline bool get_isFeasible(){return this->isFeasible;};
    ~Individual();
};


