#pragma once
#include "File.h"
#include <iterator>

class Catalog
{
private:
	vector<File> search;
	File getin;

public:
	Catalog()
	{

	}

	void addFile(const File& file) {
		search.push_back(file);
	}
	using iterator = vector<File>::iterator;
	iterator begin() {
		return search.begin();
	}
	iterator end() {
		return search.end();
	}

	void showFiles(string& mask) {
		for (auto& de : search) {
			if (de.getName().find(mask) != string::npos) {
				cout << "File: " << de.getName() << ", Size: " << de.GetFilesize() << " bytes" << " Data: " << de.getData() << " Time: " << de.getTime() << endl;

				int choice;
				cout << "What to do with the time? (1. Increase the hour, 2. Decrease the hour): ";
				cin >> choice;

				switch (choice) {
				case 1: {
					int hoursToAdd;
					cout << "Number to increase: ";
					cin >> hoursToAdd;
					de.updateTime(hoursToAdd, 0, 0);
					cout << "Updated time: " << de.getTime() << endl;
					break;
				}
				case 2: {
					int hoursToSubtract;
					cout << "Number to reduce: ";
					cin >> hoursToSubtract;
					de.updateTime2(hoursToSubtract, 0, 0);
					cout << "Updated time: " << de.getTime() << endl;
					break;
				}
				default:
					cout << "Invalid!" << endl;
				}
			}
			else {
				cout << "File not found" << endl;
			}
		}
	}
	void createAndAddFile() {
		string name;
		int size;
		int day, month, year;
		int hours, minutes, seconds;
		string attributes;
		cout << "Create a new file" << endl;
		cout << "Enter the name: ";
		cin >> name;

		cout << "Enter the size in bytes: ";
		cin >> size;

		cout << "creation date (day month year): ";
		cin >> day >> month >> year;

		cout << "creation time (hours minutes seconds): ";
		cin >> hours >> minutes >> seconds;

		cout << "Enter file attributes: ";
		cin >> attributes;

		File newFile(name, size, Data(day, month, year), Time(hours, minutes, seconds), attributes);
		addFile(newFile);

		cout << "New file added successfully!" << endl;
		cout << "-----------" << endl;
		cout << newFile << endl;
	}





};