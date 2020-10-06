#include "exercise_3_2.hpp"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::add_to_front(std::string name) {
	std::unique_ptr<Node> ptr = std::make_unique<Node>();
	ptr->name = name;
	ptr->next = std::move(head);
	head = std::move(ptr);
    return;
}

void LinkedList::add_to_back(std::string name){
	std::unique_ptr<Node> ptr = std::make_unique<Node>();
	ptr->name = "parameter";
	ptr->next = nullptr;

	if(head != nullptr) {
		Node* curr = head.get();

		while(curr->next != nullptr) {
			curr = curr->next.get();
		}

		curr->next = std::move(head);
	} else {
		head = std::move(ptr);
	}
    return;
}

void LinkedList::add_at_index(std::string name, int index) {
	std::unique_ptr<Node> ptr = std::make_unique<Node>();
	ptr->name = name;

	if(index != 0) {
		Node* curr = head.get();

		for(int i = 0; i < index-1; i++) {
			curr = curr->next.get();
		}

		ptr->next = std::move(curr->next);
	} else {
		ptr->name = name;
		ptr->next = std::move(head);
		head = std::move(ptr);
	}
    return;
}

void LinkedList::remove_from_front() {
	if (head != nullptr) {
		head = std::move(head->next);
	}
    return;
}

void LinkedList::remove_from_back() {
	if (head != nullptr) {
		if (head->next != nullptr) {
			std::unique_ptr<Node> curr = std::move(head);

			while(curr->next != nullptr) {
				curr = std::move(curr->next);
			}

			curr->next = nullptr;
		} else {
			head = nullptr;
		}
	}
    return;
}

void LinkedList::remove_at_index(int index) {
	if (head != nullptr) {
		if (index != 0) {
			Node* curr = head.get();

			for(int i = 0; i < index-1; i++) {
				curr->next = std::move(curr->next);
			}
		} else {
			head = std::move(head->next);
		}
	}
	return;
}

void LinkedList::print_names() {
	Node* ptr = head.get();

	while(ptr->next != nullptr) {
		std::cout << ptr->name << "\t" << std::endl;
		ptr = ptr->next.get();
	}

	std::cout << "\n";

    return;
}
