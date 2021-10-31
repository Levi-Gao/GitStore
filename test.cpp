//��������branch01��֧���޸ĵ����ݣ� 
//abc 
//���� 
//һ���ݹ�д��
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
         if(root){
	      if (root->data == k)  //���ҳɹ�
		      return;
	      else {
	          if (root->data > k)
                                  SearchNode(root->lChild, k);//����������
                         else
                                  SearchNode(root->rChild, k);//����������
	      }
         }
         else {
	      BiNode *s= new BiNode;				//����һ���½��
	      s->data = k;
                     root=s;//���Ҳ��ɹ��������µĽ��}
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


////////////////////////////////////
