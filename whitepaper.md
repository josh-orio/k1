# Whitepaper: K1 - Experimental Microkernel

- Author: Joshua O'Riordan
- Date: 3 Jun 25

## Index


1. [Filesystem](#filesystem)
2. [Inter Process Communication](#inter-process-communication)
2. [Boot Process](#boot-process)
4. [Running Applications](#applications)



## Boot Process

The boot process of any kernel is a dance between initialising hardware and filesystems, which often initialise each other in some capacity.