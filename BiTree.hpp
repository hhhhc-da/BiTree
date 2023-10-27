#ifndef BI_TREE_H
#define BI_TREE_H

////////////////////////////////////////////////  头文件声明  ////////////////////////////////////////

#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <exception>
#include <map>
#include <stack>
#include <bitset>

///////////////////////////////////////////////  类型声明  ////////////////////////////////////////////

/* 叶子结点类型 */
template <typename T>
class BiTreeNode;
/* 具有叶子的左节点类型 */
template <typename T>
class BiTreeLeft;
/* 具有叶子的右节点类型 */
template <typename T>
class BiTreeRight;
/* 具有叶子的双节点类型 */
template <typename T>
class BiTree2Node;
/* B树头类型 */
template <typename T>
class BiTree;

/* 节点枚举类型 */
typedef enum
{
    /* 双节点 */
    LEFT_RIGHT = 0,
    /* 左节点 */
    LEFT_ONLY,
    /* 右节点 */
    RIGHT_ONLY,
    /* 叶子结点 */
    NO_ANYNODE
} TYPE;

typedef enum
{
    /* 插在左边 */
    LEFT = 0,
    /* 插在右边 */
    RIGHT
} DIRECTION;

typedef enum
{
    MIN = 0,
    NORMAL
} MODE;

/* 运行成功标识符 */
#define OK 0
/* 运行失败标识符 */
#define ERR 1
/* 程序过载标识符 */
#define OFL 2

//////////////////////////////////////////////  类型定义  /////////////////////////////////////////////////

/* 叶子结点类型定义 */
template <typename T>
class BiTreeNode
{
public:
    friend class BiTree<T>;

    BiTreeNode() : type(NO_ANYNODE), flag(false), pos(0) {}
    BiTreeNode(TYPE tp) : type(tp), flag(false), pos(0) {}
    BiTreeNode(BiTreeNode<T> &) = default;
    BiTreeNode(BiTreeNode<T> &&) = default;
    /* 重载析构函数 */
    ~BiTreeNode();
    BiTreeNode<T> &operator=(BiTreeNode<T> &);
    BiTreeNode<T> &operator=(BiTreeNode<T> &&);
    BiTreeNode(T &input);
    BiTreeNode(T &&input);

    void reset(void);

    // 不要再创建一个接受 size_t 类型的构造函数，会发生冲突
    /* 设置当前类所在的位置 */
    void setPos(std::size_t pos)
    {
        this->pos = pos;
    }
    /* 获取当前类所在的位置 */
    std::size_t getPos(void)
    {
        return this->pos;
    }
    /* 动态获取类型 */
    TYPE getType(void)
    {
        return this->type;
    }

protected:
    /* 数据节点 */
    std::shared_ptr<T> info;
    /* 位置节点 */
    std::size_t pos;
    /* 类型标识 */
    TYPE type;
    /* 激活标识 */
    bool flag;
};

/* 具有叶子的左节点类型定义 */
template <typename T>
class BiTreeLeft : public BiTreeNode<T>
{
public:
    friend class BiTree<T>;
    friend class BiTreeNode<T>;

    BiTreeLeft() : BiTreeNode<T>(), left_node(nullptr)
    {
        this->type = LEFT_ONLY;
        this->flag = false;
    }
    BiTreeLeft(BiTreeLeft<T> &) = default;
    BiTreeLeft(BiTreeLeft<T> &&) = default;
    ~BiTreeLeft() = default;
    BiTreeLeft<T> &operator=(BiTreeLeft<T> &);
    BiTreeLeft<T> &operator=(BiTreeLeft<T> &&);
    BiTreeLeft(T &input);
    BiTreeLeft(T &&input);
    BiTreeLeft(T &input, BiTreeNode<T> &node);
    BiTreeLeft(T &input, BiTreeNode<T> &&node);
    BiTreeLeft(T &&input, BiTreeNode<T> &node);
    BiTreeLeft(T &&input, BiTreeNode<T> &&node);

private:
    /* 左节点 */
    BiTreeNode<T> *left_node;
};

/* 具有叶子的右节点类型定义 */
template <typename T>
class BiTreeRight : public BiTreeNode<T>
{
public:
    friend class BiTree<T>;
    friend class BiTreeNode<T>;

    BiTreeRight() : BiTreeNode<T>(), right_node(nullptr)
    {
        this->type = RIGHT_ONLY;
        this->flag = false;
    }

    BiTreeRight(BiTreeRight<T> &) = default;
    BiTreeRight(BiTreeRight<T> &&) = default;
    ~BiTreeRight() = default;
    BiTreeRight<T> &operator=(BiTreeRight<T> &);
    BiTreeRight<T> &operator=(BiTreeRight<T> &&);
    BiTreeRight(T &input);
    BiTreeRight(T &&input);
    BiTreeRight(T &input, BiTreeNode<T> &node);
    BiTreeRight(T &input, BiTreeNode<T> &&node);
    BiTreeRight(T &&input, BiTreeNode<T> &node);
    BiTreeRight(T &&input, BiTreeNode<T> &&node);

private:
    /* 右节点 */
    BiTreeNode<T> *right_node;
};

/* 具有叶子的双节点类型定义 */
template <typename T>
class BiTree2Node : public BiTreeNode<T>
{
public:
    friend class BiTree<T>;
    friend class BiTreeNode<T>;

