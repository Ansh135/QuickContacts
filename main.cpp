#include <iostream>
 #include <string.h>
 #include <stdlib.h>
 #include <fstream>
 #include <stack>



 using namespace std;


//NODE STRUCTURE OF BST


class contactbook
{

private:

    string name;
    long long int phone_number;
    string emailid;
    contactbook *left;
    contactbook *right;
    bool fav;

public:

    //CONSTRUCTOR 1

    contactbook()
    {

        // head = NULL;
        name = " ";
        phone_number=0;
        emailid = "";
        left = NULL;
        right = NULL;
        fav = true;

    }

    //CONSTRUCTOR 2

    contactbook(string Name, long long int number,string email)
    {

        name = Name;
        phone_number = number;
        emailid = email;
        left = NULL;
        right = NULL;
        fav = true;

    }

    //FUNCTION TO INSERT A CONTACT BY NAME (RECORD)

    contactbook* Insertbyname(contactbook* &root, string Name, long long int value, string email )
    {

        if (!root)
        {

             root= new contactbook(Name, value, email);

             char f;
             cout << "Do you want to make this contact favourite[Y/N]: ";
             cin >> f;

             if(f == 'Y'|| f == 'y')
                root->fav = false;
             else
                root->fav = true;

        }

        else if (Name < root->name)
        {
            root->left = Insertbyname(root->left, Name, value, email);

        }

        else
        {
            root->right = Insertbyname(root->right, Name, value, email);

        }
        return root;

    }

    //FUNCTION TO DISPLAY ALL RECORDS

    void Display(contactbook* root)
    {
        if (!root)
        {
            return;
        }

        Display(root->left);

        cout << "Name: "<<root->name << endl << "Phone Number: "<< root->phone_number << endl<<"EmailID: " << root->emailid ;
        cout<<endl<<endl<<endl;

        Display(root->right);

        
    }

    //FUNCTION TO INSERT BY NUMBER

    contactbook* Insertbynum(contactbook* &root1, string Name, long long int value, string email)
    {
        if (!root1)
        {

            return new contactbook(Name, value, email);

        }

         if (value < root1->phone_number)
        {

            root1->left = Insertbynum(root1->left, Name, value, email);

        }

        else
        {

            root1->right = Insertbynum(root1->right, Name, value,email);

        }

        return root1;

    }


    //FUNCTION TO SEARCH BY NAME

    int searchbyname(contactbook *root,string Name)
    {
       static bool check;

        if (!root)
            return -1;

        else if (root->name == Name)
       {
            cout<<"***********"<<endl;
            cout<<"  Name: "<<root->name<<endl;
            cout<<"  Phone Number: "<<root->phone_number<<endl;
            cout<<"  EmailID: "<<root->emailid<<endl;
            cout<<"***********"<<endl<<endl;
            check = true;

        return 1;

       }

    

    // Key is greater than root's key

        if (root->name < Name)
       {

            searchbyname(root->right, Name);

       }

    // Key is smaller than root's key

        if (root->name > Name)
       {

            searchbyname(root->left, Name);

       }

       if(check!=true)
        {

        cout<< "  Name Not Found"<<endl;

        return -1;

        }

    }

    //SEARCH BY EMAILID FUNCTION

    int searchbyemail(contactbook *root,string email){
        static bool check;

        if (!root)
            return -1;

        else if (root->emailid == email)
       {
            cout<<"***********"<<endl;
            cout<<"  Name: "<<root->name<<endl;
            cout<<"  Phone Number: "<<root->phone_number<<endl;
            cout<<"  EmailID: "<<root->emailid<<endl;
            cout<<"***********"<<endl<<endl;
            check = true;

        return 1;

       }

    

    // Key is greater than root's email

        if (root->emailid < email)
       {

            searchbyemail(root->right, email);

       }

    // Key is smaller than root's email

        if (root->emailid > email)
       {

            searchbyemail(root->left, email);

       }

       if(check!=true)
        {

        cout<< "  EmailID Not Found"<<endl;

        return -1;

        }
    }

    //FUNCTION TO SEARCH BY NUMBER

    int searchbynum(contactbook *root,long long int num)
    {
       static bool check;

        if (!root)
            return -1;
        else if (root->phone_number == num)
       {
            cout<<"***********"<<endl;
            cout<<"  Name: "<<root->name<<endl;
            cout<<"  Phone Number: "<<root->phone_number<<endl;
            cout<<"  Email: "<<root->emailid<<endl;
            cout<<"***********"<<endl;
            check = true;
            return 1;
       }


    // Key is greater than root's key

        if (root->phone_number < num)
       {

            searchbynum(root->right, num);


       }

    // Key is smaller than root's key

        if (root->phone_number > num)
       {

            searchbynum(root->left, num);


       }
       if(check!=true)
        {

            cout<< "  Name Not Found"<<endl;
            return -1;

        }

    }

    //FUNCTION TO SEARCH RECORDS BY NAME OR NUMBER OR EMAILID

