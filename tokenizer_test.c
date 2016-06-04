#include "tokenizer.h"

int main() {
	char * tokens;
	int token_count;

	token_count = read_tokens("test.bf", &tokens);
	tokens[token_count] = '\0';

	printf("%d tokens: ", token_count);
	printf("%s", tokens);

	free(tokens);

	return 0;
}
