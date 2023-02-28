#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////
// Structure for Singly Linear and Singly Circular
template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

////////////////////////////////////////////////////////////////
// Structure for Doubly Linear and doubly Circular
template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

////////////////////////////////////////////////////////////////

// Class of Singly Linear Linked List
template <class T>
class SinglyLL
{
    public:
        struct nodeS<T> * First;

        SinglyLL();
        int iCount;

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        int SearchFirstOccurace(T no);
        int SearchLastOccurace(T no);
        int Addition();
        int Maximum();
        int Minimum();
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        bool CheckPrime(T iNo);
        void DisplayPrime();

        void Display();
};

template <class T>
SinglyLL <T> :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL <T> :: InsertFirst(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next =  NULL;

    if(First == NULL) 
    {
        First = newn;
        iCount++;
    }
    else 
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL <T> :: InsertLast(T no)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next =  NULL;

    if(First == NULL) 
    {
        First = newn;
        iCount++;
    }
    else 
    {
        struct nodeS<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL <T>:: InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> * newn = new struct nodeS<T>;

        newn->data = no;
        newn->next = NULL;

        struct nodeS<T> * temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL <T>:: DeleteFirst()
{
    if(First == NULL) 
    {
        return;
    }
    else if(First -> next == NULL) 
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct nodeS<T> * temp = First;
        First = First -> next;
        delete temp;
        iCount--;
    }
}

template <class T>
void SinglyLL <T>:: DeleteLast()
{    
    if(First == NULL)   
    {
        return;
    }
    else if(First -> next == NULL) 
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct nodeS <T>* temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        iCount--;
    }
}

template <class T>
void SinglyLL <T>:: DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> * temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1;iCnt++)
        {
            temp1 = temp1->next;
        }

        struct nodeS<T> * temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

template <class T>
int SinglyLL <T>:: SearchFirstOccurace(T no)
{
    struct nodeS<T> * temp = First;
    int iCnt = 1;
    int iCount = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        iCnt++;
        if(temp->data == no)
        {
           iCount = iCnt;
           break;
        }
        
    }
    return iCount;
}

template <class T>
int SinglyLL <T>::SearchLastOccurace(T no)
{
    struct nodeS<T> * temp = First;
    int iCnt = 1;
    int iCount = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        iCnt++;
        if(temp->data == no)
        {
           iCount = iCnt;
          
        }
        
    }
    return iCount;
}

template <class T>
int SinglyLL <T>:: Addition()
{
    struct nodeS<T> * temp = First;
    T Sum = 0;
    
    while(temp->next != NULL)
    {       
        Sum = Sum + temp->data;
        temp = temp->next;       
    }
    return Sum;
}
template <class T>
int SinglyLL <T>:: Maximum()
{
    struct nodeS<T> * temp = First;
    T iMax = temp->data;
    
    while(temp->next != NULL)
    {  
        if(temp ->data > iMax) 
        {   
            iMax = temp->data;
        }
        temp = temp->next;
    }
    return iMax;
}

template <class T>
int SinglyLL <T> :: Minimum()
{
    struct nodeS<T> * temp = *First;
    T iMin = temp->data;
    
    while(temp->next != NULL)
    {  
        if(temp ->data < iMin) 
        {   
            iMin = temp->data;
        }
        temp = temp->next;
    }
    return iMin;
}

template <class T>
bool SinglyLL <T> ::CheckPerfect(T iNo)
{
    T iSum = 0;
    T iTemp = iNo;
    int iCnt = 0;

    for(iCnt = 1;iCnt <= (iNo/2);iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    return (iSum == iTemp); 
}

template <class T>
void SinglyLL <T> ::DisplayPerfect()
{
    while(First != NULL)
    {
        if(CheckPerfect(First->data) == true)
        {
		cout<<First->data<<" is a perfect number"<<"\n"; 
        }
        First = First->next;
    }
}

template <class T>
bool SinglyLL <T>::CheckPrime(T iNo)
{
    int iCnt = 0;
    bool bFlag = false;

    for(iCnt = 2; iCnt <= iNo; iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            bFlag = true;
        }
        else
        {
            bFlag = false;
        }
    }
    if(bFlag == true)
    {
        return bFlag;
    }
    else
    {
        return 1;
    }
}

