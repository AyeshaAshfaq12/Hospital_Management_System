//-----------------Header Files-------------------//
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
using namespace std;
//-------------Function Prototypes----------------//
void clearScreen();
void hms();
bool adminLogin();
void header();
int menu();
void adminHeader();
int adminMenu();
void addDoctor();
void sortDoctors();
void viewDoctors();
void updateDoctors();
void deleteDoctors();
void updateSalaries();
void viewPayments();
void viewReview();
void editManual();
void doctorHeader();
bool doctorLogin();
int doctorMenu();
void addPatient();
void sortPatients();
void viewPatients();
void updatePatients();
void deletePatients();
void prescription();
void makeAppointments();
void viewAppointments();
void updateAppointments();
void deleteAppointments();
void generateReports();
void editFees();
void patientHeader();
int patientMenu();
void viewPrescriptions();
void viewReports();
void viewLabResults();
void viewDoctorFees();
void billPayments();
void giveReviews();
void manual();
//----------Functions for File Handling----------------//
string parseRecord(int field, string line);
void store1();
void load1();
void load_doctors(string line1);
void store2();
void load2();
void load_patients(string line2);
void store3();
void load3();
void load_prescriptions(string line3);
void store4();
void load4();
void load_appointments(string line4);
void store5();
void load5();
void load_reports(string line5);
void store6();
void load6();
void load_payments(string line6);
void store7();
void load7();
void store8();
void load8();
void store9();
void load9();
//---------------Validity Checker---------------//
bool validityChecker();
bool contactValidation();
//--------------Data Structures ( Arrays , Variables )-------------//
const int MAX_RECORDS = 100;
int doctorCount = 0;
string doctorId[MAX_RECORDS];
string doctorPassword[MAX_RECORDS];
string doctorNames[MAX_RECORDS];
int doctorAges[MAX_RECORDS];
string doctorAddress[MAX_RECORDS];
string doctorQualification[MAX_RECORDS];
int doctorSalary[MAX_RECORDS];
string doctorContact[MAX_RECORDS];

int patientCount = 0;
int prescriptionCount = 0;
int appointmentCount = 0;
int reportsCount = 0;
int checkupFees;
int labTestFees;
int paymentCount = 0;
int reviewCount = 0;

string patientId[MAX_RECORDS];
string patientName[MAX_RECORDS];
int patientAge[MAX_RECORDS];
string patientDisease[MAX_RECORDS];
string patientMedicine[MAX_RECORDS];
string patientAddress[MAX_RECORDS];
string patientContact[MAX_RECORDS];

string prescriptionId[MAX_RECORDS];
string addPrescription[MAX_RECORDS];

string appointmentId[MAX_RECORDS];
string appointmentDay[MAX_RECORDS];
string appointmentTime[MAX_RECORDS];

string reportsId[MAX_RECORDS];
string test[MAX_RECORDS];
string result[MAX_RECORDS];

string paymentId[MAX_RECORDS];
int payments[MAX_RECORDS];

string reviews[MAX_RECORDS];

