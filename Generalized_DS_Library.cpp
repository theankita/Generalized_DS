/////////////////////////////////////////////////////
//      Generalized Data Structure Library
/////////////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------------------
Type                    Name of class for node          Name of class of Functionality
---------------------------------------------------------------------------------------------------
Singly Linear           SinglyLLLNode                   SinglyLLL       Done
Singly Circular         SinglyCLLNode                   SinglyCLL       Done
Doubly Linear           DoublyLLLNode                   DoublyLLL       Done
Doubly Circular         DoublyCLLNode                   DoublyCLL       Done
Stack                   StackNode                       Stack           Done
Queue                   QueueNode                       Queue           Done

*/

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
//          Singly Linear LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class SinglyLLLNode
{
    public:
        T data;
        SinglyLLLNode<T> *next;

        SinglyLLLNode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:
        SinglyLLLNode<T> * first;
        int iCount;

    public:
    
        SinglyLLL();

        void InsertFirst(T);    
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);  

        void Display();
        int Count(); 
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets  created\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)     
{
    SinglyLLLNode<T> * newn = NULL;

    newn = new SinglyLLLNode<T>(no);

    newn -> next =  this->first;      
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLNode<T> *  newn = NULL;
    SinglyLLLNode<T> *  temp = NULL;

    newn = new SinglyLLLNode<T>(no);

    if(this->iCount == 0)            
    {
        this->first = newn;   
    }
    else
    {
        temp = this->first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLNode<T> * temp = NULL;

    if(this->first == NULL)                      
    {
        return;
    }
    else if(this->first -> next == NULL)           
    {
        delete  this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void  SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLNode<T> * temp = NULL;

    if(this->first == NULL)                      
    {
        return;
    }
    else if(this->first -> next == NULL)           
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp =  this->first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display nodes from linked list 
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLNode<T> * temp = NULL;
    int iCnt = 0;
    temp =  this->first;

    for(iCnt=1 ; iCnt <=  this->iCount ; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to count number of nodes from linked list
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node , Position
//  Output :            Nothing
//  Description :       Used to insert node at nth position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no , int pos)
{
    SinglyLLLNode<T> * newn = NULL;
    SinglyLLLNode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
            cout<<"Invalid position\n";
            return;
        }

        if(pos == 1)
        {
            this->InsertFirst(no);
        }
        else if(pos ==  this->iCount + 1)
        {
            this-> InsertLast(no);
        }
        else
        {
            newn = new SinglyLLLNode<T>(no);

            temp = this->first;

            for(iCnt=1 ; iCnt < pos-1 ; iCnt++)
            {
                temp =  temp -> next;
            }

            newn -> next = temp -> next;
            temp -> next = newn;

            this->iCount++;
        }        
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Used to delete node at nth position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLNode<T> * temp = NULL;
    SinglyLLLNode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt=1 ; iCnt < pos-1 ; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;            
        temp -> next = target -> next;

        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////
//          Doubly Linear LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class DoublyLLLNode
{
    public:
        T data;
        DoublyLLLNode *next;
        DoublyLLLNode *prev;
  
        DoublyLLLNode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLNode<T> * first;                
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL <T> :: DoublyLLL()
{
    cout<<"Linked list gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLNode<T> *newn = NULL;                          

    newn = new DoublyLLLNode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn -> next = this -> first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL <T> :: InsertLast(T no)
{
    DoublyLLLNode<T> *newn = NULL;
    DoublyLLLNode<T> *temp = NULL;

    newn = new DoublyLLLNode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node , Position
//  Output :            Nothing
//  Description :       Used to insert node at nth position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL <T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLNode<T> *newn = NULL;
    DoublyLLLNode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLNode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL <T>  :: DeleteFirst()
{
    if(this->first == NULL)        
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete(this->first);
        this->first = NULL;
    }
    else                                 
    {
        this->first = this->first->next;
        delete this->first->prev;

        this->first->prev = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL <T> :: DeleteLast()
{
    DoublyLLLNode<T> *temp = NULL;

    if(this->first == NULL)        
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete(this->first);
        this->first = NULL;
    }
    else                                 
    {
        temp = this->first;
        
        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position 
//  Output :            Nothing
//  Description :       Used to delete node at nth position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL <T>  :: DeleteAtPos(int pos)
{
    DoublyLLLNode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp->next->prev;

        temp -> next -> prev = temp;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display nodes from linked list 
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL <T> :: Display()
{
    DoublyLLLNode<T> *temp = NULL;

    temp = this->first;

    cout<<"\nNULL <=>";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=>";
        temp = temp -> next;
    }
    cout<<" NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to count nodes from LL
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL <T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////
//          Singly Circular LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class SinglyCLLNode
{
    public:
        T data;
        SinglyCLLNode *next;
  
        SinglyCLLNode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLNode<T> * first;   
        SinglyCLLNode<T> * last;             
        int iCount;

    public:
        SinglyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
SinglyCLL <T> :: SinglyCLL()
{
    cout<<"Linked list gets created\n";

    this->first = NULL;
    this->last = NULL;    
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLNode<T> *newn = NULL;                          

    newn = new SinglyCLLNode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn -> next = this -> first;
        this->first = newn;
    }

    this->last->next = this->first;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLNode<T> *newn = NULL;
    SinglyCLLNode<T> *temp = NULL;

    newn = new SinglyCLLNode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this-> last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->last->next = this->first;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node , Position
//  Output :            Nothing
//  Description :       Used to insert node at nth position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL <T> :: InsertAtPos(T no, int pos)
{
    SinglyCLLNode<T> *newn = NULL;
    SinglyCLLNode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLNode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
        
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>  :: DeleteFirst()
{
    if(this->first == NULL)        
    {
        return;
    }
    else if(first == last)    
    {
        delete(this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else                                 
    {
        this->first = this->first->next;
        delete this->last->next;
        this->last->next = this->first;        
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL <T> :: DeleteLast()
{
    SinglyCLLNode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)        
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete(this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else                                 
    {
        temp = this->first;
        
        do
        {
            temp = temp -> next;
        } while (temp->next != this->last);

        delete temp -> next;
        this->last = temp;
        this->last->next = this->first;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Used to delete node at nth position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL <T>  :: DeleteAtPos(int pos)
{
    SinglyCLLNode<T> *temp = NULL;
    SinglyCLLNode<T> *target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display nodes from linked list 
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL <T> :: Display()
{
    SinglyCLLNode<T> *temp = NULL;

    temp = this->first;

    cout<<" -> ";
    do
    {
        cout<<" | "<<temp->data<<"| ->";
        temp = temp -> next;
    }while(temp != first);   

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to count nodes from LL
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL <T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////
//          Doubly Circular LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class DoublyCLLNode
{
    public:
        T data;
        DoublyCLLNode *next;
        DoublyCLLNode *prev;
  
        DoublyCLLNode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLNode<T> * first;   
        DoublyCLLNode<T> * last;             
        int iCount;

    public:
        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyCLL <T> :: DoublyCLL()
{
    cout<<"Linked list gets created\n";

    this->first = NULL;
    this->last = NULL;    
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLNode<T> *newn = NULL;                          

    newn = new DoublyCLLNode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn -> next = this -> first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLNode <T> *newn = NULL;
    DoublyCLLNode<T> *temp = NULL;

    newn = new DoublyCLLNode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this-> last = newn;
    }
    else
    {
        this->last->next = newn;
        this->first->prev = newn;
        this->last = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node , Position
//  Output :            Nothing
//  Description :       Used to insert node at nth position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyCLLNode<T> *newn = NULL;
    DoublyCLLNode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLNode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        newn -> prev = temp;
        temp -> next = newn;
        this->first->prev = this->last;
        
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>  :: DeleteFirst()
{
    if(this->first == NULL)        
    {
        return;
    }
    else if(first == last)    
    {
        delete(this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else                                 
    {
        this->first = this->first->next;
        delete this->first->prev;
        
        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    DoublyCLLNode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)        
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete(this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else                                 
    {
        temp = this->first;
        
        do
        {
            temp = temp -> next;
        } while (temp->next != this->last);

        delete temp -> next;
        this->last = temp;
        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Position
//  Output :            Nothing
//  Description :       Used to delete node at nth position
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL <T> :: DeleteAtPos(int pos)
{
    DoublyCLLNode<T> *temp = NULL;
    DoublyCLLNode<T> *target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1 ; iCnt < pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp -> next = target -> next;
        target -> next  -> prev = temp;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display nodes from linked list 
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLNode<T> *temp = NULL;

    temp = this->first;

    cout<<" <=> ";
    do
    {
        cout<<" | "<<temp->data<<"| <=>";
        temp = temp -> next;
    }while(temp != first);   

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to count nodes from the LL
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL <T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////
//              Stack using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;
    
    public:
        Stack();

        void push(T);            
        T pop();                
        T peep();
        void Display();
        int  Count();
};

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created successfully\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Push
//  Input :             Element
//  Output :            Nothing
//  Description :       Used to insert element in stack
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: push(T no)          
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn -> next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Pop
//  Input :             Nothing
//  Output :            Element
//  Description :       Used to delete element from stack
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}   

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Peep
//  Input :             Nothing
//  Output :            Element
//  Description :       Display top element
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display elements from the Stack
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp -> next;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Number of elements
//  Description :       Used to count elements from stack
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////
//              Queue using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;
    
    public:
        Queue();

        void enqueue(T);            
        T dequeue();                
    
        void Display();
        int  Count();
};

template<class T>
Queue<T>:: Queue()
{
    cout<<"Queue gets created successfully\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Enqeue
//  Input :             Element
//  Output :            Nothing
//  Description :       Used to insert element in queue
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: enqueue(T no)          
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)  
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;    
    }
    
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Dequeue
//  Input :             Nothing
//  Output :            Element  
//  Description :       Used to delete element from the queue
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}   

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Nothing
//  Output :            Nothing
//  Description :       Used to display elements from the queue
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty";
        return;     
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp -> next;
    }

    cout<<"\n"; 
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Nothing
//  Output :            Number of elements
//  Description :       Used to count elements from the queue
//  Author :            Ankita Shinde
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

////////////////////////////// End Of Library /////////////////////////////////

int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number  of nodes are:"<<iRet<<"\n";   

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number  of nodes are:"<<iRet<<"\n";   

    obj->DeleteFirst();
    obj->Display();
    iRet = obj->Count();
    cout<<"Number  of nodes are:"<<iRet<<"\n";
    
    obj->DeleteLast();
    obj->Display();  
    iRet = obj->Count();
    cout<<"Number  of nodes are:"<<iRet<<"\n";   

    obj->InsertAtPos(105,4);
    obj->Display();  
    iRet = obj->Count();
    cout<<"Number  of nodes are:"<<iRet<<"\n"; 
    
    obj->DeleteAtPos(4);
    obj->Display();  
    iRet = obj->Count();
    cout<<"Number  of nodes are:"<<iRet<<"\n"; 

    delete obj;

/////////////////////////////////////////////////////////////////////////////

    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout<<"Number of elements are:"<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"Number of elements are:"<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Number of elements are:"<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    cout<<"Number of elements are:"<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);
    dobj->Display();
    cout<<"Number of elements are:"<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();
    cout<<"Number of elements are:"<<dobj->Count()<<"\n";

    delete dobj;


/////////////////////////////////////////////////////////////////////////////

    SinglyCLL<double> *dobj1 = new SinglyCLL<double>();

    dobj1->InsertFirst(30.2);
    dobj1->InsertFirst(20.988);
    dobj1->InsertFirst(10.45);

    dobj1->Display();

    cout<<"Number of elements are:"<<dobj1->Count()<<"\n";

    dobj1->InsertLast(40.34);
    dobj1->InsertLast(50.8);
    dobj1->InsertLast(60.56);

    dobj1->Display();
    cout<<"Number of elements are:"<<dobj1->Count()<<"\n";

    dobj1->DeleteFirst();
    dobj1->Display();
    cout<<"Number of elements are:"<<dobj1->Count()<<"\n";

    dobj1->DeleteLast();
    dobj1->Display();
    cout<<"Number of elements are:"<<dobj1->Count()<<"\n";

    dobj1->InsertAtPos(45.78,4);
    dobj1->Display();
    cout<<"Number of elements are:"<<dobj1->Count()<<"\n";

    dobj1->DeleteAtPos(4);
    dobj1->Display();
    cout<<"Number of elements are:"<<dobj1->Count()<<"\n";

    delete dobj1;

/////////////////////////////////////////////////////////////////////////////

    DoublyCLL<float> *obj1 = new DoublyCLL<float>();

    obj1->InsertFirst(30.25f);
    obj1->InsertFirst(20.8f);
    obj1->InsertFirst(10.2f);

    obj1->Display();

    cout<<"Number of elements are:"<<obj1->Count()<<"\n";

    obj1->InsertLast(40.34f);
    obj1->InsertLast(50.745f);
    obj1->InsertLast(60.61f);

    obj1->Display();
    cout<<"Number of elements are:"<<obj1->Count()<<"\n";

    obj1->DeleteFirst();
    obj1->Display();
    cout<<"Number of elements are:"<<obj1->Count()<<"\n";

    obj1->DeleteLast();
    obj1->Display();
    cout<<"Number of elements are:"<<obj1->Count()<<"\n";

    obj1->InsertAtPos(45.34f,4);
    obj1->Display();
    cout<<"Number of elements are:"<<obj1->Count()<<"\n";

    obj1->DeleteAtPos(4);
    obj1->Display();
    cout<<"Number of elements are:"<<obj1->Count()<<"\n";

    delete obj1;
    
/////////////////////////////////////////////////////////////////////////////
    
    Stack<char> *sobj = new Stack<char>();

    sobj->push('A');
    sobj->push('B');
    sobj->push('C');
    sobj->push('D');

    sobj->Display();

    cout<<"Number of elements in stack are:"<<sobj->Count()<<"\n";

    cout<<"Return value of peep is:"<<sobj->peep()<<"\n";
    
    sobj->Display();
    cout<<"Number of elements in stack are:"<<sobj->Count()<<"\n";

    cout<<"Popped element is:"<<sobj->pop()<<"\n";
    sobj->Display();
    cout<<"Number of elements in stack are:"<<sobj->Count()<<"\n";
    
    cout<<"Popped element is:"<<sobj->pop()<<"\n";
    sobj->Display();
    cout<<"Number of elements in stack are:"<<sobj->Count()<<"\n";

    sobj->push('E');
    sobj->Display();
    cout<<"Number of elements in stack are:"<<sobj->Count()<<"\n";

    delete sobj;
    
/////////////////////////////////////////////////////////////////////////////

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();

    cout<<"Number of elements in queue are:"<<qobj->Count()<<"\n";
    
    cout<<"Removed element is:"<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in queue are:"<<qobj->Count()<<"\n";

    cout<<"Removed element is:"<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in queue are:"<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);   
    qobj->Display();
    cout<<"Number of elements in queue are:"<<qobj->Count()<<"\n";

    delete qobj;
    return 0;
}
