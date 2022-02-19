#include <pthread.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;

#define MAX 50
int number;
pthread_rwlock_t rwlock; // 创建读写线程锁
struct Exam {
    int age;
    int height;
};
void* read_num(void* arg) {
    for (int j = 0; j < MAX; j++) {
        pthread_rwlock_rdlock(&rwlock); // 加上读线程锁
        printf("read pthread:%lu, %d\n", pthread_self(), number);
        Sleep(rand() % 5);
        pthread_rwlock_unlock(&rwlock); // 解除读线程锁
    }
    
    return NULL; // 多个线程能个同步读取公共资源，意味着可以多个线程读到同一个数字
}
void* write_num(void* arg) {
    for (int i = 0; i < MAX; i++) {
        pthread_rwlock_wrlock(&rwlock);
        int cur = number;
        cur++;
        number = cur;
        printf("write pthread:%lu, %d\n", pthread_self(), number);
        pthread_rwlock_unlock(&rwlock);
        Sleep(5);
    }
    return NULL;

}
int main() 
{  
    Exam test;
    pthread_t p1[5], p2[3];
    pthread_rwlock_init(&rwlock, NULL);
    for (int i = 0; i < 5; i++) {
        pthread_create(&p1[i], NULL, read_num, &test);
    }
    for (int j = 0; j < 3; j++) {
        pthread_create(&p2[j], NULL, write_num, &test);
    }
    for (int j = 0; j < 3; j++) {
        pthread_join(p2[j], NULL);
    }
    for (int j = 0; j < 5; j++) {
        pthread_join(p1[j], NULL); // 线程堵塞，等待子线程结束
    }
    
    pthread_rwlock_destroy(&rwlock);

    return 0; 
}
