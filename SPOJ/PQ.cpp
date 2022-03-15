#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
 
/* Struktur Node */
 
typedef struct queueNode_t {
    int data, index;
    struct queueNode_t *next;
} QueueNode;
 
/* Struktur ADT Queue */
 
typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;
 
typedef struct pqueueNode_t {
    int data;
    struct pqueueNode_t *next;
} PQueueNode;
 
/* Struktur ADT PriorityQueue menggunakan Linked List */
 
// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;
 
/* Function prototype */
 
void queue_init(Queue *); //mendeklarasi fungsi untuk inisialisasi queue
void pqueue_init(PriorityQueue *); //mendeklarasi fungsi untuk inisialisasi pqueue
bool queue_isEmpty(Queue *); //mendeklarasi fungsi untuk mengecek apakah queue kosong atau tidak
bool pqueue_isEmpty(PriorityQueue *); //mendeklarasi fungsi untuk mengecek apakah pqueue kosong atau tidak
void queue_push(Queue *, int ,int); //mendeklarasi fungsi untuk memasukkan nilai kedalam queue
void pqueue_push(PriorityQueue *, int ); //mendeklarasi fungsi untuk memasukkan nilai kedalam pqueue
void queue_pop(Queue *); //mendeklarasi fungsi untuk menghapus nilai pada queue
void pqueue_pop(PriorityQueue *); //mendeklarasi fungsi untuk menghapus nilai pada pqueue
int  pqueue_top(PriorityQueue *); //mendeklarasi fungsi untuk mendapatkan nilai pada elemen teratas pqueue
int  queue_front(Queue *); //mendeklarasi fungsi untuk mendapatkan nilai pada elemen terdepan queue
int  queue_front_index(Queue *); //mendeklarasi fungsi untuk mendapatkan nilai pada elemen terbelakang queue
int solve (PriorityQueue *,Queue *,int);
 
/* Function definition below */
 
