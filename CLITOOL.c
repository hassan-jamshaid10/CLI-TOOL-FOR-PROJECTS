#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createReactProject(const char *projectName) {
    printf("Creating React project: %s\n", projectName);
    char command[256];
    snprintf(command, sizeof(command), "npx create vite@latest %s", projectName);
    system(command);
}

void createNextProject(const char *projectName) {
    printf("Creating Next.js project: %s\n", projectName);
    char command[256];
    snprintf(command, sizeof(command), "npx create-next-app %s", projectName);
    system(command);
}

void createExpressProject(const char *projectName) {
    printf("Creating Express project: %s\n", projectName);
    char command[512];
    snprintf(command, sizeof(command), "mkdir %s && cd %s && npm init -y && npm install express", projectName, projectName);
    system(command);

    // Create a basic server file
    char appJsPath[256];
    snprintf(appJsPath, sizeof(appJsPath), "%s/app.js", projectName);
    FILE *appJs = fopen(appJsPath, "w");
    if (appJs != NULL) {
        fprintf(appJs, "const express = require('express');\n");
        fprintf(appJs, "const app = express();\n");
        fprintf(appJs, "app.listen(3000, () => console.log('Server started on port 3000'));\n");
        fclose(appJs);
    }
}

void createPythonProject(const char *projectName) {
    printf("Creating Python project: %s\n", projectName);
    char command[256];
    snprintf(command, sizeof(command), "mkdir %s && cd %s && python3 -m venv venv", projectName, projectName);
    system(command);

    char appPyPath[256];
    snprintf(appPyPath, sizeof(appPyPath), "%s/app.py", projectName);
    FILE *appPy = fopen(appPyPath, "w");
    if (appPy != NULL) {
        fprintf(appPy, "print('Hello from Python!')\n");
        fclose(appPy);
    }
}

void createSpringBootProject(const char *projectName) {
    printf("Creating Spring Boot project: %s\n", projectName);
    char command[512];
    snprintf(command, sizeof(command), "curl https://start.spring.io/starter.zip -d dependencies=web -d name=%s -o %s.zip", projectName, projectName);
    system(command);
    snprintf(command, sizeof(command), "unzip %s.zip -d %s && rm %s.zip", projectName, projectName, projectName);
    system(command);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <projectType> <projectName>\n", argv[0]);
        printf("Supported project types: react, next, express, python, springboot\n");
        return 1;
    }

    const char *projectType = argv[1];
    const char *projectName = argv[2];

    if (strcmp(projectType, "react") == 0) {
        createReactProject(projectName);
    } else if (strcmp(projectType, "next") == 0) {
        createNextProject(projectName);
    } else if (strcmp(projectType, "express") == 0) {
        createExpressProject(projectName);
    } else if (strcmp(projectType, "python") == 0) {
        createPythonProject(projectName);
    } else if (strcmp(projectType, "springboot") == 0) {
        createSpringBootProject(projectName);
    } else {
        printf("Error: Unsupported project type '%s'.\n", projectType);
        return 1;
    }

    printf("Project '%s' created successfully.\n", projectName);
    return 0;
}