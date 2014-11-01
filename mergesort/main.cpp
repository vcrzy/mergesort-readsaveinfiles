#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void Merge(int* vetor, int inicio, int meio, int fim)
{
	int* vetorAux;
	int i,j,k;
	
	for(i = 0; inicio < meio; i++)
	{
		vetorAux[i] = vetor[i];
		
		for(j = 0; (inicio+1) < fim; j++)
		{
			vetorAux[fim + (meio + 1)- j] = vetor[j];
			i = inicio;
			j = fim; 
			
				
			for(k = 0; inicio < fim; k++)
			{
				if(vetor[i] <= vetorAux[j])
				{
        			vetor[k] = vetorAux[i]; 
					i++;  
        		}	
				vetor[k] = vetorAux[j]; 
				j--;
			}
		}
	}
}


void MergeSort(int* vetor, int inicio, int fim)
{
	int meio;
	
	if(inicio < fim)
	{	
		meio = (inicio + fim)/2;

		MergeSort(vetor,inicio,meio);
		MergeSort(vetor,meio+1,fim);
		Merge(vetor,inicio,meio,fim);
	}
	
	for(int i = 0;i < fim; i++)
	{
		cout<<vetor[i];
	}

}

int main()
{
	int* vetorDesordenado;
	int tamanho;
	int i;
	
	cout<<"Tamanho: ";
	cin>>tamanho;
	
	for(i = 0; i < tamanho; i++)
	{
		cin>>vetorDesordenado[i];
	}
	
	MergeSort(vetorDesordenado,0,tamanho);

}

int main()
{
    int num = 0;
    int x;
    int* dados;
    FILE *file;
    FILE *out;
    
   file = fopen("vetor.txt","r");
    
    if(!file){
    	cout<<"Erro ao abrir o arquivo";
    	return 0;
    }
    
    while(file){
    	
    	*dados = fscanf(file,"%d", &x);
    	num++;
    }
    
    fclose(file);
	
    int ini[num];

    mergesort(dados,ini,0,num-1);

    out = fopen( "vetor.txt", "w");
    
    for(int i=0; i<num; i++){
    
    	 fprintf(out,"%d",dados[i]);
		
		 fclose(out);
    }
    delete[] dados;
   	fclose(out);
   	return 0;
}