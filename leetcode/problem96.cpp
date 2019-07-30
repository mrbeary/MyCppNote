

//方案1：普通递归
/* 思路：假设在某一个节点，我们还有 n 个值剩余，那么设我们有 remain(n) 种不同的二叉搜索树
    对于 n = 0 和 n = 1， remain(n) = 1  因为只有 0 或 1 个值的二叉搜索树显然只有一种
    对于 remain(n) 有多少种不同的BST？
    我们轮流选取 n 个数充当（子）树的根，假设被选中的数为i，那么这n个数可被分为两半：大于i的和小于i的，
    这两半将会被分开放置到这个子树的左半侧和右半侧，我在这里用 f(left, right) 表示，left表示左半侧的节点数（不包括NULL节点），right
    则表示右半侧的节点数，在此有：left + right + 1 == n （因为有一个值已经被选作当子树的根节点了）
    所以有：f(left,right) = remain(left) * remain(right)
    假设 n = 3， 那么就有：remain(3) = f(0,2) + f(1,1) + f(2,0)
    这样就构成了一个间接递归的关系：remain 调用 f， f 调用 remain

    个人感觉这个思路的关键是理解： remain(n) 对于这 n 个值无论是多少，都是一样的，我们不需要知道这n个数是 1，2，3 还是 1，3，10，
    因为只需要知道这n个数有大有小，我们如果选第一个数为根，那么肯定会有 n - 1 个数比根的值大，位于右子树。。。。。
*/
//下面这段代码因为没有对计算过的步骤进行记录，因此会做大量重复的工作，时间复杂度应该是 O(N^N)
class Solution96 {
public:
    int numTrees(int n) {
        return remain(n);
    }

private:
    int remain(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        int res = 0;
        int left = 0, right = n - 1;
        while (right >= 0)
        {
            res += f(left, right);
            left++;
            right--;
        }
        return res;
    }

    int f(int left, int right)
    {
        return remain(left) * remain(right);
    }
};

//方案2：带“备忘录”的递归
//对处理过的步骤作记录，时间复杂度应该为O(N)
class Solution {
public:
    int numTrees(int n) {
        record1 = vector<int>(n+1,0);
        record2 = vector<vector<int>>(n+1,vector<int>(n+1,0));
        record1[0] = record1[1] = 1;
        return remain(n);
    }
    
private:
    vector<int> record1;
    vector<vector<int>> record2;
    int remain(int n)
    {
        if (record1[n] != 0)
            return record1[n];
        int res = 0;
        int left = 0, right = n - 1;
        while (right >= 0)
        {
            res += f(left, right);
            left++;
            right--;
        }
        record1[n] = res;
        return res;
    }
    
    int f(int left, int right)
    {
        if (record2[left][right] != 0)
            return record2[left][right];
        int res = remain(left) * remain(right);
        record2[left][right] = res;
        return res;
    }
};