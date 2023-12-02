#include <stdio.h>
#include <string.h>

// Function to replace a word in a string
void replaceWord(char *str, const char *oldWord, const char *newWord) {
    char *pos = strstr(str, oldWord);

    if (pos != NULL) {
        int len = strlen(oldWord);
        int newLen = strlen(newWord);

        // Shift the remaining characters to the right
        memmove(pos + newLen, pos + len, strlen(pos + len) + 1);

        // Copy the new word in the place of the old word
        memcpy(pos, newWord, newLen);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("demo.txt", "r");

    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    outputFile = fopen("your_file_modified.txt", "w");

    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    // Word replacements
    char *wordMapping[][2] = {
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"}
    };

    // Read and replace words
    char line[512]; // Adjust the buffer size as needed
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Replace each word in the line
        for (size_t i = 0; i < sizeof(wordMapping) / sizeof(wordMapping[0]); ++i) {
            replaceWord(line, wordMapping[i][0], wordMapping[i][1]);
        }

        // Write the modified line to the output file
        fputs(line, outputFile);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("File has been modified successfully.\n");

    return 0;
}
