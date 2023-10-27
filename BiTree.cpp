#include "BiTree.hpp"

using namespace std;

/////////////////////////////////////////////  全局变量  ///////////////////////////////////////////////////////////
namespace
{
    /* 暂时没有全局变量 */
}

/////////////////////////////////////////////  主函数  ////////////////////////////////////////////////////////////

int main(void)
{
    // B树测试
    testBiTree();

    // // 作业函数
    // hwBiTree();

    cout << "程序执行结束!" << endl;
    // 消除 CMD 特性
    system("pause");
    return 0;
}

/////////////////////////////////////////////  B树使用测试  ////////////////////////////////////////////////////////

/* 作业主逻辑函数 */
void hwBiTree(void)
{
    try
    {
        // 根节点定义
        BiTree<unsigned> tree;

        constructBiTree<unsigned>(tree);

        // 开始遍历
        /* (1) */
        cout << "前序遍历: \t" << endl;
        tree.treeForwardDisplay();
        /* (2) */
        cout << "\n中序遍历: \t" << endl;
        tree.treeMiddleDisplay();

        system("pause");

        /* (3) */
        cout << "\n后序遍历: \t" << endl;
        tree.treeBackwardDisplay();
        cout << endl;

        // 计算总和
        /* (4) */
        cout << "数据总和: " << tree.accBiTree() << "\n"
             << endl;

        // 计算有效节点数
        /* (5) */
        cout << "有效节点数: \t" << tree.getSize() << "\n"
             << "节点总数: \t" << tree.size() << endl
             << endl;

        system("pause");

        // 前序数列直接存一个map对应，然后扔进来就行
        map<unsigned, unsigned> mT1{
            {0, 1}, {1, 2}, {2, 4}, {3, 8}, {4, 16}, {5, 32}, {6, 64}};

        /* (6) */
        BiTree<unsigned> tree2(mT1, MIN);
        cout << "Tree2前序遍历: \t" << endl;
        tree2.treeForwardDisplay();

        /* (7) */
        tree = tree2;
        cout << "Tree前序遍历(拷贝后): \t" << endl;
        tree.treeForwardDisplay();

        /* (8) */
        cout << "Tree树深度: \t" << tree.getDepth() << endl;
    }
    catch (runtime_error e)
    {
        cerr << "Fatal Error: " << e.what() << endl;
        system("pause");
    }
    catch (...)
    {
        cerr << "Fatal Error: unknown error" << endl;
        system("pause");
    }
}

/* 构造作业的树 */
template <typename T>
void constructBiTree(BiTree<T> &tree)
{
    // 树根节点
    tree.treeInsert(0, 1, LEFT_RIGHT);
    // 第一层节点
    tree.treeInsert(1, 2, LEFT_RIGHT);
    tree.treeInsert(2, 4, LEFT_RIGHT);
    // 第二层节点
    tree.treeInsert(3, 6, NO_ANYNODE);
    tree.treeInsert(4, 7, NO_ANYNODE);
    tree.treeInsert(5, 8, NO_ANYNODE);
    tree.treeInsert(6, 9, NO_ANYNODE);
}

/* B树测试函数 */
void testBiTree(void)
{
    // B树
    BiTree<unsigned> tree;

    try
    {
        ////////////////////////////////////////////////////////////////////////////////////////

        // // 内存回收测试
        // auto t1 = new BiTreeNode<int>(5);
        // delete t1;

        // auto t2 = new BiTree2Node<int>(20);
        // auto ext2 = reinterpret_cast<BiTreeNode<int> *>(t2);
        // delete ext2;
        // /* 测试通过 */

        ////////////////////////////////////////////////////////////////////////////////////////

        // B树插入测试
        tree.treeInsert(0, 1, LEFT_RIGHT);
        tree.treeInsert(1, 2, LEFT_RIGHT);
        // tree.traceFunction();

        tree.treeInsert(2, 4, LEFT_RIGHT);
        tree.treeInsert(3, 6, LEFT_RIGHT);
        // tree.traceFunction();

        tree.treeInsert(4, 7, NO_ANYNODE);
        tree.treeInsert(5, 8, NO_ANYNODE);
        tree.treeInsert(6, 9, NO_ANYNODE);
        // tree.traceFunction();
        // /* 测试通过 */

        // tree.treeInsert(7, 15, NO_ANYNODE);
        tree.treeInsert(8, 20, NO_ANYNODE);
        // tree.traceFunction();

        // // B树删除测试
        // tree.treeDelete(7);
        // tree.traceFunction();
        // /* 测试通过 */

        // /* 重复插入测试 */
        // tree.treeInsert(5, 51, NO_ANYNODE);
        // tree.treeInsert(6, 0, NO_ANYNODE);
        // tree.traceFunction();
        // /* 测试通过，p.s.重复插入元素会直接覆盖 */

        ////////////////////////////////////////////////////////////////////////////////////////

        // // B树可变数据打印测试
        // auto ptr1 = tree.getPtr(0);
        // auto ptr2 = tree.getPtr(2);
        // auto ptr3 = tree.getPtr(5);
        // tree.treePrint(ptr1, ptr2, ptr3);
        // /* 测试通过 */

        ////////////////////////////////////////////////////////////////////////////////////////

        // // B树遍历算法测试
        // cout << "\n前序遍历: " << endl;
        // tree.treeForwardDisplay();
        // cout << "\n中序遍历: " << endl;
        // tree.treeMiddleDisplay();
        // cout << "\n后序遍历: " << endl;
        // tree.treeBackwardDisplay();
        // /* 测试通过 */

        ////////////////////////////////////////////////////////////////////////////////////////

        // // B树迭代插入算法测试
        // auto ptr4 = tree.getPtr(0);
        // // 插入节点8
        // tree.treeInsert(ptr4, 500, NO_ANYNODE, LEFT, LEFT, RIGHT);
        // // 插入节点7
        // tree.treeInsert(ptr4, 502, NO_ANYNODE, LEFT, LEFT, LEFT);
        // cout << "\n(迭代)前序遍历: " << endl;
        // tree.treeForwardDisplay();
        // /* 测试通过 */

        ////////////////////////////////////////////////////////////////////////////////////////

        // B树遍历算法2(标准库版)
        cout << "\n压栈前序遍历: " << endl;
        tree.treeForwardDisplay();
        cout << "\n标准库前序遍历: " << endl;
        tree.treeStdForwardDisplay();
        cout << "\n压栈中序遍历: " << endl;
        tree.treeMiddleDisplay();
        cout << "\n标准库中序遍历: " << endl;
        tree.treeStdMiddleDisplay();
        cout << "\n压栈后序遍历: " << endl;
        tree.treeBackwardDisplay();
        cout << "\n标准库后序遍历: " << endl;
        tree.treeStdBackwardDisplay();
        /* 测试通过 */

        ////////////////////////////////////////////////////////////////////////////////////////
    }
    catch (runtime_error e)
    {
        cerr << "Fatal Error: " << e.what() << endl;
        system("pause");
    }
    catch (...)
    {
        cerr << "Fatal Error: unknown error" << endl;
        system("pause");
    }
    return;
}

