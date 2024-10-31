cmake_minimum_required(VERSION 3.10) 
project(VARIADIC C) # Imposta il nome del progetto e il linguaggio C
add_executable(variadic src/variadic.c)

# Definisci LOG_FILE per la compilazione
target_compile_definitions(variadic PRIVATE LOG_FILE)