#ifndef PROTOTIPI_H
#define PROTOTIPI_H

#include <string>
#include <vector>

using namespace std;  // Permette l'uso diretto di string, vector, etc.

/**
 * @brief Associa corso, materia e studente.
 */
struct CourseStudent {
    string courseCode;         // Codice del corso (es. C001), verrà convertito in maiuscolo
    string courseDescription;  // Descrizione corso, formatta parole importanti
    string subjectCode;        // Codice materia (es. M101), maiuscolo
    string subjectDescription; // Descrizione materia, title case con eccezioni
    int studentId;             // Matricola studente, solo cifre valide
    string studentLastName;    // Cognome studente, iniziale maiuscola
    string studentFirstName;   // Nome studente, iniziale maiuscola
};

/*
  Carica un file CSV campo per campo.

  Apre file in lettura, verifica header, poi legge sequenzialmente
  ciascuno dei 7 campi separati da virgola o newline.
  Popola una struct CourseStudent per ogni set di campi validi.
 */
bool loadCSV(const string& filePath, vector<CourseStudent>& out);


//visualizzazione studenti dato vettore contenente
void printStudents(const vector<CourseStudent>& students);

// Prototipi delle funzioni ausiliarie utilizzate in FileLoader.cpp
// Rimuove spazi e tab iniziali e finali da una stringa
string trim(const string& s);

// Converte tutti i caratteri di una stringa in maiuscolo
string toUpper(const string& s);

// Converte tutti i caratteri di una stringa in minuscolo
string toLower(const string& s);

// Capitalizza la prima lettera di una parola (es. "pippo" -> "Pippo")
string capitalize(const string& s);

// cerca lo studente partendo dal suo id/matricola
CourseStudent searchByStudentId(const vector<CourseStudent>& data, int id);

// cerca i vari studenti partendo dal loro cognome
vector<CourseStudent> searchByLastName(const vector<CourseStudent>& data, const string& lastName);

// ricerca di tutti gli studenti per un corso specifico evitando ripetizioni
vector<CourseStudent> getStudentsByCourse(const vector<CourseStudent>& students, const string& courseCode);


#endif

