class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=nullptr;
    }
};
class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head=nullptr;
        size=0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        if(head==nullptr) return -1;
        Node* mover=head;
        int curr=0;
        while(mover!=nullptr){
            if(curr==index) return mover->val;
            curr++;
            mover=mover->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
        size++;
    }
    
    void addAtTail(int val) {
        if(head==nullptr){
            addAtHead(val);
            return;
        }
        Node* mover=head;
        while(mover->next!=nullptr) mover=mover->next;
        Node* temp=new Node(val);
        mover->next=temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;
        if(index==size){
            addAtTail(val);
            return;
        } 
        if(index==0) {
            addAtHead(val);
            return;
        }
        int count=0;
        Node* mover=head;
        while(count<index-1){
            mover=mover->next;
            count++;
        }
        Node* temp=new Node(val);
        temp->next=mover->next;
        mover->next=temp;
        size++;
    }
    void deleteAtIndex(int index) {
        if(index<0 ||index>=size || head==nullptr) return;
        int curr=0;
        Node* mover=head;
        if(index==0){
            head=head->next;
            delete mover;
            size--;
            return;
        }
        for (int i = 0; i < index - 1; i++) {
            mover = mover->next;
        }
        Node* del=mover->next;
        if(del!=nullptr){
            mover->next=del->next;
            delete del;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
