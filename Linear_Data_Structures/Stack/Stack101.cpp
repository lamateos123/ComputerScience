//Stack101 - The end of the vector is the input. 
//The push_back and pop_back operations cost O(1)
#include<iostream>
#include<vector>

using namespace std;

class Stack{
    public:
    vector<int> items;
    
    bool is_empty(){
        //test to see if the stack is empty
        //no parameter
        //return bool
        if (items.size() == 0) return true;
        return false;
    }

    void push(int item){
        //adds a new item to the top of the stack
        //item as parameter
        //return nothing
        items.push_back(item);
    }

    int pop(){
        //removes the top item from the stack
        //no parameter
        //return item integer
        int temp = items[items.size()-1];
        items.pop_back();
        return temp;
    }

    int peek(){
        //return the top item from the stack
        //no parameter
        //the stack is not modified
        return items[items.size()-1];
    }

    int size(){
        //return the number of items in the stack
        //no parameter
        return items.size();
    }

    void print(){
        //prints the stack items
        for (int i=0; i<items.size(); i++){
            cout << items[i] << ", ";
        }
        cout << endl;
    }
};

/*
~/Desktop/ComputerScience/Linear_Data_Structures/Stack$ ./Stack101
is Stack empty: true
Peek: 5
Size: 3
4, 5, 8, 3, 
pop: 3
pop: 8
pop: 5
*/





int main(){
    Stack s;
    cout << "is Stack empty: " << boolalpha << s.is_empty() << endl;

    s.push(4);
    s.push(5);
    cout << "Peek: " << s.peek() << endl;

    s.push(8);
    cout << "Size: " << s.size() << endl;

    s.push(3);
    s.print();

    cout << "pop: " << s.pop() << endl;
    cout << "pop: " << s.pop() << endl;
    cout << "pop: " << s.pop() << endl;


    return 0;
}