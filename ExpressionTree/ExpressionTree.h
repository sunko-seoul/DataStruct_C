#ifndef EXPRESSION_TREE_H
# define EXPRESSION_TREE_H

#include "BinaryTree2.h"

BTreeNode *MakeExpTree(char exp[]);  // 수식 트리를 구성
int EvaluateExpTree(BTreeNode * bt); // 수식 트리 계산

void ShowPrefixTypeExp(BTreeNode * bt); 
void ShowInfixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);

#endif