#include "Sequence.h"

/**
 * Utilities 
 * Functii auxiliare necesare in rebalansarea arborelui AVL
*/

Type maxComparison(Type a, Type b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

Sequence rotateRight(Sequence v)
{
	if (!v || !v->left)
	{
		return v;
	}
	Sequence t = v->left;
	v->left = t->right;
	t->right = v;

	if (v->left != NULL && v->right != NULL)
	{
		v->height = maxComparison(v->left->height, v->right->height) + 1;
	}
	else if (v->left != NULL)
	{
		v->height = v->left->height + 1;
	}
	else if (v->right != NULL)
	{
		v->height = v->right->height + 1;
	}
	else
	{
		v->height = 1;
	}

	if (t->left != NULL)
	{
		t->height = maxComparison(v->height, t->left->height) + 1;
	}
	else
	{
		t->height = v->height + 1;
	}
	return t;
}

Sequence rotateLeft(Sequence v)
{
	if (v == NULL || v->right == NULL)
	{
		return v;
	}
	Sequence t = v->right;
	v->right = t->left;
	t->left = v;

	if (v->left != NULL && v->right != NULL)
	{
		v->height = maxComparison(v->left->height, v->right->height) + 1;
	}
	else if (v->left != NULL)
	{
		v->height = v->left->height + 1;
	}
	else if (v->right != NULL)
	{
		v->height = v->right->height + 1;
	}
	else
	{
		v->height = 1;
	}

	if (t->right != NULL)
	{
		t->height = maxComparison(v->height, t->right->height) + 1;
	}
	else
	{
		t->height = v->height + 1;
	}
	return t;
}

Sequence rebalanceTree(Sequence v)
{
	if (v == NULL)
	{
		return v;
	}
	if (v->left == NULL && v->right == NULL)
	{
		v->height = 1;
		return v;
	}
	else if (v->left == NULL)
	{
		v->height = v->right->height + 1;
		if (v->right->height >= 2)
		{
			if (v->right->left != NULL &&
				(v->right->right == NULL ||
				 v->right->left->height > v->right->right->height))
				v->right = rotateRight(v->right);
			return rotateLeft(v);
		}
	}
	else if (v->right == NULL)
	{
		v->height = v->left->height + 1;
		if (v->left->height >= 2)
		{
			if (v->left->right != NULL &&
				(v->left->left == NULL ||
				 v->left->right->height > v->left->left->height))
				v->left = rotateLeft(v->left);
			return rotateRight(v);
		}
	}
	else
	{
		v->height = maxComparison(v->left->height, v->right->height) + 1;
		if (abs(v->left->height - v->right->height) >= 2)
		{
			if (v->left->height > v->right->height)
			{
				if (v->left->right != NULL &&
					(v->left->left == NULL ||
					 v->left->right->height > v->left->left->height))
					v->left = rotateLeft(v->left);
				return rotateRight(v);
			}
			else
			{
				if (v->right->left != NULL &&
					(v->right->right == NULL ||
					 v->right->left->height > v->right->right->height))
					v->right = rotateRight(v->right);
				return rotateLeft(v);
			}
		}
	}
	return v;
}

/**
 * Implementare
*/

Sequence init()
{
	Sequence newSequence = malloc(sizeof(struct sequence));
	newSequence->data = 0;
	newSequence->height = 0;
	newSequence->left = NULL;
	newSequence->right = NULL;
	return newSequence;
}

Sequence insert(Sequence v, Type item, int index)
{
	if (!v)
	{
		v = init();
		v->data = item;
		v->height = 1;
		return v;
	}

	if (v->data <= item)
	{
		v->right = insert(v->right, item, index);
	}
	else
	{
		v->left = insert(v->left, item, index);
	}
	return v;
	return rebalanceTree(v);
}

Sequence removeItem(Sequence v, int index)
{
	if (!v)
	{
		return NULL;
	}
	Type item = 3;
	if (v->data == item)
	{
		if (v->left == NULL && v->right == NULL)
		{
			free(v);
			return NULL;
		}
		else if (v->left == NULL)
		{
			Sequence t = v->right;
			*v = *t;
			free(t);
		}
		else if (v->right == NULL)
		{
			Sequence t = v->left;
			*v = *t;
			free(t);
		}
		else
		{
			Sequence t = v->left;
			while (t->right != NULL)
			{
				t = t->right;
			}
			Type temp = v->data;
			v->data = t->data;
			t->data = temp;
			v->left = removeItem(v->left, index);
		}
	}
	else if (item < v->data)
	{
		v->left = removeItem(v->left, index);
	}
	else
	{
		v->right = removeItem(v->right, index);
	}
	return rebalanceTree(v);
}

Type lookup(Sequence v, int index)
{
	Sequence t = v;
	while (t != NULL && t->data != index)
	{
		if (index > t->data)
			t = t->right;
		else
			t = t->left;
	}
	if (t == NULL)
	{
		return -1;
	}
	return t->data;
}

Sequence set(Sequence v, Type item, int index)
{
	Sequence t = v;
	while (t != NULL && t->data != index)
	{
		if (index > t->data)
			t = t->right;
		else
			t = t->left;
	}
	if (t != NULL)
		t->data = item;
	return v;
}

int size(Sequence v)
{
	if (!v)
	{
		return 0;
	}
	return 1 + size(v->left) + size(v->right);
}

Sequence split(Sequence v, int index)
{
	if (v->data == index)
	{
		return v;
	}
	if (v->left)
	{
		return split(v->left, index);
	}
	if (v->right)
	{
		return split(v->right, index);
	}
}

Sequence concat(Sequence struct1, Sequence struct2)
{
	Sequence t = struct1;
	while (t->right)
	{
		t = t->right;
	}
	t->left = struct2;
	struct1 = rebalanceTree(struct1);
	return struct1;
}

Sequence displaySequence(Sequence v)
{
	if (!v)
	{
		return NULL;
	}
	if (v->left)
	{
		return displaySequence(v->left);
	}
	if (v->height != 0 && v->data != 0)
	{
		printf("%d ", v->data);
	}
	if (v->right)
	{
		return displaySequence(v->right);
	}
	return v;
}
