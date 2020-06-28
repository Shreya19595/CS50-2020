from cs50 import SQL
from sys import argv, exit
import csv

#checking for command line arguments
if (len(argv) < 2):
    print("Usage: python import.py characters.csv")
    exit(1)

db = SQL("sqlite:///students.db")

csv_path = argv[1]
with open(csv_path) as csv_file:
    reader = csv.reader(csv_file)

    for row in reader:
        if row[0] == 'name':
            continue

        name_list = row[0].split()

        if len(name_list) == 2:
            first_name = name_list[0]
            last_name = name_list[1]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first_name, None, last_name, row[1], row[2])

        elif len(name_list) == 3:
            first_name = name_list[0]
            middle_name = name_list[1]
            last_name = name_list[2]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first_name, middle_name, last_name, row[1], row[2])
