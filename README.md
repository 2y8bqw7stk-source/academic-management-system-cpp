Academic Management System
📌 Overview
This project is a robust Academic Management System developed in C++. It is designed to streamline educational administration by centralizing data management for students, faculty, courses, and performance tracking.

The system follows strict Object-Oriented Programming (OOP) principles, ensuring a modular architecture with a clear separation between data interfaces and functional logic.

📂 Project Structure
The system consists of 19 units organized into functional modules. Each business entity (except for the entry point) is composed of a header file (.h) for declarations and a source file (.cpp) for implementation.

1. Identity & Personnel

Person (personne.h / personne.cpp): The base class defining fundamental identity attributes.


Student (etudiant.h / etudiant.cpp): Manages academic records and data specific to pupils.


Teacher (enseignant.h / enseignant.cpp): Handles faculty-related information and assignments.

2. Academic Administration

Module (Module.h / Module.cpp): Defines subjects, credits, and course structures.


Enrollment (inscription.h / inscription.cpp): Manages the registration process and student-course links.


Assessment (Note.h/cpp & controle.h/cpp): A complete system for tracking grades and organizing exams.

3. Core Engine & Infrastructure

System (systeme.h / systeme.cpp): The central controller that orchestrates interactions between all modules.


Table (tableau.h / tableau.cpp): A custom data structure optimized for handling collections of objects.


Main (Main.cpp): The standalone entry point of the application containing the primary execution loop.

🛠️ Technical Specifications

Environment: Developed using the Dev-C++ IDE.


Project File: Seance 3.dev.

Language: C++ (ISO C++11 or higher recommended).

Paradigm: Object-Oriented (Inheritance, Encapsulation, Polymorphism).

🚀 Getting Started
Launch the Dev-C++ IDE.

Open the project file: Seance 3.dev.

Ensure all .h and .cpp files listed in the project tree are present in the source directory.

Use the Compile & Run command (F11) to build and execute the application.
