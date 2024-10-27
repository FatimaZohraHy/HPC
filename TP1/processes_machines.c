#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
// Initialisation de MPI
MPI_Init(&argc, &argv);

// Nombre total de processus
int world_size;
MPI_Comm_size(MPI_COMM_WORLD, &world_size);

// Identifiant du processus (rank)
int world_rank;
MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

// Récupération du nom de l'hôte
char hostname[256];
gethostname(hostname, sizeof(hostname));

// Affichage des informations du nœud en travail
printf("Processus %d sur %s est en train de travailler\n", world_rank, hostname);

// Finalisation de MPI
MPI_Finalize();
return 0;
}