#include <iostream>
using namespace std;
#define MAX_SIZE 50

class Queue{
    private:
        int A[MAX_SIZE];
        int front, rear;
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        bool IsEmpty(){
            return (front == -1 && rear == -1);
        }
        bool IsFull(){
            return (rear + 1) % MAX_SIZE == front ? true : false;
        }
        void Enqueue(int x){
            cout << "Enqueuing " << x << endl;
            if (IsFull()){
                cout << "Error: Queue is Full" << endl;
                return;
            }
            if (IsEmpty()){
                front = rear = 0;
            }
            else {
                rear = (rear + 1) % MAX_SIZE;
            }
            A[rear] = x;
        }
        void Dequeue(){
            cout << "Dequeuing " << endl;
            if (IsEmpty()){
                cout << "Error: Queue is Empty" << endl;
                return;
            }
            else if (front == rear){
                rear = front = -1;
            }
            else {
                front = (front + 1) % MAX_SIZE;
            }
        }
        int Front(){
            if (front == -1){
                cout << "Error: Queue is Empty" << endl;
                return -1;
            }
            else {
                return A[front];
            }
        }
        void Print(){
            int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
            cout << "Queue: " << endl;
            for (int i=0; i<count; i++){
                int index = (front + i) % MAX_SIZE;
                cout << A[index] << " ";
            }
            cout << endl;
        }
};

int main(){
   Queue Q; 
   Q.Enqueue(0);  Q.Print();  
   Q.Enqueue(1);  Q.Print();  
   Q.Enqueue(2);  Q.Print();
   Q.Enqueue(3);  Q.Print();    
   Q.Dequeue();   Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Enqueue(4);  Q.Print();
   Q.Enqueue(5);  Q.Print();
   system("pause");
   return 0;
}
