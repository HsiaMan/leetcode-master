## DAY15 



#### [110. 平衡二叉树](https://leetcode.cn/problems/balanced-binary-tree/)

>给定一个二叉树，找出其最小深度，最小深度是从根节点到最近叶子节点的最短路径上的节点数量
>
>说明：叶子节点是指没有子节点的节点





```C++
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
    int getHeight(TreeNode * node){
        if(!node) return 0;
        // 获取左侧的深度
        int left = getHeight(node->left);
        if(left == -1) return -1;   //左子树不平衡
        
        int right = getHeight(node->right);
        if(right == -1) return -1;  //右子树不平衡
        if(abs(left - right) > 1)
            return -1;
        return max(left,right) + 1;
        
    }
};
```



> [!CAUTION]
>
> 二叉树的高度是：从叶子往上数
>
> 二叉树的深度是：从根往下数



<img src="/Users/zhangxihsia/Library/Application Support/typora-user-images/image-20260116下午40940853.png" alt="image-20260116下午40940853" style="zoom:50%;" />

下面的是表示的深度，一般是从 0 或者是 1 开始，在计算的时候统一即可

```
            A          1
          /   \
         B     C       2
        / \ 
       D   E           3
```


>[!NOTE]
>
>某个节点的高度 = 从该节点到最远叶子节点的最长路径