string instructionManual[6];
//--------------Validity Checker------------//
string num;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
main()
{
    load1();
    load2();
    load3();
    load4();
    load5();
    load6();
    load7();
    load8();
    load9();
    system("cls");
    hms();
    header();
    int option = menu();
    clearScreen();
    while (option < 5) //  we have set loop value true so loop will keep executing, we will apply some condition to break it
    {

        if (option == 1)
        {
            hms();
            header();
            adminHeader();
            if (adminLogin())
            {
                clearScreen();
                hms();
                header();
                adminHeader();
                int option1 = adminMenu();
                clearScreen();
                while (option1 < 12)
                {
                    if (option1 == 1)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << "Add record" << endl;
                        cout << "-----------" << endl;
                        cout << endl;
                        if (doctorCount < MAX_RECORDS)
                        {
                            addDoctor();
                            store1();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No more capacity. ";
                        }
                        clearScreen();
                    }
                    if (option1 == 2)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << "View Doctors (sorted according to Salary)" << endl;
                        cout << "-----------------------------------------" << endl;
                        cout << endl;
                        if (doctorCount >= 1)
                        {
                            sortDoctors();
                            viewDoctors();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if (option1 == 3)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << "Update records" << endl;
                        cout << "------------" << endl;
                        cout << endl;
                        if (doctorCount >= 1)
                        {
                            updateDoctors();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if (option1 == 4)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << "Delete records" << endl;
                        cout << "------------" << endl;
                        cout << endl;
                        if (doctorCount >= 1)
                        {
                            deleteDoctors();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if (option1 == 5)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << "View Patients (sorted according to Age)" << endl;
                        cout << "----------------------------------------" << endl;
                        cout << endl;
                        if (patientCount >= 1)
                        {
                            viewPatients();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if (option1 == 6)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << "View Apointments" << endl;
                        cout << "----------------" << endl;
                        cout << endl;
                        if (appointmentCount >= 1)
                        {
                            viewAppointments();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if (option1 == 7)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << "Update Salaries" << endl;
                        cout << "---------------" << endl;
                        cout << endl;
                        if (doctorCount >= 1)
                        {
                            updateSalaries();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet." << endl;
                        }
                        clearScreen();
                    }
                    if (option1 == 8)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << "View Checkup Fees" << endl;
                        cout << "-----------------" << endl;
                        cout << endl;
                        viewDoctorFees();
                        clearScreen();
                    }
                    if (option1 == 9)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << "View Bill Payments" << endl;
                        cout << "------------------" << endl;
                        cout << endl;
                        if (paymentCount >= 1)
                        {
                            viewPayments();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No payments yet." << endl;
                        }
                        clearScreen();
                    }
                    if (option1 == 10)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << "View Reviews by Patients" << endl;
                        cout << "------------------------" << endl;
                        cout << endl;
                        if (reviewCount >= 1)
                        {
                            viewReview();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No reviews yet." << endl;
                        }
                        clearScreen();
                    }
                    if (option1 == 11)
                    {
                        hms();
                        header();
                        adminHeader();
                        cout << endl;
                        cout << "Edit Instruction Manual" << endl;
                        cout << "-----------------------" << endl;
                        cout << endl;
                        editManual();
                        store8();
                        clearScreen();
                    }
                    hms();
                    header();
                    adminHeader();
                    option1 = adminMenu();
                    clearScreen();
                }
            }
            else
            {
                cout << endl;
                cout << "Wrong Username or Password.";
                cout << endl;
                clearScreen();
            }
        }
        if (option == 2)
        {
            hms();
            header();
            doctorHeader();
            if (doctorLogin())
            {
                clearScreen();
                hms();
                header();
                doctorHeader();
                int option2 = doctorMenu();
                clearScreen();
                while (option2 < 15)
                {
                    if (option2 == 1)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "Add Patient" << endl;
                        cout << "-----------" << endl;
                        cout << endl;
                        if (patientCount < MAX_RECORDS)
                        {
                            addPatient();
                            store2();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No more capacity. ";
                        }
                        clearScreen();
                    }
                    if (option2 == 2)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "View Patients (sorted according to Age)" << endl;
                        cout << "---------------------------------------" << endl;
                        cout << endl;
                        if (patientCount >= 1)
                        {
                            sortPatients();
                            viewPatients();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet.";
                        }
                        clearScreen();
                    }
                    if (option2 == 3)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "Update Patients" << endl;
                        cout << "---------------" << endl;
                        cout << endl;
                        if (patientCount >= 1)
                        {
                            updatePatients();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet.";
                        }
                        clearScreen();
                    }
                    if (option2 == 4)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "Delete Patients" << endl;
                        cout << "---------------" << endl;
                        cout << endl;
                        if (patientCount >= 1)
                        {
                            deletePatients();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet.";
                        }
                        clearScreen();
                    }
                    if (option2 == 5)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "Add Prescriptions" << endl;
                        cout << "-----------------" << endl;
                        cout << endl;
                        if (patientCount >= 1)
                        {
                            prescription();
                            store3();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet.";
                        }
                        clearScreen();
                    }
                    if (option2 == 6)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "Make Appointments" << endl;
                        cout << "-----------------" << endl;
                        cout << endl;
                        if (patientCount >= 1)
                        {
                            makeAppointments();
                            store4();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No patients to make appointment with.";
                        }
                        clearScreen();
                    }
                    if (option2 == 7)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "View Appointments" << endl;
                        cout << "-----------------" << endl;
                        cout << endl;
                        if (appointmentCount >= 1)
                        {
                            viewAppointments();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet.";
                        }
                        clearScreen();
                    }
                    if (option2 == 8)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "Update Appointments" << endl;
                        cout << "-------------------" << endl;
                        cout << endl;
                        if (appointmentCount >= 1)
                        {
                            updateAppointments();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet.";
                        }
                        clearScreen();
                    }
                    if (option2 == 9)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "Cancel Appointments" << endl;
                        cout << "-------------------" << endl;
                        cout << endl;
                        if (appointmentCount >= 1)
                        {
                            deleteAppointments();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No records yet.";
                        }
                        clearScreen();
                    }
                    if (option2 == 10)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "Generate Reports" << endl;
                        cout << "----------------" << endl;
                        cout << endl;
                        if (patientCount >= 1)
                        {
                            generateReports();
                            store5();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No reports yet.";
                        }
                        clearScreen();
                    }
                    if (option2 == 11)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "View Lab Test Reports" << endl;
                        cout << "---------------------" << endl;
                        cout << endl;
                        if (patientCount >= 1)
                        {
                            viewLabResults();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No reports yet.";
                        }
                        clearScreen();
                    }
                    if (option2 == 12)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << endl;
                        cout << "Edit Checkup Fees" << endl;
                        cout << "-----------------" << endl;
                        cout << endl;
                        editFees();
                        store9();
                        clearScreen();
                    }
                    if (option2 == 13)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "View Reviews by Patients" << endl;
                        cout << "------------------------" << endl;
                        cout << endl;
                        if (patientCount >= 1)
                        {
                            viewReview();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No reviews yet.";
                        }
                        clearScreen();
                    }
                    if (option2 == 14)
                    {
                        hms();
                        header();
                        doctorHeader();
                        cout << "View Bill Payments" << endl;
                        cout << "------------------" << endl;
                        cout << endl;
                        if (paymentCount >= 1)
                        {
                            viewPayments();
                        }
                        else
                        {
                            cout << endl;
                            cout << "No payments yet.";
                        }
                        clearScreen();
                    }
                    hms();
                    header();
                    doctorHeader();
                    option2 = doctorMenu();
                    clearScreen();
                }
            }
            else
            {
                cout << endl;
                cout << "Wrong Username or Password.";
                cout << endl;
                clearScreen();
            }
        }
        if (option == 3)
        {
            hms();
            header();
            patientHeader();
            int option3 = patientMenu();
            clearScreen();
            while (option3 < 8)
            {
                if (option3 == 1)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << "View Appointments" << endl;
                    cout << "-----------------" << endl;
                    cout << endl;
                    if (appointmentCount >= 1)
                    {
                        viewAppointments();
                    }
                    else
                    {
                        cout << endl;
                        cout << "No Appointments scheduled.";
                    }
                    clearScreen();
                }
                if (option3 == 2)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << "View Prescriptions" << endl;
                    cout << "------------------" << endl;
                    cout << endl;
                    if (prescriptionCount >= 1)
                    {
                        viewPrescriptions();
                    }
                    else
                    {
                        cout << endl;
                        cout << "No Prescriptions to show.";
                    }
                    clearScreen();
                }
                if (option3 == 3)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << "View Reports" << endl;
                    cout << "------------" << endl;
                    cout << endl;
                    if (reportsCount >= 1)
                    {
                        viewReports();
                    }
                    else
                    {
                        cout << endl;
                        cout << "No reports yet.";
                    }
                    clearScreen();
                }
                if (option3 == 4)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << "View Lab results" << endl;
                    cout << "----------------" << endl;
                    cout << endl;
                    if (patientCount >= 1)
                    {
                        viewLabResults();
                    }
                    else
                    {
                        cout << endl;
                        cout << "No records yet.";
                    }
                    clearScreen();
                }
                if (option3 == 5)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << "View Doctor Fees" << endl;
                    cout << "----------------" << endl;
                    cout << endl;
                    viewDoctorFees();
                    clearScreen();
                }
                if (option3 == 6)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << "View Bill Payment" << endl;
                    cout << "-----------------" << endl;
                    cout << endl;
                    if (patientCount >= 1)
                    {
                        billPayments();
                        store6();
                    }
                    else
                    {
                        cout << "No records yet.";
                    }
                    clearScreen();
                }
                if (option3 == 7)
                {
                    hms();
                    header();
                    patientHeader();
                    cout << "Add review" << endl;
                    cout << "-----------" << endl;
                    cout << endl;
                    if (patientCount >= 1)
                    {
                        giveReviews();
                        store7();
                    }
                    else
                    {
                        cout << "No records yet.";
                    }
                    clearScreen();
                }
                hms();
                header();
                patientHeader();
                option3 = patientMenu();
                clearScreen();
            }
        }
        if (option == 4)
        {
            hms();
            header();
            manual();
            clearScreen();
        }
        hms();
        header();
        option = menu();
        clearScreen();
        SetConsoleTextAttribute(hConsole, 15);
    }
}
//----------------Functions Definition--------------------//
void clearScreen()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << "Press any key to continue_";
    SetConsoleTextAttribute(hConsole, 15);
    getch();
    system("cls");
}
void hms()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\t   HHHHH       HHHHH      MMMMM         MMMMM        SSSSSSSS       " << endl;
    cout << "\t   H:::H       H:::H      M::::M       M::::M       S::SSSSS::S     " << endl;
    cout << "\t   H:::H       H:::H      M:::::M     M:::::M      S::S     SSSS    " << endl;
    cout << "\t   H:::H-H-H-H-H:::H      M::::::M   M::::::M      S::S             " << endl;
    cout << "\t   H:::::::::::::::H      M:::M::::M::::M:::M       S::SSSSSSS      " << endl;
    cout << "\t   H:::H-H-H-H-H:::H      M:::M M:::::M M:::M         SSSSSS::S     " << endl;
    cout << "\t   H:::H       H:::H      M:::M  M:::M  M:::M               S::S    " << endl;
    cout << "\t   H:::H       H:::H      M:::M   M-M   M:::M      SSSS     S::S    " << endl;
    cout << "\t   H:::H       H:::H      M:::M    M    M:::M       S::SSSSS::S     " << endl;
    cout << "\t   HHHHH       HHHHH      MMMMM         MMMMM        SSSSSSSS       " << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
