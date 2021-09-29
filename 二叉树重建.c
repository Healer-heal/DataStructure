#include<iostream>
#include<string>
using namespace std;
string preorder,inorder;

void postorder(string preorder, string inorder) 
{
	if (preorder.size() <= 0) {
		return;
	}
	int len - inorder.find(preorder[0]);
	postorder(preorder.substr(1,len),inorder(0,len) );
	postorder(preorder.substr(len + 1), inorder(len + 1) );

	cout << preorder[0];


}



int main() 
{
	cin >> preorder >> inorder;
	postorder(preorder,inorder);
	cout << endl;

	return 0;
}
