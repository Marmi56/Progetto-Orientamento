#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <unordered_set>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

//struct
struct CourseStudent {
    string courseCode;         // Codice del corso (es. C001), verra' convertito in maiuscolo
    string courseDescription;  // Descrizione corso, formatta parole importanti
    string subjectCode;        // Codice materia (es. M101), maiuscolo
    string subjectDescription; // Descrizione materia, title case con eccezioni
    int studentId;             // Matricola studente, solo cifre valide
    string studentLastName;    // Cognome studente, iniziale maiuscola
    string studentFirstName;   // Nome studente, iniziale maiuscola
};

//intestazione
vector<string> head = {
        "codice_corso", "descrizione_corso", "codice_materia",
        "descrizione_materia", "matricola_studente",
        "cognome_studente", "nome_studente" 
    };


//PROTOTIPI

//gestione file
bool loadCSV(string filePath, vector<CourseStudent>& load);                                                                                  //PUNTO 2
bool uploadCSV(string filePath, vector<CourseStudent> upload);                                                                              //PUNTO 10
void addNewStudent(vector<CourseStudent>& data, string filePath, int id, string firstName, string lastName, string subjectCodeInput);         //PUNTO 9

//funzionalita'
string trim(string s);
string toLower(string s);
string toUpper(string s);
vector<CourseStudent> deleteMultipleId(vector<CourseStudent> data);

//output
void printStudent(CourseStudent student); 
void printStudents(vector<CourseStudent> students);
void printStudentInfo(CourseStudent student);
void printStudentsInfo(vector<CourseStudent> students);

//ricerca
int searchByStudentId(vector<CourseStudent> data, int id);                                                                                  //PUNTO 3.1
vector<int> searchByLastName(vector<CourseStudent> data, string lastName);                                                                  //PUNTO 3.2
vector<CourseStudent> getStudentsByCourseCode(vector<CourseStudent> data, string courseCode);                                               //PUNTO 4
vector<CourseStudent> searchByCourseCode(vector<CourseStudent> data, string courseCodeInput);                                               //PUNTO 5
void studentPerCourse(vector<CourseStudent> data);                                                                                          //PUNTO 6
void subjectPerCourse(vector<CourseStudent> data);                                                                                          //PUNTO 7
void searchSubjectByString(vector<CourseStudent> data, string keyword);                                                                     //PUNTO 8



//MAIN
int main() {
    vector<CourseStudent> data;
    string filePath = "C:/Users/Computer/Downloads/corsi_studenti.csv";  // Modifica se necessario
    int scelta;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Carica dati da file CSV\n";
        cout << "2. Ricerca corsi frequentati da uno studente (per matricola)\n";
        cout << "3. Ricerca studenti per cognome\n";
        cout << "4. Studenti unici per corso\n";
        cout << "5. Tutti i record di un corso\n";
        cout << "6. Statistiche: numero studenti per corso\n";
        cout << "7. Statistiche: numero materie per corso\n";
        cout << "8. Cerca materia per parola chiave\n";
        cout << "9. Aggiungi nuovo studente (se materia esiste)\n";
        cout << "10. Salva dati su CSV (output.csv)\n";
        cout << "0. Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: {
                if (!loadCSV(filePath, data)) {
                    cerr << "Caricamento fallito!" << endl;
                } else {
                    cout << "Caricamento completato." << endl;
                }
                break;
            }
            case 2: {
                int id;
                cout << "Inserisci matricola studente: ";
                cin >> id;
                int pos = searchByStudentId(data, id);
                if (pos != -1) {
                    printStudent(data[pos]);
                } else {
                    cout << "Studente non trovato." << endl;
                }
                break;
            }
            case 3: {
                string lastName;
                cout << "Inserisci cognome da cercare: ";
                cin >> lastName;
                vector<int> posCognome = searchByLastName(data, toLower(trim(lastName)));
                if (!posCognome.empty()) {
                    for (int p : posCognome) printStudent(data[p]);
                } else {
                    cout << "Nessuno studente trovato con quel cognome." << endl;
                }
                break;
            }
            case 4: {
                string code;
                cout << "Inserisci codice corso: ";
                cin >> code;
                vector<CourseStudent> studentiUnici = getStudentsByCourseCode(data, code);
                printStudentsInfo(studentiUnici);
                break;
            }
            case 5: {
                string code;
                cout << "Inserisci codice corso: ";
                cin >> code;
                vector<CourseStudent> corsoCompleto = searchByCourseCode(data, code);
                printStudents(corsoCompleto);
                break;
            }
            case 6: {
                studentPerCourse(data);
                break;
            }
            case 7: {
                subjectPerCourse(data);
                break;
            }
            case 8: {
                string keyword;
                cout << "Inserisci parola chiave da cercare nella descrizione materia: ";
                cin >> keyword;
                searchSubjectByString(data, keyword);
                break;
            }
            case 9: {
                int id;
                string firstName, lastName, subjectCode;
                cout << "Inserisci matricola: ";
                cin >> id;
                cout << "Inserisci nome: ";
                cin >> firstName;
                cout << "Inserisci cognome: ";
                cin >> lastName;
                cout << "Inserisci codice materia: ";
                cin >> subjectCode;
                addNewStudent(data, filePath, id, firstName, lastName, subjectCode);
                break;
            }
            case 10: {
                if (uploadCSV("output.csv", data)) {
                    cout << "Dati salvati in output.csv" << endl;
                } else {
                    cout << "Errore nel salvataggio." << endl;
                }
                break;
            }
            case 0: {
                cout << "Uscita in corso..." << endl;
                break;
            }
            default: {
                cout << "Scelta non valida. Riprova.\n";
                break;
            }
        }

    } while (scelta != 0);

    return 0;
}





