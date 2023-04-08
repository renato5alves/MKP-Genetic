#include "Knapsack.h"
void Knapsack::build() // este metodo realiza o processo de inicialização das entradas, o qual inclui 
                       // armazenamento das entradas em suas devidas estruturas de dados
{
    FILE *f = fopen(this->filename, "r");



    /*==================== seção 1 ====================*/
    //seção 1 realiza a leitura dos valores n, m, w(melhor solução conhecida) e os n valores referente ao valor da mochila
    fscanf(f, " %d %d %d", &this->_n, &this->_m, &this->_w);
    //printf("1a.\n");
    int *values = (int*) malloc(this->_n * sizeof(int));
    for(unsigned i = 0 ; i < this->_n ; i++)
    {
        fscanf(f, " %d", &values[i]);
       // printf("%d ", values[i]);
    }
    /*==================== seção 1 ====================*/

    /*==================== seção 2 ====================*/
    // esta seção realiza leitura das m restrições cosumidas pelos itens ao serem adcionados à mochila
 
    int **constraints = (int**) malloc(this->_n * sizeof(int*));
    for (int i = 0; i < this->_n; i++)
    {
        constraints[i] = (int*) malloc(this->_m * sizeof(int));
        //constraints[i] = (int*) new int[this->_m];
    }
    /*==================== seção 2 ====================*/
    
    /*==================== seção 3 ====================*/
    //esta seção guarda em uma lista os n objetos itens contentos seu valor, restrição e media de restrição(( m1+m2+3+...+mk)/n)
    vector<Item*>::iterator it;
    it = this->_itens.begin();
    for(unsigned i = 0 ; i < this->_n ; i++)
    {
        int soma = 0;
        double media;
        vector<Item*>::iterator it;
        it = this->_itens.begin();
        for(int j = 0 ; j < this->_m ; j++)
        {
            fscanf(f, " %d", &(constraints[i][j]));
            //printf("[%d] ", constraints[i][j]);
            soma+= constraints[i][j];
            //media = soma/this->_m;
            //printf("%f\n",soma/this->_m);
        }
        
        int *aux = constraints[i];
        Item *newItem = new Item(i, (int)values[i], soma/this->_m, aux);
        this->_itens.push_back(newItem);
        //printf("\n");
        
        
    }  
    /*==================== seção 3 ====================*/
    // verifica se o armazenamento está sento feito corretamente

            // int *constr;
            // for(int i = 0 ; this->_n ; i++)
            // {
            //     printf("%d\nvalor: %d\n",i, this->_itens[i]->get_value());
            //     printf("media: %.4f\n", this->_itens[i]->get_media());
            //     constr = this->_itens[i]->get_Constraints();
            //     for (int i = 0; i < this->_m; i++)
            //        printf("%d ", constr[i]);
            //     printf("\n");
            // }
    // verifica se o armazenamento está sento feito corretamente

    /*==================== seção 4 ====================*/
    //esta seção faz a leitura das restrições chamadas restrições de mochilas
    this->_constraints = new int[this->_m];
    
    for (int i = 0; i < this->_m; i++)
    {
        int m;
        fscanf(f, " %d ", &m);
        this->_constraints[i] = m;
        //printf("kc[%d] ", this->_constraints[i]);
    }
    /*==================== seção 4 ====================*/
    /*==================== seção 5 ====================*/
    //esta seção libera a memória de estruturas de dados temporários utilizados para leitura e criação da lista
    fclose(f);

    // for(int i = 0 ; i < this->_n ; i++)
    //     free((int*)constraints[i]);
    //free(constraints);
    free(values);
    // for(unsigned i = 0 ; i < this->_m ; i ++)
    //     delete[] constraints[i];
    // free(constraints);
    // delete[] constraints; 
    // delete[] values;
    // delete[] medias;
    /*==================== seção 5 ====================*/
    //printf("saiu\n");
}