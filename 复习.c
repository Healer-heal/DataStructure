#include <iostream>
#include <string>
using namespace std;
string preorder,inorder;

void postorder(string preorder, string inorder) {	//该函数的功能是创建一棵树，并且后序遍历输出
	if (prorder.size() <= 0) {
		return;
	}
	int len = 0;
	len = inorder.find(preorder[0]);
	postorder(preorder.substr(1,len),inorder.substr(0,len) );
	postorder(prorder.substr(len + 1),inorder.substr(len + 1) );

	cout << preorder[0];
}

int main()
{
	cin >> preorder >> inorder;
	postorder(preorder,inorder);
	cout << endl;
	return 0;
}