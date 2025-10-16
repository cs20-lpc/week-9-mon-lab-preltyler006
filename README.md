[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/fyKPDzuO)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=21107821&assignment_repo_type=AssignmentRepo)
# Week 9 Mon Lab

## Directions

You will be implementing the Queue ADT as a linked list-based class. The `Queue` abstract class is already given to you, along with the header file for the `LinkedQueue` class, and a skeleton of its implementation file.

You are also in charge of writing your own driver program to test your `LinkedQueue` class. Be thorough with your testing by checking all the operations in different scenarios and with various data types.

## Notes

- If you need to access the `length` attribute in your `LinkedQueue` class, you need to write it as `this->length`
- Do **not** just use a linked list class from a previous assignment, you are starting from scratch
- This is meant to be a singly linked list with pointers to the head and last nodes of the list
- There are a number of operations that need to consider if it's invalid for it to be called: in those scenarios, make sure to `throw` a `string` exception explaining the error, like this
```C++
throw string("message goes here");
```

