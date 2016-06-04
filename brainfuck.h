#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *parent;
  struct Node **children;
  int num_children;
} Node;

#endif
