# PAIRING-HEAP

In this project, I have implemented an advanced data structure: a Pairing Heap.

### What is a pairing heap? 
A Pairing Heap is a heap-ordered multiway tree structure that can be considered a simplified Fibonacci Heap, which also has the property of a min-heap. This kind of heap has fast amortized running times for their operations and is a type of self-adjusting binomial heap. <br />
A classical pairing heap, supports the following operations: <br />
	&emsp;-> find-min: simply return the top element of the heap; complexity O(1) <br />
	&emsp;-> merge: compare the two root elements, the smaller remains the root of the result, and the larger element and its subtree are appended as a child of this root; complexity O(1) <br />
	&emsp;-> insert: create a new heap for the inserted element and `merge` it into the original heap; complexity O(1) <br />
	&emsp;-> delete-min: remove the root and do the repeated `merges` of its subtrees until one tree remains; complexity O(log n) <br />
	&emsp;-> decrease-key (optional): remove the subtree rooted at the key to be decreased, replace the key with a smaller key, then merge the result back into the heap; complexity O(log n) <br />

### My own pairing heap
Here, I have implemented a pairing heap that has the property that in the root we will always find the minimum value in the heap (min-heap), and the process of merging two heaps will be done considering a compare function that evaluates the two roots (one for each heap). This means that the heap with the smaller value in the root will become the root of the new heap, and the one with the greater value in the root will be attached to that one, so the ascending order of the nodes will be kept. <br />
The functions supported by the pairing heap that I have implemented here are: <br />
	&emsp;-> **minim**: simply return the top element of the heap, the equivalent of the 'min-find' function, that is required for a pairing heap so when we combine two independent heaps, or when we want to delete a root we can get the values of the roots in linear time and then compare them; complexity O(1) <br />
	&emsp;-> **join**: compare the two root elements, the smaller remains the root of the result, and the larger element and its subtree are appended as a child of this root, the equivalent of the 'merge' function, that is required for a pairing heap so two independent heaps can be combined into a single one; complexity O(1) <br />
	&emsp;-> **insert**: create a new heap for the inserted element and join it into the original heap, the equivalent of the 'insert' function, that is required for a pairing heap so we can expand the original heap by adding new values; complexity O(1) <br />
	&emsp;-> **delete**: remove the root and do the repeated joins of its subtrees until one tree remains, the equivalent of the 'delete-min' function, that is required for a pairing heap so we can delete the minimum value in a heap (the root) and then rearrange the initial heap; complexity O(log n) <br />

### Implementation
In my program, the input is read from a file and the output is also written into another file. Each operation supported by my pairing heap has a code so the given instructions are just simple numbers: <br />
&emsp;**1** -> insert(int value) <br />
&emsp;**2** -> minim() and delete() <br />
&emsp;**3** -> join(PairingHeap ph2) <br />
Each heap that I use in this program has an index (a number) and when I want to apply an operation on one of the heaps I need to specify the index of the one that I want to operate on.  <br />

### Input structure
First, I need the number of given heaps and the number of operations that I want to apply to them. <br />
Then for each operation: <br />
  &emsp;-> if INSERTING I need: code 1 and then the index of the heap I want to insert into and the value I want to insert <br />
  &emsp;-> if DELETING I need: code 2 and then the index of the heap that I want to delete from (I will delete the minimum value of the heap, which I will determine using the 'minim' function) <br />
  &emsp;-> if JOINING two heaps I need: code 3 and then the indexes of the two heaps that I want to combine <br />
  
### Output structure
The output will contain only the deleted values from the different heaps, one on each line. <br />

### Repository structure
One of the sources in this repository will keep the solution of the problem 'mergeheap' on Infoarena (https://www.infoarena.ro/problema/mergeheap), where we need to find the maximum value in the heap. The other solution is the actual implementation of a pairing heap. <br />
The difference between those two solutions consists in the comparison of the nodes in two different ways: meaning that for the problem 'mergeheap' we want to order the nodes decreasingly, and for the other solution we want to order them ascendingly. <br />
