#include <pthread.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;

pthread_cond_t cond;
pthread_mutex_t mutex;

struct Node {
    int number;
    Node* next;
    Node(int i): number(i) { };
};
Node* head = NULL;

void* producer(void*) {
    while (1) {
        pthread_mutex_lock(&mutex);
        Node* newnode = new Node(abs(rand()) % 1000);
        newnode->next = head;
        head = newnode;
        printf("producer, id: %ld, number: %d\n", pthread_self(), newnode->number);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        Sleep(rand() % 100);
    }
    return NULL;
}

void* consumer(void*) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (head == NULL) {
            pthread_cond_wait(&cond, &mutex); // 自动释放互斥锁，打开上面的锁
        }
        Node* node = head;
        printf("consumer, id: %ld, number: %d\n", pthread_self(), node->number);
        head = head->next;
        free(node);
        pthread_mutex_unlock(&mutex);
        Sleep(rand() % 100);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
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
    pthread_cond_destroy(&cond);

}