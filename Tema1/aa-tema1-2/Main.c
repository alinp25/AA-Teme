#include "Sequence.h"

int main(int argc, char *argv[]) {
    Sequence avlTree1 = init();
    Sequence avlTree2 = init();

    avlTree1 = insert(avlTree1, 1, 1);
    avlTree1 = insert(avlTree1, 2, 2);
    avlTree1 = insert(avlTree1, 3, 3);
    avlTree1 = insert(avlTree1, 4, 4);
    avlTree1 = insert(avlTree1, 5, 5);

    avlTree2 = insert(avlTree2, 6, 6);
    avlTree2 = insert(avlTree2, 7, 7);
    avlTree2 = insert(avlTree2, 8, 8);
    avlTree2 = insert(avlTree2, 9, 9);
    avlTree2 = insert(avlTree2, 10, 10);

    printf("\n\nTree 1\n");
    displaySequence(avlTree1);
    printf("\n");
    printf("Lookup in tree1 for 2 = %d.\n", lookup(avlTree1, 2));
    printf("Lookup in tree1 for 9 = %d.\n", lookup(avlTree1, 9));

    printf("\n\n");

    printf("\n\nTree 2\n");
    displaySequence(avlTree2);
    printf("\n");
    printf("Lookup in tree2 for 2 = %d.\n", lookup(avlTree2, 2));
    printf("Lookup in tree2 for 9 = %d.\n", lookup(avlTree2, 9));

    printf("\n\nWe set 5 to 11 in tree 1\n");
    avlTree1 = set(avlTree1, 11, 5);
    displaySequence(avlTree1);
    printf("\nSize of Tree 1 is %d\n", size(avlTree1) - 1);

    printf("\nMerge tree1 with tree2\n");
    Sequence merged = concat(avlTree1, avlTree2);
    displaySequence(merged);
    printf("\n");

    printf("\nGet the splitted tree from node with value 7\n");
    Sequence splitted = split(merged, 7);
    displaySequence(splitted);
    printf("\n");
    return 0;
}
