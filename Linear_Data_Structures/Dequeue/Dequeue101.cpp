//Dequeue rear is index [0], while queue front is [-1]
#include<iostream>
#include<vector>

using namespace std;

class Dequeue{
    public:
    vector<int> items;

    bool is_empty(){
        //check if the dequeue is empty
        //no parameter
        //return bool
        if (items.size()==0) return true;
        return false;
    }

    void add_front(int item){
        //add an element on the front
        // item as parameter
        //no return
        items.push_back(item);
    }

    void add_rear(int item){
        //adds an element on the rear
        //item as parameter
        //no return
        items.insert(items.begin(), item);
    }

    int remove_front(){
        //removes the front element
        //no parameter
        //return front item
        int temp = items[items.size()-1];
        items.pop_back();
        return temp;
    }

    int remove_rear(){
        //removes the rear element
        //no parameter
        //return rear item
        int temp = items[0];
        items.erase(items.begin());
        return temp;
    }

    int size(){
        //return the size of the dequeue
        //no parameter
        return items.size();
    }

    void print(){
        //print the items in the dequeue
        for (int i=0; i<items.size(); i++){
            cout << items[i] << ", ";
        }
        cout << endl;
    }
};

int main(){
    Dequeue d;
    cout << "is Dequeue empty: " << boolalpha << d.is_empty() << endl;

    d.add_front(1);
    d.add_rear(9);
    d.add_front(2);
    d.add_front(3);
    d.add_rear(8);
    cout << "Dequeue size: " << d.size() << endl;

    d.print();

    d.remove_front();
    cout << "is Dequeue empty: " << boolalpha << d.is_empty() << endl;

    d.print();

    d.remove_rear();
    d.print();

}
/*
~/Desktop/ComputerScience/Linear_Data_Structures/Dequeue$ ./Dequeue101 
is Dequeue empty: true
Dequeue size: 5
8, 9, 1, 2, 3, 
is Dequeue empty: false
8, 9, 1, 2, 
9, 1, 2, 
*/