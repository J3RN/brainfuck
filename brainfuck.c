#include <stdio.h>
#include <stdlib.h>

#include "brainfuck.h"
#include "parser.h"
#include "executor.h"

int main(int ARGC, char ** ARGV) {
	if (ARGC < 1) {
		perror("Too few args");
		exit(1);
	} else if (ARGC > 1) {
		perror ("Too many args");
		exit(1);
	}

	char *fname = ARGV[0];
	char * token_list;
	FILE *source = fopen(fname, "r");


	Node *parse_tree = make_parse_tree(source);
	exec_parse_tree(parse_tree);

	return 0;
}