/////////////////////////////////////////////  树插入和扩展算法  ///////////////////////////////////////////////////

/* 获取当前节点所在深度 */
template <typename T>
unsigned BiTree<T>::getDepth(unsigned pos)
{
    unsigned depthNow = 0, total = 0;
    while (true)
    {
        total += pow(2, depthNow);
        if (total > pos)
            break;

        ++depthNow;
    }

    return depthNow;
}

/* 信息重置函数：初始化节点为初始状态 */
template <typename T>
void BiTreeNode<T>::reset(void)
{
    auto tp = this->type;
    if (tp == NO_ANYNODE)
    {
        // 不许把类型搞丢了，pB->type 不允许提前重置！！！
        BiTreeNode<T> *pB = this;
        pB->flag = false;
        pB->info.reset();
    }
    else if (tp == LEFT_ONLY)
    {
        BiTreeLeft<T> *pB = reinterpret_cast<BiTreeLeft<T> *>(this);
        pB->flag = false;
        pB->info.reset();
        pB->left_node = nullptr;
    }
    else if (tp == RIGHT_ONLY)
    {
        BiTreeRight<T> *pB = reinterpret_cast<BiTreeRight<T> *>(this);
        pB->flag = false;
        pB->info.reset();
        pB->right_node = nullptr;
    }
    else if (tp == LEFT_RIGHT)
    {
        BiTree2Node<T> *pB = reinterpret_cast<BiTree2Node<T> *>(this);
        pB->flag = false;
        pB->info.reset();
        pB->left_node = nullptr;
        pB->right_node = nullptr;
    }
}

/* 打印当前节点内容 */
template <typename T>
void BiTree<T>::treePrint(BiTreeNode<T> *pT)
{
    cout << "节点数据为: " << *(pT->info) << endl;
}

/* 打印多个节点内容 */
template <typename T>
template <typename T1, typename... T2>
void BiTree<T>::treePrint(BiTreeNode<T1> *pT, T2... paras)
{
    cout << "节点数据为: " << *(pT->info) << endl;
    treePrint(paras...);
}

/* 总值统计函数 */
template <typename T>
T BiTree<T>::accBiTree(void)
{
    T total = 0;
    for (auto &i : mem)
    {
        if (i->flag == true)
            total += *(i->info);
    }

    return total;
}

/* 获取有效节点总和 */
template <typename T>
size_t BiTree<T>::getSize(void)
{
    size_t total = 0;
    for (auto &i : counter)
    {
        total += i.second;
    }
    return total;
}

/* 跟踪函数 */
template <typename T>
void BiTree<T>::traceFunction(void)
{
    cout << "/----------------------\n基本信息:" << endl;
    // 基本信息跟踪
    cout << "当前树深度: " << depth << endl
         << "占用字节: " << mem.size()
         << " * " << sizeof(*this) << " = "
         << mem.size() * sizeof(*this) << endl;

    cout << "/----------------------\n计数器信息:" << endl;
    // 层间元素检测函数
    for (auto i : counter)
    {
        cout << "层数: " << i.first << "\t数量: " << i.second << endl;
    }

    cout << "\n\n"
         << endl;
}

/* 父元素序号计算 */
template <typename T>
pair<unsigned, uint8_t> BiTree<T>::getFatherIndex(unsigned pos)
{
    // 计算当前层数
    unsigned depthNow = getDepth(pos);
    // 临时偏移量
    unsigned offset = (pos - static_cast<unsigned>(pow(2, depthNow)) + 1) / 2;
    // 计算父节点在向量中的位置，省去递归的时间
    unsigned father = pow(2, (depthNow == 0) ? 0 : depthNow - 1) + offset - 1;
    // LoR == 0 时为左节点，LoR == 1 时为右节点
    uint8_t LoR = (pos - static_cast<unsigned>(pow(2, depthNow) + 1)) % 2;

    return make_pair(father, LoR);
}

/* 子元素序号计算 */
template <typename T>
pair<unsigned, unsigned> BiTree<T>::getChildIndex(unsigned pos)
{
    // 计算当前层数
    unsigned depthNow = getDepth(pos);
    // child_left = pos + (2^(n+1) - 2 - pos) + 2*(pos - 2^n + 1) + 1)
    unsigned child_left = pos * 2 + 1;

    return make_pair(child_left, child_left + 1);
}

