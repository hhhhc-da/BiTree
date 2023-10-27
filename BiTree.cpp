#include "BiTree.hpp"

using namespace std;

/////////////////////////////////////////////  ȫ�ֱ���  ///////////////////////////////////////////////////////////
namespace
{
    /* ��ʱû��ȫ�ֱ��� */
}

/////////////////////////////////////////////  ������  ////////////////////////////////////////////////////////////

int main(void)
{
    // B������
    testBiTree();

    // // ��ҵ����
    // hwBiTree();

    cout << "����ִ�н���!" << endl;
    // ���� CMD ����
    system("pause");
    return 0;
}

/////////////////////////////////////////////  B��ʹ�ò���  ////////////////////////////////////////////////////////

/* ��ҵ���߼����� */
void hwBiTree(void)
{
    try
    {
        // ���ڵ㶨��
        BiTree<unsigned> tree;

        constructBiTree<unsigned>(tree);

        // ��ʼ����
        /* (1) */
        cout << "ǰ�����: \t" << endl;
        tree.treeForwardDisplay();
        /* (2) */
        cout << "\n�������: \t" << endl;
        tree.treeMiddleDisplay();

        system("pause");

        /* (3) */
        cout << "\n�������: \t" << endl;
        tree.treeBackwardDisplay();
        cout << endl;

        // �����ܺ�
        /* (4) */
        cout << "�����ܺ�: " << tree.accBiTree() << "\n"
             << endl;

        // ������Ч�ڵ���
        /* (5) */
        cout << "��Ч�ڵ���: \t" << tree.getSize() << "\n"
             << "�ڵ�����: \t" << tree.size() << endl
             << endl;

        system("pause");

        // ǰ������ֱ�Ӵ�һ��map��Ӧ��Ȼ���ӽ�������
        map<unsigned, unsigned> mT1{
            {0, 1}, {1, 2}, {2, 4}, {3, 8}, {4, 16}, {5, 32}, {6, 64}};

        /* (6) */
        BiTree<unsigned> tree2(mT1, MIN);
        cout << "Tree2ǰ�����: \t" << endl;
        tree2.treeForwardDisplay();

        /* (7) */
        tree = tree2;
        cout << "Treeǰ�����(������): \t" << endl;
        tree.treeForwardDisplay();

        /* (8) */
        cout << "Tree�����: \t" << tree.getDepth() << endl;
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

/* ������ҵ���� */
template <typename T>
void constructBiTree(BiTree<T> &tree)
{
    // �����ڵ�
    tree.treeInsert(0, 1, LEFT_RIGHT);
    // ��һ��ڵ�
    tree.treeInsert(1, 2, LEFT_RIGHT);
    tree.treeInsert(2, 4, LEFT_RIGHT);
    // �ڶ���ڵ�
    tree.treeInsert(3, 6, NO_ANYNODE);
    tree.treeInsert(4, 7, NO_ANYNODE);
    tree.treeInsert(5, 8, NO_ANYNODE);
    tree.treeInsert(6, 9, NO_ANYNODE);
}

/* B�����Ժ��� */
void testBiTree(void)
{
    // B��
    BiTree<unsigned> tree;

    try
    {
        ////////////////////////////////////////////////////////////////////////////////////////

        // // �ڴ���ղ���
        // auto t1 = new BiTreeNode<int>(5);
        // delete t1;

        // auto t2 = new BiTree2Node<int>(20);
        // auto ext2 = reinterpret_cast<BiTreeNode<int> *>(t2);
        // delete ext2;
        // /* ����ͨ�� */

        ////////////////////////////////////////////////////////////////////////////////////////

        // B���������
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
        // /* ����ͨ�� */

        // tree.treeInsert(7, 15, NO_ANYNODE);
        tree.treeInsert(8, 20, NO_ANYNODE);
        // tree.traceFunction();

        // // B��ɾ������
        // tree.treeDelete(7);
        // tree.traceFunction();
        // /* ����ͨ�� */

        // /* �ظ�������� */
        // tree.treeInsert(5, 51, NO_ANYNODE);
        // tree.treeInsert(6, 0, NO_ANYNODE);
        // tree.traceFunction();
        // /* ����ͨ����p.s.�ظ�����Ԫ�ػ�ֱ�Ӹ��� */

        ////////////////////////////////////////////////////////////////////////////////////////

        // // B���ɱ����ݴ�ӡ����
        // auto ptr1 = tree.getPtr(0);
        // auto ptr2 = tree.getPtr(2);
        // auto ptr3 = tree.getPtr(5);
        // tree.treePrint(ptr1, ptr2, ptr3);
        // /* ����ͨ�� */

        ////////////////////////////////////////////////////////////////////////////////////////

        // // B�������㷨����
        // cout << "\nǰ�����: " << endl;
        // tree.treeForwardDisplay();
        // cout << "\n�������: " << endl;
        // tree.treeMiddleDisplay();
        // cout << "\n�������: " << endl;
        // tree.treeBackwardDisplay();
        // /* ����ͨ�� */

        ////////////////////////////////////////////////////////////////////////////////////////

        // // B�����������㷨����
        // auto ptr4 = tree.getPtr(0);
        // // ����ڵ�8
        // tree.treeInsert(ptr4, 500, NO_ANYNODE, LEFT, LEFT, RIGHT);
        // // ����ڵ�7
        // tree.treeInsert(ptr4, 502, NO_ANYNODE, LEFT, LEFT, LEFT);
        // cout << "\n(����)ǰ�����: " << endl;
        // tree.treeForwardDisplay();
        // /* ����ͨ�� */

        ////////////////////////////////////////////////////////////////////////////////////////

        // B�������㷨2(��׼���)
        cout << "\nѹջǰ�����: " << endl;
        tree.treeForwardDisplay();
        cout << "\n��׼��ǰ�����: " << endl;
        tree.treeStdForwardDisplay();
        cout << "\nѹջ�������: " << endl;
        tree.treeMiddleDisplay();
        cout << "\n��׼���������: " << endl;
        tree.treeStdMiddleDisplay();
        cout << "\nѹջ�������: " << endl;
        tree.treeBackwardDisplay();
        cout << "\n��׼��������: " << endl;
        tree.treeStdBackwardDisplay();
        /* ����ͨ�� */

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

/////////////////////////////////////////////  ���������չ�㷨  ///////////////////////////////////////////////////

/* ��ȡ��ǰ�ڵ�������� */
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

/* ��Ϣ���ú�������ʼ���ڵ�Ϊ��ʼ״̬ */
template <typename T>
void BiTreeNode<T>::reset(void)
{
    auto tp = this->type;
    if (tp == NO_ANYNODE)
    {
        // ��������͸㶪�ˣ�pB->type ��������ǰ���ã�����
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

/* ��ӡ��ǰ�ڵ����� */
template <typename T>
void BiTree<T>::treePrint(BiTreeNode<T> *pT)
{
    cout << "�ڵ�����Ϊ: " << *(pT->info) << endl;
}

/* ��ӡ����ڵ����� */
template <typename T>
template <typename T1, typename... T2>
void BiTree<T>::treePrint(BiTreeNode<T1> *pT, T2... paras)
{
    cout << "�ڵ�����Ϊ: " << *(pT->info) << endl;
    treePrint(paras...);
}

/* ��ֵͳ�ƺ��� */
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

/* ��ȡ��Ч�ڵ��ܺ� */
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

/* ���ٺ��� */
template <typename T>
void BiTree<T>::traceFunction(void)
{
    cout << "/----------------------\n������Ϣ:" << endl;
    // ������Ϣ����
    cout << "��ǰ�����: " << depth << endl
         << "ռ���ֽ�: " << mem.size()
         << " * " << sizeof(*this) << " = "
         << mem.size() * sizeof(*this) << endl;

    cout << "/----------------------\n��������Ϣ:" << endl;
    // ���Ԫ�ؼ�⺯��
    for (auto i : counter)
    {
        cout << "����: " << i.first << "\t����: " << i.second << endl;
    }

    cout << "\n\n"
         << endl;
}

/* ��Ԫ����ż��� */
template <typename T>
pair<unsigned, uint8_t> BiTree<T>::getFatherIndex(unsigned pos)
{
    // ���㵱ǰ����
    unsigned depthNow = getDepth(pos);
    // ��ʱƫ����
    unsigned offset = (pos - static_cast<unsigned>(pow(2, depthNow)) + 1) / 2;
    // ���㸸�ڵ��������е�λ�ã�ʡȥ�ݹ��ʱ��
    unsigned father = pow(2, (depthNow == 0) ? 0 : depthNow - 1) + offset - 1;
    // LoR == 0 ʱΪ��ڵ㣬LoR == 1 ʱΪ�ҽڵ�
    uint8_t LoR = (pos - static_cast<unsigned>(pow(2, depthNow) + 1)) % 2;

    return make_pair(father, LoR);
}

/* ��Ԫ����ż��� */
template <typename T>
pair<unsigned, unsigned> BiTree<T>::getChildIndex(unsigned pos)
{
    // ���㵱ǰ����
    unsigned depthNow = getDepth(pos);
    // child_left = pos + (2^(n+1) - 2 - pos) + 2*(pos - 2^n + 1) + 1)
    unsigned child_left = pos * 2 + 1;

    return make_pair(child_left, child_left + 1);
}

// WARNING��NOT CHANGING WITHOUT THINKING
// WARNING��ʱ����룬û�з�ģ�飬û�зֺ���������ȫ����߼�ǰ��
/* ����Ԫ��(ʹ�ýڵ�Ĺ���ֵ���ж�λ) */
template <typename T>
void BiTree<T>::treeInsert(unsigned pos, T node, TYPE tp)
{
    // ������޸ĸ��ڵ�
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
    // ��չ���Ĵ洢��
    while (this->depth < pos_base)
    {
        for (double i = 0.0; i < pow(2, this->depth + 1); i = i + 1)
        {
            mem.push_back(new BiTreeNode<T>(0));
        }
        // �������ʼ��
        counter[++(this->depth)] = 0;
    }

    /* ������ this->depth��Ҫ�õ�ǰֵ���ڲ������� */
    // ���㵱ǰ����
    unsigned depthNow = getDepth(pos);
    // ��ʱƫ����
    unsigned offset = (pos - static_cast<unsigned>(pow(2, depthNow)) + 1) / 2;
    // ���㸸�ڵ��������е�λ�ã�ʡȥ�ݹ��ʱ��
    unsigned father = pow(2, (depthNow == 0) ? 0 : depthNow - 1) + offset - 1;
    // LoR == 0 ʱΪ��ڵ㣬LoR == 1 ʱΪ�ҽڵ�
    uint8_t LoR = (pos - static_cast<unsigned>(pow(2, depthNow) + 1)) % 2;

    // �˺���ܻ��׳��쳣����ע���д�쳣��ȫ����
    BiTreeNode<T> *pNode = mem.at(father);

    // ������������
    if (mem[pos]->flag == true)
    {
        // ��Ȼ���Ԫ�ش��ڣ���ô������һ������0
        counter[depthNow]--;
    }

    /* ���ڵ����ͼ�� */
    // Ҷ�ӽ�㲻�ÿ��������Ǵ��
    if (pNode->type == NO_ANYNODE)
    {
        throw runtime_error("���ڵ����Ͳ���!");
    }
    // ���ֻ����ڵ�
    else if (pNode->type == LEFT_ONLY)
    {
        // ����ǲ��ǲ��ұ�
        if (LoR == 1)
            throw runtime_error("���ڵ����Ͳ���!");
        else
        { // ��̬����ת��
            BiTreeLeft<T> *Tmp = reinterpret_cast<BiTreeLeft<T> *>(pNode);

            // ѡ��Ҫ����Ľڵ�����
            if (tp == NO_ANYNODE)
            {
                auto ptr = new BiTreeNode<T>(node);
                ptr->setPos(pos);
                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->left_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = ptr;
                Tmp->left_node = mem[pos];
            }
            else if (tp == LEFT_ONLY)
            {
                auto ptr = new BiTreeLeft<T>(node);
                ptr->setPos(pos);
                ptr->left_node = nullptr;

                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->left_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->left_node = mem[pos];
            }
            else if (tp == RIGHT_ONLY)
            {
                auto ptr = new BiTreeRight<T>(node);
                ptr->setPos(pos);
                ptr->right_node = nullptr;

                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->left_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->left_node = mem[pos];
            }
            else if (tp == LEFT_RIGHT)
            {
                auto ptr = new BiTree2Node<T>(node);
                ptr->setPos(pos);
                ptr->left_node = nullptr;
                ptr->right_node = nullptr;

                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->left_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->left_node = mem[pos];
            }
            else
            {
                throw runtime_error("���Ͳ�ƥ��!");
            }
        }
    }
    // ֻ���ҽڵ�
    else if (pNode->type == RIGHT_ONLY)
    {
        // ����ǲ��ǲ����
        if (LoR == 0)
            throw runtime_error("���ڵ����Ͳ���!");
        else
        { // ��̬����ת��
            BiTreeRight<T> *Tmp = reinterpret_cast<BiTreeRight<T> *>(pNode);

            // ѡ��Ҫ����Ľڵ�����
            if (tp == NO_ANYNODE)
            {
                auto ptr = new BiTreeNode<T>(node);
                ptr->setPos(pos);
                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->right_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = ptr;
                Tmp->right_node = mem[pos];
            }
            else if (tp == LEFT_ONLY)
            {
                auto ptr = new BiTreeLeft<T>(node);
                ptr->setPos(pos);
                ptr->left_node = nullptr;

                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->right_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->right_node = mem[pos];
            }
            else if (tp == RIGHT_ONLY)
            {
                auto ptr = new BiTreeRight<T>(node);
                ptr->setPos(pos);
                ptr->right_node = nullptr;

                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->right_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->right_node = mem[pos];
            }
            else if (tp == LEFT_RIGHT)
            {
                auto ptr = new BiTree2Node<T>(node);
                ptr->setPos(pos);
                ptr->left_node = nullptr;
                ptr->right_node = nullptr;

                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->right_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = reinterpret_cast<BiTreeNode<T> *>(ptr);
                Tmp->right_node = mem[pos];
            }
            else
            {
                throw runtime_error("���Ͳ�ƥ��!");
            }
        }
    }
    else if (pNode->type == LEFT_RIGHT)
    {
        BiTree2Node<T> *Tmp = reinterpret_cast<BiTree2Node<T> *>(pNode);

        // ѡ��Ҫ����Ľڵ�����
        if (tp == NO_ANYNODE)
        {
            auto ptr = new BiTreeNode<T>(node);
            ptr->setPos(pos);

            // ���ڵ�����λ��ѡ��
            if (LoR == 0)
            {
                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->left_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = ptr;
                Tmp->left_node = mem[pos];
            }
            else if (LoR == 1)
            {
                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->right_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = ptr;
                Tmp->right_node = mem[pos];
            }
            // ��ϴ if ��֧��������
            else
                throw runtime_error("LoR ���Ҽ�����ִ���!");
        }
        else if (tp == LEFT_ONLY)
        {
            auto ptr = new BiTreeLeft<T>(node);
            ptr->setPos(pos);

            ptr->left_node = nullptr;

            // ���ڵ�����λ��ѡ��
            if (LoR == 0)
            {
                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->left_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = ptr;
                Tmp->left_node = mem[pos];
            }
            else if (LoR == 1)
            {
                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->right_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = ptr;
                Tmp->right_node = mem[pos];
            }
            // ��ϴ if ��֧��������
            else
                throw runtime_error("LoR ���Ҽ�����ִ���!");
        }
        else if (tp == RIGHT_ONLY)
        {
            auto ptr = new BiTreeRight<T>(node);
            ptr->setPos(pos);

            ptr->right_node = nullptr;

            // ���ڵ�����λ��ѡ��
            if (LoR == 0)
            {
                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->left_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = ptr;
                Tmp->left_node = mem[pos];
            }
            else if (LoR == 1)
            {
                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->right_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = ptr;
                Tmp->right_node = mem[pos];
            }
            // ��ϴ if ��֧��������
            else
                throw runtime_error("LoR ���Ҽ�����ִ���!");
        }
        else if (tp == LEFT_RIGHT)
        {
            auto ptr = new BiTree2Node<T>(node);
            ptr->setPos(pos);

            ptr->left_node = nullptr;
            ptr->right_node = nullptr;

            // ���ڵ�����λ��ѡ��
            if (LoR == 0)
            {
                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->left_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = ptr;
                Tmp->left_node = mem[pos];
            }
            else if (LoR == 1)
            {
                // �����븸�ڵ�Ĺ�ϵ
                if (Tmp->right_node != nullptr)
                    /* ������ڴ� */
                    delete mem[pos];
                /* �������ڴ� */
                mem[pos] = ptr;
                Tmp->right_node = mem[pos];
            }
            // ��ϴ if ��֧��������
            else
                throw runtime_error("LoR ���Ҽ�����ִ���!");
        }
        else
        {
            throw runtime_error("���Ͳ�ƥ��!");
        }
    }
    else
    {
        // ������ָ��ڵ��������⣬�ȼ���Ƿ�ִ���˳�ʼ��
        cerr << "���ڼ���ʼ��!" << endl;

        if (depth == 0)
            throw runtime_error("�����ͼ��ʱ������������!");
    }

    // ִ�е�����û���κ�����ʱ�������������������Ҽ���ڵ�
    ++(counter[depthNow]);
    (mem[pos])->flag = true;
}

/* ����Ԫ��(ʹ�ø��ڵ���ӽڵ㷽����ж�λ) */
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
        throw runtime_error("����ʱ����ѡ�����");
}

/* ����Ԫ��(ʹ�ø��ڵ�Ϳɵ������ӽڵ㷽����ж�λ) */
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
        throw runtime_error("����ʱ����ѡ�����");
}

// WARNING��NOT CHANGING WITHOUT THINKING
// WARNING��ʱ����룬û�з�ģ�飬û�зֺ���������ȫ����߼�ǰ��
/* ɾ��Ԫ��(ʹ�ýڵ�Ĺ���ֵ���ж�λ) */
template <typename T>
void BiTree<T>::treeDelete(unsigned pos)
{
    // ���ȼ����Ҫɾ���ǲ�������
    if (pos == 0)
    {
        // ����һ����һ�� BiTree2Node<T> ���͵�˫ͷ���
        BiTree2Node<T> *ptr = reinterpret_cast<BiTree2Node<T> *>(mem[0]);

        if (ptr->left_node != nullptr || ptr->right_node != nullptr)
            throw runtime_error("��ͼɾ�����нڵ�ĸ��ڵ�0!");
        else
        {
            // ֻ���� ״ֵ̬ �� ��Ϣ
            ptr->info.reset();
            ptr->flag = false;

            counter[0] = 0;
        }

        return;
    }

    // ���õ���һ�����ڵ����
    unsigned depthNow = getDepth(pos);

    // ����ɾ���ڵ㣬���������ֱ���׳��쳣
    if (mem.at(pos)->flag == false)
    {
        throw runtime_error("Ҫɾ����Ԫ�ز�����!");
    }

    // ��ɾ���ڵ�����
    TYPE tp = mem.at(pos)->type;

    // �ж��������ǲ��������ڵ�ĸ�
    if (tp == NO_ANYNODE ||
        (tp == LEFT_ONLY && reinterpret_cast<BiTreeLeft<T> *>(mem[pos])->left_node == nullptr) ||
        (tp == RIGHT_ONLY && reinterpret_cast<BiTreeRight<T> *>(mem[pos])->right_node == nullptr) ||
        (tp == LEFT_RIGHT && reinterpret_cast<BiTree2Node<T> *>(mem[pos])->right_node == nullptr && reinterpret_cast<BiTree2Node<T> *>(mem[pos])->left_node == nullptr))
    {
        // ����һ�¸�Ԫ�ص�λ��
        unsigned offset = (pos - static_cast<unsigned>(pow(2, depthNow)) + 1) / 2;
        unsigned father = pow(2, (depthNow == 0) ? 0 : depthNow - 1) + offset - 1;
        // LoR == 0 ʱΪ��ڵ㣬LoR == 1 ʱΪ�ҽڵ�
        uint8_t LoR = (pos - static_cast<unsigned>(pow(2, depthNow) + 1)) % 2;

        // ��Ԫ�ز��������Լ����棬����Ҫ���
        BiTreeNode<T> *pFather = mem[father];
        // ���ڵ�����
        auto fTp = pFather->type;

        // ����Ѱ�����ֵ
        auto max = counter.rbegin();

        // �ȵ���������һ���ڴ�
        delete mem[pos];

        // ���¸�Ԫ�ص�����(�벻Ҫ��ͼʹ�� LoR ���жϱ�׼�������)
        if (fTp == LEFT_RIGHT)
        {
            BiTree2Node<T> *pF = reinterpret_cast<BiTree2Node<T> *>(pFather);

            // ȡ����Ԫ�ص�����
            if (LoR == 0)
                pF->left_node = nullptr;
            else if (LoR == 1)
                pF->right_node = nullptr;
            else
                throw runtime_error("LoR����!");
        }
        else if (fTp == LEFT_ONLY)
        {
            BiTreeLeft<T> *pF = reinterpret_cast<BiTreeLeft<T> *>(pFather);

            if (LoR == 0)
                pF->left_node = nullptr;
            else
                throw runtime_error("ɾ��ʱ���ڵ����ʹ����LoR����!");
        }
        else if (fTp == RIGHT_ONLY)
        {
            BiTreeRight<T> *pF = reinterpret_cast<BiTreeRight<T> *>(pFather);

            if (LoR == 1)
                pF->right_node = nullptr;
            else
                throw runtime_error("ɾ��ʱ���ڵ����ʹ����LoR����!");
        }
        else
            throw runtime_error("ɾ��ʱ���ڵ����ʹ���!");

        // ������һ������ֵ����Ҫɾ�ģ�������һ��ֻ����һ��
        if (max->first == depthNow && max->second == 1)
        {
            // ��ȡ��һ�е��±�
            unsigned d = 0, total = 0, old_total = 0;
            while (true)
            {
                total += pow(2, d);
                if (total > pos)
                    break;

                old_total = total;
                ++d;
            }

            // ���պ�벿���ڴ棺�˴����ܻ���BUG��������(...�Ҹо�Ӧ����û����...)
            mem.erase(static_cast<decltype(mem.end())>(&(mem[old_total])), mem.end());
            // �������������
            counter[depthNow] = 0;
            // �������Ҫ��һ
            this->depth--;

            return;
        }
        else
        {
            // �����������һ��Ψһ�ģ��Ǿ͵ݼ�������
            if (counter[depthNow] > 1)
                --(counter[depthNow]);
            else
            {
                throw runtime_error("����������!");
            }
        }
    }
    else
    {
        // ������������Ǳ�Ľڵ�ĸ��ڵ�
        throw runtime_error("����ɾ������Ҷ�ӵĸ��ڵ�!");
    }
}

/* ɾ��Ԫ��(ʹ�ýڵ��ָ����ж�λ) */
template <typename T>
void BiTree<T>::treeDelete(BiTreeNode<T> *pBTN)
{
    size_t pos = pBTN->pos;
    /* ����ʵ�� */
    treeDelete(pos);
}

//////////////////////////////////////  �������㷨  /////////////////////////////////////////////////////////

/* ǰ����� */
template <typename T>
void BiTree<T>::preOrder(BiTreeNode<T> *pB)
{
    auto tp = pB->type;
    // ��ǿת�£����ڼ̳У�������ַƫ����һ����
    this->treePrint(pB);

    // ����֧
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

/* ������� */
template <typename T>
void BiTree<T>::midOrder(BiTreeNode<T> *pB)
{
    auto tp = pB->type;

    // ����֧
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

/* ������� */
template <typename T>
void BiTree<T>::backOrder(BiTreeNode<T> *pB)
{
    auto tp = pB->type;

    // ����֧
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

/* ǰ���������(ʹ��ϵͳջ) */
template <typename T>
void BiTree<T>::treeForwardDisplay(void)
{
    auto treeHead = mem[0];

    preOrder(treeHead);
}

/* �����������(ʹ��ϵͳջ) */
template <typename T>
void BiTree<T>::treeMiddleDisplay(void)
{
    auto treeHead = mem[0];

    midOrder(treeHead);
}

/* �����������(ʹ��ϵͳջ) */
template <typename T>
void BiTree<T>::treeBackwardDisplay(void)
{
    auto treeHead = mem[0];

    backOrder(treeHead);
}

/* ǰ���������(ʹ�ñ�׼��) */
template <typename T>
void BiTree<T>::treeStdForwardDisplay(void)
{
    stack<BiTreeNode<T> *> ctrl;
    BiTreeNode<T> *pB = mem[0];

    // ���ڵ����⴦��
    while (true)
    {
        auto tp = pB->type;
        // �����
        this->treePrint(pB);

        // ����֧
        if (tp == LEFT_ONLY)
        {
            BiTreeLeft<T> *pT = reinterpret_cast<BiTreeLeft<T> *>(pB);

            if (pT->left_node != nullptr)
            {
                // ��ڵ��еĻ�ֱ����
                pB = pT->left_node;
                continue;
            }
            else
            {
                // û����ڵ�ͳ�ջ
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
                // �ҽڵ㵱����ڵ���
                pB = pT->right_node;
                continue;
            }
            else
            {
                // û���ҽڵ�ͳ�ջ
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
                // ���ҽڵ㶼ѹ��
                ctrl.push(pT->right_node);
            }

            if (pT->left_node != nullptr)
            {
                // ����ڵ��������
                pB = pT->left_node;
                continue;
            }
            else
            {
                // û����ڵ�ͳ�ջ
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
            // û�еĻ����е���һ���ڵ�
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

/* �����������(ʹ�ñ�׼��) */
template <typename T>
void BiTree<T>::treeStdMiddleDisplay(void)
{
    stack<BiTreeNode<T> *> ctrl;
    BiTreeNode<T> *pB = mem[0];
    // ���ұ���ָʾ��
    map<unsigned, size_t> LoR;

    // ���ڵ����⴦��
    while (true)
    {
        auto tp = pB->type;

        // ����֧
        if (tp == LEFT_ONLY)
        {
            BiTreeLeft<T> *pT = reinterpret_cast<BiTreeLeft<T> *>(pB);

            if (pT->left_node != nullptr && LoR[pT->pos] == 0)
            {
                // ��һ�α�������ڵ㣬���ڵĻ�ѹջֱ���ߣ��������üǺ�
                ctrl.push(pB);
                LoR[pT->pos] = 1;
                pB = pT->left_node;

                continue;
            }
            else
            {
                // �ڶ��λ���û����ڵ�ͳ�ջ���������ջ��Ԫ��
                if (ctrl.size())
                {
                    // ���
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
                // �ҽڵ㵱����ڵ��ߣ����ǲ�ѹջ��ֱ�����
                this->treePrint(pB);

                // �����ʶ
                LoR[pT->pos] = 1;
                pB = pT->right_node;

                continue;
            }
            else
            {
                // û���ҽڵ�ͳ�ջ
                if (ctrl.size())
                {
                    if (LoR[pT->pos] == 0)
                    {
                        // ��һ�α����Ҳ�ڵ�ʱ��Ҫ���
                        this->treePrint(pB);
                    }

                    // ��N�εĶ��������
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
                // ��һ�α�������ڵ㣬���ڵĻ�ѹջֱ���ߣ��������üǺ�
                ctrl.push(pB);
                LoR[pT->pos] = 1;
                pB = pT->left_node;

                continue;
            }

            if (pT->right_node != nullptr && LoR[pT->pos] <= 1)
            {
                // �ҽڵ㵱����ڵ��ߣ����ǲ�ѹջ��ֱ�����
                this->treePrint(pB);

                // �����ʶ
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
            // û�еĻ����е���һ���ڵ�
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

/* �����������(ʹ�ñ�׼��) */
template <typename T>
void BiTree<T>::treeStdBackwardDisplay(void)
{
    stack<BiTreeNode<T> *> ctrl;
    BiTreeNode<T> *pB = mem[0];
    // ���ұ���ָʾ��
    map<unsigned, size_t> LoR;

    // ���ڵ����⴦��
    while (true)
    {
        auto tp = pB->type;

        // ����֧
        if (tp == LEFT_ONLY)
        {
            BiTreeLeft<T> *pT = reinterpret_cast<BiTreeLeft<T> *>(pB);

            if (pT->left_node != nullptr && LoR[pT->pos] == 0)
            {
                // ��һ�α�������ڵ㣬���ڵĻ�ѹջֱ���ߣ��������üǺ�
                ctrl.push(pB);
                LoR[pT->pos] = 1;
                pB = pT->left_node;

                continue;
            }
            else
            {
                // �ڶ��λ���û����ڵ�ͳ�ջ���������ջ��Ԫ��
                if (ctrl.size())
                {
                    // ���
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
                // �����ʶ
                ctrl.push(pB);
                LoR[pT->pos] = 1;
                pB = pT->right_node;

                continue;
            }
            else
            {
                // û���ҽڵ�ͳ�ջ
                if (ctrl.size())
                {
                    this->treePrint(pB);

                    // ��N�εĶ��������
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
                // ��һ�α�������ڵ㣬���ڵĻ�ѹջֱ���ߣ��������üǺ�
                ctrl.push(pB);
                LoR[pT->pos] = 1;
                pB = pT->left_node;

                continue;
            }

            if (pT->right_node != nullptr && LoR[pT->pos] <= 1)
            {
                // �����ʶ
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
            // û�еĻ����е���һ���ڵ�
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

//////////////////////////////////////  ��������  ////////////////////////////////////////////////////////////

/* ������������ */
template <typename T>
BiTreeNode<T>::~BiTreeNode()
{
    // ��������ȸ���ΪĬ�Ϻ��ڽ���ɾ���������������������ھͽ�����
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

/* ���캯�� */
template <typename T>
BiTreeNode<T>::BiTreeNode(T &input) : type(NO_ANYNODE), pos(0)
{
    this->info.reset(new T{input});
    this->flag = false;
}

/* ���캯�� */
template <typename T>
BiTreeNode<T>::BiTreeNode(T &&input) : type(NO_ANYNODE), pos(0)
{
    this->info.reset(new T{input});
    this->flag = false;
}

/* ���캯�� */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &input) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &&input) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &input, BiTreeNode<T> &node) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->left_node = node;
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &input, BiTreeNode<T> &&node) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->left_node = node;
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &&input, BiTreeNode<T> &node) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->left_node = node;
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeLeft<T>::BiTreeLeft(T &&input, BiTreeNode<T> &&node) : BiTreeNode<T>(LEFT_ONLY)
{
    this->info.reset(new T{input});
    this->left_node = node;
    this->flag = false;
    this->type = LEFT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &input) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &&input) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &input, BiTreeNode<T> &node) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->right_node = node;
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &input, BiTreeNode<T> &&node) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->right_node = node;
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &&input, BiTreeNode<T> &node) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->right_node = node;
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTreeRight<T>::BiTreeRight(T &&input, BiTreeNode<T> &&node) : BiTreeNode<T>(RIGHT_ONLY)
{
    this->info.reset(new T{input});
    this->right_node = node;
    this->flag = false;
    this->type = RIGHT_ONLY;
}

/* ���캯�� */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &input) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* ���캯�� */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &&input) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* ���캯�� */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &input, BiTreeNode<T> &left, BiTreeNode<T> &right) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->left_node = left;
    this->right_node = right;
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* ���캯�� */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &input, BiTreeNode<T> &&left, BiTreeNode<T> &&right) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->left_node = left;
    this->right_node = right;
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* ���캯�� */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &&input, BiTreeNode<T> &left, BiTreeNode<T> &right) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->left_node = left;
    this->right_node = right;
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* ���캯�� */
template <typename T>
BiTree2Node<T>::BiTree2Node(T &&input, BiTreeNode<T> &&left, BiTreeNode<T> &&right) : BiTreeNode<T>(LEFT_RIGHT)
{
    this->info.reset(new T{input});
    this->left_node = left;
    this->right_node = right;
    this->flag = false;
    this->type = LEFT_RIGHT;
}

/* ���캯�� */
template <typename T>
BiTree<T>::BiTree(BiTree<T> &tree)
{
    // �����˹����ڴ�
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

/* ���캯�� */
template <typename T>
BiTree<T>::BiTree(BiTree<T> &&tree)
{
    // �����˹����ڴ�
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
    // ������Ҫ�����ʼ��
    auto ptr = new BiTree2Node<T>();
    /* ���ڳ�ʼ���ڵ�δ����ֵ������Ĭ��Ϊδ����״̬ */
    ptr->setPos(0);
    // mem.push_back(reinterpret_cast<BiTreeNode<T> *>(ptr));
    mem.push_back(ptr);

    if (mode == NORMAL)
        for (auto &i : m)
        {
            // ��һ���˷ѿռ䣬�պ���
            this->treeInsert(i.first, i.second, LEFT_RIGHT);
        }
    else if (mode == MIN)
    {
        // ����һ���ӽڵ���ڲ�����
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

            // ����ѡ�������ӽڵ�Ԥ��Ͳ���
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
                throw runtime_error("CONF�������ͼ���������!");
        }
    }
    else
    {
        throw runtime_error("�����ڵĲ���ģʽ!");
    }
}

//////////////////////////////////////  ����ȫ���������������  ///////////////////////////////////////////////

/* ��������� */
template <typename T>
BiTreeNode<T> &BiTreeNode<T>::operator=(BiTreeNode<T> &tree)
{
    // this->info.reset(tree.info.release());
    this->info = tree.info;
    this->type = tree.type;
    this->pos = tree.pos;

    return *this;
}

/* ��������� */
template <typename T>
BiTreeNode<T> &BiTreeNode<T>::operator=(BiTreeNode<T> &&tree)
{
    this->info = tree.info;
    this->type = std::move(tree.type);
    this->pos = tree.pos;

    return *this;
}

/* ��������� */
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

/* ��������� */
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

/* ��������� */
template <typename T>
BiTreeLeft<T> &BiTreeLeft<T>::operator=(BiTreeLeft<T> &tree)
{
    this->info = tree.info;
    this->type = tree.type;
    this->pos = tree.pos;

    this->left_node = tree.left_node;

    return *this;
}

/* ��������� */
template <typename T>
BiTreeLeft<T> &BiTreeLeft<T>::operator=(BiTreeLeft<T> &&tree)
{
    this->info = tree.info;
    this->type = std::move(tree.type);
    this->pos = tree.pos;

    this->left_node = tree.left_node;

    return *this;
}

/* ��������� */
template <typename T>
BiTreeRight<T> &BiTreeRight<T>::operator=(BiTreeRight<T> &tree)
{
    this->info = tree.info;
    this->type = tree.type;
    this->pos = tree.pos;

    this->right_node = tree.right_node;

    return *this;
}

/* ��������� */
template <typename T>
BiTreeRight<T> &BiTreeRight<T>::operator=(BiTreeRight<T> &&tree)
{
    this->info = tree.info;
    this->type = std::move(tree.type);
    this->pos = tree.pos;

    this->right_node = tree.right_node;

    return *this;
}

/* ��������� */
template <typename T>
BiTree<T> &BiTree<T>::operator=(BiTree<T> &tree)
{
    // �����˹����ڴ�
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

/* ��������� */
template <typename T>
BiTree<T> &BiTree<T>::operator=(BiTree<T> &&tree)
{
    // �����˹����ڴ�
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