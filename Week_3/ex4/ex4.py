import sys
import copy

class Date:
    dom = [31,28,31,30,31,30,31,31,30,31,30,31]
    def __init__(self, day = 1,month = 1,year = 1):
        self.__day = day
        self.__month = month
        self.__year = year
    def display(self):
        print "%d/%d/%d" % (self.__day, self.__month, self.__year),
    def is_leap(self):
        if (self.__year % 400 == 0):
            return True 
        elif ((self.__year % 100 != 0) and (self.__year % 4 == 0)):
            return True 
        else:
            return False 
    def the_date_after(self):
        if (self.__day >= (self.dom[self.__month-1] + (1 if self.is_leap() else 0))):
            if (self.__month == 12):
                self.__year =  self.__year + 1
                self.__month = 1
            else:
                self.__month = self.__month + 1
            self.__day = 1
        else:
            self.__day = self.__day + 1
    def the_date_before(self):
        if  (self.__day == 1):
            if (self.__month == 1):
                self.__year = self.__year - 1
                self.__month = 12
            else:
                self.__month = self.__month - 1
            self.__day = self.dom[self.__month-1] + (1 if self.is_leap() else 0)
        else:
            self.__day = self.__day - 1
day = int(input("Day: "))
month = int(input("Month: "))
year = int(input("Year: "))

#a = Date(28,2,2016)
a = Date(day,month,year)
print "The day after",
a.display()
print "is",
b = copy.copy(a)
b.the_date_after()
b.display()

print "\nThe day before",
a.display()
print "is",
c = copy.copy(a)
c.the_date_before()
c.display()
