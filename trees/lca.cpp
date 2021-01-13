/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class bsttree {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int pdata = p->val;
        int qdata = q->val;
        TreeNode* temp = root;
        int rdata;
        helperfunc(temp, pdata, qdata);
        return answer;
    }
    
    void helperfunc(TreeNode* temp, int pdata, int qdata)
    {
        if(temp == nullptr)
            return;
        
        int rdata = temp->val;
        if((pdata <= rdata && qdata >= rdata) || (pdata >= rdata && qdata <= rdata)){
                
            answer =  temp;
            return;
        }        
        else if(pdata > rdata && qdata > rdata){
                
                helperfunc(temp->right, pdata, qdata); 
        }
        else if(pdata < rdata && qdata < rdata){
                
                helperfunc(temp->left, pdata, qdata); 
        }
    }
    private:
        TreeNode * answer;
};