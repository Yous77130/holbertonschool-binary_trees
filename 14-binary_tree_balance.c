#include "binary_trees.h"

/**
 * height - measures height including leaves
 * @tree: pointer to the root node
 * Return: height
 */
static size_t height(const binary_tree_t *tree)
{
	size_t left;
	size_t right;

	if (tree == NULL)
		return (0);
	left = height(tree->left);
	right = height(tree->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * binary_tree_balance - measures balance factor of a binary tree
 * @tree: pointer to the root node
 * Return: balance factor, 0 if NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return ((int)height(tree->left) - (int)height(tree->right));
}
