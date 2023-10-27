#ifndef BI_TREE_H
#define BI_TREE_H

////////////////////////////////////////////////  ͷ�ļ�����  ////////////////////////////////////////

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

///////////////////////////////////////////////  ��������  ////////////////////////////////////////////

/* Ҷ�ӽ������ */
template <typename T>
class BiTreeNode;
/* ����Ҷ�ӵ���ڵ����� */
template <typename T>
class BiTreeLeft;
/* ����Ҷ�ӵ��ҽڵ����� */
template <typename T>
class BiTreeRight;
/* ����Ҷ�ӵ�˫�ڵ����� */
template <typename T>
class BiTree2Node;
/* B��ͷ���� */
template <typename T>
class BiTree;

/* �ڵ�ö������ */
typedef enum
{
    /* ˫�ڵ� */
    LEFT_RIGHT = 0,
    /* ��ڵ� */
    LEFT_ONLY,
    /* �ҽڵ� */
    RIGHT_ONLY,
    /* Ҷ�ӽ�� */
    NO_ANYNODE
} TYPE;

typedef enum
{
    /* ������� */
    LEFT = 0,
    /* �����ұ� */
    RIGHT
} DIRECTION;

typedef enum
{
    MIN = 0,
    NORMAL
} MODE;

/* ���гɹ���ʶ�� */
#define OK 0
/* ����ʧ�ܱ�ʶ�� */
#define ERR 1
/* ������ر�ʶ�� */
#define OFL 2

//////////////////////////////////////////////  ���Ͷ���  /////////////////////////////////////////////////

/* Ҷ�ӽ�����Ͷ��� */
template <typename T>
class BiTreeNode
{
public:
    friend class BiTree<T>;

    BiTreeNode() : type(NO_ANYNODE), flag(false), pos(0) {}
    BiTreeNode(TYPE tp) : type(tp), flag(false), pos(0) {}
    BiTreeNode(BiTreeNode<T> &) = default;
    BiTreeNode(BiTreeNode<T> &&) = default;
    /* ������������ */
    ~BiTreeNode();
    BiTreeNode<T> &operator=(BiTreeNode<T> &);
    BiTreeNode<T> &operator=(BiTreeNode<T> &&);
    BiTreeNode(T &input);
    BiTreeNode(T &&input);

    void reset(void);

    // ��Ҫ�ٴ���һ������ size_t ���͵Ĺ��캯�����ᷢ����ͻ
    /* ���õ�ǰ�����ڵ�λ�� */
    void setPos(std::size_t pos)
    {
        this->pos = pos;
    }
    /* ��ȡ��ǰ�����ڵ�λ�� */
    std::size_t getPos(void)
    {
        return this->pos;
    }
    /* ��̬��ȡ���� */
    TYPE getType(void)
    {
        return this->type;
    }

protected:
    /* ���ݽڵ� */
    std::shared_ptr<T> info;
    /* λ�ýڵ� */
    std::size_t pos;
    /* ���ͱ�ʶ */
    TYPE type;
    /* �����ʶ */
    bool flag;
};

/* ����Ҷ�ӵ���ڵ����Ͷ��� */
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
    /* ��ڵ� */
    BiTreeNode<T> *left_node;
};

/* ����Ҷ�ӵ��ҽڵ����Ͷ��� */
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
    /* �ҽڵ� */
    BiTreeNode<T> *right_node;
};

/* ����Ҷ�ӵ�˫�ڵ����Ͷ��� */
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
    /* ��ڵ� & �ҽڵ� */
    BiTreeNode<T> *right_node, *left_node;
};

/* B��ͷ���Ͷ��� */
template <typename T>
class BiTree
{
public:
    friend class BiTreeNode<T>;

    BiTree() : depth(0), mem()
    {
        // ������Ҫ�����ʼ��
        auto ptr = new BiTree2Node<T>();
        /* ���ڳ�ʼ���ڵ�δ����ֵ������Ĭ��Ϊδ����״̬ */
        ptr->setPos(0);
        // mem.push_back(reinterpret_cast<BiTreeNode<T> *>(ptr));
        mem.push_back(ptr);
    }

