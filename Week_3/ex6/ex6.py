import copy
import operator

input_file = raw_input("Enter file name ")

class student:
    def __init__(self, student_id, first_name, last_name, address, dob, mark):
        self.__student_id = student_id
        self.__first_name = first_name
        self.__last_name = last_name
        self.__address = address
        self.__dob = dob
        self.__mark = mark
    def __lt__(self, other):
        return self.__last_name < other.__last_name
    def display(self,file_out):
        print >> file_out, "Student ID: %sFirst name: %sLast name: %sAddress: %s" % (self.__student_id, self.__first_name, self.__last_name, self.__address),
        print >> file_out, "Date of birth: %sMark: %s" % (self.__dob, self.__mark)

student_list = []
current_file = open(input_file)

while True:
    ID = current_file.readline()
    first_name = current_file.readline()
    last_name = current_file.readline()
    address = current_file.readline()
    dob = current_file.readline()
    mark = current_file.readline()
    if not ID: 
        break
    student_list.append(student(ID, first_name, last_name, address, dob, mark))

student_list.sort()

file_out = open('test.out', "w")

for item in student_list:
    item.display(file_out)
