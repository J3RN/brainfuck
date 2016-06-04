#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_TOKENS 7

const char VALID_TOKENS[NUM_TOKENS] = { '+', '-', '.', '<', '>', '[', ']'};

void memory_check(void * mem) {
	if (mem == NULL) {
		perror("Failed to allocate memory");
		exit(1);
	}
}

int add_to_token_list(char * token_list, int * count, char token) {
	int valid_token;
	int i;

	valid_token = 0;
	for (i = 0; i < NUM_TOKENS; i++) {
		if (token == VALID_TOKENS[i]) {
			valid_token = 1;
		}
	}

	if (valid_token) {
		token_list[*count] = token;
		(*count)++;
	} else {
		printf("WARNING: Invalid token: %c", token);
	}

	return valid_token;
}

int read_tokens(char * filename, char ** token_list) {
	FILE * source;

	int chunk_size = 100;
	int count = 0;

	source = fopen(filename, "r");
	*token_list = malloc(chunk_size * sizeof(char *));
	memory_check(token_list);

	while (!feof(source)) {
		char c;
		fread(&c, sizeof(char), 1, source); // Read 1 char

		// Resize token list, if necessary
		if (count >= chunk_size) {
			int old_size = chunk_size;
			char * new_list;

			chunk_size *= 2;
			new_list = malloc(chunk_size * sizeof(char *));
			memory_check(new_list);
			strncpy(new_list, *token_list, old_size);
			*token_list = new_list;
		}

		add_to_token_list(*token_list, &count, c);
	}

	fclose(source);

	return count;
}

