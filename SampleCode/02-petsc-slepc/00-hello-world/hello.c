#include <slepceps.h>

static char help[] = "Hello World for SLEPc.\n\n"
  "The command line options are:\n"
  "  -n <n>, where <n> = integer.\n\n";

int main(int argc,char **argv)
{
  PetscInt       n=30;
  PetscErrorCode ierr;
  ierr = SlepcInitialize(&argc,&argv,(char*)0,help);if (ierr) return ierr;

  ierr = PetscOptionsGetInt(NULL,NULL,"-n",&n,NULL);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD,"\nHello World!, n=%D\n\n",n);CHKERRQ(ierr);

  ierr = SlepcFinalize();
  return ierr;
}
