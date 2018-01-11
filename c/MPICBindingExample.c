#include <stdio.h>
#include "mpi.h"

/* filename: MPICBindingExample.cpp */
int main (int argc, char **argv)
{ 
        MPI_Init (&argc, &argv);
        int myrank, size;
        void master();
        void slave();
        MPI_Comm_rank (MPI_COMM_WORLD, &myrank);
        MPI_Comm_size( MPI_COMM_WORLD, &size );

        printf("%s", myrank);
        if (!myrank)
            master ();
        else 
		    slave ();
        MPI_Finalize ();
        return (1);
}

void master()
		{printf("I am the master program\n");}

void slave()
		{printf("I am the slave program\n");}
		