bool adminLogin()
{
    string password, userid;
    cout << "Enter User Id and Password: " << endl;
    cout << endl;
    cout << "\t\tUser Id:  ";
    cin >> userid;
    cout << "\t\tPassword:  ";
    cin >> password;
    if (userid == "ayesha" && password == "taehyung")
    {
        return true;
    }
    return false;
}
void header()
{
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 6);
    cout << "\t   ***************************************************" << endl;
    cout << "\t   *********  HOSPITAL  MANAGEMENT  SYSTEM  **********" << endl;
    cout << "\t   ***************************************************" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
int menu()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t\t---------------------" << endl;
    cout << "\t\t\t|     Main Menu     |" << endl;
    cout << "\t\t\t---------------------" << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << endl;
    cout << " -------------------------------" << endl;
    cout << " | Select one option from menu |" << endl;
    cout << " -------------------------------" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\t1. Admin" << endl;
    cout << "\t2. Doctor" << endl;
    cout << "\t3. Patient" << endl;
    cout << "\t4. Instruction Manual" << endl;
    cout << "\t5. Exit" << endl;
    cout << endl;
    cout << "Your option_";
    int option;
    cin >> option;
    return option;
}
void adminHeader()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t\t   -------------------" << endl;
    cout << "\t\t\t   |    ADMIN MENU   |" << endl;
    cout << "\t\t\t   -------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
}
int adminMenu()
{
    int op;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << " -------------------------------" << endl;
    cout << " | Select one option from menu |" << endl;
    cout << " -------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << "\t 1. Add record" << endl;
    cout << "\t 2. View records (sorted according to salaries)" << endl;
    cout << "\t 3. Update record" << endl;
    cout << "\t 4. Delete record" << endl;
    cout << "\t 5. View Patients" << endl;
    cout << "\t 6. View Appointments" << endl;
    cout << "\t 7. Update Salaries" << endl;
    cout << "\t 8. View Checkup Fees" << endl;
    cout << "\t 9. View Bill Payments" << endl;
    cout << "\t10. View Reviews by patients" << endl;
    cout << "\t11. Edit Instruction Manual" << endl;
    cout << "\t12. Exit" << endl;
    cout << endl;
    cout << "Your option_";
    cin >> op;
    return op;
}
void addDoctor()
{
    cout << "Doctor ID:  ";
    cin >> doctorId[doctorCount];
    cout << "Doctor Password:  ";
    cin >> doctorPassword[doctorCount];
    cout << "Name of Doctor:  ";
    cin.ignore();
    getline(cin, doctorNames[doctorCount]);
    while (true)
    {
        cout << "Doctor Age:  ";
        cin >> num;
        if (validityChecker())
        {
            doctorAges[doctorCount] = stoi(num);
            break;
        }
        else
        {
            cout << "  Age not valid.";
            cout << endl;
        }
    }
    cout << "Address:  ";
    cin.ignore();
    getline(cin, doctorAddress[doctorCount]);
    while (true)
    {
        cout << "Contact Number (without spaces):  ";
        cin >> num;
        if (contactValidation())
        {
            doctorContact[doctorCount] = num;
            break;
        }
        else
        {
            cout << " Invalid Contact Numbers (11 digits).";
            cout << endl;
        }
    }
    cout << "Qualification:  ";
    cin.ignore();
    getline(cin, doctorQualification[doctorCount]);
    while (true)
    {
        cout << "Salary:  ";
        cin >> num;
        if (validityChecker())
        {
            doctorSalary[doctorCount] = stoi(num);
            break;
        }
        else
        {
            cout << "  Input not valid.";
            cout << endl;
        }
    }
    cout << endl;
    doctorCount++;
}
void sortDoctors()
{
    for (int i = 0; i < doctorCount; i++)
    {
        int j;
        int temp_salary, temp_age;
        string temp_name, temp_address, temp_qualification, temp_contact, temp_id, temp_password;
        int max_salary = -1;
        int idx = 0;
        for (j = i; j < doctorCount; j++)
        {
            if (doctorSalary[j] > max_salary)
            {
                max_salary = doctorSalary[j];
                idx = j;
            }
        }
        temp_salary = doctorSalary[i];
        temp_name = doctorNames[i];
        temp_age = doctorAges[i];
        temp_qualification = doctorQualification[i];
        temp_address = doctorAddress[i];
        temp_contact = doctorContact[i];
        temp_id = doctorId[i];
        temp_password = doctorPassword[i];
        doctorSalary[i] = doctorSalary[idx];
        doctorNames[i] = doctorNames[idx];
        doctorAges[i] = doctorAges[idx];
        doctorQualification[i] = doctorQualification[idx];
        doctorContact[i] = doctorContact[idx];
        doctorAddress[i] = doctorAddress[idx];
        doctorId[i] = doctorId[idx];
        doctorPassword[i] = doctorPassword[idx];
        doctorSalary[idx] = temp_salary;
        doctorNames[idx] = temp_name;
        doctorAges[idx] = temp_age;
        doctorQualification[idx] = temp_qualification;
        doctorContact[idx] = temp_contact;
        doctorAddress[idx] = temp_address;
        doctorId[idx] = temp_id;
        doctorPassword[idx] = temp_password;
    }
}
void viewDoctors()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "   DoctorId\t\tPassword\tName\t\tAge\t\tSalary\t\tQualification\t\tAddress\t\tContact No " << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    for (int i = 0; i <= doctorCount; i++)
    {
        if (doctorSalary[i] == 0)
        {
            continue;
        }
        else
        {
            cout << (i + 1) << ". " << doctorId[i] << "\t\t\t" << doctorPassword[i] << "\t\t" << doctorNames[i] << "\t\t" << doctorAges[i] << "\t\t" << doctorSalary[i] << "\t\t" << doctorQualification[i] << "\t\t" << doctorAddress[i] << "\t\t" << doctorContact[i] << endl;
        }
    }
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
}
void updateDoctors()
{
    viewDoctors();
    cout << endl;
    int uprecord;
    string choice;
    cout << "Select record you want to update_";
    cin >> uprecord;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "   DoctorId \t\t  Password  \t\tName\t\tAge\t\tSalary\t\tQualification\t\tAddress\t\tContact No" << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << "   " << doctorId[uprecord - 1] << "\t\t" << doctorPassword[uprecord - 1] << "\t\t\t" << doctorNames[uprecord - 1] << "\t\t" << doctorAges[uprecord - 1] << "\t\t" << doctorSalary[uprecord - 1] << "\t\t" << doctorQualification[uprecord - 1] << "\t\t\t" << doctorAddress[uprecord - 1] << "\t\t" << doctorContact[uprecord - 1] << endl;
    cout << endl;
    cout << "Select field you want to update ( Salary , Address , Contact )_";
    cin >> choice;
    if (choice == "Salary" || choice == "salary")
    {
        while (true)
        {
            cout << "Previous Salary: " << doctorSalary[uprecord - 1] << endl;
            cout << "Enter New Salary: ";
            cin >> num;
            if (validityChecker())
            {
                doctorSalary[uprecord - 1] = stoi(num);
                break;
            }
            else
            {
                cout << "  Input not valid.";
                cout << endl;
            }
        }
    }
    else if (choice == "Address" || choice == "address")
    {
        cout << "Previous Address: " << doctorAddress[uprecord - 1] << endl;
        cout << "Enter New Address: ";
        cin >> doctorAddress[uprecord - 1];
    }
    else if (choice == "Contact" || choice == "contact")
    {
        while (true)
        {
            cout << "Previous Contact: " << doctorContact[uprecord - 1] << endl;
            cout << "Enter New Contact Number: ";
            cin >> num;
            if (contactValidation())
            {
                doctorContact[uprecord - 1] = num;
                break;
            }
            else
            {
                cout << " Invalid Contact Numbers (11 digits).";
                cout << endl;
            }
        }
    }
    else
    {
        cout << " Wrong input." << endl;
    }
}
void deleteDoctors()
{
    viewDoctors();
    cout << endl;
    int delrecord;
    cout << "Select record you want to delete_";
    cin >> delrecord;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "   DoctorId \t\t  Password  \t\tName\t\tAge\t\tSalary\t\tQualification\t\tAddress\t\tContact No" << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << "   " << doctorId[delrecord - 1] << "\t\t" << doctorPassword[delrecord - 1] << "\t\t\t" << doctorNames[delrecord - 1] << "\t\t" << doctorAges[delrecord - 1] << "\t\t" << doctorSalary[delrecord - 1] << "\t\t" << doctorQualification[delrecord - 1] << "\t\t\t" << doctorAddress[delrecord - 1] << "\t\t" << doctorContact[delrecord - 1] << endl;
    cout << endl;
    doctorPassword[delrecord - 1] = "";
    doctorId[delrecord - 1] = "";
    doctorNames[delrecord - 1] = "";
    doctorSalary[delrecord - 1] = 0;
    doctorAddress[delrecord - 1] = "";
    doctorAges[delrecord - 1] = 0;
    doctorQualification[delrecord - 1] = "";
    doctorContact[delrecord - 1] = "";
    cout << endl;
    cout << "Record deleted successfully.";
    cout << endl;
}
void updateSalaries()
{
    int count = 0;
    viewDoctors();
    cout << endl;
    string upSalaryId;
    cout << "Enter Doctor Id: ";
    cin >> upSalaryId;
    for (int i = 0; i < doctorCount; i++)
    {
        if (upSalaryId == doctorId[i])
        {
            while (true)
            {
                cout << "Previous Salary: " << doctorSalary[i] << endl;
                cout << "Enter New Salary: ";
                cin >> num;
                if (validityChecker())
                {
                    doctorSalary[i] = stoi(num);
                    count++;
                    break;
                }
                else
                {
                    cout << "  Input not valid.";
                    cout << endl;
                }
            }
        }
    }
    if (count == 0)
    {
        cout << endl;
        cout << "  No such Id.";
        cout << endl;
    }
}
void viewPayments()
{
    SetConsoleTextAttribute(hConsole, 2);
    cout << "====================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  Patient Id"
         << "\t   "
         << "Payments" << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "====================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    for (int i = 0; i < paymentCount; i++)
    {
        cout << "  " << paymentId[i] << "\t   " << payments[i] << endl;
    }
    SetConsoleTextAttribute(hConsole, 2);
    cout << "====================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
}
void viewReview()
{
    cout << endl;
    for (int i = 0; i < reviewCount; i++)
    {
        cout << i + 1 << "  " << reviews[i] << endl;
        cout << endl;
    }
    cout << endl;
}
void doctorHeader()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t\t   ---------------------" << endl;
    cout << "\t\t\t   |    DOCTOR MENU    |" << endl;
    cout << "\t\t\t   ---------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
}
int doctorMenu()
{
    int x;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << " -------------------------------" << endl;
    cout << " | Select one option from menu |" << endl;
    cout << " -------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << "\t 1. Add Patient " << endl;
    cout << "\t 2. View records (sorted according to age) " << endl;
    cout << "\t 3. Update records  " << endl;
    cout << "\t 4. Delete records " << endl;
    cout << "\t 5. Advise Prescription " << endl;
    cout << "\t 6. Make Appointments" << endl;
    cout << "\t 7. View Appointments " << endl;
    cout << "\t 8. Update Appointments " << endl;
    cout << "\t 9. Cancel Appointments " << endl;
    cout << "\t10. Generate Reports " << endl;
    cout << "\t11. Check Lab Test Results " << endl;
    cout << "\t12. Edit Checkup Fees " << endl;
    cout << "\t13. View Reviews by Patients." << endl;
    cout << "\t14. View Bill Payments" << endl;
    cout << "\t15. Exit " << endl;
    cout << endl;
    cout << "Your option_";
    cin >> x;
    return x;
}
bool doctorLogin()
{
    bool check = false;
    string id, password;
    cout << " Enter your Id:  ";
    cin >> id;
    cout << " Enter password:  ";
    cin >> password;
    for (int i = 0; i < doctorCount; i++)
    {
        if (id == doctorId[i] && password == doctorPassword[i])
        {
            check = true;
            break;
        }
    }
    return check;
}
void addPatient()
{
    cout << "Patient id: ";
    cin >> patientId[patientCount];
    cout << "Patient Name: ";
    cin.ignore();
    getline(cin, patientName[patientCount]);
    while (true)
    {
        cout << "Patient Age:  ";
        cin >> num;
        if (validityChecker())
        {
            patientAge[patientCount] = stoi(num);
            break;
        }
        else
        {
            cout << "  Age not valid.";
            cout << endl;
        }
    }
    cout << "Patient Disease: ";
    cin.ignore();
    getline(cin, patientDisease[patientCount]);
    cout << "Patient Medicine: ";
    cin.ignore();
    getline(cin, patientMedicine[patientCount]);
    cout << "Patient Address: ";
    cin.ignore();
    getline(cin, patientAddress[patientCount]);
    while (true)
    {
        cout << "Contact Number (without spaces):  ";
        cin >> num;
        if (contactValidation())
        {
            patientContact[patientCount] = num;
            break;
        }
        else
        {
            cout << " Invalid Contact Numbers (11 digits).";
            cout << endl;
        }
    }
    cout << endl;
    patientCount++;
}
void sortPatients()
{
    for (int i = 0; i < patientCount; i++)
    {
        int j;
        int temp_age;
        string temp_id, temp_name, temp_address, temp_contact, temp_medicine, temp_disease;
        int age = 9999;
        int idx = 0;
        for (j = i; j < patientCount; j++)
        {
            if (patientAge[j] < age)
            {
                age = patientAge[j];
                idx = j;
            }
        }
        temp_age = patientAge[i];
        temp_id = patientId[i];
        temp_name = patientName[i];
        temp_contact = patientContact[i];
        temp_address = patientAddress[i];
        temp_medicine = patientMedicine[i];
        temp_disease = patientDisease[i];
        patientAge[i] = patientAge[idx];
        patientId[i] = patientId[idx];
        patientName[i] = patientName[idx];
        patientContact[i] = patientContact[idx];
        patientAddress[i] = patientAddress[idx];
        patientMedicine[i] = patientMedicine[idx];
        patientContact[i] = patientContact[idx];
        patientAge[idx] = temp_age;
        patientId[idx] = temp_id;
        patientName[idx] = temp_name;
        patientContact[idx] = temp_contact;
        patientAddress[idx] = temp_address;
        patientDisease[idx] = temp_disease;
        patientMedicine[idx] = temp_medicine;
    }
}
void viewPatients()
{

    cout << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "======================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  PatientId\t\tName\t\tAge\t\tDisease\t\tMedicine\t\tAddress\t\tContact No" << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "======================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    for (int i = 0; i <= patientCount; i++)
    {
        if (patientAge[i] == 0)
        {
            continue;
        }
        cout << i + 1 << ".  " << patientId[i] << "\t\t" << patientName[i] << "\t\t" << patientAge[i] << "\t\t" << patientDisease[i] << "\t\t" << patientMedicine[i] << "\t\t" << patientAddress[i] << "\t\t" << patientContact[i] << endl;
    }
    SetConsoleTextAttribute(hConsole, 2);
    cout << "======================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void updatePatients()
{
    viewPatients();
    cout << endl;
    int uprecord;
    string choice;
    cout << "Select record you want to update_";
    cin >> uprecord;
    cout << endl;
    cout << "======================================================================================================================================" << endl;
    cout << "  PatientId\t\tName\t\tAge\t\tDisease\t\tMedicine\t\tContact No\t\tAddress" << endl;
    cout << "======================================================================================================================================" << endl;
    cout << endl;
    cout << "    " << patientId[uprecord - 1] << "\t\t" << patientName[uprecord - 1] << "\t\t" << patientAge[uprecord - 1] << "\t\t" << patientDisease[uprecord - 1] << "\t\t" << patientMedicine[uprecord - 1] << "\t\t   " << patientContact[uprecord - 1] << "\t\t  " << patientAddress[uprecord - 1] << endl;
    cout << endl;
    cout << "Select field you want to update (Medicine , Contact)_";
    cin >> choice;
    if (choice == "Medicine" || choice == "medicine")
    {
        cout << "Previous Medicine: " << patientMedicine[uprecord - 1] << endl;
        cout << "Enter New Medicine: ";
        cin >> patientMedicine[uprecord - 1];
    }
    else if (choice == "Contact" || choice == "contact")
    {
        while (true)
        {
            cout << "Previous Contact: " << patientContact[uprecord - 1] << endl;
            cout << "Contact Number (without spaces):  ";
            cin >> num;
            if (contactValidation())
            {
                patientContact[uprecord - 1] = num;
                break;
            }
            else
            {
                cout << " Invalid Contact Numbers (11 digits).";
                cout << endl;
            }
        }
    }
    else
    {
        cout << " Wrong input." << endl;
    }
}
void deletePatients()
{
    viewPatients();
    cout << endl;
    int delrecord;
    cout << "Select record you want to delete_";
    cin >> delrecord;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "======================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  PatientId\t\tName\t\tAge\t\tDisease\t\tMedicine\t\tContact No\t\tAddress" << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "======================================================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << "\t" << patientId[delrecord - 1] << "\t\t" << patientName[delrecord - 1] << "\t\t" << patientAge[delrecord - 1] << "\t\t" << patientDisease[delrecord - 1] << "\t\t" << patientMedicine[delrecord - 1] << "\t\t   " << patientContact[delrecord - 1] << "\t\t   " << patientAddress[delrecord - 1] << endl;
    cout << endl;
    patientId[delrecord - 1] = "";
    patientName[delrecord - 1] = "";
    patientAge[delrecord - 1] = 0;
    patientDisease[delrecord - 1] = "";
    patientMedicine[delrecord - 1] = "";
    patientContact[delrecord - 1] = "";
    patientAddress[delrecord - 1] = "";
    cout << endl;
    cout << "Record deleted successfully.";
    cout << endl;
}
void prescription()
{
    int count = 0;
    viewPatients();
    cout << endl;
    cout << "To Patient ID: ";
    cin >> prescriptionId[prescriptionCount];
    for (int i = 0; i < patientCount; i++)
    {
        if (prescriptionId[prescriptionCount] == patientId[i])
        {
            cout << patientName[i] << endl;
            cout << patientAge[i] << endl;
            cout << patientDisease[i] << endl;
            cout << patientMedicine[i] << endl;
            cout << patientContact[i] << endl;
            cout << "\nAdd Prescription: ";
            cin.ignore();
            getline(cin, addPrescription[prescriptionCount]);
            prescriptionCount++;
            count++;
            break;
        }
    }
    if (count == 0)
    {
        cout << endl;
        cout << "  No such Id.";
        cout << endl;
    }
}
void makeAppointments()
{
    int count = 0;
    viewPatients();
    cout << endl;
    cout << "With Patient ID: ";
    cin >> appointmentId[appointmentCount];
    for (int i = 0; i < patientCount; i++)
    {
        if (appointmentId[appointmentCount] == patientId[i])
        {
            cout << patientName[i] << endl;
            cout << patientAge[i] << endl;
            cout << patientDisease[i] << endl;
            cout << patientMedicine[i] << endl;
            cout << patientContact[i] << endl;
            cout << patientAddress[i] << endl;
            cout << "\nDay: ";
            cin >> appointmentDay[appointmentCount];
            cout << "Timing: ";
            cin >> appointmentTime[appointmentCount];
            appointmentCount++;
            count++;
            break;
        }
    }
    if (count == 0)
    {
        cout << endl;
        cout << "  No such Id.";
        cout << endl;
    }
}
void viewAppointments()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  PatientId\t\tName\t\tAppointment Day\t\tAppointment Time" << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    for (int i = 0; i < appointmentCount; i++)
    {
        if (appointmentId[i] == "")
        {
            continue;
        }
        for (int j = i; j < patientCount; j++)
        {
            if (appointmentId[i] == patientId[j])
            {
                cout << (i + 1) << ". " << patientId[j] << "\t\t" << patientName[j] << "\t\t    " << appointmentDay[i] << "\t\t\t" << appointmentTime[i] << endl;
                break;
            }
        }
    }
}
void updateAppointments()
{
    viewAppointments();
    int upAppoint;
    cout << "Select appointment you want to change_";
    cin >> upAppoint;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  PatientId\t\tName\t\tAppointment Day\t\tAppointment Time" << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << patientId[upAppoint - 1] << "\t\t" << patientName[upAppoint - 1] << "\t\t    " << appointmentDay[upAppoint - 1] << "\t\t\t" << appointmentTime[upAppoint - 1] << endl;
    cout << endl;
    string upfield;
    cout << "Select field you want to change (Day, Time)_";
    cin >> upfield;
    if (upfield == "Day" || upfield == "day")
    {
        cout << "Old Appointment day: " << appointmentDay[upAppoint - 1];
        cout << "Enter New Appointment Day: ";
        cin >> appointmentDay[upAppoint - 1];
    }
    if (upfield == "Time" || upfield == "time")
    {
        cout << "Old Appointment Time: " << appointmentTime[upAppoint - 1];
        cout << "Enter New Appointment Time: ";
        cin >> appointmentTime[upAppoint - 1];
    }
}
void deleteAppointments()
{
    viewAppointments();
    int delAppoint;
    cout << "Select appointment you want to cancel_";
    cin >> delAppoint;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "  PatientId\t\tName\t\tAppointment Day\t\tAppointment Time" << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "=======================================================================================================" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << patientId[delAppoint - 1] << "\t\t" << patientName[delAppoint - 1] << "\t\t    " << appointmentDay[delAppoint - 1] << "\t\t\t" << appointmentTime[delAppoint - 1] << endl;
    cout << endl;
    appointmentId[delAppoint - 1] = "";
    appointmentDay[delAppoint - 1] = "";
    appointmentTime[delAppoint - 1] = "";
    cout << "Appointment deleted successfully.";
    cout << endl;
}
void generateReports()
{
    int count = 0;
    cout << "Generate Reports of Patients ID: ";
    cin >> reportsId[reportsCount];
    for (int i = 0; i <= patientCount; i++)
    {
        if (patientId[i] == reportsId[reportsCount])
        {
            cout << patientName[i] << endl;
            cout << patientAge[i] << endl;
            cout << patientDisease[i] << endl;
            cout << patientMedicine[i] << endl;
            cout << endl;
            cout << "Test Taken: ";
            cin >> test[reportsCount];
            cout << "Result: ";
            cin >> result[reportsCount];
            reportsCount++;
            count++;
            break;
        }
    }
    if (count == 0)
    {
        cout << endl;
        cout << "  No such Id.";
        cout << endl;
    }
}
void editFees()
{
    cout << "Previous Checkup Fees: " << checkupFees << endl;
    cout << endl;
    cout << "Add new Checkup Fees: ";
    cin >> checkupFees;
}
void patientHeader()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t\t        ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "\t\t\t        ~    PATIENT    ~" << endl;
    cout << "\t\t\t        ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
}
int patientMenu()
{
    int x;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << " -------------------------------" << endl;
    cout << " | Select one option from menu |" << endl;
    cout << " -------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << "\t 1. View Appointments" << endl;
    cout << "\t 2. View Prescriptions" << endl;
    cout << "\t 3. View Reports" << endl;
    cout << "\t 4. View Lab Test results" << endl;
    cout << "\t 5. View Doctor Fees" << endl;
    cout << "\t 6. Bill Payments" << endl;
    cout << "\t 7. Give Review" << endl;
    cout << "\t 8. Exit" << endl;
    cout << endl;
    cout << "Your option_";
    cin >> x;
    return x;
}
void viewPrescriptions()
{
    int count = 0;
    string ptPrescriptionId;
    cout << "Enter Patient Id: ";
    cin >> ptPrescriptionId;
    cout << endl;
    for (int i = 0; i < patientCount; i++)
    {
        if (ptPrescriptionId == patientId[i])
        {
            for (int j = 0; j < prescriptionCount; j++)
            {
                if (ptPrescriptionId == prescriptionId[j])
                {
                    cout << patientName[i] << endl;
                    cout << patientAge[i] << endl;
                    cout << patientDisease[i] << endl;
                    cout << patientMedicine[i] << endl;
                    cout << patientContact[i] << endl;
                    cout << addPrescription[j];
                    cout << endl;
                    count++;
                    break;
                }
            }
        }
    }
    if (count == 0)
    {
        cout << endl;
        cout << "  No such Id.";
        cout << endl;
    }
}
void viewReports()
{
    int count = 0;
    string ptReportId;
    cout << "Enter your Patient Id: ";
    cin >> ptReportId;
    for (int i = 0; i < patientCount; i++)
    {
        if (ptReportId == patientId[i])
        {
            for (int j = 0; j < reportsCount; j++)
            {
                if (reportsId[j] == ptReportId)
                {
                    cout << endl;
                    cout << patientName[i] << endl;
                    cout << patientAge[i] << endl;
                    cout << patientDisease[i] << endl;
                    cout << patientMedicine[i] << endl;
                    cout << test[j] << endl;
                    cout << result[j] << endl;
                    cout << endl;
                    count++;
                    break;
                }
            }
        }
    }
    if (count == 0)
    {
        cout << endl;
        cout << "  No such Id.";
        cout << endl;
    }
}
void viewLabResults()
{
    string id;
    cout << "Enter Patient ID: ";
    cin >> id;
    cout << endl;
    cout << "Test Taken: Covid-19" << endl;
    cout << "Red Blood Cells: 432" << endl;
    cout << "White Blood Cells: 223" << endl;
    cout << "Platlets (billion/L): 262 " << endl;
    cout << "RBC's (trillion/L): 3.84 " << endl;
    cout << "HB (g/dL): 11.7 " << endl;
    cout << "WBC's (billion/L): 8.00 " << endl;
    cout << "Lymphs: 68H" << endl;
    cout << "Hemoglobin: 10.8L" << endl;
    cout << "EOS: 0.7" << endl;
}
void viewDoctorFees()
{
    cout << "  Doctor Checkup Fees: " << checkupFees;
    cout << endl;
}
void billPayments()
{
    cout << "Enter Patient Id: ";
    cin >> paymentId[paymentCount];
    cout << "Doctor Checkup Fees: " << checkupFees << endl;
    cout << labTestFees;
    payments[paymentCount] = checkupFees + labTestFees;
    cout << "Payable Amount: " << payments[paymentCount];
    cout << endl;
    paymentCount++;
}
void giveReviews()
{
    cout << "Please give your Review: ";
    cin.ignore();
    getline(cin, reviews[reviewCount]);
    reviewCount++;
}
void manual()
{
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t ---------------------------" << endl;
    cout << "\t\t |   INSTRUCTION  MANUAL   |" << endl;
    cout << "\t\t ---------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << instructionManual[i] << endl;
        cout << endl;
    }
}
void editManual()
{
    int a = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t   ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "\t   ~     INSTRUCTION  MANUAL   ~" << endl;
    cout << "\t   ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << instructionManual[i] << endl;
        cout << endl;
    }
    int choose;
    cout << "Select field you want to edit (1,2,3,4,5,6,7): " << endl;
    cout << endl;
    cin >> choose;
    char stop11;
    if (choose == 1)
    {
        cout << "Previous: " << instructionManual[0] << endl;
        cout << "New: ";
        cin >> instructionManual[0];
        cout << endl;
    }
    else if (choose == 2)
    {
        cout << "Previous: " << instructionManual[1] << endl;
        cout << "New: ";
        cin >> instructionManual[1];
        cout << endl;
    }
    else if (choose == 3)
    {
        cout << "Previous: " << instructionManual[2] << endl;
        cout << "New: ";
        cin >> instructionManual[2];
        cout << endl;
    }
    else if (choose == 4)
    {
        cout << "Previous: " << instructionManual[3] << endl;
        cout << "New: ";
        cin >> instructionManual[3];
        cout << endl;
    }
    else if (choose == 5)
    {
        cout << "Previous: " << instructionManual[4] << endl;
        cout << "New: ";
        cin >> instructionManual[4];
        cout << endl;
    }
    else if (choose == 6)
    {
        cout << "Previous: " << instructionManual[5] << endl;
        cout << "New: ";
        cin >> instructionManual[5];
        cout << endl;
    }
    else if (choose == 7)
    {
        cout << "Previous: " << instructionManual[6] << endl;
        cout << "New: ";
        cin >> instructionManual[6];
        cout << endl;
    }
}
//----------------File Handling Functions------------------//

