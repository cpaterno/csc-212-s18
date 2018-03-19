class DArray {
    private:
        int cap;
        int length;
        int* content;
        void grow();
        void shrink();

    public:
        DArray();
        DArray(int);
        ~DArray();

        int size();
        int capacity();
        int at(int);
        int front();
        int back();
        bool empty();
        void clear();
        void set(int, int);
        void push_back(int);
        int pop_back();
        void insert(int, int);
        void erase(int);
};
