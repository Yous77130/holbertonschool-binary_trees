#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

static void print_node(const binary_tree_t *node, int offset, int depth, char **s)
{
	char b[6];
	int left, right, is_left, start, i;

	if (!node)
		return;
	left = node->left ? 1 : 0;
	right = node->right ? 1 : 0;
	is_left = node->parent && node->parent->left == node;
	snprintf(b, sizeof(b), "(%03d)", node->n);
	start = offset - 3 + (is_left ? 1 : 0);
	for (i = 0; i < 5; i++)
		s[depth][start + i] = b[i];
	if (node->parent)
	{
		if (is_left)
			s[depth - 1][offset - 1] = '.';
		else
			s[depth - 1][offset + 3] = '.';
	}
	print_node(node->left, offset - 4, depth + 1, s);
	print_node(node->right, offset + 4, depth + 1, s);
}

void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	int h, i, j;

	if (!tree)
		return;
	h = 0;
	{
		const binary_tree_t *tmp = tree;
		while (tmp)
		{			h++;
			tmp = tmp->left;
		}
	}
	s = malloc(sizeof(*s) * h);
	for (i = 0; i < h; i++)
	{
		s[i] = malloc(255);
		memset(s[i], ' ', 255);
	}
	print_node(tree, 128, 0, s);
	for (i = 0; i < h; i++)
	{
		for (j = 254; j >= 0; j--)
			if (s[i][j] != ' ')
				break;
		s[i][j + 1] = '\0';
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
