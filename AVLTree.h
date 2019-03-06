//a的新平衡破坏了AVL的条件，a是需要重新平衡的结点，不平衡时，a两颗子树高度差为2
//从插入点往上找，第一个不平衡点为a，把a与使a不平衡的那个儿子旋转(单旋转）也许使它不平衡的不是它儿子是它孙子辈但不影响操作，孩子取代父亲做根，父亲做孩子
//因为单旋转为外部，所以，最左和最右不会变。此时，需要改变的结点为（左边情况下）原孩子的右孩子需要链接到a的左边(a此时为孩子了)，a的孩子此时是新的父亲。另一边类似
//不管单双旋转，最左边和最右边的情况不会变
//单旋转  a的左子树的左边   或a的右子树的右边插入
//双旋转   a的左子树的右边，或右子树的左边插入  此时单旋转解决不了问题，因为子树太大还有二叉搜索树的性质   先在a的儿子和孙子间旋转再在a与他的新儿子间旋转  不管下面有多深，我们只关心，a  a的儿子 a的孙子
//可以这样区别单双旋转   区分到a的孙子（即使它孙子后面还有节点）就可以截止了   a的左儿子的左右哪个子树，a的右儿子的左右哪个子树
//需要调整的为插入点  到a结点  之间的结点
//双旋转，左右双旋转 理解为   在a左子树的右边插入使avl性质不满足    先把a儿子和孙子左旋转  a儿子传进来，再把a与他的新儿子右旋转（传a）  另一边类似（先右旋，后左旋）
//而单旋转，a左边插入，注意是a的左边，a不一定是插入点的父亲，a右旋转。  另一边类似
//不管单双，都是向插入孩子的另一边旋转，  比如左右双旋，  在a的左边的右边插入，所以a的儿子与孙子先左旋转，接着a与它的新儿子进行一次右旋转！是a右旋转。  所以不管单双的哪种情况都是向插入的相反方向旋转！
//单旋转代码 最后一步，k2 = k1并不是把k2地址改了，只是把k2这个指针保存的地址改了  修改了指针值。   你想啊，    假如k2以前是root或者某个结点的子树，现在那个root不是k2了，不链接到原k2地址，而是把root或者某个结点子树链接到了k1保存的地址！
//左旋右旋说的旋转父亲而不是孩子
//如何区别 单旋转还是 双旋转  即   a左儿子左子树方向 右儿子右子树方向(单)。 右儿子左子树方向，左儿子右子树方向(双)。
//
//单双旋 孩子分配情况：
/*单旋转 以a左子树左边插入为例， a的儿子(左子树)的右子数(如果存在)旋转后成为a的左子树    (因为以前par是a， 之后par是a的左子树， 之前a的左子树是左子树， 旋转后变为 它左子树的右子右子树)
  简单点， a左子树左边插入，  左子树的右子树链接到原a的左子树，   原a成为左子树的右子树， 原a的右子树与  a的左子树的左子树不变*/
//双旋转：a的孙子(插入方向上)代替了a的位置，  假设是a的左子树右边插入  左右双旋，  a的孙子的左子树成为a的儿子的右子树， a的孙子的右子树成为原a的左子树
//二叉树 搜索二叉树  将avl树看作左右子树高度差不超过2的搜索二叉树

template<class T>//如果你将AVLNode的定义放到私有部分，则公有函数的参数则不能识别AVLNode类型， 其调用子函数也无法识别，但使用_root（这种私有数据成员则可以识别）.
struct AVLNode
{
    T _data;
    AVLNode* _left;
    AVLNode* _right;
    int _height;

    AVLNode( const T& x, AVLNode* left, AVLNode* right, int h = 0  )
        :_data( x  )
         ,_left( left  )
         ,_right( right  )
         ,_height( h  )
    {}
};                                              //别忘了;


template<class T>
class AVLTree
{
    typedef AVLNode<T> AVLNode;

    public:
    AVLTree(  )
        :_root( NULL  )
    {}

    int Height( AVLNode* root  ) const
    {
        return (NULL == root) ? -1 : root->_height;
    }

