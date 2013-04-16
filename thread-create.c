#include <pthread.h>
#include <stdio.h>

struct char_print_param {
    char c;
    int count;
} /* optional variable list */;

void* char_print(void* param)
{
    struct char_print_param* p = (struct char_print_param*) param;
    int i;

    for (i = 0; i < p->count; ++i) {
        fputc(p->c, stderr);
    }

    return NULL;
}

int main(int argc, const char *argv[])
{
    pthread_t thread1_id, thread2_id;

    struct char_print_param thread1_args, thread2_args;

    thread1_args.c      = 'x';
    thread1_args.count  = 300;
    pthread_create(&thread1_id, NULL, &char_print, &thread1_args);

    thread2_args.c      = 'o';
    thread2_args.count  = 200;
    pthread_create(&thread2_id, NULL, &char_print, &thread2_args);

    // Make sure the thread1, thread2 has finished. 
    // Otherwise, they will use the args create by main().
    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);

    return 0;
}