    BiTree2Node() : BiTreeNode<T>(), left_node(nullptr), right_node(nullptr)
    {
        this->type = LEFT_RIGHT;
        this->flag = false;
    }
    BiTree2Node(BiTree2Node<T> &) = default;
    BiTree2Node(BiTree2Node<T> &&) = default;
    ~BiTree2Node() = default;
    BiTree2Node<T> &operator=(BiTree2Node<T> &);
    BiTree2Node<T> &operator=(BiTree2Node<T> &&);
    BiTree2Node(T &input);
    BiTree2Node(T &&input);
    BiTree2Node(T &input, BiTreeNode<T> &left, BiTreeNode<T> &right);
    BiTree2Node(T &input, BiTreeNode<T> &&left, BiTreeNode<T> &&right);
    BiTree2Node(T &&input, BiTreeNode<T> &left, BiTreeNode<T> &right);
    BiTree2Node(T &&input, BiTreeNode<T> &&left, BiTreeNode<T> &&right);

private:
    /* 左节点 & 右节点 */
    BiTreeNode<T> *right_node, *left_node;
};

/* B树头类型定义 */
template <typename T>
class BiTree
{
public:
    friend class BiTreeNode<T>;

    BiTree() : depth(0), mem()
    {
        // 树根需要特殊初始化
        auto ptr = new BiTree2Node<T>();
        /* 由于初始根节点未被赋值，所以默认为未激活状态 */
        ptr->setPos(0);
        // mem.push_back(reinterpret_cast<BiTreeNode<T> *>(ptr));
        mem.push_back(ptr);
    }

    /* 本来想都锁定，不允许拷贝或移动的 */
    BiTree(BiTree<T> &);
    BiTree(BiTree<T> &&);
    BiTree(std::map<unsigned, T> &m, MODE mode);
    ~BiTree() = default;
    BiTree<T> &operator=(BiTree<T> &);
    BiTree<T> &operator=(BiTree<T> &&);

    /* 获取指定节点所在深度 */
    unsigned getDepth(unsigned pos);
    /* 获取当前节点所在深度 */
    unsigned getDepth(void)
    {
        return this->depth;
    }
    /* 插入元素(使用节点的固有值进行定位) */
    void treeInsert(unsigned pos, T node, TYPE tp);
    /* 插入元素(使用父节点和子节点方向进行定位) */
    void treeInsert(BiTreeNode<T> *pFather, T node, TYPE tp, DIRECTION LoR);
    /* 插入元素(使用父节点和可迭代的子节点方向进行定位) */
    template <typename T1, typename... T2>
    void treeInsert(BiTreeNode<T> *pFather, T node, TYPE tp, T1 LoR, T2... paras);

    /* 删除元素(使用节点的固有值进行定位) */
    void treeDelete(unsigned pos);
    /* 删除元素(使用节点的指针进行定位) */
    void treeDelete(BiTreeNode<T> *pBTN);

    /* 获取元素指针 */
    BiTreeNode<T> *getPtr(unsigned pos)
    {
        return mem.at(pos);
    }
    /* 获取节点总数 */
    std::size_t size(void)
    {
        return mem.size();
    }
    /* 总值统计函数 */
    T accBiTree(void);
    /* 获取有效节点总和 */
    std::size_t getSize(void);

    /* 前序遍历函数(使用系统栈) */
    void treeForwardDisplay(void);
    /* 中序遍历函数(使用系统栈) */
    void treeMiddleDisplay(void);
    /* 后序遍历函数(使用系统栈) */
    void treeBackwardDisplay(void);
    /* 前序遍历函数(使用标准库) */
    void treeStdForwardDisplay(void);
    /* 中序遍历函数(使用标准库) */
    void treeStdMiddleDisplay(void);
    /* 后序遍历函数(使用标准库) */
    void treeStdBackwardDisplay(void);

    /* 打印当前节点内容 */
    void treePrint(BiTreeNode<T> *pT);
    /* 打印多个节点内容 */
    template <typename T1, typename... T2>
    void treePrint(BiTreeNode<T1> *pT, T2... paras);
    /* 父元素序号计算 */
    std::pair<unsigned, uint8_t> getFatherIndex(unsigned pos);
    /* 子元素序号计算 */
    std::pair<unsigned, unsigned> getChildIndex(unsigned pos);
    /* 跟踪函数 */
    void traceFunction(void);

private:
    /* 前序遍历 */
    void preOrder(BiTreeNode<T> *pB);
    /* 中序遍历 */
    void midOrder(BiTreeNode<T> *pB);
    /* 后序遍历 */
    void backOrder(BiTreeNode<T> *pB);

    /* 树深度 */
    std::size_t depth;
    /* 需要零层预初始化 */
    // 层间元素计数器，用于管理向量所占内存
    std::map<unsigned, size_t> counter{{0, 0}};
    /* 树主存储体(一维向量作为主存储体) */
    std::vector<BiTreeNode<T> *> mem;
};

//////////////////////////////////////////////  函数声明  /////////////////////////////////////////////////

/* B树测试函数 */
void testBiTree(void);
/* 构造作业的树 */
template <typename T>
void constructBiTree(BiTree<T> &tree);
/* 作业主逻辑函数 */
void hwBiTree(void);

#endif
