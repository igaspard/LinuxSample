#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, const char *argv[])
{
    char *android_java_path = getenv("ANDROID_JAVA_TOOLCHAIN");
    char *debug = getenv("ENABLE_MEDIASERVER_DEBUG");
    
    if (android_java_path != NULL) {
        /* code */
        printf("%s\n", android_java_path);
    }

    if (debug != NULL) {
        /* code */
        printf("Enable Debug: %s\n", debug);
    }
    else {
        printf("Not Debug\n");
    }

    printf("argc: %d\n", argc);
    if (argc > 1) {
        if (!strcmp(argv[1], "debug")) {
            printf("Debug mode, argv[%d]: %s\n", 1, argv[1]);
        }
        else {
            printf("argv[%d]: %s\n", 1, argv[1]);
        }
    }
    return 0;
}
