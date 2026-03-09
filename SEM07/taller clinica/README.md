# Sistema de Gestión de Clínica

## Descripción
Este proyecto implementa un sistema de gestión de clínica en C++ utilizando Programación Orientada a Objetos.

El sistema permite:
- Registrar pacientes
- Registrar doctores
- Agendar citas
- Cancelar citas
- Generar reportes


## Cómo compilar y ejecutar

1. Abrir el archivo en un compilador de C++.
2. Compilar el programa.
3. Ejecutar el archivo.

El sistema mostrará un menú con las opciones disponibles.


## Justificación del UML

El sistema utiliza Programación Orientada a Objetos.

- **Herencia:** Paciente y Doctor heredan de Persona.
- **Asociación:** Cita relaciona Paciente y Doctor.
- **Composición:** Paciente contiene una Historia Clínica.


## Pruebas del sistema

### Prueba 1: Registro de paciente válido

Entrada:

DNI: 12345678  
Teléfono: 987654321  

Resultado:

Paciente registrado correctamente.

---

### Prueba 2: DNI inválido

Entrada:

DNI: 1234

Resultado:

Error: DNI inválido.

---

### Prueba 3: Teléfono inválido

Entrada:

Teléfono: 12345

Resultado:

Error: Teléfono inválido.