#include <iostream>
using namespace std;


void Inorder_Traversal(int l, char arr[], int size)
{
	if (size >= l)
	{
		return;
	}

	else
	{
		if (arr[size] != '\0')
		{
			
			Inorder_Traversal(l,arr, 2 * size);
			cout << arr[size]<< "  ";
			Inorder_Traversal(l,arr, 2 * size + 1);
		}
	}
}


void Preorder_Traversal(int l,char arr[], int size)
{
	if (size >= l)
	{
		return;
	}

	else
	{
		if (arr[size] != '\0')
		{
			cout << arr[size] << " ";
			Inorder_Traversal(l,arr, 2 * size);

			Inorder_Traversal(l,arr, 2 * size + 1);
		}
	}
}

void Postorder_Traversal(int l,char arr[], int size)
{
	if (size >= l)
	{
		return;
	}

	else
	{
		if (arr[size] != '\0')
		{
			
			Inorder_Traversal(l,arr, 2 * size);

			Inorder_Traversal(l,arr, 2 * size + 1);
			cout << arr[size]<< "  ";
		}
	}
}

int main()
{
	int l = 15;
	char tree[] = { '\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L' };
	int size=1;
	
	
	
	


	char s=0;
	char op='1';
	while (op != '4')
	{
		cout << "enter 1 for Inorder_Traversal  " << endl;
		cout << "enter 2 for Preorder_Traversal" << endl;
		cout << "enter 3 for   Postorder_Traversal " << endl;
		cout << "4 is inavlid !" << endl;
		cin >> op;
		
		if (op == '1')
		{
			Inorder_Traversal(l, tree, size);
			cout << endl;
		}

		else if (op == '2')
		{
			Preorder_Traversal(l, tree, size);
			cout << endl;
		}

		else if (op == '3')
		{
			Postorder_Traversal(l, tree, size);
			cout << endl;
		}

		else
		{
			cout << "invalid option!"<< endl;
		}
	}
}