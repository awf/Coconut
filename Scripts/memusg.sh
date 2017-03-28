#!/bin/bash
PROG=$1
eval "/usr/bin/time -l 2>&1 ./$PROG | grep maximum"
