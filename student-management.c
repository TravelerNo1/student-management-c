#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//初始化学生列表
typedef struct {
    int id;
    char name[50];
    int age;
    float score;
} Student;

typedef struct {
    Student* data;
    int size;
    int capacity;
} StudentList;

void initList(StudentList* list) {
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}
//实现扩容
void checkCapacity(StudentList* list) {
    if (list->size >= list->capacity) {
        int newCapacity = list->capacity == 0 ? 10 : list->capacity * 2;
        Student* newData = (Student*)realloc(list->data, newCapacity * sizeof(Student));

        if (newData == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        list->data = newData;
        list->capacity = newCapacity;
    }
}
//添加学生
void addStudent(StudentList* list) {
    checkCapacity(list);

    Student s;

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Score: ");
    scanf("%f", &s.score);

    list->data[list->size] = s;
    list->size++;

    printf("Student added successfully!\n");
}
//显示所有学生
void showStudents(StudentList* list) {
    int i;

    if (list->size == 0) {
        printf("No students found.\n");
        return;
    }

    for (i = 0; i < list->size; i++) {
        printf("ID: %d | Name: %s | Age: %d | Score: %.2f\n",
            list->data[i].id,
            list->data[i].name,
            list->data[i].age,
            list->data[i].score);
    }
}
//查找学生
int findStudentById(StudentList* list, int id) {
    int i;
    for (i = 0; i < list->size; i++) {
        if (list->data[i].id == id) {
            return i;  
        }
    }
    return -1;  
}
void searchStudent(StudentList* list) {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);

    int index = findStudentById(list, id);

    if (index == -1) {
        printf("Student not found.\n");
    } else {
        Student s = list->data[index];
        printf("Found: ID:%d Name:%s Age:%d Score:%.2f\n",
            s.id, s.name, s.age, s.score);
    }
}
//删除学生
void deleteStudent(StudentList* list) {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    int index = findStudentById(list, id);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    int i;
    for (i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;

    printf("Student deleted successfully!\n");
}
//保存数据
void saveToFile(StudentList* list) {
    FILE* fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("Failed to open file!\n");
        return;
    }

    int i;
    for (i = 0; i < list->size; i++) {
        fprintf(fp, "%d %s %d %.2f\n",
            list->data[i].id,
            list->data[i].name,
            list->data[i].age,
            list->data[i].score);
    }

    fclose(fp);
    printf("Data saved successfully!\n");
}
void loadFromFile(StudentList* list) {
    FILE* fp = fopen("students.txt", "r");

    if (fp == NULL) {
        return;
    }

    Student s;

    while (fscanf(fp, "%d %s %d %f",
        &s.id, s.name, &s.age, &s.score) == 4) {

        checkCapacity(list);
        list->data[list->size++] = s;
    }

    fclose(fp);
}
//清屏
void clear_screen() {
#ifdef _WIN32 
    system("cls");
#else 
    printf("\033[2J\033[1;1H");
#endif
} 
int main() {
    StudentList list;
    initList(&list);
	loadFromFile(&list); 
    int choice;

    while (1) {
        printf("\n==== Student Management System ====\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Search Student\n");
		printf("4. Delete Student\n");
		printf("5. Save to File\n");
		printf("6. Clear the Screen\n");
		printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&list);
                break;
            case 2:
                showStudents(&list);
                break;
            case 3:
  				searchStudent(&list);
   				break;
			case 4:
   				deleteStudent(&list);
    			break;
    		case 5:
    			saveToFile(&list);
    			break;
    		case 6:
    			clear_screen(); 
    			break;
            case 0:
    			saveToFile(&list);
    			printf("Bye!\n");
    			return 0;
            default:
                printf("Invalid choice!\n");
        }

    }
}