// WARNING：NOT CHANGING WITHOUT THINKING
// WARNING：时序插入，没有分模块，没有分函数，在完全理解逻辑前勿动
/* 插入元素(使用节点的固有值进行定位) */
template <typename T>
void BiTree<T>::treeInsert(unsigned pos, T node, TYPE tp)
{
    // 如果是修改根节点
    if (pos == 0)
    {
        auto ptr = mem[0];
        BiTree2Node<T> *pt = reinterpret_cast<BiTree2Node<T> *>(ptr);

        pt->flag = true;
        pt->info.reset(new T{node});

        counter[0] = 1;

        return;
    }

    unsigned pos_base = getDepth(pos);
    // 扩展树的存储体
    while (this->depth < pos_base)
    {
        for (double i = 0.0; i < pow(2, this->depth + 1); i = i + 1)
        {
            mem.push_back(new BiTreeNode<T>(0));
        }
        // 计数层初始化
        counter[++(this->depth)] = 0;
    }

    /* 不能用 this->depth，要用当前值所在层数计算 */
    // 计算当前层数
    unsigned depthNow = getDepth(pos);
    // 临时偏移量
    unsigned offset = (pos - static_cast<unsigned>(pow(2, depthNow)) + 1) / 2;
    // 计算父节点在向量中的位置，省去递归的时间
    unsigned father = pow(2, (depthNow == 0) ? 0 : depthNow - 1) + offset - 1;
    // LoR == 0 时为左节点，LoR == 1 时为右节点
    uint8_t LoR = (pos - static_cast<unsigned>(pow(2, depthNow) + 1)) % 2;

    // 此后可能会抛出异常，请注意编写异常安全代码
    BiTreeNode<T> *pNode = mem.at(father);

    // 计数器控制区
    if (mem[pos]->flag == true)
    {
        // 既然这个元素存在，那么计数器一定大于0
        counter[depthNow]--;
    }

    /* 父节点类型检测 */
    // 叶子结点不用看，绝对是错的
    if (pNode->type == NO_ANYNODE)
    {
        throw runtime_error("父节点类型不符!");
    }
    // 如果只有左节点
    else if (pNode->type == LEFT_ONLY)
    {
        // 检查是不是插右边
        if (LoR == 1)
            throw runtime_error("父节点类型不符!");
        else
        { // 动态类型转换
            BiTreeLeft<T> *Tmp = reinterpret_cast<BiTreeLeft<T> *>(pNode);

            // 选择要插入的节点类型
            if (tp == NO_ANYNODE)
            {
                auto ptr = new BiTreeNode<T>(node);
                ptr->setPos(pos);
                // 控制与父节点的关系
                if (Tmp->left_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = ptr;
                Tmp->left_node = mem[pos];
            }
            else if (tp == LEFT_ONLY)
            {
                auto ptr = new BiTreeLeft<T>(node);
                ptr->setPos(pos);
                ptr->left_node = nullptr;

                // 控制与父节点的关系
                if (Tmp->left_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->left_node = mem[pos];
            }
            else if (tp == RIGHT_ONLY)
            {
                auto ptr = new BiTreeRight<T>(node);
                ptr->setPos(pos);
                ptr->right_node = nullptr;

                // 控制与父节点的关系
                if (Tmp->left_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->left_node = mem[pos];
            }
            else if (tp == LEFT_RIGHT)
            {
                auto ptr = new BiTree2Node<T>(node);
                ptr->setPos(pos);
                ptr->left_node = nullptr;
                ptr->right_node = nullptr;

                // 控制与父节点的关系
                if (Tmp->left_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->left_node = mem[pos];
            }
            else
            {
                throw runtime_error("类型不匹配!");
            }
        }
    }
    // 只有右节点
    else if (pNode->type == RIGHT_ONLY)
    {
        // 检查是不是插左边
        if (LoR == 0)
            throw runtime_error("父节点类型不符!");
        else
        { // 动态类型转换
            BiTreeRight<T> *Tmp = reinterpret_cast<BiTreeRight<T> *>(pNode);

            // 选择要插入的节点类型
            if (tp == NO_ANYNODE)
            {
                auto ptr = new BiTreeNode<T>(node);
                ptr->setPos(pos);
                // 控制与父节点的关系
                if (Tmp->right_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = ptr;
                Tmp->right_node = mem[pos];
            }
            else if (tp == LEFT_ONLY)
            {
                auto ptr = new BiTreeLeft<T>(node);
                ptr->setPos(pos);
                ptr->left_node = nullptr;

                // 控制与父节点的关系
                if (Tmp->right_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->right_node = mem[pos];
            }
            else if (tp == RIGHT_ONLY)
            {
                auto ptr = new BiTreeRight<T>(node);
                ptr->setPos(pos);
                ptr->right_node = nullptr;

                // 控制与父节点的关系
                if (Tmp->right_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->right_node = mem[pos];
            }
            else if (tp == LEFT_RIGHT)
            {
                auto ptr = new BiTree2Node<T>(node);
                ptr->setPos(pos);
                ptr->left_node = nullptr;
                ptr->right_node = nullptr;

                // 控制与父节点的关系
                if (Tmp->right_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->right_node = mem[pos];
            }
            else
            {
                throw runtime_error("类型不匹配!");
            }
        }
    }
    else if (pNode->type == LEFT_RIGHT)
    {
        BiTree2Node<T> *Tmp = reinterpret_cast<BiTree2Node<T> *>(pNode);

        // 选择要插入的节点类型
        if (tp == NO_ANYNODE)
        {
            auto ptr = new BiTreeNode<T>(node);
            ptr->setPos(pos);

            // 父节点连接位置选择
            if (LoR == 0)
            {
                // 控制与父节点的关系
                if (Tmp->left_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = ptr;
                Tmp->left_node = mem[pos];
            }
            else if (LoR == 1)
            {
                // 控制与父节点的关系
                if (Tmp->right_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = ptr;
                Tmp->right_node = mem[pos];
            }
            // 清洗 if 分支编译特性
            else
                throw runtime_error("LoR 左右鉴别出现错误!");
        }
        else if (tp == LEFT_ONLY)
        {
            auto ptr = new BiTreeLeft<T>(node);
            ptr->setPos(pos);

            ptr->left_node = nullptr;

            // 父节点连接位置选择
            if (LoR == 0)
            {
                // 控制与父节点的关系
                if (Tmp->left_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = ptr;
                Tmp->left_node = mem[pos];
            }
            else if (LoR == 1)
            {
                // 控制与父节点的关系
                if (Tmp->right_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = ptr;
                Tmp->right_node = mem[pos];
            }
            // 清洗 if 分支编译特性
            else
                throw runtime_error("LoR 左右鉴别出现错误!");
        }
        else if (tp == RIGHT_ONLY)
        {
            auto ptr = new BiTreeRight<T>(node);
            ptr->setPos(pos);

            ptr->right_node = nullptr;

            // 父节点连接位置选择
            if (LoR == 0)
            {
                // 控制与父节点的关系
                if (Tmp->left_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = ptr;
                Tmp->left_node = mem[pos];
            }
            else if (LoR == 1)
            {
                // 控制与父节点的关系
                if (Tmp->right_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = ptr;
                Tmp->right_node = mem[pos];
            }
            // 清洗 if 分支编译特性
            else
                throw runtime_error("LoR 左右鉴别出现错误!");
        }
        else if (tp == LEFT_RIGHT)
        {
            auto ptr = new BiTree2Node<T>(node);
            ptr->setPos(pos);

            ptr->left_node = nullptr;
            ptr->right_node = nullptr;

            // 父节点连接位置选择
            if (LoR == 0)
            {
                // 控制与父节点的关系
                if (Tmp->left_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = ptr;
                Tmp->left_node = mem[pos];
            }
            else if (LoR == 1)
            {
                // 控制与父节点的关系
                if (Tmp->right_node != nullptr)
                    /* 清除旧内存 */
                    delete mem[pos];
                /* 连接新内存 */
                mem[pos] = ptr;
                Tmp->right_node = mem[pos];
            }
            // 清洗 if 分支编译特性
            else
                throw runtime_error("LoR 左右鉴别出现错误!");
        }
        else
        {
            throw runtime_error("类型不匹配!");
        }
    }
    else
    {
        // 如果出现父节点类型问题，先检查是否执行了初始化
        cerr << "正在检查初始化!" << endl;

        if (depth == 0)
            throw runtime_error("父类型检测时出现致命错误!");
    }

    // 执行到这里没有任何问题时，递增层间计数器，并且激活节点
    ++(counter[depthNow]);
    (mem[pos])->flag = true;
}

/* 插入元素(使用父节点和子节点方向进行定位) */
template <typename T>
void BiTree<T>::treeInsert(BiTreeNode<T> *pFather, T node, TYPE tp, DIRECTION LoR)
{
    auto ret = getChildIndex(pFather->pos);

    if (LoR == LEFT)
    {
        treeInsert(ret.first, node, tp);
    }
    else if (LoR == RIGHT)
    {
        treeInsert(ret.second, node, tp);
    }
    else
        throw runtime_error("插入时方向选择错误");
}

/* 插入元素(使用父节点和可迭代的子节点方向进行定位) */
template <typename T>
template <typename T1, typename... T2>
void BiTree<T>::treeInsert(BiTreeNode<T> *pFather, T node, TYPE tp, T1 LoR, T2... paras)
{
    auto ret = getChildIndex(pFather->pos);

    if (LoR == LEFT)
    {
        treeInsert(mem[ret.first], node, tp, paras...);
    }
    else if (LoR == RIGHT)
    {
        treeInsert(mem[ret.second], node, tp, paras...);
    }
    else
        throw runtime_error("插入时方向选择错误");
}

// WARNING：NOT CHANGING WITHOUT THINKING
// WARNING：时序插入，没有分模块，没有分函数，在完全理解逻辑前勿动
/* 删除元素(使用节点的固有值进行定位) */
template <typename T>
void BiTree<T>::treeDelete(unsigned pos)
{
    // 首先检测你要删的是不是树根
    if (pos == 0)
    {
        // 树根一定是一个 BiTree2Node<T> 类型的双头结点
        BiTree2Node<T> *ptr = reinterpret_cast<BiTree2Node<T> *>(mem[0]);

        if (ptr->left_node != nullptr || ptr->right_node != nullptr)
            throw runtime_error("试图删除具有节点的根节点0!");
        else
        {
            // 只更新 状态值 和 信息
            ptr->info.reset();
            ptr->flag = false;

            counter[0] = 0;
        }

        return;
    }

    // 先拿到这一层所在的深度
    unsigned depthNow = getDepth(pos);

    // 检测待删除节点，如果不存在直接抛出异常
    if (mem.at(pos)->flag == false)
    {
        throw runtime_error("要删除的元素不存在!");
    }

    // 待删除节点类型
    TYPE tp = mem.at(pos)->type;

    // 判断这玩意是不是其他节点的根
    if (tp == NO_ANYNODE ||
        (tp == LEFT_ONLY && reinterpret_cast<BiTreeLeft<T> *>(mem[pos])->left_node == nullptr) ||
        (tp == RIGHT_ONLY && reinterpret_cast<BiTreeRight<T> *>(mem[pos])->right_node == nullptr) ||
        (tp == LEFT_RIGHT && reinterpret_cast<BiTree2Node<T> *>(mem[pos])->right_node == nullptr && reinterpret_cast<BiTree2Node<T> *>(mem[pos])->left_node == nullptr))
    {
        // 计算一下父元素的位置
        unsigned offset = (pos - static_cast<unsigned>(pow(2, depthNow)) + 1) / 2;
        unsigned father = pow(2, (depthNow == 0) ? 0 : depthNow - 1) + offset - 1;
        // LoR == 0 时为左节点，LoR == 1 时为右节点
        uint8_t LoR = (pos - static_cast<unsigned>(pow(2, depthNow) + 1)) % 2;

        // 父元素不可能在自己后面，不需要检测
        BiTreeNode<T> *pFather = mem[father];
        // 父节点类型
        auto fTp = pFather->type;

        // 倒序寻找最大值
        auto max = counter.rbegin();

        // 先单独回收这一块内存
        delete mem[pos];

        // 更新父元素的连接(请不要试图使用 LoR 简化判断标准，会更乱)
        if (fTp == LEFT_RIGHT)
        {
            BiTree2Node<T> *pF = reinterpret_cast<BiTree2Node<T> *>(pFather);

            // 取消父元素的连接
            if (LoR == 0)
                pF->left_node = nullptr;
            else if (LoR == 1)
                pF->right_node = nullptr;
            else
                throw runtime_error("LoR错误!");
        }
        else if (fTp == LEFT_ONLY)
        {
            BiTreeLeft<T> *pF = reinterpret_cast<BiTreeLeft<T> *>(pFather);

            if (LoR == 0)
                pF->left_node = nullptr;
            else
                throw runtime_error("删除时父节点类型错误或LoR错误!");
        }
        else if (fTp == RIGHT_ONLY)
        {
            BiTreeRight<T> *pF = reinterpret_cast<BiTreeRight<T> *>(pFather);

            if (LoR == 1)
                pF->right_node = nullptr;
            else
                throw runtime_error("删除时父节点类型错误或LoR错误!");
        }
        else
            throw runtime_error("删除时父节点类型错误!");

        // 如果最后一个最大的值是你要删的，而且这一层只有这一个
        if (max->first == depthNow && max->second == 1)
        {
            // 获取第一行的下标
            unsigned d = 0, total = 0, old_total = 0;
            while (true)
            {
                total += pow(2, d);
                if (total > pos)
                    break;

                old_total = total;
                ++d;
            }

            // 回收后半部分内存：此处可能会有BUG，请留心(...我感觉应该是没问题...)
            mem.erase(static_cast<decltype(mem.end())>(&(mem[old_total])), mem.end());
            // 本层计数器归零
            counter[depthNow] = 0;
            // 自身层数要减一
            this->depth--;

            return;
        }
        else
        {
            // 如果他不是这一行唯一的，那就递减计数器
            if (counter[depthNow] > 1)
                --(counter[depthNow]);
            else
            {
                throw runtime_error("计数器错误!");
            }
        }
    }
    else
    {
        // 如果这玩意真是别的节点的根节点
        throw runtime_error("不能删除具有叶子的根节点!");
    }
}

/* 删除元素(使用节点的指针进行定位) */
template <typename T>
void BiTree<T>::treeDelete(BiTreeNode<T> *pBTN)
{
    size_t pos = pBTN->pos;
    /* 辅助实现 */
    treeDelete(pos);
}

//////////////////////////////////////  树遍历算法  /////////////////////////////////////////////////////////

/* 前序遍历 */
template <typename T>
void BiTree<T>::preOrder(BiTreeNode<T> *pB)
{
    auto tp = pB->type;
    // 在强转下，由于继承，其基类地址偏移是一样的
    this->treePrint(pB);

    // 检测分支
    if (tp == LEFT_ONLY)
    {
        BiTreeLeft<T> *pT = reinterpret_cast<BiTreeLeft<T> *>(pB);
        if (pT->left_node != nullptr)
            preOrder(pT->left_node);
    }
    else if (tp == RIGHT_ONLY)
    {
        BiTreeRight<T> *pT = reinterpret_cast<BiTreeRight<T> *>(pB);
        if (pT->right_node != nullptr)
            preOrder(pT->right_node);
    }
    else if (tp == LEFT_RIGHT)
    {
        BiTree2Node<T> *pT = reinterpret_cast<BiTree2Node<T> *>(pB);
        if (pT->left_node != nullptr)
            preOrder(pT->left_node);
        if (pT->right_node != nullptr)
            preOrder(pT->right_node);
    }
}

/* 中序遍历 */
template <typename T>
void BiTree<T>::midOrder(BiTreeNode<T> *pB)
{
    auto tp = pB->type;

    // 检测分支
    if (tp == LEFT_ONLY)
    {
        BiTreeLeft<T> *pT = reinterpret_cast<BiTreeLeft<T> *>(pB);
        if (pT->left_node != nullptr)
            midOrder(pT->left_node);
        this->treePrint(pB);
    }
    else if (tp == RIGHT_ONLY)
    {
        BiTreeRight<T> *pT = reinterpret_cast<BiTreeRight<T> *>(pB);
        this->treePrint(pB);
        if (pT->right_node != nullptr)
            midOrder(pT->right_node);
    }
    else if (tp == LEFT_RIGHT)
    {
        BiTree2Node<T> *pT = reinterpret_cast<BiTree2Node<T> *>(pB);
        if (pT->left_node != nullptr)
            midOrder(pT->left_node);
        this->treePrint(pB);
        if (pT->right_node != nullptr)
            midOrder(pT->right_node);
    }
    else
    {
        this->treePrint(pB);
    }
}

/* 后序遍历 */
template <typename T>
void BiTree<T>::backOrder(BiTreeNode<T> *pB)
{
    auto tp = pB->type;

    // 检测分支
    if (tp == LEFT_ONLY)
    {
        BiTreeLeft<T> *pT = reinterpret_cast<BiTreeLeft<T> *>(pB);
        if (pT->left_node != nullptr)
            backOrder(pT->left_node);
        this->treePrint(pB);
    }
    else if (tp == RIGHT_ONLY)
    {
        BiTreeRight<T> *pT = reinterpret_cast<BiTreeRight<T> *>(pB);
        if (pT->right_node != nullptr)
            backOrder(pT->right_node);
        this->treePrint(pB);
    }
    else if (tp == LEFT_RIGHT)
    {
        BiTree2Node<T> *pT = reinterpret_cast<BiTree2Node<T> *>(pB);
        if (pT->left_node != nullptr)
            backOrder(pT->left_node);
        if (pT->right_node != nullptr)
            backOrder(pT->right_node);
        this->treePrint(pB);
    }
    else
    {
        this->treePrint(pB);
    }
}

/* 前序遍历函数(使用系统栈) */
template <typename T>
void BiTree<T>::treeForwardDisplay(void)
{
    auto treeHead = mem[0];

    preOrder(treeHead);
}

/* 中序遍历函数(使用系统栈) */
template <typename T>
void BiTree<T>::treeMiddleDisplay(void)
{
    auto treeHead = mem[0];

    midOrder(treeHead);
}

/* 后序遍历函数(使用系统栈) */
template <typename T>
void BiTree<T>::treeBackwardDisplay(void)
{
    auto treeHead = mem[0];

    backOrder(treeHead);
}

/* 前序遍历函数(使用标准库) */
template <typename T>
void BiTree<T>::treeStdForwardDisplay(void)
{
    stack<BiTreeNode<T> *> ctrl;
    BiTreeNode<T> *pB = mem[0];

    // 根节点特殊处理
    while (true)
    {
        auto tp = pB->type;
        // 先输出
        this->treePrint(pB);

        // 检测分支
        if (tp == LEFT_ONLY)
        {
            BiTreeLeft<T> *pT = reinterpret_cast<BiTreeLeft<T> *>(pB);

            if (pT->left_node != nullptr)
            {
                // 左节点有的话直接走
                pB = pT->left_node;
                continue;
            }
            else
            {
                // 没有左节点就出栈
                if (ctrl.size())
                {
                    pB = ctrl.top();
                    ctrl.pop();
                }
                else
                    break;
                continue;
            }
        }
        else if (tp == RIGHT_ONLY)
        {
            BiTreeRight<T> *pT = reinterpret_cast<BiTreeRight<T> *>(pB);
            if (pT->right_node != nullptr)
            {
                // 右节点当成左节点走
                pB = pT->right_node;
                continue;
            }
            else
            {
                // 没有右节点就出栈
                if (ctrl.size())
                {
                    pB = ctrl.top();
                    ctrl.pop();
                }
                else
                    break;
                continue;
            }
        }
        else if (tp == LEFT_RIGHT)
        {
            BiTree2Node<T> *pT = reinterpret_cast<BiTree2Node<T> *>(pB);
            if (pT->right_node != nullptr)
            {
                // 把右节点都压入
                ctrl.push(pT->right_node);
            }

            if (pT->left_node != nullptr)
            {
                // 有左节点就向下走
                pB = pT->left_node;
                continue;
            }
            else
            {
                // 没有左节点就出栈
                if (ctrl.size())
                {
                    pB = ctrl.top();
                    ctrl.pop();
                }
                else
                    break;
                continue;
            }
        }
        else if (tp == NO_ANYNODE)
        {
            // 没有的话就切到下一个节点
            if (ctrl.size())
            {
                pB = ctrl.top();
                ctrl.pop();
            }
            else
                break;
            continue;
        }
    }
}

/* 中序遍历函数(使用标准库) */
template <typename T>
void BiTree<T>::treeStdMiddleDisplay(void)
{
    stack<BiTreeNode<T> *> ctrl;
    BiTreeNode<T> *pB = mem[0];
    // 左右遍历指示器
    map<unsigned, size_t> LoR;

    // 根节点特殊处理
    while (true)
    {
        auto tp = pB->type;

        // 检测分支
        if (tp == LEFT_ONLY)
        {
            BiTreeLeft<T> *pT = reinterpret_cast<BiTreeLeft<T> *>(pB);

            if (pT->left_node != nullptr && LoR[pT->pos] == 0)
            {
                // 第一次遍历到左节点，存在的话压栈直接走，并且做好记号
                ctrl.push(pB);
                LoR[pT->pos] = 1;
                pB = pT->left_node;

                continue;
            }
            else
            {
                // 第二次或者没有左节点就出栈，并且输出栈顶元素
                if (ctrl.size())
                {
                    // 输出
                    this->treePrint(pB);

                    pB = ctrl.top();
                    ctrl.pop();
                }
                else
                {
                    this->treePrint(pB);
                    break;
                }
                continue;
            }
        }
        else if (tp == RIGHT_ONLY)
        {
            BiTreeRight<T> *pT = reinterpret_cast<BiTreeRight<T> *>(pB);
            if (pT->right_node != nullptr && LoR[pT->pos] == 0)
            {
                // 右节点当成左节点走，但是不压栈，直接输出
                this->treePrint(pB);

                // 输出标识
                LoR[pT->pos] = 1;
                pB = pT->right_node;

                continue;
            }
            else
            {
                // 没有右节点就出栈
                if (ctrl.size())
                {
                    if (LoR[pT->pos] == 0)
                    {
                        // 第一次遍历右侧节点时需要输出
                        this->treePrint(pB);
                    }

                    // 第N次的都输出过了
                    pB = ctrl.top();
                    ctrl.pop();
                }
                else
                {
                    this->treePrint(pB);
                    break;
                }
                continue;
            }
        }
        else if (tp == LEFT_RIGHT)
        {
            BiTree2Node<T> *pT = reinterpret_cast<BiTree2Node<T> *>(pB);

            if (pT->left_node != nullptr && LoR[pT->pos] == 0)
            {
                // 第一次遍历到左节点，存在的话压栈直接走，并且做好记号
                ctrl.push(pB);
                LoR[pT->pos] = 1;
                pB = pT->left_node;

                continue;
            }

            if (pT->right_node != nullptr && LoR[pT->pos] <= 1)
            {
                // 右节点当成左节点走，但是不压栈，直接输出
                this->treePrint(pB);

                // 输出标识
                LoR[pT->pos] = 2;
                pB = pT->right_node;
                continue;
            }
            else
            {
                if (ctrl.size())
                {
                    this->treePrint(pB);

                    pB = ctrl.top();
                    ctrl.pop();
                }
                else
                {
                    this->treePrint(pB);
                    break;
                }
                continue;
            }
        }
        else if (tp == NO_ANYNODE)
        {
            // 没有的话就切到下一个节点
            if (ctrl.size())
            {
                this->treePrint(pB);

                pB = ctrl.top();
                ctrl.pop();
            }
            else
            {
                this->treePrint(pB);
                break;
            }
            continue;
        }
    }
}

/* 后序遍历函数(使用标准库) */
template <typename T>
void BiTree<T>::treeStdBackwardDisplay(void)
{
    stack<BiTreeNode<T> *> ctrl;
    BiTreeNode<T> *pB = mem[0];
    // 左右遍历指示器
    map<unsigned, size_t> LoR;

    // 根节点特殊处理
    while (true)
    {
        auto tp = pB->type;

        // 检测分支
        if (tp == LEFT_ONLY)
        {
            BiTreeLeft<T> *pT = reinterpret_cast<BiTreeLeft<T> *>(pB);

            if (pT->left_node != nullptr && LoR[pT->pos] == 0)
            {
                // 第一次遍历到左节点，存在的话压栈直接走，并且做好记号
                ctrl.push(pB);
                LoR[pT->pos] = 1;
                pB = pT->left_node;

                continue;
            }
            else
            {
                // 第二次或者没有左节点就出栈，并且输出栈顶元素
                if (ctrl.size())
                {
                    // 输出
                    this->treePrint(pB);

                    pB = ctrl.top();
                    ctrl.pop();
                }
                else
                {
                    this->treePrint(pB);
                    break;
                }
                continue;
            }
        }
        else if (tp == RIGHT_ONLY)
        {
            BiTreeRight<T> *pT = reinterpret_cast<BiTreeRight<T> *>(pB);
            if (pT->right_node != nullptr && LoR[pT->pos] == 0)
            {
                // 输出标识
                ctrl.push(pB);
                LoR[pT->pos] = 1;
                pB = pT->right_node;

                continue;
            }
            else
            {
                // 没有右节点就出栈
                if (ctrl.size())
                {
                    this->treePrint(pB);

                    // 第N次的都输出过了
                    pB = ctrl.top();
                    ctrl.pop();
                }
                else
                {
                    this->treePrint(pB);
                    break;
                }
                continue;
            }
        }
        else if (tp == LEFT_RIGHT)
        {
            BiTree2Node<T> *pT = reinterpret_cast<BiTree2Node<T> *>(pB);

            if (pT->left_node != nullptr && LoR[pT->pos] == 0)
            {
                // 第一次遍历到左节点，存在的话压栈直接走，并且做好记号
                ctrl.push(pB);
                LoR[pT->pos] = 1;
                pB = pT->left_node;

                continue;
            }

            if (pT->right_node != nullptr && LoR[pT->pos] <= 1)
            {
                // 输出标识
                ctrl.push(pB);
                LoR[pT->pos] = 2;
                pB = pT->right_node;
                continue;
            }
            else
            {
                if (ctrl.size())
                {
                    this->treePrint(pB);

                    pB = ctrl.top();
                    ctrl.pop();
                }
                else
                {
                    this->treePrint(pB);
                    break;
                }
                continue;
            }
        }
        else if (tp == NO_ANYNODE)
        {
            // 没有的话就切到下一个节点
            if (ctrl.size())
            {
                this->treePrint(pB);

                pB = ctrl.top();
                ctrl.pop();
            }
            else
            {
                this->treePrint(pB);
                break;
            }
            continue;
        }
    }
}

//////////////////////////////////////  拷贝控制  ////////////////////////////////////////////////////////////

/* 重载析构函数 */
template <typename T>
BiTreeNode<T>::~BiTreeNode()
{
    // 这里可以先更改为默认后在进行删除，到这里他的生命周期就结束了
    auto tp = this->type;
    if (tp == NO_ANYNODE)
    {
        this->flag = false;
        this->type = NO_ANYNODE;
        this->info.reset();
    }
    else if (tp == LEFT_ONLY)
    {
        BiTreeLeft<T> *pB = reinterpret_cast<BiTreeLeft<T> *>(this);

        pB->flag = false;
        pB->type = NO_ANYNODE;
        pB->info.reset();

        pB->left_node = nullptr;
    }
    else if (tp == RIGHT_ONLY)
    {
        BiTreeRight<T> *pB = reinterpret_cast<BiTreeRight<T> *>(this);

        pB->flag = false;
        pB->type = NO_ANYNODE;
        pB->info.reset();

        pB->right_node = nullptr;
    }
    else if (tp == LEFT_RIGHT)
    {
        BiTree2Node<T> *pB = reinterpret_cast<BiTree2Node<T> *>(this);

        pB->flag = false;
        pB->type = NO_ANYNODE;
        pB->info.reset();

        pB->left_node = nullptr;
        pB->right_node = nullptr;
    }
}

/* 构造函数 */
template <typename T>
BiTreeNode<T>::BiTreeNode(T &input) : type(NO_ANYNODE), pos(0)
{
    this->info.reset(new T{input});
    this->flag = false;
}

/* 构造函数 */
template <typename T>
BiTreeNode<T>::BiTreeNode(T &&input) : type(NO_ANYNODE), pos(0)
{
    this->info.reset(new T{input});
    this->flag = false;
}

/* 构造函数 */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &input) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &&input) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &input, BiTreeNode<T> &node) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->left_node = node;
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &input, BiTreeNode<T> &&node) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->left_node = node;
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &&input, BiTreeNode<T> &node) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->left_node = node;
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &&input, BiTreeNode<T> &&node) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->left_node = node;
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &input) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &&input) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &input, BiTreeNode<T> &node) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->right_node = node;
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &input, BiTreeNode<T> &&node) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->right_node = node;
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &&input, BiTreeNode<T> &node) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->right_node = node;
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &&input, BiTreeNode<T> &&node) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->right_node = node;
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* 构造函数 */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &input) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* 构造函数 */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &&input) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* 构造函数 */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &input, BiTreeNode<T> &left, BiTreeNode<T> &right) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->left_node = left;
    this->right_node = right;
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* 构造函数 */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &input, BiTreeNode<T> &&left, BiTreeNode<T> &&right) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->left_node = left;
    this->right_node = right;
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* 构造函数 */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &&input, BiTreeNode<T> &left, BiTreeNode<T> &right) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->left_node = left;
    this->right_node = right;
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* 构造函数 */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &&input, BiTreeNode<T> &&left, BiTreeNode<T> &&right) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->left_node = left;
    this->right_node = right;
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* 构造函数 */
template <typename T>
BiTree<T>::BiTree(BiTree<T> &tree)
{
    // 别忘了管理内存
    for (auto &i : mem)
    {
        delete i;
    }
    mem.clear();
    counter.clear();

    mem.assign(tree.mem.begin(), tree.mem.end());
    counter = tree.counter;
    depth = tree.depth;
}