//FUNZIONI

bool loadCSV(string filePath, vector<CourseStudent>& load) {
    
    //PARTE 1: APERTURA FILE
    ifstream File(filePath);
    
    if (!File) {
        cerr << "Errore: impossibile aprire " << filePath << endl;
        return false;
    }



    //PARTE 2: CONTROLLO HEADER
    vector<string> headers(7);

    for (int i = 0; i < 7; i++) {

        if (i < 6) {
            getline(File, headers[i], ',');
        }
        else {
            getline(File, headers[i]);
        }

        headers[i] = toLower(trim(headers[i]));

    }

        
    for (int i = 0; i < 7; i++) {
        if (headers[i] != head[i]) {
            cerr << "Errore header colonna " << i << ": trovato '"
                 << headers[i] << "', atteso '" << head[i] << "'" << endl;
            return false;
        }
    }

    
    
    //PARTE 3:  INPUT Dati

    string a; //stringa di appoggio
    while (getline(File, a, ',')) {   //ciclo fino a fine file
        CourseStudent sudent;
        // 0: courseCode -> minuscolo
        sudent.courseCode = toLower(trim(a));

        // 1: courseDescription
        getline(File, a, ',');
        sudent.courseDescription = toLower(trim(a));

        // 2: subjectCode
        getline(File, a, ',');
        sudent.subjectCode = toLower(trim(a));

        // 3: subjectDescription
        getline(File, a, ',');
        sudent.subjectDescription = toLower(trim(a));

        // 4: studentId
        getline(File, a, ',');
        a = trim(a);
        sudent.studentId = stoi(a);

        // 5: studentLastName
        getline(File, a, ',');
        sudent.studentLastName = toLower(trim(a));

        // 6: studentFirstName
        getline(File, a);
        sudent.studentFirstName = toLower(trim(a));


        //insert of student in vector
        load.push_back(sudent);
    }

    File.close();
    return true;
}


//PUNTO 10
bool uploadCSV(string filePath, vector<CourseStudent> upload) {
    //apertura file
    ofstream File (filePath);

    if (!File) {
        cerr << "Errore: impossibile aprire " << filePath << endl;
        return false;
    }

    //output intestazione
    for (int i = 0; i < head.size()-1; i++) {
        File << head[i]<<",";
    }
    File<<head[head.size()-1]<<endl;
    
    //output dati
    for (int i = 0; i < upload.size(); i++) {
        File << upload[i].courseCode << ","
            << upload[i].courseDescription << ","
            << upload[i].subjectCode << ","
            << upload[i].subjectDescription << ","
            << upload[i].studentId << ","
            << upload[i].studentLastName << ","
            << upload[i].studentFirstName << endl;
    }
    
    File.close();
    return true;
}


string trim(string s) {
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



string toLower(string s) {
    string result = s;

    for (int i = 0; i < result.size(); ++i) {
        result[i] = tolower(result[i]);
    }
    return result;
}

string toUpper(string s) {
    string result = s;
    
    for (int i = 0; i < result.size(); ++i) {
        result[i] = toupper(result[i]);
    }
    return result;
}


//dato un vettore con duplicati di codice_matricola ritorna il vettore eliminando i duplicati
vector<CourseStudent> deleteMultipleId(vector<CourseStudent> data) {
    vector<CourseStudent> students;
    unordered_set<int> seenIds;  // tiene traccia degli ID già trovati

    for (int i = 0; i < data.size(); i++) {
        int currentId = data[i].studentId;

        if (seenIds.find(currentId) == seenIds.end()) {     //se non trova ritorna l'ultimo elemento del set -> elemento nuovo e va aggiunto
            students.push_back(data[i]);      // Aggiunge lo studente se ID non già visto
            seenIds.insert(currentId);        // Segna l'ID come visto
        }
    }

    return students;
}

void printStudent(CourseStudent student){
    cout << student.courseCode << " | "
        << student.courseDescription << " | "
        << student.subjectCode << " | "
        << student.subjectDescription << " | "
        << student.studentId << " | "
        << student.studentLastName << " | "
        << student.studentFirstName << endl;
}


// Funzione per stampare gli studenti iscritti con i dati separati da "|"
void printStudents(vector<CourseStudent> students) {
    for (const CourseStudent student : students) {
        printStudent(student);
    }
}

void printStudentInfo(CourseStudent student) {
    cout<< student.studentId << " | "
        << student.studentLastName << " | "
        << student.studentFirstName << endl;
}

void printStudentsInfo(vector<CourseStudent> students) {
    for (const CourseStudent student : students) {
        printStudentInfo(student);
    }
}

//PUNTO 3.1
int searchByStudentId(vector<CourseStudent> data, int id) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i].studentId == id) {
            return i;
        }
    }
    return -1;
}

