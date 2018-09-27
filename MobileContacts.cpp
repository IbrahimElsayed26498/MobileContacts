//In the name of Allah the Gracious the merciful
/*
    That was a project for the first year first term at collage 
    Student project : Mobile Contacts
        Faculty of Electronic Engineering
        Dr /Hanaa Torkey
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

#define Size 30
struct node
{
    string num;
    char name[Size]= {' '};
    char family[Size]= {' '};
    node *next;
    node *prev;
};

class Contact
{
private:
    node *head;
public:
    Contact();
    void  Start();//the main function of functions(the main screen)
    void  NewContact(node*&h);//add new contact
    void  Delete(node *&h);//delete contact
    void  View(node*&h);//the main fuction of the (View) functions
    void  View_details(node*&h);//show details of contacts
    void  View_names(node*&h);//view only names without details
    void  viewOneContact(node*&h);//view the details for one contact
    void  Search(node*&h);//the main function of search
    void  searchByName(node*&h);//search by writing the first name
    void  SearchByFamily(node*&h);//search by writing the family name
    void  searchByFirstChar(node*&h);//search by writing the first Char
    void  searchByChar(node *&h);//Search by writing any char
    void  searchByNumber(node*&h);//search by writing the number
    bool  Check(node*&h,char ch[Size],int z);//Searching help function(checks if the name is exists)
    bool  CheckChar(node*&h,char ch);//Searching help function(check if the char is exists)
    int   count_contacts(node*&h);//it's count how many contacts in the linked list
    void  Edit(node *&h);//edit the contact(s)
    void  ClearName(node*&h);//this functions clear the first name(Editing help function)
    void  ClearFamily(node*&h);//this function clear the family name(Editing help function)
};

int main()
{
    cout<< "In the name of Allah, the Gracious the Merciful"<<endl;
    cout<< "\n\t\tWELCOME ! !"<<endl;
    cout<< "\n\t******Contacts book******"<<endl;
    Contact c1;
    c1.Start();
    return 0;
}
Contact :: Contact()
{
    head =NULL;
}

void Contact::Start()
{
    while(true)
    {
        int x;
        cout<< "\n================================\n";
        cout<< "\n1. Add new contact\n2. Search\n3. View All\n4. Delete\n5. Edit\n6. Clear \n7. Exit"<<endl;
        cout<< "\nEnter your choice : ";
        cin>>x;
        switch(x)
        {
        case 1:
            NewContact(*&head);
            break;
        case 2:
            Search(*&head);
            break;
        case 3:
            View(*&head);
            break;
        case 4:
            Delete(*&head);
            break;
        case 5:
            Edit(*&head);
            break;
        case 6:
            system("cls");
            cout<< "In the name of Allah, the Gracious the Merciful"<<endl;
            cout<< "\n\t\tWELCOME ! !"<<endl;
            cout<< "\n\t******Contacts book******"<<endl;
            break;
        case 7:
            return ;
        default :
            cout<< "\n Wrong choice ! !\n";
        }
    }

}

void Contact::NewContact(node* &h)
{
    node* ptr,*ptr1=h;//ptr1 is the moving pointer
    ptr = new(nothrow) node;//ptr is the pointer which will save the information of the new contact
    if(ptr==0)//check if the node is successfully created
    {
        cout<< "\nError ! !\n";
        return ;
    }
    cin.ignore();//solves cin.getline problems
    cout<< "\nName   : ";
    cin.getline(ptr->name,Size);//enter the name
    cout<< "Family : ";
    cin.getline(ptr->family,Size);//Enter the family
    cout<< "Number : ";
    cin>>ptr->num;//enter the number
    ptr->next=NULL;
    ptr->prev=NULL;
    if(h==NULL)//if the list is empty
    {
        h=ptr;
        ptr->prev=NULL;//make the prev pointer poin to NULL
    }
    else//the list is not empty
    {
        while(ptr1!=NULL)
        {
            if(ptr1->name[0]>ptr->name[0])
            {
                if(ptr1->prev== NULL)
                {
                    h=ptr;
                    ptr->next=ptr1;
                    ptr1->prev=ptr;
                    break;
                }
                else
                {
                    ptr->next=ptr1;
                    ptr->prev=ptr1->prev;
                    ptr1->prev->next=ptr;
                    ptr1->prev=ptr;
                    break;
                }
            }
            else if(ptr1->next==NULL)
            {
                ptr1->next=ptr;
                ptr->prev=ptr1;
                break;
            }
            ptr1=ptr1->next;
        }
    }
    cout<< "\nThe new contact has been added successfully.\n";
    return ;
}

void Contact::View_details(node * &h)
{
    node *temp=h;
    if(temp==NULL)
    {
        cout<< "\n\tList is empty ! !\n\nThere is no Contacts have been added\n";
        return ;
    }
    short C=1;
    cout<< "\n********The List*******\n";
    while(temp!=NULL)
    {
        cout<< "\nContact Number : "<<C<<endl;
        C++;
        cout<< "\n\tName         : ";
        for(int i=0; i<Size; i++)
            cout<<temp->name[i];
        cout<< "\n\tFamily       : ";
        for(int j=0; j<Size; j++)
            cout<<temp->family[j];
        cout<< "\n\tPhone Number : "<<temp->num;
        cout<< "\n\n===========================\n";
        temp=temp->next;
    }
    cout<< "\n\t\tEnd of the List ! !\n\n";
    return;
}

void Contact::View(node*&h)
{
    int x;
    cout<< "\n1. View Names\n2. View details\n";
    cout<< "\nYour choice:";
    cin>>x;
    switch(x)
    {
    case 1:
        View_names(*&h);
        break;
    case 2:
        View_details(*&h);
        break;
    default :
        cout<< "Sorry ! Wrong Choice!!\n";
    }
    return ;
}

void Contact::View_names(node*&h)
{
    int c=1;
    node *ptr=h;
    if(ptr==0)
    {
        cout<< "\tList is Empty ! !\n";
        return ;
    }
    else
    {
        cout<< "\n********* The List ********\n";
        while(ptr!=NULL)
        {
            cout<<c<<"\n. Full name : "<<ptr->name<< " "<<ptr->family<<endl;
            c++;
            ptr=ptr->next;
        }
        cout<< "\n\tEnd of the list ! !\n";
        return ;
    }
}

int Contact::count_contacts(node*&h)
{
    int c=0;
    node *C=h;
    if(C==NULL)
        return c;
    else
    {
        while(C!=NULL)
        {
            c++;
            C=C->next;
        }
    }
    return c;
}

void Contact::Delete(node *&h)
{
    int x;
    int n=count_contacts(*&h);
    node *temp=h;
    if (n==0)
    {
        cout<< "\n************List is empty***********\n";
        return ;
    }
    View_names(*&h);
    cout<< "\n\nEnter the number of the name you want to delete : ";
    cin>> x;
    if(x<=0)
    {
        cout<< "Wrong Number!!";
        return ;
    }
    if(x>n)// the user entered a non contained number
    {
        cout<< "\n\t\tWrong Number\n";
        return ;
    }
    else if(x==1)//first element
    {
        if(n!=1)//check if there is more one element in the linked list
        {
            h=h->next;
            h->prev =NULL;
            delete temp;
        }
        else
        {
            h=NULL;
            delete temp;
        }
        cout<< "\n\n\t\tThe number deleted successfully ! !\n";
        return ;
    }
    //After this cases so the number is not in the start.
    for(int i=1; i<x; i++)
    {
        temp=temp->next;
    }
    if(x==n)//last element
    {
        temp->prev->next=NULL;
        delete temp;
    }
    else//the element is on the middle of the linked list
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
    cout<< "\n\t\tThe contact deleted successfully ! ! \n";
    return ;
}

void Contact::viewOneContact(node*&h)
{
    int i;
    cout<< "\n*************************************************************\n";
    cout<< "\nName   : ";
    for(i=0; i<Size; i++)
    {
        cout<< h->name[i];
    }
    cout<<endl;
    cout<< "Family : ";
    for(i=0; i<Size; i++)
    {
        cout<< h->family[i];
    }
    cout<<endl;
    cout<< "Number : "<<h->num<<endl;
    cout<< "\n*************************************************************\n";
}

void Contact::Search(node*&h)
{
    int x;
    if(h==NULL)
    {
        cout<< "\n**************The list is empty**********\n";
        return ;
    }
    cout<< "\n==>Do you want to search by ....\n";
    cout<< "\n1. Name\n2. Family\n3. Number\n4. First Character\n5. Character\n";
    cout<< "Enter your choice : ";
    cin>>x;
    switch(x)
    {
    case 1:
        searchByName(*&h);
        break;
    case 2:
        SearchByFamily(*&h);
        break;
    case 3:
        searchByNumber(*&h);
        break;
    case 4:
        searchByFirstChar(*&h);
        break;
    case 5:
        searchByChar(*&h);
        break;
    default :
        cout<< "\aWrong choice ! !"<<endl;
    }
    return ;
}

void Contact::searchByFirstChar(node *&h)
{
    node *temp=h;
    char ch;
    short int x=0;
    cout<< "\nEnter the first char : ";
    cin>>ch;
    while(temp!=NULL)
    {
        if(ch==temp->name[0])
        {
            viewOneContact(*&temp);
            x++;
        }
        else if(ch>temp->name[0])
            break;
        temp=temp->next;
    }
    if (x==0)
        cout<< "\nNot Found\n";
}

void Contact::searchByNumber(node*&h)
{
    node *temp=h;
    string Number;
    int x=0;
    cout<< "\nEnter the Number : ";
    cin>>Number;
    while(temp!=NULL)
    {
        if(Number==temp->num)
        {
            viewOneContact(*&temp);
            x++;
            break;
        }
        temp=temp->next;
    }
    if (x==0)
        cout<< "\n\aNot Found\n";
}

void Contact::searchByName(node *&h)
{
    node *temp=h;
    char name[Size]= {' '};
    int x=0;
    cout<< "\nEnter the Name : ";
    cin.ignore();
    cin.getline(name,Size);
    while(temp!=NULL)
    {
        if(Check(*&temp,name,1))
        {
            viewOneContact(*&temp);
            x++;
        }
        temp=temp->next;
    }
    if(x==0)
        cout<< "\nNot Found\n";
}

void Contact::SearchByFamily(node*&h)
{
    node *temp=h;
    char name[Size]= {' '};
    int x=0;
    cout<< "\nEnter the Family name : ";
    cin.ignore();
    cin.getline(name,Size);
    while(temp!=NULL)
    {
        if(Check(*&temp,name,2))
        {
            viewOneContact(*&temp);
            x++;
        }
        temp=temp->next;
    }
    if(x==0)
        cout<< "\nNot Found\n";
}

void Contact::searchByChar(node*&h)
{
    node *temp=h;
    char ch;
    int x=0;
    cout<< "\nEnter Char : ";
    cin>>ch;
    while(temp!=NULL)
    {
        if(CheckChar(*&temp,ch))
        {
            viewOneContact(*&temp);
            x++;
        }
        temp=temp->next;
    }
    if(x==0)
        cout<< "\nNot Found\n";
}

bool Contact::Check(node*&h,char ch[Size],int z)//if z == 1 it will search by the name else by the family
{
    short int x=0;
    if(z==1)
    {
        for(int i=0; i<Size; i++)
        {
            if(!(ch[i]==h->name[i]))
            {
                x=1;
                break;
            }
        }
        if(x==1)
            return false;
        return true;
    }
    else
    {
        for(int i=0; i<Size; i++)
        {
            if(!(ch[i]==h->family[i]))
            {
                x=1;
                break;
            }
        }
        if(x==1)
            return false;
        return true;
    }

}
bool Contact::CheckChar(node*&h,char ch)
{
    for(int i=0; i<Size; i++)
    {
        if(ch==h->name[i])
        {
            return true;
        }
        else if(ch==h->family[i])
        {
            return true;
        }

    }
    return false;
}

void Contact::Edit(node*&h)
{
    node *temp=h;
    int  x;
    short int y=count_contacts(*&h);
    View_names(*&h);
    if(y==0)
        return;
    cout<< "\nEnter the number of the name : ";
    cin>>x;
    if(x>y)
    {
        cout<< "\n\t\tWrong number ! !\n";
    }
    else
    {
        for(int i=1; i<x; i++)
        {
            temp=temp->next;
        }
        while(true)
        {
            cout<< "\n1. Name\n2. Family\n3. Number\n4. Exit";
            cout<< "\nEnter your choice : ";
            cin>>x;
            switch(x)
            {
            case 1 :
                ClearName(*&temp);
                cout<< "\nName : ";
                cin.ignore();
                cin.getline(temp->name,Size);
                cout<< "\n\t\tSaved !\n";
                break;
            case 2:
                ClearFamily(*&temp);
                cout<< "\nFamily : ";
                cin.ignore();
                cin.getline(temp->family,Size);
                cout<< "\n\t\tSaved !\n";
                break;
            case 3:
                cout<< "Number : ";
                cin>>temp->num;
                cout<< "\n\t\tSaved !\n";
            default :
                return;
            }
        }
    }
}

void Contact::ClearName(node *&h)
{
    for(int i=0; i<Size; i++)
        h->name[i]=' ';
}

void Contact::ClearFamily(node *&h)
{
    for(int i=0; i<Size; i++)
        h->family[i]=' ';
}
         
