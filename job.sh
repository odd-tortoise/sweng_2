#!/bin/bash

SING_IMG = my_container.sif

export TMPDIR = $HOME/tmp
mkdir -p $TMPDIR

singularity exec --bind $TMPDIR:$TMPDIR $SING_IMG
