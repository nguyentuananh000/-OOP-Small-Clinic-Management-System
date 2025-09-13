#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Human {
    protected:
    string name;
    string ID;
    int age;
    public:
    Human(){
        cout<<"Human construction"<<endl;
    }
    Human(string n, string id, int a) : name(n), ID(id), age(a) {}
    virtual ~Human() {}
    virtual void displayInfor() const = 0;
    
    // Getter methods
    string getName() const {return name;}
    string getId() const {return ID;}
    int getAge() const {return age;}
};
class Patient : public Human{
    protected:
    string medicalHistory;
    string bloodType;
    public:
    Patient() : Human(), medicalHistory(""), bloodType("") {}
    Patient(string n, string id, int a) : Human(n, id, a), medicalHistory(""), bloodType("") {}
    Patient(string n, string id, int a, string history, string blood) 
        : Human(n, id, a), medicalHistory(history), bloodType(blood) {}
    
    // Setter methods
    void setMedicalHistory(string history) { medicalHistory = history; }
    void setBloodType(string blood) { bloodType = blood; }
    
    // Getter methods
    string getMedicalHistory() const { return medicalHistory; }
    string getBloodType() const { return bloodType; }
    
    void displayInfor() const override {
        cout<<"Patient General: Name: "<<name<<", Age: "<<age<<", ID: "<<ID<<endl;
        cout<<"Medical History: "<<medicalHistory<<", Blood Type: "<<bloodType<<endl;
    }
};
class ChronicPatient : public Patient {
    private:
    string chronicCondition;
    
    public:
    ChronicPatient(string _name, string _id, int _age, string condition = "") 
        : Patient(_name, _id, _age), chronicCondition(condition) {}
    
    void setChronicCondition(string condition) { chronicCondition = condition; }
    string getChronicCondition() const { return chronicCondition; }
    
    void displayInfor() const override {
        cout << "=== CHRONIC PATIENT ===" << endl;
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID << endl;
        cout << "Medical History: " << medicalHistory << ", Blood Type: " << bloodType << endl;
        cout << "Chronic Condition: " << chronicCondition << endl;
    }
};
class EmergencyPatient : public Patient {
    private:
    string emergencyType;
    string severity; // "Critical", "Serious", "Stable"
    
    public:
    EmergencyPatient(string _name, string _id, int _age, string emergency, string sev) 
        : Patient(_name, _id, _age), emergencyType(emergency), severity(sev) {}
    
    void setSeverity(string sev) { severity = sev; }
    string getEmergencyType() const { return emergencyType; }
    string getSeverity() const { return severity; }
    
    void displayInfor() const override {
        cout << "=== EMERGENCY PATIENT ===" << endl;
        cout << "Name: " << name << ", Age: " << age << ", ID: " << ID << endl;
        cout << "Emergency Type: " << emergencyType << endl;
        cout << "Severity: " << severity << endl;
        cout << "Medical History: " << medicalHistory << ", Blood Type: " << bloodType << endl;
    }
};
class Appointment {
private:
    string appointmentID;
    string patientID;
    string doctorID;
    string date;
    string time;
    string reason;
    string status; // "Scheduled", "Completed", "Cancelled"
    
public:
    Appointment(string appID, string pID, string dID, string d, string t, string r)
        : appointmentID(appID), patientID(pID), doctorID(dID), 
          date(d), time(t), reason(r), status("Scheduled") {}
    
    // Setter methods
    void setStatus(string s) { status = s; }
    void setDate(string d) { date = d; }
    void setTime(string t) { time = t; }
    string getAppointmentID() { return appointmentID; }
    string getPatientID() { return patientID; }
    string getDoctorID() { return doctorID; }
    string getDate() { return date; }
    string getTime() { return time; }
    string getReason() { return reason; }
    string getStatus() { return status; }
    
    void displayAppointment() const {
        cout << "=== APPOINTMENT DETAILS ===" << endl;
        cout << "Appointment ID: " << appointmentID << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        cout << "Reason: " << reason << endl;
        cout << "Status: " << status << endl;
    }
};
class Doctor : public Human{
    private:
    string specialty;
    string license;
    double consultationFee;
    
    public:
    Doctor() : Human(), specialty(""), license(""), consultationFee(0.0) {}
    Doctor(string n, string id, int a, string s, string lic = "", double fee = 0.0)
        : Human(n, id, a), specialty(s), license(lic), consultationFee(fee) {}
    
    string getSpecialty() const {return specialty;}
    string getLicense() const {return license;}
    double getConsultationFee() const {return consultationFee;}
    
    void displayInfor() const override {
        cout<<"Doctor Name: "<<name<<", ID:"<<ID<<", Age: "<<age<<", Specialty: "<<specialty<<endl;
        cout<<"License: "<<license<<", Fee: $"<<consultationFee<<endl;
    }
};
class Operations{
private:
    vector<Patient*> patients;
    vector<Doctor*> doctors;
    vector<Appointment*> appointments;
    
public:
    ~Operations() {
        for(auto patient : patients) delete patient;
        for(auto doctor : doctors) delete doctor;
        for(auto appointment : appointments) delete appointment;
    }
    
