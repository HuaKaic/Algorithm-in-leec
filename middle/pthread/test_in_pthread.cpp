#include <pthread.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;

#define MAX 50
int number;
pthread_mutex_t mutex; // 创建线程锁
struct Exam {
    int age;
    int height;
};
void* callback1(void* arg) {
    pthread_mutex_lock(&mutex); // 加上线程锁
    printf("sub pthread:%ld\n", pthread_self());
    printf("callback1\n");
    // static Exam test;
    Exam* test = (Exam*) arg;
    test->age = 25;
    test->height = 173;
    // pthread_exit(&test);
    Sleep(3000);
    pthread_mutex_unlock(&mutex); // 解除线程锁
    return NULL;
}
void* callback2(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("sub pthread:%lu\n", pthread_self());
    printf("callback2\n");
    pthread_mutex_unlock(&mutex);
    return NULL;

}
int main() 
{  
    Exam test;
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, callback1, &test);
    pthread_create(&t2, NULL, callback2, &test);
    printf("main pthred:%ld\n", pthread_self());
    // Sleep(3);
    // pthread_exit(NULL);
    void* ptr; // 指向子线程传出参数指针的地址
    pthread_join(t1, &ptr); // 线程堵塞，等待子线程结束
    pthread_join(t2, NULL);
    struct Exam* pt = (struct Exam*) ptr;
    // cout << pt->age << pt->height << endl;
    // pthread_detach(ti); 将主线程与子线程分离
    printf("%d\n",test.age);
    pthread_mutex_destroy(&mutex);
    return 0; 
}
