#include <iostream>#include <windows.h>#include <unistd.h>#include <conio.h>#include <time.h>#include <vector>#include <sstream>using namespace std;
int ch;
std::vector<std::string> myvector;std::vector<std::string>::iterator it;
class Staff {
public:  void alertNurses() {    Beep(1500, 89);    cout << "Staff have been notified" << endl;  }
  void alertSecurity() {    Beep(100, 89);    cout << "Security have been notified" << endl;  }
  void waitInPatient() {    rand() % usleep(5000000) + usleep(500000);    cout << "Patient has arrived.";    usleep(500000);    cout << ".";    usleep(500000);    cout << "." << endl;  }
  string enterName(string pName) {    cout << "Enter the Patients Name" << endl;    cin >> pName;    cout << "The Patients name is " << pName << endl;    it = myvector.begin();    myvector.push_back(pName);  }};
class StaffButtons : public Staff {public:  Staff workers;
  void notifyNurses() {
    if (ch == '8') {      workers.alertNurses();    }  }  void notifySecurity() {    if (ch == '7') {      workers.alertSecurity();    }  }  void getPatientNames() {    if (ch == '6') {      cout << "--Getting patients Names" << endl;      for (it = myvector.begin(); it < myvector.end(); it++)        std::cout << '\t' << *it << endl;      std::cout << '\n';      getch();    }  }  void selectPatientFile() {    if (ch == '5') {      while (1) {        getch();        if (ch == '+') {          myvector.begin()++;          cout << *it;        }        if (ch == '-') {          myvector.begin()--;          cout << *it;        }      }    }  }};class Patients : public Staff {};int main() {
  system("color 0B");  Staff *staff = new Staff;  StaffButtons *staffAlertButtons = new StaffButtons;  while (1) {    ch = getch();    staffAlertButtons->notifyNurses();    staffAlertButtons->notifySecurity();    staffAlertButtons->getPatientNames();    staffAlertButtons->selectPatientFile();
    staff->waitInPatient();    staff->enterName("");
    if (ch == 'z') {      cout << "z";      usleep(500000);      cout << "z";      usleep(500000);      cout << "z";      usleep(500000);    }  }}
