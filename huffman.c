#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 256

HuffmanTable huffmanTable[MAX_CHARACTERS];
int tableSize = 0;

Node* createNode(char character, int frequency, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->array = (Node**)malloc(capacity * sizeof(Node*));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void swapNodes(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;
    
    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;
    
    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

MinHeap* createAndBuildMinHeap(char characters[], int frequencies[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(characters[i], frequencies[i], NULL, NULL);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(characters, frequencies, size);
    
    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        
        top = createNode('$', left->frequency + right->frequency, left, right);
        insertMinHeap(minHeap, top);
    }
    
    return extractMin(minHeap);
}

void storeCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        storeCodes(root->left, arr, top + 1);
    }
    
    if (root->right) {
        arr[top] = 1;
        storeCodes(root->right, arr, top + 1);
    }
    
    if (!(root->left) && !(root->right)) {
        for (int i = 0; i < tableSize; ++i) {
            if (huffmanTable[i].character == root->character) {
                for (int j = 0; j < top; ++j) {
                    huffmanTable[i].code[j] = arr[j] + '0';
                }
                huffmanTable[i].code[top] = '\0';
            }
        }
    }
}

void HuffmanCodes(char characters[], int frequencies[], int size) {
    Node* root = buildHuffmanTree(characters, frequencies, size);
    int arr[256], top = 0;
    storeCodes(root, arr, top);
}

void addCharacter(char character, int frequency) {
    for (int i = 0; i < tableSize; ++i) {
        if (huffmanTable[i].character == character) {
            huffmanTable[i].frequency = frequency;
            return;
        }
    }
    huffmanTable[tableSize].character = character;
    huffmanTable[tableSize].frequency = frequency;
    tableSize++;
}

void calculateHuffmanCodes() {
    char characters[tableSize];
    int frequencies[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        characters[i] = huffmanTable[i].character;
        frequencies[i] = huffmanTable[i].frequency;
    }
    HuffmanCodes(characters, frequencies, tableSize);
}

void printHuffmanTable() {
    for (int i = 0; i < tableSize; ++i) {
        printf("%c com frequencia %d codificado como %s\n", huffmanTable[i].character, huffmanTable[i].frequency, huffmanTable[i].code);
    }
}

void encodeString(char* str) {
    char encoded[1024] = "";
    for (int i = 0; str[i] != '\0'; ++i) {
        for (int j = 0; j < tableSize; ++j) {
            if (str[i] == huffmanTable[j].character) {
                strcat(encoded, huffmanTable[j].code);
                break;
            }
        }
    }
    printf("Codificação: %s\n", encoded);
}

Node* buildHuffmanTreeFromTable() {
    char characters[tableSize];
    int frequencies[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        characters[i] = huffmanTable[i].character;
        frequencies[i] = huffmanTable[i].frequency;
    }
    return buildHuffmanTree(characters, frequencies, tableSize);
}

void decodeBits(char* bits) {
    Node* root = buildHuffmanTreeFromTable();
    Node* current = root;
    char decoded[1024] = "";
    int index = 0;
    for (int i = 0; bits[i] != '\0'; ++i) {
        if (bits[i] == '0')
            current = current->left;
        else
            current = current->right;
        
        if (!(current->left) && !(current->right)) {
            decoded[index++] = current->character;
            current = root;
        }
    }
    decoded[index] = '\0';
    printf("Decodificação: %s\n", decoded);
}

void clearTable() {
    tableSize = 0;
}