string parseRecord(int field, string line)
{
    int comma = 1;
    string item;
    for (int x = 0; line[x] != '\0'; x++)
    {
        if (line[x] == ',')
        {
            comma = comma + 1;
        }
        else if (comma == field)
        {
            item = item + line[x];
        }
    }
    return item;
}
void store1()
{
    fstream file;
    file.open("DoctorsInformation.txt", ios ::out);
    for (int i = 0; i < doctorCount; i++)
    {
        file << doctorId[i] << "," << doctorPassword[i] << "," << doctorNames[i] << "," << doctorAges[i] << "," << doctorAddress[i] << "," << doctorContact[i] << "," << doctorQualification[i] << "," << doctorSalary[i] << endl;
    }
    file.close();
}
void load1()
{
    string line1;
    fstream file;
    file.open("DoctorsInformation.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line1);
        if (line1 != "")
        {
            load_doctors(line1);
        }
    }
    file.close();
}
void load_doctors(string line1)
{
    doctorId[doctorCount] = parseRecord(1, line1);
    doctorPassword[doctorCount] = parseRecord(2, line1);
    doctorNames[doctorCount] = parseRecord(3, line1);
    doctorAges[doctorCount] = stoi(parseRecord(4, line1));
    doctorAddress[doctorCount] = parseRecord(5, line1);
    doctorContact[doctorCount] = parseRecord(6, line1);
    doctorQualification[doctorCount] = parseRecord(7, line1);
    doctorSalary[doctorCount] = stoi(parseRecord(8, line1));
    doctorCount++;
}
void store2()
{
    fstream file;
    file.open("PatientsInformation.txt", ios ::out);
    for (int i = 0; i < patientCount; i++)
    {
        file << patientId[i] << "," << patientName[i] << "," << patientAge[i] << "," << patientDisease[i] << "," << patientMedicine[i] << "," << patientAddress[i] << "," << patientContact[i] << endl;
    }
    file.close();
}
void load2()
{
    string line2;
    fstream file;
    file.open("PatientsInformation.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line2);
        if (line2 != "")
        {
            load_patients(line2);
        }
    }
    file.close();
}
void load_patients(string line2)
{
    patientId[patientCount] = parseRecord(1, line2);
    patientName[patientCount] = parseRecord(2, line2);
    patientAge[patientCount] = stoi(parseRecord(3, line2));
    patientDisease[patientCount] = parseRecord(4, line2);
    patientMedicine[patientCount] = parseRecord(5, line2);
    patientAddress[patientCount] = parseRecord(6, line2);
    patientContact[patientCount] = parseRecord(7, line2);
    patientCount++;
}
void store3()
{
    fstream file;
    file.open("Prescriptions.txt", ios ::out);
    for (int i = 0; i < prescriptionCount; i++)
    {
        file << prescriptionId[i] << "," << addPrescription[i] << endl;
    }
    file.close();
}
void load3()
{
    string line3;
    fstream file;
    file.open("Prescriptions.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line3);
        if (line3 != "")
        {
            load_prescriptions(line3);
        }
    }
    file.close();
}
void load_prescriptions(string line3)
{
    prescriptionId[prescriptionCount] = parseRecord(1, line3);
    addPrescription[prescriptionCount] = parseRecord(2, line3);
    prescriptionCount++;
}
void store4()
{
    fstream file;
    file.open("Appointments.txt", ios ::out);
    for (int i = 0; i < appointmentCount; i++)
    {
        file << appointmentId[i] << "," << appointmentDay[i] << "," << appointmentTime[i] << endl;
    }
    file.close();
}
void load4()
{
    string line4;
    fstream file;
    file.open("Appointments.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line4);
        if (line4 != "")
        {
            load_appointments(line4);
        }
    }
    file.close();
}
void load_appointments(string line4)
{
    appointmentId[appointmentCount] = parseRecord(1, line4);
    appointmentDay[appointmentCount] = parseRecord(2, line4);
    appointmentTime[appointmentCount] = parseRecord(3, line4);
    appointmentCount++;
}
void store5()
{
    fstream file;
    file.open("Reports.txt", ios ::out);
    for (int i = 0; i < reportsCount; i++)
    {
        file << reportsId[i] << "," << test[i] << "," << result[i] << endl;
    }
    file.close();
}
void load5()
{
    string line5;
    fstream file;
    file.open("Reports.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line5);
        if (line5 != "")
        {
            load_reports(line5);
        }
    }
    file.close();
}
void load_reports(string line5)
{
    reportsId[reportsCount] = parseRecord(1, line5);
    test[reportsCount] = parseRecord(2, line5);
    result[reportsCount] = parseRecord(3, line5);
    reportsCount++;
}
void store6()
{
    fstream file;
    file.open("Bill Payments.txt", ios ::out);
    for (int i = 0; i < paymentCount; i++)
    {
        file << paymentId[i] << "," << payments[i] << endl;
    }
    file.close();
}
void load6()
{
    string line6;
    fstream file;
    file.open("Bill Payments.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line6);
        if (line6 != "")
        {
            load_payments(line6);
        }
    }
    file.close();
}
void load_payments(string line6)
{
    paymentId[paymentCount] = parseRecord(1, line6);
    payments[paymentCount] = stoi(parseRecord(2, line6));
    paymentCount++;
}
void store7()
{
    fstream file;
    file.open("Reviews.txt", ios ::out);
    for (int i = 0; i < reviewCount; i++)
    {
        file << reviews[i] << endl;
    }
    file.close();
}
void load7()
{
    string line7;
    fstream file;
    file.open("Reviews.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line7);
        if (line7 != "")
        {
            reviews[reviewCount] = line7;
            reviewCount++;
        }
    }
    file.close();
}
void store8()
{
    fstream file;
    file.open("Manual.txt", ios ::out);
    for (int i = 0; i < 6; i++)
    {
        file << instructionManual[i] << endl;
    }
    file.close();
}
void load8()
{
    int i = 0;
    string line8;
    fstream file;
    file.open("Manual.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line8);
        if (line8 != "")
        {
            instructionManual[i] = line8;
            i++;
        }
    }
    file.close();
}
void store9()
{
    fstream file;
    file.open("DoctorFees.txt", ios ::out);
    file << checkupFees << endl;
    file << labTestFees << endl;
    file.close();
}
void load9()
{
    string line9;
    fstream file;
    file.open("DoctorFees.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line9);
        if (line9 != "")
        {
            checkupFees = stoi(line9);
            labTestFees = stoi(line9);
        }
    }
    file.close();
}
//-------------Validity Checker----------------//
bool validityChecker()
{
    int count1 = 0, count2 = 0;
    for (int i = 0; num[i] != '\0'; i++)
    {
        count1++;
    }
    for (int j = 0; num[j] != '\0'; j++)
    {
        if (num[j] >= '0' && num[j] <= '9')
        {
            count2++;
        }
    }
    if (count1 == count2)
    {
        return true;
    }
    return false;
}
bool contactValidation()
{
    int count1 = 0, count2 = 0;
    for (int i = 0; num[i] != '\0'; i++)
    {
        count1++;
    }
    for (int j = 0; num[j] != '\0'; j++)
    {
        if (num[j] >= '0' && num[j] <= '9')
        {
            count2++;
        }
    }
    if ((count1 == 11) && (count1 == count2))
    {
        return true;
    }
    return false;
}