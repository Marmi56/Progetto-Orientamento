#include "prototipi.h"

#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;



string trim(const string& s) {
    int start = 0;
    while (start < (int)s.size() && (s[start] == ' ' || s[start] == '\t')) {
        start++;
    }
    int end = (int)s.size() - 1;
    while (end >= start && (s[end] == ' ' || s[end] == '\t')) {
        end--;
    }
    if (end < start) return "";
    return s.substr(start, end - start + 1);
}

string toLower(const string& s) {
    string result = s;
    for (int i = 0; i < (int)result.size(); i++) {
        char c = result[i];
        if (c >= 'A' && c <= 'Z') {
            result[i] = c + ('a' - 'A');
        }
    }
    return result;
}

string toUpper(const string& s) {
    string result = s;
    for (int i = 0; i < (int)result.size(); i++) {
        char c = result[i];
        if (c >= 'a' && c <= 'z') {
            result[i] = c - ('a' - 'A');
        }
    }
    return result;
}

string capitalize(const string& s) {
    if (s.empty()) return s;
    string low = toLower(s);
    low[0] = low[0] - ('a' - 'A');
    return low;
}


bool loadCSV(const string& filePath, vector<CourseStudent>& out) {
    ifstream inFile(filePath);
    if (!inFile) {
        cerr << "Errore: impossibile aprire " << filePath << endl;
        return false;
    }

    // **HEADER**: leggere 7 colonne
    vector<string> headers(7);
    for (int i = 0; i < 7; i++) {
        if (i < 6) getline(inFile, headers[i], ',');
        else getline(inFile, headers[i]);
        // trim e toLower da procedure.h
        headers[i] = toLower(trim(headers[i]));
    }
    vector<string> expected = {
        "codice_corso", "descrizione_corso", "codice_materia",
        "descrizione_materia", "matricola_studente",
        "cognome_studente", "nome_studente" };
    for (int i = 0; i < 7; i++) {
        if (headers[i] != expected[i]) {
            cerr << "Errore header colonna " << i << ": trovato '"
                 << headers[i] << "', atteso '" << expected[i] << "'" << endl;
            return false;
        }
    }

    // **RECORDS**: ciclo fino a EOF, 7 campi per riga
    string field;
    while (getline(inFile, field, ',')) {
        CourseStudent cs;
        // 0: courseCode -> minuscolo
        cs.courseCode = toLower(trim(field));
        // 1: courseDescription
        getline(inFile, field, ',');
        cs.courseDescription = toLower(trim(field));
        // 2: subjectCode
        getline(inFile, field, ',');
        cs.subjectCode = toLower(trim(field));
        // 3: subjectDescription
        getline(inFile, field, ',');
        cs.subjectDescription = toLower(trim(field));
        // 4: studentId
        getline(inFile, field, ',');
        field = trim(field);
        if (field.empty() || !all_of(field.begin(), field.end(), [](char c){ return isdigit(c); })) {
            cerr << "Avviso: matricola non valida, record saltato" << endl;
            // salta cognome e nome
            getline(inFile, field, ',');
            getline(inFile, field);
            continue;
        }
        cs.studentId = stoi(field);
        // 5: studentLastName
        getline(inFile, field, ',');
        cs.studentLastName = toLower(trim(field));
        // 6: studentFirstName
        getline(inFile, field);
        cs.studentFirstName = toLower(trim(field));

        out.push_back(cs);
    }

    inFile.close();
    return true;
}

CourseStudent searchByStudentId(const vector<CourseStudent>& data, int id) {
    auto it = find_if(data.begin(), data.end(), [id](const CourseStudent& cs) {
        return cs.studentId == id;
        });

    if (it != data.end()) {
        return *it;
    } else {
        return CourseStudent{"", "", "", "", -1, "", ""};  // convenzione per \"non trovato\"
    }
}

// Cerca per cognome (possono esserci più risultati)
vector<CourseStudent> searchByLastName(const vector<CourseStudent>& data, const string& lastName) {
    vector<CourseStudent> results;
    string searchTerm = toLower(trim(lastName));
    for (int i = 0; i < (int)data.size(); i++) {
        if (data[i].studentLastName == searchTerm) {
            results.push_back(data[i]);
        }
    }
    return results;
}

//ricercano tutti i studenti iscritti ad un determinato corso partendo da codeid
vector<CourseStudent> getStudentsByCourse(const vector<CourseStudent>& students, const string& courseCode) {
    vector<CourseStudent> enrolledStudents;
    string upperCourseCode = toUpper(courseCode);

    for (const CourseStudent& student : students) {
        if (toUpper(student.courseCode) == upperCourseCode) {
            enrolledStudents.push_back(student);
        }
    }

    return enrolledStudents;
}

// Funzione per stampare gli studenti iscritti con i dati separati da "|"
void printStudents(const vector<CourseStudent>& students) {
    for (const CourseStudent& student : students) {
        cout << student.courseCode << " | "
             << student.courseDescription << " | "
             << student.subjectCode << " | "
             << student.subjectDescription << " | "
             << student.studentId << " | "
             << student.studentLastName << " | "
             << student.studentFirstName << endl;
    }
}
