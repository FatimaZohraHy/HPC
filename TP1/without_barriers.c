#include<stdio.h>
#include<mpi.h>
void main(int argc, char **argv)
{ int size, node;
double start, end;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &node);
MPI_Comm_size(MPI_COMM_WORLD, &size);
start = MPI_Wtime();
if(node==0)
{ printf("Hello From Master. node = %d. Time = %lf \n", node, MPI_Wtime() - start); }
else
{ printf("Hello From Slave. node = %d. Time = %lf \n", node, (MPI_Wtime() - start)); }
MPI_Finalize(); }