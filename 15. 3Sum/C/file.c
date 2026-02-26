#include "shared.h"

IntArray createCase(char* filename) {
	FILE* fp = fopen(filename, "r");
	fseek(fp, 1, SEEK_SET);
	int* resultArr = calloc(1, sizeof(int));

	IntArray result = {0};

	char* line = NULL;
	size_t size = 0;
	ssize_t nread = getline(&line, &size, fp);

	if(nread == -1) {
		free(line);
		return result;
	}

	char* token = strtok(line, ",");

	int i = 0;

	while(token != NULL) {
		int num = strtol(token, NULL, 10);
		resultArr[i++] = num;
		resultArr = realloc(resultArr, ((i + 1) * sizeof(int)));
		// printf("%d\n", num);
		token = strtok(0, ",");
	}

	result.arr = resultArr;
	result.size = i;

	free(line);

	return result;
}
