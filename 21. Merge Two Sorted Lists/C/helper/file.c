#include "../shared.h"

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
		fclose(fp);
		return result;
	}
	fclose(fp);

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

IntArray* createCases(char* filename, int* returnSize) {
	FILE* fp = fopen(filename, "r");
	if(!fp) return NULL;

	char** lines = calloc(1, sizeof(char*));
	char* line = NULL;
	size_t n = 0;

	int linesRead = 0;
	while(getline(&line, &n, fp) != -1) {
		lines = realloc(lines, (linesRead + 1) * sizeof(char*));
		lines[linesRead++] = strdup(line);
	}
	free(line);
	fclose(fp);

	IntArray* result = calloc(linesRead, sizeof(IntArray));

	for(int i = 0; i < linesRead; ++i) {
		char* token = strtok(lines[i] + 1, ",");
		int j = 0;

		result[i].arr = calloc(1, sizeof(int));

		while(token != NULL) {
			int num = strtol(token, NULL, 10);

			result[i].arr = realloc(result[i].arr, ((j + 1) * sizeof(int)));
			result[i].arr[j++] = num;

			token = strtok(NULL, ",");
		}

		result[i].size = j;
	}

	for(int i = 0; i < linesRead; ++i) {
		free(lines[i]);
	}
	free(lines);

	*returnSize = linesRead;

	return result;
}

void freeIntArrayArray(IntArray* array, int arraySize) {
	for(int i = 0; i < arraySize; ++i) {
		free(array[i].arr);
	}
	free(array);
}
