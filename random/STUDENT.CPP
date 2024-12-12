#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <dos.h>

int main() {
	struct student_record {
		char name[99];
		int roll_num, age, english, math, science;
	};
	int students = 0, students_id = 0;
	int search_rn, index;
	char search_name[99];
	student_record list[99];
	int running = 1;
	char rep;
	while (running) {
		clrscr();
		cout << "STUDENT RECORDS" << endl
			 << "[1] Display Student Record" << endl
			 << "[2] Add Student" << endl
			 << "[3] Search Student" << endl
			 << "[4] Exit";
		rep = tolower(getch());
		switch (rep) {
			case '1':
				clrscr();
				if (students == 0) {
					cout << "NO STUDENTS ENROLLED";
					delay(750);
					break;
				}
				cout << "|--------------|-------------|-----|---------|------|---------|" << endl
					 << "|     Name     | Roll Number | Age | English | Math | Science |" << endl
					 << "|--------------|-------------|-----|---------|------|---------|" << endl;
				for (int x = 0; x < students; x++) {
					cout << "| " << list[x].name;
					for (int y = 1; y <= 12 - strlen(list[x].name); y++) {
						cout << " ";
					}
					cout << " | " << list[x].roll_num;
					if (list[x].roll_num < 10) {
						cout << "          ";
					}
					else {
						cout << "         ";
					}
					cout << " | " << list[x].age;
					if (list[x].age < 10) {
						cout << "  ";
					}
					else {
						cout << " ";
					}
					cout << " | ";
					if (list[x].english == 0) {
						cout << "NA";
					}
					else {
						cout << list[x].english;
					}
					cout << "     " << " | ";
					if (list[x].math == 0) {
						cout << "NA";
					}
					else {
						cout << list[x].math;
					}
					cout << "  " << " | ";
					if (list[x].science == 0) {
						cout << "NA";
					}
					else {
						cout << list[x].science;
					}
					cout << "     " << " | " << endl
						 << "|--------------|-------------|-----|---------|------|---------|" << endl;
				}
				getch();
				break;
			case '2':
				do {
					clrscr();
					cout << "Name of student [4 - 10]: ";
					cin >> list[students].name;
				} while (strlen(list[students].name) > 10 || strlen(list[students].name) < 4);
				list[students].roll_num = students_id + 1;
				clrscr();
				cout << "Age of student: ";
				cin >> list[students].age;
				list[students].english = 0;
				list[students].math = 0;
				list[students].science = 0;
				students++;
				students_id++;
				break;
			case '3':
				clrscr();
				index = students;
				cout << "Search by: " << endl
					 << "[1] Roll number" << endl
					 << "[2] Name";
				rep = tolower(getch());
				switch (rep) {
					case '1':
						clrscr();
						cout << "Enter roll number: ";
						cin >> search_rn;
						for (int x = 0; x < students; x++) {
							if (search_rn == list[x].roll_num) {
								index = x;
								break;
							}
						}
						break;
					case '2':
						clrscr();
						cout << "Enter name: ";
						cin >> search_name;
						for (x = 0; x < students; x++) {
							if (strcmp(search_name, list[x].name) == 0) {
								index = x;
								break;
							}
						}
						break;
				}
				if (index == students) {
					clrscr();
					cout << "No Students Found";
					delay(750);
					break;
				}
				else {
					clrscr();
					cout << "Name: " << list[index].name << endl
						 << "Roll number: " << list[index].roll_num << endl
						 << "Age: " << list[index].age << endl
						 << "English: ";
					if (list[index].english == 0) {
						cout << "NA" << endl;
					}
					else {
						cout << list[index].english << endl;
					}
					cout << "Math: ";
					if (list[index].math == 0) {
						cout << "NA" << endl;
					}
					else {
						cout << list[index].math << endl;
					}
					cout << "Science: ";
					if (list[index].science == 0) {
						cout << "NA" << endl;
					}
					else {
						cout << list[index].science << endl;
					}
					cout << "\n[1] EDIT GRADE\n[2] DELETE";
					rep = tolower(getch());
					if (rep == '1') {
						clrscr();
						cout << "Enter grade for" << endl
							 << "English: ";
						cin >> list[index].english;
						cout << "Math: ";
						cin >> list[index].math;
						cout << "Science: ";
						cin >> list[index].science;
						clrscr();
						cout << "Edit Done";
						delay(750);
					}
					else if (rep == '2') {
						clrscr();
						cout << "Are you sure? [Y][N]";
						rep = tolower(getch());
						if (rep == 'y') {
							for (int y = index; y < students; y++) {
								strcpy(list[y].name, list[y + 1].name);
								list[y].roll_num = list[y + 1].roll_num;
								list[y].age = list[y + 1].age;
								list[y].english = list[y + 1].english;
								list[y].math = list[y + 1].math;
								list[y].science = list[y + 1].science;
							}
							students--;
						}
					}
				}
				break;
			case '4':
				running = 0;
				break;
		}
	}
	return 0;
}