//PUNTO 3.2
vector<int> searchByLastName(vector<CourseStudent> data, string lastName) {
    vector<int> positions;
    
    for (int i = 0; i < data.size(); i++) {
        if (data[i].studentLastName == lastName) {
            positions.push_back(i);
        }
    }
    return positions;
}

//PUNTO 4
//visualizzare sudente: nome | cognome | codice_studente
vector<CourseStudent> getStudentsByCourseCode(vector<CourseStudent> data, string courseCode) {
    vector <CourseStudent> students;
    
    courseCode = toLower(trim(courseCode));

    students = searchByCourseCode(data, courseCode);

    students = deleteMultipleId(students);

    return students;
}



//PUNTO 5
vector<CourseStudent> searchByCourseCode(vector<CourseStudent> data, string courseCodeInput){
    vector <CourseStudent> students;

    courseCodeInput = toLower(trim(courseCodeInput));

    for (int i = 0; i < data.size(); i++) {
        if (data[i].courseCode == courseCodeInput) {
            students.push_back(data[i]);
        }
    }

    return students;
}

//PUNTO 6


void studentPerCourse(vector<CourseStudent> data) {
    // Mappa: courseCode -> insieme di studentId (unici)
    map<string, set<int>> courseStudents;

    for (int i = 0; i < data.size(); i++) {    //per tutti gli elementi del data
        string course = data[i].courseCode;         //aggiorno il corso attuale
        int studentId = data[i].studentId;          //aggiorno l'id attuale

        //Inserisce lo studentId nel set del corso corrispondente
        courseStudents[course].insert(studentId);
    }

    //Stampa i risultati
    for (auto& pair : courseStudents) {     //ciclo del map con iterator
        string course = pair.first;
        int count = pair.second.size();     //numero di materie uniche
        cout << "Corso " << course << ": " << count << " studente/i" << endl;
    }
}



//PUNTO 7 
// stampare il numero di materie per corso

void subjectPerCourse(vector<CourseStudent> data) {

    // Mappa: courseCode -> insieme di materie (uniche)
    map<string, set<string>> courseStudents;

    for (int i = 0; i < data.size(); i++) {    //per tutti gli elementi del data
        string course = data[i].courseCode;         //aggiorno il corso attuale
        string subjct = data[i].subjectCode;          //aggiorno la materia

        //Inserisce la materia nel set del corso corrispondente
        courseStudents[course].insert(subjct);
    }

    // Stampa i risultati
    for (auto& pair : courseStudents) {     //ciclo del map con iterator
        string course = pair.first;
        int count = pair.second.size(); // numero di studenti unici
        cout << "Corso " << course << ": " << count << " materie" << endl;
    }
}



//PUNTO 8

void searchSubjectByString(vector<CourseStudent> data, string keyword) {

    keyword = toLower(trim(keyword));

    set<string> duplicated;

    for (int i = 0; i < data.size(); i++) {

        string subject = data[i].subjectDescription;

        if (subject.find(keyword) != string::npos){ //se trova la parola keyword

            if(duplicated.count(data[i].subjectDescription) == 0){
                
                cout << data[i].subjectDescription << endl;
                duplicated.insert(data[i].subjectDescription);
            }
            
        }
    }

    if (duplicated.empty()) {
        cout << "Nessuna materia trovata contenente" << keyword << endl;
    }
    

}



//PUNTO 9

void addNewStudent(vector<CourseStudent>& data, string filePath, int id, string firstName, string lastName, string subjectCodeInput) {

    string subjectCode = toLower(trim(subjectCodeInput));
    bool found = false;

    for (int i = 0; i < (int)data.size(); i++) {
        CourseStudent cs = data[i];

        // Trova una materia esistente con lo stesso subjectCode
        if (toLower(trim(cs.subjectCode)) == subjectCode) {
            cs.studentId = id;
            cs.studentFirstName = toLower(trim(firstName));
            cs.studentLastName  = toLower(trim(lastName));

            data.push_back(cs);  // Aggiunge al vettore

            // Scrive su file (modalità append)
            ofstream outFile(filePath, ios::app);
            if (!outFile) {
                cerr << "Errore nell'apertura del file per scrittura." << endl;
            }
            else {
                outFile << cs.courseCode << ","
                << cs.courseDescription << ","
                << cs.subjectCode << ","
                << cs.subjectDescription << ","
                << cs.studentId << ","
                << cs.studentLastName << ","
                << cs.studentFirstName << "\n";

            
            }

            outFile.close();

            found = true;
            break; //risparmia run time ;)

        }
    }

    if (!found) {
        cout << "Errore: codice materia \"" << subjectCodeInput << "\" non trovato.\n";
    }
}