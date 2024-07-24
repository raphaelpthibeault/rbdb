#include <stdio.h>
#include <stdlib.h>

#include <util.h>
#include <db_pages.h>

int
main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s <file.bdb>\n", *argv);
        exit(1);
    }

    char *filename = argv[1];
    char *content = extract_text(filename);

    /*
    for (int i = 0; i < 511; ++i)
        printf("%d", content[i]);
    printf("\n");
    */

    free(content);
    return 0;
}
