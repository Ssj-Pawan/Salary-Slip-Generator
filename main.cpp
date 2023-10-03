#include <bits/stdc++.h>

using namespace std;

class Employee
{
public:
    string EmpId;     //employee id
    string Name;     //employee name
    string Salary;  //salary of the employee


    Employee(string EmpId="", string Name="", string Salary=""): EmpId(EmpId), Name(Name), Salary(Salary)
    {

    }

    bool operator==(const Employee& obj)   //Operator overloading is for storing the data
    {
        return (EmpId == obj.EmpId) && (Name == obj.Name) && (Salary==obj.Salary);
    }

    friend ostream& operator<<(ostream& out, const Employee& obj)   //This friend function is for writing the data
    {
        out<<obj.EmpId<<" "<<obj.Name<<" "<<obj.Salary<<endl;
        return out;
    }

    friend istream& operator>>(istream& in,  Employee& obj)     //This friend function is for reading the data
    {
        in>>obj.EmpId;
        in>>obj.Name;
        in>>obj.Salary;

        return in;
    }


};

class EmployeeData
{
public:
    void addEmployee()
    {
        string empid, name, salary;
        cout<<"Enter Employee Id : ";
        cin>>empid;
        cout<<"Enter the name of Employee : ";
        cin>>name;
        cout<<"Enter the Salary of the Employee : ";
        cin>>salary;

        Employee emp(empid, name, salary);
        ofstream out("Employee.txt", ios::app);
        out<<emp;
        out.close();
        cout<<" The Employee "<< empid <<" has been added to the database "<<endl;
    }

    void disEmployee()
    {
        cout<<"EmpId\tName\tSalary"<<endl;
        Employee e;
        ifstream in("Employee.txt");

        while(in)
        {
            in>>e;
            cout<< e.EmpId <<"\t"<< e.Name <<"\t"<< e.Salary <<endl;
        }
        in.close();
    }

    double generatePaySlip()
    {
        int month;
        cout<<"Enter the month(in digits): ";
        cin>>month;

        string id;
        cout<<"Enter the Employee Id to generate payable amount: ";
        cin>>id;


        Employee e;
        ifstream in("Employee.txt");

        while(in)
        {
            in>>e;

            if(id==e.EmpId)
            {
                int wdays;    //No. of working days by Employee
                cout<<"Enter the number of present days by employee: ";
                cin>>wdays;
                double salary = stod(e.Salary);

                switch(month)
                {
                case 1:
                    return calculateAmount(salary,wdays,31);
                    break;

                case 2:
                    return calculateAmount(salary,wdays,28);
                    break;

                case 3:
                    return calculateAmount(salary,wdays,31);
                    break;

                case 4:
                    return calculateAmount(salary,wdays,30);
                    break;

                case 5:
                    return calculateAmount(salary,wdays,31);
                    break;

                case 6:
                    return calculateAmount(salary,wdays,30);
                    break;

                case 7:
                    return calculateAmount(salary,wdays,31);
                    break;

                case 8:
                    return calculateAmount(salary,wdays,31);
                    break;

                case 9:
                    return calculateAmount(salary,wdays,30);
                    break;

                case 10:
                    return calculateAmount(salary,wdays,31);
                    break;

                case 11:
                    return calculateAmount(salary,wdays,30);
                    break;

                case 12:
                    return calculateAmount(salary,wdays,31);
                    break;
                }

            }

        }
        in.close();
    }

    double calculateAmount( double salary, int pDays, int tDays)   //pDays= no. of working days by the employee and tDays= Total no. of days in the given month
    {
        if(pDays>tDays)
        {
            cout<<"The working days cannot be greater than the Total days"<<endl;
        }
        else
        {
            double pdSalary = salary/tDays;    //pdSalary=per day salary of the employee
            double amount = pdSalary*pDays;
            cout<<" The payable amount of the Employee is: "<< amount <<endl;

            return amount;
        }


    }

    void createPaySlip()
    {
        string id;
        cout <<"Enter the Employee Id : ";
        cin >>id;
        Employee e;
        ifstream in("Employee.txt");

        while(in)
        {
            in>>e;
            if(id==e.EmpId)
            {
                double amt = generatePaySlip();
                ofstream out("Pay Slip.doc");
                out<<"XYZ Company"<<endl;
                out<<"Employee Id : "<< e.EmpId <<endl;
                out<<"Name of the Employee : "<< e.Name <<endl;
                out<<"Basic Salary of the Employee : "<< e.Salary <<endl;
                out<<"Amount Payable : "<<amt<<endl;
                out.close();
            }
        }





    }
};

int main()
{
    int ch;
    EmployeeData emp;

    do
    {
        cout << "--------------XYZ Company--------------" << endl;
        cout << "1. Add Employee " <<endl;
        cout << "2. Display Employee " <<endl;
        cout << "3. Get Payable Amount of the Employee " <<endl;
        cout << "4. Generate Salary Slip " <<endl;
        cout << "5. Exit " <<endl;

        cout << "Enter Your Choice " <<endl;
        cin>>ch;

        switch(ch)
        {
        case 1:
            emp.addEmployee();
            break;

        case 2:
            emp.disEmployee();
            break;

        case 3:
            emp.generatePaySlip();
            break;

        case 4:
            emp.createPaySlip();

        case 5:
            cout << "Exiting\n";
            break;

        default:
            cout << " Enter the correct Choice\n";

        }
    }
    while(ch!=5);


    return 0;
}
