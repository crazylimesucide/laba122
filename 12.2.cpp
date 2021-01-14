#include <iostream>
using namespace std;
struct Node
{
	Node* link;
	int info;
};
Node* CreateNode(int nodeCount)
{
	if (nodeCount == 0)
		return NULL;
	else
	{
		Node* newNode = new Node;

		cout << " Enter node value: ";
		cin >> newNode->info;

		int Count = nodeCount - 1;
		newNode->link = CreateNode(Count);

		return newNode;
	}
}
void Vivid(Node* newNode, int count)
{
	if (count > 0)
	{
		cout << ' ' << newNode->info;
		Vivid(newNode->link, count - 1);
	}
	else
		cout << endl;

}
void Kilk(Node* newNode, int& k, int N)
{
	if (N > 0)
	{
		if (newNode->info < 0)
			k++;
		Kilk(newNode->link, k, N - 1);
	}
}
int main()
{
	int N, k = 0;
	cout << "Enter nodes count: "; cin >> N;
	Node* root = CreateNode(N);
	Vivid(root, N);
	Kilk(root, k, N);
	cout << "Count of vidyemni: " << k;
	return 0;
}