#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"

void	BSTMakeAndInit(BTreeNode **pRoot)
{
	*pRoot = NULL;
}

BSTData	BTSGetNodeData(BTreeNode *bst)
{
	return (GetData(bst));
}

void	BSTInsert(BTreeNode **pRoot, BSTData data)
{
	BTreeNode	*pNode = NULL;      //Parent Node
	BTreeNode	*cNode = *pRoot;    //Current Node
	BTreeNode	*nNode = NULL;      //New Node

	while (cNode != NULL)
	{
		if(GetData(cNode) == data)
			return ;

		pNode = cNode;
		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
		*pRoot = nNode;
}

BTreeNode	*BSTSearch(BTreeNode *bst, BSTData target)
{
	BTreeNode	*cNode = bst;
	BSTData		cd;

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return (cNode);
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return (NULL);
}

BTreeNode	*BSTRemove(BTreeNode **pRoot, BSTData target)
{
	BTreeNode	*pVRoot = MakeBTreeNode();    // virtual root node
	BTreeNode	*pNode = pVRoot;              // parant node
	BTreeNode	*cNode = *pRoot;              // current node
	BTreeNode	*dNode;                       // delete node

	// pVRoot's Right Sub node is pRoot
	ChangeRightSubTree(pVRoot, *pRoot);

	// search Remove node
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		if (target  < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// not exist Remove target
	if (cNode == NULL)
		return (NULL);

	// find Remove target
	dNode = cNode;

	// case 1: Leaf Node
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	// case 2: only one childNode
	else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode	*dcNode;

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	// case 3: Complete Node
	else
	{
		BTreeNode	*mNode = GetRightSubTree(dNode);
		BTreeNode	*mpNode = dNode;
		int			delData;

		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);			//  대입 전 데이터 백업
		SetData(dNode, GetData(mNode));		//  대입!

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	return (dNode);
}
