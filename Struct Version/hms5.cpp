//-----------------Header Files-------------------//
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>
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
void prescribeMedicine();
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
//---------------Recommendation----------------//
void markAttendance();
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
//void store10();
//void load10();
//void array();
//char parse(int field);
    //---------------Validity Checker---------------//
    bool validityChecker();
bool contactValidation();
bool nameValidation();
bool doctorIdValidation();
bool patientIdValidation();
string prescriptionIdValidation();
string appointmentIdValidation();
//--------------Data Structures ( Arrays , Variables )-------------//
const int MAX_RECORDS = 100;
int doctorCount = 0;
int patientCount = 0;
int prescriptionCount = 0;
int appointmentCount = 0;
int reportsCount = 0;
int checkupFees = 0;
int labTestFees = 0;
int paymentCount = 0;
int reviewCount = 0;

struct doctor
{
    string doctorId;
    string doctorPassword;
    string doctorNames;
    int doctorAges;
    string doctorAddress;
    string doctorQualification;
    int doctorSalary;
    string doctorContact;
};
doctor total_doctor[MAX_RECORDS];

struct patient
{
    string patientId;
    string patientName;
    int patientAge;
    string patientDisease;
    string patientMedicine;
    string patientAddress;
    string patientContact;
};
patient total_patient[MAX_RECORDS];

struct prescription
{
    string prescriptionId;
    string addPrescription;
};
prescription total_prescription[MAX_RECORDS];

struct appointment
{
    string appointmentId;
    string appointmentDay;
    string appointmentTime;
};
appointment total_appointment[MAX_RECORDS];

struct report
{
    string reportsId;
    string test;
    string result;
};
report total_report[MAX_RECORDS];

struct payBill
{
    string paymentId;
    int payments;
};
payBill total_payBill[MAX_RECORDS];

string reviews[MAX_RECORDS];

