from cs50 import SQL
from sys import argv, exit
import csv

def main():

    #checking for command line arguments
    if (len(argv) < 3):
        if argv[1] != "Gryffindor" or argv[1] != "Slytherin" or argv[1] != "Hufflepuff" or argv[1] != "Ravenclaw":
            print("Usage: python roster.py house")

    db = SQL("sqlite:///students.db")

    house_list = db.execute("SELECT first, middle, last, birth FROM students WHERE house = (?) ORDER BY last, first", argv[1])

    for row in house_list:
        if row["middle"] == None:
            print(row["first"] + " " + row["last"] + ", born " + str(row["birth"]))
        else:
            print(row["first"] + " " + row["middle"] + " " + row["last"] + ", born " + str(row["birth"]))