/* 构造函数 */
template <typename T>
BiTree<T>::BiTree(BiTree<T> &&tree)
{
    // 别忘了管理内存
    for (auto &i : mem)
    {
        delete i;
    }
    mem.clear();
    counter.clear();

    mem.assign(tree.mem.begin(), tree.mem.end());
    counter = tree.counter;
    depth = tree.depth;
}

template <typename T>
BiTree<T>::BiTree(map<unsigned, T> &m, MODE mode) : depth(0), mem()
{
    // 树根需要特殊初始化
    auto ptr = new BiTree2Node<T>();
    /* 由于初始根节点未被赋值，所以默认为未激活状态 */
    ptr->setPos(0);
    // mem.push_back(reinterpret_cast<BiTreeNode<T> *>(ptr));
    mem.push_back(ptr);

    if (mode == NORMAL)
        for (auto &i : m)
        {
            // 有一点浪费空间，凑合用
            this->treeInsert(i.first, i.second, LEFT_RIGHT);
        }
    else if (mode == MIN)
    {
        // 计算一下子节点存在不存在
        for (auto &i : m)
        {
            unsigned now = i.first;
            auto ret = getChildIndex(now);

            uint8_t conf = 0;
            if (m.find(ret.first) != m.end())
            {
                conf |= (1U << 0);
            }
            else
                ;

            if (m.find(ret.second) != m.end())
            {
                conf |= (1U << 1);
            }
            else
                ;

            // 根据选择表进行子节点预测和插入
            if (conf == 0)
            {
                this->treeInsert(i.first, i.second, NO_ANYNODE);
            }
            else if (conf == (1U << 0))
            {
                this->treeInsert(i.first, i.second, LEFT_ONLY);
            }
            else if (conf == (1U << 1))
            {
                this->treeInsert(i.first, i.second, RIGHT_ONLY);
            }
            else if (conf == (1U << 0) + (1U << 1))
            {
                this->treeInsert(i.first, i.second, LEFT_RIGHT);
            }
            else
                throw runtime_error("CONF插入类型计数器错误!");
        }
    }
    else
    {
        throw runtime_error("不存在的插入模式!");
    }
}

