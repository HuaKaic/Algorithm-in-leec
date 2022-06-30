#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;

sem_t sem1;
sem_t sem2;
pthread_mutex_t mutex;

struct Node {
    int number;
    Node* next;
    Node(int i): number(i) { };
};
Node* head = NULL;

void* producer(void*) {
    while (1) {
        sem_wait(&sem1); // 判断生产者的资源数，
        pthread_mutex_lock(&mutex);
        Node* newnode = new Node(abs(rand()) % 1000);
        newnode->next = head;
        head = newnode;
        printf("producer, id: %ld, number: %d\n", pthread_self(), newnode->number);
        pthread_mutex_unlock(&mutex);
        sem_post(&sem2);
        Sleep(rand() % 100);
    }
    return NULL;
}

void* consumer(void*) {
    while (1) {
        sem_wait(&sem2); // 判断是否还有资源
        pthread_mutex_lock(&mutex); // 注意互斥锁的位置，实现线程的顺序顺序执行
        Node* node = head;
        printf("consumer, id: %ld, number: %d\n", pthread_self(), node->number);
        head = head->next;
        free(node);
        pthread_mutex_unlock(&mutex);
        sem_post(&sem1);
        Sleep(rand() % 100);
    }
    return NULL;
}

int main() {
    sem_init(&sem1, 0, 6 ); // 第二个数字：0表示线程同步，非零表示进程同步
    sem_init(&sem2, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_t t1[5], t2[5];
    for (int i = 0; i < 5; i++) {
        pthread_create(&t1[i], NULL, producer, NULL);
        pthread_create(&t2[i], NULL, consumer, NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(t1[i], NULL);
        pthread_join(t2[i], NULL);
    }


    pthread_mutex_destroy(&mutex);
    sem_destroy(&sem1);
    sem_destroy(&sem2);

}