    /* �����붼�����������������ƶ��� */
    BiTree(BiTree<T> &);
    BiTree(BiTree<T> &&);
    BiTree(std::map<unsigned, T> &m, MODE mode);
    ~BiTree() = default;
    BiTree<T> &operator=(BiTree<T> &);
    BiTree<T> &operator=(BiTree<T> &&);

    /* ��ȡָ���ڵ�������� */
    unsigned getDepth(unsigned pos);
    /* ��ȡ��ǰ�ڵ�������� */
    unsigned getDepth(void)
    {
        return this->depth;
    }
    /* ����Ԫ��(ʹ�ýڵ�Ĺ���ֵ���ж�λ) */
    void treeInsert(unsigned pos, T node, TYPE tp);
    /* ����Ԫ��(ʹ�ø��ڵ���ӽڵ㷽����ж�λ) */
    void treeInsert(BiTreeNode<T> *pFather, T node, TYPE tp, DIRECTION LoR);
    /* ����Ԫ��(ʹ�ø��ڵ�Ϳɵ������ӽڵ㷽����ж�λ) */
    template <typename T1, typename... T2>
    void treeInsert(BiTreeNode<T> *pFather, T node, TYPE tp, T1 LoR, T2... paras);

    /* ɾ��Ԫ��(ʹ�ýڵ�Ĺ���ֵ���ж�λ) */
    void treeDelete(unsigned pos);
    /* ɾ��Ԫ��(ʹ�ýڵ��ָ����ж�λ) */
    void treeDelete(BiTreeNode<T> *pBTN);

    /* ��ȡԪ��ָ�� */
    BiTreeNode<T> *getPtr(unsigned pos)
    {
        return mem.at(pos);
    }
    /* ��ȡ�ڵ����� */
    std::size_t size(void)
    {
        return mem.size();
    }
    /* ��ֵͳ�ƺ��� */
    T accBiTree(void);
    /* ��ȡ��Ч�ڵ��ܺ� */
    std::size_t getSize(void);

    /* ǰ���������(ʹ��ϵͳջ) */
    void treeForwardDisplay(void);
    /* �����������(ʹ��ϵͳջ) */
    void treeMiddleDisplay(void);
    /* �����������(ʹ��ϵͳջ) */
    void treeBackwardDisplay(void);
    /* ǰ���������(ʹ�ñ�׼��) */
    void treeStdForwardDisplay(void);
    /* �����������(ʹ�ñ�׼��) */
    void treeStdMiddleDisplay(void);
    /* �����������(ʹ�ñ�׼��) */
    void treeStdBackwardDisplay(void);

    /* ��ӡ��ǰ�ڵ����� */
    void treePrint(BiTreeNode<T> *pT);
    /* ��ӡ����ڵ����� */
    template <typename T1, typename... T2>
    void treePrint(BiTreeNode<T1> *pT, T2... paras);
    /* ��Ԫ����ż��� */
    std::pair<unsigned, uint8_t> getFatherIndex(unsigned pos);
    /* ��Ԫ����ż��� */
    std::pair<unsigned, unsigned> getChildIndex(unsigned pos);
    /* ���ٺ��� */
    void traceFunction(void);

private:
    /* ǰ����� */
    void preOrder(BiTreeNode<T> *pB);
    /* ������� */
    void midOrder(BiTreeNode<T> *pB);
    /* ������� */
    void backOrder(BiTreeNode<T> *pB);

    /* ����� */
    std::size_t depth;
    /* ��Ҫ���Ԥ��ʼ�� */
    // ���Ԫ�ؼ����������ڹ���������ռ�ڴ�
    std::map<unsigned, size_t> counter{{0, 0}};
    /* �����洢��(һά������Ϊ���洢��) */
    std::vector<BiTreeNode<T> *> mem;
};

//////////////////////////////////////////////  ��������  /////////////////////////////////////////////////

/* B�����Ժ��� */
void testBiTree(void);
/* ������ҵ���� */
template <typename T>
void constructBiTree(BiTree<T> &tree);
/* ��ҵ���߼����� */
void hwBiTree(void);

#endif