    int search(contactbook *root, contactbook *root1)
    {
        if (!root)
        {

            cout<<"  No Contacts... Please Add Some Contacts"<<endl;

		    cout<<"  Thanks"<<endl;

            return 1;

        }

        cout<<"***********"<<endl;

	    cout<<"  Press 1 if you want to Search By Name."<<endl;

		cout<<"  Press 2 if you want to Search By Number."<<endl;

        cout<<"  press 3 if you want to Search by EmailID."<<endl;

    	int command;

	    cout<<"  Enter the Command: ";

		cin>>command;

        if(command==1 && root!=NULL)
        {

            string Name;

            cout<<"  Enter the Name to Search: ";

	    	cin>>Name;

            searchbyname(root, Name);

	    }

        else if(command==2)
	    	{

	    		long long int num;

                cout << "  Enter the Number to Search: ";

                cin >> num;

                searchbynum(root1,num);

            }
        else if (command==3){

            string email;
            cout<<"Enter EmailID to Search by: ";
            cin>>email;
            searchbyemail(root,email);
        }
        
    }

    //FUNTION TO GET LEFTMOST CONTACT NODE

    contactbook * minval(contactbook *root)
    {

        contactbook *x = root;

        while (x->left != NULL)
        {
            x = x->left;
        }

        return x;

    }

    //SUBFUNCTION OF DELETE FUNCTION

    contactbook * delete_1(contactbook * root , string n1)
    {

        if (root == NULL)
        {
            return root;

        }

        else if (root->name == n1)
        {
        //   0 child case -
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;

            }

            //   1 child case -

            if (root->right == NULL && root->left != NULL)
            {
                contactbook *temp = root->left;
                delete root;
                return temp;

            }

            if (root->right != NULL && root->left == NULL)
            {
                contactbook *temp = root->right;
                delete root;
                return temp;

            }

            //   2 child case -

            if (root->right != NULL && root->left != NULL)
            {
                string mini = minval(root->right)->name;
                root->name = mini;
                root->right = delete_1(root->right, mini);
                return root;

            }
        }

