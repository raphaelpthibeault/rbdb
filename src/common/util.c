#include <util.h>

static char *parse_file(const char *);

char *extract_text(const char *filename) {
    char *ext = strrchr(filename, '.');
    if (ext == NULL) {
        return NULL;
    } else if (strcmp(ext, ".bdb") != 0) {
        return NULL;
    }
    return parse_file(filename);
}

char *parse_file(const char *filename) {
    FILE *file;
    long fsize;
    char *content;
    unsigned long read;

    file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    fsize = ftell(file);
    rewind(file);

    content = malloc(fsize + 1);
    read = fread(content, 1, fsize, file);
    fclose(file);
    if (read != fsize) {
        fprintf(stderr, "Error reading %s\n", filename);
        exit(1);
    }

    content[fsize] = '\0';
    return content;
}
