#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

typedef struct {
    char character;
    int frequency;
    char code[256];
} HuffmanTable;

typedef struct {
    Node** array;
    int size;
    int capacity;
} MinHeap;

Node* createNode(char character, int frequency, Node* left, Node* right);
MinHeap* createMinHeap(int capacity);
void swapNodes(Node** a, Node** b);
void minHeapify(MinHeap* minHeap, int idx);
Node* extractMin(MinHeap* minHeap);
void insertMinHeap(MinHeap* minHeap, Node* node);
void buildMinHeap(MinHeap* minHeap);
MinHeap* createAndBuildMinHeap(char characters[], int frequencies[], int size);
Node* buildHuffmanTree(char characters[], int frequencies[], int size);
void printCodes(Node* root, int arr[], int top);
void HuffmanCodes(char characters[], int frequencies[], int size);

void addCharacter(char character, int frequency);
void calculateHuffmanCodes();
void printHuffmanTable();
void encodeString(char* str);
void decodeBits(char* bits);
void clearTable();

Node* buildHuffmanTreeFromTable();

#endif
