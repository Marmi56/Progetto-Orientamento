#include "prototipi.h"

#include <fstream>    // ifstream
#include <iostream>   // cerr, cout
#include <algorithm>  // std::all_of, std::transform

using namespace std;


int main() {
    const string csvPath = "corsi_studenti.csv";
    vector<CourseStudent> students;

    if (!loadCSV(csvPath, students)) {
        cout << "Caricamento fallito." << endl;
        return 1;
    }
    if (students.empty()) {
        cout << "Nessun elemento valido trovato." << endl;
        return 1;
    }

    //*************************************************COUT DI TEST****************************************************************
    cout << "Primi 5 elementi (tot=" << students.size() << "):"<<endl;

    for (int i = 0; i < (int)students.size() && i < 5; i++) {
        const CourseStudent& cs = students[i];
        cout << cs.courseCode << " | "
             << cs.courseDescription << " | "
             << cs.subjectCode << " | "
             << cs.subjectDescription << " | "
             << cs.studentId << " | "
             << cs.studentLastName << " | "
             << cs.studentFirstName << endl;
    }


      // --- TEST: ricerca per matricola ---
    int testId = 780604;  // usa una matricola esistente nel tuo file
    CourseStudent trovato = searchByStudentId(students, testId);

    cout << "\nRisultato ricerca per matricola (" << testId << "):\n";
    if (trovato.studentId != -1) {
        cout << trovato.courseCode << " | " << trovato.courseDescription << " | "
             << trovato.subjectCode << " | " << trovato.subjectDescription << " | "
             << trovato.studentId << " | " << trovato.studentLastName << " | "
             << trovato.studentFirstName << endl;
    } else {
        cout << "Studente non trovato.\n";
    }


     // --- TEST: ricerca per cognome ---
    string testLastName = "Taccola";  // usa un cognome presente nel file
    vector<CourseStudent> risultati = searchByLastName(students, testLastName);

    cout << "\nRisultati ricerca per cognome (\"" << testLastName << "\"):\n";
    if (!risultati.empty()) {
        for (int i = 0; i < (int)risultati.size(); i++) {
            const CourseStudent& cs = risultati[i];
            cout << cs.courseCode << " | " << cs.courseDescription << " | "
                 << cs.subjectCode << " | " << cs.subjectDescription << " | "
                 << cs.studentId << " | " << cs.studentLastName << " | "
                 << cs.studentFirstName << endl;
        }
    } else {
        cout << "Nessuno trovato.\n";
    }

    // TEST: Ricerca senza ripetizioni tramite codice corso
    string courseCodeTest;

    cout<<endl;
    cout<<"inserisci un courseCode da cercare:";
    cin>>courseCodeTest;
    cout<<endl;

    vector<CourseStudent> enrolledStudents = getStudentsByCourse(students, courseCodeTest);

    cout << "Studenti iscritti al corso " << courseCodeTest << ":\n";
    printStudents(enrolledStudents);


    return 0;
}
