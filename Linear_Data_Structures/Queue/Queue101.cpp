//Queue rear is index [0], while queue front is [-1]
#include<iostream>
#include<vector>

using namespace std;

class Queue{
    public:
    vector<int> items;

    bool is_empty(){
        //test to see if the queue is empty
        //no parameter
        //return bool
        if (items.size()==0) return true;
        return false;
    }

    void enqueue(int item){
        //adds a new item to the rear of the queue
        //requires an item
        //no return
        items.insert(items.begin(),item);
    }

    int dequeue(){
        //removes the front item from the queue
        //no parameter
        //return the front item
        int temp = items[items.size()-1];
        items.pop_back();
        return temp;
    }

    int size(){
        //returns the number of items in the queue
        //no parameter
        return items.size();
    }

    void print(){
        //prints the queue items
        for (int i=0; i<items.size(); i++){
            cout << items[i] << ", ";
        }
        cout << endl;
    }

};

int main(){
    Queue q;
    cout << "is Queue empty? " << boolalpha << q.is_empty() << endl;

    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(9);
    cout << "Queue size: " << q.size() << endl;

    q.enqueue(2);
    q.print();

    cout << "Queue dequeue: "<< q.dequeue() << endl;
    cout << "Queue dequeue: "<< q.dequeue() << endl;

    cout << "Queue size: " << q.size() << endl;

    q.print();

    return 0;
}

/*
~/Desktop/ComputerScience/Linear_Data_Structures/Queue$ ./Queue101 
is Queue empty? true
Queue size: 3
2, 9, 5, 4, 
Queue dequeue: 4
Queue dequeue: 5
Queue size: 2
2, 9, 
*/