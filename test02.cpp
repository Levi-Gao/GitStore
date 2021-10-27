//二、非递归写法
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
       BiNode *p=root,*q=p;             //p为查找过程中进行扫描的指针
       if(root){
           while(p){
              if(k==p->data)
                 {return;}  //查找成功
              if(k<p->data)
                 {q=p;p=p->lChild; }  //继续向左搜索
              else
                 {q=p;p=p->rChild; } //继续向右搜索
           }//查找不成功，生成一个新结点s，插入到二叉排序树叶子处
           BiNode* s = new BiNode;
           s->data=k;
           if(k<q->data)
              q->lChild=s; //若K比叶子小，挂左边
           else
              q->rChild=s; //若K比叶子大，挂右边
      }
      else{
           root=new BiNode;
           root->data=k;
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
