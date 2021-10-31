//这是我在branch01分支中修改的内容： 
//abc 
//不烦 
//一、递归写法
#include<iostream>
using namespace std;

class BiNode{
public:
    int data;
    BiNode *lChild,*rChild;
    BiNode():lChild(NULL),rChild(NULL){}
    ~BiNode(){}
};

class tree{
    BiNode* root;
public:
    tree(){            //创建二叉排序树
        root=NULL;
        int n,data;
        cin>>n;
        for (int i=0; i<n; i++) {	//对输入的值，依次作插入操作
              cin>>data;
             SearchNode(root, data); //在二叉排序树中插入一个结点s
       }
    }

    void SearchNode(BiNode* &root, int k)		//查找一个结点
    {
         if(root){
	      if (root->data == k)  //查找成功
		      return;
	      else {
	          if (root->data > k)
                                  SearchNode(root->lChild, k);//查找左子树
                         else
                                  SearchNode(root->rChild, k);//查找右子树
	      }
         }
         else {
	      BiNode *s= new BiNode;				//生成一个新结点
	      s->data = k;
                     root=s;//查找不成功，插入新的结点}
         }
    }

    void SearchBST(int k)  //查找结点，并中序输出
    {
          SearchNode(root, k);
          InOrderTraverse(root);
          cout<<endl;
     }

   void InOrderTraverse (BiNode*  T ) { //中序输出
      if (T) {
	     InOrderTraverse ( T->lChild );
 	     cout << T->data<<" ";
                     InOrderTraverse ( T->rChild );
      }
  }

   void InOrder () {
         InOrderTraverse ( root );
   }

};

int main(){
    int t,n,data;
    cin>>t;

    while(t--){
      tree t;
      t.InOrder();
      cout<<endl;
      cin>>n;
      while(n--){
           cin>>data;
           t.SearchBST(data);
      }
    }
    return 1;
}


////////////////////////////////////
