#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void * Hello(void * h)
{
    long hello = (long)h;
    printf("This is %lu\n",hello);
    return NULL;
}


int main(void)
{
    int count = 4;
    pthread_t *pth = (pthread_t*)malloc(sizeof(pthread_t) * count);

    for(long i = 0; i < count; i++){
        pthread_create(&pth[i],NULL,Hello,(void *)i);
        printf("create thread %ld \n", i);
    }  
    for(int i = 0; i < count; i++){
        pthread_join(pth[i],NULL);
        printf("over thread %d\n ", i);
    }

    free(pth);
    return 0;
}
