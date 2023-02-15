#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "Knapsack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    printf("programa iniciou\n");
    if(argv[1] != NULL)
    {
        printf("started knapsack algorithm\n");
        Knapsack *knapsack = new Knapsack((char*)argv[1]);
        knapsack->build();
        //Item *teste = knapsack->searchItem(5);
        
        //printf("%d\n", teste->get_value());

        //delete(knapsack);
    } else {
        printf("ERRO INVALID ENTRY\n");
        exit(0);
    }


  return 0;
}