string instructionManual[7];
//--------------Validity Checker------------//
string num;
string name;
string line;
string IdCheck1;
string IdCheck2;
string prescriptionIdCheck;
string appointmentIdCheck;
//-------------Recommendations------------//
char attendance[10][31] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

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
    //load10();
    system("cls");
    hms();
    header();
    //markAttendance();
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
                        store9();
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
                            prescribeMedicine();
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
    while (true)
    {
        cout << "Doctor ID:  ";
        cin >> IdCheck1;
        if (doctorIdValidation())
        {
            total_doctor[doctorCount].doctorId = IdCheck1;
            break;
        }
        else
        {
            cout << "  " << IdCheck1 << "  Already exist." << endl;
        }
    }
    cout << "Doctor Password:  ";
    cin >> total_doctor[doctorCount].doctorPassword;
    while (true)
    {
        cout << "Name of Doctor:  ";
        cin.ignore();
        getline(cin, name);
        if (nameValidation())
        {
            total_doctor[doctorCount].doctorNames = name;
            break;
        }
        else
        {
            cout << "  Name not valid.";
            cout << endl;
        }
    }
    while (true)
    {
        cout << "Doctor Age:  ";
        cin >> num;
        if (validityChecker())
        {
            total_doctor[doctorCount].doctorAges = stoi(num);
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
    getline(cin, total_doctor[doctorCount].doctorAddress);
    while (true)
    {
        cout << "Contact Number (without spaces):  ";
        cin >> num;
        if (contactValidation())
        {
            total_doctor[doctorCount].doctorContact = num;
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
    getline(cin, total_doctor[doctorCount].doctorQualification);
    while (true)
    {
        cout << "Salary:  ";
        cin >> num;
        if (validityChecker())
        {
            total_doctor[doctorCount].doctorSalary = stoi(num);
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
            if (total_doctor[j].doctorSalary > max_salary)
            {
                max_salary = total_doctor[j].doctorSalary;
                idx = j;
            }
        }
        temp_salary = total_doctor[i].doctorSalary;
        temp_name = total_doctor[i].doctorNames;
        temp_age = total_doctor[i].doctorAges;
        temp_qualification = total_doctor[i].doctorQualification;
        temp_address = total_doctor[i].doctorAddress;
        temp_contact = total_doctor[i].doctorContact;
        temp_id = total_doctor[i].doctorId;
        temp_password = total_doctor[i].doctorPassword;
        total_doctor[i].doctorSalary = total_doctor[idx].doctorSalary;
        total_doctor[i].doctorNames = total_doctor[idx].doctorNames;
        total_doctor[i].doctorAges = total_doctor[idx].doctorAges;
        total_doctor[i].doctorQualification = total_doctor[idx].doctorQualification;
        total_doctor[i].doctorContact = total_doctor[idx].doctorContact;
        total_doctor[i].doctorAddress = total_doctor[idx].doctorAddress;
        total_doctor[i].doctorId = total_doctor[idx].doctorId;
        total_doctor[i].doctorPassword = total_doctor[idx].doctorPassword;
        total_doctor[idx].doctorSalary = temp_salary;
        total_doctor[idx].doctorNames = temp_name;
        total_doctor[idx].doctorAges = temp_age;
        total_doctor[idx].doctorQualification = temp_qualification;
        total_doctor[idx].doctorContact = temp_contact;
        total_doctor[idx].doctorAddress = temp_address;
        total_doctor[idx].doctorId = temp_id;
        total_doctor[idx].doctorPassword = temp_password;
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
        if (total_doctor[i].doctorSalary == 0)
        {
            continue;
        }
        else
        {
            cout << (i + 1) << ". " << total_doctor[i].doctorId << "\t\t\t" << total_doctor[i].doctorPassword << "\t\t" << total_doctor[i].doctorNames << "\t\t" << total_doctor[i].doctorAges << "\t\t" << total_doctor[i].doctorSalary << "\t\t" << total_doctor[i].doctorQualification << "\t\t" << total_doctor[i].doctorAddress << "\t\t" << total_doctor[i].doctorContact << endl;
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
    cout << "   " << setw(10) << total_doctor[uprecord - 1].doctorId << "\t\t" << setw(10) << total_doctor[uprecord - 1].doctorPassword << "\t\t\t" << setw(10) << total_doctor[uprecord - 1].doctorNames << "\t\t" << setw(10) << total_doctor[uprecord - 1].doctorAges << "\t\t" << setw(10) << total_doctor[uprecord - 1].doctorSalary << "\t\t" << setw(10) << total_doctor[uprecord - 1].doctorQualification << "\t\t\t" << setw(20) << total_doctor[uprecord - 1].doctorAddress << "\t\t" << setw(20) << total_doctor[uprecord - 1].doctorContact << endl;
    cout << endl;
    cout << "Select field you want to update ( Salary , Address , Contact )_";
    cin >> choice;
    if (choice == "Salary" || choice == "salary")
    {
        while (true)
        {
            cout << "Previous Salary: " << total_doctor[uprecord - 1].doctorSalary << endl;
            cout << "Enter New Salary: ";
            cin >> num;
            if (validityChecker())
            {
                total_doctor[uprecord - 1].doctorSalary = stoi(num);
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
        cout << "Previous Address: " << total_doctor[uprecord - 1].doctorAddress << endl;
        cout << "Enter New Address: ";
        cin >> total_doctor[uprecord - 1].doctorAddress;
    }
    else if (choice == "Contact" || choice == "contact")
    {
        while (true)
        {
            cout << "Previous Contact: " << total_doctor[uprecord - 1].doctorContact << endl;
            cout << "Enter New Contact Number: ";
            cin >> num;
            if (contactValidation())
            {
                total_doctor[uprecord - 1].doctorContact = num;
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
    cout << "   " << total_doctor[delrecord - 1].doctorId << "\t\t" << total_doctor[delrecord - 1].doctorPassword << "\t\t\t" << total_doctor[delrecord - 1].doctorNames << "\t\t" << total_doctor[delrecord - 1].doctorAges << "\t\t" << total_doctor[delrecord - 1].doctorSalary << "\t\t" << total_doctor[delrecord - 1].doctorQualification << "\t\t\t" << total_doctor[delrecord - 1].doctorAddress << "\t\t" << total_doctor[delrecord - 1].doctorContact << endl;
    cout << endl;
    total_doctor[delrecord - 1].doctorPassword = "";
    total_doctor[delrecord - 1].doctorId = "";
    total_doctor[delrecord - 1].doctorNames = "";
    total_doctor[delrecord - 1].doctorSalary = 0;
    total_doctor[delrecord - 1].doctorAddress = "";
    total_doctor[delrecord - 1].doctorAges = 0;
    total_doctor[delrecord - 1].doctorQualification = "";
    total_doctor[delrecord - 1].doctorContact = "";
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
        if (upSalaryId == total_doctor[i].doctorId)
        {
            while (true)
            {
                cout << "Previous Salary: " << total_doctor[i].doctorSalary << endl;
                cout << "Enter New Salary: ";
                cin >> num;
                if (validityChecker())
                {
                    total_doctor[i].doctorSalary = stoi(num);
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
        cout << "  " << total_payBill[i].paymentId << "\t   " << total_payBill[i].payments << endl;
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
        if (id == total_doctor[i].doctorId && password == total_doctor[i].doctorPassword)
        {
            check = true;
            break;
        }
    }
    return check;
}
void addPatient()
{
    while (true)
    {
        cout << "Patient id: ";
        cin >> IdCheck2;
        if (patientIdValidation())
        {
            total_patient[patientCount].patientId = IdCheck2;
            break;
        }
        else
        {
            cout << "  " << IdCheck2 << "  Already exist." << endl;
        }
    }
    while (true)
    {
        cout << "Patient Name: ";
        cin.ignore();
        getline(cin, name);
        if (nameValidation())
        {
            total_patient[patientCount].patientName = name;
            break;
        }
        else
        {
            cout << "  Name not valid.";
            cout << endl;
        }
    }
    while (true)
    {
        cout << "Patient Age:  ";
        cin >> num;
        if (validityChecker())
        {
            total_patient[patientCount].patientAge = stoi(num);
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
    getline(cin, total_patient[patientCount].patientDisease);
    cout << "Patient Medicine: ";
    cin.ignore();
    getline(cin, total_patient[patientCount].patientMedicine);
    cout << "Patient Address: ";
    cin.ignore();
    getline(cin, total_patient[patientCount].patientAddress);
    while (true)
    {
        cout << "Contact Number (without spaces):  ";
        cin >> num;
        if (contactValidation())
        {
            total_patient[patientCount].patientContact = num;
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
            if (total_patient[j].patientAge < age)
            {
                age = total_patient[j].patientAge;
                idx = j;
            }
        }
        temp_age = total_patient[i].patientAge;
        temp_id = total_patient[i].patientId;
        temp_name = total_patient[i].patientName;
        temp_contact = total_patient[i].patientContact;
        temp_address = total_patient[i].patientAddress;
        temp_medicine = total_patient[i].patientMedicine;
        temp_disease = total_patient[i].patientDisease;
        total_patient[i].patientAge = total_patient[idx].patientAge;
        total_patient[i].patientId = total_patient[idx].patientId;
        total_patient[i].patientName = total_patient[idx].patientName;
        total_patient[i].patientContact = total_patient[idx].patientContact;
        total_patient[i].patientAddress = total_patient[idx].patientAddress;
        total_patient[i].patientMedicine = total_patient[idx].patientMedicine;
        total_patient[i].patientContact = total_patient[idx].patientContact;
        total_patient[idx].patientAge = temp_age;
        total_patient[idx].patientId = temp_id;
        total_patient[idx].patientName = temp_name;
        total_patient[idx].patientContact = temp_contact;
        total_patient[idx].patientAddress = temp_address;
        total_patient[idx].patientDisease = temp_disease;
        total_patient[idx].patientMedicine = temp_medicine;
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
        if (total_patient[i].patientAge == 0)
        {
            continue;
        }
        cout << i + 1 << ".  " << total_patient[i].patientId << "\t\t" << total_patient[i].patientName << "\t\t" << total_patient[i].patientAge << "\t\t" << total_patient[i].patientDisease << "\t\t" << total_patient[i].patientMedicine << "\t\t" << total_patient[i].patientAddress << "\t\t" << total_patient[i].patientContact << endl;
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
    cout << "    " << total_patient[uprecord - 1].patientId << "\t\t" << total_patient[uprecord - 1].patientName << "\t\t" << total_patient[uprecord - 1].patientAge << "\t\t" << total_patient[uprecord - 1].patientDisease << "\t\t" << total_patient[uprecord - 1].patientMedicine << "\t\t   " << total_patient[uprecord - 1].patientContact << "\t\t  " << total_patient[uprecord - 1].patientAddress << endl;
    cout << endl;
    cout << "Select field you want to update (Medicine , Contact)_";
    cin >> choice;
    if (choice == "Medicine" || choice == "medicine")
    {
        cout << "Previous Medicine: " << total_patient[uprecord - 1].patientMedicine << endl;
        cout << "Enter New Medicine: ";
        cin >> total_patient[uprecord - 1].patientMedicine;
    }
    else if (choice == "Contact" || choice == "contact")
    {
        while (true)
        {
            cout << "Previous Contact: " << total_patient[uprecord - 1].patientContact << endl;
            cout << "Contact Number (without spaces):  ";
            cin >> num;
            if (contactValidation())
            {
                total_patient[uprecord - 1].patientContact = num;
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
    cout << "\t" << total_patient[delrecord - 1].patientId << "\t\t" << total_patient[delrecord - 1].patientName << "\t\t" << total_patient[delrecord - 1].patientAge << "\t\t" << total_patient[delrecord - 1].patientDisease << "\t\t" << total_patient[delrecord - 1].patientMedicine << "\t\t   " << total_patient[delrecord - 1].patientContact << "\t\t   " << total_patient[delrecord - 1].patientAddress << endl;
    cout << endl;
    total_patient[delrecord - 1].patientId = "";
    total_patient[delrecord - 1].patientName = "";
    total_patient[delrecord - 1].patientAge = 0;
    total_patient[delrecord - 1].patientDisease = "";
    total_patient[delrecord - 1].patientMedicine = "";
    total_patient[delrecord - 1].patientContact = "";
    total_patient[delrecord - 1].patientAddress = "";
    cout << endl;
    cout << "Record deleted successfully.";
    cout << endl;
}
void prescribeMedicine()
{
    viewPatients();
    cout << endl;
    cout << "Enter Patient ID: ";
    cin >> prescriptionIdCheck;
    if (prescriptionIdValidation() == "Prescribe medicine")
    {
        for (int i = 0; i < patientCount; i++)
        {
            if (total_patient[i].patientId == prescriptionIdCheck)
            {
                total_prescription[prescriptionCount].prescriptionId = prescriptionIdCheck;
                cout << total_patient[i].patientName << endl;
                cout << total_patient[i].patientAge << endl;
                cout << total_patient[i].patientDisease << endl;
                cout << total_patient[i].patientMedicine << endl;
                cout << total_patient[i].patientContact << endl;
                cout << "\nAdd Prescription: ";
                cin.ignore();
                getline(cin, total_prescription[prescriptionCount].addPrescription);
                prescriptionCount++;
                break;
            }
        }
    }
    else if (prescriptionIdValidation() == "Already prescribed medicine")
    {
        cout << "  Already prescribed medicine to this patient.";
    }
    else if (prescriptionIdValidation() == "No such patient Id")
    {
        cout << "  No such Patient Id exists. ";
    }
}
void makeAppointments()
{
    viewPatients();
    cout << endl;
    cout << "With Patient ID: ";
    cin >> appointmentIdCheck;
    if (appointmentIdValidation() == "Make appointment")
    {
        for (int i = 0; i < patientCount; i++)
        {
            if (total_patient[i].patientId == appointmentIdCheck)
            {
                total_appointment[appointmentCount].appointmentId = appointmentIdCheck;
                cout << total_patient[i].patientName << endl;
                cout << total_patient[i].patientAge << endl;
                cout << total_patient[i].patientDisease << endl;
                cout << total_patient[i].patientMedicine << endl;
                cout << total_patient[i].patientContact << endl;
                cout << total_patient[i].patientAddress << endl;
                cout << "\nDay: ";
                cin >> total_appointment[appointmentCount].appointmentDay;
                cout << "Timing: ";
                cin >> total_appointment[appointmentCount].appointmentTime;
                appointmentCount++;
                break;
            }
        }
    }
    else if (appointmentIdValidation() == "Appointment already fixed.")
    {
        cout << "  Appointment already fixed with this patient.";
    }
    else if (appointmentIdValidation() == "No such patient Id")
    {
        cout << "  No such Patient Id exists. ";
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
        if (total_appointment[i].appointmentId == "")
        {
            continue;
        }
        for (int j = i; j < patientCount; j++)
        {
            if (total_appointment[i].appointmentId == total_patient[j].patientId)
            {
                cout << (i + 1) << ". " << total_patient[j].patientId << "\t\t" << total_patient[j].patientName << "\t\t    " << total_appointment[i].appointmentDay << "\t\t\t" << total_appointment[i].appointmentTime << endl;
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
    cout << total_patient[upAppoint - 1].patientId << "\t\t" << total_patient[upAppoint - 1].patientName << "\t\t    " << total_appointment[upAppoint - 1].appointmentDay << "\t\t\t" << total_appointment[upAppoint - 1].appointmentTime << endl;
    cout << endl;
    string upfield;
    cout << "Select field you want to change (Day, Time)_";
    cin >> upfield;
    if (upfield == "Day" || upfield == "day")
    {
        cout << "Old Appointment day: " << total_appointment[upAppoint - 1].appointmentDay;
        cout << "Enter New Appointment Day: ";
        cin >> total_appointment[upAppoint - 1].appointmentDay;
    }
    if (upfield == "Time" || upfield == "time")
    {
        cout << "Old Appointment Time: " << total_appointment[upAppoint - 1].appointmentTime;
        cout << "Enter New Appointment Time: ";
        cin >> total_appointment[upAppoint - 1].appointmentTime;
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
    cout << total_patient[delAppoint - 1].patientId << "\t\t" << total_patient[delAppoint - 1].patientName << "\t\t    " << total_appointment[delAppoint - 1].appointmentDay << "\t\t\t" << total_appointment[delAppoint - 1].appointmentTime << endl;
    cout << endl;
    total_appointment[delAppoint - 1].appointmentId = "";
    total_appointment[delAppoint - 1].appointmentDay = "";
    total_appointment[delAppoint - 1].appointmentTime = "";
    cout << "Appointment deleted successfully.";
    cout << endl;
}
void generateReports()
{
    int count = 0;
    cout << "Generate Reports of Patients ID: ";
    cin >> total_report[reportsCount].reportsId;
    for (int i = 0; i <= patientCount; i++)
    {
        if (total_patient[i].patientId == total_report[reportsCount].reportsId)
        {
            cout << total_patient[i].patientName << endl;
            cout << total_patient[i].patientAge << endl;
            cout << total_patient[i].patientDisease << endl;
            cout << total_patient[i].patientMedicine << endl;
            cout << endl;
            cout << "Test Taken: ";
            cin >> total_report[reportsCount].test;
            cout << "Result: ";
            cin >> total_report[reportsCount].result;
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
        if (ptPrescriptionId == total_patient[i].patientId)
        {
            for (int j = 0; j < prescriptionCount; j++)
            {
                if (ptPrescriptionId == total_prescription[j].prescriptionId)
                {
                    cout << total_patient[i].patientName << endl;
                    cout << total_patient[i].patientAge << endl;
                    cout << total_patient[i].patientDisease << endl;
                    cout << total_patient[i].patientMedicine << endl;
                    cout << total_patient[i].patientContact << endl;
                    cout << total_prescription[j].addPrescription;
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
    cout << endl;
}
void viewReports()
{
    int count = 0;
    string ptReportId;
    cout << "Enter your Patient Id: ";
    cin >> ptReportId;
    for (int i = 0; i < patientCount; i++)
    {
        if (ptReportId == total_patient[i].patientId)
        {
            for (int j = 0; j < reportsCount; j++)
            {
                if (total_report[j].reportsId == ptReportId)
                {
                    cout << endl;
                    cout << total_patient[i].patientName << endl;
                    cout << total_patient[i].patientAge << endl;
                    cout << total_patient[i].patientDisease << endl;
                    cout << total_patient[i].patientMedicine << endl;
                    cout << total_report[j].test << endl;
                    cout << total_report[j].result << endl;
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
    for (int i = 0; i < reportsCount; i++)
    {
        if (total_report[i].reportsId == id)
        {
            cout << "Test Taken: " << total_report[i].test << endl;
            cout << "Result: " << total_report[i].result << endl;
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
    }
}
void viewDoctorFees()
{
    cout << "  Doctor Checkup Fees: " << checkupFees;
    cout << endl;
}
void billPayments()
{
    cout << "Enter Patient Id: ";
    cin >> total_payBill[paymentCount].paymentId;
    cout << "Doctor Checkup Fees: " << checkupFees << endl;
    cout << labTestFees;
    total_payBill[paymentCount].payments = checkupFees + labTestFees;
    cout << "Payable Amount: " << total_payBill[paymentCount].payments;
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
    for (int i = 0; i < 7; i++)
    {
        cout << (i + 1) << ". " << instructionManual[i] << endl;
        cout << endl;
    }
}
void editManual()
{
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t   ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "\t   ~     INSTRUCTION  MANUAL   ~" << endl;
    cout << "\t   ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << (i + 1) << ". " << instructionManual[i] << endl;
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
void markAttendance()
{
    cout << endl;
    cout << endl;
    cout << " Doctor Id   1   2   3   4   5   6   7   8   9   10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29   30" << endl;
    cout << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << "    d" << (i+1) ;
        for(int j = 0; j < 31; j++)
        {
            cout << "  " << attendance[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    bool check = false;
    string id; 
    int date;
    cout << "Select doctor id: ";
    cin >> id;
    cout << "Select date: ";
    cin >> date;
    for(int i = 0; i < doctorCount; i++)
    {
        if(id == total_doctor->doctorId)
        {
            check = true;
        }
    }
    if(check)
    {
        if(id == "d1")
        {
            attendance[0][date-1] == 'P';
        }
        if (id == "d2")
        {
            attendance[0][date - 1] == 'P';
        }
        if (id == "d3")
        {
            attendance[0][date - 1] == 'P';
        }
        if (id == "d4")
        {
            attendance[0][date - 1] == 'P';
        }
        if (id == "d5")
        {
            attendance[0][date - 1] == 'P';
        }
        if (id == "d6")
        {
            attendance[0][date - 1] == 'P';
        }
        if (id == "d7")
        {
            attendance[0][date - 1] == 'P';
        }
        if (id == "d8")
        {
            attendance[0][date - 1] == 'P';
        }
        if (id == "d9")
        {
            attendance[0][date - 1] == 'P';
        }
        if (id == "d10")
        {
            attendance[0][date - 1] == 'P';
        }
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
        file << total_doctor[i].doctorId << "," << total_doctor[i].doctorPassword << "," << total_doctor[i].doctorNames << "," << total_doctor[i].doctorAges << "," << total_doctor[i].doctorAddress << "," << total_doctor[i].doctorContact << "," << total_doctor[i].doctorQualification << "," << total_doctor[i].doctorSalary << endl;
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
    total_doctor[doctorCount].doctorId = parseRecord(1, line1);
    total_doctor[doctorCount].doctorPassword = parseRecord(2, line1);
    total_doctor[doctorCount].doctorNames = parseRecord(3, line1);
    total_doctor[doctorCount].doctorAges = stoi(parseRecord(4, line1));
    total_doctor[doctorCount].doctorAddress = parseRecord(5, line1);
    total_doctor[doctorCount].doctorContact = parseRecord(6, line1);
    total_doctor[doctorCount].doctorQualification = parseRecord(7, line1);
    total_doctor[doctorCount].doctorSalary = stoi(parseRecord(8, line1));
    doctorCount++;
}
void store2()
{
    fstream file;
    file.open("PatientsInformation.txt", ios ::out);
    for (int i = 0; i < patientCount; i++)
    {
        file << total_patient[i].patientId << "," << total_patient[i].patientName << "," << total_patient[i].patientAge << "," << total_patient[i].patientDisease << "," << total_patient[i].patientMedicine << "," << total_patient[i].patientAddress << "," << total_patient[i].patientContact << endl;
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
    total_patient[patientCount].patientId = parseRecord(1, line2);
    total_patient[patientCount].patientName = parseRecord(2, line2);
    total_patient[patientCount].patientAge = stoi(parseRecord(3, line2));
    total_patient[patientCount].patientDisease = parseRecord(4, line2);
    total_patient[patientCount].patientMedicine = parseRecord(5, line2);
    total_patient[patientCount].patientAddress = parseRecord(6, line2);
    total_patient[patientCount].patientContact = parseRecord(7, line2);
    patientCount++;
}
void store3()
{
    fstream file;
    file.open("Prescriptions.txt", ios ::out);
    for (int i = 0; i < prescriptionCount; i++)
    {
        file << total_prescription[i].prescriptionId << "," << total_prescription[i].addPrescription << endl;
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
    total_prescription[prescriptionCount].prescriptionId = parseRecord(1, line3);
    total_prescription[prescriptionCount].addPrescription = parseRecord(2, line3);
    prescriptionCount++;
}
void store4()
{
    fstream file;
    file.open("Appointments.txt", ios ::out);
    for (int i = 0; i < appointmentCount; i++)
    {
        file << total_appointment[i].appointmentId[i] << "," << total_appointment[i].appointmentDay << "," << total_appointment[appointmentCount].appointmentTime << endl;
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
    total_appointment[appointmentCount].appointmentId = parseRecord(1, line4);
    total_appointment[appointmentCount].appointmentDay = parseRecord(2, line4);
    total_appointment[appointmentCount].appointmentTime = parseRecord(3, line4);
    appointmentCount++;
}
void store5()
{
    fstream file;
    file.open("Reports.txt", ios ::out);
    for (int i = 0; i < reportsCount; i++)
    {
        file << total_report[i].reportsId << "," << total_report[i].test << "," << total_report[i].result << endl;
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
    total_report[reportsCount].reportsId = parseRecord(1, line5);
    total_report[reportsCount].test = parseRecord(2, line5);
    total_report[reportsCount].result = parseRecord(3, line5);
    reportsCount++;
}
void store6()
{
    fstream file;
    file.open("Bill Payments.txt", ios ::out);
    for (int i = 0; i < paymentCount; i++)
    {
        file << total_payBill[i].paymentId << "," << total_payBill[i].payments << endl;
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
    total_payBill[paymentCount].paymentId = parseRecord(1, line6);
    total_payBill[paymentCount].payments = stoi(parseRecord(2, line6));
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
    for (int i = 0; i < 7; i++)
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
/*
void store10()
{
    fstream file;
    file.open("Attendance.txt", ios ::out);
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            file << seats[i][j] << ",";
        }
        file << endl;
    }
    file.close();
}
void load10()
{
    fstream file;
    file.open("Attendance.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line);
        array();
    }
}
void array()
{
    char a;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            a = parseRecord(i);
            attendance[i][j] = a;
        }
    }
}
char parse(int field)
{
    int comma = 1;
    char item;
    for (int x = 0; line[x] != '\0'; x++)
    {
        if (line[x] == ',')
        {
            comma = comma + 1;
        }
        else if (comma == field)
        {
            item = line[x];
        }
    }
    return item;
}4
*/
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
bool nameValidation()
{
    int count1 = 0, count2 = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count1++;
    }
    for (int j = 0; name[j] != '\0'; j++)
    {
        if ((name[j] >= 'a' || name[j] >= 'A') && (name[j] <= 'z' || name[j] <= 'Z'))
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
bool doctorIdValidation()
{
    for (int i = 0; i < doctorCount; i++)
    {
        if (IdCheck1 == total_doctor[i].doctorId)
        {
            return false;
        }
    }
    return true;
}
bool patientIdValidation()
{
    for (int i = 0; i < patientCount; i++)
    {
        if (IdCheck2 == total_patient[i].patientId)
        {
            return false;
        }
    }
    return true;
}
string prescriptionIdValidation()
{
    string check;
    check = "No such patient Id";
    for (int j = 0; j < prescriptionCount; j++)
    {
        if (prescriptionIdCheck == total_prescription[j].prescriptionId)
        {
            check = "Already prescribed medicine";
            return check;
        }
    }
    for (int i = 0; i < patientCount; i++)
    {
        if (total_patient[i].patientId == prescriptionIdCheck)
        {
            check = "Prescribe medicine";
            return check;
        }
    }
    return check;
}
string appointmentIdValidation()
{
    string check;
    check = "No such patient Id";
    for (int j = 0; j < appointmentCount; j++)
    {
        if (appointmentIdCheck == total_appointment[j].appointmentId)
        {
            check = "Appointment already fixed.";
            return check;
        }
    }
    for (int i = 0; i < patientCount; i++)
    {
        if (total_patient[i].patientId == appointmentIdCheck)
        {
            check = "Make appointment";
            return check;
        }
    }
    return check;
}
