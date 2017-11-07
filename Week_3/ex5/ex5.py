import copy

class Time:
    def __init__(self, hour = 0, minute = 0, second = 0):
        self.__hour = hour
        self.__minute = minute
        self.__second = second
    def display(self):
        print "%02d:%02d:%02d" % (self.__hour, self.__minute, self.__second),
    def increase_second(self, sec):  
        t = self.__second + sec
        self.__second = t % 60
        t = t / 60 + self.__minute
        self.__minute = t % 60
        t = t / 60 + self.__hour
        self.__hour = t % 24
    def decrease_second(self, sec):  
        t = self.__second - sec
        if (t < 0):
            self.__second = t + 60
            t = -1
        else:
            self.__second = t
            t = 0
        t = self.__minute + t
        if (t < 0):
            self.__minute = t + 60
            t = -1
        else:
            self.__minute = t
            t = 0
        t = self.__hour + t
        if (t < 0):
            self.__hour = t + 24
        else:
            self.__hour = t
            
val = raw_input("Input time 'hh:mm:ss' (24-hour) ").split(':')

hh = int(val[0])
mm = int(val[1])
ss = int(val[2])

a = Time(hh, mm , ss)
b = copy.copy(a)
b.increase_second(1)
c = copy.copy(a)
c.decrease_second(1)

a.display()
print "\n",
print "Increase 1 second" 
b.display()
print "\n",
print "Decrease 1 second"
c.display()