template <class T>
void SinglyLL <T>::DisplayPrime()
{
    while(First != NULL)
    {
        if(CheckPrime(First->data) == true)
        {
		cout<<First->data<<" is a prime number"<<"\n";
        }
        First = First->next;
    }
}

template <class T>
void SinglyLL <T>:: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

////////////////////////////////////////////////////////////////

// Class of Singly Circular Linked List
template <class T>
class SinglyCL
{
    public:
        struct nodeS<T> * First;
        struct nodeS <T> * Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        int SearchFirstOccurace(T no);
        int SearchLastOccurace(T no);
        int Addition();
        int Maximum();
        int Minimum();
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        bool CheckPrime(T iNo);
        void DisplayPrime();

        void Display();
        int Count();
};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct nodeS <T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else 
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct nodeS <T> * newn = new struct nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL)) 
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else  
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

template <class T>
int SinglyCL <T>:: SearchFirstOccurace(T no)
{
    struct nodeS<T> * temp = First;
    int iCnt = 1;
    int iCount = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        iCnt++;
        if(temp->data == no)
        {
           iCount = iCnt;
           break;
        }
        
    }
    return iCount;
}

template <class T>
int SinglyCL <T>::SearchLastOccurace(T no)
{
    struct nodeS<T> * temp = First;
    int iCnt = 1;
    int iCount = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        iCnt++;
        if(temp->data == no)
        {
           iCount = iCnt;
          
        }
        
    }
    return iCount;
}

template <class T>
int SinglyCL <T>:: Addition()
{
    struct nodeS<T> * temp = First;
    T Sum = 0;
    
    while(temp->next != NULL)
    {       
        Sum = Sum + temp->data;
        temp = temp->next;       
    }
    return Sum;
}
template <class T>
int SinglyCL <T>:: Maximum()
{
    struct nodeS<T> * temp = First;
    T iMax = temp->data;
    
    while(temp->next != NULL)
    {  
        if(temp ->data > iMax) 
        {   
            iMax = temp->data;
        }
        temp = temp->next;
    }
    return iMax;
}

template <class T>
int SinglyCL <T> :: Minimum()
{
    struct nodeS<T> * temp = *First;
    T iMin = temp->data;
    
    while(temp->next != NULL)
    {  
        if(temp ->data < iMin) 
        {   
            iMin = temp->data;
        }
        temp = temp->next;
    }
    return iMin;
}

template <class T>
bool SinglyCL <T> ::CheckPerfect(T iNo)
{
    T iSum = 0;
    T iTemp = iNo;
    int iCnt = 0;

    for(iCnt = 1;iCnt <= (iNo/2);iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    return (iSum == iTemp); 
}

template <class T>
void SinglyCL <T> ::DisplayPerfect()
{
    while(First != NULL)
    {
        if(CheckPerfect(First->data) == true)
        {
		cout<<First->data<<" is a perfect number"<<"\n"; 
        }
        First = First->next;
    }
}

template <class T>
bool SinglyCL <T>::CheckPrime(T iNo)
{
    int iCnt = 0;
    bool bFlag = false;

    for(iCnt = 2; iCnt <= iNo; iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            bFlag = true;
        }
        else
        {
            bFlag = false;
        }
    }
    if(bFlag == true)
    {
        return bFlag;
    }
    else
    {
        return 1;
    }
}

template <class T>
void SinglyCL <T>::DisplayPrime()
{
    while(First != NULL)
    {
        if(CheckPrime(First->data) == true)
        {
		cout<<First->data<<" is a prime number"<<"\n";
        }
        First = First->next;
    }
}

template <class T>
void SinglyCL<T> :: Display()
{
    struct nodeS <T> * temp = First;

    cout<<"Elements of Linked list are :";

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"NULL\n";
}

template <class T>
int SinglyCL<T> :: Count()
{
    struct nodeS <T> * temp = First;
    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    struct nodeS <T> * temp = First;

    if((First == NULL) && (Last == NULL)) 
    {
        return;
    }
    else if(First == Last) 
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else   
    {
        First = (First)->next;
        delete temp;
        (Last) ->next = First;
    }
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct nodeS <T> * temp = First;

    if((First == NULL) && (Last == NULL)) 
    {
        return;
    }
    else if(First == Last)   
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else   
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;
        Last = temp; 
        (Last) ->next = First;
    }
}