void queue_init(Queue *queue){
	// size diinisiasi dengan 0
    queue->_size = 0;
    // front diinisiasi dengan NULL
    queue->_front = NULL;
    // rear diinisiasi dengan NULL
    queue->_rear = NULL;
}

 
void pqueue_init(PriorityQueue *pqueue){
	// pqueue top diinisiasi dengan NULL
    pqueue->_top = NULL;
    // pqueue size diinisiasi dengan 0
    pqueue->_size = 0;
}

 
bool queue_isEmpty(Queue *queue){
    //mengembalikan nilai queue_isEmpty == true jika elemen terdepan dan terbelakang queue NULL
    return (queue->_front == NULL && queue->_rear == NULL); 
}

 
bool pqueue_isEmpty(PriorityQueue *pqueue){
    //mengembalikan nilai pqueue_isEmpty == true jika elemen teratas pqueue NULL
    return (pqueue->_top == NULL);
}


 
void queue_push(Queue *queue, int value, int index){
    // menginisiasi node baru untuk menyimpan data-data yang akan dimasukkan di dalam queue
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    //membuat kondisi jika node baru !NULL
    if (newNode) {
        //melakukan increment pada nilai size
        queue->_size++;
        //melakukan inisiasi terhadap node baru dengan data data yang akan ditambahkan
        newNode->data = value;
        newNode->index = index;
        newNode->next = NULL;
        //membuat kondisi untuk mengecek apakah queue kosong atau tidak
        if (queue_isEmpty(queue))   
            // jika queue masih kosong maka element paling belakang dan paling depan diinisasi dengan node baru               
            queue->_front = queue->_rear = newNode;
        else {
            // jika queue tidak kosong node baru akan diletakkan di posisi paling belakang
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}
 
void pqueue_push(PriorityQueue *pqueue, int value){
    // melakukan deklarasi terhadap variable node temp, dan newNode
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;
    //membuat kondisi jika node kosong, maka data terbaru akan ditambahkan ke pada posisi top
    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }
    /*
    membuat kondisi jika data yang diinput lebih besar dari pada elemen teratas, maka nilai akan dimasukan pada elemen teratas
    dan nilai yang sebelumnya berada di elemen teratas, dipindahkan pada elemen setelah elemen teratas
    */
    if (value > pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    /*
	jika data yang diinput lebih kecil dari pada elemen teratas, maka node temp	akan menelusuri list hingga mencapai posisi yang sesuai, 
    dan nilai yang dimasukkan akan diletakkan pada posisi tersebut
    */
    else {
        while ( temp->next != NULL && 
                temp->next->data > value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
 
void queue_pop(Queue *queue){
    //membuat kondisi jika queue tidak kosong
    if (!queue_isEmpty(queue)){
        //memindahkan value dari elemen terdepan queue pada variable temp
        QueueNode *temp = queue->_front;
        //memindahkan value dari elemen setelah terdepan queue pada posisi elemen terdepan
        queue->_front = queue->_front->next;
        //membebaskan variable temp
        free(temp);
        //jika elemen terdepan queue kosong
        if (queue->_front == NULL)
            //set elemen terbelakang queue menjadi NULL
            queue->_rear = NULL;
        //melakukan decrement pada size queue
        queue->_size--;
    }
}
 
void pqueue_pop(PriorityQueue *pqueue){
    //membuat kondisi jika pqueue tidak kosong
    if (!pqueue_isEmpty(pqueue)) {
        //memindahkan value dari elemen teratas pqueue pada variable temp
        PQueueNode *temp = pqueue->_top;
        //memindahkan value dari elemen setelah teratas pqueue pada posisi elemen teratas
        pqueue->_top = pqueue->_top->next;
        //membebaskan variable temp
        free(temp);
    }
}
 
int pqueue_top(PriorityQueue *pqueue) {
    //membuat kondisi jika pqueue tidak kosong
    if (!pqueue_isEmpty(pqueue))
        //mengembalikan nilai posisi teratas pqueue
        return pqueue->_top->data;
    //jika pqueue kosong mengembalikan nilai 0
    else return 0;
}
 
int queue_front(Queue *queue){
    //membuat kondisi jika queue tidak kosong
    if (!queue_isEmpty(queue)) {
        //mengembalikan nilai posisi terdepan pqueue
        return (queue->_front->data);
    }
    //jika queue kosong mengembalikan nilai 0
    return (int)0;
}
 
int queue_front_index(Queue *queue){
    //membuat kondisi jika queue tidak kosong
    if (!queue_isEmpty(queue)) {
        //mengembalikan nilai posisi index terdepan pqueue
        return (queue->_front->index);
    }
    //jika queue kosong mengembalikan nilai 0
    return (int)0;
}
 
int main(){
    PriorityQueue jobs;
    Queue main_jobs;
    //menginisialisasi variable t untuk jumlah test case
	int t;
    //melakukan pada jumlah test case
	scanf("%d",&t);
    //membuat perulangan dengan argumen jumlah test case lebih besar dari 0
	while(t>0){
        //menginisialisasi pqueue
		pqueue_init(&jobs);
        //menginisialisasi queue
		queue_init(&main_jobs);
        //menginisialisasi variable n dan m
		int n,m;
        //melakukan input pada variable n dan m
		scanf("%d %d",&n,&m);
        //membuat perulangan dengan parameter j antara 0 sampai j<n
		for(int j=0;j<n;j++){
            //menginisialisasi variable form
			int form;
            //melakukan input pada variable from
			scanf("%d",&form);
            //memasukan nilai form pada pqueue
			pqueue_push(&jobs,form);
            //memasukan nilai form pada queue dengan index j
			queue_push(&main_jobs,form,j);
		}
        //print out hasil output
		printf("%d\n",solve(&jobs,&main_jobs,m));
        //melakukan decrement pada test case
		t--;
	}
	return 0;
}
 
int solve (PriorityQueue *pqueue,Queue *queue,int m){
    //mendeklarasikan variabel time dengan nilai 1
	int time=1;
    //membuat perulangan dengan argumen sampai queue atau pqueue tidak kosong
	while(!queue_isEmpty(queue) || !pqueue_isEmpty(pqueue)){
            //membuat kondisi jika nilai posisi terdepan index queue = m dan posisi terdepan queue = posisi teratas queue
			if(queue_front_index(queue) == m && queue_front(queue)==pqueue_top(pqueue)){
                //mengembalikan nilai dari variabel time
				return time;
				break;
			}
            //membuat kondisi jika posisi terdepan queue lebih kecil dari posisi teratas pqueue
			if(queue_front(queue)<pqueue_top(pqueue)){
                //memasukan posisi terdepan dari queue kedalam queue
				queue_push(queue, queue_front(queue), queue_front_index(queue));
                //menghapus data pada posisi terdepan queue
				queue_pop(queue);
			}
			else{
                //melakukan increment pada nilai variabel time
				time++;
                //menghapus data pada posisi terdepan queue
				queue_pop(queue);
                //menghapus data pada posisi teratas pqueue
				pqueue_pop(pqueue);
			}
		}
}