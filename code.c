#include <stdio.h> 
#define MAX_APPOINTMENTS 10 
  
struct Appointment { 
    int id; 
    char name[50]; 
    char date[20]; 
}; 
 struct Appointment appointmentQueue[MAX_APPOINTMENTS]; 
int front = -1, rear = -1; 
  
int isEmpty() { 
    if (front == -1 || front > rear) 
        return 1; 
    else 
        return 0; 
} 
  
int isFull() { 
    if (rear == MAX_APPOINTMENTS - 1) 
        return 1; 
    else 
        return 0; 
} 
  
void enqueue(struct Appointment app) { 
    if (isFull()) { 
        printf("Appointment queue is full. Cannot add more appointments.\n"); 
        return; 
    } 
  
    if (isEmpty()) 
        front = 0; 
  
    rear++; 
    appointmentQueue[rear] = app; 
  
    printf("Appointment with ID %d added successfully.\n", app.id); 
} 
  
void dequeue() { 
    if (isEmpty()) { 
        printf("Appointment queue is empty. No appointments to remove.\n"); 
        return; 
    } 
  
    struct Appointment app = appointmentQueue[front]; 
    printf("Appointment with ID %d removed successfully.\n", app.id); 
  
    front++; 
  
    if (front > rear) 
        front = rear = -1; 
} 
  
void displayAppointments() { 
    if (isEmpty()) { 
        printf("Appointment queue is empty. No appointments to display.\n"); 
        return; 
    } 
  
    printf("Appointments in the queue:\n"); 
    for (int i = front; i <= rear; i++) { 
        struct Appointment app = appointmentQueue[i]; 
        printf("ID: %d, Name: %s, Date: %s\n", app.id, app.name, app.date); 
    } 
} 
  
int main() { 
    int choice; 
    struct Appointment app; 
     
    do { 
        printf("\n-- Hospital Appointment System --\n"); 
        printf("1. Add an appointment\n"); 
        printf("2. Remove an appointment\n"); 
        printf("3. Display appointments\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
  
        switch (choice) { 
            case 1: 
                printf("Enter appointment ID: "); 
                scanf("%d", &app.id); 
                printf("Enter patient name: "); 
                scanf("%s", app.name); 
                printf("Enter appointment date: "); 
                scanf("%s", app.date); 
                enqueue(app); 
                break; 
            case 2: 
                dequeue(); 
                break; 
            case 3: 
                displayAppointments(); 
                break; 
            case 4: 
                printf("Exiting the program...\n"); 
                break; 
            default: 
                printf("Invalid choice. Please try again.\n"); 
                break; 
        } 
    } while (choice != 4); 
  
    return 0; 
} 
 
