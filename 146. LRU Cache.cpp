

class LRUCache
{

    struct Node
    {
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int x, int y) : key(x), val(y), next(NULL), prev(NULL) {}
    };

public:
    int cache_capacity;
    unordered_map<int, Node *> mp;
    int cnt;
    Node *head;
    Node *tail;

    void add_front(Node *x)
    {
        Node *head_next = head->next;
        x->next = head_next;
        head_next->prev = x;
        head->next = x;
        x->prev = head;
    }

    void remove_back(Node *x)
    {
        Node *next_node = x->next;
        Node *prev_node = x->prev;

        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    LRUCache(int capacity)
    {

        cache_capacity = capacity;
        cnt = 0;
        mp.clear();

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *x = mp[key];
            int ret = x->val;
            remove_back(x);
            add_front(x);
            return ret;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {

        Node *x = mp[key];

        if (x != NULL)
        {
            remove_back(x);
            x->val = value;
            add_front(x);
        }
        else
        {
            if (cnt == cache_capacity)
            {
                cnt--;
                mp.erase(tail->prev->key);
                remove_back(tail->prev);
            }
            cnt++;
            Node *new_node = new Node(key, value);
            mp[key] = new_node;
            add_front(new_node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */