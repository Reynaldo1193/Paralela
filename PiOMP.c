#include <omp.h>
#include<stdlib.h>
#include<stdio.h>
#include <math.h>
#include<time.h>
#define max 1000000000
int main(int argc,char *argv[]){
		long double suma=0.0;
		long double Pi=0.0;
		long double sumalocal=0;

		int hilos=strtol(argv[1],NULL,10);
		double inicio, fin;
		inicio=clock();

		#pragma omp parallel for num_threads(hilos) reduction(+:suma) private(sumalocal)
		for(int i=0;i<max;i++){
		if(i%2)
			sumalocal+=-4.0/(2*i+1);
		else
			sumalocal+=4.0/(2*i+1);
		suma=sumalocal;
		}
		Pi=suma;

		fin=clock();
		double tiempo=fin-inicio;
		printf("Pi=%.50Lf\n",Pi);
		printf("Tiempo: %f\n",tiempo);


	return 0;
}
