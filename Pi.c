#include <mpi.h>
#include <stdio.h>
#include <math.h>
#define max 10000000

int main(int argc,char **argv[]){
	int my_rank;
	int com_sz;
	double Pi;

	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,&com_sz);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);

	double sumalocal=0;
	double inicio=MPI_Wtime();
	for(int i=my_rank;i<max;i+=com_sz){
		if(i%2)
			sumalocal+=-4.0/(2*i+1);
		else
			sumalocal+=4.0/(2*i+1);
	}
	MPI_Reduce(&sumalocal,&Pi,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
	double fin=MPI_Wtime();
	if(my_rank==0){
		printf("Pi=%.50f\n",Pi);
		printf("Tiempo: %f\n",fin-inicio);
	}
	MPI_Finalize();
	return 0;

}
