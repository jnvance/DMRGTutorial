#include<mpi.h>
#include<stdio.h>

int main(int argc, char **argv)
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    /*---- Body of the MPI program ----*/
    /* Each rank r calculates 2*rank+1 */
    int rank_val = 2*rank + 1;
    printf("[%d] Val: %-5d\n", rank, rank_val);

    /* Get the sum of all values from all ranks */
    int sum;
    MPI_Reduce(&rank_val, &sum, 1, MPI_INT, MPI_SUM, 0,
               MPI_COMM_WORLD);
    printf("[%d] Sum: %-5d\n", rank, sum);

    /* Assert that sum=size^2 */
    if(rank==0 && sum!=size*size){
        printf("Sum should be %d.\n",size*size);
        return(1);
    }
    /*---------------------------------*/

    MPI_Finalize();
    return(0);
}
