#include<iostream>
using namespace std;



const int MAX_NO = 100;


class ArrayList {
private:
    int data[MAX_NO];
    int size;
public:
    ArrayList() {
        size = 0;
    }


    //insrt an element at end of list 


    void InsertEnd(int value) {
        if (size < MAX_NO) {
            data[size++] = value;
        }
        else {
            cout << "Array is Full!!!\nCan't Insert\n\n";
        }
    }

    //Insert an Element at given position

    void InsertAt(int value, int position) {
        if (position > 0 && position <= size && size < MAX_NO) {
            for (int i = size; i > position; i--) {
                data[i] = data[i - 1];
            }
            data[position] = value;
            size++;
        }
        else {
            cout << "Error!!\n\n";
        }
        }

    //print the values 
    void Print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }


    //remove the value from array
    void Remove(int value ) {
        int i = 0;
        while (i < size) {
            int j = 0;
            if (data[i] == value) {
                for (int i = j; j < size - 1; j++) {
                    data[j] = data[j + 1];
                }
                size--;
            }
            else
            i++;
        }
    }


    //return if the array is empty or not 
    bool IsEmpty() {
        return size == 0;
    }

    //replace element at given position
    void Replace(int value,int position) {
        if (position < size && position >= 0) {
            data[position] = value;
        }
        else
        {
            cout << "Invalid!!! Retry \n\n";
        }
    }



    //clear the list

    void Clear() {
        size = 0;
    }


    //sorting 

    void Sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    
    }


    //search the element 
    int Search(int value ) {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == value) {
                return 1;
            }
           
        }
        return -1;
    }



    //dublication

    void Duplicate() {
        if (size * 2 <= MAX_NO) {
            for (int i = 0; i < size; i++) {
                data[size + i] = data[i];
            }
            size *= 2;
        }
        else {
            cout << "List size would exceed the maximum limit. Cannot duplicate." << endl;
        }
        }
    
};














int main() {
    ArrayList list;

    // Insert elements at the end
    list.InsertEnd(10);
    list.InsertEnd(20);
    list.InsertEnd(30);

    // Insert an element at a given position
    list.InsertAt(15, 1);

    // Print the list
    list.Print(); // Output: 10 15 20 30

    // Check if the list is empty
    cout << "Is the list empty? " << (list.IsEmpty() ? "Yes" : "No") << endl;

    // Replace an element at a given position
    list.Replace(25, 2);

    // Print the list after replacing
    list.Print(); // Output: 10 15 25 30

    // Sort the list
    list.Sort();

    // Print the sorted list
    list.Print(); // Output: 10 15 25 30

    // Search for an element
    int searchElement = 15;
    int position = list.Search(searchElement);
    if (position != -1) {
        cout << "Element " << searchElement << " found at position " << position << endl;
    }
    else {
        cout << "Element " << searchElement << " not found in the list" << endl;
    }

    // Remove an element
    list.Remove(15);

    // Print the list after removal
    list.Print(); // Output: 10 25 30

    // Duplicate the list
    list.Duplicate();

    // Print the duplicated list
    list.Print(); // Output: 10 25 30 10 25 30

    return 0;
}