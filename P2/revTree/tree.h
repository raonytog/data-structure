#ifndef _TREE_H_
#define _TREE_H_

typedef struct Tree Tree;

Tree *InitTree();

Tree *InsertOnTree(Tree *treeNode, char *word);

Tree *RemoveFromTree(Tree *treeNode, char *word);

Tree *SearchOnTree(Tree *treeNode, char *word);

void DestroyTree(Tree *treeNode);

void PrintTree(Tree *treeNode);

int LeafsTree(Tree *treeNode);

int HightTree(Tree *treeNode);

#endif //  _TREE_H_

// Tree *RemoveFromTree(Tree *treeNode, char *word) {
//     if (!treeNode || !word) return NULL;

//     if (strlen(treeNode->word) < strlen(word)) 
//         treeNode->right = RemoveFromTree(treeNode->right, word);

//     else if (strlen(word) < strlen(treeNode->word))
//         treeNode->left = RemoveFromTree(treeNode->left, word);
    
//     /**
//      * Caso 1: sem filhos
//      * apenas remove o node.
//      */
//     if (treeNode->left == NULL && treeNode->right == NULL) {
//         free(treeNode);
//         treeNode = NULL;
//     }

//     /**
//      * Caso 2: um filho
//      * copio referencia do filho, excluo-o e passo a referencia do pai para o proximo
//      */
//     else if (treeNode->left == NULL) {
//         Tree *auxiliar = treeNode->right;
//         treeNode = treeNode->right;
//         free(auxiliar->word);
//         free(auxiliar);
//     }

//     else if (treeNode->right == NULL) {
//         Tree *auxiliar = treeNode->left;
//         treeNode = treeNode->left;
//         free(auxiliar->word);
//         free(auxiliar);
//     }

//     /**
//      * Caso 3: dois filhos
//      * left
//      * right till the end
//      */
//     else {
//         Tree *auxilar = treeNode->left;
//         while (auxilar->right) auxilar = auxilar->right;

//         char string_auxiliar[100]; strcpy(string_auxiliar, treeNode->word);
//         treeNode->word = auxilar->word;
//         auxilar->word = string_auxiliar;
//         treeNode->left = RemoveFromTree(treeNode->left, word);
//     }

//     return treeNode;
// }