    void Insert( const T& x  )
    {
        _Insert( x, _root  );
    }

    void RotateWithLeftChild( AVLNode*& k2  )    //a左子树左边插入   右旋转a的左孩子       //k2为a
    {
        _RotateWithLeftChild( k2  );
    }

    void RotateWithRightChild( AVLNode*& k1   )  //左单旋
    {
        _RotateWithRightChild( k1  );
    }

    void DoubleWithLeftChild ( AVLNode*& k3  )   //左右双旋， a的左子树的右边插入
    {
        _RotateWithRightChild( k3->_left  );      //先在a的儿子与孙子间执行一次左单旋(插入在a儿子的右边)，传入a的儿子。
        _RotateWithLeftChild( k3  );             //再在a与他的新儿子间执行一次右单旋，传入a。
    }

    void DoubleWithRightChild ( AVLNode*& k1  )  //右左双旋， a的右子树的左边插入
    {
        _RotateWithLeftChild( k1->_right  );
        _RotateWithRightChild( k1  );
    }

    const T& Max( const T& x, const T& y  ) const
    {
        return x > y ? x : y;
    }

    private:
    AVLNode* _root;                             //先声明结点，再定义  顺序不对就会出错

    void _Insert( const T& x, AVLNode*& root  )  //&别忘了
    {
        if ( NULL == root  )
        {
            root = new AVLNode( x, NULL, NULL  );
        }
        else if ( x < root->_data  )
        {
            _Insert( x, root->_left  );

            if ( 2 == Height( root->_left  ) - Height( root->_right  )  )//是从插入点往上走(递归返回时程序运行方式)，每次递归返回时(因为在此时t的左树插入节点了，)判断这个条件，判断此时t是不是a，因为是从插入点网上走，所以第一个不满足条件的t肯定为第一个破坏平衡条件的a（不满足时，t就是第一个破坏avl平衡条件的a）， 不可能会是别的，不可能遗漏第一个a
            {
                if ( x < root->_left->_data  )
                {
                    RotateWithLeftChild( root  );
                }
                else
                {
                    DoubleWithLeftChild( root  );
                }
            }
        }
        else if ( x > root->_data  )
        {
            _Insert( x, root->_right  );

            if ( 2 == Height( root->_right  ) - Height( root->_left  )  )
            {
                if ( x > root->_right->_data  )
                {
                    RotateWithRightChild( root  );
                }
                else
                {
                    DoubleWithRightChild( root  );
                }
            }
        }
        else
        {
            ;
        }

        root->_height = (Max( Height(root->_left), Height(root->_right)  ) + 1);
    }

    void _RotateWithLeftChild( AVLNode*& k2  )   //a的左孩子，右单旋a(k2)
    {
        AVLNode* k1 = k2->_left;

        k2->_left = k1->_right;
        k1->_right = k2;

        k2->_height = Max( Height(k2->_left), Height(k2->_right)  ) + 1;
        k1->_height = Max( Height(k1->_left), k2->_height  ) + 1;//这里有个小细节，先求子树k2高度， 然后求k1高度时，因为k2为它左子树，所以不用Height(k1->_left)而是直接k2->_height

        k2 = k1;                                //好好想这一步， k2是以前那个子树的根， 或直接是根节点，  假如是k2根节点， 则系统认为k2这个指针保存的是根节点， but现在那个结点已经不是根节点了， 所以 需要更新这个指针的值， k2 = k1  现在的根节点值为原k1指针保存的值，  好好想想k1 k2 只是名字， 重点是它们保存的值。  k2也没有丢失，k2是k1的右子树，怎么会丢失呢？   k1指针保存值给k2
    }

    void _RotateWithRightChild( AVLNode*& k1  )  //左单旋
    {
        AVLNode* k2 = k1->_right;

        k1->_right = k2->_left;
        k2->_left = k1;

        k1->_height = Max( Height(k1->_left), Height(k1->_right)  ) + 1;
        k2->_height = Max( k1->_height, Height(k2->_right)  ) + 1;

        k1 = k2;
    }
};