template <class T>
void SinglyCL <T>:: InsertAtPos(T no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct nodeS <T> * newn = NULL;
    struct nodeS <T> * temp = First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeS <T>; 
        
        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct nodeS <T> * temp1 = First;
    struct nodeS <T> * temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}
////////////////////////////////////////////////////////////////

// Class of Doubly Linear Linked List

template <class T>
class DoublyLL
{
    public:
        struct nodeD<T> * First;

        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        int SearchFirstOccurace(T no);
        int SearchLastOccurace(T no);
        int Addition();
        int Maximum();
        int Minimum();
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        bool CheckPrime(T iNo);
        void DisplayPrime();

        void Display();
};

template <class T>
DoublyLL <T>:: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL <T>:: InsertFirst(T no)
{
    struct nodeD <T> * newn = new struct nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;  // X

        First = newn;
        iCount++;
    }
}

template <class T>
void DoublyLL <T>:: InsertLast(T no)
{
    struct nodeD <T> * newn = new struct nodeD<T>;
    struct nodeD <T> *  temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // X
        iCount++;
    }
}

template <class T>
void DoublyLL <T>:: Display()
{
    cout<<"Elements of the Linked List are :"<<"\n";

    cout<<"NULL<=> ";

    while(First != NULL)
    {
        cout<<"| "<<First->data<<" |<=>";
        First = First->next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
void DoublyLL <T>:: DeleteFirst()
{
    struct nodeD <T> *  temp = First;
    if(First == NULL)      //LL is empty
    {
        return;
    }
    else if((First)->next == NULL)     //LL contains 1 element
    {
        delete(First);
        First = NULL;
        iCount--;
    }
    else                //LL contains more than one elements
    {
        (temp) = (temp) -> next;
        delete(temp->prev);       //X
        (temp)->prev = NULL;      //X
        iCount--;
    }
}

template <class T>
void DoublyLL <T>:: DeleteLast()
{
    struct nodeD <T> *  temp = First;

    if(First == NULL)      //LL is empty
    {
        return;
    }
    else if((First)->next == NULL)     //LL contains 1 element
    {
        delete(First);
        First = NULL;
        iCount--;
    }
    else                //LL contains more than one elements
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp ->next;
        }
        delete(temp-> next);
        temp ->next = NULL;
        iCount--;
    }
}

template <class T>
void DoublyLL <T>:: InsertAtPos(T no,int iPos)
{
    int iCnt = 0;
    struct nodeD <T> *  newn = NULL;
    struct nodeD <T> *  temp = NULL;

    if((iPos < 1) || (iPos > (iCount + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == (iCount + 1))
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeD<T> ;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      //X

        temp = First;

        for(iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;        //X
        temp -> next = newn;
        newn -> prev = temp;                //X
        iCount++;

    }
}

template <class T>
void DoublyLL <T>:: DeleteAtPos(int iPos)
{
    struct nodeD <T> * temp1 = NULL;
    struct nodeD <T> * temp2 = NULL;
    int iCnt = 0;


    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(iCnt = 1;iCnt < (iPos - 1);iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1 -> next; 
        temp1 ->next = temp2->next;
        delete(temp2);
        iCount--;
    }
}

template <class T>
int DoublyLL <T>:: SearchFirstOccurace(T no)
{
    struct nodeD<T> * temp = First;
    int iCnt = 1;
    int iCount = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        iCnt++;
        if(temp->data == no)
        {
           iCount = iCnt;
           break;
        }
        
    }
    return iCount;
}

template <class T>
int DoublyLL <T>::SearchLastOccurace(T no)
{
    struct nodeD<T> * temp = First;
    int iCnt = 1;
    int iCount = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        iCnt++;
        if(temp->data == no)
        {
           iCount = iCnt;
          
        }
        
    }
    return iCount;
}

template <class T>
int DoublyLL <T>:: Addition()
{
    struct nodeD<T> * temp = First;
    T Sum = 0;
    
    while(temp->next != NULL)
    {       
        Sum = Sum + temp->data;
        temp = temp->next;       
    }
    return Sum;
}
template <class T>
int DoublyLL <T>:: Maximum()
{
    struct nodeD<T> * temp = First;
    T iMax = temp->data;
    
    while(temp->next != NULL)
    {  
        if(temp ->data > iMax) 
        {   
            iMax = temp->data;
        }
        temp = temp->next;
    }
    return iMax;
}

