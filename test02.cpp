//�����ǵݹ�д��
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
    tree(){            //��������������
        root=NULL;
        int n,data;
        cin>>n;
        for (int i=0; i<n; i++) {	//�������ֵ���������������
	cin>>data;
               SearchNode(root, data); //�ڶ����������в���һ�����s
       }
    }

    void SearchNode(BiNode* &root, int k)		//����һ�����
    {
       BiNode *p=root,*q=p;             //pΪ���ҹ����н���ɨ���ָ��
       if(root){
           while(p){
              if(k==p->data)
                 {return;}  //���ҳɹ�
              if(k<p->data)
                 {q=p;p=p->lChild; }  //������������
              else
                 {q=p;p=p->rChild; } //������������
           }//���Ҳ��ɹ�������һ���½��s�����뵽����������Ҷ�Ӵ�
           BiNode* s = new BiNode;
           s->data=k;
           if(k<q->data)
              q->lChild=s; //��K��Ҷ��С�������
           else
              q->rChild=s; //��K��Ҷ�Ӵ󣬹��ұ�
      }
      else{
           root=new BiNode;
           root->data=k;
      }
   }

    void SearchBST(int k)  //���ҽ�㣬���������
    {
         SearchNode(root, k);
         InOrderTraverse(root);
         cout<<endl;
     }

   void InOrderTraverse (BiNode*  T ) { //�������
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