//////////////////////////////////////  后面全都是运算符重载了  ///////////////////////////////////////////////

/* 运算符重载 */
template <typename T>
BiTreeNode<T> &BiTreeNode<T>::operator=(BiTreeNode<T> &tree)
{
    // this->info.reset(tree.info.release());
    this->info = tree.info;
    this->type = tree.type;
    this->pos = tree.pos;

    return *this;
}

/* 运算符重载 */
template <typename T>
BiTreeNode<T> &BiTreeNode<T>::operator=(BiTreeNode<T> &&tree)
{
    this->info = tree.info;
    this->type = std::move(tree.type);
    this->pos = tree.pos;

    return *this;
}

/* 运算符重载 */
template <typename T>
BiTree2Node<T> &BiTree2Node<T>::operator=(BiTree2Node<T> &tree)
{
    this->info = tree.info;
    this->type = tree.type;
    this->pos = tree.pos;

    this->left_node = tree.left_node;
    this->right_node = tree.right_node;

    return *this;
}

/* 运算符重载 */
template <typename T>
BiTree2Node<T> &BiTree2Node<T>::operator=(BiTree2Node<T> &&tree)
{
    this->info = tree.info;
    this->type = std::move(tree.type);
    this->pos = tree.pos;

    this->left_node = tree.left_node;
    this->right_node = tree.right_node;

    return *this;
}

