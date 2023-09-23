#include <iostream>
using namespace std;

enum Codes { // ������������ ��� ������ ����.
	������, �����
};
bool Work = ������;

class List
{
private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* head;
public:
	List() // �����������
	{
		head = nullptr;
	}
	~List() { // ����������
		while (head != NULL) {
			DeleteFirstElement();
		}
	}

	int SearchLastListinList(List list) // ����� ���������� ��������� ������� ������ � ������.
	{
		bool comparise = false;
		int LastIndex = 0;
		int CurrIndex = 0;
		bool NotEmpty = !list.CheckEmptyList();
		if (NotEmpty) {
			Node* current = head;
			while (current != NULL && current->next != NULL) {
				comparise = false;
				if (current->data == list.head->data) {
					comparise = true;
					Node* ListCurrent = list.head;
					while (current->next != nullptr && ListCurrent->next != nullptr && comparise)
					{
						current = current->next;
						CurrIndex++;
						ListCurrent = ListCurrent->next;
						if (ListCurrent->data != current->data)
						{
							comparise = false;
						}
					}
				}
				if (comparise)
				{
					LastIndex = CurrIndex;
				}
				CurrIndex++;
				current = current->next;
			}
		}
		if (NotEmpty) {
			return LastIndex;
		}
		else return 1;
	}