template <class T>
int DoublyLL <T> :: Minimum()
{
    struct nodeD<T> * temp = *First;
    T iMin = temp->data;
    
    while(temp->next != NULL)
    {  
        if(temp ->data < iMin) 
        {   
            iMin = temp->data;
        }
        temp = temp->next;
    }
    return iMin;
}

template <class T>
bool DoublyLL <T> ::CheckPerfect(T iNo)
{
    T iSum = 0;
    T iTemp = iNo;
    int iCnt = 0;

    for(iCnt = 1;iCnt <= (iNo/2);iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    return (iSum == iTemp); 
}

template <class T>
void DoublyLL <T> ::DisplayPerfect()
{
    while(First != NULL)
    {
        if(CheckPerfect(First->data) == true)
        {
		cout<<First->data<<" is a perfect number"<<"\n"; 
        }
        First = First->next;
    }
}

template <class T>
bool DoublyLL <T>::CheckPrime(T iNo)
{
    int iCnt = 0;
    bool bFlag = false;

    for(iCnt = 2; iCnt <= iNo; iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            bFlag = true;
        }
        else
        {
            bFlag = false;
        }
    }
    if(bFlag == true)
    {
        return bFlag;
    }
    else
    {
        return 1;
    }
}

template <class T>
void DoublyLL <T>::DisplayPrime()
{
    while(First != NULL)
    {
        if(CheckPrime(First->data) == true)
        {
		cout<<First->data<<" is a prime number"<<"\n";
        }
        First = First->next;
    }
}

////////////////////////////////////////////////////////////////

// Class of Doubly Circular Linked List

template <class T>
class DoublyCL
{
    public:
        struct nodeD<T> * First;
        struct nodeD<T> * Last;

        DoublyCL();
        
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        int SearchFirstOccurace(T no);
        int SearchLastOccurace(T no);
        int Addition();
        int Maximum();
        int Minimum();
        bool CheckPerfect(T iNo);
        void DisplayPerfect();
        bool CheckPrime(T iNo);
        void DisplayPrime();

        void Display();
        int Count();
};

template <class T> 
DoublyCL<T> :: DoublyCL()      //Default Constructor
{
    First = NULL;
    Last = NULL;
}

template <class T> 
void DoublyCL<T> ::  InsertFirst(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        newn->next = First;
        First->prev = newn;
        First = newn; 
    }

    First->prev = Last;
    Last->next = First;
}

template <class T> 
void DoublyCL<T> :: InsertLast(T no)
{
    struct nodeD<T> * newn = new struct nodeD<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template <class T> 
void DoublyCL<T> :: Display()
{
    struct nodeD<T> * temp = First;
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<" |<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

template <class T> 
int DoublyCL<T> :: Count()
{
    struct nodeD<T> * temp = First;
    int iCnt = 0;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

template <class T> 
void DoublyCL <T>:: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        //free(*First);
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        (First) = (First) ->next;
        //free((*Last)->next);        // free((*First)->prev);
        delete (Last)->next;

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T> 
void DoublyCL<T> :: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        //free(*First);
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        //free((*First)->prev);       // free((*Last)->next);
        delete (First)->prev;

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T> 
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    int  iNodeCnt = Count();
    struct nodeD<T> * newn = NULL;
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt +1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct nodeD<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1;iCnt < ipos - 1;iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
    
}

template <class T> 
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    int  iNodeCnt = Count();
    struct nodeD<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt +1)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1;iCnt < ipos - 1;iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
    
}

template <class T>
int DoublyLL <T>:: SearchFirstOccurace(T no)
{
    struct nodeD<T> * temp = First;
    int iCnt = 1;
    int iCount = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        iCnt++;
        if(temp->data == no)
        {
           iCount = iCnt;
           break;
        }
        
    }
    return iCount;
}

template <class T>
int DoublyLL <T>::SearchLastOccurace(T no)
{
    struct nodeD<T> * temp = First;
    int iCnt = 1;
    int iCount = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        iCnt++;
        if(temp->data == no)
        {
           iCount = iCnt;
          
        }
        
    }
    return iCount;
}

template <class T>
int DoublyLL <T>:: Addition()
{
    struct nodeD<T> * temp = First;
    T Sum = 0;
    
    while(temp->next != NULL)
    {       
        Sum = Sum + temp->data;
        temp = temp->next;       
    }
    return Sum;
}
template <class T>
int DoublyLL <T>:: Maximum()
{
    struct nodeD<T> * temp = First;
    T iMax = temp->data;
    
    while(temp->next != NULL)
    {  
        if(temp ->data > iMax) 
        {   
            iMax = temp->data;
        }
        temp = temp->next;
    }
    return iMax;
}