/* 运算符重载 */
template <typename T>
BiTreeLeft<T> &BiTreeLeft<T>::operator=(BiTreeLeft<T> &tree)
{
    this->info = tree.info;
    this->type = tree.type;
    this->pos = tree.pos;

    this->left_node = tree.left_node;

    return *this;
}

/* 运算符重载 */
template <typename T>
BiTreeLeft<T> &BiTreeLeft<T>::operator=(BiTreeLeft<T> &&tree)
{
    this->info = tree.info;
    this->type = std::move(tree.type);
    this->pos = tree.pos;

    this->left_node = tree.left_node;

    return *this;
}

/* 运算符重载 */
template <typename T>
BiTreeRight<T> &BiTreeRight<T>::operator=(BiTreeRight<T> &tree)
{
    this->info = tree.info;
    this->type = tree.type;
    this->pos = tree.pos;

    this->right_node = tree.right_node;

    return *this;
}

/* 运算符重载 */
template <typename T>
BiTreeRight<T> &BiTreeRight<T>::operator=(BiTreeRight<T> &&tree)
{
    this->info = tree.info;
    this->type = std::move(tree.type);
    this->pos = tree.pos;

    this->right_node = tree.right_node;

    return *this;
}

/* 运算符重载 */
template <typename T>
BiTree<T> &BiTree<T>::operator=(BiTree<T> &tree)
{
    // 别忘了管理内存
    for (auto &i : mem)
    {
        delete i;
    }
    mem.clear();
    counter.clear();

    mem.assign(tree.mem.begin(), tree.mem.end());
    counter = tree.counter;
    depth = tree.depth;

    return *this;
}

/* 运算符重载 */
template <typename T>
BiTree<T> &BiTree<T>::operator=(BiTree<T> &&tree)
{
    // 别忘了管理内存
    for (auto &i : mem)
    {
        delete i;
    }
    mem.clear();
    counter.clear();

    mem.assign(tree.mem.begin(), tree.mem.end());
    counter = tree.counter;
    depth = tree.depth;

    return *this;
}