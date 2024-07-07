#include<iostream>
using namespace std;

struct Node {
	int StudentID;
	string StudentName;
	float GPA;
	Node* next;

	Node(int a, string b, float c) {
		StudentID = a;
		StudentName = b;
		GPA = c;
		next = nullptr;
	}
};

class LinkedList {
public:
	Node* head;
	LinkedList() {
		head = nullptr;
	}





	void findAndUpdateGPA(int id, float newGPA) {
		Node* current = head;
		while (current != nullptr) {
			if (current->StudentID == id) {
				current->GPA = newGPA;
				return;
			}
			current = current->next;
		}
		cout << "Student with ID " << id << " not found." << endl;
	}

	void insertInSortedOrder(int id, const string& name, float gpa) {
		Node* newNode = new Node(id, name, gpa);

		if (head == nullptr || id < head->StudentID) {
			newNode->next = head;
			head = newNode;
			return;
		}

		Node* current = head;
		while (current->next != nullptr && id > current->next->StudentID) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}


	void calculateAverageGPA() {
		if (head == nullptr) {
			cout << "The list is empty." << endl;
			return;
		}



		float totalGPA = 0.0;
		int count = 0;
		Node* current = head;
		while (current != nullptr) {
			totalGPA += current->GPA;
			count++;
			current = current->next;
		}





		float averageGPA = totalGPA / count;
		cout << "Average GPA of all students: " << averageGPA << endl;
	}


	


	void findLowestGPA() {
		if (head == nullptr) {
			cout << "The list is empty." << endl;
			return;
		}

		float lowestGPA = head->GPA;
		Node* current = head;

		while (current != nullptr) {
			if (current->GPA < lowestGPA) {
				lowestGPA = current->GPA;
			}
			current = current->next;
		}

		cout << "Student(s) with the lowest GPA (" << lowestGPA << "):" << endl;
		current = head;

		while (current != nullptr) {
			if (current->GPA == lowestGPA) {
				cout << "Student ID: " << current->StudentID << ", Name: " << current->StudentName << endl;
			}
			current = current->next;
		}
	}
	void findHighestGPA() {
		if (head == nullptr) {
			cout << "The list is empty." << endl;
			return;
		}

		float highestGPA = head->GPA;
		Node* current = head;

		while (current != nullptr) {
			if (current->GPA > highestGPA) {
				highestGPA = current->GPA;
			}
			current = current->next;
		}

		cout << "Student(s) with the highest GPA (" << highestGPA << "):" << endl;
		current = head;

		while (current != nullptr) {
			if (current->GPA == highestGPA) {
				cout << "Student ID: " << current->StudentID << ", Name: " << current->StudentName << endl;
			}
			current = current->next;
		}
	}

};






int main() {
	LinkedList studentList;

	
	studentList.insertInSortedOrder(51, "ali", 3.8);
	studentList.insertInSortedOrder(52, "asim", 1.5);
	studentList.insertInSortedOrder(53, "muneer", 2.9);
	studentList.insertInSortedOrder(54, "bajwa", 2.5);

	studentList.findAndUpdateGPA(103, 4.0);

	studentList.calculateAverageGPA();

	studentList.findHighestGPA();

	studentList.findLowestGPA();

	return 0;
}