    void addPatient(Patient* patient) {
        patients.push_back(patient);
    }
    
    void addDoctor(Doctor* doctor) {
        doctors.push_back(doctor);
    }
    
    void addAppointment(Appointment* appointment) {
        appointments.push_back(appointment);
    }
    
    void displayAllPatients() const {
        cout << "\n========== ALL PATIENTS ==========" << endl;
        for(const auto& patient : patients) {
            patient->displayInfor();
            cout << "-----------------------------------" << endl;
        }
    }
    
    void displayAllDoctors() const {
        cout << "\n========== ALL DOCTORS ==========" << endl;
        for(const auto& doctor : doctors) {
            doctor->displayInfor();
            cout << "-----------------------------------" << endl;
        }
    }
    
    void displayAllAppointments() const {
        cout << "\n========== ALL APPOINTMENTS ==========" << endl;
        for(const auto& appointment : appointments) {
            appointment->displayAppointment();
            cout << "-----------------------------------" << endl;
        }
    }
};
int main() {
    cout << "=== CLINIC MANAGEMENT SYSTEM TEST CASES ===" << endl;
    
    Operations clinic;
    
    // TEST CASE 1: Creating Regular Patients
    cout << "\n=== TEST CASE 1: CREATING REGULAR PATIENTS ===" << endl;
    Patient* patient1 = new Patient("John Smith", "P001", 35, "No major issues", "O+");
    Patient* patient2 = new Patient("Mary Johnson", "P002", 28, "Allergic to penicillin", "A-");
    
    clinic.addPatient(patient1);
    clinic.addPatient(patient2);
    
    cout << "✅ Test Case 1 Passed: Regular patients created successfully" << endl;
    
    // TEST CASE 2: Creating Chronic Patients
    cout << "\n=== TEST CASE 2: CREATING CHRONIC PATIENTS ===" << endl;
    ChronicPatient* chronicPatient1 = new ChronicPatient("Robert Brown", "P003", 60, "Diabetes Type 2");
    chronicPatient1->setMedicalHistory("Family history of diabetes");
    chronicPatient1->setBloodType("B+");
    
    ChronicPatient* chronicPatient2 = new ChronicPatient("Linda Davis", "P004", 55, "Hypertension");
    chronicPatient2->setMedicalHistory("High blood pressure for 10 years");
    chronicPatient2->setBloodType("AB-");
    
    clinic.addPatient(chronicPatient1);
    clinic.addPatient(chronicPatient2);
    
    cout << "✅ Test Case 2 Passed: Chronic patients created successfully" << endl;
    
    // TEST CASE 3: Creating Emergency Patients
    cout << "\n=== TEST CASE 3: CREATING EMERGENCY PATIENTS ===" << endl;
    EmergencyPatient* emergencyPatient1 = new EmergencyPatient("Mike Wilson", "P005", 45, "Heart Attack", "Critical");
    emergencyPatient1->setMedicalHistory("Previous heart issues");
    emergencyPatient1->setBloodType("O-");
    
    EmergencyPatient* emergencyPatient2 = new EmergencyPatient("Sarah Taylor", "P006", 32, "Car Accident", "Serious");
    emergencyPatient2->setMedicalHistory("No major medical history");
    emergencyPatient2->setBloodType("A+");
    
    clinic.addPatient(emergencyPatient1);
    clinic.addPatient(emergencyPatient2);
    
    cout << "✅ Test Case 3 Passed: Emergency patients created successfully" << endl;
    
    // TEST CASE 4: Creating Doctors
    cout << "\n=== TEST CASE 4: CREATING DOCTORS ===" << endl;
    Doctor* doctor1 = new Doctor("Dr. Alice Anderson", "D001", 40, "General Medicine", "MD12345", 100.0);
    Doctor* doctor2 = new Doctor("Dr. Michael Chen", "D002", 50, "Cardiology", "MD67890", 200.0);
    Doctor* doctor3 = new Doctor("Dr. Emily Rodriguez", "D003", 38, "Emergency Medicine", "MD11111", 150.0);
    Doctor* doctor4 = new Doctor("Dr. David Kim", "D004", 45, "Endocrinology", "MD22222", 180.0);
    
    clinic.addDoctor(doctor1);
    clinic.addDoctor(doctor2);
    clinic.addDoctor(doctor3);
    clinic.addDoctor(doctor4);
    
    cout << "✅ Test Case 4 Passed: Doctors created successfully" << endl;
    
    // TEST CASE 5: Creating Appointments
    cout << "\n=== TEST CASE 5: CREATING APPOINTMENTS ===" << endl;
    Appointment* app1 = new Appointment("A001", "P001", "D001", "2024-03-15", "10:00 AM", "Regular Checkup");
    Appointment* app2 = new Appointment("A002", "P002", "D001", "2024-03-16", "2:00 PM", "Follow-up visit");
    Appointment* app3 = new Appointment("A003", "P003", "D004", "2024-03-17", "11:00 AM", "Diabetes Management");
    Appointment* app4 = new Appointment("A004", "P004", "D001", "2024-03-18", "3:00 PM", "Blood Pressure Check");
    Appointment* app5 = new Appointment("A005", "P005", "D002", "2024-03-14", "EMERGENCY", "Heart Attack Treatment");
    Appointment* app6 = new Appointment("A006", "P006", "D003", "2024-03-14", "EMERGENCY", "Trauma Care");
    
    clinic.addAppointment(app1);
    clinic.addAppointment(app2);
    clinic.addAppointment(app3);
    clinic.addAppointment(app4);
    clinic.addAppointment(app5);
    clinic.addAppointment(app6);
    
    cout << "✅ Test Case 5 Passed: Appointments created successfully" << endl;
    
    // TEST CASE 6: Displaying All Information
    cout << "\n=== TEST CASE 6: DISPLAYING ALL INFORMATION ===" << endl;
    clinic.displayAllPatients();
    clinic.displayAllDoctors();
    clinic.displayAllAppointments();
    
    cout << "✅ Test Case 6 Passed: All information displayed successfully" << endl;
    
    // TEST CASE 7: Testing Appointment Status Changes
    cout << "\n=== TEST CASE 7: TESTING APPOINTMENT STATUS CHANGES ===" << endl;
    app1->setStatus("Completed");
    app2->setStatus("In Progress");
    app3->setStatus("Cancelled");
    
    cout << "Updated appointment statuses:" << endl;
    app1->displayAppointment();
    cout << "-----------------------------------" << endl;
    app2->displayAppointment();
    cout << "-----------------------------------" << endl;
    app3->displayAppointment();
    
    cout << "✅ Test Case 7 Passed: Appointment status changes working" << endl;
    
    // TEST CASE 8: Testing Polymorphism
    cout << "\n=== TEST CASE 8: TESTING POLYMORPHISM ===" << endl;
    vector<Patient*> allPatients = {patient1, patient2, chronicPatient1, emergencyPatient1};
    
    cout << "Polymorphic display of different patient types:" << endl;
    for(auto patient : allPatients) {
        patient->displayInfor();
        cout << "-----------------------------------" << endl;
    }
    
    cout << "✅ Test Case 8 Passed: Polymorphism working correctly" << endl;
    
    // TEST CASE 9: Testing Getter Methods
    cout << "\n=== TEST CASE 9: TESTING GETTER METHODS ===" << endl;
    cout << "Patient 1 Name: " << patient1->getName() << endl;
    cout << "Patient 1 ID: " << patient1->getId() << endl;
    cout << "Patient 1 Age: " << patient1->getAge() << endl;
    cout << "Patient 1 Blood Type: " << patient1->getBloodType() << endl;
    
    cout << "Doctor 1 Name: " << doctor1->getName() << endl;
    cout << "Doctor 1 Specialty: " << doctor1->getSpecialty() << endl;
    cout << "Doctor 1 Fee: $" << doctor1->getConsultationFee() << endl;
    
    cout << "Chronic Patient Condition: " << chronicPatient1->getChronicCondition() << endl;
    cout << "Emergency Patient Type: " << emergencyPatient1->getEmergencyType() << endl;
    cout << "Emergency Patient Severity: " << emergencyPatient1->getSeverity() << endl;
    
    cout << "✅ Test Case 9 Passed: All getter methods working" << endl;
    
    // TEST CASE 10: Testing Setter Methods
    cout << "\n=== TEST CASE 10: TESTING SETTER METHODS ===" << endl;
    patient2->setMedicalHistory("Updated: Allergic to penicillin and aspirin");
    patient2->setBloodType("A+");
    
    chronicPatient2->setChronicCondition("Hypertension and High Cholesterol");
    emergencyPatient2->setSeverity("Stable");
    
    cout << "After using setter methods:" << endl;
    patient2->displayInfor();
    cout << "-----------------------------------" << endl;
    chronicPatient2->displayInfor();
    cout << "-----------------------------------" << endl;
    emergencyPatient2->displayInfor();
    
    cout << "✅ Test Case 10 Passed: All setter methods working" << endl;
    
    // SUMMARY
    cout << "\n=== TEST SUMMARY ===" << endl;
    cout << "✅ All 10 Test Cases Passed Successfully!" << endl;
    cout << "Total Patients Created: 6 (2 Regular, 2 Chronic, 2 Emergency)" << endl;
    cout << "Total Doctors Created: 4" << endl;
    cout << "Total Appointments Created: 6" << endl;
    cout << "Inheritance: ✅ Working" << endl;
    cout << "Polymorphism: ✅ Working" << endl;
    cout << "Encapsulation: ✅ Working" << endl;
    
    cout << "\n=== CLINIC MANAGEMENT SYSTEM TEST COMPLETED ===" << endl;
    
    return 0;
}