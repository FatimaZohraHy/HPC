#include<stdio.h>
#include<mpi.h>

void main(int argc, char **argv)
{ int size, node;
int serial_counter = 0;
double start, end;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
MPI_Barrier(MPI_COMM_WORLD);
start = MPI_Wtime();
MPI_Barrier(MPI_COMM_WORLD);
if(node==0)
{ printf("Hello From Master. Node = %d. Time = %lf \n", node, (MPI_Wtime() - start)); }
else
{ printf("Hello From Slave. Node = %d. Time = %lf \n", node, (MPI_Wtime() - start)); }
MPI_Finalize(); }