template <class T>
int DoublyLL <T> :: Minimum()
{
    struct nodeD<T> * temp = *First;
    T iMin = temp->data;
    
    while(temp->next != NULL)
    {  
        if(temp ->data < iMin) 
        {   
            iMin = temp->data;
        }
        temp = temp->next;
    }
    return iMin;
}

template <class T>
bool DoublyLL <T> ::CheckPerfect(T iNo)
{
    T iSum = 0;
    T iTemp = iNo;
    int iCnt = 0;

    for(iCnt = 1;iCnt <= (iNo/2);iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    return (iSum == iTemp); 
}

template <class T>
void DoublyLL <T> ::DisplayPerfect()
{
    while(First != NULL)
    {
        if(CheckPerfect(First->data) == true)
        {
		cout<<First->data<<" is a perfect number"<<"\n"; 
        }
        First = First->next;
    }
}

template <class T>
bool DoublyLL <T>::CheckPrime(T iNo)
{
    int iCnt = 0;
    bool bFlag = false;

    for(iCnt = 2; iCnt <= iNo; iCnt++)
    {
        if(iNo % iCnt == 0)
        {
            bFlag = true;
        }
        else
        {
            bFlag = false;
        }
    }
    if(bFlag == true)
    {
        return bFlag;
    }
    else
    {
        return 1;
    }
}

template <class T>
void DoublyLL <T>::DisplayPrime()
{
    while(First != NULL)
    {
        if(CheckPrime(First->data) == true)
        {
		cout<<First->data<<" is a prime number"<<"\n";
        }
        First = First->next;
    }
}

////////////////////////////////////////////////////////////////

//Class of Stack
template <class T>
struct nodeStack
{
    T data;
    struct nodeStack *next;
};

template <class T>
class Stack
{
    public:
        struct nodeStack<T> *First;
        int iCount;

        Stack();

        bool IsStackEmpty();
        void Push(T no);      //Insert
        T Pop();              //delete
        void Display();
};

template <class T>
Stack <T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Stack<T> :: IsStackEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Stack <T>:: Push(T no)      //InsertFirst
{
    struct nodeStack<T> * newn = new struct nodeStack<T>;

    newn ->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;

    cout<<"Gets pushed in the stack successfully"<<"\n";
}

template <class T>
T Stack <T>:: Pop()              //DeleteLast
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty"<<"\n";
        return -1;
    }
    else
    {
        T value = First->data;
        struct nodeStack<T> * temp = First;
        First = First->next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void Stack<T> ::  Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty"<<"\n";
    }
    else
    {
        cout<<"Elements of Stack are : "<<"\n";

        struct nodeStack <T>*temp =First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp -> next;
        }
        cout<<"NULL "<<"\n";
    }
}
///////////////////////////////////////////////////////////////

//Class of Queue
template <class T> 
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <class T>
class Queue
{
    public:
        struct nodeQ<T> * First;
        int iCount;

        Queue();

        bool IsQueueEmpty();
        void EnQueue(T no);       //Insert    Push
        T DeQueue();              //delete    Pop
        void Display();
};

template <class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Queue<T> :: IsQueueEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Queue<T> :: EnQueue(T no)      //InsertLast
{
    struct nodeQ<T> * newn = new struct nodeQ<T>;

    newn ->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeQ<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp ->next;
        }
        temp->next = newn;
    }
    iCount++;

    cout<<"Gets pushed in the Queue successfully"<<"\n";
}

template <class T>
T Queue<T> :: DeQueue()              //DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to pop the element as Stack is empty"<<"\n";
        return(T) -1;
    }
    else
    {
        T value = First->data;
        struct nodeQ<T> * temp = First;
        First = First->next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void Queue<T> ::  Display()
{
    if(First == NULL)
    {
        cout<<"Queue is empty"<<"\n";
    }
    else
    {
        cout<<"Elements of Queue are : "<<"\n";

        struct nodeQ <T>*temp =First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp -> next;
        }
        cout<<"NULL "<<"\n";
    }
}
///////////////////////////////////////////////////////////////

int main()
{
    
    return 0;
}