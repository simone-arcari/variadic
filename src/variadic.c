#include <stdio.h>
#include <stdarg.h>

void log_message(const char *format, ...) {
    va_list args;
    va_start(args, format);


#ifdef LOG_FILE
    FILE *logfile = fopen("log.txt", "a");
    if (logfile) {
        vfprintf(logfile, format, args);     
        fclose(logfile);
    } else {
        perror("Errore nell'apertura del file di log");
    }
#else
    vfprintf(stdout, format, args);
#endif

    // Termina la lista di argomenti
    va_end(args);
}

int main() {
    log_message("Questo è un log: %d, %s\n", 42, "ciao");

    return 0;
}