	int SearchFirstListinList(List list) // ����� ������� ��������� ������� ������ � ������.
	{
		bool comparise = false;
		bool exit = false;
		int FirstIndex = 0;
		int CurrIndex = 0;
		bool NotEmpty = !list.CheckEmptyList(); // ��� ������ ���� ��� �� ����
		if (NotEmpty) { // ���� ��� ������ �� ������
			Node* current = head; // ������ ������� �������, ������� �������� ��������� �������� ������� ������.
			// ���������������� ��������� ��������� ��������� ������ � �������� ��������� ������������ ������.
			while (current != NULL && current->next != NULL && !exit) { // ���� ������ ���� ������� � ����������� �� ����� 0.
				comparise = false; 
				if (current->data == list.head->data) { // ���� �������� ��������� �������.
					// ���� �������� �������, �� ��������������� ����������� ��������� ��������.
					comparise = true;
					Node* ListCurrent = list.head;
					while (current->next != NULL && ListCurrent->next != NULL && comparise) {
						current = current->next;
						CurrIndex++;
						ListCurrent = ListCurrent->next;
						if (ListCurrent->data != current->data) {
							comparise = false;
						}
					}
				}
				if (comparise) { // ���� ���������, �� ������������ ������.
					FirstIndex = CurrIndex;
					exit = true;
				}
				CurrIndex++; // ����������� ������.
				current = current->next; // ������� � ���������� ��������.
			}
		}
		if (NotEmpty) {
			return FirstIndex - 2;
		}
		else return 1;
	}
	bool CheckEmptyList() // �������� �� ������� ������.
	{
		return head == NULL; // ���� �������� ������� ������ �� �����, �� ������ ����.
	}
	int GetLengthList() // ��������� ������� ������.
	{
		int length = 0;
		if (!CheckEmptyList()) { // ���� ������ ��������, �� ���������� �� ���� ��� ��������� � ������������ ��.
			for (Node* current = head; current->next != NULL; current = current->next) {
				length++;
			}
			length++; // ����������, ��� ��� ������ ���� � 0 �������.
		}
		return length;
	}
	int GetElementbyIndex(int index) // ��������� �������� �� �������.
	{
		Node* current = head;  
		if (GetLengthList() < index || index < 0) { // �������� ��������� �������.
			cout << " ���������� ���������� ���� ������.\n";
		}
		else { // � ���� ������ �������������, �� ��������� �� ������� �������.
			for (int i = 0; i < index; i++) { // ����������� � ������� ��������.
				current = current->next;
			}
		}
		return current->data; // � ���������� �������� ��������.
	}
	void ReplacementTwoElements(List& list, int index1, int index2) // ����� ���� ��������� ������ �� ��������.
	{
		if ((index1 >= 0 && index2 >= 0) && (list.GetLengthList() > index1 && (list.GetLengthList() > index2))) { // �������� �������� ��������.
			int element;
			Node* current = head; // �������� ����.
			for (int i = 0; i < index1; i++) { // ����������� � ������� ��������.
				current = current->next;
			}
			Node* ListCurrent = list.head; 
			for (int i = 0; i < index2; i++) {
				ListCurrent = ListCurrent->next;
			}
			element = current->data;
			current->data = ListCurrent->data;
			ListCurrent->data = element;
		}
		else {
			cout << "���������� ���������� ����(~���) ������(-�).";
		}
	}
	void Reverse() // ������ ������� ��������� � ������ �� ��������. 
	{
		int element;
		Node* current = head;
		for (int i = 0; i < GetLengthList(); i++) { // �������� �� ������, ������� ��������, ����� ���������, ����� �� 1 �������.
			current = head;
			element = current->data; // ���������� ������ �������.
			for (int j = 0; j < GetLengthList() - i - 1; j++) { // ��������� �� ���� ���������, ����� ����, ������� ���������.
				current->data = current->next->data;
				current = current->next;
			} 
			current->data = element; // � ���������� �������� ������������ �������� ������� ��������.
		}
	}
	void ReplacementElementbyIndex(int data, int index) // ������ �������� �� ������� �� ������������ �������.
	{
		if (GetLengthList() < index || index < 0) {
			cout << " ���������� ���������� ���� ������.\n";
		}
		else {
			Node* current = head;
			for (int i = 0; i < index; i++) { // ������� �� ������� �������.
				current = current->next;
			}
			current->data = data; // � ������ �������� ��������.
		}
	}
	void DeleteAllElements() // �������� ���� ��������� ������.
	{
		if (!CheckEmptyList()) {
			while (!CheckEmptyList()) { // ���� ������ �� ������, ������� ������ �������.
				DeleteFirstElement();
			}
			cout << "���  ������ ����!";
		}
		else {
			cout << "�������� �� ���������, ��� ��� ������ ������.\n";
		}
	}
	void DeleteElementbyIndex(int index) // �������� �������� �� �������.
	{
		if (GetLengthList() < index || index < 0) {
			cout << " ���������� ���������� ���� ������.\n";
		}
		else if (!CheckEmptyList()) { // ���� ������ ��������, �� ��� ������.
			if (index == 0) { // ���� ������� ������.
				DeleteFirstElement(); // �������� ������� ��������.
			}
			else {
				if (GetLengthList() - 1 == index) { // ���� ������� ���������.
					DeleteLastElement(); // �������� ���������� ��������.
				} 
				else { // ���� �� ������ � �� ���������.
					Node* current = head;
					for (int i = 0; i < index - 1; i++) { // ��� �� ������� �������.
						current = current->next;
					}
					Node* deleteNode = current->next; // ����������� ����� � ������� �������.
					current->next = deleteNode->next;
					delete deleteNode;
				}
			}
		}
		else {
			cout << "�������� �� ���������, ��� ��� ������ ������.\n";
		}
	}
	void DeleteFirstElement() // �������� ������� ��������.
	{
		if (!CheckEmptyList()) {
			Node* deleteNode = head; // ����������� ����� � ������� �������.
			head = deleteNode->next;
			delete deleteNode;
		}
		else {
			cout << "�������� �� ���������, ��� ��� ������ ������.\n";
		}
	}
	void DeleteLastElement() // �������� ����������� ��������.
	{
		if (!CheckEmptyList()) {
			Node* current = head;
			while ((current->next)->next != nullptr) { // ������� �� �������������� �������� � ������.
				current = current->next; // ������� ��������� ������� � ������.
			}
			Node* deleteNode = current->next; 
			current->next = nullptr; // ����������� ����� � ������� �������.
			delete deleteNode;
		}
		else {
			cout << "�������� �� ���������, ��� ��� ������ ������.\n";
		}
	}
	void AddListEnd(List& list) //  ������� ������ � ����� ������� ������. 
	{
		if (!list.CheckEmptyList()) {
			Node* ListCur = list.head;
			for (int i = 0; i < list.GetLengthList(); i++) {
				this->AddEnd(ListCur->data);
				ListCur = ListCur->next;
			}
		}
		else cout << "��������� ������, ��� ��� ������ ����.\n";
	}
	void AddListFirst(List& list)  // ������� ������ � ������ ������� ������. 
	{
		if (!list.CheckEmptyList()) {
			Node* ListCur = list.head;
			for (int i = 0; i < list.GetLengthList(); i++) {
				this->AddElementbyIndex(ListCur->data, i);
				ListCur = ListCur->next;
			}
		}
	}
	void AddListbyIndex(List& list, int index) // ������� ������� ������ � ������, ������� � �������. 
	{
		if (!list.CheckEmptyList()) {
			if (index >= 0 && list.GetLengthList() >= index) {
				if (index == 0) {
					AddListFirst(list);
				}
				else {
					if (index == list.GetLengthList()) {
						AddListEnd(list);
					}
					else {
						Node* current = head; // �������, ����� �������� ����� ������.
						for (int i = 0; i < index - 1; i++) {
							current = current->next;
						}
						Node* ListCurrent = list.head; // ��������� ������� ��������������� ������.
						while (ListCurrent->next != NULL) {
							ListCurrent = ListCurrent->next;
						}
						ListCurrent->next = current->next;
						current->next = list.head;
					}
				}
			}
			else {
				cout << "������ ���������� ���� ������.\n";
			}
		}
	}
	bool ComparisonList(List& list) { // �������� �� ���������� ������� ������ � ������. 
		bool comparison = false;
		bool NotEmpty = !list.CheckEmptyList();
		if (NotEmpty) {
			Node* current = head;
			while (current != NULL && current->next != NULL) {
				comparison = false;
				if (current->data == list.head->data) {
					comparison = true;
					Node* ListCur = list.head;
					while (current->next != NULL && ListCur->next != NULL && comparison) {
						current = current->next;
						ListCur = ListCur->next;
						if (ListCur->data != current->data) {
							comparison = false;
						}
					}
				}
				current = current->next;
			}
		}
		if (NotEmpty) {
			return comparison;
		}
		else return 0;
	}
	void AddElementbyIndex(int data, int index) // ���������� �������� �� �������.
	{
		if (GetLengthList() >= index && index >= 0) {
			if (index == 0) {
				AddFirst(data);
			}
			else {
				if (index == GetLengthList()) {
					AddEnd(data);
				}
				else {
					Node* newNode = new Node;
					newNode->data = data;
					Node* curr = head;
					for (int i = 0; i < index - 1; i++) {
						curr = curr->next;
					}
					newNode->next = curr->next;
					curr->next = newNode;
				}
			}
		}
		else {
			cout << " ���������� ���������� ���� ������.\n";
		}
	}
	void AddFirst(int data) // ���������� �������� � ������ ������.
	{
		Node* node = new Node;
		node->data = data;
		if (head == nullptr)
		{
			node->next = nullptr;
			head = node;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}
	void AddEnd(int data) // ���������� �������� � ����� ������.
	{
		Node* node = new Node;
		node->data = data;
		node->next = nullptr;
		if (head == nullptr)
		{
			node->next = nullptr;
			head = node;
		}
		else
		{
			Node* current = head;

			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = node;

		}
	}
	void Output() // ����� ��������� ������.
	{
		cout << "��� ������: ";
		for (Node* current = head; current != nullptr; current = current->next) {
			cout << current->data << ' ';
		}
		cout << "\n";
	}
};

void CheckEmpty(List* list) { // �������� �� ������� ������ � ����� ����������.
	bool check;
	check = list->CheckEmptyList(); // �������� true ��� false � ���������� �� ����, ����� �� ������ ������� NULL.
	if (check) { // ���� ����� true, �� ������, ����� ���-�� ����.
		cout << "��� ������ ����.\n";
	}
	else cout << "��� ������ �� ����.\n";
}

void Insertion_AddEnd(List* list) { // ���� �������� ��� ������� � �����, ���� ������� � ����� ������.
	int index, element;
	cout << "������� �������, ������� ������ ��������:\n";
	cin >> element;
	list->AddEnd(element); // ������� ��� ������ � ����� ������.
	list->Output(); // ����� ������.
}

void Insertion_AddFirst(List* list) { // ���� �������� ��� ������� � ������, ���� ������� � ����� ������. 
	int element;
	cout << "������� �������, ������� ������ ��������: \n";
	cin >> element;
	list->AddFirst(element); // ������� ��� ������� �������� � ������ ������.
	list->Output(); // ����� ������.
}

void Add_Insert(List* list1, List* list2) { // ������ ������� � ���������� ��������.
	cout << "\n����� ������ ����� �� ������ �����������?\n";
	cout << "1.���������� � ����� ������.\n" // Insertion - AddEnd(int element)
		<< "2.���������� � ������ ������.\n" // Insertion - AddFirst(int element)
		<< "3.���������� �������� �� ������� (������� ����� ���������, ������� ��� ����� �������� �� ����� �������).\n"
		<< "4.������� ������� ������ � ������, ������� � �������.\n"
		<< "5.������� ������� ������ � �����.\n"
		<< "6.������� ������� ������ � ������.\n"
		<< "7.��������� � ����.\n";
	int choice;
	cin >> choice;
	switch (choice) { // ����� ������� ������.
	case 1:
		Insertion_AddEnd(list1);
		break;
	case 2:
		Insertion_AddFirst(list1);
		break;
	case 3:
		int element, index;
		cout << "������� �������, ������� ������ ��������: \n";
		cin >> element;
		cout << "������� ������, ���� ���������� �������� �������: \n";
		cin >> index;
		list1->AddElementbyIndex(element, index);
		list1->Output();
		break;
	case 4:
		cout << "������� ������, ����� �������� ��������� �������� ������ ������ � ������: ";
		cin >> index;
		cout << endl;
		list1->AddListbyIndex(*list2, index);
		list1->Output();
		break;
	case 5:
		list1->AddListEnd(*list2);
		list1->Output();
		break;
	case 6:
		list1->AddListFirst(*list2);
		list1->Output();
		break;
	case 7:
		break;
	default:
		cout << "������ �������� ���.";
		break;
	}
}

void Delete_Replacement(List* list1, List* list2) {
	cout << "\n����� ������ ����� �� ������ �����������?\n";
	cout << "1.�������� ���������� ��������.\n"
		<< "2.�������� ������� ��������.\n"
		<< "3.�������� �������� �� �������.\n"
		<< "4.�������� ���� ��������� ������.\n"
		<< "5.������ �������� �� ������� �� ������������ �������.\n"
		<< "6.������ ������� ��������� � ������ �� ��������.\n"
		<< "7.����� ���� ��������� ������ �� ��������.\n"
		<< "8.��������� � ����.\n";
	int choice;
	cin >> choice;
	switch (choice) { // ����� ������� ������.
	case 1:
		list1->DeleteLastElement();
		list1->Output();
		break;
	case 2:
		list1->DeleteFirstElement();
		list1->Output();
		break;
	case 3:
		int index;
		cout << "������� ������, ������� �������� ���������� �������: \n";
		cin >> index;
		list1->DeleteElementbyIndex(index);
		list1->Output();
		break;
	case 4:
		list1->DeleteAllElements();
		break;
	case 5:
		int element;
		cout << "������� ������ ��������, ������� ������ ��������:\n";
		cin >> index;
		cout << "�� ����� ������� ��������?\n";
		cin >> element;
		list1->ReplacementElementbyIndex(element, index);
		list1->Output();
		break;
	case 6:
		list1->Reverse();
		list1->Output();
		break;
	case 7:
		cout << "������ �� ������: \n";
		list1->Output();
		int indexFirst, indexSecond;
		cout << "������� ������ ������: ";
		cin >> indexFirst;
		cout << "\n������� ������ ������: ";
		cin >> indexSecond;
		cout << endl << "������ ����� ������: \n";
		list1->ReplacementTwoElements(*list1, indexFirst, indexSecond);
		list1->Output();
		break;
	case 8:
		break;
	default:
		cout << "������ �������� ���.";
		break;
	}
}

void OtherMethods(List* list1, List* list2) {
	cout << "\n����� ������ ����� �� ������ �����������?\n";
	cout << "1.��������� �������� �� �������.\n"
		<< "2.��������� ������� ������.\n"
		<< "3.�������� �� ������� ������.\n"
		<< "4.����� ������� ��������� ������� ������ � ������.\n"
		<< "5.����� ���������� ��������� ������� ������ � ������.\n"
		<< "6.�������� �� ���������� ������� ������ � ������.\n"
		<< "7.��������� � ����.\n";
	int choice;
	cin >> choice;
	switch (choice) { // ����� ������� ������.
	case 1:
		int index, element;
		cout << "������� ������, ����� ������ �������� ��������: ";
		cin >> index;
		cout << "�� [" << index << "] �����: " << list1->GetElementbyIndex(index) << endl;
		break;
	case 2:
		cout << "����� ������ ������: " << list1->GetLengthList() << endl;
		break;
	case 3:
		CheckEmpty(list1);
		break;
	case 4:
		cout << "������ ��������� ������� ������ � ������: " << list1->SearchFirstListinList(*list2);
		break;
	case 5:
		cout << "��������� ��������� ������� ������ � ������: " << list1->SearchLastListinList(*list2);
		break;
	case 6:
		bool check;
		list1->ComparisonList(*list2);
		check = list1->ComparisonList(*list2); // �������� true ��� false � ���������� �� ����, ���� �� �������� ��� ���.
		if (check) {
			cout << "���� ������ ���������� � ������.\n";
		}
		else cout << "���� ������ �� ���������� � ������.\n";
		break;
	case 7:
		break;
	default:
		cout << "������ �������� ���.";
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	List* list = new List;
	List* secondlist = new List;

	// ����� ������� ��� ����, ����� ������ ������ ���������� �� ��� ������, ��� ����� �������, ����� �������� � �.�.

	list->AddEnd(4);
	list->AddEnd(100);
	list->AddEnd(56);
	list->AddEnd(90);
	list->AddEnd(15);

	secondlist->AddEnd(100);
	secondlist->AddEnd(56);
	secondlist->AddEnd(90);

	int choice;
	cout << "1) ";
	list->Output();
	cout << "2) ";
	secondlist->Output();

	while (Work == ������) { // ���������� ����.
		cout << endl;
		cout << "�������� ����������� �����: \n";
		cout << "1. ����������/������� ��������(-��).\n"
			<< "2. ��������/������ �������(-��).\n"
			<< "3. ������ ������.\n"
			<< "4. ���������� ���������.\n";
		cin >> choice;
		switch (choice) {
		case 1:
			Add_Insert(list, secondlist); // ������ ���������� � ������� ���������.
			break;
		case 2:
			Delete_Replacement(list, secondlist); // ������ �������� � ������ ���������.
			break;
		case 3:
			OtherMethods(list, secondlist); // ������ ������.
			break;
		case 4:
			Work = �����;
			break; // ���������� ���������.
		default:
			cout << "������� ������������ �������."; // ��������� �� ������.
		}
	}
}
