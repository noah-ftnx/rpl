
struct Node{
  int data;
  struct Node * next;
  struct Node * bottom;

  Node(int x){
    data = x;
    next = NULL;
    bottom = NULL;
  }

};

using namespace std;

void printList(Node *Node)
{
  while (Node != NULL)
  {
    printf("%d ", Node->data);
    Node = Node->bottom;
  }
}

Node* flatten (Node* root);

int main(void) {

  int t;
  cin>>t;
  while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
    struct Node * head=NULL;
    struct Node * pre=NULL;
    struct Node * tempB=NULL;
    struct Node * preB=NULL;
    cin>>n;
    int work[n];
    for(int i=0;i<n;i++)
      cin>>work[i];
    for(int i=0;i<n;i++){
      m=work[i];
      --m;
      int data;
      scanf("%d",&data);
      temp = new Node(data);
      temp->next = NULL;
      temp->bottom = NULL;

      if(flag){
        head = temp;
        pre = temp;
        flag = 0;
        flag1 = 1;
      }
      else{
        pre->next = temp;
        pre = temp;
        flag1 = 1;
      }
      for(int j=0;j<m;j++){

        int temp_data;
        scanf("%d",&temp_data);
        tempB = new Node(temp_data);

        if(flag1){
          temp->bottom=tempB;
          preB=tempB;
          flag1=0;
        }
        else{
          preB->bottom=tempB;
          preB=tempB;
        }
      }
    }
    Node *fun = head;
    Node *fun2=head;

    Node* root = flatten(head);
    printList(root);
    cout<<endl;

  }
  return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
        int data;
        struct Node * next;
        struct Node * bottom;

        Node(int x){
            data = x;
            next = NULL;
            bottom = NULL;
        }

};
*/

/*
      .
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22   35
|           |     |
8          50    40
|                 |
30               45
12 ?
*/

/////////////////////////////////////////////////



Node* mergeSortedLists(Node* l1, Node* l2) {
  Node* BH = new Node(0);
  auto prev=BH;

  while (l1 && l2) { // merge lists
    if (l1->data <=l2->data) {
      // bind prev to this one
      prev->bottom=l1;
      prev=l1;
      l1=l1->bottom;
    } else {
      prev->bottom=l2;
      prev=l2;
      l2=l2->bottom;
    }
  }

  // bind any additional nodes:
  if (l1) prev->bottom=l1; // l1 had higher numbers
  else if (l2) prev->bottom=l2;  // l2 had higher numbers

  return BH->bottom;
}

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root) {
  if (!root) return root;

  Node *l1=root, *l2=l1->next;
  l1->next=nullptr;
  while(l2) {
    auto next=l2->next;
    l2->next=nullptr;

    auto mergedList = mergeSortedLists(l1, l2);
    l1=mergedList;
    l2=next;
  }
  // special case: the head might be updated:
  return l1;
}

