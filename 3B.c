#include <stdio.h>
#include <stdlib.h>

#define LEN 100005

typedef struct pp {
    char name[100];
    int time;
} Process;

Process Q[LEN];
int head = 0;
int tail = 0;

void enqueue(Process x) {
    Q[tail] = x;
    if (tail + 1 == LEN) {
        tail = 0;
    }
    else {
        tail++;
    }
}

Process dequeue() {
    Process x = Q[head];
    if (head + 1 == LEN) {
        head = 0;
    }
    else {
        head++;
    }
    return x;
}

int main(void) {
    int elaps = 0; // 経過時間
    int i;
    int n;
    int quantum;
    Process u;
    scanf("%d %d", &n, &quantum);

    for (i = 1; i <= n; i++) {
        Process p1;
        scanf("%s", &p1.name);
        scanf("%d", &p1.time);
        enqueue(p1);
    }

    while (head != tail) {
        Process p2 = dequeue();
        if (p2.time > quantum) {
            elaps += quantum;
            p2.time -= quantum;
            enqueue(p2);
        } else {
            elaps += p2.time;
            printf("%s %d\n", p2.name, elaps);
        }
    }

    return 0;
}
