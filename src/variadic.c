#include <stdio.h>
#include <stdarg.h>

void log_message(FILE *file, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Se il file è NULL, usa stdout come destinazione
    FILE *output = file ? file : stdout;

    // Stampa il messaggio utilizzando vfprintf, che accetta una lista di argomenti variabili
    vfprintf(output, format, args);

    // Termina la lista di argomenti
    va_end(args);
}

int main() {
    // Log su stdout
    log_message(NULL, "Questo è un log su stdout: %d, %s\n", 42, "ciao");

    // Log su un file specifico
    FILE *logfile = fopen("log.txt", "a");
    if (logfile) {
        log_message(logfile, "Questo è un log su file: %f\n", 3.14);
        fclose(logfile);
    } else {
        perror("Errore nell'apertura del file di log");
    }

    return 0;
}