        else if (root->name > n1)
        {
            root->left = delete_1(root->left, n1 );

        }
        else
        {
            root->right = delete_1(root->right, n1 ) ;

        }
    }

    //FUNCTION TO DELETE SPECIFIC CONTACT(NODE)

    contactbook * delete_spec(contactbook * root)
    {

        string n1;

        cout<<" ENTER NAME TO BE DELETED :"<<endl;

        cin>>n1;

        if(root=delete_1(root , n1)){

            cout<<"DELETED SUCCESSFULLY "<<endl;

        }
        else
        {

            cout<<"NAME NOT FOUND"<<endl;

        }
        return root;
    }

    //FUNCTION TO INSERT CONTACT

    void insertcontact(contactbook* &root, contactbook* &root1)
    {
        string str;
        long long int Num;
        string email;
        cout << "Enter Name : ";
        cin >> str;
        cout << "Enter Phone number : ";
        cin >> Num;
        cout<< "Enter EmailID : ";
        cin>>email;

        Insertbyname(root,str,Num,email);
        Insertbynum(root1,str,Num,email);

    }

    //SUBFUNCTION WHICH SEARCHES BY NAME

    contactbook * sname(contactbook *root, string n1)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->name == n1)
        {
            return root;
        }

        if (n1> root->name)
        {
            return sname(root->right, n1);
        }
        else{

            return sname(root->left, n1);
        }
    }


    //SUBFUNCTION WHICH SEARCHES BY NUMBER


    contactbook * snumber(contactbook *root, long long int n2)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->phone_number == n2)
        {
            return root;
        }

        if (n2> root->phone_number)
        {
            return snumber(root->right, n2);
        }
        else{
            return snumber(root->left, n2);

        }
    }


    //SUBFUNCTION WHICH SEARCHES BY EMAIL


    contactbook * semail(contactbook *root, string n3)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->emailid == n3)
        {
            return root;
        }

        if (n3> root->emailid)
        {
            return semail(root->right, n3);
        }
        else{
            return semail(root->left, n3);
        }
    }

    //FUNCTION TO EDIT CONTACT BY NAME OR NUMBER OR EMAILID

    void edit1(contactbook * root, contactbook *root1)
    {

        int command;

        cout<<"ENTER 1 TO EDIT BY NAME : "<<endl;

        cout<<"ENTER 2 TO EDIT BY NUMBER   : "<<endl;

        cout<<"ENTER 3 TO EDIT BY EMAILID   :"<<endl;
       
        cin >> command;

        if(command==1){

            string n2 , n3 ;
            cout<<"ENTER NAME :"<<endl;
            cin>>n2;

            root=sname(root , n2);
           
            if(root==NULL){
                cout<<"NAME NOT FOUND "<<endl;
            }

            string s1;
            cout<<"ENTER NEW NAME"<<endl;
            cin>>s1;
            root->name=s1;
           

        }
        else if(command==2)
        {
            long long int n2 , n3 ;
            cout<<"ENTER NUMBER :"<<endl;
            cin>>n2;

            root=snumber(root , n2);
            

            if(root==NULL){

                cout<<"NUMBER NOT FOUND"<<endl;

            }

            long long int s1;

            cout<<"ENTER NEW NUMBER"<<endl;
            cin>>s1;

            root->phone_number=s1;
           
        }

        else if(command==3){
            string n2, n3;

            cout<<"Enter EMAILID: "<<endl;
            cin>>n2;

            root=semail(root,n2);
            
            if(root==NULL){

                cout<<"EMAIL NOT FOUND"<<endl;


            }
            cout<<"Enter new Emailid: " <<endl;
            cin>>n3;
            root->emailid=n3;
            

        }
    }

    //function to delete all contacts

    void delete_Tree(contactbook* node)
    {
        if (node == NULL)
            return;

        delete_Tree(node->left);
        delete_Tree(node->right);

        delete node;
    }

    void showfav(contactbook* &rt)
    {
        stack<contactbook *> s;
        contactbook *curr = rt;

        while (!s.empty() || curr != NULL)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if (curr->fav!= true)
            {
                cout << " Name: "<< curr->name << endl;
                cout << "NUMBER: "<<curr->phone_number << endl;
                cout << "EmailID: "<<curr->emailid<< " "<<endl;

            }
                curr = curr->right;
        }
    }

    //FUNCTION FOR MENU

    void menu(contactbook* &rt, contactbook* &rt1)
    {
        int c;
        st :
        cout<<endl<<"1 for Inserting new contact."<<endl;
        cout<<"2 for Displaying all contacts."<<endl;
        cout<<"3 for Searching any contact."<<endl;
        cout<<"4 for Editing contacts."<<endl;
        cout<<"5 for Deleting any specific contact"<<endl;
        cout<<"6 for Deleting whole contact directory"<<endl;
        cout<<"7 for Showing favourite contacts"<<endl;
        cout<<"8 for exit"<<endl;
        cout<<"Enter Your choice :-"<<endl;
        cin>>c;

        switch(c)
        {
            case 1:
            {
                insertcontact(rt,rt1);
                OflineSave(rt);
                cout<<endl;
            }
            goto st;
            case 2:
            {
                Display(rt);
                cout<<endl;
            }
            goto st;
            case 3:
            {
                search(rt,rt1);
                cout<<endl;
            }
            goto st;
            case 4:
            {
                edit1(rt,rt1);
                cout<<endl;
            }
            goto st;
            case 5:
            {
                delete_spec(rt);
                cout<<endl;
            }
            goto st;
            case 6:
            {
                delete_Tree(rt);
                cout<<endl;

            }
            goto st;
            case 7:
            {
                showfav(rt);
                cout<<endl;

            }
            goto st;
            case 8:
            {
                cout<<endl;
                cout<<"!!!Thankyou for visiting!!!";
                cout<<endl;
            }
                break;
            default:
            {
                cout<<endl;
                cout<<"Invalid Input, Enter again!";
                cout<<endl;
            }
            goto st;
        }

    }


    //FUNCTION FOR SAVING ALL CONTACTS IN A TXT FILE


    void OflineSave(contactbook *rt)
    	{
    		ofstream myfile ("contactbook.txt");

            if (myfile.is_open())
            {
                stack<contactbook *> s;
                contactbook *curr = rt;

                while (!s.empty() || curr != NULL)
                {
                    while (curr != NULL)
                    {
                        s.push(curr);
                        curr = curr->left;
                    }
                    curr = s.top();
                    s.pop();
                    myfile << "***********************************************************************************" << endl;
                    myfile << "NAME: "<< curr->name << endl;
                    myfile << "NUMBER: "<< curr->phone_number << endl;
                    myfile << "EmailID: "<< curr->emailid << endl<<endl;
                    myfile << "***********************************************************************************" << endl;
                    curr = curr->right;
                }
                myfile.close();
            }
            else
            {
            	cout<<"  Thanks, file is empty."<<endl;

			}
		}
};



//DRIVER CODE:


int main()
{
    system("cls");
    system("color B");
    
    contactbook *rt=NULL,*rt1=NULL;
    contactbook b;



    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+                                                                                                         +\n");
    printf("+                       ******  ******    *   *   ******      *       ******    ******                    +\n");
    printf("+                       *       *    *    **  *     *        * *      *           *                       +\n");
    printf("+                       *       *    *    *  **     *       * * *     *           *                       +\n");
    printf("+                       ******  ******    *   *     *      *     *    ******      *                       +\n");
    printf("+                                                                                                         +\n");
    printf("+              ******   *****   *****   *******   ******   ******   ******    ******    *   *             +\n");
    printf("+              *    *     *     *   *   *         *          *      *    *    *    *     * *              +\n");
    printf("+              *    *     *     *****   ****      *          *      *    *    ******      *               +\n");
    printf("+              *    *     *     * *     *         *          *      *    *    * *         *               +\n");
    printf("+              ******   *****   *   *   *******   ******     *      ******    *   *       *               +\n");
    printf("+                                                                                                         +\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");




    b.menu(rt,rt1);
    return 0 ;

}