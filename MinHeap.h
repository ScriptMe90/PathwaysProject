class Node
{
	Node* left;
	Node* right;
	int data;
	
public:
	Node();
	Node(Node* l, Node* r, int dat);
	friend class MinHeap;
};

class MinHeap
{
public:
	MinHeap();
	~MinHeap();
	
	void insert(int val);
	void removeMin();
private:

	Node* findNext();

	Node* root;
};