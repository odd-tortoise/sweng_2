#!/bin/bash
#SBATCH --job-name=matrix_multiplication
#SBATCH --output=output.txt
#SBATCH --error=error.txt
#SBATCH --ntasks=2
#SBATCH --nodes=1
#SBATCH --time=00:10:00
#SBATCH --partition=g100_all_serial

module load singularity

SINGULARITY_IMAGE=my_container.sif

export TMPDIR=$HOME/tmp
mkdir -p $TMPDIR

singularity exec --bind $TMPDIR:$TMPDIR $SINGULARITY_IMAGE bash -c "export OMPI_MCA_tmpdir_base=$TMPDIR && mpirun -np 2 build/src/main"
