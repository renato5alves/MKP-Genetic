#include "Knapsack.h"
class Individual
{
private:
    int *_genes;
    int  _fit;
    int *_constraints;
    double _gap;
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
            c = (int*) item->get_constraints();
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
        //printf("before repair fit %d\n ", this->_fit);
        this->repair(k);
        //printf("after repair fot %d\n", this->_fit);
        double w = k->get_w();
        double a = this->_fit;
        this->_gap = 100 * ((w - a) / w);
     
    };
    Individual(Knapsack *k, int *genes)
    {
        this->_genes = genes;

        int n = k->get_n();
        int m = k->get_m();
        this->_constraints = (int*) calloc(m, sizeof(int));
        this->_fit = 0;
        for (int i = 0; i < n; i++)
        {
            int *c, f;
            
            Item *item = k->get_item(i);
            //printf("\n%d\n", item->get_value());
            //printf("%f\n", item->get_media());
            c = (int*) item->get_constraints();
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
        //printf("before repair fit %d\n ", this->_fit);
        //this->repair(k);
        // printf("after repair fot %d\n", this->_fit);
        double w = k->get_w();
        double a = this->_fit;
        this->_gap = 100 * ((w - a) / w);
    }
    void set_fit(Knapsack *k)
    {
        this->_fit = 0;
        for (int i = 0; i < k->get_n(); i++)
        {
            if(this->_genes[i] == 1)
            {
                Item *item = k->get_item(i); 
                this->_fit += item->get_value();
            }
        }
        //printf("%d\n", this->_fit);
        
    }
    int* 
    get_genes(){return this->_genes;};
    inline 
    int  get_fit(){

        return this->_fit;
        };
    inline 
    int* get_constraints(){return this->_constraints;};
    inline 
    void set_isFeasible(Knapsack *k){
        this->isFeasible = true;
        int *Knapsack_coonstraints;
        Knapsack_coonstraints = k->get_constraints();
        for ( int i = 0; i < k->get_m(); i++)
        {
            //printf("%d < %d\n", c[i], this->_constraints[i]);
            if(Knapsack_coonstraints[i] < this->_constraints[i])
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
    double get_gap()
    {
        return this->_gap;
    }
    double get_gap(int w)
    {
        double a = w;
        double b = this->_fit;
        return 100 * ((a - b ) / a);
    }
    inline
    void repair(Knapsack *Knapsack)
    {
        this->_drop(Knapsack);
        this->_add(Knapsack);
    }
    inline 
    void _drop(Knapsack* Knapsack)
    {
        int maior;
        int maior_media;
        while(!(this->get_isFeasible()))
        {
            maior = 0;
            
            for (int i = 0; i < Knapsack->get_n(); i++)
            {
                if(this->_genes[i] == 1)
                {
                    Item *tmp = Knapsack->get_item(i);
                    if(tmp->get_media() > maior_media)
                    {    
                        maior = i;
                        maior_media = tmp->get_media();
                    }   

                }
                
            }
            // for (size_t i = 0; i < Knapsack->get_m(); i++)
            // {
            //     printf("{%d}", this->_constraints[i]);
            // }
            this->_genes[maior] = 0;
            Item *tmp = Knapsack->get_item(maior);
            int  *removed = tmp->get_constraints();
            // printf("\n============================\n");
            for (int i = 0; i < Knapsack->get_m(); i++)
            {
                this->_constraints[i] -= removed[i];
                //printf("[%d]", removed[i]);
            }
            // printf("\n");
            // for (size_t i = 0; i < Knapsack->get_m(); i++)
            // {
            //     printf("(%d)", this->_constraints[i]);
            // }
            // printf("\n============================\n");
            this->_fit -= tmp->get_value();

            // for (int i = 0; i < Knapsack->get_m(); i++)
            //     printf("%d ", this->_constraints[i]);
            //     printf("\n");
            set_isFeasible(Knapsack);
        }
        
    
    }

    inline
    void _add(Knapsack *k)
    {
        //int iterations = k->get_n();


        for(int j = 0 ; j < k->get_n() ; j++)
        {
            int *kc = k->get_constraints();
            int *ic;
            //printf("%d ", this->_fit);
            if(this->_genes[j] == 0)
            {
                Item *tmp = k->get_item(j);
                ic = tmp->get_constraints();
                int flag = 0;
                for(int i = 0 ; i < k->get_m() ; i++)
                {
                    if(this->_constraints[i] + ic[i] > kc[i])
                        flag++;
                }
                if(flag == 0)
                {
                    this->_fit += tmp->get_value();
                    for (int i = 0; i < k->get_m(); i++)
                        this->_constraints[i] += ic[i];
                    this->_genes[j] = 1;
                    set_isFeasible(k);
                }

                
                // for (int i = 0; i < k->get_n(); i++)
                //     printf("%d", this->_genes[i]);
                // printf("\n");
            }else{
                continue; // para garantir que seja contabilizada as tentativas de itens que ainda não estão na mochila
            }

        }
        //printf("\n");
    }

    inline void mutation(Knapsack* k)
    {
        int n = k->get_n();
        
        int m;
        int r = rand() % 2;
        //printf("k %d ", k);
        if(r == 1)
            m = 1;
        else     
            m = 2;
        for (int i = 0; i < m; i++)
        {  
            r = rand() % n;
            Item *added = k->get_item(r);
            int *addConst = added->get_constraints();
            if(this->_genes[r] == 0)
            {
                this->_genes[r] = 1;
                for(int j = 0 ; j < k->get_m(); j++)
                {
                    this->_constraints[j]+= addConst[j];
                    this->_fit += added->get_value();
                }
            }   
            else
            {
                this->_genes[r] = 0;
                for(int j = 0 ; j < k->get_m(); j++)
                {
                    this->_constraints[j] -= addConst[j];
                    this->_fit -= added->get_value();
                }
            }
            
            this->set_isFeasible(k);
            
        }
    }
    inline void replace(Individual* replace) /*subistitui os atributos por valores de outro individuo */
    {
        /*
        int *_genes;
        int  _fit;
        int *_constraints;
        double _gap;
        bool isFeasible;
        */
        this->_genes        = replace->get_genes();
        this->_fit          = replace->get_fit();
        this->_constraints  = replace->get_constraints();
        this->_gap          = replace->get_gap();
        this->isFeasible    = replace->get_isFeasible();
    }

    ~Individual();
};


