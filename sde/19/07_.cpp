void changeTree(BinaryTreeNode <int>* root) {
  if (root==nullptr) return;

  // Step 1:
  // might have to increase a child's value
  // must be done BEFORE visiting them
  int leftVal = root->left? root->left->data : 0;
  int rightVal = root->right? root->right->data : 0;
  int childSum = leftVal+rightVal;
  if (childSum==0) return; // leaf node. no need to go further down

  if (root->data > childSum) { // if both null wont enter (root->data GT 0)
    // pick max child/min value
    BinaryTreeNode <int>* mxNode=root->left; int mnValue=rightVal;
    if (mxNode==nullptr ||
        (root->right && root->right->data > mxNode->data)) {
      mxNode=root->right;
      mnValue=leftVal;
    }

    // CUR: 30
    // MX 29: other: 0
    // MX 4: other 2
    // MX: 30-0-29 MUST ADD THIS!

    // update a child value (BEFORE visiting)
    // 30-other-MX= 30-0-3=27 MUST ADD THIS
    // 30-4-3=23
    // MX 4: other 3:
    // PAR 30:
    // 30-3-4=23
    // add 23? 27
    int toAdd = root->data-mnValue-mxNode->data;
    mxNode->data+=toAdd;
  }

  // STEP 2: RECUR
  changeTree(root->left);
  changeTree(root->right);

  // STEP 3: update own value
  // get updated child sum
  leftVal = root->left? root->left->data : 0;
  rightVal = root->right? root->right->data : 0;
  childSum = leftVal+rightVal;
  if (childSum > root->data) {
    root->data=childSum;
  }
}
